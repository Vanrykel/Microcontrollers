/*******************************************************************************
* File Name: cyfittergnu.inc
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

.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu_trm.inc"

/* PWM */
.set PWM_cy_m0s8_tcpwm_1__CC, CYREG_TCPWM_CNT0_CC
.set PWM_cy_m0s8_tcpwm_1__CC_BUFF, CYREG_TCPWM_CNT0_CC_BUFF
.set PWM_cy_m0s8_tcpwm_1__COUNTER, CYREG_TCPWM_CNT0_COUNTER
.set PWM_cy_m0s8_tcpwm_1__CTRL, CYREG_TCPWM_CNT0_CTRL
.set PWM_cy_m0s8_tcpwm_1__INTR, CYREG_TCPWM_CNT0_INTR
.set PWM_cy_m0s8_tcpwm_1__INTR_MASK, CYREG_TCPWM_CNT0_INTR_MASK
.set PWM_cy_m0s8_tcpwm_1__INTR_MASKED, CYREG_TCPWM_CNT0_INTR_MASKED
.set PWM_cy_m0s8_tcpwm_1__INTR_SET, CYREG_TCPWM_CNT0_INTR_SET
.set PWM_cy_m0s8_tcpwm_1__PERIOD, CYREG_TCPWM_CNT0_PERIOD
.set PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF, CYREG_TCPWM_CNT0_PERIOD_BUFF
.set PWM_cy_m0s8_tcpwm_1__STATUS, CYREG_TCPWM_CNT0_STATUS
.set PWM_cy_m0s8_tcpwm_1__TCPWM_CMD, CYREG_TCPWM_CMD
.set PWM_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK, 0x01
.set PWM_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT, 0
.set PWM_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK, 0x100
.set PWM_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT, 8
.set PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK, 0x1000000
.set PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT, 24
.set PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK, 0x10000
.set PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT, 16
.set PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL, CYREG_TCPWM_CTRL
.set PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK, 0x01
.set PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT, 0
.set PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE, CYREG_TCPWM_INTR_CAUSE
.set PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK, 0x01
.set PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT, 0
.set PWM_cy_m0s8_tcpwm_1__TCPWM_NUMBER, 0
.set PWM_cy_m0s8_tcpwm_1__TR_CTRL0, CYREG_TCPWM_CNT0_TR_CTRL0
.set PWM_cy_m0s8_tcpwm_1__TR_CTRL1, CYREG_TCPWM_CNT0_TR_CTRL1
.set PWM_cy_m0s8_tcpwm_1__TR_CTRL2, CYREG_TCPWM_CNT0_TR_CTRL2

