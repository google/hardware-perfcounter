// AUTOGENERATED; DO NOT EDIT!

#ifndef HPC_GPU_ADRENO_A5XX_H_
#define HPC_GPU_ADRENO_A5XX_H_

typedef enum hpc_gpu_adreno_a5xx_ccu_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_CCU_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_CCU_STALL_CYCLES_RB_DEPTH_RETURN = 1,
  HPC_GPU_ADRENO_A5XX_CCU_STALL_CYCLES_RB_COLOR_RETURN = 2,
  HPC_GPU_ADRENO_A5XX_CCU_STARVE_CYCLES_FLAG_RETURN = 3,
  HPC_GPU_ADRENO_A5XX_CCU_DEPTH_BLOCKS = 4,
  HPC_GPU_ADRENO_A5XX_CCU_COLOR_BLOCKS = 5,
  HPC_GPU_ADRENO_A5XX_CCU_DEPTH_BLOCK_HIT = 6,
  HPC_GPU_ADRENO_A5XX_CCU_COLOR_BLOCK_HIT = 7,
  HPC_GPU_ADRENO_A5XX_CCU_PARTIAL_BLOCK_READ = 8,
  HPC_GPU_ADRENO_A5XX_CCU_GMEM_READ = 9,
  HPC_GPU_ADRENO_A5XX_CCU_GMEM_WRITE = 10,
  HPC_GPU_ADRENO_A5XX_CCU_DEPTH_READ_FLAG0_COUNT = 11,
  HPC_GPU_ADRENO_A5XX_CCU_DEPTH_READ_FLAG1_COUNT = 12,
  HPC_GPU_ADRENO_A5XX_CCU_DEPTH_READ_FLAG2_COUNT = 13,
  HPC_GPU_ADRENO_A5XX_CCU_DEPTH_READ_FLAG3_COUNT = 14,
  HPC_GPU_ADRENO_A5XX_CCU_DEPTH_READ_FLAG4_COUNT = 15,
  HPC_GPU_ADRENO_A5XX_CCU_COLOR_READ_FLAG0_COUNT = 16,
  HPC_GPU_ADRENO_A5XX_CCU_COLOR_READ_FLAG1_COUNT = 17,
  HPC_GPU_ADRENO_A5XX_CCU_COLOR_READ_FLAG2_COUNT = 18,
  HPC_GPU_ADRENO_A5XX_CCU_COLOR_READ_FLAG3_COUNT = 19,
  HPC_GPU_ADRENO_A5XX_CCU_COLOR_READ_FLAG4_COUNT = 20,
  HPC_GPU_ADRENO_A5XX_CCU_2D_BUSY_CYCLES = 21,
  HPC_GPU_ADRENO_A5XX_CCU_2D_RD_REQ = 22,
  HPC_GPU_ADRENO_A5XX_CCU_2D_WR_REQ = 23,
  HPC_GPU_ADRENO_A5XX_CCU_2D_REORDER_STARVE_CYCLES = 24,
  HPC_GPU_ADRENO_A5XX_CCU_2D_PIXELS = 25
} hpc_gpu_adreno_a5xx_ccu_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_cmp_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_STALL_CYCLES_VBIF = 0,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_VBIF_LATENCY_CYCLES = 1,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_VBIF_LATENCY_SAMPLES = 2,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_VBIF_READ_DATA_CCU = 3,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_VBIF_WRITE_DATA_CCU = 4,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_VBIF_READ_REQUEST = 5,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_VBIF_WRITE_REQUEST = 6,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_VBIF_READ_DATA = 7,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_VBIF_WRITE_DATA = 8,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_FLAG_FETCH_CYCLES = 9,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_FLAG_FETCH_SAMPLES = 10,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_DEPTH_WRITE_FLAG1_COUNT = 11,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_DEPTH_WRITE_FLAG2_COUNT = 12,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_DEPTH_WRITE_FLAG3_COUNT = 13,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_DEPTH_WRITE_FLAG4_COUNT = 14,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_COLOR_WRITE_FLAG1_COUNT = 15,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_COLOR_WRITE_FLAG2_COUNT = 16,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_COLOR_WRITE_FLAG3_COUNT = 17,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_COLOR_WRITE_FLAG4_COUNT = 18,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_2D_STALL_CYCLES_VBIF_REQ = 19,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_2D_STALL_CYCLES_VBIF_WR = 20,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_2D_STALL_CYCLES_VBIF_RETURN = 21,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_2D_RD_DATA = 22,
  HPC_GPU_ADRENO_A5XX_CMP_CMPDECMP_2D_WR_DATA = 23
} hpc_gpu_adreno_a5xx_cmp_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_cp_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_CP_ALWAYS_COUNT = 0,
  HPC_GPU_ADRENO_A5XX_CP_BUSY_GFX_CORE_IDLE = 1,
  HPC_GPU_ADRENO_A5XX_CP_BUSY_CYCLES = 2,
  HPC_GPU_ADRENO_A5XX_CP_PFP_IDLE = 3,
  HPC_GPU_ADRENO_A5XX_CP_PFP_BUSY_WORKING = 4,
  HPC_GPU_ADRENO_A5XX_CP_PFP_STALL_CYCLES_ANY = 5,
  HPC_GPU_ADRENO_A5XX_CP_PFP_STARVE_CYCLES_ANY = 6,
  HPC_GPU_ADRENO_A5XX_CP_PFP_ICACHE_MISS = 7,
  HPC_GPU_ADRENO_A5XX_CP_PFP_ICACHE_HIT = 8,
  HPC_GPU_ADRENO_A5XX_CP_PFP_MATCH_PM4_PKT_PROFILE = 9,
  HPC_GPU_ADRENO_A5XX_CP_ME_BUSY_WORKING = 10,
  HPC_GPU_ADRENO_A5XX_CP_ME_IDLE = 11,
  HPC_GPU_ADRENO_A5XX_CP_ME_STARVE_CYCLES_ANY = 12,
  HPC_GPU_ADRENO_A5XX_CP_ME_FIFO_EMPTY_PFP_IDLE = 13,
  HPC_GPU_ADRENO_A5XX_CP_ME_FIFO_EMPTY_PFP_BUSY = 14,
  HPC_GPU_ADRENO_A5XX_CP_ME_FIFO_FULL_ME_BUSY = 15,
  HPC_GPU_ADRENO_A5XX_CP_ME_FIFO_FULL_ME_NON_WORKING = 16,
  HPC_GPU_ADRENO_A5XX_CP_ME_STALL_CYCLES_ANY = 17,
  HPC_GPU_ADRENO_A5XX_CP_ME_ICACHE_MISS = 18,
  HPC_GPU_ADRENO_A5XX_CP_ME_ICACHE_HIT = 19,
  HPC_GPU_ADRENO_A5XX_CP_NUM_PREEMPTIONS = 20,
  HPC_GPU_ADRENO_A5XX_CP_PREEMPTION_REACTION_DELAY = 21,
  HPC_GPU_ADRENO_A5XX_CP_PREEMPTION_SWITCH_OUT_TIME = 22,
  HPC_GPU_ADRENO_A5XX_CP_PREEMPTION_SWITCH_IN_TIME = 23,
  HPC_GPU_ADRENO_A5XX_CP_DEAD_DRAWS_IN_BIN_RENDER = 24,
  HPC_GPU_ADRENO_A5XX_CP_PREDICATED_DRAWS_KILLED = 25,
  HPC_GPU_ADRENO_A5XX_CP_MODE_SWITCH = 26,
  HPC_GPU_ADRENO_A5XX_CP_ZPASS_DONE = 27,
  HPC_GPU_ADRENO_A5XX_CP_CONTEXT_DONE = 28,
  HPC_GPU_ADRENO_A5XX_CP_CACHE_FLUSH = 29,
  HPC_GPU_ADRENO_A5XX_CP_LONG_PREEMPTIONS = 30
} hpc_gpu_adreno_a5xx_cp_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_hlsq_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_HLSQ_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_HLSQ_STALL_CYCLES_UCHE = 1,
  HPC_GPU_ADRENO_A5XX_HLSQ_STALL_CYCLES_SP_STATE = 2,
  HPC_GPU_ADRENO_A5XX_HLSQ_STALL_CYCLES_SP_FS_STAGE = 3,
  HPC_GPU_ADRENO_A5XX_HLSQ_UCHE_LATENCY_CYCLES = 4,
  HPC_GPU_ADRENO_A5XX_HLSQ_UCHE_LATENCY_COUNT = 5,
  HPC_GPU_ADRENO_A5XX_HLSQ_FS_STAGE_32_WAVES = 6,
  HPC_GPU_ADRENO_A5XX_HLSQ_FS_STAGE_64_WAVES = 7,
  HPC_GPU_ADRENO_A5XX_HLSQ_QUADS = 8,
  HPC_GPU_ADRENO_A5XX_HLSQ_SP_STATE_COPY_TRANS_FS_STAGE = 9,
  HPC_GPU_ADRENO_A5XX_HLSQ_SP_STATE_COPY_TRANS_VS_STAGE = 10,
  HPC_GPU_ADRENO_A5XX_HLSQ_TP_STATE_COPY_TRANS_FS_STAGE = 11,
  HPC_GPU_ADRENO_A5XX_HLSQ_TP_STATE_COPY_TRANS_VS_STAGE = 12,
  HPC_GPU_ADRENO_A5XX_HLSQ_CS_INVOCATIONS = 13,
  HPC_GPU_ADRENO_A5XX_HLSQ_COMPUTE_DRAWCALLS = 14
} hpc_gpu_adreno_a5xx_hlsq_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_lrz_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_LRZ_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_LRZ_STARVE_CYCLES_RAS = 1,
  HPC_GPU_ADRENO_A5XX_LRZ_STALL_CYCLES_RB = 2,
  HPC_GPU_ADRENO_A5XX_LRZ_STALL_CYCLES_VSC = 3,
  HPC_GPU_ADRENO_A5XX_LRZ_STALL_CYCLES_VPC = 4,
  HPC_GPU_ADRENO_A5XX_LRZ_STALL_CYCLES_FLAG_PREFETCH = 5,
  HPC_GPU_ADRENO_A5XX_LRZ_STALL_CYCLES_UCHE = 6,
  HPC_GPU_ADRENO_A5XX_LRZ_LRZ_READ = 7,
  HPC_GPU_ADRENO_A5XX_LRZ_LRZ_WRITE = 8,
  HPC_GPU_ADRENO_A5XX_LRZ_READ_LATENCY = 9,
  HPC_GPU_ADRENO_A5XX_LRZ_MERGE_CACHE_UPDATING = 10,
  HPC_GPU_ADRENO_A5XX_LRZ_PRIM_KILLED_BY_MASKGEN = 11,
  HPC_GPU_ADRENO_A5XX_LRZ_PRIM_KILLED_BY_LRZ = 12,
  HPC_GPU_ADRENO_A5XX_LRZ_VISIBLE_PRIM_AFTER_LRZ = 13,
  HPC_GPU_ADRENO_A5XX_LRZ_FULL_8X8_TILES = 14,
  HPC_GPU_ADRENO_A5XX_LRZ_PARTIAL_8X8_TILES = 15,
  HPC_GPU_ADRENO_A5XX_LRZ_TILE_KILLED = 16,
  HPC_GPU_ADRENO_A5XX_LRZ_TOTAL_PIXEL = 17,
  HPC_GPU_ADRENO_A5XX_LRZ_VISIBLE_PIXEL_AFTER_LRZ = 18
} hpc_gpu_adreno_a5xx_lrz_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_pc_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_PC_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_PC_WORKING_CYCLES = 1,
  HPC_GPU_ADRENO_A5XX_PC_STALL_CYCLES_VFD = 2,
  HPC_GPU_ADRENO_A5XX_PC_STALL_CYCLES_TSE = 3,
  HPC_GPU_ADRENO_A5XX_PC_STALL_CYCLES_VPC = 4,
  HPC_GPU_ADRENO_A5XX_PC_STALL_CYCLES_UCHE = 5,
  HPC_GPU_ADRENO_A5XX_PC_STALL_CYCLES_TESS = 6,
  HPC_GPU_ADRENO_A5XX_PC_STALL_CYCLES_TSE_ONLY = 7,
  HPC_GPU_ADRENO_A5XX_PC_STALL_CYCLES_VPC_ONLY = 8,
  HPC_GPU_ADRENO_A5XX_PC_PASS1_TF_STALL_CYCLES = 9,
  HPC_GPU_ADRENO_A5XX_PC_STARVE_CYCLES_FOR_INDEX = 10,
  HPC_GPU_ADRENO_A5XX_PC_STARVE_CYCLES_FOR_TESS_FACTOR = 11,
  HPC_GPU_ADRENO_A5XX_PC_STARVE_CYCLES_FOR_VIZ_STREAM = 12,
  HPC_GPU_ADRENO_A5XX_PC_STARVE_CYCLES_FOR_POSITION = 13,
  HPC_GPU_ADRENO_A5XX_PC_STARVE_CYCLES_DI = 14,
  HPC_GPU_ADRENO_A5XX_PC_VIS_STREAMS_LOADED = 15,
  HPC_GPU_ADRENO_A5XX_PC_INSTANCES = 16,
  HPC_GPU_ADRENO_A5XX_PC_VPC_PRIMITIVES = 17,
  HPC_GPU_ADRENO_A5XX_PC_DEAD_PRIM = 18,
  HPC_GPU_ADRENO_A5XX_PC_LIVE_PRIM = 19,
  HPC_GPU_ADRENO_A5XX_PC_VERTEX_HITS = 20,
  HPC_GPU_ADRENO_A5XX_PC_IA_VERTICES = 21,
  HPC_GPU_ADRENO_A5XX_PC_IA_PRIMITIVES = 22,
  HPC_GPU_ADRENO_A5XX_PC_GS_PRIMITIVES = 23,
  HPC_GPU_ADRENO_A5XX_PC_HS_INVOCATIONS = 24,
  HPC_GPU_ADRENO_A5XX_PC_DS_INVOCATIONS = 25,
  HPC_GPU_ADRENO_A5XX_PC_VS_INVOCATIONS = 26,
  HPC_GPU_ADRENO_A5XX_PC_GS_INVOCATIONS = 27,
  HPC_GPU_ADRENO_A5XX_PC_DS_PRIMITIVES = 28,
  HPC_GPU_ADRENO_A5XX_PC_VPC_POS_DATA_TRANSACTION = 29,
  HPC_GPU_ADRENO_A5XX_PC_3D_DRAWCALLS = 30,
  HPC_GPU_ADRENO_A5XX_PC_2D_DRAWCALLS = 31,
  HPC_GPU_ADRENO_A5XX_PC_NON_DRAWCALL_GLOBAL_EVENTS = 32,
  HPC_GPU_ADRENO_A5XX_PC_TESS_BUSY_CYCLES = 33,
  HPC_GPU_ADRENO_A5XX_PC_TESS_WORKING_CYCLES = 34,
  HPC_GPU_ADRENO_A5XX_PC_TESS_STALL_CYCLES_PC = 35,
  HPC_GPU_ADRENO_A5XX_PC_TESS_STARVE_CYCLES_PC = 36
} hpc_gpu_adreno_a5xx_pc_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_ras_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_RAS_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_RAS_SUPERTILE_ACTIVE_CYCLES = 1,
  HPC_GPU_ADRENO_A5XX_RAS_STALL_CYCLES_LRZ = 2,
  HPC_GPU_ADRENO_A5XX_RAS_STARVE_CYCLES_TSE = 3,
  HPC_GPU_ADRENO_A5XX_RAS_SUPER_TILES = 4,
  HPC_GPU_ADRENO_A5XX_RAS_8X4_TILES = 5,
  HPC_GPU_ADRENO_A5XX_RAS_MASKGEN_ACTIVE = 6,
  HPC_GPU_ADRENO_A5XX_RAS_FULLY_COVERED_SUPER_TILES = 7,
  HPC_GPU_ADRENO_A5XX_RAS_FULLY_COVERED_8X4_TILES = 8,
  HPC_GPU_ADRENO_A5XX_RAS_PRIM_KILLED_INVISILBE = 9
} hpc_gpu_adreno_a5xx_ras_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_rb_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_RB_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_RB_STALL_CYCLES_CCU = 1,
  HPC_GPU_ADRENO_A5XX_RB_STALL_CYCLES_HLSQ = 2,
  HPC_GPU_ADRENO_A5XX_RB_STALL_CYCLES_FIFO0_FULL = 3,
  HPC_GPU_ADRENO_A5XX_RB_STALL_CYCLES_FIFO1_FULL = 4,
  HPC_GPU_ADRENO_A5XX_RB_STALL_CYCLES_FIFO2_FULL = 5,
  HPC_GPU_ADRENO_A5XX_RB_STARVE_CYCLES_SP = 6,
  HPC_GPU_ADRENO_A5XX_RB_STARVE_CYCLES_LRZ_TILE = 7,
  HPC_GPU_ADRENO_A5XX_RB_STARVE_CYCLES_CCU = 8,
  HPC_GPU_ADRENO_A5XX_RB_STARVE_CYCLES_Z_PLANE = 9,
  HPC_GPU_ADRENO_A5XX_RB_STARVE_CYCLES_BARY_PLANE = 10,
  HPC_GPU_ADRENO_A5XX_RB_Z_WORKLOAD = 11,
  HPC_GPU_ADRENO_A5XX_RB_HLSQ_ACTIVE = 12,
  HPC_GPU_ADRENO_A5XX_RB_Z_READ = 13,
  HPC_GPU_ADRENO_A5XX_RB_Z_WRITE = 14,
  HPC_GPU_ADRENO_A5XX_RB_C_READ = 15,
  HPC_GPU_ADRENO_A5XX_RB_C_WRITE = 16,
  HPC_GPU_ADRENO_A5XX_RB_TOTAL_PASS = 17,
  HPC_GPU_ADRENO_A5XX_RB_Z_PASS = 18,
  HPC_GPU_ADRENO_A5XX_RB_Z_FAIL = 19,
  HPC_GPU_ADRENO_A5XX_RB_S_FAIL = 20,
  HPC_GPU_ADRENO_A5XX_RB_BLENDED_FXP_COMPONENTS = 21,
  HPC_GPU_ADRENO_A5XX_RB_BLENDED_FP16_COMPONENTS = 22,
  HPC_GPU_ADRENO_A5XX_RB_RESERVED = 23,
  HPC_GPU_ADRENO_A5XX_RB_2D_ALIVE_CYCLES = 24,
  HPC_GPU_ADRENO_A5XX_RB_2D_STALL_CYCLES_A2D = 25,
  HPC_GPU_ADRENO_A5XX_RB_2D_STARVE_CYCLES_SRC = 26,
  HPC_GPU_ADRENO_A5XX_RB_2D_STARVE_CYCLES_SP = 27,
  HPC_GPU_ADRENO_A5XX_RB_2D_STARVE_CYCLES_DST = 28,
  HPC_GPU_ADRENO_A5XX_RB_2D_VALID_PIXELS = 29
} hpc_gpu_adreno_a5xx_rb_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_rbbm_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_RBBM_ALWAYS_COUNT = 0,
  HPC_GPU_ADRENO_A5XX_RBBM_ALWAYS_ON = 1,
  HPC_GPU_ADRENO_A5XX_RBBM_TSE_BUSY = 2,
  HPC_GPU_ADRENO_A5XX_RBBM_RAS_BUSY = 3,
  HPC_GPU_ADRENO_A5XX_RBBM_PC_DCALL_BUSY = 4,
  HPC_GPU_ADRENO_A5XX_RBBM_PC_VSD_BUSY = 5,
  HPC_GPU_ADRENO_A5XX_RBBM_STATUS_MASKED = 6,
  HPC_GPU_ADRENO_A5XX_RBBM_COM_BUSY = 7,
  HPC_GPU_ADRENO_A5XX_RBBM_DCOM_BUSY = 8,
  HPC_GPU_ADRENO_A5XX_RBBM_VBIF_BUSY = 9,
  HPC_GPU_ADRENO_A5XX_RBBM_VSC_BUSY = 10,
  HPC_GPU_ADRENO_A5XX_RBBM_TESS_BUSY = 11,
  HPC_GPU_ADRENO_A5XX_RBBM_UCHE_BUSY = 12,
  HPC_GPU_ADRENO_A5XX_RBBM_HLSQ_BUSY = 13
} hpc_gpu_adreno_a5xx_rbbm_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_rb_samples_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_RB_SAMPLES_TOTAL_SAMPLES = 0,
  HPC_GPU_ADRENO_A5XX_RB_SAMPLES_ZPASS_SAMPLES = 1,
  HPC_GPU_ADRENO_A5XX_RB_SAMPLES_ZFAIL_SAMPLES = 2,
  HPC_GPU_ADRENO_A5XX_RB_SAMPLES_SFAIL_SAMPLES = 3
} hpc_gpu_adreno_a5xx_rb_samples_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_sp_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_SP_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_SP_ALU_WORKING_CYCLES = 1,
  HPC_GPU_ADRENO_A5XX_SP_EFU_WORKING_CYCLES = 2,
  HPC_GPU_ADRENO_A5XX_SP_STALL_CYCLES_VPC = 3,
  HPC_GPU_ADRENO_A5XX_SP_STALL_CYCLES_TP = 4,
  HPC_GPU_ADRENO_A5XX_SP_STALL_CYCLES_UCHE = 5,
  HPC_GPU_ADRENO_A5XX_SP_STALL_CYCLES_RB = 6,
  HPC_GPU_ADRENO_A5XX_SP_SCHEDULER_NON_WORKING = 7,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_CONTEXTS = 8,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_CONTEXT_CYCLES = 9,
  HPC_GPU_ADRENO_A5XX_SP_FS_STAGE_WAVE_CYCLES = 10,
  HPC_GPU_ADRENO_A5XX_SP_FS_STAGE_WAVE_SAMPLES = 11,
  HPC_GPU_ADRENO_A5XX_SP_VS_STAGE_WAVE_CYCLES = 12,
  HPC_GPU_ADRENO_A5XX_SP_VS_STAGE_WAVE_SAMPLES = 13,
  HPC_GPU_ADRENO_A5XX_SP_FS_STAGE_DURATION_CYCLES = 14,
  HPC_GPU_ADRENO_A5XX_SP_VS_STAGE_DURATION_CYCLES = 15,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_CTRL_CYCLES = 16,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_LOAD_CYCLES = 17,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_EMIT_CYCLES = 18,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_NOP_CYCLES = 19,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_WAIT_CYCLES = 20,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_FETCH_CYCLES = 21,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_IDLE_CYCLES = 22,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_END_CYCLES = 23,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_LONG_SYNC_CYCLES = 24,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_SHORT_SYNC_CYCLES = 25,
  HPC_GPU_ADRENO_A5XX_SP_WAVE_JOIN_CYCLES = 26,
  HPC_GPU_ADRENO_A5XX_SP_LM_LOAD_INSTRUCTIONS = 27,
  HPC_GPU_ADRENO_A5XX_SP_LM_STORE_INSTRUCTIONS = 28,
  HPC_GPU_ADRENO_A5XX_SP_LM_ATOMICS = 29,
  HPC_GPU_ADRENO_A5XX_SP_GM_LOAD_INSTRUCTIONS = 30,
  HPC_GPU_ADRENO_A5XX_SP_GM_STORE_INSTRUCTIONS = 31,
  HPC_GPU_ADRENO_A5XX_SP_GM_ATOMICS = 32,
  HPC_GPU_ADRENO_A5XX_SP_VS_STAGE_TEX_INSTRUCTIONS = 33,
  HPC_GPU_ADRENO_A5XX_SP_VS_STAGE_CFLOW_INSTRUCTIONS = 34,
  HPC_GPU_ADRENO_A5XX_SP_VS_STAGE_EFU_INSTRUCTIONS = 35,
  HPC_GPU_ADRENO_A5XX_SP_VS_STAGE_FULL_ALU_INSTRUCTIONS = 36,
  HPC_GPU_ADRENO_A5XX_SP_VS_STAGE_HALF_ALU_INSTRUCTIONS = 37,
  HPC_GPU_ADRENO_A5XX_SP_FS_STAGE_TEX_INSTRUCTIONS = 38,
  HPC_GPU_ADRENO_A5XX_SP_FS_STAGE_CFLOW_INSTRUCTIONS = 39,
  HPC_GPU_ADRENO_A5XX_SP_FS_STAGE_EFU_INSTRUCTIONS = 40,
  HPC_GPU_ADRENO_A5XX_SP_FS_STAGE_FULL_ALU_INSTRUCTIONS = 41,
  HPC_GPU_ADRENO_A5XX_SP_FS_STAGE_HALF_ALU_INSTRUCTIONS = 42,
  HPC_GPU_ADRENO_A5XX_SP_FS_STAGE_BARY_INSTRUCTIONS = 43,
  HPC_GPU_ADRENO_A5XX_SP_VS_INSTRUCTIONS = 44,
  HPC_GPU_ADRENO_A5XX_SP_FS_INSTRUCTIONS = 45,
  HPC_GPU_ADRENO_A5XX_SP_ADDR_LOCK_COUNT = 46,
  HPC_GPU_ADRENO_A5XX_SP_UCHE_READ_TRANS = 47,
  HPC_GPU_ADRENO_A5XX_SP_UCHE_WRITE_TRANS = 48,
  HPC_GPU_ADRENO_A5XX_SP_EXPORT_VPC_TRANS = 49,
  HPC_GPU_ADRENO_A5XX_SP_EXPORT_RB_TRANS = 50,
  HPC_GPU_ADRENO_A5XX_SP_PIXELS_KILLED = 51,
  HPC_GPU_ADRENO_A5XX_SP_ICL1_REQUESTS = 52,
  HPC_GPU_ADRENO_A5XX_SP_ICL1_MISSES = 53,
  HPC_GPU_ADRENO_A5XX_SP_ICL0_REQUESTS = 54,
  HPC_GPU_ADRENO_A5XX_SP_ICL0_MISSES = 55,
  HPC_GPU_ADRENO_A5XX_SP_HS_INSTRUCTIONS = 56,
  HPC_GPU_ADRENO_A5XX_SP_DS_INSTRUCTIONS = 57,
  HPC_GPU_ADRENO_A5XX_SP_GS_INSTRUCTIONS = 58,
  HPC_GPU_ADRENO_A5XX_SP_CS_INSTRUCTIONS = 59,
  HPC_GPU_ADRENO_A5XX_SP_GPR_READ = 60,
  HPC_GPU_ADRENO_A5XX_SP_GPR_WRITE = 61,
  HPC_GPU_ADRENO_A5XX_SP_LM_CH0_REQUESTS = 62,
  HPC_GPU_ADRENO_A5XX_SP_LM_CH1_REQUESTS = 63,
  HPC_GPU_ADRENO_A5XX_SP_LM_BANK_CONFLICTS = 64
} hpc_gpu_adreno_a5xx_sp_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_tp_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_TP_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_TP_STALL_CYCLES_UCHE = 1,
  HPC_GPU_ADRENO_A5XX_TP_LATENCY_CYCLES = 2,
  HPC_GPU_ADRENO_A5XX_TP_LATENCY_TRANS = 3,
  HPC_GPU_ADRENO_A5XX_TP_FLAG_CACHE_REQUEST_SAMPLES = 4,
  HPC_GPU_ADRENO_A5XX_TP_FLAG_CACHE_REQUEST_LATENCY = 5,
  HPC_GPU_ADRENO_A5XX_TP_L1_CACHELINE_REQUESTS = 6,
  HPC_GPU_ADRENO_A5XX_TP_L1_CACHELINE_MISSES = 7,
  HPC_GPU_ADRENO_A5XX_TP_SP_TP_TRANS = 8,
  HPC_GPU_ADRENO_A5XX_TP_TP_SP_TRANS = 9,
  HPC_GPU_ADRENO_A5XX_TP_OUTPUT_PIXELS = 10,
  HPC_GPU_ADRENO_A5XX_TP_FILTER_WORKLOAD_16BIT = 11,
  HPC_GPU_ADRENO_A5XX_TP_FILTER_WORKLOAD_32BIT = 12,
  HPC_GPU_ADRENO_A5XX_TP_QUADS_RECEIVED = 13,
  HPC_GPU_ADRENO_A5XX_TP_QUADS_OFFSET = 14,
  HPC_GPU_ADRENO_A5XX_TP_QUADS_SHADOW = 15,
  HPC_GPU_ADRENO_A5XX_TP_QUADS_ARRAY = 16,
  HPC_GPU_ADRENO_A5XX_TP_QUADS_GRADIENT = 17,
  HPC_GPU_ADRENO_A5XX_TP_QUADS_1D = 18,
  HPC_GPU_ADRENO_A5XX_TP_QUADS_2D = 19,
  HPC_GPU_ADRENO_A5XX_TP_QUADS_BUFFER = 20,
  HPC_GPU_ADRENO_A5XX_TP_QUADS_3D = 21,
  HPC_GPU_ADRENO_A5XX_TP_QUADS_CUBE = 22,
  HPC_GPU_ADRENO_A5XX_TP_STATE_CACHE_REQUESTS = 23,
  HPC_GPU_ADRENO_A5XX_TP_STATE_CACHE_MISSES = 24,
  HPC_GPU_ADRENO_A5XX_TP_DIVERGENT_QUADS_RECEIVED = 25,
  HPC_GPU_ADRENO_A5XX_TP_BINDLESS_STATE_CACHE_REQUESTS = 26,
  HPC_GPU_ADRENO_A5XX_TP_BINDLESS_STATE_CACHE_MISSES = 27,
  HPC_GPU_ADRENO_A5XX_TP_PRT_NON_RESIDENT_EVENTS = 28,
  HPC_GPU_ADRENO_A5XX_TP_OUTPUT_PIXELS_POINT = 29,
  HPC_GPU_ADRENO_A5XX_TP_OUTPUT_PIXELS_BILINEAR = 30,
  HPC_GPU_ADRENO_A5XX_TP_OUTPUT_PIXELS_MIP = 31,
  HPC_GPU_ADRENO_A5XX_TP_OUTPUT_PIXELS_ANISO = 32,
  HPC_GPU_ADRENO_A5XX_TP_OUTPUT_PIXELS_ZERO_LOD = 33,
  HPC_GPU_ADRENO_A5XX_TP_FLAG_CACHE_REQUESTS = 34,
  HPC_GPU_ADRENO_A5XX_TP_FLAG_CACHE_MISSES = 35,
  HPC_GPU_ADRENO_A5XX_TP_L1_5_L2_REQUESTS = 36,
  HPC_GPU_ADRENO_A5XX_TP_2D_OUTPUT_PIXELS = 37,
  HPC_GPU_ADRENO_A5XX_TP_2D_OUTPUT_PIXELS_POINT = 38,
  HPC_GPU_ADRENO_A5XX_TP_2D_OUTPUT_PIXELS_BILINEAR = 39,
  HPC_GPU_ADRENO_A5XX_TP_2D_FILTER_WORKLOAD_16BIT = 40,
  HPC_GPU_ADRENO_A5XX_TP_2D_FILTER_WORKLOAD_32BIT = 41
} hpc_gpu_adreno_a5xx_tp_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_tse_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_TSE_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_TSE_CLIPPING_CYCLES = 1,
  HPC_GPU_ADRENO_A5XX_TSE_STALL_CYCLES_RAS = 2,
  HPC_GPU_ADRENO_A5XX_TSE_STALL_CYCLES_LRZ_BARYPLANE = 3,
  HPC_GPU_ADRENO_A5XX_TSE_STALL_CYCLES_LRZ_ZPLANE = 4,
  HPC_GPU_ADRENO_A5XX_TSE_STARVE_CYCLES_PC = 5,
  HPC_GPU_ADRENO_A5XX_TSE_INPUT_PRIM = 6,
  HPC_GPU_ADRENO_A5XX_TSE_INPUT_NULL_PRIM = 7,
  HPC_GPU_ADRENO_A5XX_TSE_TRIVAL_REJ_PRIM = 8,
  HPC_GPU_ADRENO_A5XX_TSE_CLIPPED_PRIM = 9,
  HPC_GPU_ADRENO_A5XX_TSE_ZERO_AREA_PRIM = 10,
  HPC_GPU_ADRENO_A5XX_TSE_FACENESS_CULLED_PRIM = 11,
  HPC_GPU_ADRENO_A5XX_TSE_ZERO_PIXEL_PRIM = 12,
  HPC_GPU_ADRENO_A5XX_TSE_OUTPUT_NULL_PRIM = 13,
  HPC_GPU_ADRENO_A5XX_TSE_OUTPUT_VISIBLE_PRIM = 14,
  HPC_GPU_ADRENO_A5XX_TSE_CINVOCATION = 15,
  HPC_GPU_ADRENO_A5XX_TSE_CPRIMITIVES = 16,
  HPC_GPU_ADRENO_A5XX_TSE_2D_INPUT_PRIM = 17,
  HPC_GPU_ADRENO_A5XX_TSE_2D_ALIVE_CLCLES = 18
} hpc_gpu_adreno_a5xx_tse_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_uche_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_UCHE_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_UCHE_STALL_CYCLES_VBIF = 1,
  HPC_GPU_ADRENO_A5XX_UCHE_VBIF_LATENCY_CYCLES = 2,
  HPC_GPU_ADRENO_A5XX_UCHE_VBIF_LATENCY_SAMPLES = 3,
  HPC_GPU_ADRENO_A5XX_UCHE_VBIF_READ_BEATS_TP = 4,
  HPC_GPU_ADRENO_A5XX_UCHE_VBIF_READ_BEATS_VFD = 5,
  HPC_GPU_ADRENO_A5XX_UCHE_VBIF_READ_BEATS_HLSQ = 6,
  HPC_GPU_ADRENO_A5XX_UCHE_VBIF_READ_BEATS_LRZ = 7,
  HPC_GPU_ADRENO_A5XX_UCHE_VBIF_READ_BEATS_SP = 8,
  HPC_GPU_ADRENO_A5XX_UCHE_READ_REQUESTS_TP = 9,
  HPC_GPU_ADRENO_A5XX_UCHE_READ_REQUESTS_VFD = 10,
  HPC_GPU_ADRENO_A5XX_UCHE_READ_REQUESTS_HLSQ = 11,
  HPC_GPU_ADRENO_A5XX_UCHE_READ_REQUESTS_LRZ = 12,
  HPC_GPU_ADRENO_A5XX_UCHE_READ_REQUESTS_SP = 13,
  HPC_GPU_ADRENO_A5XX_UCHE_WRITE_REQUESTS_LRZ = 14,
  HPC_GPU_ADRENO_A5XX_UCHE_WRITE_REQUESTS_SP = 15,
  HPC_GPU_ADRENO_A5XX_UCHE_WRITE_REQUESTS_VPC = 16,
  HPC_GPU_ADRENO_A5XX_UCHE_WRITE_REQUESTS_VSC = 17,
  HPC_GPU_ADRENO_A5XX_UCHE_EVICTS = 18,
  HPC_GPU_ADRENO_A5XX_UCHE_BANK_REQ0 = 19,
  HPC_GPU_ADRENO_A5XX_UCHE_BANK_REQ1 = 20,
  HPC_GPU_ADRENO_A5XX_UCHE_BANK_REQ2 = 21,
  HPC_GPU_ADRENO_A5XX_UCHE_BANK_REQ3 = 22,
  HPC_GPU_ADRENO_A5XX_UCHE_BANK_REQ4 = 23,
  HPC_GPU_ADRENO_A5XX_UCHE_BANK_REQ5 = 24,
  HPC_GPU_ADRENO_A5XX_UCHE_BANK_REQ6 = 25,
  HPC_GPU_ADRENO_A5XX_UCHE_BANK_REQ7 = 26,
  HPC_GPU_ADRENO_A5XX_UCHE_VBIF_READ_BEATS_CH0 = 27,
  HPC_GPU_ADRENO_A5XX_UCHE_VBIF_READ_BEATS_CH1 = 28,
  HPC_GPU_ADRENO_A5XX_UCHE_GMEM_READ_BEATS = 29,
  HPC_GPU_ADRENO_A5XX_UCHE_FLAG_COUNT = 30
} hpc_gpu_adreno_a5xx_uche_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_vbif_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_0 = 0,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_1 = 1,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_2 = 2,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_3 = 3,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_4 = 4,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_5 = 5,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_6 = 6,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_7 = 7,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_8 = 8,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_9 = 9,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_10 = 10,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_11 = 11,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_12 = 12,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_13 = 13,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_14 = 14,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_ID_15 = 15,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI0_READ_REQUESTS_TOTAL = 16,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI1_READ_REQUESTS_TOTAL = 17,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI2_READ_REQUESTS_TOTAL = 18,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI3_READ_REQUESTS_TOTAL = 19,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_REQUESTS_TOTAL = 20,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_0 = 21,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_1 = 22,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_2 = 23,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_3 = 24,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_4 = 25,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_5 = 26,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_6 = 27,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_7 = 28,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_8 = 29,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_9 = 30,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_10 = 31,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_11 = 32,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_12 = 33,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_13 = 34,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_14 = 35,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_ID_15 = 36,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI0_WRITE_REQUESTS_TOTAL = 37,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI1_WRITE_REQUESTS_TOTAL = 38,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI2_WRITE_REQUESTS_TOTAL = 39,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI3_WRITE_REQUESTS_TOTAL = 40,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_REQUESTS_TOTAL = 41,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_TOTAL_REQUESTS = 42,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_0 = 43,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_1 = 44,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_2 = 45,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_3 = 46,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_4 = 47,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_5 = 48,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_6 = 49,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_7 = 50,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_8 = 51,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_9 = 52,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_10 = 53,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_11 = 54,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_12 = 55,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_13 = 56,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_14 = 57,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_ID_15 = 58,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI0_READ_DATA_BEATS_TOTAL = 59,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI1_READ_DATA_BEATS_TOTAL = 60,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI2_READ_DATA_BEATS_TOTAL = 61,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI3_READ_DATA_BEATS_TOTAL = 62,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_READ_DATA_BEATS_TOTAL = 63,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_0 = 64,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_1 = 65,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_2 = 66,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_3 = 67,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_4 = 68,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_5 = 69,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_6 = 70,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_7 = 71,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_8 = 72,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_9 = 73,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_10 = 74,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_11 = 75,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_12 = 76,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_13 = 77,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_14 = 78,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_ID_15 = 79,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI0_WRITE_DATA_BEATS_TOTAL = 80,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI1_WRITE_DATA_BEATS_TOTAL = 81,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI2_WRITE_DATA_BEATS_TOTAL = 82,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI3_WRITE_DATA_BEATS_TOTAL = 83,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_WRITE_DATA_BEATS_TOTAL = 84,
  HPC_GPU_ADRENO_A5XX_VBIF_AXI_DATA_BEATS_TOTAL = 85
} hpc_gpu_adreno_a5xx_vbif_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_vfd_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_VFD_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_VFD_STALL_CYCLES_UCHE = 1,
  HPC_GPU_ADRENO_A5XX_VFD_STALL_CYCLES_VPC_ALLOC = 2,
  HPC_GPU_ADRENO_A5XX_VFD_STALL_CYCLES_MISS_VB = 3,
  HPC_GPU_ADRENO_A5XX_VFD_STALL_CYCLES_MISS_Q = 4,
  HPC_GPU_ADRENO_A5XX_VFD_STALL_CYCLES_SP_INFO = 5,
  HPC_GPU_ADRENO_A5XX_VFD_STALL_CYCLES_SP_ATTR = 6,
  HPC_GPU_ADRENO_A5XX_VFD_STALL_CYCLES_VFDP_VB = 7,
  HPC_GPU_ADRENO_A5XX_VFD_STALL_CYCLES_VFDP_Q = 8,
  HPC_GPU_ADRENO_A5XX_VFD_DECODER_PACKER_STALL = 9,
  HPC_GPU_ADRENO_A5XX_VFD_STARVE_CYCLES_UCHE = 10,
  HPC_GPU_ADRENO_A5XX_VFD_RBUFFER_FULL = 11,
  HPC_GPU_ADRENO_A5XX_VFD_ATTR_INFO_FIFO_FULL = 12,
  HPC_GPU_ADRENO_A5XX_VFD_DECODED_ATTRIBUTE_BYTES = 13,
  HPC_GPU_ADRENO_A5XX_VFD_NUM_ATTRIBUTES = 14,
  HPC_GPU_ADRENO_A5XX_VFD_INSTRUCTIONS = 15,
  HPC_GPU_ADRENO_A5XX_VFD_UPPER_SHADER_FIBERS = 16,
  HPC_GPU_ADRENO_A5XX_VFD_LOWER_SHADER_FIBERS = 17,
  HPC_GPU_ADRENO_A5XX_VFD_MODE_0_FIBERS = 18,
  HPC_GPU_ADRENO_A5XX_VFD_MODE_1_FIBERS = 19,
  HPC_GPU_ADRENO_A5XX_VFD_MODE_2_FIBERS = 20,
  HPC_GPU_ADRENO_A5XX_VFD_MODE_3_FIBERS = 21,
  HPC_GPU_ADRENO_A5XX_VFD_MODE_4_FIBERS = 22,
  HPC_GPU_ADRENO_A5XX_VFD_TOTAL_VERTICES = 23,
  HPC_GPU_ADRENO_A5XX_VFD_NUM_ATTR_MISS = 24,
  HPC_GPU_ADRENO_A5XX_VFD_1_BURST_REQ = 25,
  HPC_GPU_ADRENO_A5XX_VFD_VFDP_STALL_CYCLES_VFD = 26,
  HPC_GPU_ADRENO_A5XX_VFD_VFDP_STALL_CYCLES_VFD_INDEX = 27,
  HPC_GPU_ADRENO_A5XX_VFD_VFDP_STALL_CYCLES_VFD_PROG = 28,
  HPC_GPU_ADRENO_A5XX_VFD_VFDP_STARVE_CYCLES_PC = 29,
  HPC_GPU_ADRENO_A5XX_VFD_VFDP_VS_STAGE_32_WAVES = 30
} hpc_gpu_adreno_a5xx_vfd_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_vpc_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_VPC_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_VPC_WORKING_CYCLES = 1,
  HPC_GPU_ADRENO_A5XX_VPC_STALL_CYCLES_UCHE = 2,
  HPC_GPU_ADRENO_A5XX_VPC_STALL_CYCLES_VFD_WACK = 3,
  HPC_GPU_ADRENO_A5XX_VPC_STALL_CYCLES_HLSQ_PRIM_ALLOC = 4,
  HPC_GPU_ADRENO_A5XX_VPC_STALL_CYCLES_PC = 5,
  HPC_GPU_ADRENO_A5XX_VPC_STALL_CYCLES_SP_LM = 6,
  HPC_GPU_ADRENO_A5XX_VPC_POS_EXPORT_STALL_CYCLES = 7,
  HPC_GPU_ADRENO_A5XX_VPC_STARVE_CYCLES_SP = 8,
  HPC_GPU_ADRENO_A5XX_VPC_STARVE_CYCLES_LRZ = 9,
  HPC_GPU_ADRENO_A5XX_VPC_PC_PRIMITIVES = 10,
  HPC_GPU_ADRENO_A5XX_VPC_SP_COMPONENTS = 11,
  HPC_GPU_ADRENO_A5XX_VPC_SP_LM_PRIMITIVES = 12,
  HPC_GPU_ADRENO_A5XX_VPC_SP_LM_COMPONENTS = 13,
  HPC_GPU_ADRENO_A5XX_VPC_SP_LM_DWORDS = 14,
  HPC_GPU_ADRENO_A5XX_VPC_STREAMOUT_COMPONENTS = 15,
  HPC_GPU_ADRENO_A5XX_VPC_GRANT_PHASES = 16
} hpc_gpu_adreno_a5xx_vpc_perfcounter_t;

typedef enum hpc_gpu_adreno_a5xx_vsc_perfcounter_e {
  HPC_GPU_ADRENO_A5XX_VSC_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A5XX_VSC_WORKING_CYCLES = 1,
  HPC_GPU_ADRENO_A5XX_VSC_STALL_CYCLES_UCHE = 2,
  HPC_GPU_ADRENO_A5XX_VSC_EOT_NUM = 3
} hpc_gpu_adreno_a5xx_vsc_perfcounter_t;

#endif  // HPC_GPU_ADRENO_A5XX_H_