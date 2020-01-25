/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice_trm.h"

/* P04 */
#define P04__0__DM__MASK 0x07u
#define P04__0__DM__SHIFT 0u
#define P04__0__DR CYREG_PRT1_DR
#define P04__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define P04__0__HSIOM_MASK 0x0000000Fu
#define P04__0__HSIOM_SHIFT 0u
#define P04__0__INTCFG CYREG_PRT1_INTCFG
#define P04__0__INTSTAT CYREG_PRT1_INTSTAT
#define P04__0__MASK 0x01u
#define P04__0__OUT_SEL CYREG_UDB_PA1_CFG10
#define P04__0__OUT_SEL_SHIFT 0u
#define P04__0__OUT_SEL_VAL 3u
#define P04__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define P04__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define P04__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define P04__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define P04__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define P04__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define P04__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define P04__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define P04__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define P04__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define P04__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define P04__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define P04__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define P04__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define P04__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define P04__0__PC CYREG_PRT1_PC
#define P04__0__PC2 CYREG_PRT1_PC2
#define P04__0__PORT 1u
#define P04__0__PS CYREG_PRT1_PS
#define P04__0__SHIFT 0u
#define P04__DR CYREG_PRT1_DR
#define P04__INTCFG CYREG_PRT1_INTCFG
#define P04__INTSTAT CYREG_PRT1_INTSTAT
#define P04__MASK 0x01u
#define P04__PA__CFG0 CYREG_UDB_PA1_CFG0
#define P04__PA__CFG1 CYREG_UDB_PA1_CFG1
#define P04__PA__CFG10 CYREG_UDB_PA1_CFG10
#define P04__PA__CFG11 CYREG_UDB_PA1_CFG11
#define P04__PA__CFG12 CYREG_UDB_PA1_CFG12
#define P04__PA__CFG13 CYREG_UDB_PA1_CFG13
#define P04__PA__CFG14 CYREG_UDB_PA1_CFG14
#define P04__PA__CFG2 CYREG_UDB_PA1_CFG2
#define P04__PA__CFG3 CYREG_UDB_PA1_CFG3
#define P04__PA__CFG4 CYREG_UDB_PA1_CFG4
#define P04__PA__CFG5 CYREG_UDB_PA1_CFG5
#define P04__PA__CFG6 CYREG_UDB_PA1_CFG6
#define P04__PA__CFG7 CYREG_UDB_PA1_CFG7
#define P04__PA__CFG8 CYREG_UDB_PA1_CFG8
#define P04__PA__CFG9 CYREG_UDB_PA1_CFG9
#define P04__PC CYREG_PRT1_PC
#define P04__PC2 CYREG_PRT1_PC2
#define P04__PORT 1u
#define P04__PS CYREG_PRT1_PS
#define P04__SHIFT 0u