/* UART */
.set UART_rx__0__DM__MASK, 0x07
.set UART_rx__0__DM__SHIFT, 0
.set UART_rx__0__DR, CYREG_PRT3_DR
.set UART_rx__0__HSIOM, CYREG_HSIOM_PORT_SEL3
.set UART_rx__0__HSIOM_GPIO, 0
.set UART_rx__0__HSIOM_I2C, 14
.set UART_rx__0__HSIOM_I2C_SCL, 14
.set UART_rx__0__HSIOM_MASK, 0x0000000F
.set UART_rx__0__HSIOM_SHIFT, 0
.set UART_rx__0__HSIOM_SPI, 15
.set UART_rx__0__HSIOM_SPI_MOSI, 15
.set UART_rx__0__HSIOM_UART, 9
.set UART_rx__0__HSIOM_UART_RX, 9
.set UART_rx__0__INTCFG, CYREG_PRT3_INTCFG
.set UART_rx__0__INTSTAT, CYREG_PRT3_INTSTAT
.set UART_rx__0__MASK, 0x01
.set UART_rx__0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set UART_rx__0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set UART_rx__0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set UART_rx__0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set UART_rx__0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set UART_rx__0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set UART_rx__0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set UART_rx__0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set UART_rx__0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set UART_rx__0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set UART_rx__0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set UART_rx__0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set UART_rx__0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set UART_rx__0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set UART_rx__0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set UART_rx__0__PC, CYREG_PRT3_PC
.set UART_rx__0__PC2, CYREG_PRT3_PC2
.set UART_rx__0__PORT, 3
.set UART_rx__0__PS, CYREG_PRT3_PS
.set UART_rx__0__SHIFT, 0
.set UART_rx__DR, CYREG_PRT3_DR
.set UART_rx__INTCFG, CYREG_PRT3_INTCFG
.set UART_rx__INTSTAT, CYREG_PRT3_INTSTAT
.set UART_rx__MASK, 0x01
.set UART_rx__PA__CFG0, CYREG_UDB_PA3_CFG0
.set UART_rx__PA__CFG1, CYREG_UDB_PA3_CFG1
.set UART_rx__PA__CFG10, CYREG_UDB_PA3_CFG10
.set UART_rx__PA__CFG11, CYREG_UDB_PA3_CFG11
.set UART_rx__PA__CFG12, CYREG_UDB_PA3_CFG12
.set UART_rx__PA__CFG13, CYREG_UDB_PA3_CFG13
.set UART_rx__PA__CFG14, CYREG_UDB_PA3_CFG14
.set UART_rx__PA__CFG2, CYREG_UDB_PA3_CFG2
.set UART_rx__PA__CFG3, CYREG_UDB_PA3_CFG3
.set UART_rx__PA__CFG4, CYREG_UDB_PA3_CFG4
.set UART_rx__PA__CFG5, CYREG_UDB_PA3_CFG5
.set UART_rx__PA__CFG6, CYREG_UDB_PA3_CFG6
.set UART_rx__PA__CFG7, CYREG_UDB_PA3_CFG7
.set UART_rx__PA__CFG8, CYREG_UDB_PA3_CFG8
.set UART_rx__PA__CFG9, CYREG_UDB_PA3_CFG9
.set UART_rx__PC, CYREG_PRT3_PC
.set UART_rx__PC2, CYREG_PRT3_PC2
.set UART_rx__PORT, 3
.set UART_rx__PS, CYREG_PRT3_PS
.set UART_rx__SHIFT, 0
.set UART_SCB__BIST_CONTROL, CYREG_SCB1_BIST_CONTROL
.set UART_SCB__BIST_DATA, CYREG_SCB1_BIST_DATA
.set UART_SCB__CTRL, CYREG_SCB1_CTRL
.set UART_SCB__EZ_DATA00, CYREG_SCB1_EZ_DATA00
.set UART_SCB__EZ_DATA01, CYREG_SCB1_EZ_DATA01
.set UART_SCB__EZ_DATA02, CYREG_SCB1_EZ_DATA02
.set UART_SCB__EZ_DATA03, CYREG_SCB1_EZ_DATA03
.set UART_SCB__EZ_DATA04, CYREG_SCB1_EZ_DATA04
.set UART_SCB__EZ_DATA05, CYREG_SCB1_EZ_DATA05
.set UART_SCB__EZ_DATA06, CYREG_SCB1_EZ_DATA06
.set UART_SCB__EZ_DATA07, CYREG_SCB1_EZ_DATA07
.set UART_SCB__EZ_DATA08, CYREG_SCB1_EZ_DATA08
.set UART_SCB__EZ_DATA09, CYREG_SCB1_EZ_DATA09
.set UART_SCB__EZ_DATA10, CYREG_SCB1_EZ_DATA10
.set UART_SCB__EZ_DATA11, CYREG_SCB1_EZ_DATA11
.set UART_SCB__EZ_DATA12, CYREG_SCB1_EZ_DATA12
.set UART_SCB__EZ_DATA13, CYREG_SCB1_EZ_DATA13
.set UART_SCB__EZ_DATA14, CYREG_SCB1_EZ_DATA14
.set UART_SCB__EZ_DATA15, CYREG_SCB1_EZ_DATA15
.set UART_SCB__EZ_DATA16, CYREG_SCB1_EZ_DATA16
.set UART_SCB__EZ_DATA17, CYREG_SCB1_EZ_DATA17
.set UART_SCB__EZ_DATA18, CYREG_SCB1_EZ_DATA18
.set UART_SCB__EZ_DATA19, CYREG_SCB1_EZ_DATA19
.set UART_SCB__EZ_DATA20, CYREG_SCB1_EZ_DATA20
.set UART_SCB__EZ_DATA21, CYREG_SCB1_EZ_DATA21
.set UART_SCB__EZ_DATA22, CYREG_SCB1_EZ_DATA22
.set UART_SCB__EZ_DATA23, CYREG_SCB1_EZ_DATA23
.set UART_SCB__EZ_DATA24, CYREG_SCB1_EZ_DATA24
.set UART_SCB__EZ_DATA25, CYREG_SCB1_EZ_DATA25
.set UART_SCB__EZ_DATA26, CYREG_SCB1_EZ_DATA26
.set UART_SCB__EZ_DATA27, CYREG_SCB1_EZ_DATA27
.set UART_SCB__EZ_DATA28, CYREG_SCB1_EZ_DATA28
.set UART_SCB__EZ_DATA29, CYREG_SCB1_EZ_DATA29
.set UART_SCB__EZ_DATA30, CYREG_SCB1_EZ_DATA30
.set UART_SCB__EZ_DATA31, CYREG_SCB1_EZ_DATA31
.set UART_SCB__I2C_CFG, CYREG_SCB1_I2C_CFG
.set UART_SCB__I2C_CTRL, CYREG_SCB1_I2C_CTRL
.set UART_SCB__I2C_M_CMD, CYREG_SCB1_I2C_M_CMD
.set UART_SCB__I2C_S_CMD, CYREG_SCB1_I2C_S_CMD
.set UART_SCB__I2C_STATUS, CYREG_SCB1_I2C_STATUS
.set UART_SCB__INTR_CAUSE, CYREG_SCB1_INTR_CAUSE
.set UART_SCB__INTR_I2C_EC, CYREG_SCB1_INTR_I2C_EC
.set UART_SCB__INTR_I2C_EC_MASK, CYREG_SCB1_INTR_I2C_EC_MASK
.set UART_SCB__INTR_I2C_EC_MASKED, CYREG_SCB1_INTR_I2C_EC_MASKED
.set UART_SCB__INTR_M, CYREG_SCB1_INTR_M
.set UART_SCB__INTR_M_MASK, CYREG_SCB1_INTR_M_MASK
.set UART_SCB__INTR_M_MASKED, CYREG_SCB1_INTR_M_MASKED
.set UART_SCB__INTR_M_SET, CYREG_SCB1_INTR_M_SET
.set UART_SCB__INTR_RX, CYREG_SCB1_INTR_RX
.set UART_SCB__INTR_RX_MASK, CYREG_SCB1_INTR_RX_MASK
.set UART_SCB__INTR_RX_MASKED, CYREG_SCB1_INTR_RX_MASKED
.set UART_SCB__INTR_RX_SET, CYREG_SCB1_INTR_RX_SET
.set UART_SCB__INTR_S, CYREG_SCB1_INTR_S
.set UART_SCB__INTR_S_MASK, CYREG_SCB1_INTR_S_MASK
.set UART_SCB__INTR_S_MASKED, CYREG_SCB1_INTR_S_MASKED
.set UART_SCB__INTR_S_SET, CYREG_SCB1_INTR_S_SET
.set UART_SCB__INTR_SPI_EC, CYREG_SCB1_INTR_SPI_EC
.set UART_SCB__INTR_SPI_EC_MASK, CYREG_SCB1_INTR_SPI_EC_MASK
.set UART_SCB__INTR_SPI_EC_MASKED, CYREG_SCB1_INTR_SPI_EC_MASKED
.set UART_SCB__INTR_TX, CYREG_SCB1_INTR_TX
.set UART_SCB__INTR_TX_MASK, CYREG_SCB1_INTR_TX_MASK
.set UART_SCB__INTR_TX_MASKED, CYREG_SCB1_INTR_TX_MASKED
.set UART_SCB__INTR_TX_SET, CYREG_SCB1_INTR_TX_SET
.set UART_SCB__RX_CTRL, CYREG_SCB1_RX_CTRL
.set UART_SCB__RX_FIFO_CTRL, CYREG_SCB1_RX_FIFO_CTRL
.set UART_SCB__RX_FIFO_RD, CYREG_SCB1_RX_FIFO_RD
.set UART_SCB__RX_FIFO_RD_SILENT, CYREG_SCB1_RX_FIFO_RD_SILENT
.set UART_SCB__RX_FIFO_STATUS, CYREG_SCB1_RX_FIFO_STATUS
.set UART_SCB__RX_MATCH, CYREG_SCB1_RX_MATCH
.set UART_SCB__SPI_CTRL, CYREG_SCB1_SPI_CTRL
.set UART_SCB__SPI_STATUS, CYREG_SCB1_SPI_STATUS
.set UART_SCB__SS0_POSISTION, 0
.set UART_SCB__SS1_POSISTION, 1
.set UART_SCB__SS2_POSISTION, 2
.set UART_SCB__SS3_POSISTION, 3
.set UART_SCB__STATUS, CYREG_SCB1_STATUS
.set UART_SCB__TX_CTRL, CYREG_SCB1_TX_CTRL
.set UART_SCB__TX_FIFO_CTRL, CYREG_SCB1_TX_FIFO_CTRL
.set UART_SCB__TX_FIFO_STATUS, CYREG_SCB1_TX_FIFO_STATUS
.set UART_SCB__TX_FIFO_WR, CYREG_SCB1_TX_FIFO_WR
.set UART_SCB__UART_CTRL, CYREG_SCB1_UART_CTRL
.set UART_SCB__UART_RX_CTRL, CYREG_SCB1_UART_RX_CTRL
.set UART_SCB__UART_RX_STATUS, CYREG_SCB1_UART_RX_STATUS
.set UART_SCB__UART_TX_CTRL, CYREG_SCB1_UART_TX_CTRL
.set UART_SCB_IRQ__INTC_CLR_EN_REG, CYREG_CM0_ICER
.set UART_SCB_IRQ__INTC_CLR_PD_REG, CYREG_CM0_ICPR
.set UART_SCB_IRQ__INTC_MASK, 0x800
.set UART_SCB_IRQ__INTC_NUMBER, 11
.set UART_SCB_IRQ__INTC_PRIOR_MASK, 0xC0000000
.set UART_SCB_IRQ__INTC_PRIOR_NUM, 3
.set UART_SCB_IRQ__INTC_PRIOR_REG, CYREG_CM0_IPR2
.set UART_SCB_IRQ__INTC_SET_EN_REG, CYREG_CM0_ISER
.set UART_SCB_IRQ__INTC_SET_PD_REG, CYREG_CM0_ISPR
.set UART_SCBCLK__DIVIDER_MASK, 0x0000FFFF
.set UART_SCBCLK__ENABLE, CYREG_CLK_DIVIDER_A00
.set UART_SCBCLK__ENABLE_MASK, 0x80000000
.set UART_SCBCLK__MASK, 0x80000000
.set UART_SCBCLK__REGISTER, CYREG_CLK_DIVIDER_A00
.set UART_tx__0__DM__MASK, 0x38
.set UART_tx__0__DM__SHIFT, 3
.set UART_tx__0__DR, CYREG_PRT3_DR
.set UART_tx__0__HSIOM, CYREG_HSIOM_PORT_SEL3
.set UART_tx__0__HSIOM_GPIO, 0
.set UART_tx__0__HSIOM_I2C, 14
.set UART_tx__0__HSIOM_I2C_SDA, 14
.set UART_tx__0__HSIOM_MASK, 0x000000F0
.set UART_tx__0__HSIOM_SHIFT, 4
.set UART_tx__0__HSIOM_SPI, 15
.set UART_tx__0__HSIOM_SPI_MISO, 15
.set UART_tx__0__HSIOM_UART, 9
.set UART_tx__0__HSIOM_UART_TX, 9
.set UART_tx__0__INTCFG, CYREG_PRT3_INTCFG
.set UART_tx__0__INTSTAT, CYREG_PRT3_INTSTAT
.set UART_tx__0__MASK, 0x02
.set UART_tx__0__OUT_SEL, CYREG_UDB_PA3_CFG10
.set UART_tx__0__OUT_SEL_SHIFT, 2
.set UART_tx__0__OUT_SEL_VAL, -1
.set UART_tx__0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set UART_tx__0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set UART_tx__0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set UART_tx__0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set UART_tx__0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set UART_tx__0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set UART_tx__0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set UART_tx__0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set UART_tx__0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set UART_tx__0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set UART_tx__0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set UART_tx__0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set UART_tx__0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set UART_tx__0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set UART_tx__0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set UART_tx__0__PC, CYREG_PRT3_PC
.set UART_tx__0__PC2, CYREG_PRT3_PC2
.set UART_tx__0__PORT, 3
.set UART_tx__0__PS, CYREG_PRT3_PS
.set UART_tx__0__SHIFT, 1
.set UART_tx__DR, CYREG_PRT3_DR
.set UART_tx__INTCFG, CYREG_PRT3_INTCFG
.set UART_tx__INTSTAT, CYREG_PRT3_INTSTAT
.set UART_tx__MASK, 0x02
.set UART_tx__PA__CFG0, CYREG_UDB_PA3_CFG0
.set UART_tx__PA__CFG1, CYREG_UDB_PA3_CFG1
.set UART_tx__PA__CFG10, CYREG_UDB_PA3_CFG10
.set UART_tx__PA__CFG11, CYREG_UDB_PA3_CFG11
.set UART_tx__PA__CFG12, CYREG_UDB_PA3_CFG12
.set UART_tx__PA__CFG13, CYREG_UDB_PA3_CFG13
.set UART_tx__PA__CFG14, CYREG_UDB_PA3_CFG14
.set UART_tx__PA__CFG2, CYREG_UDB_PA3_CFG2
.set UART_tx__PA__CFG3, CYREG_UDB_PA3_CFG3
.set UART_tx__PA__CFG4, CYREG_UDB_PA3_CFG4
.set UART_tx__PA__CFG5, CYREG_UDB_PA3_CFG5
.set UART_tx__PA__CFG6, CYREG_UDB_PA3_CFG6
.set UART_tx__PA__CFG7, CYREG_UDB_PA3_CFG7
.set UART_tx__PA__CFG8, CYREG_UDB_PA3_CFG8
.set UART_tx__PA__CFG9, CYREG_UDB_PA3_CFG9
.set UART_tx__PC, CYREG_PRT3_PC
.set UART_tx__PC2, CYREG_PRT3_PC2
.set UART_tx__PORT, 3
.set UART_tx__PS, CYREG_PRT3_PS
.set UART_tx__SHIFT, 1

