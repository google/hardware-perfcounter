# HardwarePerfCounter

HardwarePerfCounter is a set of libraries and utilities for sampling hardware
performance counters, focusing on GPU right now, for benchmarking/profiling
purposes.

## Rationale

Benchmarking/profiling is crucial for improving application performance.
However, the GPU landscape is diverse, with many different architectures from
quite a few hardware vendors. To understand the fine performance details,
we often need to resort to vendor-specific tools like [AMD Radeon GPU
Profiler][rgp], [ARM Mobile Studio][mobile-studio], [NVIDIA Nsight][nsight],
and [Qualcomm Snapdragon Profiler][snapdragon-profiler].

They are really all-encompassing tool suites, providing many utilities and
aiming for profiling the whole system. It's great if we just want an integrated
solution for one vendor, but not so much if we need to support multiple vendors
and/or have our own benchmarking/profiling solution in the development flow
that just needs a non-intrusive plugin.

This project aims to provide a cross-vendor, lightweight, and embeddable library
for sampling GPU performance counters to serve such needs. It is inspired by
[HWCPipe][hwcpipe]. However, HWCPipe only supports Mali GPUs and it uses many
C++ features (STL, exception, etc.) that cannot be configured away.

## Goals and Features

* **Cross-vendor**: for now, Adreno GPUs and Mali GPUs on Android/Linux.
  Others to come.
* **Layered abstractions**: there are abstractions across vendors, specific
  to one vendor, and specific to one vendor product category. It's possible
  to target broadly with fewer counter choices to specific with more counter
  choices.
* **Layered libraries**: the core libraries are implemented in C and directly
  talk to kernel drivers under the hood. C++ libraries (to be added later) are
  on top of the C libraries.
* **Flexible building configurations**: follows good CMake practice for
  integration. There are CMake options for each vendor. There is proper support
  for installation and target import/export.

## Status

Right now only the low level APIs are implemented, which exposes vendor-specific
counters as is. Such acess will stay as it gives users choice to dive into the
details.

The next step is to build high level APIs to provide vendor-agonistic counters.

## Dependencies

This repository requires a common C/C++ project development environment:

* [CMake][cmake] with version >= 3.13
* _Optional_ [Ninja][ninja] build system
* A C/C++ compiler that supports C11/C++14

## Building

### Android

```shell
git clone https://github.com/google/HardwarePerfCounter.git
cd HardwarePerfCounter

cmake -G Ninja -S ./ -B build-android/  \
  -DCMAKE_TOOLCHAIN_FILE="${ANDROID_NDK?}/build/cmake/android.toolchain.cmake" \
  -DANDROID_ABI="arm64-v8a" -DANDROID_PLATFORM=android-30
cmake --build build-android/
```

Where `ANDROID_NDK` is the path to the [Android NDK installation][android-ndk-install].
See Android's CMake guide for explanation over [`ANDROID_ABI`][android-abi] and
[`ANROID_PLATFORM`][android-platform].


### Linux/macOS

```shell
git clone https://github.com/google/HardwarePerfCounter.git
cd HardwarePerfCounter

cmake -G Ninja -S ./ -B build/
cmake --build build/
```

### Windows

Not supported yet.

[cmake]: https://cmake.org/
[ninja]: https://ninja-build.org/
[hwcpipe]: https://github.com/ARM-software/HWCPipe
[rgp]: https://gpuopen.com/rgp/
[mobile-studio]: https://developer.arm.com/tools-and-software/graphics-and-gaming/arm-mobile-studio
[nsight]: https://developer.nvidia.com/nsight-graphics
[snapdragon-profiler]: https://developer.qualcomm.com/software/snapdragon-profiler
[android-abi]: https://developer.android.com/ndk/guides/cmake#android_abi
[android-ndk-install]: https://developer.android.com/ndk/downloads
[android-platform]: https://developer.android.com/ndk/guides/cmake#android_platform