/* ADC_SAR */
#define ADC_SAR_cy_psoc4_sar__SAR_ANA_TRIM CYREG_SAR_ANA_TRIM
#define ADC_SAR_cy_psoc4_sar__SAR_AVG_STAT CYREG_SAR_AVG_STAT
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_CONFIG00 CYREG_SAR_CHAN_CONFIG00
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_CONFIG01 CYREG_SAR_CHAN_CONFIG01
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_CONFIG02 CYREG_SAR_CHAN_CONFIG02
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_CONFIG03 CYREG_SAR_CHAN_CONFIG03
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_CONFIG04 CYREG_SAR_CHAN_CONFIG04
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_CONFIG05 CYREG_SAR_CHAN_CONFIG05
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_CONFIG06 CYREG_SAR_CHAN_CONFIG06
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_CONFIG07 CYREG_SAR_CHAN_CONFIG07
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_EN CYREG_SAR_CHAN_EN
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_RESULT_VALID CYREG_SAR_CHAN_RESULT_VALID
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_RESULT00 CYREG_SAR_CHAN_RESULT00
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_RESULT01 CYREG_SAR_CHAN_RESULT01
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_RESULT02 CYREG_SAR_CHAN_RESULT02
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_RESULT03 CYREG_SAR_CHAN_RESULT03
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_RESULT04 CYREG_SAR_CHAN_RESULT04
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_RESULT05 CYREG_SAR_CHAN_RESULT05
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_RESULT06 CYREG_SAR_CHAN_RESULT06
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_RESULT07 CYREG_SAR_CHAN_RESULT07
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_WORK_VALID CYREG_SAR_CHAN_WORK_VALID
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_WORK00 CYREG_SAR_CHAN_WORK00
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_WORK01 CYREG_SAR_CHAN_WORK01
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_WORK02 CYREG_SAR_CHAN_WORK02
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_WORK03 CYREG_SAR_CHAN_WORK03
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_WORK04 CYREG_SAR_CHAN_WORK04
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_WORK05 CYREG_SAR_CHAN_WORK05
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_WORK06 CYREG_SAR_CHAN_WORK06
#define ADC_SAR_cy_psoc4_sar__SAR_CHAN_WORK07 CYREG_SAR_CHAN_WORK07
#define ADC_SAR_cy_psoc4_sar__SAR_CTRL CYREG_SAR_CTRL
#define ADC_SAR_cy_psoc4_sar__SAR_DFT_CTRL CYREG_SAR_DFT_CTRL
#define ADC_SAR_cy_psoc4_sar__SAR_INTR CYREG_SAR_INTR
#define ADC_SAR_cy_psoc4_sar__SAR_INTR_CAUSE CYREG_SAR_INTR_CAUSE
#define ADC_SAR_cy_psoc4_sar__SAR_INTR_MASK CYREG_SAR_INTR_MASK
#define ADC_SAR_cy_psoc4_sar__SAR_INTR_MASKED CYREG_SAR_INTR_MASKED
#define ADC_SAR_cy_psoc4_sar__SAR_INTR_SET CYREG_SAR_INTR_SET
#define ADC_SAR_cy_psoc4_sar__SAR_MUX_SWITCH_CLEAR0 CYREG_SAR_MUX_SWITCH_CLEAR0
#define ADC_SAR_cy_psoc4_sar__SAR_MUX_SWITCH_CLEAR1 CYREG_SAR_MUX_SWITCH_CLEAR1
#define ADC_SAR_cy_psoc4_sar__SAR_MUX_SWITCH_HW_CTRL CYREG_SAR_MUX_SWITCH_HW_CTRL
#define ADC_SAR_cy_psoc4_sar__SAR_MUX_SWITCH_STATUS CYREG_SAR_MUX_SWITCH_STATUS
#define ADC_SAR_cy_psoc4_sar__SAR_MUX_SWITCH0 CYREG_SAR_MUX_SWITCH0
#define ADC_SAR_cy_psoc4_sar__SAR_MUX_SWITCH1 CYREG_SAR_MUX_SWITCH1
#define ADC_SAR_cy_psoc4_sar__SAR_NUMBER 0u
#define ADC_SAR_cy_psoc4_sar__SAR_PUMP_CTRL CYREG_SAR_PUMP_CTRL
#define ADC_SAR_cy_psoc4_sar__SAR_RANGE_COND CYREG_SAR_RANGE_COND
#define ADC_SAR_cy_psoc4_sar__SAR_RANGE_INTR CYREG_SAR_RANGE_INTR
#define ADC_SAR_cy_psoc4_sar__SAR_RANGE_INTR_MASK CYREG_SAR_RANGE_INTR_MASK
#define ADC_SAR_cy_psoc4_sar__SAR_RANGE_INTR_MASKED CYREG_SAR_RANGE_INTR_MASKED
#define ADC_SAR_cy_psoc4_sar__SAR_RANGE_INTR_SET CYREG_SAR_RANGE_INTR_SET
#define ADC_SAR_cy_psoc4_sar__SAR_RANGE_THRES CYREG_SAR_RANGE_THRES
#define ADC_SAR_cy_psoc4_sar__SAR_SAMPLE_CTRL CYREG_SAR_SAMPLE_CTRL
#define ADC_SAR_cy_psoc4_sar__SAR_SAMPLE_TIME01 CYREG_SAR_SAMPLE_TIME01
#define ADC_SAR_cy_psoc4_sar__SAR_SAMPLE_TIME23 CYREG_SAR_SAMPLE_TIME23
#define ADC_SAR_cy_psoc4_sar__SAR_SATURATE_INTR CYREG_SAR_SATURATE_INTR
#define ADC_SAR_cy_psoc4_sar__SAR_SATURATE_INTR_MASK CYREG_SAR_SATURATE_INTR_MASK
#define ADC_SAR_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED CYREG_SAR_SATURATE_INTR_MASKED
#define ADC_SAR_cy_psoc4_sar__SAR_SATURATE_INTR_SET CYREG_SAR_SATURATE_INTR_SET
#define ADC_SAR_cy_psoc4_sar__SAR_START_CTRL CYREG_SAR_START_CTRL
#define ADC_SAR_cy_psoc4_sar__SAR_STATUS CYREG_SAR_STATUS
#define ADC_SAR_cy_psoc4_sar__SAR_WOUNDING CYREG_SAR_WOUNDING
#define ADC_SAR_intClock__DIVIDER_MASK 0x0000FFFFu
#define ADC_SAR_intClock__ENABLE CYREG_CLK_DIVIDER_B00
#define ADC_SAR_intClock__ENABLE_MASK 0x80000000u
#define ADC_SAR_intClock__MASK 0x80000000u
#define ADC_SAR_intClock__REGISTER CYREG_CLK_DIVIDER_B00
#define ADC_SAR_IRQ__INTC_CLR_EN_REG CYREG_CM0_ICER
#define ADC_SAR_IRQ__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define ADC_SAR_IRQ__INTC_MASK 0x4000u
#define ADC_SAR_IRQ__INTC_NUMBER 14u
#define ADC_SAR_IRQ__INTC_PRIOR_MASK 0xC00000u
#define ADC_SAR_IRQ__INTC_PRIOR_NUM 1u
#define ADC_SAR_IRQ__INTC_PRIOR_REG CYREG_CM0_IPR3
#define ADC_SAR_IRQ__INTC_SET_EN_REG CYREG_CM0_ISER
#define ADC_SAR_IRQ__INTC_SET_PD_REG CYREG_CM0_ISPR