/* Clock */
.set Clock__DIVIDER_MASK, 0x0000FFFF
.set Clock__ENABLE, CYREG_CLK_DIVIDER_C00
.set Clock__ENABLE_MASK, 0x80000000
.set Clock__MASK, 0x80000000
.set Clock__REGISTER, CYREG_CLK_DIVIDER_C00

/* Pin_LED */
.set Pin_LED__0__DM__MASK, 0x1C0000
.set Pin_LED__0__DM__SHIFT, 18
.set Pin_LED__0__DR, CYREG_PRT1_DR
.set Pin_LED__0__HSIOM, CYREG_HSIOM_PORT_SEL1
.set Pin_LED__0__HSIOM_MASK, 0x0F000000
.set Pin_LED__0__HSIOM_SHIFT, 24
.set Pin_LED__0__INTCFG, CYREG_PRT1_INTCFG
.set Pin_LED__0__INTSTAT, CYREG_PRT1_INTSTAT
.set Pin_LED__0__MASK, 0x40
.set Pin_LED__0__OUT_SEL, CYREG_UDB_PA1_CFG10
.set Pin_LED__0__OUT_SEL_SHIFT, 12
.set Pin_LED__0__OUT_SEL_VAL, 2
.set Pin_LED__0__PA__CFG0, CYREG_UDB_PA1_CFG0
.set Pin_LED__0__PA__CFG1, CYREG_UDB_PA1_CFG1
.set Pin_LED__0__PA__CFG10, CYREG_UDB_PA1_CFG10
.set Pin_LED__0__PA__CFG11, CYREG_UDB_PA1_CFG11
.set Pin_LED__0__PA__CFG12, CYREG_UDB_PA1_CFG12
.set Pin_LED__0__PA__CFG13, CYREG_UDB_PA1_CFG13
.set Pin_LED__0__PA__CFG14, CYREG_UDB_PA1_CFG14
.set Pin_LED__0__PA__CFG2, CYREG_UDB_PA1_CFG2
.set Pin_LED__0__PA__CFG3, CYREG_UDB_PA1_CFG3
.set Pin_LED__0__PA__CFG4, CYREG_UDB_PA1_CFG4
.set Pin_LED__0__PA__CFG5, CYREG_UDB_PA1_CFG5
.set Pin_LED__0__PA__CFG6, CYREG_UDB_PA1_CFG6
.set Pin_LED__0__PA__CFG7, CYREG_UDB_PA1_CFG7
.set Pin_LED__0__PA__CFG8, CYREG_UDB_PA1_CFG8
.set Pin_LED__0__PA__CFG9, CYREG_UDB_PA1_CFG9
.set Pin_LED__0__PC, CYREG_PRT1_PC
.set Pin_LED__0__PC2, CYREG_PRT1_PC2
.set Pin_LED__0__PORT, 1
.set Pin_LED__0__PS, CYREG_PRT1_PS
.set Pin_LED__0__SHIFT, 6
.set Pin_LED__DR, CYREG_PRT1_DR
.set Pin_LED__INTCFG, CYREG_PRT1_INTCFG
.set Pin_LED__INTSTAT, CYREG_PRT1_INTSTAT
.set Pin_LED__MASK, 0x40
.set Pin_LED__PA__CFG0, CYREG_UDB_PA1_CFG0
.set Pin_LED__PA__CFG1, CYREG_UDB_PA1_CFG1
.set Pin_LED__PA__CFG10, CYREG_UDB_PA1_CFG10
.set Pin_LED__PA__CFG11, CYREG_UDB_PA1_CFG11
.set Pin_LED__PA__CFG12, CYREG_UDB_PA1_CFG12
.set Pin_LED__PA__CFG13, CYREG_UDB_PA1_CFG13
.set Pin_LED__PA__CFG14, CYREG_UDB_PA1_CFG14
.set Pin_LED__PA__CFG2, CYREG_UDB_PA1_CFG2
.set Pin_LED__PA__CFG3, CYREG_UDB_PA1_CFG3
.set Pin_LED__PA__CFG4, CYREG_UDB_PA1_CFG4
.set Pin_LED__PA__CFG5, CYREG_UDB_PA1_CFG5
.set Pin_LED__PA__CFG6, CYREG_UDB_PA1_CFG6
.set Pin_LED__PA__CFG7, CYREG_UDB_PA1_CFG7
.set Pin_LED__PA__CFG8, CYREG_UDB_PA1_CFG8
.set Pin_LED__PA__CFG9, CYREG_UDB_PA1_CFG9
.set Pin_LED__PC, CYREG_PRT1_PC
.set Pin_LED__PC2, CYREG_PRT1_PC2
.set Pin_LED__PORT, 1
.set Pin_LED__PS, CYREG_PRT1_PS
.set Pin_LED__SHIFT, 6

