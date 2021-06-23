// AUTOGENERATED; DO NOT EDIT!

#ifndef HPC_GPU_ADRENO_A6XX_H_
#define HPC_GPU_ADRENO_A6XX_H_

typedef enum hpc_gpu_adreno_a6xx_ccu_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_CCU_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_CCU_STALL_CYCLES_RB_DEPTH_RETURN = 1,
  HPC_GPU_ADRENO_A6XX_CCU_STALL_CYCLES_RB_COLOR_RETURN = 2,
  HPC_GPU_ADRENO_A6XX_CCU_STARVE_CYCLES_FLAG_RETURN = 3,
  HPC_GPU_ADRENO_A6XX_CCU_DEPTH_BLOCKS = 4,
  HPC_GPU_ADRENO_A6XX_CCU_COLOR_BLOCKS = 5,
  HPC_GPU_ADRENO_A6XX_CCU_DEPTH_BLOCK_HIT = 6,
  HPC_GPU_ADRENO_A6XX_CCU_COLOR_BLOCK_HIT = 7,
  HPC_GPU_ADRENO_A6XX_CCU_PARTIAL_BLOCK_READ = 8,
  HPC_GPU_ADRENO_A6XX_CCU_GMEM_READ = 9,
  HPC_GPU_ADRENO_A6XX_CCU_GMEM_WRITE = 10,
  HPC_GPU_ADRENO_A6XX_CCU_DEPTH_READ_FLAG0_COUNT = 11,
  HPC_GPU_ADRENO_A6XX_CCU_DEPTH_READ_FLAG1_COUNT = 12,
  HPC_GPU_ADRENO_A6XX_CCU_DEPTH_READ_FLAG2_COUNT = 13,
  HPC_GPU_ADRENO_A6XX_CCU_DEPTH_READ_FLAG3_COUNT = 14,
  HPC_GPU_ADRENO_A6XX_CCU_DEPTH_READ_FLAG4_COUNT = 15,
  HPC_GPU_ADRENO_A6XX_CCU_DEPTH_READ_FLAG5_COUNT = 16,
  HPC_GPU_ADRENO_A6XX_CCU_DEPTH_READ_FLAG6_COUNT = 17,
  HPC_GPU_ADRENO_A6XX_CCU_DEPTH_READ_FLAG8_COUNT = 18,
  HPC_GPU_ADRENO_A6XX_CCU_COLOR_READ_FLAG0_COUNT = 19,
  HPC_GPU_ADRENO_A6XX_CCU_COLOR_READ_FLAG1_COUNT = 20,
  HPC_GPU_ADRENO_A6XX_CCU_COLOR_READ_FLAG2_COUNT = 21,
  HPC_GPU_ADRENO_A6XX_CCU_COLOR_READ_FLAG3_COUNT = 22,
  HPC_GPU_ADRENO_A6XX_CCU_COLOR_READ_FLAG4_COUNT = 23,
  HPC_GPU_ADRENO_A6XX_CCU_COLOR_READ_FLAG5_COUNT = 24,
  HPC_GPU_ADRENO_A6XX_CCU_COLOR_READ_FLAG6_COUNT = 25,
  HPC_GPU_ADRENO_A6XX_CCU_COLOR_READ_FLAG8_COUNT = 26,
  HPC_GPU_ADRENO_A6XX_CCU_2D_RD_REQ = 27,
  HPC_GPU_ADRENO_A6XX_CCU_2D_WR_REQ = 28
} hpc_gpu_adreno_a6xx_ccu_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_cmp_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_STALL_CYCLES_ARB = 0,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_VBIF_LATENCY_CYCLES = 1,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_VBIF_LATENCY_SAMPLES = 2,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_VBIF_READ_DATA_CCU = 3,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_VBIF_WRITE_DATA_CCU = 4,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_VBIF_READ_REQUEST = 5,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_VBIF_WRITE_REQUEST = 6,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_VBIF_READ_DATA = 7,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_VBIF_WRITE_DATA = 8,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_FLAG_FETCH_CYCLES = 9,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_FLAG_FETCH_SAMPLES = 10,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_DEPTH_WRITE_FLAG1_COUNT = 11,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_DEPTH_WRITE_FLAG2_COUNT = 12,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_DEPTH_WRITE_FLAG3_COUNT = 13,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_DEPTH_WRITE_FLAG4_COUNT = 14,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_DEPTH_WRITE_FLAG5_COUNT = 15,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_DEPTH_WRITE_FLAG6_COUNT = 16,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_DEPTH_WRITE_FLAG8_COUNT = 17,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_COLOR_WRITE_FLAG1_COUNT = 18,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_COLOR_WRITE_FLAG2_COUNT = 19,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_COLOR_WRITE_FLAG3_COUNT = 20,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_COLOR_WRITE_FLAG4_COUNT = 21,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_COLOR_WRITE_FLAG5_COUNT = 22,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_COLOR_WRITE_FLAG6_COUNT = 23,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_COLOR_WRITE_FLAG8_COUNT = 24,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_2D_STALL_CYCLES_VBIF_REQ = 25,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_2D_STALL_CYCLES_VBIF_WR = 26,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_2D_STALL_CYCLES_VBIF_RETURN = 27,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_2D_RD_DATA = 28,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_2D_WR_DATA = 29,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_VBIF_READ_DATA_UCHE_CH0 = 30,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_VBIF_READ_DATA_UCHE_CH1 = 31,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_2D_OUTPUT_TRANS = 32,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_VBIF_WRITE_DATA_UCHE = 33,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_DEPTH_WRITE_FLAG0_COUNT = 34,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_COLOR_WRITE_FLAG0_COUNT = 35,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_COLOR_WRITE_FLAGALPHA_COUNT = 36,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_2D_BUSY_CYCLES = 37,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_2D_REORDER_STARVE_CYCLES = 38,
  HPC_GPU_ADRENO_A6XX_CMP_CMPDECMP_2D_PIXELS = 39
} hpc_gpu_adreno_a6xx_cmp_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_cp_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_CP_ALWAYS_COUNT = 0,
  HPC_GPU_ADRENO_A6XX_CP_BUSY_GFX_CORE_IDLE = 1,
  HPC_GPU_ADRENO_A6XX_CP_BUSY_CYCLES = 2,
  HPC_GPU_ADRENO_A6XX_CP_NUM_PREEMPTIONS = 3,
  HPC_GPU_ADRENO_A6XX_CP_PREEMPTION_REACTION_DELAY = 4,
  HPC_GPU_ADRENO_A6XX_CP_PREEMPTION_SWITCH_OUT_TIME = 5,
  HPC_GPU_ADRENO_A6XX_CP_PREEMPTION_SWITCH_IN_TIME = 6,
  HPC_GPU_ADRENO_A6XX_CP_DEAD_DRAWS_IN_BIN_RENDER = 7,
  HPC_GPU_ADRENO_A6XX_CP_PREDICATED_DRAWS_KILLED = 8,
  HPC_GPU_ADRENO_A6XX_CP_MODE_SWITCH = 9,
  HPC_GPU_ADRENO_A6XX_CP_ZPASS_DONE = 10,
  HPC_GPU_ADRENO_A6XX_CP_CONTEXT_DONE = 11,
  HPC_GPU_ADRENO_A6XX_CP_CACHE_FLUSH = 12,
  HPC_GPU_ADRENO_A6XX_CP_LONG_PREEMPTIONS = 13,
  HPC_GPU_ADRENO_A6XX_CP_SQE_I_CACHE_STARVE = 14,
  HPC_GPU_ADRENO_A6XX_CP_SQE_IDLE = 15,
  HPC_GPU_ADRENO_A6XX_CP_SQE_PM4_STARVE_RB_IB = 16,
  HPC_GPU_ADRENO_A6XX_CP_SQE_PM4_STARVE_SDS = 17,
  HPC_GPU_ADRENO_A6XX_CP_SQE_MRB_STARVE = 18,
  HPC_GPU_ADRENO_A6XX_CP_SQE_RRB_STARVE = 19,
  HPC_GPU_ADRENO_A6XX_CP_SQE_VSD_STARVE = 20,
  HPC_GPU_ADRENO_A6XX_CP_VSD_DECODE_STARVE = 21,
  HPC_GPU_ADRENO_A6XX_CP_SQE_PIPE_OUT_STALL = 22,
  HPC_GPU_ADRENO_A6XX_CP_SQE_SYNC_STALL = 23,
  HPC_GPU_ADRENO_A6XX_CP_SQE_PM4_WFI_STALL = 24,
  HPC_GPU_ADRENO_A6XX_CP_SQE_SYS_WFI_STALL = 25,
  HPC_GPU_ADRENO_A6XX_CP_SQE_T4_EXEC = 26,
  HPC_GPU_ADRENO_A6XX_CP_SQE_LOAD_STATE_EXEC = 27,
  HPC_GPU_ADRENO_A6XX_CP_SQE_SAVE_SDS_STATE = 28,
  HPC_GPU_ADRENO_A6XX_CP_SQE_DRAW_EXEC = 29,
  HPC_GPU_ADRENO_A6XX_CP_SQE_CTXT_REG_BUNCH_EXEC = 30,
  HPC_GPU_ADRENO_A6XX_CP_SQE_EXEC_PROFILED = 31,
  HPC_GPU_ADRENO_A6XX_CP_MEMORY_POOL_EMPTY = 32,
  HPC_GPU_ADRENO_A6XX_CP_MEMORY_POOL_SYNC_STALL = 33,
  HPC_GPU_ADRENO_A6XX_CP_MEMORY_POOL_ABOVE_THRESH = 34,
  HPC_GPU_ADRENO_A6XX_CP_AHB_WR_STALL_PRE_DRAWS = 35,
  HPC_GPU_ADRENO_A6XX_CP_AHB_STALL_SQE_GMU = 36,
  HPC_GPU_ADRENO_A6XX_CP_AHB_STALL_SQE_WR_OTHER = 37,
  HPC_GPU_ADRENO_A6XX_CP_AHB_STALL_SQE_RD_OTHER = 38,
  HPC_GPU_ADRENO_A6XX_CP_CLUSTER0_EMPTY = 39,
  HPC_GPU_ADRENO_A6XX_CP_CLUSTER1_EMPTY = 40,
  HPC_GPU_ADRENO_A6XX_CP_CLUSTER2_EMPTY = 41,
  HPC_GPU_ADRENO_A6XX_CP_CLUSTER3_EMPTY = 42,
  HPC_GPU_ADRENO_A6XX_CP_CLUSTER4_EMPTY = 43,
  HPC_GPU_ADRENO_A6XX_CP_CLUSTER5_EMPTY = 44,
  HPC_GPU_ADRENO_A6XX_CP_PM4_DATA = 45,
  HPC_GPU_ADRENO_A6XX_CP_PM4_HEADERS = 46,
  HPC_GPU_ADRENO_A6XX_CP_VBIF_READ_BEATS = 47,
  HPC_GPU_ADRENO_A6XX_CP_VBIF_WRITE_BEATS = 48,
  HPC_GPU_ADRENO_A6XX_CP_SQE_INSTR_COUNTER = 49
} hpc_gpu_adreno_a6xx_cp_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_hlsq_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_HLSQ_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_HLSQ_STALL_CYCLES_UCHE = 1,
  HPC_GPU_ADRENO_A6XX_HLSQ_STALL_CYCLES_SP_STATE = 2,
  HPC_GPU_ADRENO_A6XX_HLSQ_STALL_CYCLES_SP_FS_STAGE = 3,
  HPC_GPU_ADRENO_A6XX_HLSQ_UCHE_LATENCY_CYCLES = 4,
  HPC_GPU_ADRENO_A6XX_HLSQ_UCHE_LATENCY_COUNT = 5,
  HPC_GPU_ADRENO_A6XX_HLSQ_FS_STAGE_1X_WAVES = 6,
  HPC_GPU_ADRENO_A6XX_HLSQ_FS_STAGE_2X_WAVES = 7,
  HPC_GPU_ADRENO_A6XX_HLSQ_QUADS = 8,
  HPC_GPU_ADRENO_A6XX_HLSQ_CS_INVOCATIONS = 9,
  HPC_GPU_ADRENO_A6XX_HLSQ_COMPUTE_DRAWCALLS = 10,
  HPC_GPU_ADRENO_A6XX_HLSQ_FS_DATA_WAIT_PROGRAMMING = 11,
  HPC_GPU_ADRENO_A6XX_HLSQ_DUAL_FS_PROG_ACTIVE = 12,
  HPC_GPU_ADRENO_A6XX_HLSQ_DUAL_VS_PROG_ACTIVE = 13,
  HPC_GPU_ADRENO_A6XX_HLSQ_FS_BATCH_COUNT_ZERO = 14,
  HPC_GPU_ADRENO_A6XX_HLSQ_VS_BATCH_COUNT_ZERO = 15,
  HPC_GPU_ADRENO_A6XX_HLSQ_WAVE_PENDING_NO_QUAD = 16,
  HPC_GPU_ADRENO_A6XX_HLSQ_WAVE_PENDING_NO_PRIM_BASE = 17,
  HPC_GPU_ADRENO_A6XX_HLSQ_STALL_CYCLES_VPC = 18,
  HPC_GPU_ADRENO_A6XX_HLSQ_PIXELS = 19,
  HPC_GPU_ADRENO_A6XX_HLSQ_DRAW_MODE_SWITCH_VSFS_SYNC = 20
} hpc_gpu_adreno_a6xx_hlsq_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_lrz_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_LRZ_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_LRZ_STARVE_CYCLES_RAS = 1,
  HPC_GPU_ADRENO_A6XX_LRZ_STALL_CYCLES_RB = 2,
  HPC_GPU_ADRENO_A6XX_LRZ_STALL_CYCLES_VSC = 3,
  HPC_GPU_ADRENO_A6XX_LRZ_STALL_CYCLES_VPC = 4,
  HPC_GPU_ADRENO_A6XX_LRZ_STALL_CYCLES_FLAG_PREFETCH = 5,
  HPC_GPU_ADRENO_A6XX_LRZ_STALL_CYCLES_UCHE = 6,
  HPC_GPU_ADRENO_A6XX_LRZ_LRZ_READ = 7,
  HPC_GPU_ADRENO_A6XX_LRZ_LRZ_WRITE = 8,
  HPC_GPU_ADRENO_A6XX_LRZ_READ_LATENCY = 9,
  HPC_GPU_ADRENO_A6XX_LRZ_MERGE_CACHE_UPDATING = 10,
  HPC_GPU_ADRENO_A6XX_LRZ_PRIM_KILLED_BY_MASKGEN = 11,
  HPC_GPU_ADRENO_A6XX_LRZ_PRIM_KILLED_BY_LRZ = 12,
  HPC_GPU_ADRENO_A6XX_LRZ_VISIBLE_PRIM_AFTER_LRZ = 13,
  HPC_GPU_ADRENO_A6XX_LRZ_FULL_8X8_TILES = 14,
  HPC_GPU_ADRENO_A6XX_LRZ_PARTIAL_8X8_TILES = 15,
  HPC_GPU_ADRENO_A6XX_LRZ_TILE_KILLED = 16,
  HPC_GPU_ADRENO_A6XX_LRZ_TOTAL_PIXEL = 17,
  HPC_GPU_ADRENO_A6XX_LRZ_VISIBLE_PIXEL_AFTER_LRZ = 18,
  HPC_GPU_ADRENO_A6XX_LRZ_FULLY_COVERED_TILES = 19,
  HPC_GPU_ADRENO_A6XX_LRZ_PARTIAL_COVERED_TILES = 20,
  HPC_GPU_ADRENO_A6XX_LRZ_FEEDBACK_ACCEPT = 21,
  HPC_GPU_ADRENO_A6XX_LRZ_FEEDBACK_DISCARD = 22,
  HPC_GPU_ADRENO_A6XX_LRZ_FEEDBACK_STALL = 23,
  HPC_GPU_ADRENO_A6XX_LRZ_STALL_CYCLES_RB_ZPLANE = 24,
  HPC_GPU_ADRENO_A6XX_LRZ_STALL_CYCLES_RB_BPLANE = 25,
  HPC_GPU_ADRENO_A6XX_LRZ_STALL_CYCLES_VC = 26,
  HPC_GPU_ADRENO_A6XX_LRZ_RAS_MASK_TRANS = 27
} hpc_gpu_adreno_a6xx_lrz_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_pc_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_PC_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_PC_WORKING_CYCLES = 1,
  HPC_GPU_ADRENO_A6XX_PC_STALL_CYCLES_VFD = 2,
  HPC_GPU_ADRENO_A6XX_PC_STALL_CYCLES_TSE = 3,
  HPC_GPU_ADRENO_A6XX_PC_STALL_CYCLES_VPC = 4,
  HPC_GPU_ADRENO_A6XX_PC_STALL_CYCLES_UCHE = 5,
  HPC_GPU_ADRENO_A6XX_PC_STALL_CYCLES_TESS = 6,
  HPC_GPU_ADRENO_A6XX_PC_STALL_CYCLES_TSE_ONLY = 7,
  HPC_GPU_ADRENO_A6XX_PC_STALL_CYCLES_VPC_ONLY = 8,
  HPC_GPU_ADRENO_A6XX_PC_PASS1_TF_STALL_CYCLES = 9,
  HPC_GPU_ADRENO_A6XX_PC_STARVE_CYCLES_FOR_INDEX = 10,
  HPC_GPU_ADRENO_A6XX_PC_STARVE_CYCLES_FOR_TESS_FACTOR = 11,
  HPC_GPU_ADRENO_A6XX_PC_STARVE_CYCLES_FOR_VIZ_STREAM = 12,
  HPC_GPU_ADRENO_A6XX_PC_STARVE_CYCLES_FOR_POSITION = 13,
  HPC_GPU_ADRENO_A6XX_PC_STARVE_CYCLES_DI = 14,
  HPC_GPU_ADRENO_A6XX_PC_VIS_STREAMS_LOADED = 15,
  HPC_GPU_ADRENO_A6XX_PC_INSTANCES = 16,
  HPC_GPU_ADRENO_A6XX_PC_VPC_PRIMITIVES = 17,
  HPC_GPU_ADRENO_A6XX_PC_DEAD_PRIM = 18,
  HPC_GPU_ADRENO_A6XX_PC_LIVE_PRIM = 19,
  HPC_GPU_ADRENO_A6XX_PC_VERTEX_HITS = 20,
  HPC_GPU_ADRENO_A6XX_PC_IA_VERTICES = 21,
  HPC_GPU_ADRENO_A6XX_PC_IA_PRIMITIVES = 22,
  HPC_GPU_ADRENO_A6XX_PC_GS_PRIMITIVES = 23,
  HPC_GPU_ADRENO_A6XX_PC_HS_INVOCATIONS = 24,
  HPC_GPU_ADRENO_A6XX_PC_DS_INVOCATIONS = 25,
  HPC_GPU_ADRENO_A6XX_PC_VS_INVOCATIONS = 26,
  HPC_GPU_ADRENO_A6XX_PC_GS_INVOCATIONS = 27,
  HPC_GPU_ADRENO_A6XX_PC_DS_PRIMITIVES = 28,
  HPC_GPU_ADRENO_A6XX_PC_VPC_POS_DATA_TRANSACTION = 29,
  HPC_GPU_ADRENO_A6XX_PC_3D_DRAWCALLS = 30,
  HPC_GPU_ADRENO_A6XX_PC_2D_DRAWCALLS = 31,
  HPC_GPU_ADRENO_A6XX_PC_NON_DRAWCALL_GLOBAL_EVENTS = 32,
  HPC_GPU_ADRENO_A6XX_PC_TESS_BUSY_CYCLES = 33,
  HPC_GPU_ADRENO_A6XX_PC_TESS_WORKING_CYCLES = 34,
  HPC_GPU_ADRENO_A6XX_PC_TESS_STALL_CYCLES_PC = 35,
  HPC_GPU_ADRENO_A6XX_PC_TESS_STARVE_CYCLES_PC = 36,
  HPC_GPU_ADRENO_A6XX_PC_TSE_TRANSACTION = 37,
  HPC_GPU_ADRENO_A6XX_PC_TSE_VERTEX = 38,
  HPC_GPU_ADRENO_A6XX_PC_TESS_PC_UV_TRANS = 39,
  HPC_GPU_ADRENO_A6XX_PC_TESS_PC_UV_PATCHES = 40,
  HPC_GPU_ADRENO_A6XX_PC_TESS_FACTOR_TRANS = 41
} hpc_gpu_adreno_a6xx_pc_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_ras_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_RAS_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_RAS_SUPERTILE_ACTIVE_CYCLES = 1,
  HPC_GPU_ADRENO_A6XX_RAS_STALL_CYCLES_LRZ = 2,
  HPC_GPU_ADRENO_A6XX_RAS_STARVE_CYCLES_TSE = 3,
  HPC_GPU_ADRENO_A6XX_RAS_SUPER_TILES = 4,
  HPC_GPU_ADRENO_A6XX_RAS_8X4_TILES = 5,
  HPC_GPU_ADRENO_A6XX_RAS_MASKGEN_ACTIVE = 6,
  HPC_GPU_ADRENO_A6XX_RAS_FULLY_COVERED_SUPER_TILES = 7,
  HPC_GPU_ADRENO_A6XX_RAS_FULLY_COVERED_8X4_TILES = 8,
  HPC_GPU_ADRENO_A6XX_RAS_PRIM_KILLED_INVISILBE = 9,
  HPC_GPU_ADRENO_A6XX_RAS_SUPERTILE_GEN_ACTIVE_CYCLES = 10,
  HPC_GPU_ADRENO_A6XX_RAS_LRZ_INTF_WORKING_CYCLES = 11,
  HPC_GPU_ADRENO_A6XX_RAS_BLOCKS = 12
} hpc_gpu_adreno_a6xx_ras_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_rb_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_RB_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_RB_STALL_CYCLES_HLSQ = 1,
  HPC_GPU_ADRENO_A6XX_RB_STALL_CYCLES_FIFO0_FULL = 2,
  HPC_GPU_ADRENO_A6XX_RB_STALL_CYCLES_FIFO1_FULL = 3,
  HPC_GPU_ADRENO_A6XX_RB_STALL_CYCLES_FIFO2_FULL = 4,
  HPC_GPU_ADRENO_A6XX_RB_STARVE_CYCLES_SP = 5,
  HPC_GPU_ADRENO_A6XX_RB_STARVE_CYCLES_LRZ_TILE = 6,
  HPC_GPU_ADRENO_A6XX_RB_STARVE_CYCLES_CCU = 7,
  HPC_GPU_ADRENO_A6XX_RB_STARVE_CYCLES_Z_PLANE = 8,
  HPC_GPU_ADRENO_A6XX_RB_STARVE_CYCLES_BARY_PLANE = 9,
  HPC_GPU_ADRENO_A6XX_RB_Z_WORKLOAD = 10,
  HPC_GPU_ADRENO_A6XX_RB_HLSQ_ACTIVE = 11,
  HPC_GPU_ADRENO_A6XX_RB_Z_READ = 12,
  HPC_GPU_ADRENO_A6XX_RB_Z_WRITE = 13,
  HPC_GPU_ADRENO_A6XX_RB_C_READ = 14,
  HPC_GPU_ADRENO_A6XX_RB_C_WRITE = 15,
  HPC_GPU_ADRENO_A6XX_RB_TOTAL_PASS = 16,
  HPC_GPU_ADRENO_A6XX_RB_Z_PASS = 17,
  HPC_GPU_ADRENO_A6XX_RB_Z_FAIL = 18,
  HPC_GPU_ADRENO_A6XX_RB_S_FAIL = 19,
  HPC_GPU_ADRENO_A6XX_RB_BLENDED_FXP_COMPONENTS = 20,
  HPC_GPU_ADRENO_A6XX_RB_BLENDED_FP16_COMPONENTS = 21,
  HPC_GPU_ADRENO_A6XX_RB_PS_INVOCATIONS = 22,
  HPC_GPU_ADRENO_A6XX_RB_2D_ALIVE_CYCLES = 23,
  HPC_GPU_ADRENO_A6XX_RB_2D_STALL_CYCLES_A2D = 24,
  HPC_GPU_ADRENO_A6XX_RB_2D_STARVE_CYCLES_SRC = 25,
  HPC_GPU_ADRENO_A6XX_RB_2D_STARVE_CYCLES_SP = 26,
  HPC_GPU_ADRENO_A6XX_RB_2D_STARVE_CYCLES_DST = 27,
  HPC_GPU_ADRENO_A6XX_RB_2D_VALID_PIXELS = 28,
  HPC_GPU_ADRENO_A6XX_RB_3D_PIXELS = 29,
  HPC_GPU_ADRENO_A6XX_RB_BLENDER_WORKING_CYCLES = 30,
  HPC_GPU_ADRENO_A6XX_RB_ZPROC_WORKING_CYCLES = 31,
  HPC_GPU_ADRENO_A6XX_RB_CPROC_WORKING_CYCLES = 32,
  HPC_GPU_ADRENO_A6XX_RB_SAMPLER_WORKING_CYCLES = 33,
  HPC_GPU_ADRENO_A6XX_RB_STALL_CYCLES_CCU_COLOR_READ = 34,
  HPC_GPU_ADRENO_A6XX_RB_STALL_CYCLES_CCU_COLOR_WRITE = 35,
  HPC_GPU_ADRENO_A6XX_RB_STALL_CYCLES_CCU_DEPTH_READ = 36,
  HPC_GPU_ADRENO_A6XX_RB_STALL_CYCLES_CCU_DEPTH_WRITE = 37,
  HPC_GPU_ADRENO_A6XX_RB_STALL_CYCLES_VPC = 38,
  HPC_GPU_ADRENO_A6XX_RB_2D_INPUT_TRANS = 39,
  HPC_GPU_ADRENO_A6XX_RB_2D_OUTPUT_RB_DST_TRANS = 40,
  HPC_GPU_ADRENO_A6XX_RB_2D_OUTPUT_RB_SRC_TRANS = 41,
  HPC_GPU_ADRENO_A6XX_RB_BLENDED_FP32_COMPONENTS = 42,
  HPC_GPU_ADRENO_A6XX_RB_COLOR_PIX_TILES = 43,
  HPC_GPU_ADRENO_A6XX_RB_STALL_CYCLES_CCU = 44,
  HPC_GPU_ADRENO_A6XX_RB_EARLY_Z_ARB3_GRANT = 45,
  HPC_GPU_ADRENO_A6XX_RB_LATE_Z_ARB3_GRANT = 46,
  HPC_GPU_ADRENO_A6XX_RB_EARLY_Z_SKIP_GRANT = 47
} hpc_gpu_adreno_a6xx_rb_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_rbbm_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_RBBM_ALWAYS_COUNT = 0,
  HPC_GPU_ADRENO_A6XX_RBBM_ALWAYS_ON = 1,
  HPC_GPU_ADRENO_A6XX_RBBM_TSE_BUSY = 2,
  HPC_GPU_ADRENO_A6XX_RBBM_RAS_BUSY = 3,
  HPC_GPU_ADRENO_A6XX_RBBM_PC_DCALL_BUSY = 4,
  HPC_GPU_ADRENO_A6XX_RBBM_PC_VSD_BUSY = 5,
  HPC_GPU_ADRENO_A6XX_RBBM_STATUS_MASKED = 6,
  HPC_GPU_ADRENO_A6XX_RBBM_COM_BUSY = 7,
  HPC_GPU_ADRENO_A6XX_RBBM_DCOM_BUSY = 8,
  HPC_GPU_ADRENO_A6XX_RBBM_VBIF_BUSY = 9,
  HPC_GPU_ADRENO_A6XX_RBBM_VSC_BUSY = 10,
  HPC_GPU_ADRENO_A6XX_RBBM_TESS_BUSY = 11,
  HPC_GPU_ADRENO_A6XX_RBBM_UCHE_BUSY = 12,
  HPC_GPU_ADRENO_A6XX_RBBM_HLSQ_BUSY = 13
} hpc_gpu_adreno_a6xx_rbbm_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_sp_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_SP_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_SP_ALU_WORKING_CYCLES = 1,
  HPC_GPU_ADRENO_A6XX_SP_EFU_WORKING_CYCLES = 2,
  HPC_GPU_ADRENO_A6XX_SP_STALL_CYCLES_VPC = 3,
  HPC_GPU_ADRENO_A6XX_SP_STALL_CYCLES_TP = 4,
  HPC_GPU_ADRENO_A6XX_SP_STALL_CYCLES_UCHE = 5,
  HPC_GPU_ADRENO_A6XX_SP_STALL_CYCLES_RB = 6,
  HPC_GPU_ADRENO_A6XX_SP_NON_EXECUTION_CYCLES = 7,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_CONTEXTS = 8,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_CONTEXT_CYCLES = 9,
  HPC_GPU_ADRENO_A6XX_SP_FS_STAGE_WAVE_CYCLES = 10,
  HPC_GPU_ADRENO_A6XX_SP_FS_STAGE_WAVE_SAMPLES = 11,
  HPC_GPU_ADRENO_A6XX_SP_VS_STAGE_WAVE_CYCLES = 12,
  HPC_GPU_ADRENO_A6XX_SP_VS_STAGE_WAVE_SAMPLES = 13,
  HPC_GPU_ADRENO_A6XX_SP_FS_STAGE_DURATION_CYCLES = 14,
  HPC_GPU_ADRENO_A6XX_SP_VS_STAGE_DURATION_CYCLES = 15,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_CTRL_CYCLES = 16,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_LOAD_CYCLES = 17,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_EMIT_CYCLES = 18,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_NOP_CYCLES = 19,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_WAIT_CYCLES = 20,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_FETCH_CYCLES = 21,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_IDLE_CYCLES = 22,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_END_CYCLES = 23,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_LONG_SYNC_CYCLES = 24,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_SHORT_SYNC_CYCLES = 25,
  HPC_GPU_ADRENO_A6XX_SP_WAVE_JOIN_CYCLES = 26,
  HPC_GPU_ADRENO_A6XX_SP_LM_LOAD_INSTRUCTIONS = 27,
  HPC_GPU_ADRENO_A6XX_SP_LM_STORE_INSTRUCTIONS = 28,
  HPC_GPU_ADRENO_A6XX_SP_LM_ATOMICS = 29,
  HPC_GPU_ADRENO_A6XX_SP_GM_LOAD_INSTRUCTIONS = 30,
  HPC_GPU_ADRENO_A6XX_SP_GM_STORE_INSTRUCTIONS = 31,
  HPC_GPU_ADRENO_A6XX_SP_GM_ATOMICS = 32,
  HPC_GPU_ADRENO_A6XX_SP_VS_STAGE_TEX_INSTRUCTIONS = 33,
  HPC_GPU_ADRENO_A6XX_SP_VS_STAGE_EFU_INSTRUCTIONS = 34,
  HPC_GPU_ADRENO_A6XX_SP_VS_STAGE_FULL_ALU_INSTRUCTIONS = 35,
  HPC_GPU_ADRENO_A6XX_SP_VS_STAGE_HALF_ALU_INSTRUCTIONS = 36,
  HPC_GPU_ADRENO_A6XX_SP_FS_STAGE_TEX_INSTRUCTIONS = 37,
  HPC_GPU_ADRENO_A6XX_SP_FS_STAGE_CFLOW_INSTRUCTIONS = 38,
  HPC_GPU_ADRENO_A6XX_SP_FS_STAGE_EFU_INSTRUCTIONS = 39,
  HPC_GPU_ADRENO_A6XX_SP_FS_STAGE_FULL_ALU_INSTRUCTIONS = 40,
  HPC_GPU_ADRENO_A6XX_SP_FS_STAGE_HALF_ALU_INSTRUCTIONS = 41,
  HPC_GPU_ADRENO_A6XX_SP_FS_STAGE_BARY_INSTRUCTIONS = 42,
  HPC_GPU_ADRENO_A6XX_SP_VS_INSTRUCTIONS = 43,
  HPC_GPU_ADRENO_A6XX_SP_FS_INSTRUCTIONS = 44,
  HPC_GPU_ADRENO_A6XX_SP_ADDR_LOCK_COUNT = 45,
  HPC_GPU_ADRENO_A6XX_SP_UCHE_READ_TRANS = 46,
  HPC_GPU_ADRENO_A6XX_SP_UCHE_WRITE_TRANS = 47,
  HPC_GPU_ADRENO_A6XX_SP_EXPORT_VPC_TRANS = 48,
  HPC_GPU_ADRENO_A6XX_SP_EXPORT_RB_TRANS = 49,
  HPC_GPU_ADRENO_A6XX_SP_PIXELS_KILLED = 50,
  HPC_GPU_ADRENO_A6XX_SP_ICL1_REQUESTS = 51,
  HPC_GPU_ADRENO_A6XX_SP_ICL1_MISSES = 52,
  HPC_GPU_ADRENO_A6XX_SP_HS_INSTRUCTIONS = 53,
  HPC_GPU_ADRENO_A6XX_SP_DS_INSTRUCTIONS = 54,
  HPC_GPU_ADRENO_A6XX_SP_GS_INSTRUCTIONS = 55,
  HPC_GPU_ADRENO_A6XX_SP_CS_INSTRUCTIONS = 56,
  HPC_GPU_ADRENO_A6XX_SP_GPR_READ = 57,
  HPC_GPU_ADRENO_A6XX_SP_GPR_WRITE = 58,
  HPC_GPU_ADRENO_A6XX_SP_FS_STAGE_HALF_EFU_INSTRUCTIONS = 59,
  HPC_GPU_ADRENO_A6XX_SP_VS_STAGE_HALF_EFU_INSTRUCTIONS = 60,
  HPC_GPU_ADRENO_A6XX_SP_LM_BANK_CONFLICTS = 61,
  HPC_GPU_ADRENO_A6XX_SP_TEX_CONTROL_WORKING_CYCLES = 62,
  HPC_GPU_ADRENO_A6XX_SP_LOAD_CONTROL_WORKING_CYCLES = 63,
  HPC_GPU_ADRENO_A6XX_SP_FLOW_CONTROL_WORKING_CYCLES = 64,
  HPC_GPU_ADRENO_A6XX_SP_LM_WORKING_CYCLES = 65,
  HPC_GPU_ADRENO_A6XX_SP_DISPATCHER_WORKING_CYCLES = 66,
  HPC_GPU_ADRENO_A6XX_SP_SEQUENCER_WORKING_CYCLES = 67,
  HPC_GPU_ADRENO_A6XX_SP_LOW_EFFICIENCY_STARVED_BY_TP = 68,
  HPC_GPU_ADRENO_A6XX_SP_STARVE_CYCLES_HLSQ = 69,
  HPC_GPU_ADRENO_A6XX_SP_NON_EXECUTION_LS_CYCLES = 70,
  HPC_GPU_ADRENO_A6XX_SP_WORKING_EU = 71,
  HPC_GPU_ADRENO_A6XX_SP_ANY_EU_WORKING = 72,
  HPC_GPU_ADRENO_A6XX_SP_WORKING_EU_FS_STAGE = 73,
  HPC_GPU_ADRENO_A6XX_SP_ANY_EU_WORKING_FS_STAGE = 74,
  HPC_GPU_ADRENO_A6XX_SP_WORKING_EU_VS_STAGE = 75,
  HPC_GPU_ADRENO_A6XX_SP_ANY_EU_WORKING_VS_STAGE = 76,
  HPC_GPU_ADRENO_A6XX_SP_WORKING_EU_CS_STAGE = 77,
  HPC_GPU_ADRENO_A6XX_SP_ANY_EU_WORKING_CS_STAGE = 78,
  HPC_GPU_ADRENO_A6XX_SP_GPR_READ_PREFETCH = 79,
  HPC_GPU_ADRENO_A6XX_SP_GPR_READ_CONFLICT = 80,
  HPC_GPU_ADRENO_A6XX_SP_GPR_WRITE_CONFLICT = 81,
  HPC_GPU_ADRENO_A6XX_SP_GM_LOAD_LATENCY_CYCLES = 82,
  HPC_GPU_ADRENO_A6XX_SP_GM_LOAD_LATENCY_SAMPLES = 83,
  HPC_GPU_ADRENO_A6XX_SP_EXECUTABLE_WAVES = 84
} hpc_gpu_adreno_a6xx_sp_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_tp_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_TP_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_TP_STALL_CYCLES_UCHE = 1,
  HPC_GPU_ADRENO_A6XX_TP_LATENCY_CYCLES = 2,
  HPC_GPU_ADRENO_A6XX_TP_LATENCY_TRANS = 3,
  HPC_GPU_ADRENO_A6XX_TP_FLAG_CACHE_REQUEST_SAMPLES = 4,
  HPC_GPU_ADRENO_A6XX_TP_FLAG_CACHE_REQUEST_LATENCY = 5,
  HPC_GPU_ADRENO_A6XX_TP_L1_CACHELINE_REQUESTS = 6,
  HPC_GPU_ADRENO_A6XX_TP_L1_CACHELINE_MISSES = 7,
  HPC_GPU_ADRENO_A6XX_TP_SP_TP_TRANS = 8,
  HPC_GPU_ADRENO_A6XX_TP_TP_SP_TRANS = 9,
  HPC_GPU_ADRENO_A6XX_TP_OUTPUT_PIXELS = 10,
  HPC_GPU_ADRENO_A6XX_TP_FILTER_WORKLOAD_16BIT = 11,
  HPC_GPU_ADRENO_A6XX_TP_FILTER_WORKLOAD_32BIT = 12,
  HPC_GPU_ADRENO_A6XX_TP_QUADS_RECEIVED = 13,
  HPC_GPU_ADRENO_A6XX_TP_QUADS_OFFSET = 14,
  HPC_GPU_ADRENO_A6XX_TP_QUADS_SHADOW = 15,
  HPC_GPU_ADRENO_A6XX_TP_QUADS_ARRAY = 16,
  HPC_GPU_ADRENO_A6XX_TP_QUADS_GRADIENT = 17,
  HPC_GPU_ADRENO_A6XX_TP_QUADS_1D = 18,
  HPC_GPU_ADRENO_A6XX_TP_QUADS_2D = 19,
  HPC_GPU_ADRENO_A6XX_TP_QUADS_BUFFER = 20,
  HPC_GPU_ADRENO_A6XX_TP_QUADS_3D = 21,
  HPC_GPU_ADRENO_A6XX_TP_QUADS_CUBE = 22,
  HPC_GPU_ADRENO_A6XX_TP_DIVERGENT_QUADS_RECEIVED = 23,
  HPC_GPU_ADRENO_A6XX_TP_PRT_NON_RESIDENT_EVENTS = 24,
  HPC_GPU_ADRENO_A6XX_TP_OUTPUT_PIXELS_POINT = 25,
  HPC_GPU_ADRENO_A6XX_TP_OUTPUT_PIXELS_BILINEAR = 26,
  HPC_GPU_ADRENO_A6XX_TP_OUTPUT_PIXELS_MIP = 27,
  HPC_GPU_ADRENO_A6XX_TP_OUTPUT_PIXELS_ANISO = 28,
  HPC_GPU_ADRENO_A6XX_TP_OUTPUT_PIXELS_ZERO_LOD = 29,
  HPC_GPU_ADRENO_A6XX_TP_FLAG_CACHE_REQUESTS = 30,
  HPC_GPU_ADRENO_A6XX_TP_FLAG_CACHE_MISSES = 31,
  HPC_GPU_ADRENO_A6XX_TP_L1_5_L2_REQUESTS = 32,
  HPC_GPU_ADRENO_A6XX_TP_2D_OUTPUT_PIXELS = 33,
  HPC_GPU_ADRENO_A6XX_TP_2D_OUTPUT_PIXELS_POINT = 34,
  HPC_GPU_ADRENO_A6XX_TP_2D_OUTPUT_PIXELS_BILINEAR = 35,
  HPC_GPU_ADRENO_A6XX_TP_2D_FILTER_WORKLOAD_16BIT = 36,
  HPC_GPU_ADRENO_A6XX_TP_2D_FILTER_WORKLOAD_32BIT = 37,
  HPC_GPU_ADRENO_A6XX_TP_TPA2TPC_TRANS = 38,
  HPC_GPU_ADRENO_A6XX_TP_L1_MISSES_ASTC_1TILE = 39,
  HPC_GPU_ADRENO_A6XX_TP_L1_MISSES_ASTC_2TILE = 40,
  HPC_GPU_ADRENO_A6XX_TP_L1_MISSES_ASTC_4TILE = 41,
  HPC_GPU_ADRENO_A6XX_TP_L1_5_L2_COMPRESS_REQS = 42,
  HPC_GPU_ADRENO_A6XX_TP_L1_5_L2_COMPRESS_MISS = 43,
  HPC_GPU_ADRENO_A6XX_TP_L1_BANK_CONFLICT = 44,
  HPC_GPU_ADRENO_A6XX_TP_L1_5_MISS_LATENCY_CYCLES = 45,
  HPC_GPU_ADRENO_A6XX_TP_L1_5_MISS_LATENCY_TRANS = 46,
  HPC_GPU_ADRENO_A6XX_TP_QUADS_CONSTANT_MULTIPLIED = 47,
  HPC_GPU_ADRENO_A6XX_TP_FRONTEND_WORKING_CYCLES = 48,
  HPC_GPU_ADRENO_A6XX_TP_L1_TAG_WORKING_CYCLES = 49,
  HPC_GPU_ADRENO_A6XX_TP_L1_DATA_WRITE_WORKING_CYCLES = 50,
  HPC_GPU_ADRENO_A6XX_TP_PRE_L1_DECOM_WORKING_CYCLES = 51,
  HPC_GPU_ADRENO_A6XX_TP_BACKEND_WORKING_CYCLES = 52,
  HPC_GPU_ADRENO_A6XX_TP_FLAG_CACHE_WORKING_CYCLES = 53,
  HPC_GPU_ADRENO_A6XX_TP_L1_5_CACHE_WORKING_CYCLES = 54,
  HPC_GPU_ADRENO_A6XX_TP_STARVE_CYCLES_SP = 55,
  HPC_GPU_ADRENO_A6XX_TP_STARVE_CYCLES_UCHE = 56
} hpc_gpu_adreno_a6xx_tp_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_tse_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_TSE_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_TSE_CLIPPING_CYCLES = 1,
  HPC_GPU_ADRENO_A6XX_TSE_STALL_CYCLES_RAS = 2,
  HPC_GPU_ADRENO_A6XX_TSE_STALL_CYCLES_LRZ_BARYPLANE = 3,
  HPC_GPU_ADRENO_A6XX_TSE_STALL_CYCLES_LRZ_ZPLANE = 4,
  HPC_GPU_ADRENO_A6XX_TSE_STARVE_CYCLES_PC = 5,
  HPC_GPU_ADRENO_A6XX_TSE_INPUT_PRIM = 6,
  HPC_GPU_ADRENO_A6XX_TSE_INPUT_NULL_PRIM = 7,
  HPC_GPU_ADRENO_A6XX_TSE_TRIVAL_REJ_PRIM = 8,
  HPC_GPU_ADRENO_A6XX_TSE_CLIPPED_PRIM = 9,
  HPC_GPU_ADRENO_A6XX_TSE_ZERO_AREA_PRIM = 10,
  HPC_GPU_ADRENO_A6XX_TSE_FACENESS_CULLED_PRIM = 11,
  HPC_GPU_ADRENO_A6XX_TSE_ZERO_PIXEL_PRIM = 12,
  HPC_GPU_ADRENO_A6XX_TSE_OUTPUT_NULL_PRIM = 13,
  HPC_GPU_ADRENO_A6XX_TSE_OUTPUT_VISIBLE_PRIM = 14,
  HPC_GPU_ADRENO_A6XX_TSE_CINVOCATION = 15,
  HPC_GPU_ADRENO_A6XX_TSE_CPRIMITIVES = 16,
  HPC_GPU_ADRENO_A6XX_TSE_2D_INPUT_PRIM = 17,
  HPC_GPU_ADRENO_A6XX_TSE_2D_ALIVE_CYCLES = 18,
  HPC_GPU_ADRENO_A6XX_TSE_CLIP_PLANES = 19
} hpc_gpu_adreno_a6xx_tse_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_uche_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_UCHE_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_UCHE_STALL_CYCLES_ARBITER = 1,
  HPC_GPU_ADRENO_A6XX_UCHE_VBIF_LATENCY_CYCLES = 2,
  HPC_GPU_ADRENO_A6XX_UCHE_VBIF_LATENCY_SAMPLES = 3,
  HPC_GPU_ADRENO_A6XX_UCHE_VBIF_READ_BEATS_TP = 4,
  HPC_GPU_ADRENO_A6XX_UCHE_VBIF_READ_BEATS_VFD = 5,
  HPC_GPU_ADRENO_A6XX_UCHE_VBIF_READ_BEATS_HLSQ = 6,
  HPC_GPU_ADRENO_A6XX_UCHE_VBIF_READ_BEATS_LRZ = 7,
  HPC_GPU_ADRENO_A6XX_UCHE_VBIF_READ_BEATS_SP = 8,
  HPC_GPU_ADRENO_A6XX_UCHE_READ_REQUESTS_TP = 9,
  HPC_GPU_ADRENO_A6XX_UCHE_READ_REQUESTS_VFD = 10,
  HPC_GPU_ADRENO_A6XX_UCHE_READ_REQUESTS_HLSQ = 11,
  HPC_GPU_ADRENO_A6XX_UCHE_READ_REQUESTS_LRZ = 12,
  HPC_GPU_ADRENO_A6XX_UCHE_READ_REQUESTS_SP = 13,
  HPC_GPU_ADRENO_A6XX_UCHE_WRITE_REQUESTS_LRZ = 14,
  HPC_GPU_ADRENO_A6XX_UCHE_WRITE_REQUESTS_SP = 15,
  HPC_GPU_ADRENO_A6XX_UCHE_WRITE_REQUESTS_VPC = 16,
  HPC_GPU_ADRENO_A6XX_UCHE_WRITE_REQUESTS_VSC = 17,
  HPC_GPU_ADRENO_A6XX_UCHE_EVICTS = 18,
  HPC_GPU_ADRENO_A6XX_UCHE_BANK_REQ0 = 19,
  HPC_GPU_ADRENO_A6XX_UCHE_BANK_REQ1 = 20,
  HPC_GPU_ADRENO_A6XX_UCHE_BANK_REQ2 = 21,
  HPC_GPU_ADRENO_A6XX_UCHE_BANK_REQ3 = 22,
  HPC_GPU_ADRENO_A6XX_UCHE_BANK_REQ4 = 23,
  HPC_GPU_ADRENO_A6XX_UCHE_BANK_REQ5 = 24,
  HPC_GPU_ADRENO_A6XX_UCHE_BANK_REQ6 = 25,
  HPC_GPU_ADRENO_A6XX_UCHE_BANK_REQ7 = 26,
  HPC_GPU_ADRENO_A6XX_UCHE_VBIF_READ_BEATS_CH0 = 27,
  HPC_GPU_ADRENO_A6XX_UCHE_VBIF_READ_BEATS_CH1 = 28,
  HPC_GPU_ADRENO_A6XX_UCHE_GMEM_READ_BEATS = 29,
  HPC_GPU_ADRENO_A6XX_UCHE_TPH_REF_FULL = 30,
  HPC_GPU_ADRENO_A6XX_UCHE_TPH_VICTIM_FULL = 31,
  HPC_GPU_ADRENO_A6XX_UCHE_TPH_EXT_FULL = 32,
  HPC_GPU_ADRENO_A6XX_UCHE_VBIF_STALL_WRITE_DATA = 33,
  HPC_GPU_ADRENO_A6XX_UCHE_DCMP_LATENCY_SAMPLES = 34,
  HPC_GPU_ADRENO_A6XX_UCHE_DCMP_LATENCY_CYCLES = 35,
  HPC_GPU_ADRENO_A6XX_UCHE_VBIF_READ_BEATS_PC = 36,
  HPC_GPU_ADRENO_A6XX_UCHE_READ_REQUESTS_PC = 37,
  HPC_GPU_ADRENO_A6XX_UCHE_RAM_READ_REQ = 38,
  HPC_GPU_ADRENO_A6XX_UCHE_RAM_WRITE_REQ = 39
} hpc_gpu_adreno_a6xx_uche_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_vfd_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_VFD_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_VFD_STALL_CYCLES_UCHE = 1,
  HPC_GPU_ADRENO_A6XX_VFD_STALL_CYCLES_VPC_ALLOC = 2,
  HPC_GPU_ADRENO_A6XX_VFD_STALL_CYCLES_SP_INFO = 3,
  HPC_GPU_ADRENO_A6XX_VFD_STALL_CYCLES_SP_ATTR = 4,
  HPC_GPU_ADRENO_A6XX_VFD_STARVE_CYCLES_UCHE = 5,
  HPC_GPU_ADRENO_A6XX_VFD_RBUFFER_FULL = 6,
  HPC_GPU_ADRENO_A6XX_VFD_ATTR_INFO_FIFO_FULL = 7,
  HPC_GPU_ADRENO_A6XX_VFD_DECODED_ATTRIBUTE_BYTES = 8,
  HPC_GPU_ADRENO_A6XX_VFD_NUM_ATTRIBUTES = 9,
  HPC_GPU_ADRENO_A6XX_VFD_UPPER_SHADER_FIBERS = 10,
  HPC_GPU_ADRENO_A6XX_VFD_LOWER_SHADER_FIBERS = 11,
  HPC_GPU_ADRENO_A6XX_VFD_MODE_0_FIBERS = 12,
  HPC_GPU_ADRENO_A6XX_VFD_MODE_1_FIBERS = 13,
  HPC_GPU_ADRENO_A6XX_VFD_MODE_2_FIBERS = 14,
  HPC_GPU_ADRENO_A6XX_VFD_MODE_3_FIBERS = 15,
  HPC_GPU_ADRENO_A6XX_VFD_MODE_4_FIBERS = 16,
  HPC_GPU_ADRENO_A6XX_VFD_TOTAL_VERTICES = 17,
  HPC_GPU_ADRENO_A6XX_VFD_VFDP_STALL_CYCLES_VFD = 18,
  HPC_GPU_ADRENO_A6XX_VFD_VFDP_STALL_CYCLES_VFD_INDEX = 19,
  HPC_GPU_ADRENO_A6XX_VFD_VFDP_STALL_CYCLES_VFD_PROG = 20,
  HPC_GPU_ADRENO_A6XX_VFD_VFDP_STARVE_CYCLES_PC = 21,
  HPC_GPU_ADRENO_A6XX_VFD_VFDP_VS_STAGE_WAVES = 22
} hpc_gpu_adreno_a6xx_vfd_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_vpc_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_VPC_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_VPC_WORKING_CYCLES = 1,
  HPC_GPU_ADRENO_A6XX_VPC_STALL_CYCLES_UCHE = 2,
  HPC_GPU_ADRENO_A6XX_VPC_STALL_CYCLES_VFD_WACK = 3,
  HPC_GPU_ADRENO_A6XX_VPC_STALL_CYCLES_HLSQ_PRIM_ALLOC = 4,
  HPC_GPU_ADRENO_A6XX_VPC_STALL_CYCLES_PC = 5,
  HPC_GPU_ADRENO_A6XX_VPC_STALL_CYCLES_SP_LM = 6,
  HPC_GPU_ADRENO_A6XX_VPC_STARVE_CYCLES_SP = 7,
  HPC_GPU_ADRENO_A6XX_VPC_STARVE_CYCLES_LRZ = 8,
  HPC_GPU_ADRENO_A6XX_VPC_PC_PRIMITIVES = 9,
  HPC_GPU_ADRENO_A6XX_VPC_SP_COMPONENTS = 10,
  HPC_GPU_ADRENO_A6XX_VPC_STALL_CYCLES_VPCRAM_POS = 11,
  HPC_GPU_ADRENO_A6XX_VPC_LRZ_ASSIGN_PRIMITIVES = 12,
  HPC_GPU_ADRENO_A6XX_VPC_RB_VISIBLE_PRIMITIVES = 13,
  HPC_GPU_ADRENO_A6XX_VPC_LM_TRANSACTION = 14,
  HPC_GPU_ADRENO_A6XX_VPC_STREAMOUT_TRANSACTION = 15,
  HPC_GPU_ADRENO_A6XX_VPC_VS_BUSY_CYCLES = 16,
  HPC_GPU_ADRENO_A6XX_VPC_PS_BUSY_CYCLES = 17,
  HPC_GPU_ADRENO_A6XX_VPC_VS_WORKING_CYCLES = 18,
  HPC_GPU_ADRENO_A6XX_VPC_PS_WORKING_CYCLES = 19,
  HPC_GPU_ADRENO_A6XX_VPC_STARVE_CYCLES_RB = 20,
  HPC_GPU_ADRENO_A6XX_VPC_NUM_VPCRAM_READ_POS = 21,
  HPC_GPU_ADRENO_A6XX_VPC_WIT_FULL_CYCLES = 22,
  HPC_GPU_ADRENO_A6XX_VPC_VPCRAM_FULL_CYCLES = 23,
  HPC_GPU_ADRENO_A6XX_VPC_LM_FULL_WAIT_FOR_INTP_END = 24,
  HPC_GPU_ADRENO_A6XX_VPC_NUM_VPCRAM_WRITE = 25,
  HPC_GPU_ADRENO_A6XX_VPC_NUM_VPCRAM_READ_SO = 26,
  HPC_GPU_ADRENO_A6XX_VPC_NUM_ATTR_REQ_LM = 27
} hpc_gpu_adreno_a6xx_vpc_perfcounter_t;

typedef enum hpc_gpu_adreno_a6xx_vsc_perfcounter_e {
  HPC_GPU_ADRENO_A6XX_VSC_BUSY_CYCLES = 0,
  HPC_GPU_ADRENO_A6XX_VSC_WORKING_CYCLES = 1,
  HPC_GPU_ADRENO_A6XX_VSC_STALL_CYCLES_UCHE = 2,
  HPC_GPU_ADRENO_A6XX_VSC_EOT_NUM = 3,
  HPC_GPU_ADRENO_A6XX_VSC_INPUT_TILES = 4
} hpc_gpu_adreno_a6xx_vsc_perfcounter_t;

#endif  // HPC_GPU_ADRENO_A6XX_H_