/* Clock_1 */
#define Clock_1__DIVIDER_MASK 0x0000FFFFu
#define Clock_1__ENABLE CYREG_CLK_DIVIDER_A00
#define Clock_1__ENABLE_MASK 0x80000000u
#define Clock_1__MASK 0x80000000u
#define Clock_1__REGISTER CYREG_CLK_DIVIDER_A00

/* Audio_In */
#define Audio_In__0__DM__MASK 0x1C0u
#define Audio_In__0__DM__SHIFT 6u
#define Audio_In__0__DR CYREG_PRT2_DR
#define Audio_In__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define Audio_In__0__HSIOM_MASK 0x00000F00u
#define Audio_In__0__HSIOM_SHIFT 8u
#define Audio_In__0__INTCFG CYREG_PRT2_INTCFG
#define Audio_In__0__INTSTAT CYREG_PRT2_INTSTAT
#define Audio_In__0__MASK 0x04u
#define Audio_In__0__OUT_SEL CYREG_UDB_PA2_CFG10
#define Audio_In__0__OUT_SEL_SHIFT 4u
#define Audio_In__0__OUT_SEL_VAL 2u
#define Audio_In__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define Audio_In__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define Audio_In__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define Audio_In__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define Audio_In__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define Audio_In__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define Audio_In__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define Audio_In__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define Audio_In__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define Audio_In__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define Audio_In__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define Audio_In__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define Audio_In__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define Audio_In__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define Audio_In__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define Audio_In__0__PC CYREG_PRT2_PC
#define Audio_In__0__PC2 CYREG_PRT2_PC2
#define Audio_In__0__PORT 2u
#define Audio_In__0__PS CYREG_PRT2_PS
#define Audio_In__0__SHIFT 2u
#define Audio_In__DR CYREG_PRT2_DR
#define Audio_In__INTCFG CYREG_PRT2_INTCFG
#define Audio_In__INTSTAT CYREG_PRT2_INTSTAT
#define Audio_In__MASK 0x04u
#define Audio_In__PA__CFG0 CYREG_UDB_PA2_CFG0
#define Audio_In__PA__CFG1 CYREG_UDB_PA2_CFG1
#define Audio_In__PA__CFG10 CYREG_UDB_PA2_CFG10
#define Audio_In__PA__CFG11 CYREG_UDB_PA2_CFG11
#define Audio_In__PA__CFG12 CYREG_UDB_PA2_CFG12
#define Audio_In__PA__CFG13 CYREG_UDB_PA2_CFG13
#define Audio_In__PA__CFG14 CYREG_UDB_PA2_CFG14
#define Audio_In__PA__CFG2 CYREG_UDB_PA2_CFG2
#define Audio_In__PA__CFG3 CYREG_UDB_PA2_CFG3
#define Audio_In__PA__CFG4 CYREG_UDB_PA2_CFG4
#define Audio_In__PA__CFG5 CYREG_UDB_PA2_CFG5
#define Audio_In__PA__CFG6 CYREG_UDB_PA2_CFG6
#define Audio_In__PA__CFG7 CYREG_UDB_PA2_CFG7
#define Audio_In__PA__CFG8 CYREG_UDB_PA2_CFG8
#define Audio_In__PA__CFG9 CYREG_UDB_PA2_CFG9
#define Audio_In__PC CYREG_PRT2_PC
#define Audio_In__PC2 CYREG_PRT2_PC2
#define Audio_In__PORT 2u
#define Audio_In__PS CYREG_PRT2_PS
#define Audio_In__SHIFT 2u
#define Audio_In_Neg__0__DM__MASK 0x07u
#define Audio_In_Neg__0__DM__SHIFT 0u
#define Audio_In_Neg__0__DR CYREG_PRT0_DR
#define Audio_In_Neg__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define Audio_In_Neg__0__HSIOM_MASK 0x0000000Fu
#define Audio_In_Neg__0__HSIOM_SHIFT 0u
#define Audio_In_Neg__0__INTCFG CYREG_PRT0_INTCFG
#define Audio_In_Neg__0__INTSTAT CYREG_PRT0_INTSTAT
#define Audio_In_Neg__0__MASK 0x01u
#define Audio_In_Neg__0__OUT_SEL CYREG_UDB_PA0_CFG10
#define Audio_In_Neg__0__OUT_SEL_SHIFT 0u
#define Audio_In_Neg__0__OUT_SEL_VAL 3u
#define Audio_In_Neg__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define Audio_In_Neg__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define Audio_In_Neg__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define Audio_In_Neg__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define Audio_In_Neg__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define Audio_In_Neg__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define Audio_In_Neg__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define Audio_In_Neg__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define Audio_In_Neg__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define Audio_In_Neg__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define Audio_In_Neg__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define Audio_In_Neg__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define Audio_In_Neg__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define Audio_In_Neg__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define Audio_In_Neg__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define Audio_In_Neg__0__PC CYREG_PRT0_PC
#define Audio_In_Neg__0__PC2 CYREG_PRT0_PC2
#define Audio_In_Neg__0__PORT 0u
#define Audio_In_Neg__0__PS CYREG_PRT0_PS
#define Audio_In_Neg__0__SHIFT 0u
#define Audio_In_Neg__DR CYREG_PRT0_DR
#define Audio_In_Neg__INTCFG CYREG_PRT0_INTCFG
#define Audio_In_Neg__INTSTAT CYREG_PRT0_INTSTAT
#define Audio_In_Neg__MASK 0x01u
#define Audio_In_Neg__PA__CFG0 CYREG_UDB_PA0_CFG0
#define Audio_In_Neg__PA__CFG1 CYREG_UDB_PA0_CFG1
#define Audio_In_Neg__PA__CFG10 CYREG_UDB_PA0_CFG10
#define Audio_In_Neg__PA__CFG11 CYREG_UDB_PA0_CFG11
#define Audio_In_Neg__PA__CFG12 CYREG_UDB_PA0_CFG12
#define Audio_In_Neg__PA__CFG13 CYREG_UDB_PA0_CFG13
#define Audio_In_Neg__PA__CFG14 CYREG_UDB_PA0_CFG14
#define Audio_In_Neg__PA__CFG2 CYREG_UDB_PA0_CFG2
#define Audio_In_Neg__PA__CFG3 CYREG_UDB_PA0_CFG3
#define Audio_In_Neg__PA__CFG4 CYREG_UDB_PA0_CFG4
#define Audio_In_Neg__PA__CFG5 CYREG_UDB_PA0_CFG5
#define Audio_In_Neg__PA__CFG6 CYREG_UDB_PA0_CFG6
#define Audio_In_Neg__PA__CFG7 CYREG_UDB_PA0_CFG7
#define Audio_In_Neg__PA__CFG8 CYREG_UDB_PA0_CFG8
#define Audio_In_Neg__PA__CFG9 CYREG_UDB_PA0_CFG9
#define Audio_In_Neg__PC CYREG_PRT0_PC
#define Audio_In_Neg__PC2 CYREG_PRT0_PC2
#define Audio_In_Neg__PORT 0u
#define Audio_In_Neg__PS CYREG_PRT0_PS
#define Audio_In_Neg__SHIFT 0u