/* Miscellaneous */
.set CYDEV_BCLK__HFCLK__HZ, 24000000
.set CYDEV_BCLK__HFCLK__KHZ, 24000
.set CYDEV_BCLK__HFCLK__MHZ, 24
.set CYDEV_BCLK__SYSCLK__HZ, 24000000
.set CYDEV_BCLK__SYSCLK__KHZ, 24000
.set CYDEV_BCLK__SYSCLK__MHZ, 24
.set CYDEV_BOOTLOADER_APPLICATIONS, 1
.set CYDEV_BOOTLOADER_CHECKSUM_BASIC, 0
.set CYDEV_BOOTLOADER_CHECKSUM_CRC, 1
.set CYDEV_BOOTLOADER_IO_COMP_CUSTOM_IO, 0
.set CyBtldr_Custom_Interface, CYDEV_BOOTLOADER_IO_COMP_CUSTOM_IO
.set CYDEV_BOOTLOADER_IO_COMP_LAUNCHER_ONLY, 1
.set CyBtldr_LAUNCHER_ONLY, CYDEV_BOOTLOADER_IO_COMP_LAUNCHER_ONLY
.set CYDEV_BOOTLOADER_IO_COMP_UART, 2
.set CyBtldr_UART, CYDEV_BOOTLOADER_IO_COMP_UART
.set CYDEV_BOOTLOADER_IO_COMP, CYDEV_BOOTLOADER_IO_COMP_UART
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PSOC4A, 21
.set CYDEV_CHIP_DIE_PSOC5LP, 2
.set CYDEV_CHIP_DIE_PSOC5TM, 3
.set CYDEV_CHIP_DIE_TMA4, 4
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_FM0P, 5
.set CYDEV_CHIP_FAMILY_FM3, 6
.set CYDEV_CHIP_FAMILY_FM4, 7
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_PSOC6, 4
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC4
.set CYDEV_CHIP_JTAG_ID, 0x04C81193
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 21
.set CYDEV_CHIP_MEMBER_4D, 16
.set CYDEV_CHIP_MEMBER_4E, 6
.set CYDEV_CHIP_MEMBER_4F, 22
.set CYDEV_CHIP_MEMBER_4G, 4
.set CYDEV_CHIP_MEMBER_4H, 20
.set CYDEV_CHIP_MEMBER_4I, 26
.set CYDEV_CHIP_MEMBER_4J, 17
.set CYDEV_CHIP_MEMBER_4K, 18
.set CYDEV_CHIP_MEMBER_4L, 25
.set CYDEV_CHIP_MEMBER_4M, 24
.set CYDEV_CHIP_MEMBER_4N, 11
.set CYDEV_CHIP_MEMBER_4O, 8
.set CYDEV_CHIP_MEMBER_4P, 23
.set CYDEV_CHIP_MEMBER_4Q, 14
.set CYDEV_CHIP_MEMBER_4R, 9
.set CYDEV_CHIP_MEMBER_4S, 12
.set CYDEV_CHIP_MEMBER_4T, 10
.set CYDEV_CHIP_MEMBER_4U, 5
.set CYDEV_CHIP_MEMBER_4V, 19
.set CYDEV_CHIP_MEMBER_4W, 13
.set CYDEV_CHIP_MEMBER_4X, 7
.set CYDEV_CHIP_MEMBER_4Y, 15
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_5B, 2
.set CYDEV_CHIP_MEMBER_6A, 27
.set CYDEV_CHIP_MEMBER_FM3, 31
.set CYDEV_CHIP_MEMBER_FM4, 32
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1, 28
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2, 29
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3, 30
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_4A
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES0, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES1, 1
.set CYDEV_CHIP_REV_PSOC5TM_PRODUCTION, 1
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4P_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Q_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4R_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4S_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4T_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4V_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4W_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4X_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Y_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_6A_ES, 17
.set CYDEV_CHIP_REVISION_6A_NO_UDB, 33
.set CYDEV_CHIP_REVISION_6A_PRODUCTION, 33
.set CYDEV_CHIP_REVISION_FM3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM4_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_4A_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_READ_ACCELERATOR, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_PROTECT_KILL, 4
.set CYDEV_DEBUG_PROTECT_OPEN, 1
.set CYDEV_DEBUG_PROTECT, CYDEV_DEBUG_PROTECT_OPEN
.set CYDEV_DEBUG_PROTECT_PROTECTED, 2
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DFT_SELECT_CLK0, 1
.set CYDEV_DFT_SELECT_CLK1, 2
.set CYDEV_HEAP_SIZE, 0x0100
.set CYDEV_IMO_TRIMMED_BY_USB, 0
.set CYDEV_IMO_TRIMMED_BY_WCO, 0
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 1
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_STACK_SIZE, 0x0400
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 1
.set CYDEV_VDDA_MV, 3300
.set CYDEV_VDDD_MV, 3300
.set CYDEV_WDT_GENERATE_ISR, 0
.set CYIPBLOCK_M0S8_CTBM_VERSION, 0
.set CYIPBLOCK_m0s8cpuss_VERSION, 0
.set CYIPBLOCK_m0s8csd_VERSION, 0
.set CYIPBLOCK_m0s8gpio2_VERSION, 0
.set CYIPBLOCK_m0s8hsiom4a_VERSION, 0
.set CYIPBLOCK_m0s8lcd_VERSION, 0
.set CYIPBLOCK_m0s8lpcomp_VERSION, 0
.set CYIPBLOCK_m0s8pclk_VERSION, 0
.set CYIPBLOCK_m0s8sar_VERSION, 0
.set CYIPBLOCK_m0s8scb_VERSION, 0
.set CYIPBLOCK_m0s8srssv2_VERSION, 1
.set CYIPBLOCK_m0s8tcpwm_VERSION, 0
.set CYIPBLOCK_m0s8udbif_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 2
.set CYDEV_BOOTLOADER_ENABLE, 1
.endif