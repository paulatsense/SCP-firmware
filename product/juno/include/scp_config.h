/*
 * Arm SCP/MCP Software
 * Copyright (c) 2019-2021, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Description:
 *     SoC-level System Control register definitions
 */

#ifndef SCP_CONFIG_H
#define SCP_CONFIG_H

#include "system_mmap.h"

#include <fwk_macros.h>

#include <stdint.h>

struct scp_config_reset_reg {
    FWK_RW  uint32_t  STATUS;
    FWK_W   uint32_t  SET;
    FWK_W   uint32_t  CLEAR;
};

struct scp_config_reg {
    FWK_RW  uint32_t             BIG_STATIC_CONFIG;
    FWK_RW  uint32_t             LITTLE_STATIC_CONFIG;
    FWK_RW  uint32_t             GPU_CONFIG;
    FWK_RW  uint32_t             SYS_PROFILER_CONFIG;
    FWK_RW  uint32_t             SYS_PROFILER_DISABLE;
    FWK_RW  uint32_t             RESET_VEC_BASE_ADDR;
            uint8_t              RESERVED1[0x100 - 0x18];
    FWK_RW  uint32_t             BIGCLK_CONTROL;
    FWK_RW  uint32_t             LITTLECLK_CONTROL;
    FWK_RW  uint32_t             GPUCLK_CONTROL;
    FWK_RW  uint32_t             DMCCLK_CONTROL;
            uint8_t              RESERVED2[0x200 - 0x110];
    FWK_RW  uint32_t             ATCLK_CONTROL;
    FWK_RW  uint32_t             CCICLK_CONTROL;
    FWK_RW  uint32_t             NICSCPCLK_CONTROL;
    FWK_RW  uint32_t             NICPERCLK_CONTROL;
    FWK_RW  uint32_t             SPCLK_CONTROL;
    FWK_RW  uint32_t             GICCLK_CONTROL;
    FWK_RW  uint32_t             RESERVED3;
    FWK_RW  uint32_t             TRACECLKIN_CONTROL;
    FWK_RW  uint32_t             PCLKDBG_CONTROL;
            uint8_t              RESERVED4[0x300 - 0x224];
    FWK_R   uint32_t             CLOCK_ENABLE_STATUS;
    FWK_W   uint32_t             CLOCK_ENABLE_SET;
    FWK_W   uint32_t             CLOCK_ENABLE_CLEAR;
    FWK_R   uint32_t             CLOCK_FORCE_STATUS;
    FWK_W   uint32_t             CLOCK_FORCE_SET;
    FWK_W   uint32_t             CLOCK_FORCE_CLEAR;
    FWK_R   uint32_t             CLOCK_STOPPED_STATUS;
    FWK_W   uint32_t             CLOCK_STOPPED_SET;
    FWK_W   uint32_t             CLOCK_STOPPED_CLEAR;
            uint8_t              RESERVED5[0x400 - 0x324];
    FWK_RW  uint32_t             SCP_CONTROL;
    FWK_RW  uint32_t             SCP_STATUS;
    FWK_RW  uint32_t             SLAVE_EXT_CONTROL;
    FWK_RW  uint32_t             BIG_SNOOP_CONTROL;
    FWK_RW  uint32_t             LITTLE_SNOOP_CONTROL;
            uint8_t              RESERVED6[0x500 - 0x414];
    FWK_R   uint32_t             RESET_SYNDROME;
    struct scp_config_reset_reg  SYS_MANUAL_RESET;
    struct scp_config_reset_reg  BIG_MANUAL_RESET;
    struct scp_config_reset_reg  LITTLE_MANUAL_RESET;
            uint8_t              RESERVED7[0x600 - 0x528];
    FWK_RW  uint32_t             DEBUG_CONTROL;
    FWK_R   uint32_t             DEBUG_STATUS;
    FWK_R   uint32_t             AP_DAP_TARGET_ID;
    FWK_R   uint32_t             SCP_DAP_TARGET_ID;
    FWK_R   uint32_t             DEBUG_PORT_ID;
            uint8_t              RESERVED8[0xFD0 - 0x614];
    FWK_R   uint32_t             PID_4;
    FWK_R   uint32_t             PID_0;
    FWK_R   uint32_t             PID_1;
    FWK_R   uint32_t             PID_2;
    FWK_R   uint32_t             PID_3;
    FWK_R   uint32_t             COMPID_0;
    FWK_R   uint32_t             COMPID_1;
    FWK_R   uint32_t             COMPID_2;
    FWK_R   uint32_t             COMPID_3;
};

