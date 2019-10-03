/* Copyright (c) 2016-2018 The Linux Foundation. All rights reserved.
 * Copyright (C) 2018 XiaoMi, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __SMB2_CHARGER_REG_H
#define __SMB2_CHARGER_REG_H

#include <linux/bitops.h>

#define CHGR_BASE	0x1000
#define OTG_BASE	0x1100
#define BATIF_BASE	0x1200
#define USBIN_BASE	0x1300
#define DCIN_BASE	0x1400
#define MISC_BASE	0x1600
#define CHGR_FREQ_BASE	0x1900

#define PERPH_TYPE_OFFSET		0x04
#define TYPE_MASK			GENMASK(7, 0)
#define PERPH_SUBTYPE_OFFSET		0x05
#define SUBTYPE_MASK			GENMASK(7, 0)
#define INT_RT_STS_OFFSET		0x10

/* CHGR Peripheral Registers */
#define BATTERY_CHARGER_STATUS_1_REG	(CHGR_BASE + 0x06)
#define BVR_INITIAL_RAMP_BIT		BIT(7)
#define CC_SOFT_TERMINATE_BIT		BIT(6)
#define STEP_CHARGING_STATUS_SHIFT	3
#define STEP_CHARGING_STATUS_MASK	GENMASK(5, 3)
#define BATTERY_CHARGER_STATUS_MASK	GENMASK(2, 0)
enum {
	TRICKLE_CHARGE = 0,
	PRE_CHARGE,
	FAST_CHARGE,
	FULLON_CHARGE,
	TAPER_CHARGE,
	TERMINATE_CHARGE,
	INHIBIT_CHARGE,
	DISABLE_CHARGE,
};

#define BATTERY_CHARGER_STATUS_2_REG			(CHGR_BASE + 0x07)
#define INPUT_CURRENT_LIMITED_BIT			BIT(7)
#define CHARGER_ERROR_STATUS_SFT_EXPIRE_BIT		BIT(6)
#define CHARGER_ERROR_STATUS_BAT_OV_BIT			BIT(5)
#define CHARGER_ERROR_STATUS_BAT_TERM_MISSING_BIT	BIT(4)
#define BAT_TEMP_STATUS_MASK				GENMASK(3, 0)
#define BAT_TEMP_STATUS_SOFT_LIMIT_MASK			GENMASK(3, 2)
#define BAT_TEMP_STATUS_HOT_SOFT_LIMIT_BIT		BIT(3)
#define BAT_TEMP_STATUS_COLD_SOFT_LIMIT_BIT		BIT(2)
#define BAT_TEMP_STATUS_TOO_HOT_BIT			BIT(1)
#define BAT_TEMP_STATUS_TOO_COLD_BIT			BIT(0)

#define CHG_OPTION_REG					(CHGR_BASE + 0x08)
#define PIN_BIT						BIT(7)

#define BATTERY_CHARGER_STATUS_3_REG			(CHGR_BASE + 0x09)
#define FV_POST_JEITA_MASK				GENMASK(7, 0)

#define BATTERY_CHARGER_STATUS_4_REG			(CHGR_BASE + 0x0A)
#define CHARGE_CURRENT_POST_JEITA_MASK			GENMASK(7, 0)

#define BATTERY_CHARGER_STATUS_5_REG			(CHGR_BASE + 0x0B)
#define VALID_INPUT_POWER_SOURCE_BIT			BIT(7)
#define DISABLE_CHARGING_BIT				BIT(6)
#define FORCE_ZERO_CHARGE_CURRENT_BIT			BIT(5)
#define CHARGING_ENABLE_BIT				BIT(4)
#define TAPER_BIT					BIT(3)
#define ENABLE_CHG_SENSORS_BIT				BIT(2)
#define ENABLE_TAPER_SENSOR_BIT				BIT(1)
#define TAPER_REGION_BIT				BIT(0)

#define BATTERY_CHARGER_STATUS_6_REG			(CHGR_BASE + 0x0C)
#define GF_BATT_OV_BIT					BIT(7)
#define DROP_IN_BATTERY_VOLTAGE_REFERENCE_BIT		BIT(6)
#define VBATT_LTET_RECHARGE_BIT				BIT(5)
#define VBATT_GTET_INHIBIT_BIT				BIT(4)
#define VBATT_GTET_FLOAT_VOLTAGE_BIT			BIT(3)
#define BATT_GT_PRE_TO_FAST_BIT				BIT(2)
#define BATT_GT_FULL_ON_BIT				BIT(1)
#define VBATT_LT_2V_BIT					BIT(0)

#define BATTERY_CHARGER_STATUS_7_REG			(CHGR_BASE + 0x0D)
#define ENABLE_TRICKLE_BIT				BIT(7)
#define ENABLE_PRE_CHARGING_BIT				BIT(6)
#define ENABLE_FAST_CHARGING_BIT			BIT(5)
#define ENABLE_FULLON_MODE_BIT				BIT(4)
#define TOO_COLD_ADC_BIT				BIT(3)
#define TOO_HOT_ADC_BIT					BIT(2)
#define HOT_SL_ADC_BIT					BIT(1)
#define COLD_SL_ADC_BIT					BIT(0)

#define BATTERY_CHARGER_STATUS_8_REG			(CHGR_BASE + 0x0E)
#define PRE_FAST_BIT					BIT(7)
#define PRE_FULLON_BIT					BIT(6)
#define PRE_RCHG_BIT					BIT(5)
#define PRE_INHIBIT_BIT					BIT(4)
#define PRE_OVRV_BIT					BIT(3)
#define PRE_TERM_BIT					BIT(2)
#define BAT_ID_BMISS_CMP_BIT				BIT(1)
#define THERM_CMP_BIT					BIT(0)

/* CHGR Interrupt Bits */
#define CHGR_7_RT_STS_BIT				BIT(7)
#define CHGR_6_RT_STS_BIT				BIT(6)
#define FG_FVCAL_QUALIFIED_RT_STS_BIT			BIT(5)
#define STEP_CHARGING_SOC_UPDATE_REQUEST_RT_STS_BIT	BIT(4)
#define STEP_CHARGING_SOC_UPDATE_FAIL_RT_STS_BIT	BIT(3)
#define STEP_CHARGING_STATE_CHANGE_RT_STS_BIT		BIT(2)
#define CHARGING_STATE_CHANGE_RT_STS_BIT		BIT(1)
#define CHGR_ERROR_RT_STS_BIT				BIT(0)

#define STEP_CHG_SOC_VBATT_V_REG			(CHGR_BASE + 0x40)
#define STEP_CHG_SOC_VBATT_V_MASK			GENMASK(7, 0)

#define STEP_CHG_SOC_VBATT_V_UPDATE_REG			(CHGR_BASE + 0x41)
#define STEP_CHG_SOC_VBATT_V_UPDATE_BIT			BIT(0)

#define CHARGING_ENABLE_CMD_REG				(CHGR_BASE + 0x42)
#define CHARGING_ENABLE_CMD_BIT				BIT(0)

#define ALLOW_FAST_CHARGING_CMD_REG			(CHGR_BASE + 0x43)
#define ALLOW_FAST_CHARGING_CMD_BIT			BIT(0)

#define QNOVO_PT_ENABLE_CMD_REG				(CHGR_BASE + 0x44)
#define QNOVO_PT_ENABLE_CMD_BIT				BIT(0)

#define CHGR_CFG1_REG					(CHGR_BASE + 0x50)
#define INCREASE_RCHG_TIMEOUT_CFG_BIT			BIT(1)
#define LOAD_BAT_BIT					BIT(0)

#define CHGR_CFG2_REG					(CHGR_BASE + 0x51)
#define CHG_EN_SRC_BIT					BIT(7)
#define CHG_EN_POLARITY_BIT				BIT(6)
#define PRETOFAST_TRANSITION_CFG_BIT			BIT(5)
#define BAT_OV_ECC_BIT					BIT(4)
#define I_TERM_BIT					BIT(3)
#define AUTO_RECHG_BIT					BIT(2)
#define EN_ANALOG_DROP_IN_VBATT_BIT			BIT(1)
#define CHARGER_INHIBIT_BIT				BIT(0)