/* PWM_Tick */
#define PWM_Tick_cy_m0s8_tcpwm_1__CC CYREG_TCPWM_CNT0_CC
#define PWM_Tick_cy_m0s8_tcpwm_1__CC_BUFF CYREG_TCPWM_CNT0_CC_BUFF
#define PWM_Tick_cy_m0s8_tcpwm_1__COUNTER CYREG_TCPWM_CNT0_COUNTER
#define PWM_Tick_cy_m0s8_tcpwm_1__CTRL CYREG_TCPWM_CNT0_CTRL
#define PWM_Tick_cy_m0s8_tcpwm_1__INTR CYREG_TCPWM_CNT0_INTR
#define PWM_Tick_cy_m0s8_tcpwm_1__INTR_MASK CYREG_TCPWM_CNT0_INTR_MASK
#define PWM_Tick_cy_m0s8_tcpwm_1__INTR_MASKED CYREG_TCPWM_CNT0_INTR_MASKED
#define PWM_Tick_cy_m0s8_tcpwm_1__INTR_SET CYREG_TCPWM_CNT0_INTR_SET
#define PWM_Tick_cy_m0s8_tcpwm_1__PERIOD CYREG_TCPWM_CNT0_PERIOD
#define PWM_Tick_cy_m0s8_tcpwm_1__PERIOD_BUFF CYREG_TCPWM_CNT0_PERIOD_BUFF
#define PWM_Tick_cy_m0s8_tcpwm_1__STATUS CYREG_TCPWM_CNT0_STATUS
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_CMD CYREG_TCPWM_CMD
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK 0x01u
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT 0u
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK 0x100u
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT 8u
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK 0x1000000u
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT 24u
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK 0x10000u
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT 16u
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_CTRL CYREG_TCPWM_CTRL
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK 0x01u
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT 0u
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE CYREG_TCPWM_INTR_CAUSE
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK 0x01u
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT 0u
#define PWM_Tick_cy_m0s8_tcpwm_1__TCPWM_NUMBER 0u
#define PWM_Tick_cy_m0s8_tcpwm_1__TR_CTRL0 CYREG_TCPWM_CNT0_TR_CTRL0
#define PWM_Tick_cy_m0s8_tcpwm_1__TR_CTRL1 CYREG_TCPWM_CNT0_TR_CTRL1
#define PWM_Tick_cy_m0s8_tcpwm_1__TR_CTRL2 CYREG_TCPWM_CNT0_TR_CTRL2