#define SCP_CONFIG ((struct scp_config_reg *) CONFIG_BASE)

#define SCP_CONFIG_BIG_STATIC_CONFIG_CLUSTERID           UINT32_C(0x0000000F)
#define SCP_CONFIG_BIG_STATIC_CONFIG_CFGEND              UINT32_C(0x00000030)
#define SCP_CONFIG_BIG_STATIC_CONFIG_CFGTE               UINT32_C(0x00000300)
#define SCP_CONFIG_BIG_STATIC_CONFIG_CRYPTODISABLE       UINT32_C(0x00002000)
#define SCP_CONFIG_BIG_STATIC_CONFIG_BARRIERDISABLE      UINT32_C(0x00040000)

#define SCP_CONFIG_LITTLE_STATIC_CONFIG_CLUSTERID        UINT32_C(0x0000000F)
#define SCP_CONFIG_LITTLE_STATIC_CONFIG_CFGEND           UINT32_C(0x000000F0)
#define SCP_CONFIG_LITTLE_STATIC_CONFIG_CFGTE            UINT32_C(0x00000F00)
#define SCP_CONFIG_LITTLE_STATIC_CONFIG_CRYPTODISABLE    UINT32_C(0x00002000)
#define SCP_CONFIG_LITTLE_STATIC_CONFIG_BARRIERDISABLE   UINT32_C(0x00040000)

#define SCP_CONFIG_GPU_CONFIG_BARRIERDISABLE             UINT32_C(0x00000001)
#define SCP_CONFIG_GPU_CONFIG_BARRIERDISABLE_FALSE       UINT32_C(0x00000000)
#define SCP_CONFIG_GPU_CONFIG_BARRIERDISABLE_TRUE        UINT32_C(0x00000001)

#define SCP_CONFIG_SYS_PROFILER_CONFIG_SPSNOOPEND        UINT32_C(0x00000001)
#define SCP_CONFIG_SYS_PROFILER_CONFIG_SPSNOOPSTART      UINT32_C(0x00000002)
#define SCP_CONFIG_SYS_PROFILER_CONFIG_SPWRITEEND        UINT32_C(0x00000004)
#define SCP_CONFIG_SYS_PROFILER_CONFIG_SPWRITESTART      UINT32_C(0x00000008)
#define SCP_CONFIG_SYS_PROFILER_CONFIG_SPREADEND         UINT32_C(0x00000010)
#define SCP_CONFIG_SYS_PROFILER_CONFIG_SPREADSTART       UINT32_C(0x00000020)
#define SCP_CONFIG_SYS_PROFILER_DISABLE_POMSTRDIS        UINT32_C(0x00000001)
#define SCP_CONFIG_SYS_PROFILER_DISABLE_SOFTMSTRDIS      UINT32_C(0x00000002)

#define SCP_CONFIG_CLUSTERCLK_CONTROL_CLKSEL_MASK        UINT32_C(0x0000000F)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CLKSEL_POS         UINT32_C(0x00000000)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CLKSEL_GATED       UINT32_C(0x00000000)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CLKSEL_SYSREFCLK   UINT32_C(0x00000001)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CLKSEL_SYSINCLK    UINT32_C(0x00000002)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CLKSEL_PRIVCLK     UINT32_C(0x00000004)

#define SCP_CONFIG_CLUSTERCLK_CONTROL_CLKDIVSYS_MASK     UINT32_C(0x000000F0)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CLKDIVSYS_POS      UINT32_C(0x00000004)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CLKDIVEXT_MASK     UINT32_C(0x00000F00)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CLKDIVEXT_POS      UINT32_C(0x00000008)

#define SCP_CONFIG_CLUSTERCLK_CONTROL_CRNTCLK_MASK       UINT32_C(0x0000F000)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CRNTCLK_POS        UINT32_C(0x0000000C)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CRNTCLK_GATED      UINT32_C(0x00000000)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CRNTCLK_SYSREFCLK  UINT32_C(0x00001000)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CRNTCLK_SYSINCLK   UINT32_C(0x00002000)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CRNTCLK_PRIVCLK    UINT32_C(0x00004000)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CRNTCLKDIVSYS_MASK UINT32_C(0x000F0000)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CRNTCLKDIVSYS_POS  UINT32_C(0x00000010)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CRNTCLKDIVEXT_MASK UINT32_C(0x00F00000)
#define SCP_CONFIG_CLUSTERCLK_CONTROL_CRNTCLKDIVEXT_POS  UINT32_C(0x00000014)