#define CHARGER_ENABLE_CFG_REG				(CHGR_BASE + 0x52)
#define CHG_ENB_TIMEOUT_SETTING_BIT			BIT(1)
#define FORCE_ZERO_CFG_BIT				BIT(0)

#define CFG_REG						(CHGR_BASE + 0x53)
#define CHG_OPTION_PIN_TRIM_BIT				BIT(7)
#define BATN_SNS_CFG_BIT				BIT(4)
#define CFG_TAPER_DIS_AFVC_BIT				BIT(3)
#define BATFET_SHUTDOWN_CFG_BIT				BIT(2)
#define VDISCHG_EN_CFG_BIT				BIT(1)
#define VCHG_EN_CFG_BIT					BIT(0)

#define CHARGER_SPARE_REG				(CHGR_BASE + 0x54)
#define CHARGER_SPARE_MASK				GENMASK(5, 0)

#define PRE_CHARGE_CURRENT_CFG_REG			(CHGR_BASE + 0x60)
#define PRE_CHARGE_CURRENT_SETTING_MASK			GENMASK(5, 0)

#define FAST_CHARGE_CURRENT_CFG_REG			(CHGR_BASE + 0x61)
#define FAST_CHARGE_CURRENT_SETTING_MASK		GENMASK(7, 0)

#define CHARGE_CURRENT_TERMINATION_CFG_REG		(CHGR_BASE + 0x62)
#define ANALOG_CHARGE_CURRENT_TERMINATION_SETTING_MASK	GENMASK(2, 0)

#define TCCC_CHARGE_CURRENT_TERMINATION_CFG_REG		(CHGR_BASE + 0x63)
#define TCCC_CHARGE_CURRENT_TERMINATION_SETTING_MASK	GENMASK(3, 0)

#define CHARGE_CURRENT_SOFTSTART_SETTING_CFG_REG	(CHGR_BASE + 0x64)
#define CHARGE_CURRENT_SOFTSTART_SETTING_MASK		GENMASK(1, 0)

#define FLOAT_VOLTAGE_CFG_REG				(CHGR_BASE + 0x70)
#define FLOAT_VOLTAGE_SETTING_MASK			GENMASK(7, 0)

#define AUTO_FLOAT_VOLTAGE_COMPENSATION_CFG_REG		(CHGR_BASE + 0x71)
#define AUTO_FLOAT_VOLTAGE_COMPENSATION_MASK		GENMASK(2, 0)

#define CHARGE_INHIBIT_THRESHOLD_CFG_REG		(CHGR_BASE + 0x72)
#define CHARGE_INHIBIT_THRESHOLD_MASK			GENMASK(1, 0)
#define CHARGE_INHIBIT_THRESHOLD_50MV			0
#define CHARGE_INHIBIT_THRESHOLD_100MV			1
#define CHARGE_INHIBIT_THRESHOLD_200MV			2
#define CHARGE_INHIBIT_THRESHOLD_300MV			3

#define RECHARGE_THRESHOLD_CFG_REG			(CHGR_BASE + 0x73)
#define RECHARGE_THRESHOLD_MASK				GENMASK(1, 0)

#define PRE_TO_FAST_CHARGE_THRESHOLD_CFG_REG		(CHGR_BASE + 0x74)
#define PRE_TO_FAST_CHARGE_THRESHOLD_MASK		GENMASK(1, 0)

#define FV_HYSTERESIS_CFG_REG				(CHGR_BASE + 0x75)
#define FV_DROP_HYSTERESIS_CFG_MASK			GENMASK(7, 4)
#define THRESH_HYSTERESIS_CFG_MASK			GENMASK(3, 0)

#define FVC_CHARGE_INHIBIT_THRESHOLD_CFG_REG		(CHGR_BASE + 0x80)
#define FVC_CHARGE_INHIBIT_THRESHOLD_MASK		GENMASK(5, 0)

#define FVC_RECHARGE_THRESHOLD_CFG_REG			(CHGR_BASE + 0x81)
#define FVC_RECHARGE_THRESHOLD_MASK			GENMASK(7, 0)

#define FVC_PRE_TO_FAST_CHARGE_THRESHOLD_CFG_REG	(CHGR_BASE + 0x82)
#define FVC_PRE_TO_FAST_CHARGE_THRESHOLD_MASK		GENMASK(7, 0)

#define FVC_FULL_ON_THRESHOLD_CFG_REG			(CHGR_BASE + 0x83)
#define FVC_FULL_ON_THRESHOLD_MASK			GENMASK(7, 0)

#define FVC_CC_MODE_GLITCH_FILTER_SEL_CFG_REG		(CHGR_BASE + 0x84)
#define FVC_CC_MODE_GLITCH_FILTER_SEL_MASK		GENMASK(1, 0)

#define FVC_TERMINATION_GLITCH_FILTER_SEL_CFG_REG	(CHGR_BASE + 0x85)
#define FVC_TERMINATION_GLITCH_FILTER_SEL_MASK		GENMASK(1, 0)

#define JEITA_EN_CFG_REG		(CHGR_BASE + 0x90)
#define JEITA_EN_HARDLIMIT_BIT		BIT(4)
#define JEITA_EN_HOT_SL_FCV_BIT		BIT(3)
#define JEITA_EN_COLD_SL_FCV_BIT	BIT(2)
#define JEITA_EN_HOT_SL_CCC_BIT		BIT(1)
#define JEITA_EN_COLD_SL_CCC_BIT	BIT(0)

#define JEITA_FVCOMP_CFG_REG		(CHGR_BASE + 0x91)
#define JEITA_FVCOMP_MASK		GENMASK(7, 0)

#define JEITA_CCCOMP_CFG_REG		(CHGR_BASE + 0x92)
#define JEITA_CCCOMP_MASK		GENMASK(7, 0)

#define FV_CAL_CFG_REG			(CHGR_BASE + 0x76)
#define FV_CALIBRATION_CFG_MASK		GENMASK(2, 0)

#define FV_ADJUST_REG			(CHGR_BASE + 0x77)
#define FLOAT_VOLTAGE_ADJUSTMENT_MASK	GENMASK(4, 0)

#define FG_VADC_DISQ_THRESH_REG		(CHGR_BASE + 0x78)
#define VADC_DISQUAL_THRESH_MASK	GENMASK(7, 0)

#define FG_IADC_DISQ_THRESH_REG		(CHGR_BASE + 0x79)
#define IADC_DISQUAL_THRESH_MASK	GENMASK(7, 0)

#define FG_UPDATE_CFG_1_REG	(CHGR_BASE + 0x7A)
#define BT_TMPR_TCOLD_BIT	BIT(7)
#define BT_TMPR_COLD_BIT	BIT(6)
#define BT_TMPR_HOT_BIT		BIT(5)
#define BT_TMPR_THOT_BIT	BIT(4)
#define CHG_DIE_TMPR_HOT_BIT	BIT(3)
#define CHG_DIE_TMPR_THOT_BIT	BIT(2)
#define SKIN_TMPR_HOT_BIT	BIT(1)
#define SKIN_TMPR_THOT_BIT	BIT(0)

#define FG_UPDATE_CFG_1_SEL_REG		(CHGR_BASE + 0x7B)
#define BT_TMPR_TCOLD_SEL_BIT		BIT(7)
#define BT_TMPR_COLD_SEL_BIT		BIT(6)
#define BT_TMPR_HOT_SEL_BIT		BIT(5)
#define BT_TMPR_THOT_SEL_BIT		BIT(4)
#define CHG_DIE_TMPR_HOT_SEL_BIT	BIT(3)
#define CHG_DIE_TMPR_THOT_SEL_BIT	BIT(2)
#define SKIN_TMPR_HOT_SEL_BIT		BIT(1)
#define SKIN_TMPR_THOT_SEL_BIT		BIT(0)

#define FG_UPDATE_CFG_2_REG		(CHGR_BASE + 0x7C)
#define SOC_LT_OTG_THRESH_BIT		BIT(3)
#define SOC_LT_CHG_RECHARGE_THRESH_BIT	BIT(2)
#define VBT_LT_CHG_RECHARGE_THRESH_BIT	BIT(1)
#define IBT_LT_CHG_TERM_THRESH_BIT	BIT(0)