/* StripLights */
#define StripLights_B_WS2811_ctrl__0__MASK 0x01u
#define StripLights_B_WS2811_ctrl__0__POS 0
#define StripLights_B_WS2811_ctrl__16BIT_CONTROL_AUX_CTL_REG CYREG_UDB_W16_ACTL_02
#define StripLights_B_WS2811_ctrl__16BIT_CONTROL_CONTROL_REG CYREG_UDB_W16_CTL_02
#define StripLights_B_WS2811_ctrl__16BIT_CONTROL_COUNT_REG CYREG_UDB_W16_CTL_02
#define StripLights_B_WS2811_ctrl__16BIT_COUNT_CONTROL_REG CYREG_UDB_W16_CTL_02
#define StripLights_B_WS2811_ctrl__16BIT_COUNT_COUNT_REG CYREG_UDB_W16_CTL_02
#define StripLights_B_WS2811_ctrl__16BIT_MASK_MASK_REG CYREG_UDB_W16_MSK_02
#define StripLights_B_WS2811_ctrl__16BIT_MASK_PERIOD_REG CYREG_UDB_W16_MSK_02
#define StripLights_B_WS2811_ctrl__16BIT_PERIOD_MASK_REG CYREG_UDB_W16_MSK_02
#define StripLights_B_WS2811_ctrl__16BIT_PERIOD_PERIOD_REG CYREG_UDB_W16_MSK_02
#define StripLights_B_WS2811_ctrl__3__MASK 0x08u
#define StripLights_B_WS2811_ctrl__3__POS 3
#define StripLights_B_WS2811_ctrl__4__MASK 0x10u
#define StripLights_B_WS2811_ctrl__4__POS 4
#define StripLights_B_WS2811_ctrl__5__MASK 0x20u
#define StripLights_B_WS2811_ctrl__5__POS 5
#define StripLights_B_WS2811_ctrl__CONTROL_AUX_CTL_REG CYREG_UDB_W8_ACTL_02
#define StripLights_B_WS2811_ctrl__CONTROL_REG CYREG_UDB_W8_CTL_02
#define StripLights_B_WS2811_ctrl__CONTROL_ST_REG CYREG_UDB_CAT16_CTL_ST_02
#define StripLights_B_WS2811_ctrl__COUNT_REG CYREG_UDB_W8_CTL_02
#define StripLights_B_WS2811_ctrl__COUNT_ST_REG CYREG_UDB_CAT16_CTL_ST_02
#define StripLights_B_WS2811_ctrl__MASK 0x39u
#define StripLights_B_WS2811_ctrl__MASK_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define StripLights_B_WS2811_ctrl__PER_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define StripLights_B_WS2811_ctrl__PERIOD_REG CYREG_UDB_W8_MSK_02
#define StripLights_B_WS2811_dshifter_u0__16BIT_A0_REG CYREG_UDB_W16_A0_02
#define StripLights_B_WS2811_dshifter_u0__16BIT_A1_REG CYREG_UDB_W16_A1_02
#define StripLights_B_WS2811_dshifter_u0__16BIT_D0_REG CYREG_UDB_W16_D0_02
#define StripLights_B_WS2811_dshifter_u0__16BIT_D1_REG CYREG_UDB_W16_D1_02
#define StripLights_B_WS2811_dshifter_u0__16BIT_DP_AUX_CTL_REG CYREG_UDB_W16_ACTL_02
#define StripLights_B_WS2811_dshifter_u0__16BIT_F0_REG CYREG_UDB_W16_F0_02
#define StripLights_B_WS2811_dshifter_u0__16BIT_F1_REG CYREG_UDB_W16_F1_02
#define StripLights_B_WS2811_dshifter_u0__A0_A1_REG CYREG_UDB_CAT16_A_02
#define StripLights_B_WS2811_dshifter_u0__A0_REG CYREG_UDB_W8_A0_02
#define StripLights_B_WS2811_dshifter_u0__A1_REG CYREG_UDB_W8_A1_02
#define StripLights_B_WS2811_dshifter_u0__D0_D1_REG CYREG_UDB_CAT16_D_02
#define StripLights_B_WS2811_dshifter_u0__D0_REG CYREG_UDB_W8_D0_02
#define StripLights_B_WS2811_dshifter_u0__D1_REG CYREG_UDB_W8_D1_02
#define StripLights_B_WS2811_dshifter_u0__DP_AUX_CTL_REG CYREG_UDB_W8_ACTL_02
#define StripLights_B_WS2811_dshifter_u0__F0_F1_REG CYREG_UDB_CAT16_F_02
#define StripLights_B_WS2811_dshifter_u0__F0_REG CYREG_UDB_W8_F0_02
#define StripLights_B_WS2811_dshifter_u0__F1_REG CYREG_UDB_W8_F1_02
#define StripLights_B_WS2811_dshifter_u0__MSK_DP_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define StripLights_B_WS2811_dshifter_u0__PER_DP_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define StripLights_B_WS2811_pwm8_u0__16BIT_A0_REG CYREG_UDB_W16_A0_01
#define StripLights_B_WS2811_pwm8_u0__16BIT_A1_REG CYREG_UDB_W16_A1_01
#define StripLights_B_WS2811_pwm8_u0__16BIT_D0_REG CYREG_UDB_W16_D0_01
#define StripLights_B_WS2811_pwm8_u0__16BIT_D1_REG CYREG_UDB_W16_D1_01
#define StripLights_B_WS2811_pwm8_u0__16BIT_DP_AUX_CTL_REG CYREG_UDB_W16_ACTL_01
#define StripLights_B_WS2811_pwm8_u0__16BIT_F0_REG CYREG_UDB_W16_F0_01
#define StripLights_B_WS2811_pwm8_u0__16BIT_F1_REG CYREG_UDB_W16_F1_01
#define StripLights_B_WS2811_pwm8_u0__A0_A1_REG CYREG_UDB_CAT16_A_01
#define StripLights_B_WS2811_pwm8_u0__A0_REG CYREG_UDB_W8_A0_01
#define StripLights_B_WS2811_pwm8_u0__A1_REG CYREG_UDB_W8_A1_01
#define StripLights_B_WS2811_pwm8_u0__D0_D1_REG CYREG_UDB_CAT16_D_01
#define StripLights_B_WS2811_pwm8_u0__D0_REG CYREG_UDB_W8_D0_01
#define StripLights_B_WS2811_pwm8_u0__D1_REG CYREG_UDB_W8_D1_01
#define StripLights_B_WS2811_pwm8_u0__DP_AUX_CTL_REG CYREG_UDB_W8_ACTL_01
#define StripLights_B_WS2811_pwm8_u0__F0_F1_REG CYREG_UDB_CAT16_F_01
#define StripLights_B_WS2811_pwm8_u0__F0_REG CYREG_UDB_W8_F0_01
#define StripLights_B_WS2811_pwm8_u0__F1_REG CYREG_UDB_W8_F1_01
#define StripLights_B_WS2811_pwm8_u0__MSK_DP_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_01
#define StripLights_B_WS2811_pwm8_u0__PER_DP_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_01
#define StripLights_B_WS2811_StatusReg__0__MASK 0x01u
#define StripLights_B_WS2811_StatusReg__0__POS 0
#define StripLights_B_WS2811_StatusReg__1__MASK 0x02u
#define StripLights_B_WS2811_StatusReg__1__POS 1
#define StripLights_B_WS2811_StatusReg__16BIT_STATUS_AUX_CTL_REG CYREG_UDB_W16_ACTL_02
#define StripLights_B_WS2811_StatusReg__16BIT_STATUS_REG CYREG_UDB_W16_ST_02
#define StripLights_B_WS2811_StatusReg__6__MASK 0x40u
#define StripLights_B_WS2811_StatusReg__6__POS 6
#define StripLights_B_WS2811_StatusReg__7__MASK 0x80u
#define StripLights_B_WS2811_StatusReg__7__POS 7
#define StripLights_B_WS2811_StatusReg__MASK 0xC3u
#define StripLights_B_WS2811_StatusReg__MASK_REG CYREG_UDB_W8_MSK_02
#define StripLights_B_WS2811_StatusReg__MASK_ST_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define StripLights_B_WS2811_StatusReg__PER_ST_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define StripLights_B_WS2811_StatusReg__STATUS_AUX_CTL_REG CYREG_UDB_W8_ACTL_02
#define StripLights_B_WS2811_StatusReg__STATUS_CNT_REG CYREG_UDB_CAT16_CTL_ST_02
#define StripLights_B_WS2811_StatusReg__STATUS_CONTROL_REG CYREG_UDB_CAT16_CTL_ST_02
#define StripLights_B_WS2811_StatusReg__STATUS_REG CYREG_UDB_W8_ST_02
#define StripLights_isr__INTC_CLR_EN_REG CYREG_CM0_ICER
#define StripLights_isr__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define StripLights_isr__INTC_MASK 0x01u
#define StripLights_isr__INTC_NUMBER 0u
#define StripLights_isr__INTC_PRIOR_MASK 0xC0u
#define StripLights_isr__INTC_PRIOR_NUM 0u
#define StripLights_isr__INTC_PRIOR_REG CYREG_CM0_IPR0
#define StripLights_isr__INTC_SET_EN_REG CYREG_CM0_ISER
#define StripLights_isr__INTC_SET_PD_REG CYREG_CM0_ISPR
#define StripLights_StringSel_Sync_ctrl_reg__0__MASK 0x01u
#define StripLights_StringSel_Sync_ctrl_reg__0__POS 0
#define StripLights_StringSel_Sync_ctrl_reg__1__MASK 0x02u
#define StripLights_StringSel_Sync_ctrl_reg__1__POS 1
#define StripLights_StringSel_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG CYREG_UDB_W16_ACTL_01
#define StripLights_StringSel_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG CYREG_UDB_W16_CTL_01
#define StripLights_StringSel_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG CYREG_UDB_W16_CTL_01
#define StripLights_StringSel_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG CYREG_UDB_W16_CTL_01
#define StripLights_StringSel_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG CYREG_UDB_W16_CTL_01
#define StripLights_StringSel_Sync_ctrl_reg__16BIT_MASK_MASK_REG CYREG_UDB_W16_MSK_01
#define StripLights_StringSel_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG CYREG_UDB_W16_MSK_01
#define StripLights_StringSel_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG CYREG_UDB_W16_MSK_01
#define StripLights_StringSel_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG CYREG_UDB_W16_MSK_01
#define StripLights_StringSel_Sync_ctrl_reg__2__MASK 0x04u
#define StripLights_StringSel_Sync_ctrl_reg__2__POS 2
#define StripLights_StringSel_Sync_ctrl_reg__3__MASK 0x08u
#define StripLights_StringSel_Sync_ctrl_reg__3__POS 3
#define StripLights_StringSel_Sync_ctrl_reg__CONTROL_AUX_CTL_REG CYREG_UDB_W8_ACTL_01
#define StripLights_StringSel_Sync_ctrl_reg__CONTROL_REG CYREG_UDB_W8_CTL_01
#define StripLights_StringSel_Sync_ctrl_reg__CONTROL_ST_REG CYREG_UDB_CAT16_CTL_ST_01
#define StripLights_StringSel_Sync_ctrl_reg__COUNT_REG CYREG_UDB_W8_CTL_01
#define StripLights_StringSel_Sync_ctrl_reg__COUNT_ST_REG CYREG_UDB_CAT16_CTL_ST_01
#define StripLights_StringSel_Sync_ctrl_reg__MASK 0x0Fu
#define StripLights_StringSel_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_01
#define StripLights_StringSel_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_01
#define StripLights_StringSel_Sync_ctrl_reg__PERIOD_REG CYREG_UDB_W8_MSK_01