#define SCP_CONFIG_DMCCLK_CONTROL_CLKSEL                 UINT32_C(0x0000000F)
#define SCP_CONFIG_DMCCLK_CONTROL_CLKSEL_GATED           UINT32_C(0x00000000)
#define SCP_CONFIG_DMCCLK_CONTROL_CLKSEL_REFCLK          UINT32_C(0x00000001)
#define SCP_CONFIG_DMCCLK_CONTROL_CLKSEL_SYSINCLK        UINT32_C(0x00000002)
#define SCP_CONFIG_DMCCLK_CONTROL_CLKDIV                 UINT32_C(0x000000F0)
#define SCP_CONFIG_DMCCLK_CONTROL_DMCAUXCLKEN            UINT32_C(0x00000100)
#define SCP_CONFIG_DMCCLK_CONTROL_DMCCLKRATIO            UINT32_C(0x00000100)
#define SCP_CONFIG_DMCCLK_CONTROL_DMCCLKRATIO_1_1        UINT32_C(0x00000000)
#define SCP_CONFIG_DMCCLK_CONTROL_DMCCLKRATIO_1_2        UINT32_C(0x00000100)
#define SCP_CONFIG_DMCCLK_CONTROL_CRNTCLK                UINT32_C(0x0000F000)
#define SCP_CONFIG_DMCCLK_CONTROL_CRNTCLK_GATED          UINT32_C(0x00000000)
#define SCP_CONFIG_DMCCLK_CONTROL_CRNTCLK_REFCLK         UINT32_C(0x00001000)
#define SCP_CONFIG_DMCCLK_CONTROL_CRNTCLK_SYSINCLK       UINT32_C(0x00002000)
#define SCP_CONFIG_DMCCLK_CONTROL_CRNTCLKDIV             UINT32_C(0x000F0000)

#define SCP_CONFIG_STDCLK_CONTROL_CLKSEL_MASK            UINT32_C(0x0000000F)
#define SCP_CONFIG_STDCLK_CONTROL_CLKSEL_POS             UINT32_C(0x00000000)
#define SCP_CONFIG_STDCLK_CONTROL_CLKSEL_GATED           UINT32_C(0x00000000)
#define SCP_CONFIG_STDCLK_CONTROL_CLKSEL_REFCLK          UINT32_C(0x00000001)
#define SCP_CONFIG_STDCLK_CONTROL_CLKSEL_SYSINCLK        UINT32_C(0x00000002)
#define SCP_CONFIG_STDCLK_CONTROL_CLKDIV_MASK            UINT32_C(0x000000F0)
#define SCP_CONFIG_STDCLK_CONTROL_CLKDIV_POS             UINT32_C(0x00000004)
#define SCP_CONFIG_STDCLK_CONTROL_CRNTCLK_MASK           UINT32_C(0x00000F00)
#define SCP_CONFIG_STDCLK_CONTROL_CRNTCLK_POS            UINT32_C(0x00000008)
#define SCP_CONFIG_STDCLK_CONTROL_CRNTCLK_GATED          UINT32_C(0x00000000)
#define SCP_CONFIG_STDCLK_CONTROL_CRNTCLK_REFCLK         UINT32_C(0x00000100)
#define SCP_CONFIG_STDCLK_CONTROL_CRNTCLK_SYSINCLK       UINT32_C(0x00000200)
#define SCP_CONFIG_STDCLK_CONTROL_CRNTCLKDIV_MASK        UINT32_C(0x0000F000)
#define SCP_CONFIG_STDCLK_CONTROL_CRNTCLKDIV_POS         UINT32_C(0x0000000C)

/* Only supported for CCICLK, NICSCPCLK, NICPERCLK and SPCLK */

#define SCP_CONFIG_STDCLK_CONTROL_LPIDELAY               UINT32_C(0x00FF0000)