#define FG_UPDATE_CFG_2_SEL_REG			(CHGR_BASE + 0x7D)
#define SOC_LT_OTG_THRESH_SEL_BIT		BIT(3)
#define SOC_LT_CHG_RECHARGE_THRESH_SEL_BIT	BIT(2)
#define VBT_LT_CHG_RECHARGE_THRESH_SEL_BIT	BIT(1)
#define IBT_LT_CHG_TERM_THRESH_SEL_BIT		BIT(0)

#define FG_CHG_INTERFACE_CFG_REG	(CHGR_BASE + 0x7E)
#define ESR_ISINK_CFG_MASK		GENMASK(7, 6)
#define ESR_FASTCHG_DECR_CFG_MASK	GENMASK(5, 4)
#define FG_CHARGER_INHIBIT_BIT		BIT(3)
#define FG_BATFET_BIT			BIT(2)
#define IADC_SYNC_CNV_BIT		BIT(1)
#define VADC_SYNC_CNV_BIT		BIT(0)

#define FG_CHG_INTERFACE_CFG_SEL_REG	(CHGR_BASE + 0x7F)
#define ESR_ISINK_CFG_SEL_BIT		BIT(5)
#define ESR_FASTCHG_DECR_CFG_SEL_BIT	BIT(4)
#define FG_CHARGER_INHIBIT_SEL_BIT	BIT(3)
#define FG_BATFET_SEL_BIT		BIT(2)
#define IADC_SYNC_CNV_SEL_BIT		BIT(1)
#define VADC_SYNC_CNV_SEL_BIT		BIT(0)

#define CHGR_STEP_CHG_MODE_CFG_REG		(CHGR_BASE + 0xB0)
#define STEP_CHARGING_SOC_FAIL_OPTION_BIT	BIT(3)
#define STEP_CHARGING_MODE_SELECT_BIT		BIT(2)
#define STEP_CHARGING_SOURCE_SELECT_BIT		BIT(1)
#define STEP_CHARGING_ENABLE_BIT		BIT(0)

#define STEP_CHG_UPDATE_REQUEST_TIMEOUT_CFG_REG		(CHGR_BASE + 0xB1)
#define STEP_CHG_UPDATE_REQUEST_TIMEOUT_CFG_MASK	GENMASK(0, 1)
#define STEP_CHG_UPDATE_REQUEST_TIMEOUT_5S		0
#define STEP_CHG_UPDATE_REQUEST_TIMEOUT_10S		1
#define STEP_CHG_UPDATE_REQUEST_TIMEOUT_20S		2
#define STEP_CHG_UPDATE_REQUEST_TIMEOUT_40S		3

#define STEP_CHG_UPDATE_FAIL_TIMEOUT_CFG_REG		(CHGR_BASE + 0xB2)
#define STEP_CHG_UPDATE_FAIL_TIMEOUT_CFG_MASK		GENMASK(0, 1)
#define STEP_CHG_UPDATE_FAIL_TIMEOUT_10S		0
#define STEP_CHG_UPDATE_FAIL_TIMEOUT_30S		1
#define STEP_CHG_UPDATE_FAIL_TIMEOUT_60S		2
#define STEP_CHG_UPDATE_FAIL_TIMEOUT_120S		3

#define STEP_CHG_SOC_OR_BATT_V_TH1_REG	(CHGR_BASE + 0xB3)
#define STEP_CHG_SOC_OR_BATT_V_TH2_REG	(CHGR_BASE + 0xB4)
#define STEP_CHG_SOC_OR_BATT_V_TH3_REG	(CHGR_BASE + 0xB5)
#define STEP_CHG_SOC_OR_BATT_V_TH4_REG	(CHGR_BASE + 0xB6)
#define STEP_CHG_CURRENT_DELTA1_REG	(CHGR_BASE + 0xB7)
#define STEP_CHG_CURRENT_DELTA2_REG	(CHGR_BASE + 0xB8)
#define STEP_CHG_CURRENT_DELTA3_REG	(CHGR_BASE + 0xB9)
#define STEP_CHG_CURRENT_DELTA4_REG	(CHGR_BASE + 0xBA)
#define STEP_CHG_CURRENT_DELTA5_REG	(CHGR_BASE + 0xBB)

/* OTG Peripheral Registers */
#define RID_CC_CONTROL_23_16_REG	(OTG_BASE + 0x06)
#define RID_CC_CONTROL_23_BIT		BIT(7)
#define VCONN_SOFTSTART_EN_BIT		BIT(6)
#define VCONN_SFTST_CFG_MASK		GENMASK(5, 4)
#define CONNECT_RIDCC_SENSOR_TO_CC_MASK	GENMASK(3, 2)
#define EN_CC_1P1CLAMP_BIT		BIT(1)
#define ENABLE_CRUDESEN_CC_1_BIT	BIT(0)

#define RID_CC_CONTROL_15_8_REG		(OTG_BASE + 0x07)
#define ENABLE_CRUDESEN_CC_0_BIT	BIT(7)
#define EN_FMB_2P5UA_CC_MASK		GENMASK(6, 5)
#define EN_ISRC_180UA_BIT		BIT(4)
#define ENABLE_CURRENTSOURCE_CC_MASK	GENMASK(3, 2)
#define EN_BANDGAP_RID_C_DET_BIT	BIT(1)
#define ENABLE_RD_CC_1_BIT		BIT(0)

#define RID_CC_CONTROL_7_0_REG		(OTG_BASE + 0x08)
#define ENABLE_RD_CC_0_BIT		BIT(7)
#define VCONN_ILIM500MA_BIT		BIT(6)
#define EN_MICRO_USB_MODE_BIT		BIT(5)
#define UFP_DFP_MODE_BIT		BIT(4)
#define VCONN_EN_CC_MASK		GENMASK(3, 2)
#define VREF_SEL_RIDCC_SENSOR_MASK	GENMASK(1, 0)

#define OTG_STATUS_REG			(OTG_BASE + 0x09)
#define BOOST_SOFTSTART_DONE_BIT	BIT(3)
#define OTG_STATE_MASK			GENMASK(2, 0)
#define OTG_STATE_ENABLED		0x2

/* OTG Interrupt Bits */
#define TESTMODE_CHANGE_DETECT_RT_STS_BIT	BIT(3)
#define OTG_OC_DIS_SW_STS_RT_STS_BIT		BIT(2)
#define OTG_OVERCURRENT_RT_STS_BIT		BIT(1)
#define OTG_FAIL_RT_STS_BIT			BIT(0)

#define CMD_OTG_REG			(OTG_BASE + 0x40)
#define OTG_EN_BIT			BIT(0)

#define BAT_UVLO_THRESHOLD_CFG_REG	(OTG_BASE + 0x51)
#define BAT_UVLO_THRESHOLD_MASK		GENMASK(1, 0)

#define OTG_CURRENT_LIMIT_CFG_REG	(OTG_BASE + 0x52)
#define OTG_CURRENT_LIMIT_MASK		GENMASK(2, 0)

#define OTG_CFG_REG			(OTG_BASE + 0x53)
#define OTG_RESERVED_MASK		GENMASK(7, 6)
#define DIS_OTG_ON_TLIM_BIT		BIT(5)
#define QUICKSTART_OTG_FASTROLESWAP_BIT	BIT(4)
#define INCREASE_DFP_TIME_BIT		BIT(3)
#define ENABLE_OTG_IN_DEBUG_MODE_BIT	BIT(2)
#define OTG_EN_SRC_CFG_BIT		BIT(1)
#define CONCURRENT_MODE_CFG_BIT		BIT(0)

#define OTG_ENG_OTG_CFG_REG		(OTG_BASE + 0xC0)
#define ENG_BUCKBOOST_HALT1_8_MODE_BIT	BIT(0)

/* BATIF Peripheral Registers */
/* BATIF Interrupt Bits */
#define BAT_7_RT_STS_BIT			BIT(7)
#define BAT_6_RT_STS_BIT			BIT(6)
#define BAT_TERMINAL_MISSING_RT_STS_BIT		BIT(5)
#define BAT_THERM_OR_ID_MISSING_RT_STS_BIT	BIT(4)
#define BAT_LOW_RT_STS_BIT			BIT(3)
#define BAT_OV_RT_STS_BIT			BIT(2)
#define BAT_OCP_RT_STS_BIT			BIT(1)
#define BAT_TEMP_RT_STS_BIT			BIT(0)

