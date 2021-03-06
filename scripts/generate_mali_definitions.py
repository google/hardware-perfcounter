#!/usr/bin/env python3
# Copyright 2021 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


import argparse
import os

import xml.etree.ElementTree as ET
from dataclasses import dataclass
from typing import Dict, Optional, Sequence, Tuple

VERBOSE = False

# Omit Midgard Gen1/Gen2/Gen3 architectures: they are fairly old now.
PRODUCT_IGNORE_LIST = ["T60x", "T62x", "T72x", "T76x"]
LAYOUT_IGNORE_LIST = ["T60X", "T62X", "T72X", "T76X"]

# Each category can only have up to 64 counters. So actually we can use 6 here.
# But it is fine to be a bit generous.
MALI_COUNTER_CATEGORY_NUM_BITS = 8

MALI_COUNTER_CATEGORIES = {
    "JOB_MANAGER": 0,
    "TILER": 1,
    "SHADER_CORE": 2,
    "MEMORY": 3,
}

MALI_AUTOGEN_MARKER = "AUTOGENERATED REGION; DO NOT EDIT!"

# Code templates for Mali counter layout definitions
MALI_LAYOUT_ENUM_PREFIX = "HPC_GPU_MALI_COUNTER_LAYOUT_"
MALI_LAYOUT_ENUM = """
/// Mali GPU counter layout schemes.
typedef enum hpc_gpu_mali_counter_layout_e {{
  {cases}
}} hpc_gpu_mali_counter_layout_t;
"""
MALI_GET_LAYOUT_FN = """
hpc_gpu_mali_counter_layout_t hpc_gpu_mali_get_counter_layout(uint16_t gpu_id) {{
  {cases}
}}
"""

# Code templates for Mali counter definitions
MALI_COUNTER_ENUM_CASE = "HPC_GPU_MALI_{group}_{category}_{counter} = {value}u"
MALI_COUNTER_ENUM = """
/// Common Mali {comment}GPU counters.
typedef enum hpc_gpu_mali_{group}_counter_e {{
  {cases}
}} hpc_gpu_mali_{group}_counter_t;
"""

# Code templates for Mali counter conversion definitions
MALI_COUNTER_CONVERSION_CASE = "case HPC_GPU_MALI_{group}_{category}_{counter}: return {value};"
MALI_COUNTER_CONVERSION_SWITCH_FN = """
static uint32_t hpc_gpu_mali_{group}_counter_convert_to_{layout}(uint32_t counter) {{
  // clang-format off
  switch ((hpc_gpu_mali_{group}_counter_t)counter) {{
    {cases}
  }}
  // clang-format on
}}
"""
MALI_COUNTER_CONVERSION_DIRECT_FN = """
static inline uint32_t hpc_gpu_mali_{group}_counter_convert_to_{layout}(
    uint32_t counter) {{
  return counter & ((1u << {bits}u) - 1u);
}}
"""

# Code templates for Mali counter layout conversion definitions
MALI_LAYOUT_CONVERSION_CASE = ("case {prefix}{ulayout}: return hpc_gpu_mali_"
                               "{group}_counter_convert_to_{llayout}(counter);")
MALI_LAYOUT_CONVERSION_SWITCH_FN = """
static uint32_t hpc_gpu_mali_{group}_counter_convert(
    uint32_t counter, hpc_gpu_mali_counter_layout_t layout) {{
  // clang-format off
  switch (layout) {{
    {cases}
    default: assert(0 && "should not happen!"); return ~0u;
  }}
  // clang-format on
}}
"""


@dataclass
class MaliProduct:
  """A data class containing one Mali product."""
  name: str  # Product name
  mask: str  # Product mask
  id: str  # Product ID (after applying mask)
  arch: str  # Product architecture
  layout: str  # Product perf counter layout

  def __str__(self):
    return f"{self.name}/{self.id} arch={self.arch} layout={self.layout}"


@dataclass
class MaliCounter:
  """A data class containing one Mali perf counter."""
  name: str  # Counter name
  index: int  # Counter index in the sample buffer

  def __str__(self):
    return f"[{self.index}] {self.name}"


@dataclass
class MaliLayout:
  """A data class containing one Mali perf counter layout."""
  name: str  # Layout name
  categories: Dict[str, Sequence[MaliCounter]]

  def __str__(self):
    lines = [f"Layout {self.name}"]
    for name, counters in self.categories.items():
      lines.extend(
          ["  {}{}".format(name, str(counter)) for counter in counters])
    return "\n".join(lines)