#define SCP_CONFIG_CLOCK_ENABLE_PCLKDBGEN                UINT32_C(0x00000001)
#define SCP_CONFIG_CLOCK_ENABLE_TRACECLKINEN             UINT32_C(0x00000002)
#define SCP_CONFIG_CLOCK_ENABLE_GICCLKEN                 UINT32_C(0x00000008)
#define SCP_CONFIG_CLOCK_ENABLE_DMCCLKEN                 UINT32_C(0x00000020)
#define SCP_CONFIG_CLOCK_ENABLE_NICPERCLKEN              UINT32_C(0x00000040)
#define SCP_CONFIG_CLOCK_ENABLE_NICSCPCLKEN              UINT32_C(0x00000080)
#define SCP_CONFIG_CLOCK_ENABLE_CCICLKEN                 UINT32_C(0x00000100)
#define SCP_CONFIG_CLOCK_ENABLE_ATCLKEN                  UINT32_C(0x00000200)
#define SCP_CONFIG_CLOCK_ENABLE_GPUCLKEN                 UINT32_C(0x00000400)
#define SCP_CONFIG_CLOCK_ENABLE_LITTLECLKEN              UINT32_C(0x00000800)
#define SCP_CONFIG_CLOCK_ENABLE_BIGCLKEN                 UINT32_C(0x00001000)

#define SCP_CONFIG_CLOCK_ENABLE_ALL (SCP_CONFIG_CLOCK_ENABLE_PCLKDBGEN | \
                                     SCP_CONFIG_CLOCK_ENABLE_TRACECLKINEN | \
                                     SCP_CONFIG_CLOCK_ENABLE_GICCLKEN | \
                                     SCP_CONFIG_CLOCK_ENABLE_DMCCLKEN | \
                                     SCP_CONFIG_CLOCK_ENABLE_NICPERCLKEN | \
                                     SCP_CONFIG_CLOCK_ENABLE_NICSCPCLKEN | \
                                     SCP_CONFIG_CLOCK_ENABLE_CCICLKEN | \
                                     SCP_CONFIG_CLOCK_ENABLE_ATCLKEN | \
                                     SCP_CONFIG_CLOCK_ENABLE_GPUCLKEN | \
                                     SCP_CONFIG_CLOCK_ENABLE_LITTLECLKEN | \
                                     SCP_CONFIG_CLOCK_ENABLE_BIGCLKEN)

#define SCP_CONFIG_CLOCK_FORCE_SPCLKFORCE                UINT32_C(0x00000010)
#define SCP_CONFIG_CLOCK_FORCE_NICPERCLKFORCE            UINT32_C(0x00000040)
#define SCP_CONFIG_CLOCK_FORCE_NICSCPCLKFORCE            UINT32_C(0x00000080)
#define SCP_CONFIG_CLOCK_FORCE_CCICLKFORCE               UINT32_C(0x00000100)

#define SCP_CONFIG_CLOCK_STOPPED_SYSINCLKSTOPPED         UINT32_C(0x00000001)
#define SCP_CONFIG_CLOCK_STOPPED_GPUINCLKSTOPPED         UINT32_C(0x00000002)
#define SCP_CONFIG_CLOCK_STOPPED_LITTLEINCLKSTOPPED      UINT32_C(0x00000004)
#define SCP_CONFIG_CLOCK_STOPPED_BIGINCLKSTOPPED         UINT32_C(0x00000008)

#define SCP_CONFIG_SCP_CONTROL_REFCLKREQFORCE            UINT32_C(0x00000001)
#define SCP_CONFIG_SCP_CONTROL_SCPSYSREMAPEN             UINT32_C(0x00000002)
#define SCP_CONFIG_SCP_CONTROL_M3HCLKFORCE               UINT32_C(0x00000020)

#define SCP_CONFIG_SCP_STATUS_REFCLKACK                  UINT32_C(0x00000001)
#define SCP_CONFIG_SCP_STATUS_SYSINPLLLOCK               UINT32_C(0x00000002)
#define SCP_CONFIG_SCP_STATUS_GPUINPLLLOCK               UINT32_C(0x00000004)
#define SCP_CONFIG_SCP_STATUS_LITTLEINPLLLOCK            UINT32_C(0x00000008)
#define SCP_CONFIG_SCP_STATUS_BIGINPLLLOCK               UINT32_C(0x00000010)

#define SCP_CONFIG_SLAVE_EXT_CONTROL_PACCSYSREQ_SC       UINT32_C(0x00000001)
#define SCP_CONFIG_SLAVE_EXT_CONTROL_PACCSYSACK_SC       UINT32_C(0x00000002)
#define SCP_CONFIG_SLAVE_EXT_CONTROL_PACCSYSREQ_SM0      UINT32_C(0x00000004)
#define SCP_CONFIG_SLAVE_EXT_CONTROL_PACCSYSACK_SM0      UINT32_C(0x00000008)
#define SCP_CONFIG_SLAVE_EXT_CONTROL_PACCSYSREQ_SM1      UINT32_C(0x00000010)
#define SCP_CONFIG_SLAVE_EXT_CONTROL_PACCSYSACK_SM1      UINT32_C(0x00000020)
#define SCP_CONFIG_SLAVE_EXT_CONTROL_EXTIFSERVICE        UINT32_C(0x00000040)
#define SCP_CONFIG_SLAVE_EXT_CONTROL_EXTIFSNOOP          UINT32_C(0x00000080)