#define SHIP_MODE_REG			(BATIF_BASE + 0x40)
#define SHIP_MODE_EN_BIT		BIT(0)

#define BATOCP_THRESHOLD_CFG_REG	(BATIF_BASE + 0x50)
#define BATOCP_ENABLE_CFG_BIT		BIT(3)
#define BATOCP_THRESHOLD_MASK		GENMASK(2, 0)

#define BATOCP_INTRPT_DELAY_TMR_CFG_REG	(BATIF_BASE + 0x51)
#define BATOCP_INTRPT_TIMEOUT_MASK	GENMASK(5, 3)
#define BATOCP_DELAY_TIMEOUT_MASK	GENMASK(2, 0)

#define BATOCP_RESET_TMR_CFG_REG	(BATIF_BASE + 0x52)
#define EN_BATOCP_RESET_TMR_BIT		BIT(3)
#define BATOCP_RESET_TIMEOUT_MASK	GENMASK(2, 0)

#define LOW_BATT_DETECT_EN_CFG_REG	(BATIF_BASE + 0x60)
#define LOW_BATT_DETECT_EN_BIT		BIT(0)

#define LOW_BATT_THRESHOLD_CFG_REG	(BATIF_BASE + 0x61)
#define LOW_BATT_THRESHOLD_MASK		GENMASK(3, 0)

#define BAT_FET_CFG_REG			(BATIF_BASE + 0x62)
#define BAT_FET_CFG_BIT			BIT(0)

#define BAT_MISS_SRC_CFG_REG		(BATIF_BASE + 0x70)
#define BAT_MISS_ALG_EN_BIT		BIT(2)
#define BAT_MISS_RESERVED_BIT		BIT(1)
#define BAT_MISS_PIN_SRC_EN_BIT		BIT(0)

#define BAT_MISS_ALG_OPTIONS_CFG_REG	(BATIF_BASE + 0x71)
#define BAT_MISS_INPUT_PLUGIN_BIT	BIT(2)
#define BAT_MISS_TMR_START_OPTION_BIT	BIT(1)
#define BAT_MISS_POLL_EN_BIT		BIT(0)

#define BAT_MISS_PIN_GF_CFG_REG		(BATIF_BASE + 0x72)
#define BAT_MISS_PIN_GF_MASK		GENMASK(1, 0)

/* USBIN Peripheral Registers */
#define USBIN_INPUT_STATUS_REG		(USBIN_BASE + 0x06)
#define USBIN_INPUT_STATUS_7_BIT	BIT(7)
#define USBIN_INPUT_STATUS_6_BIT	BIT(6)
#define USBIN_12V_BIT			BIT(5)
#define USBIN_9V_TO_12V_BIT		BIT(4)
#define USBIN_9V_BIT			BIT(3)
#define USBIN_5V_TO_12V_BIT		BIT(2)
#define USBIN_5V_TO_9V_BIT		BIT(1)
#define USBIN_5V_BIT			BIT(0)
#define QC_2P0_STATUS_MASK		GENMASK(2, 0)

#define APSD_STATUS_REG			(USBIN_BASE + 0x07)
#define APSD_STATUS_7_BIT		BIT(7)
#define HVDCP_CHECK_TIMEOUT_BIT		BIT(6)
#define SLOW_PLUGIN_TIMEOUT_BIT		BIT(5)
#define ENUMERATION_DONE_BIT		BIT(4)
#define VADP_CHANGE_DONE_AFTER_AUTH_BIT	BIT(3)
#define QC_AUTH_DONE_STATUS_BIT		BIT(2)
#define QC_CHARGER_BIT			BIT(1)
#define APSD_DTC_STATUS_DONE_BIT	BIT(0)

#define APSD_RESULT_STATUS_REG		(USBIN_BASE + 0x08)
#define ICL_OVERRIDE_LATCH_BIT		BIT(7)
#define APSD_RESULT_STATUS_MASK		GENMASK(6, 0)
#define QC_3P0_BIT			BIT(6)
#define QC_2P0_BIT			BIT(5)
#define FLOAT_CHARGER_BIT		BIT(4)
#define DCP_CHARGER_BIT			BIT(3)
#define CDP_CHARGER_BIT			BIT(2)
#define OCP_CHARGER_BIT			BIT(1)
#define SDP_CHARGER_BIT			BIT(0)

#define QC_CHANGE_STATUS_REG		(USBIN_BASE + 0x09)
#define QC_CHANGE_STATUS_7_BIT		BIT(7)
#define QC_CHANGE_STATUS_6_BIT		BIT(6)
#define QC_9V_TO_12V_REASON_BIT		BIT(5)
#define QC_5V_TO_9V_REASON_BIT		BIT(4)
#define QC_CONTINUOUS_BIT		BIT(3)
#define QC_12V_BIT			BIT(2)
#define QC_9V_BIT			BIT(1)
#define QC_5V_BIT			BIT(0)

#define QC_PULSE_COUNT_STATUS_REG		(USBIN_BASE + 0x0A)
#define QC_PULSE_COUNT_STATUS_7_BIT		BIT(7)
#define QC_PULSE_COUNT_STATUS_6_BIT		BIT(6)
#define QC_PULSE_COUNT_MASK			GENMASK(5, 0)

#define TYPE_C_STATUS_1_REG			(USBIN_BASE + 0x0B)
#define UFP_TYPEC_MASK				GENMASK(7, 5)
#define UFP_TYPEC_RDSTD_BIT			BIT(7)
#define UFP_TYPEC_RD1P5_BIT			BIT(6)
#define UFP_TYPEC_RD3P0_BIT			BIT(5)
#define UFP_TYPEC_FMB_255K_BIT			BIT(4)
#define UFP_TYPEC_FMB_301K_BIT			BIT(3)
#define UFP_TYPEC_FMB_523K_BIT			BIT(2)
#define UFP_TYPEC_FMB_619K_BIT			BIT(1)
#define UFP_TYPEC_OPEN_OPEN_BIT			BIT(0)

#define TYPE_C_STATUS_2_REG			(USBIN_BASE + 0x0C)
#define DFP_RA_OPEN_BIT				BIT(7)
#define TIMER_STAGE_BIT				BIT(6)
#define EXIT_UFP_MODE_BIT			BIT(5)
#define EXIT_DFP_MODE_BIT			BIT(4)
#define DFP_TYPEC_MASK				GENMASK(3, 0)
#define DFP_RD_OPEN_BIT				BIT(3)
#define DFP_RD_RA_VCONN_BIT			BIT(2)
#define DFP_RD_RD_BIT				BIT(1)
#define DFP_RA_RA_BIT				BIT(0)

#define TYPE_C_STATUS_3_REG			(USBIN_BASE + 0x0D)
#define ENABLE_BANDGAP_BIT			BIT(7)
#define U_USB_GND_NOVBUS_BIT			BIT(6)
#define U_USB_FLOAT_NOVBUS_BIT			BIT(5)
#define U_USB_GND_BIT				BIT(4)
#define U_USB_FMB1_BIT				BIT(3)
#define U_USB_FLOAT1_BIT			BIT(2)
#define U_USB_FMB2_BIT				BIT(1)
#define U_USB_FLOAT2_BIT			BIT(0)

#define TYPE_C_STATUS_4_REG			(USBIN_BASE + 0x0E)
#define UFP_DFP_MODE_STATUS_BIT			BIT(7)
#define TYPEC_VBUS_STATUS_BIT			BIT(6)
#define TYPEC_VBUS_ERROR_STATUS_BIT		BIT(5)
#define TYPEC_DEBOUNCE_DONE_STATUS_BIT		BIT(4)
#define TYPEC_UFP_AUDIO_ADAPT_STATUS_BIT	BIT(3)
#define TYPEC_VCONN_OVERCURR_STATUS_BIT		BIT(2)
#define CC_ORIENTATION_BIT			BIT(1)
#define CC_ATTACHED_BIT				BIT(0)