@dataclass
class MaliDatabase:
  """A data class containing the whole Mali product database."""
  products: Sequence[MaliProduct]
  layouts: Dict[str, MaliLayout]

  def __str__(self):
    lines = ["=== Products ==="]
    lines.extend([str(product) for product in self.products])
    lines.append("=== Layouts ===")
    lines.extend([str(layout) for layout in self.layouts.values()])
    return "\n".join(lines)

  def get_counter_layout_enum(self) -> str:
    """Returns a C enum containing all counter layouts."""
    cases = [f"{MALI_LAYOUT_ENUM_PREFIX}UNKNOWN"]
    cases.extend([
        "{}{}".format(MALI_LAYOUT_ENUM_PREFIX, l) for l in self.layouts.keys()
    ])
    return MALI_LAYOUT_ENUM.format(cases=",\n  ".join(cases))

  def get_counter_layout_fn(self) -> str:
    """Returns a function get the counter layout for a given GPU ID."""
    case_template = ("if ((gpu_id & {mask}u) == {id}u) "
                     "return {prefix}{layout};")
    cases = [
        case_template.format(mask=p.mask,
                             id=p.id,
                             layout=p.layout,
                             prefix=MALI_LAYOUT_ENUM_PREFIX)
        for p in reversed(self.products)
    ]
    cases.append(f"return {MALI_LAYOUT_ENUM_PREFIX}UNKNOWN;")
    return MALI_GET_LAYOUT_FN.format(cases="\n  ".join(cases))

  def _get_layouts_for_arch(self, arch: str) -> Sequence[str]:
    """Gets the layouts for a specific architecture."""
    layouts = []
    for product in self.products:
      if (product.arch == arch) or (arch.lower() == "common"):
        if product.layout not in layouts:
          layouts.append(product.layout)
    return layouts

  def _get_common_counter_for_layouts(
      self,
      layouts: Sequence[str]) -> Tuple[Dict[str, Sequence[MaliCounter]], bool]:
    """Returns a dict containing counters common to all Mali GPUs."""
    categories = {}
    # Whether any common counter use the same index for all layouts
    all_same_index = True

    # Convert the (layout -> category) hierarchy into (category -> layout).
    for layout_name in layouts:
      layout = self.layouts[layout_name]
      for name, category in layout.categories.items():
        if categories.get(name) is None:
          categories[name] = []
        categories[name].append(category)

    for name in categories.keys():
      category = categories[name]
      common_counters = []
      # Check all counters in the first layout to see whether they exist
      # in other layouts.
      for counter in category[0]:
        if not all([(counter.name in [c.name
                                      for c in layout])
                    for layout in category[1:]]):
          continue  # This one is not ubiquitous.

        # Figure out whether the counter has the same index for all layouts.
        indices = [counter.index]
        for layout in category[1:]:
          for c in layout:
            if c.name == counter.name:
              indices.append(c.index)
              break
        assert len(indices) == len(category), "missing counters in some layout!"
        same_index = len(set(indices)) == 1
        all_same_index &= same_index
        if not same_index and VERBOSE:
          print(
              f"{layouts} counter {counter.name} has different indices: {indices}"
          )

        common_counters.append(counter)
      categories[name] = common_counters

    return categories, all_same_index

  def get_common_counter_enum(self) -> Dict[str, str]:
    """Returns C enums containing counters common to different GPU classes."""
    all_enums = {}

    for group, comment in [("common", ""), ("valhall", "Valhall "),
                           ("bifrost", "Bifrost ")]:
      counters = []
      layouts = self._get_layouts_for_arch(group)
      common_counters, _ = self._get_common_counter_for_layouts(layouts)
      for name, category in common_counters.items():
        for counter in category:
          value = (MALI_COUNTER_CATEGORIES[name] <<
                   MALI_COUNTER_CATEGORY_NUM_BITS) + counter.index
          counters.append(
              MALI_COUNTER_ENUM_CASE.format(group=group.upper(),
                                            category=name.upper(),
                                            counter=counter.name,
                                            value=value))
      all_enums[group] = MALI_COUNTER_ENUM.format(comment=comment,
                                                  group=group,
                                                  cases=",\n  ".join(counters))

    return all_enums

  def get_counter_common_to_specific_fn(self) -> Dict[str, str]:
    """Returns functions that convert common enum counter values to the index
    for a specific GPU product."""
    all_fns = {}

    for group in ["common", "valhall", "bifrost"]:
      all_fns[group] = ""
      layouts = self._get_layouts_for_arch(group)
      common_counters, same_index = self._get_common_counter_for_layouts(
          layouts)

      layout_cases = []
      for target_layout in layouts:
        layout_cases.append(
            MALI_LAYOUT_CONVERSION_CASE.format(prefix=MALI_LAYOUT_ENUM_PREFIX,
                                               group=group,
                                               ulayout=target_layout.upper(),
                                               llayout=target_layout.lower()))

        # If for any common counter, it has the same index across all products,
        # we can just directly extract the index.
        if same_index:
          all_fns[group] += MALI_COUNTER_CONVERSION_DIRECT_FN.format(
              group=group,
              layout=target_layout.lower(),
              bits=MALI_COUNTER_CATEGORY_NUM_BITS)
          continue

        cases = []
        for name, category in common_counters.items():
          for counter in category:
            cases.append(
                MALI_COUNTER_CONVERSION_CASE.format(group=group.upper(),
                                                    category=name.upper(),
                                                    counter=counter.name,
                                                    value=counter.index))
        all_fns[group] += MALI_COUNTER_CONVERSION_SWITCH_FN.format(
            group=group,
            layout=target_layout.lower(),
            cases="\n    ".join(cases))

      all_fns[group] += MALI_LAYOUT_CONVERSION_SWITCH_FN.format(
          group=group, cases="\n    ".join(layout_cases))

    return all_fns