/* Opamp_Buffer */
#define Opamp_Buffer_cy_psoc4_abuf__COMP_STAT CYREG_CTBM_COMP_STAT
#define Opamp_Buffer_cy_psoc4_abuf__COMP_STAT_SHIFT 0u
#define Opamp_Buffer_cy_psoc4_abuf__CTBM_CTB_CTRL CYREG_CTBM_CTB_CTRL
#define Opamp_Buffer_cy_psoc4_abuf__INTR CYREG_CTBM_INTR
#define Opamp_Buffer_cy_psoc4_abuf__INTR_MASK CYREG_CTBM_INTR_MASK
#define Opamp_Buffer_cy_psoc4_abuf__INTR_MASK_SHIFT 0u
#define Opamp_Buffer_cy_psoc4_abuf__INTR_MASKED CYREG_CTBM_INTR_MASKED
#define Opamp_Buffer_cy_psoc4_abuf__INTR_MASKED_SHIFT 0u
#define Opamp_Buffer_cy_psoc4_abuf__INTR_SET CYREG_CTBM_INTR_SET
#define Opamp_Buffer_cy_psoc4_abuf__INTR_SET_SHIFT 0u
#define Opamp_Buffer_cy_psoc4_abuf__INTR_SHIFT 0u
#define Opamp_Buffer_cy_psoc4_abuf__OA_COMP_TRIM CYREG_CTBM_OA0_COMP_TRIM
#define Opamp_Buffer_cy_psoc4_abuf__OA_NUMBER 0u
#define Opamp_Buffer_cy_psoc4_abuf__OA_OFFSET_TRIM CYREG_CTBM_OA0_OFFSET_TRIM
#define Opamp_Buffer_cy_psoc4_abuf__OA_RES_CTRL CYREG_CTBM_OA_RES0_CTRL
#define Opamp_Buffer_cy_psoc4_abuf__OA_SLOPE_OFFSET_TRIM CYREG_CTBM_OA0_SLOPE_OFFSET_TRIM
#define Opamp_Buffer_cy_psoc4_abuf__OA_SW CYREG_CTBM_OA0_SW
#define Opamp_Buffer_cy_psoc4_abuf__OA_SW_CLEAR CYREG_CTBM_OA0_SW_CLEAR

