/*
 * Arm SCP/MCP Software
 * Copyright (c) 2018-2021, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CONFIG_POWER_DOMAIN_H
#define CONFIG_POWER_DOMAIN_H

#include <stdint.h>

enum systop_child_index {
    CONFIG_POWER_DOMAIN_SYSTOP_CHILD_DBGTOP,
    CONFIG_POWER_DOMAIN_SYSTOP_CHILD_DPUTOP,
    CONFIG_POWER_DOMAIN_SYSTOP_CHILD_GPUTOP,
    CONFIG_POWER_DOMAIN_SYSTOP_CHILD_VPUTOP,
    CONFIG_POWER_DOMAIN_SYSTOP_SYSTEM,
    CONFIG_POWER_DOMAIN_NONE = UINT32_MAX
};

#endif /* CONFIG_POWER_DOMAIN_H */