#define TYPE_C_STATUS_5_REG			(USBIN_BASE + 0x0F)
#define TRY_SOURCE_FAILED_BIT			BIT(6)
#define TRY_SINK_FAILED_BIT			BIT(5)
#define TIMER_STAGE_2_BIT			BIT(4)
#define TYPEC_LEGACY_CABLE_STATUS_BIT		BIT(3)
#define TYPEC_NONCOMP_LEGACY_CABLE_STATUS_BIT	BIT(2)
#define TYPEC_TRYSOURCE_DETECT_STATUS_BIT	BIT(1)
#define TYPEC_TRYSINK_DETECT_STATUS_BIT		BIT(0)

/* USBIN Interrupt Bits */
#define TYPE_C_CHANGE_RT_STS_BIT		BIT(7)
#define USBIN_ICL_CHANGE_RT_STS_BIT		BIT(6)
#define USBIN_SOURCE_CHANGE_RT_STS_BIT		BIT(5)
#define USBIN_PLUGIN_RT_STS_BIT			BIT(4)
#define USBIN_OV_RT_STS_BIT			BIT(3)
#define USBIN_UV_RT_STS_BIT			BIT(2)
#define USBIN_LT_3P6V_RT_STS_BIT		BIT(1)
#define USBIN_COLLAPSE_RT_STS_BIT		BIT(0)

#define QC_PULSE_COUNT_STATUS_1_REG		(USBIN_BASE + 0x30)

#define USBIN_CMD_IL_REG			(USBIN_BASE + 0x40)
#define BAT_2_SYS_FET_DIS_BIT			BIT(1)
#define USBIN_SUSPEND_BIT			BIT(0)

#define CMD_APSD_REG				(USBIN_BASE + 0x41)
#define ICL_OVERRIDE_BIT			BIT(1)
#define APSD_RERUN_BIT				BIT(0)

#define CMD_HVDCP_2_REG				(USBIN_BASE + 0x43)
#define RESTART_AICL_BIT			BIT(7)
#define TRIGGER_AICL_BIT			BIT(6)
#define FORCE_12V_BIT				BIT(5)
#define FORCE_9V_BIT				BIT(4)
#define FORCE_5V_BIT				BIT(3)
#define IDLE_BIT				BIT(2)
#define SINGLE_DECREMENT_BIT			BIT(1)
#define SINGLE_INCREMENT_BIT			BIT(0)

#define USB_MISC2_REG				(USBIN_BASE + 0x57)
#define USB_MISC2_MASK				GENMASK(1, 0)

#define TYPE_C_CFG_REG				(USBIN_BASE + 0x58)
#define APSD_START_ON_CC_BIT			BIT(7)
#define WAIT_FOR_APSD_BIT			BIT(6)
#define FACTORY_MODE_DETECTION_EN_BIT		BIT(5)
#define FACTORY_MODE_ICL_3A_4A_BIT		BIT(4)
#define FACTORY_MODE_DIS_CHGING_CFG_BIT		BIT(3)
#define SUSPEND_NON_COMPLIANT_CFG_BIT		BIT(2)
#define VCONN_OC_CFG_BIT			BIT(1)
#define TYPE_C_OR_U_USB_BIT			BIT(0)

#define TYPE_C_CFG_2_REG			(USBIN_BASE + 0x59)
#define TYPE_C_DFP_CURRSRC_MODE_BIT		BIT(7)
#define VCONN_ILIM500MA_CFG_BIT			BIT(6)
#define VCONN_SOFTSTART_CFG_MASK		GENMASK(5, 4)
#define EN_TRY_SOURCE_MODE_BIT			BIT(3)
#define USB_FACTORY_MODE_ENABLE_BIT		BIT(2)
#define TYPE_C_UFP_MODE_BIT			BIT(1)
#define EN_80UA_180UA_CUR_SOURCE_BIT		BIT(0)

#define TYPE_C_CFG_3_REG			(USBIN_BASE + 0x5A)
#define TVBUS_DEBOUNCE_BIT			BIT(7)
#define TYPEC_LEGACY_CABLE_INT_EN_BIT		BIT(6)
#define TYPEC_NONCOMPLIANT_LEGACY_CABLE_INT_EN_BIT		BIT(5)
#define TYPEC_TRYSOURCE_DETECT_INT_EN_BIT	BIT(4)
#define TYPEC_TRYSINK_DETECT_INT_EN_BIT		BIT(3)
#define EN_TRYSINK_MODE_BIT			BIT(2)
#define EN_LEGACY_CABLE_DETECTION_BIT		BIT(1)
#define ALLOW_PD_DRING_UFP_TCCDB_BIT		BIT(0)

#define HVDCP_PULSE_COUNT_MAX_REG		(USBIN_BASE + 0x5B)
#define PULSE_COUNT_QC2P0_12V			BIT(7)
#define PULSE_COUNT_QC2P0_9V			BIT(6)
#define PULSE_COUNT_QC3P0_mask			GENMASK(5, 0)
#define HVDCP_PULSE_COUNT_MAX_QC2_MASK		GENMASK(7, 6)
enum {
	HVDCP_PULSE_COUNT_MAX_QC2_5V,
	HVDCP_PULSE_COUNT_MAX_QC2_9V,
	HVDCP_PULSE_COUNT_MAX_QC2_12V,
	HVDCP_PULSE_COUNT_MAX_QC2_INVALID
};

#define USBIN_ADAPTER_ALLOW_CFG_REG		(USBIN_BASE + 0x60)
#define USBIN_ADAPTER_ALLOW_MASK		GENMASK(3, 0)
enum {
	USBIN_ADAPTER_ALLOW_5V		= 0,
	USBIN_ADAPTER_ALLOW_9V		= 2,
	USBIN_ADAPTER_ALLOW_5V_OR_9V	= 3,
	USBIN_ADAPTER_ALLOW_12V		= 4,
	USBIN_ADAPTER_ALLOW_5V_OR_12V	= 5,
	USBIN_ADAPTER_ALLOW_9V_TO_12V	= 6,
	USBIN_ADAPTER_ALLOW_5V_OR_9V_TO_12V = 7,
	USBIN_ADAPTER_ALLOW_5V_TO_9V	= 8,
	USBIN_ADAPTER_ALLOW_5V_TO_12V	= 12,
};

#define USBIN_OPTIONS_1_CFG_REG			(USBIN_BASE + 0x62)
#define CABLE_R_SEL_BIT				BIT(7)
#define HVDCP_AUTH_ALG_EN_CFG_BIT		BIT(6)
#define HVDCP_AUTONOMOUS_MODE_EN_CFG_BIT	BIT(5)
#define INPUT_PRIORITY_BIT			BIT(4)
#define AUTO_SRC_DETECT_BIT			BIT(3)
#define HVDCP_EN_BIT				BIT(2)
#define VADP_INCREMENT_VOLTAGE_LIMIT_BIT	BIT(1)
#define VADP_TAPER_TIMER_EN_BIT			BIT(0)

#define USBIN_OPTIONS_2_CFG_REG			(USBIN_BASE + 0x63)
#define WIPWR_RST_EUD_CFG_BIT			BIT(7)
#define SWITCHER_START_CFG_BIT			BIT(6)
#define DCD_TIMEOUT_SEL_BIT			BIT(5)
#define OCD_CURRENT_SEL_BIT			BIT(4)
#define SLOW_PLUGIN_TIMER_EN_CFG_BIT		BIT(3)
#define FLOAT_OPTIONS_MASK			GENMASK(2, 0)
#define FLOAT_DIS_CHGING_CFG_BIT		BIT(2)
#define SUSPEND_FLOAT_CFG_BIT			BIT(1)
#define FORCE_FLOAT_SDP_CFG_BIT			BIT(0)

#define TAPER_TIMER_SEL_CFG_REG			(USBIN_BASE + 0x64)
#define TYPEC_SPARE_CFG_BIT			BIT(7)
#define TYPEC_DRP_DFP_TIME_CFG_BIT		BIT(5)
#define TAPER_TIMER_SEL_MASK			GENMASK(1, 0)

#define USBIN_LOAD_CFG_REG			(USBIN_BASE + 0x65)
#define USBIN_OV_CH_LOAD_OPTION_BIT		BIT(7)
#define ICL_OVERRIDE_AFTER_APSD_BIT		BIT(4)
#define USBIN_COLLAPSE_SEL_MASK                 GENMASK(1, 0)

