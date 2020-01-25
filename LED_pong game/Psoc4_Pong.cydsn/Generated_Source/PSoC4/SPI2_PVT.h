/***************************************************************************//**
* \file .h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_SPI2_H)
#define CY_SCB_PVT_SPI2_H

#include "SPI2.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define SPI2_SetI2CExtClkInterruptMode(interruptMask) SPI2_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define SPI2_ClearI2CExtClkInterruptSource(interruptMask) SPI2_CLEAR_INTR_I2C_EC(interruptMask)
#define SPI2_GetI2CExtClkInterruptSource()                (SPI2_INTR_I2C_EC_REG)
#define SPI2_GetI2CExtClkInterruptMode()                  (SPI2_INTR_I2C_EC_MASK_REG)
#define SPI2_GetI2CExtClkInterruptSourceMasked()          (SPI2_INTR_I2C_EC_MASKED_REG)

#if (!SPI2_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define SPI2_SetSpiExtClkInterruptMode(interruptMask) \
                                                                SPI2_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define SPI2_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                SPI2_CLEAR_INTR_SPI_EC(interruptMask)
    #define SPI2_GetExtSpiClkInterruptSource()                 (SPI2_INTR_SPI_EC_REG)
    #define SPI2_GetExtSpiClkInterruptMode()                   (SPI2_INTR_SPI_EC_MASK_REG)
    #define SPI2_GetExtSpiClkInterruptSourceMasked()           (SPI2_INTR_SPI_EC_MASKED_REG)
#endif /* (!SPI2_CY_SCBIP_V1) */

#if(SPI2_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void SPI2_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (SPI2_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (SPI2_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_SPI2_CUSTOM_INTR_HANDLER)
    extern cyisraddress SPI2_customIntrHandler;
#endif /* !defined (CY_REMOVE_SPI2_CUSTOM_INTR_HANDLER) */
#endif /* (SPI2_SCB_IRQ_INTERNAL) */

extern SPI2_BACKUP_STRUCT SPI2_backup;

#if(SPI2_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 SPI2_scbMode;
    extern uint8 SPI2_scbEnableWake;
    extern uint8 SPI2_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 SPI2_mode;
    extern uint8 SPI2_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * SPI2_rxBuffer;
    extern uint8   SPI2_rxDataBits;
    extern uint32  SPI2_rxBufferSize;

    extern volatile uint8 * SPI2_txBuffer;
    extern uint8   SPI2_txDataBits;
    extern uint32  SPI2_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 SPI2_numberOfAddr;
    extern uint8 SPI2_subAddrSize;
#endif /* (SPI2_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (SPI2_SCB_MODE_I2C_CONST_CFG || \
        SPI2_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 SPI2_IntrTxMask;
#endif /* (! (SPI2_SCB_MODE_I2C_CONST_CFG || \
              SPI2_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(SPI2_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define SPI2_SCB_MODE_I2C_RUNTM_CFG     (SPI2_SCB_MODE_I2C      == SPI2_scbMode)
    #define SPI2_SCB_MODE_SPI_RUNTM_CFG     (SPI2_SCB_MODE_SPI      == SPI2_scbMode)
    #define SPI2_SCB_MODE_UART_RUNTM_CFG    (SPI2_SCB_MODE_UART     == SPI2_scbMode)
    #define SPI2_SCB_MODE_EZI2C_RUNTM_CFG   (SPI2_SCB_MODE_EZI2C    == SPI2_scbMode)
    #define SPI2_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (SPI2_SCB_MODE_UNCONFIG == SPI2_scbMode)

    /* Defines wakeup enable */
    #define SPI2_SCB_WAKE_ENABLE_CHECK       (0u != SPI2_scbEnableWake)
#endif /* (SPI2_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!SPI2_CY_SCBIP_V1)
    #define SPI2_SCB_PINS_NUMBER    (7u)
#else
    #define SPI2_SCB_PINS_NUMBER    (2u)
#endif /* (!SPI2_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_SPI2_H) */


/* [] END OF FILE */