/* Control_Reg_NeoWrite */
#define Control_Reg_NeoWrite_Sync_ctrl_reg__0__MASK 0x01u
#define Control_Reg_NeoWrite_Sync_ctrl_reg__0__POS 0
#define Control_Reg_NeoWrite_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG CYREG_UDB_W16_ACTL_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG CYREG_UDB_W16_CTL_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG CYREG_UDB_W16_CTL_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG CYREG_UDB_W16_CTL_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG CYREG_UDB_W16_CTL_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__16BIT_MASK_MASK_REG CYREG_UDB_W16_MSK_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG CYREG_UDB_W16_MSK_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG CYREG_UDB_W16_MSK_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG CYREG_UDB_W16_MSK_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__32BIT_CONTROL_AUX_CTL_REG CYREG_UDB_W32_ACTL_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__32BIT_CONTROL_REG CYREG_UDB_W32_CTL_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__32BIT_COUNT_REG CYREG_UDB_W32_CTL_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__32BIT_PERIOD_REG CYREG_UDB_W32_MSK_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__CONTROL_AUX_CTL_REG CYREG_UDB_W8_ACTL_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__CONTROL_REG CYREG_UDB_W8_CTL_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__CONTROL_ST_REG CYREG_UDB_CAT16_CTL_ST_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__COUNT_REG CYREG_UDB_W8_CTL_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__COUNT_ST_REG CYREG_UDB_CAT16_CTL_ST_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__MASK 0x01u
#define Control_Reg_NeoWrite_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_00
#define Control_Reg_NeoWrite_Sync_ctrl_reg__PERIOD_REG CYREG_UDB_W8_MSK_00