#define USBIN_ICL_OPTIONS_REG			(USBIN_BASE + 0x66)
#define CFG_USB3P0_SEL_BIT			BIT(2)
#define USB51_MODE_BIT				BIT(1)
#define USBIN_MODE_CHG_BIT			BIT(0)

#define TYPE_C_INTRPT_ENB_REG			(USBIN_BASE + 0x67)
#define TYPEC_CCOUT_DETACH_INT_EN_BIT		BIT(7)
#define TYPEC_CCOUT_ATTACH_INT_EN_BIT		BIT(6)
#define TYPEC_VBUS_ERROR_INT_EN_BIT		BIT(5)
#define TYPEC_UFP_AUDIOADAPT_INT_EN_BIT		BIT(4)
#define TYPEC_DEBOUNCE_DONE_INT_EN_BIT		BIT(3)
#define TYPEC_CCSTATE_CHANGE_INT_EN_BIT		BIT(2)
#define TYPEC_VBUS_DEASSERT_INT_EN_BIT		BIT(1)
#define TYPEC_VBUS_ASSERT_INT_EN_BIT		BIT(0)

#define TYPE_C_INTRPT_ENB_SOFTWARE_CTRL_REG	(USBIN_BASE + 0x68)
#define EXIT_SNK_BASED_ON_CC_BIT		BIT(7)
#define VCONN_EN_ORIENTATION_BIT		BIT(6)
#define TYPEC_VCONN_OVERCURR_INT_EN_BIT		BIT(5)
#define VCONN_EN_SRC_BIT			BIT(4)
#define VCONN_EN_VALUE_BIT			BIT(3)
#define TYPEC_POWER_ROLE_CMD_MASK		GENMASK(2, 0)
#define UFP_EN_CMD_BIT				BIT(2)
#define DFP_EN_CMD_BIT				BIT(1)
#define TYPEC_DISABLE_CMD_BIT			BIT(0)

#define USBIN_SOURCE_CHANGE_INTRPT_ENB_REG	(USBIN_BASE + 0x69)
#define SLOW_IRQ_EN_CFG_BIT			BIT(5)
#define ENUMERATION_IRQ_EN_CFG_BIT		BIT(4)
#define VADP_IRQ_EN_CFG_BIT			BIT(3)
#define AUTH_IRQ_EN_CFG_BIT			BIT(2)
#define HVDCP_IRQ_EN_CFG_BIT			BIT(1)
#define APSD_IRQ_EN_CFG_BIT			BIT(0)

#define USBIN_CURRENT_LIMIT_CFG_REG		(USBIN_BASE + 0x70)
#define USBIN_CURRENT_LIMIT_MASK		GENMASK(7, 0)

#define USBIN_AICL_OPTIONS_CFG_REG		(USBIN_BASE + 0x80)
#define SUSPEND_ON_COLLAPSE_USBIN_BIT		BIT(7)
#define USBIN_AICL_HDC_EN_BIT			BIT(6)
#define USBIN_AICL_START_AT_MAX_BIT		BIT(5)
#define USBIN_AICL_RERUN_EN_BIT			BIT(4)
#define USBIN_AICL_ADC_EN_BIT			BIT(3)
#define USBIN_AICL_EN_BIT			BIT(2)
#define USBIN_HV_COLLAPSE_RESPONSE_BIT		BIT(1)
#define USBIN_LV_COLLAPSE_RESPONSE_BIT		BIT(0)

#define USBIN_5V_AICL_THRESHOLD_CFG_REG		(USBIN_BASE + 0x81)
#define USBIN_5V_AICL_THRESHOLD_CFG_MASK	GENMASK(2, 0)

#define USBIN_9V_AICL_THRESHOLD_CFG_REG		(USBIN_BASE + 0x82)
#define USBIN_9V_AICL_THRESHOLD_CFG_MASK	GENMASK(2, 0)

#define USBIN_12V_AICL_THRESHOLD_CFG_REG	(USBIN_BASE + 0x83)
#define USBIN_12V_AICL_THRESHOLD_CFG_MASK	GENMASK(2, 0)

#define USBIN_CONT_AICL_THRESHOLD_CFG_REG	(USBIN_BASE + 0x84)
#define USBIN_CONT_AICL_THRESHOLD_CFG_MASK	GENMASK(5, 0)

/* DCIN Peripheral Registers */
#define DCIN_INPUT_STATUS_REG		(DCIN_BASE + 0x06)
#define DCIN_INPUT_STATUS_7_BIT		BIT(7)
#define DCIN_INPUT_STATUS_6_BIT		BIT(6)
#define DCIN_12V_BIT			BIT(5)
#define DCIN_9V_TO_12V_BIT		BIT(4)
#define DCIN_9V_BIT			BIT(3)
#define DCIN_5V_TO_12V_BIT		BIT(2)
#define DCIN_5V_TO_9V_BIT		BIT(1)
#define DCIN_5V_BIT			BIT(0)

#define WIPWR_STATUS_REG		(DCIN_BASE + 0x07)
#define WIPWR_STATUS_7_BIT		BIT(7)
#define WIPWR_STATUS_6_BIT		BIT(6)
#define WIPWR_STATUS_5_BIT		BIT(5)
#define DCIN_WIPWR_OV_DG_BIT		BIT(4)
#define DIV2_EN_DG_BIT			BIT(3)
#define SHUTDOWN_N_LATCH_BIT		BIT(2)
#define CHG_OK_PIN_BIT			BIT(1)
#define WIPWR_CHARGING_ENABLED_BIT	BIT(0)

#define WIPWR_RANGE_STATUS_REG		(DCIN_BASE + 0x08)
#define WIPWR_RANGE_STATUS_MASK		GENMASK(4, 0)

/* DCIN Interrupt Bits */
#define WIPWR_VOLTAGE_RANGE_RT_STS_BIT	BIT(7)
#define DCIN_ICL_CHANGE_RT_STS_BIT	BIT(6)
#define DIV2_EN_DG_RT_STS_BIT		BIT(5)
#define DCIN_PLUGIN_RT_STS_BIT		BIT(4)
#define DCIN_OV_RT_STS_BIT		BIT(3)
#define DCIN_UV_RT_STS_BIT		BIT(2)
#define DCIN_LT_3P6V_RT_STS_BIT		BIT(1)
#define DCIN_COLLAPSE_RT_STS_BIT	BIT(0)

#define DCIN_CMD_IL_REG				(DCIN_BASE + 0x40)
#define WIRELESS_CHG_DIS_BIT			BIT(3)
#define SHDN_N_CLEAR_CMD_BIT			BIT(2)
#define SHDN_N_SET_CMD_BIT			BIT(1)
#define DCIN_SUSPEND_BIT			BIT(0)

#define DC_SPARE_REG				(DCIN_BASE + 0x58)
#define DC_SPARE_MASK				GENMASK(3, 0)

#define DCIN_ADAPTER_ALLOW_CFG_REG		(DCIN_BASE + 0x60)
#define DCIN_ADAPTER_ALLOW_MASK			GENMASK(3, 0)

#define DCIN_LOAD_CFG_REG			(DCIN_BASE + 0x65)
#define DCIN_OV_CH_LOAD_OPTION_BIT		BIT(7)

#define DCIN_CURRENT_LIMIT_CFG_REG		(DCIN_BASE + 0x70)
#define DCIN_CURRENT_LIMIT_MASK			GENMASK(7, 0)

#define DCIN_AICL_OPTIONS_CFG_REG		(DCIN_BASE + 0x80)
#define SUSPEND_ON_COLLAPSE_DCIN_BIT		BIT(7)
#define DCIN_AICL_HDC_EN_BIT			BIT(6)
#define DCIN_AICL_START_AT_MAX_BIT		BIT(5)
#define DCIN_AICL_RERUN_EN_BIT			BIT(4)
#define DCIN_AICL_ADC_EN_BIT			BIT(3)
#define DCIN_AICL_EN_BIT			BIT(2)
#define DCIN_HV_COLLAPSE_RESPONSE_BIT		BIT(1)
#define DCIN_LV_COLLAPSE_RESPONSE_BIT		BIT(0)

#define DCIN_AICL_REF_SEL_CFG_REG		(DCIN_BASE + 0x81)
#define DCIN_CONT_AICL_THRESHOLD_CFG_MASK	GENMASK(5, 0)

