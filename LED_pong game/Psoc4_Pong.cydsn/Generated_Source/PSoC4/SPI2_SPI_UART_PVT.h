/***************************************************************************//**
* \file SPI2_SPI_UART_PVT.h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
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

#if !defined(CY_SCB_SPI_UART_PVT_SPI2_H)
#define CY_SCB_SPI_UART_PVT_SPI2_H

#include "SPI2_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (SPI2_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  SPI2_rxBufferHead;
    extern volatile uint32  SPI2_rxBufferTail;
    
    /**
    * \addtogroup group_globals
    * @{
    */
    
    /** Sets when internal software receive buffer overflow
     *  was occurred.
    */  
    extern volatile uint8   SPI2_rxBufferOverflow;
    /** @} globals */
#endif /* (SPI2_INTERNAL_RX_SW_BUFFER_CONST) */

#if (SPI2_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  SPI2_txBufferHead;
    extern volatile uint32  SPI2_txBufferTail;
#endif /* (SPI2_INTERNAL_TX_SW_BUFFER_CONST) */

#if (SPI2_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 SPI2_rxBufferInternal[SPI2_INTERNAL_RX_BUFFER_SIZE];
#endif /* (SPI2_INTERNAL_RX_SW_BUFFER) */

#if (SPI2_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 SPI2_txBufferInternal[SPI2_TX_BUFFER_SIZE];
#endif /* (SPI2_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void SPI2_SpiPostEnable(void);
void SPI2_SpiStop(void);

#if (SPI2_SCB_MODE_SPI_CONST_CFG)
    void SPI2_SpiInit(void);
#endif /* (SPI2_SCB_MODE_SPI_CONST_CFG) */

#if (SPI2_SPI_WAKE_ENABLE_CONST)
    void SPI2_SpiSaveConfig(void);
    void SPI2_SpiRestoreConfig(void);
#endif /* (SPI2_SPI_WAKE_ENABLE_CONST) */

void SPI2_UartPostEnable(void);
void SPI2_UartStop(void);

#if (SPI2_SCB_MODE_UART_CONST_CFG)
    void SPI2_UartInit(void);
#endif /* (SPI2_SCB_MODE_UART_CONST_CFG) */

#if (SPI2_UART_WAKE_ENABLE_CONST)
    void SPI2_UartSaveConfig(void);
    void SPI2_UartRestoreConfig(void);
#endif /* (SPI2_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in SPI2_SetPins() */
#define SPI2_UART_RX_PIN_ENABLE    (SPI2_UART_RX)
#define SPI2_UART_TX_PIN_ENABLE    (SPI2_UART_TX)

/* UART RTS and CTS position to be used in  SPI2_SetPins() */
#define SPI2_UART_RTS_PIN_ENABLE    (0x10u)
#define SPI2_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define SPI2_SpiUartEnableIntRx(intSourceMask)  SPI2_SetRxInterruptMode(intSourceMask)
#define SPI2_SpiUartEnableIntTx(intSourceMask)  SPI2_SetTxInterruptMode(intSourceMask)
uint32  SPI2_SpiUartDisableIntRx(void);
uint32  SPI2_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_SPI2_H) */


/* [] END OF FILE */
