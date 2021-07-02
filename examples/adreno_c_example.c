#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define ADRENO_IOC_TYPE 0x09

#define ADRENO_PERFCOUNTER_GROUP_SP 0xA

#define ADRENO_SP_BUSY_CYCLES 0
#define ADRENO_SP_GM_ATOMICS 32
#define ADRENO_SP_FS_INSTRUCTIONS 44

struct adreno_perfcounter_get {
  unsigned int group_id;
  unsigned int countable_selector;
  unsigned int regster_offset_low;
  unsigned int regster_offset_high;
  unsigned int __pad;
};

#define ADRENO_IOCTL_PERFCOUNTER_GET \
  _IOWR(ADRENO_IOC_TYPE, 0x38, struct adreno_perfcounter_get)

void andreno_activate_perf_counter(int gpu_device, unsigned int group_id,
                                   unsigned int countable_selector) {
  struct adreno_perfcounter_get payload;
  memset(&payload, 0, sizeof(struct adreno_perfcounter_get));
  payload.group_id = group_id;
  payload.countable_selector = countable_selector;

  int ret = ioctl(gpu_device, ADRENO_IOCTL_PERFCOUNTER_GET, &payload);
  if (ret == -1) {
    perror("ioctl");
  }
}

struct adreno_perfcounter_put {
  unsigned int group_id;
  unsigned int countable_selector;
  unsigned int __pad[2];
};

#define ADRENO_IOCTL_PERFCOUNTER_PUT \
  _IOW(ADRENO_IOC_TYPE, 0x39, struct adreno_perfcounter_put)

void andreno_deactivate_perf_counter(int gpu_device, unsigned int group_id,
                                     unsigned int countable_selector) {
  struct adreno_perfcounter_put payload;
  memset(&payload, 0, sizeof(struct adreno_perfcounter_put));
  payload.group_id = group_id;
  payload.countable_selector = countable_selector;

  int ret = ioctl(gpu_device, ADRENO_IOCTL_PERFCOUNTER_PUT, &payload);
  if (ret == -1) {
    perror("ioctl");
  }
}

struct adreno_perfcounter_read_group {
  unsigned int group_id;
  unsigned int countable_selector;
  unsigned long long value;
};

struct adreno_perfcounter_read {
  struct adreno_perfcounter_read_group *groups;
  unsigned int num_groups;
  unsigned int __pad[2];
};

#define ADRENO_IOCTL_PERFCOUNTER_READ \
  _IOWR(ADRENO_IOC_TYPE, 0x3B, struct adreno_perfcounter_read)

void andreno_query_perf_counters(int gpu_device, unsigned int num_groups,
                                 struct adreno_perfcounter_read_group *groups,
                                 unsigned long long *values) {
  struct adreno_perfcounter_read payload;
  memset(&payload, 0, sizeof(struct adreno_perfcounter_read));
  payload.num_groups = num_groups;
  payload.groups = groups;

  int ret = ioctl(gpu_device, ADRENO_IOCTL_PERFCOUNTER_READ, &payload);
  if (ret == -1) {
    perror("ioctl");
  }

  for (int i = 0; i < num_groups; ++i) {
    values[i] = groups[i].value;
  }
}

static uint64_t pack2xi32(uint32_t high, uint32_t low) {
  return ((uint64_t)high << 32) | (uint64_t)low;
}

int main(void) {
  int gpu_device = open("/dev/kgsl-3d0", O_RDWR);
  if (gpu_device == -1) {
    perror("open");
  }

  andreno_activate_perf_counter(gpu_device, ADRENO_PERFCOUNTER_GROUP_SP,
                                ADRENO_SP_BUSY_CYCLES);
  andreno_activate_perf_counter(gpu_device, ADRENO_PERFCOUNTER_GROUP_SP,
                                ADRENO_SP_GM_ATOMICS);
  andreno_activate_perf_counter(gpu_device, ADRENO_PERFCOUNTER_GROUP_SP,
                                ADRENO_SP_FS_INSTRUCTIONS);

  struct adreno_perfcounter_read_group counters[3];
  memset(&counters, 0, sizeof(counters));
  counters[0].group_id = ADRENO_PERFCOUNTER_GROUP_SP;
  counters[0].countable_selector = ADRENO_SP_BUSY_CYCLES;
  counters[1].group_id = ADRENO_PERFCOUNTER_GROUP_SP;
  counters[1].countable_selector = ADRENO_SP_GM_ATOMICS;
  counters[2].group_id = ADRENO_PERFCOUNTER_GROUP_SP;
  counters[2].countable_selector = ADRENO_SP_FS_INSTRUCTIONS;

  unsigned long long old_metrics[3], new_metrics[3], diff[3];
  memset(&old_metrics, 0, sizeof(old_metrics));
  for (int i = 0; i < 100; ++i) {
    andreno_query_perf_counters(gpu_device, 3, counters, new_metrics);
    for (int j = 0; j < 3; ++j) {
      diff[j] = new_metrics[j] - old_metrics[j];
    }
    printf("busy-cycles=%llu, gm-atomics=%llu, fs-instructions=%llu\n", diff[0],
           diff[1], diff[2]);
    for (int j = 0; j < 3; ++j) {
      old_metrics[j] = new_metrics[j];
    }
    sleep(1);
  }

  andreno_deactivate_perf_counter(gpu_device, ADRENO_PERFCOUNTER_GROUP_SP,
                                  ADRENO_SP_BUSY_CYCLES);
  andreno_deactivate_perf_counter(gpu_device, ADRENO_PERFCOUNTER_GROUP_SP,
                                  ADRENO_SP_GM_ATOMICS);
  andreno_deactivate_perf_counter(gpu_device, ADRENO_PERFCOUNTER_GROUP_SP,
                                  ADRENO_SP_FS_INSTRUCTIONS);

  int ret = close(gpu_device);
  if (ret == -1) {
    perror("close");
  }

  return 0;
}