#define SCP_CONFIG_SNOOP_CONTROL_L2ACCREQ                UINT32_C(0x00000001)
#define SCP_CONFIG_SNOOP_CONTROL_L2ACCACK                UINT32_C(0x00000002)
#define SCP_CONFIG_SNOOP_CONTROL_STANDBYWFIL2            UINT32_C(0x00000004)

#define SCP_CONFIG_RESET_SYNDROME_PORESET                UINT32_C(0x00000001)
#define SCP_CONFIG_RESET_SYNDROME_WDOGRESET              UINT32_C(0x00000006)
#define SCP_CONFIG_RESET_SYNDROME_WDOGRESET_SCP          UINT32_C(0x00000002)
#define SCP_CONFIG_RESET_SYNDROME_WDOGRESET_SYS          UINT32_C(0x00000004)
#define SCP_CONFIG_RESET_SYNDROME_SYSRESETREQ            UINT32_C(0x00000008)
#define SCP_CONFIG_RESET_SYNDROME_SCPM3LOCKUP            UINT32_C(0x00000010)

#define SCP_CONFIG_SYS_MANUAL_RESET_DBGSYSRESET          UINT32_C(0x00000002)

#define SCP_CONFIG_CLUSTER_MANUAL_RESET_NPRESETDEBUG     UINT32_C(0x00001000)
#define SCP_CONFIG_CLUSTER_MANUAL_RESET_NL2RESET         UINT32_C(0x00002000)

#define SCP_CONFIG_DEBUG_CONTROL_CDBGRSTACK              UINT32_C(0x00000001)
#define SCP_CONFIG_DEBUG_CONTROL_CDBGPWRUPACK            UINT32_C(0x00000002)
#define SCP_CONFIG_DEBUG_CONTROL_CSYSPWRUPACK            UINT32_C(0x00000004)

#define SCP_CONFIG_DEBUG_STATUS_CDBGRSTREQ               UINT32_C(0x00000001)
#define SCP_CONFIG_DEBUG_STATUS_CDBGPWRUPREQ             UINT32_C(0x00000002)
#define SCP_CONFIG_DEBUG_STATUS_CSYSPWRUPREQ             UINT32_C(0x00000004)
#define SCP_CONFIG_DEBUG_STATUS_LITTLECPUDBGPWRUPREQ     UINT32_C(0x000000F0)
#define SCP_CONFIG_DEBUG_STATUS_LITTLECPU0DBGPWRUPREQ    UINT32_C(0x00000010)
#define SCP_CONFIG_DEBUG_STATUS_LITTLECPU1DBGPWRUPREQ    UINT32_C(0x00000020)
#define SCP_CONFIG_DEBUG_STATUS_LITTLECPU2DBGPWRUPREQ    UINT32_C(0x00000040)
#define SCP_CONFIG_DEBUG_STATUS_LITTLECPU3DBGPWRUPREQ    UINT32_C(0x00000080)
#define SCP_CONFIG_DEBUG_STATUS_BIGCPUDBGPWRUPREQ        UINT32_C(0x00000F00)
#define SCP_CONFIG_DEBUG_STATUS_BIGCPU0DBGPWRUPREQ       UINT32_C(0x00000100)
#define SCP_CONFIG_DEBUG_STATUS_BIGCPU1DBGPWRUPREQ       UINT32_C(0x00000200)
#define SCP_CONFIG_DEBUG_STATUS_BIGCPU2DBGPWRUPREQ       UINT32_C(0x00000400)
#define SCP_CONFIG_DEBUG_STATUS_BIGCPU3DBGPWRUPREQ       UINT32_C(0x00000800)

#define SCP_CONFIG_AP_DAP_TARGET_ID                      UINT32_C(0x07270477)

#define SCP_CONFIG_SCP_DAP_TARGET_ID                     UINT32_C(0x07280477)

#define SCP_CONFIG_DEBUG_PORT_ID_INSTANCEID              UINT32_C(0x0000000F)

#endif /* SCP_CONFIG_H */
