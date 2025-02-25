/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include <zephyr.h>

/* Voltage divider PCA10121 board versions.
 * The defines give what value the ADC will read back.
 * This is determined by the on-board voltage divider.
 */

struct board_version {
	char name[10];
	uint32_t mask;
	uint32_t adc_reg_val;
};

#define BOARD_PCA10121_0_0_0_MSK (BIT(0))
#define BOARD_PCA10121_0_6_0_MSK (BIT(1))
#define BOARD_PCA10121_0_7_0_MSK (BIT(2))
#define BOARD_PCA10121_0_7_1_MSK (BIT(3))
#define BOARD_PCA10121_0_8_0_MSK (BIT(4))
#define BOARD_PCA10121_0_8_1_MSK (BIT(5))
#define BOARD_PCA10121_0_8_2_MSK (BIT(6))
#define BOARD_PCA10121_0_9_0_MSK (BIT(7))
#define BOARD_PCA10121_0_10_0_MSK (BIT(8))
#define BOARD_PCA10121_1_0_0_MSK (BIT(9))

static const struct board_version BOARD_VERSION_ARR[] = {
	{ "0.0.0", BOARD_PCA10121_0_0_0_MSK, INT_MIN },
	{ "0.6.0", BOARD_PCA10121_0_6_0_MSK, 61 },
	{ "0.7.0", BOARD_PCA10121_0_7_0_MSK, 102 },
	{ "0.7.1", BOARD_PCA10121_0_7_1_MSK, 303 },
	{ "0.8.0", BOARD_PCA10121_0_8_0_MSK, 534 },
	{ "0.8.1", BOARD_PCA10121_0_8_1_MSK, 780 },
	{ "0.8.2", BOARD_PCA10121_0_8_2_MSK, 1018 },
	{ "0.9.0", BOARD_PCA10121_0_9_0_MSK, 1260 },
	/* Lower value used on 0.10.0 due to high ohm divider */
	{ "0.10.0", BOARD_PCA10121_0_10_0_MSK, 1480 },
	{ "1.0.0", BOARD_PCA10121_1_0_0_MSK, 1743 },
};

#define BOARD_VERSION_VALID_MSK                                                                    \
	(BOARD_PCA10121_0_7_0_MSK | BOARD_PCA10121_0_7_1_MSK | BOARD_PCA10121_0_8_0_MSK |          \
	 BOARD_PCA10121_0_8_1_MSK | BOARD_PCA10121_0_8_2_MSK | BOARD_PCA10121_0_9_0_MSK |          \
	 BOARD_PCA10121_0_10_0_MSK | BOARD_PCA10121_1_0_0_MSK)

#define BOARD_VERSION_VALID_MSK_SD_CARD                                                            \
	(BOARD_PCA10121_0_7_0_MSK | BOARD_PCA10121_0_8_0_MSK | BOARD_PCA10121_0_8_1_MSK |          \
	 BOARD_PCA10121_0_8_2_MSK | BOARD_PCA10121_0_9_0_MSK | BOARD_PCA10121_0_10_0_MSK |         \
	 BOARD_PCA10121_1_0_0_MSK)

#define BOARD_REVISION_VALID_MSK_MAX14690_PMIC                                                     \
	(BOARD_PCA10121_0_6_0_MSK | BOARD_PCA10121_0_7_0_MSK | BOARD_PCA10121_0_7_1_MSK)

#define LED_APP_RGB 0
#define LED_NET_RGB 1
#define LED_APP_1_BLUE 2
#define LED_APP_2_GREEN 3
#define LED_APP_3_GREEN 4

#endif