#define DCIN_ICL_START_CFG_REG			(DCIN_BASE + 0x82)
#define DCIN_ICL_START_CFG_BIT			BIT(0)

#define DIV2_EN_GF_TIME_CFG_REG			(DCIN_BASE + 0x90)
#define DIV2_EN_GF_TIME_CFG_MASK		GENMASK(1, 0)

#define WIPWR_IRQ_TMR_CFG_REG			(DCIN_BASE + 0x91)
#define WIPWR_IRQ_TMR_MASK			GENMASK(2, 0)

#define ZIN_ICL_PT_REG				(DCIN_BASE + 0x92)
#define ZIN_ICL_PT_MASK				GENMASK(7, 0)

#define ZIN_ICL_LV_REG				(DCIN_BASE + 0x93)
#define ZIN_ICL_LV_MASK				GENMASK(7, 0)

#define ZIN_ICL_HV_REG				(DCIN_BASE + 0x94)
#define ZIN_ICL_HV_MASK				GENMASK(7, 0)

#define WI_PWR_OPTIONS_REG			(DCIN_BASE + 0x95)
#define CHG_OK_BIT				BIT(7)
#define WIPWR_UVLO_IRQ_OPT_BIT			BIT(6)
#define BUCK_HOLDOFF_ENABLE_BIT			BIT(5)
#define CHG_OK_HW_SW_SELECT_BIT			BIT(4)
#define WIPWR_RST_ENABLE_BIT			BIT(3)
#define DCIN_WIPWR_IRQ_SELECT_BIT		BIT(2)
#define AICL_SWITCH_ENABLE_BIT			BIT(1)
#define ZIN_ICL_ENABLE_BIT			BIT(0)

#define ZIN_ICL_PT_HV_REG			(DCIN_BASE + 0x96)
#define ZIN_ICL_PT_HV_MASK			GENMASK(7, 0)

#define ZIN_ICL_MID_LV_REG			(DCIN_BASE + 0x97)
#define ZIN_ICL_MID_LV_MASK			GENMASK(7, 0)

#define ZIN_ICL_MID_HV_REG			(DCIN_BASE + 0x98)
#define ZIN_ICL_MID_HV_MASK			GENMASK(7, 0)

enum {
	ZIN_ICL_PT_MAX_MV = 8000,
	ZIN_ICL_PT_HV_MAX_MV = 9000,
	ZIN_ICL_LV_MAX_MV = 5500,
	ZIN_ICL_MID_LV_MAX_MV = 6500,
	ZIN_ICL_MID_HV_MAX_MV = 8000,
	ZIN_ICL_HV_MAX_MV = 11000,
};

#define DC_ENG_SSUPPLY_CFG2_REG			(DCIN_BASE + 0xC1)
#define ENG_SSUPPLY_IVREF_OTG_SS_MASK		GENMASK(2, 0)
#define OTG_SS_SLOW				0x3

#define DC_ENG_SSUPPLY_CFG3_REG			(DCIN_BASE + 0xC2)
#define ENG_SSUPPLY_HI_CAP_BIT			BIT(6)
#define ENG_SSUPPLY_HI_RES_BIT			BIT(5)
#define ENG_SSUPPLY_CFG_SKIP_TH_V0P2_BIT	BIT(3)
#define ENG_SSUPPLY_CFG_SYSOV_TH_4P8_BIT	BIT(2)
#define ENG_SSUPPLY_5V_OV_OPT_BIT		BIT(0)

/* MISC Peripheral Registers */
#define REVISION1_REG				(MISC_BASE + 0x00)
#define DIG_MINOR_MASK				GENMASK(7, 0)

#define REVISION2_REG				(MISC_BASE + 0x01)
#define DIG_MAJOR_MASK				GENMASK(7, 0)

#define REVISION3_REG				(MISC_BASE + 0x02)
#define ANA_MINOR_MASK				GENMASK(7, 0)

#define REVISION4_REG				(MISC_BASE + 0x03)
#define ANA_MAJOR_MASK				GENMASK(7, 0)

#define TEMP_RANGE_STATUS_REG			(MISC_BASE + 0x06)
#define TEMP_RANGE_STATUS_7_BIT			BIT(7)
#define THERM_REG_ACTIVE_BIT			BIT(6)
#define TLIM_BIT				BIT(5)
#define TEMP_RANGE_MASK				GENMASK(4, 1)
#define ALERT_LEVEL_BIT				BIT(4)
#define TEMP_ABOVE_RANGE_BIT			BIT(3)
#define TEMP_WITHIN_RANGE_BIT			BIT(2)
#define TEMP_BELOW_RANGE_BIT			BIT(1)
#define THERMREG_DISABLED_BIT			BIT(0)

#define ICL_STATUS_REG				(MISC_BASE + 0x07)
#define INPUT_CURRENT_LIMIT_MASK		GENMASK(7, 0)

#define ADAPTER_5V_ICL_STATUS_REG		(MISC_BASE + 0x08)
#define ADAPTER_5V_ICL_MASK			GENMASK(7, 0)

#define ADAPTER_9V_ICL_STATUS_REG		(MISC_BASE + 0x09)
#define ADAPTER_9V_ICL_MASK			GENMASK(7, 0)

#define AICL_STATUS_REG				(MISC_BASE + 0x0A)
#define AICL_STATUS_7_BIT			BIT(7)
#define SOFT_ILIMIT_BIT				BIT(6)
#define HIGHEST_DC_BIT				BIT(5)
#define USBIN_CH_COLLAPSE_BIT			BIT(4)
#define DCIN_CH_COLLAPSE_BIT			BIT(3)
#define ICL_IMIN_BIT				BIT(2)
#define AICL_FAIL_BIT				BIT(1)
#define AICL_DONE_BIT				BIT(0)

#define POWER_PATH_STATUS_REG			(MISC_BASE + 0x0B)
#define INPUT_SS_DONE_BIT			BIT(7)
#define USBIN_SUSPEND_STS_BIT			BIT(6)
#define DCIN_SUSPEND_STS_BIT			BIT(5)
#define USE_USBIN_BIT				BIT(4)
#define USE_DCIN_BIT				BIT(3)
#define POWER_PATH_MASK				GENMASK(2, 1)
#define VALID_INPUT_POWER_SOURCE_STS_BIT	BIT(0)

#define WDOG_STATUS_REG				(MISC_BASE + 0x0C)
#define WDOG_STATUS_7_BIT			BIT(7)
#define WDOG_STATUS_6_BIT			BIT(6)
#define WDOG_STATUS_5_BIT			BIT(5)
#define WDOG_STATUS_4_BIT			BIT(4)
#define WDOG_STATUS_3_BIT			BIT(3)
#define WDOG_STATUS_2_BIT			BIT(2)
#define WDOG_STATUS_1_BIT			BIT(1)
#define BARK_BITE_STATUS_BIT			BIT(0)

#define SYSOK_REASON_STATUS_REG			(MISC_BASE + 0x0D)
#define SYSOK_REASON_DCIN_BIT			BIT(1)
#define SYSOK_REASON_USBIN_BIT			BIT(0)

/* MISC Interrupt Bits */
#define SWITCHER_POWER_OK_RT_STS_BIT		BIT(7)
#define TEMPERATURE_CHANGE_RT_STS_BIT		BIT(6)
#define INPUT_CURRENT_LIMITING_RT_STS_BIT	BIT(5)
#define HIGH_DUTY_CYCLE_RT_STS_BIT		BIT(4)
#define AICL_DONE_RT_STS_BIT			BIT(3)
#define AICL_FAIL_RT_STS_BIT			BIT(2)
#define WDOG_BARK_RT_STS_BIT			BIT(1)
#define WDOG_SNARL_RT_STS_BIT			BIT(0)

#define WDOG_RST_REG				(MISC_BASE + 0x40)
#define WDOG_RST_BIT				BIT(0)

#define AFP_MODE_REG				(MISC_BASE + 0x41)
#define AFP_MODE_EN_BIT				BIT(0)

#define GSM_PA_ON_ADJ_EN_REG			(MISC_BASE + 0x42)
#define GSM_PA_ON_ADJ_EN_BIT			BIT(0)

#define BARK_BITE_WDOG_PET_REG			(MISC_BASE + 0x43)
#define BARK_BITE_WDOG_PET_BIT			BIT(0)

