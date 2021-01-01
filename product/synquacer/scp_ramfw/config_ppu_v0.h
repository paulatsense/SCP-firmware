/*
 * Arm SCP/MCP Software
 * Copyright (c) 2018-2021, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CONFIG_PPU_V0_H
#define CONFIG_PPU_V0_H

enum ppu_v0_element_idx {
    PPU_V0_ELEMENT_IDX_CLUSTER0_CPU0,
    PPU_V0_ELEMENT_IDX_CLUSTER0_CPU1,
    PPU_V0_ELEMENT_IDX_CLUSTER1_CPU0,
    PPU_V0_ELEMENT_IDX_CLUSTER1_CPU1,
    PPU_V0_ELEMENT_IDX_CLUSTER2_CPU0,
    PPU_V0_ELEMENT_IDX_CLUSTER2_CPU1,
    PPU_V0_ELEMENT_IDX_CLUSTER3_CPU0,
    PPU_V0_ELEMENT_IDX_CLUSTER3_CPU1,
    PPU_V0_ELEMENT_IDX_CLUSTER4_CPU0,
    PPU_V0_ELEMENT_IDX_CLUSTER4_CPU1,
    PPU_V0_ELEMENT_IDX_CLUSTER5_CPU0,
    PPU_V0_ELEMENT_IDX_CLUSTER5_CPU1,
    PPU_V0_ELEMENT_IDX_CLUSTER6_CPU0,
    PPU_V0_ELEMENT_IDX_CLUSTER6_CPU1,
    PPU_V0_ELEMENT_IDX_CLUSTER7_CPU0,
    PPU_V0_ELEMENT_IDX_CLUSTER7_CPU1,
    PPU_V0_ELEMENT_IDX_CLUSTER8_CPU0,
    PPU_V0_ELEMENT_IDX_CLUSTER8_CPU1,
    PPU_V0_ELEMENT_IDX_CLUSTER9_CPU0,
    PPU_V0_ELEMENT_IDX_CLUSTER9_CPU1,
    PPU_V0_ELEMENT_IDX_CLUSTER10_CPU0,
    PPU_V0_ELEMENT_IDX_CLUSTER10_CPU1,
    PPU_V0_ELEMENT_IDX_CLUSTER11_CPU0,
    PPU_V0_ELEMENT_IDX_CLUSTER11_CPU1,
    PPU_V0_ELEMENT_IDX_CLUSTER0,
    PPU_V0_ELEMENT_IDX_CLUSTER1,
    PPU_V0_ELEMENT_IDX_CLUSTER2,
    PPU_V0_ELEMENT_IDX_CLUSTER3,
    PPU_V0_ELEMENT_IDX_CLUSTER4,
    PPU_V0_ELEMENT_IDX_CLUSTER5,
    PPU_V0_ELEMENT_IDX_CLUSTER6,
    PPU_V0_ELEMENT_IDX_CLUSTER7,
    PPU_V0_ELEMENT_IDX_CLUSTER8,
    PPU_V0_ELEMENT_IDX_CLUSTER9,
    PPU_V0_ELEMENT_IDX_CLUSTER10,
    PPU_V0_ELEMENT_IDX_CLUSTER11,

    PPU_V0_ELEMENT_IDX_SYS3,
    PPU_V0_ELEMENT_IDX_SYS1,
    PPU_V0_ELEMENT_IDX_SYS2,
    /* PPU_SYS4 is always ON and managed by romfw */
    PPU_V0_ELEMENT_IDX_DEBUG,
    PPU_V0_ELEMENT_IDX_SYSTOP,

    PPU_V0_ELEMENT_IDX_COUNT
};

#endif /* CONFIG_PPU_V0_H */