def get_counter_category_definitions():
  """Returns definitions related to counter categories."""
  category_enum = ["typedef enum mali_counter_category_e {"]
  for cat, index in MALI_COUNTER_CATEGORIES.items():
    category_enum.append("  MALI_COUNTER_CATEGORY_{} = {},".format(cat, index))
  category_enum.append("} mali_counter_category_t;")
  category_enum = "\n".join(category_enum)

  get_category_fn = [
      "static inline mali_counter_category_t mali_get_counter_category(",
      "    uint32_t counter) {",
      "  return counter >> {}u;".format(MALI_COUNTER_CATEGORY_NUM_BITS), "}"
  ]
  get_category_fn = "\n".join(get_category_fn)
  return category_enum + "\n\n" + get_category_fn + "\n\n"


def parse_xml_file(xml_path: str) -> MaliDatabase:
  """Parses the given XML file containg the Mali product database.

  The input XML file is expected to have the following structure:
  ```
  <database>
    <products>
      <product name="G78"   mask="0xf00f" id="0x9002"
               architecture="valhall" layout="TBOX" />
      ...
    </products>
    <layouts>
      <layout name="TBOX">
        <category name="SHADER_CORE">
          <counter index="...", name="...">
          ...
        </category>
      </layout>
      ...
    </layouts>
  </database>
  ```
  """
  tree = ET.parse(xml_path)
  root = tree.getroot()

  xml_products = root.find("products")
  xml_layouts = root.find("layouts")

  # Collect all GPU products.
  products = []
  for product in xml_products.findall("product"):
    if product.get("name") in PRODUCT_IGNORE_LIST:
      continue
    products.append(
        MaliProduct(name=product.get("name"),
                    mask=product.get("mask"),
                    id=product.get("id"),
                    arch=product.get("architecture"),
                    layout=product.get("layout")))

  # Collect all perf counter layouts
  layouts = {}
  for layout in xml_layouts.findall("layout"):
    name = layout.get("name")
    if name in LAYOUT_IGNORE_LIST:
      continue
    categories = {}
    for category in layout.findall("category"):
      counters = []
      for counter in category.findall("counter"):
        counters.append(
            MaliCounter(name=counter.get("name"),
                        index=int(counter.get("index"))))
      categories[category.get("name")] = counters
    layouts[name] = MaliLayout(name, categories)

  return MaliDatabase(products=products, layouts=layouts)


def update_generated_file(autogen_file: str, updated_content: str):
  """Updates the autogen region in the given file to the new content."""
  with open(autogen_file, "r") as f:
    old_content = f.readlines()

  marker_lines = []
  for index, line in enumerate(old_content):
    if MALI_AUTOGEN_MARKER in line:
      marker_lines.append(index)
  if len(marker_lines) != 2:
    raise ValueError("Original content should contain two autogen markers!")

  new_content = []
  new_content.extend(old_content[:marker_lines[0] + 1])
  new_content.append(updated_content)
  new_content.extend(old_content[marker_lines[1]:])

  with open(autogen_file, "w") as f:
    f.write(''.join(new_content))


def parse_arguments():
  """Parses command-line options."""

  def check_file_path(path: str):
    if os.path.isfile(path):
      return path
    else:
      raise ValueError(f"{path} does not point to a file")

  parser = argparse.ArgumentParser()
  parser.add_argument(
      "--mali_xml",
      metavar="<mali-xml-file>",
      type=check_file_path,
      required=True,
      help="Specify the XML file path containing Mali product database")
  parser.add_argument("-o",
                      "--output",
                      metavar="<project-root-dir>",
                      required=True,
                      help="Specify the root directory for this project")
  args = parser.parse_args()

  return args


def main(args):
  db = parse_xml_file(args.mali_xml)
  header_dir_prefix = ["include", "hpc", "gpu", "mali"]
  lib_dir_prefix = ["lib", "gpu", "mali"]

  context_header = os.path.join(args.output, *lib_dir_prefix, "context.h")
  update_generated_file(context_header, db.get_counter_layout_enum() + "\n")
  context_lib = os.path.join(args.output, *lib_dir_prefix, "context.c")
  update_generated_file(
      context_lib,
      db.get_counter_layout_fn() + "\n" + get_counter_category_definitions())

  counter_enums = db.get_common_counter_enum()
  conversion_fns = db.get_counter_common_to_specific_fn()

  for group in ["common", "valhall", "bifrost"]:
    common_header = os.path.join(args.output, *header_dir_prefix, f"{group}.h")
    update_generated_file(common_header, counter_enums[group] + "\n")
    common_lib = os.path.join(args.output, *lib_dir_prefix, f"{group}.c")
    update_generated_file(common_lib, conversion_fns[group] + "\n")


if __name__ == "__main__":
  main(parse_arguments())