#define PHYON_CMD_REG				(MISC_BASE + 0x44)
#define PHYON_CMD_BIT				BIT(0)

#define SHDN_CMD_REG				(MISC_BASE + 0x45)
#define SHDN_CMD_BIT				BIT(0)

#define FINISH_COPY_COMMAND_REG			(MISC_BASE + 0x4F)
#define START_COPY_BIT				BIT(0)

#define WD_CFG_REG				(MISC_BASE + 0x51)
#define WATCHDOG_TRIGGER_AFP_EN_BIT		BIT(7)
#define BARK_WDOG_INT_EN_BIT			BIT(6)
#define BITE_WDOG_INT_EN_BIT			BIT(5)
#define SFT_AFTER_WDOG_IRQ_MASK			GENMASK(4, 3)
#define WDOG_IRQ_SFT_BIT			BIT(2)
#define WDOG_TIMER_EN_ON_PLUGIN_BIT		BIT(1)
#define WDOG_TIMER_EN_BIT			BIT(0)

#define MISC_CFG_REG				(MISC_BASE + 0x52)
#define GSM_PA_ON_ADJ_SEL_BIT			BIT(0)
#define STAT_PARALLEL_1400MA_EN_CFG_BIT		BIT(3)
#define TCC_DEBOUNCE_20MS_BIT			BIT(5)

#define SNARL_BARK_BITE_WD_CFG_REG		(MISC_BASE + 0x53)
#define BITE_WDOG_DISABLE_CHARGING_CFG_BIT	BIT(7)
#define SNARL_WDOG_TIMEOUT_MASK			GENMASK(6, 4)
#define BARK_WDOG_TIMEOUT_MASK			GENMASK(3, 2)
#define BITE_WDOG_TIMEOUT_MASK			GENMASK(1, 0)

#define PHYON_CFG_REG				(MISC_BASE + 0x54)
#define USBPHYON_PUSHPULL_CFG_BIT		BIT(1)
#define PHYON_SW_SEL_BIT			BIT(0)

#define CHGR_TRIM_OPTIONS_7_0_REG		(MISC_BASE + 0x55)
#define TLIM_DIS_TBIT_BIT			BIT(0)

#define CH_OV_OPTION_CFG_REG			(MISC_BASE + 0x56)
#define OV_OPTION_TBIT_BIT			BIT(0)

#define AICL_CFG_REG				(MISC_BASE + 0x60)
#define TREG_ALLOW_DECREASE_BIT			BIT(1)
#define AICL_HIGH_DC_INC_BIT			BIT(0)

#define AICL_RERUN_TIME_CFG_REG			(MISC_BASE + 0x61)
#define AICL_RERUN_TIME_MASK			GENMASK(1, 0)

#define AICL_RERUN_TEMP_TIME_CFG_REG		(MISC_BASE + 0x62)
#define AICL_RERUN_TEMP_TIME_MASK		GENMASK(1, 0)

#define THERMREG_SRC_CFG_REG			(MISC_BASE + 0x70)
#define SKIN_ADC_CFG_BIT			BIT(3)
#define THERMREG_SKIN_ADC_SRC_EN_BIT		BIT(2)
#define THERMREG_DIE_ADC_SRC_EN_BIT		BIT(1)
#define THERMREG_DIE_CMP_SRC_EN_BIT		BIT(0)

#define TREG_DIE_CMP_INC_CYCLE_TIME_CFG_REG	(MISC_BASE + 0x71)
#define TREG_DIE_CMP_INC_CYCLE_TIME_MASK	GENMASK(1, 0)

#define TREG_DIE_CMP_DEC_CYCLE_TIME_CFG_REG	(MISC_BASE + 0x72)
#define TREG_DIE_CMP_DEC_CYCLE_TIME_MASK	GENMASK(1, 0)

#define TREG_DIE_ADC_INC_CYCLE_TIME_CFG_REG	(MISC_BASE + 0x73)
#define TREG_DIE_ADC_INC_CYCLE_TIME_MASK	GENMASK(1, 0)

#define TREG_DIE_ADC_DEC_CYCLE_TIME_CFG_REG	(MISC_BASE + 0x74)
#define TREG_DIE_ADC_DEC_CYCLE_TIME_MASK	GENMASK(1, 0)

#define TREG_SKIN_ADC_INC_CYCLE_TIME_CFG_REG	(MISC_BASE + 0x75)
#define TREG_SKIN_ADC_INC_CYCLE_TIME_MASK	GENMASK(1, 0)

#define TREG_SKIN_ADC_DEC_CYCLE_TIME_CFG_REG	(MISC_BASE + 0x76)
#define TREG_SKIN_ADC_DEC_CYCLE_TIME_MASK	GENMASK(1, 0)

#define BUCK_OPTIONS_CFG_REG			(MISC_BASE + 0x80)
#define CHG_EN_PIN_SUSPEND_CFG_BIT		BIT(6)
#define HICCUP_OPTIONS_MASK			GENMASK(5, 4)
#define INPUT_CURRENT_LIMIT_SOFTSTART_EN_BIT	BIT(3)
#define HV_HIGH_DUTY_CYCLE_PROTECT_EN_BIT	BIT(2)
#define BUCK_OC_PROTECT_EN_BIT			BIT(1)
#define INPUT_MISS_POLL_EN_BIT			BIT(0)

#define ICL_SOFTSTART_RATE_CFG_REG		(MISC_BASE + 0x81)
#define ICL_SOFTSTART_RATE_MASK			GENMASK(1, 0)

#define ICL_SOFTSTOP_RATE_CFG_REG		(MISC_BASE + 0x82)
#define ICL_SOFTSTOP_RATE_MASK			GENMASK(1, 0)

#define VSYS_MIN_SEL_CFG_REG			(MISC_BASE + 0x83)
#define VSYS_MIN_SEL_MASK			GENMASK(1, 0)

#define TRACKING_VOLTAGE_SEL_CFG_REG		(MISC_BASE + 0x84)
#define TRACKING_VOLTAGE_SEL_BIT		BIT(0)

#define STAT_CFG_REG				(MISC_BASE + 0x90)
#define STAT_SW_OVERRIDE_VALUE_BIT		BIT(7)
#define STAT_SW_OVERRIDE_CFG_BIT		BIT(6)
#define STAT_PARALLEL_OFF_DG_CFG_MASK		GENMASK(5, 4)
#define STAT_POLARITY_CFG_BIT			BIT(3)
#define STAT_PARALLEL_CFG_BIT			BIT(2)
#define STAT_FUNCTION_CFG_BIT			BIT(1)
#define STAT_IRQ_PULSING_EN_BIT			BIT(0)

#define LBC_EN_CFG_REG				(MISC_BASE + 0x91)
#define LBC_DURING_CHARGING_CFG_BIT		BIT(1)
#define LBC_EN_BIT				BIT(0)

#define LBC_PERIOD_CFG_REG			(MISC_BASE + 0x92)
#define LBC_PERIOD_MASK				GENMASK(2, 0)

#define LBC_DUTY_CYCLE_CFG_REG			(MISC_BASE + 0x93)
#define LBC_DUTY_CYCLE_MASK			GENMASK(2, 0)

#define SYSOK_CFG_REG				(MISC_BASE + 0x94)
#define SYSOK_PUSHPULL_CFG_BIT			BIT(5)
#define SYSOK_B_OR_C_SEL_BIT			BIT(4)
#define SYSOK_POL_BIT				BIT(3)
#define SYSOK_OPTIONS_MASK			GENMASK(2, 0)

#define CFG_BUCKBOOST_FREQ_SELECT_BUCK_REG	(MISC_BASE + 0xA0)
#define CFG_BUCKBOOST_FREQ_SELECT_BOOST_REG	(MISC_BASE + 0xA1)

#define TM_IO_DTEST4_SEL			(MISC_BASE + 0xE9)

#define ENG_SDCDC_CFG7_REG			(MISC_BASE + 0xC6)
#define ENG_SDCDC_BST_SET_POINT_MASK		GENMASK(7, 6)

/* CHGR FREQ Peripheral registers */
#define FREQ_CLK_DIV_REG			(CHGR_FREQ_BASE + 0x50)

#endif /* __SMB2_CHARGER_REG_H */