/* Miscellaneous */
#define CY_PROJECT_NAME "SpectrumAnalyzer_NeoPixel"
#define CY_VERSION "PSoC Creator  4.2"
#define CYDEV_BANDGAP_VOLTAGE 1.024
#define CYDEV_BCLK__HFCLK__HZ 48000000U
#define CYDEV_BCLK__HFCLK__KHZ 48000U
#define CYDEV_BCLK__HFCLK__MHZ 48U
#define CYDEV_BCLK__SYSCLK__HZ 48000000U
#define CYDEV_BCLK__SYSCLK__KHZ 48000U
#define CYDEV_BCLK__SYSCLK__MHZ 48U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 18u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC4
#define CYDEV_CHIP_JTAG_ID 0x04C81193u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 18u
#define CYDEV_CHIP_MEMBER_4D 13u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 19u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 17u
#define CYDEV_CHIP_MEMBER_4I 23u
#define CYDEV_CHIP_MEMBER_4J 14u
#define CYDEV_CHIP_MEMBER_4K 15u
#define CYDEV_CHIP_MEMBER_4L 22u
#define CYDEV_CHIP_MEMBER_4M 21u
#define CYDEV_CHIP_MEMBER_4N 10u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 20u
#define CYDEV_CHIP_MEMBER_4Q 12u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 11u
#define CYDEV_CHIP_MEMBER_4T 9u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 16u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 24u
#define CYDEV_CHIP_MEMBER_FM3 28u
#define CYDEV_CHIP_MEMBER_FM4 29u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 25u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 26u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 27u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_4A
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_4A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_PROTECT_KILL 4
#define CYDEV_DEBUG_PROTECT_OPEN 1
#define CYDEV_DEBUG_PROTECT CYDEV_DEBUG_PROTECT_OPEN
#define CYDEV_DEBUG_PROTECT_PROTECTED 2
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DFT_SELECT_CLK0 1u
#define CYDEV_DFT_SELECT_CLK1 2u
#define CYDEV_HEAP_SIZE 0x0100
#define CYDEV_IMO_TRIMMED_BY_USB 0u
#define CYDEV_IMO_TRIMMED_BY_WCO 0u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_STACK_SIZE 0x0400
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 1
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYDEV_WDT_GENERATE_ISR 0u
#define CYIPBLOCK_M0S8_CTBM_VERSION 0
#define CYIPBLOCK_m0s8cpuss_VERSION 0
#define CYIPBLOCK_m0s8csd_VERSION 0
#define CYIPBLOCK_m0s8gpio2_VERSION 0
#define CYIPBLOCK_m0s8hsiom4a_VERSION 0
#define CYIPBLOCK_m0s8lcd_VERSION 0
#define CYIPBLOCK_m0s8lpcomp_VERSION 0
#define CYIPBLOCK_m0s8pclk_VERSION 0
#define CYIPBLOCK_m0s8sar_VERSION 0
#define CYIPBLOCK_m0s8scb_VERSION 0
#define CYIPBLOCK_m0s8srssv2_VERSION 1
#define CYIPBLOCK_m0s8tcpwm_VERSION 0
#define CYIPBLOCK_m0s8udbif_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 2
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
