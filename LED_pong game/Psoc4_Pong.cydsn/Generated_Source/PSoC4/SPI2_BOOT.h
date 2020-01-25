/***************************************************************************//**
* \file SPI2_BOOT.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_SPI2_H)
#define CY_SCB_BOOT_SPI2_H

#include "SPI2_PVT.h"

#if (SPI2_SCB_MODE_I2C_INC)
    #include "SPI2_I2C.h"
#endif /* (SPI2_SCB_MODE_I2C_INC) */

#if (SPI2_SCB_MODE_EZI2C_INC)
    #include "SPI2_EZI2C.h"
#endif /* (SPI2_SCB_MODE_EZI2C_INC) */

#if (SPI2_SCB_MODE_SPI_INC || SPI2_SCB_MODE_UART_INC)
    #include "SPI2_SPI_UART.h"
#endif /* (SPI2_SCB_MODE_SPI_INC || SPI2_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define SPI2_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPI2) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (SPI2_SCB_MODE_I2C_INC)
    #define SPI2_I2C_BTLDR_COMM_ENABLED     (SPI2_BTLDR_COMM_ENABLED && \
                                                            (SPI2_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             SPI2_I2C_SLAVE_CONST))
#else
     #define SPI2_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (SPI2_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (SPI2_SCB_MODE_EZI2C_INC)
    #define SPI2_EZI2C_BTLDR_COMM_ENABLED   (SPI2_BTLDR_COMM_ENABLED && \
                                                         SPI2_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define SPI2_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (SPI2_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (SPI2_SCB_MODE_SPI_INC)
    #define SPI2_SPI_BTLDR_COMM_ENABLED     (SPI2_BTLDR_COMM_ENABLED && \
                                                            (SPI2_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             SPI2_SPI_SLAVE_CONST))
#else
        #define SPI2_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (SPI2_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (SPI2_SCB_MODE_UART_INC)
       #define SPI2_UART_BTLDR_COMM_ENABLED    (SPI2_BTLDR_COMM_ENABLED && \
                                                            (SPI2_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (SPI2_UART_RX_DIRECTION && \
                                                              SPI2_UART_TX_DIRECTION)))
#else
     #define SPI2_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (SPI2_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define SPI2_BTLDR_COMM_MODE_ENABLED    (SPI2_I2C_BTLDR_COMM_ENABLED   || \
                                                     SPI2_SPI_BTLDR_COMM_ENABLED   || \
                                                     SPI2_EZI2C_BTLDR_COMM_ENABLED || \
                                                     SPI2_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI2_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void SPI2_I2CCyBtldrCommStart(void);
    void SPI2_I2CCyBtldrCommStop (void);
    void SPI2_I2CCyBtldrCommReset(void);
    cystatus SPI2_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI2_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (SPI2_SCB_MODE_I2C_CONST_CFG)
        #define SPI2_CyBtldrCommStart   SPI2_I2CCyBtldrCommStart
        #define SPI2_CyBtldrCommStop    SPI2_I2CCyBtldrCommStop
        #define SPI2_CyBtldrCommReset   SPI2_I2CCyBtldrCommReset
        #define SPI2_CyBtldrCommRead    SPI2_I2CCyBtldrCommRead
        #define SPI2_CyBtldrCommWrite   SPI2_I2CCyBtldrCommWrite
    #endif /* (SPI2_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI2_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI2_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void SPI2_EzI2CCyBtldrCommStart(void);
    void SPI2_EzI2CCyBtldrCommStop (void);
    void SPI2_EzI2CCyBtldrCommReset(void);
    cystatus SPI2_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI2_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (SPI2_SCB_MODE_EZI2C_CONST_CFG)
        #define SPI2_CyBtldrCommStart   SPI2_EzI2CCyBtldrCommStart
        #define SPI2_CyBtldrCommStop    SPI2_EzI2CCyBtldrCommStop
        #define SPI2_CyBtldrCommReset   SPI2_EzI2CCyBtldrCommReset
        #define SPI2_CyBtldrCommRead    SPI2_EzI2CCyBtldrCommRead
        #define SPI2_CyBtldrCommWrite   SPI2_EzI2CCyBtldrCommWrite
    #endif /* (SPI2_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI2_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI2_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void SPI2_SpiCyBtldrCommStart(void);
    void SPI2_SpiCyBtldrCommStop (void);
    void SPI2_SpiCyBtldrCommReset(void);
    cystatus SPI2_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI2_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (SPI2_SCB_MODE_SPI_CONST_CFG)
        #define SPI2_CyBtldrCommStart   SPI2_SpiCyBtldrCommStart
        #define SPI2_CyBtldrCommStop    SPI2_SpiCyBtldrCommStop
        #define SPI2_CyBtldrCommReset   SPI2_SpiCyBtldrCommReset
        #define SPI2_CyBtldrCommRead    SPI2_SpiCyBtldrCommRead
        #define SPI2_CyBtldrCommWrite   SPI2_SpiCyBtldrCommWrite
    #endif /* (SPI2_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI2_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI2_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void SPI2_UartCyBtldrCommStart(void);
    void SPI2_UartCyBtldrCommStop (void);
    void SPI2_UartCyBtldrCommReset(void);
    cystatus SPI2_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI2_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (SPI2_SCB_MODE_UART_CONST_CFG)
        #define SPI2_CyBtldrCommStart   SPI2_UartCyBtldrCommStart
        #define SPI2_CyBtldrCommStop    SPI2_UartCyBtldrCommStop
        #define SPI2_CyBtldrCommReset   SPI2_UartCyBtldrCommReset
        #define SPI2_CyBtldrCommRead    SPI2_UartCyBtldrCommRead
        #define SPI2_CyBtldrCommWrite   SPI2_UartCyBtldrCommWrite
    #endif /* (SPI2_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI2_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI2_BTLDR_COMM_ENABLED)
    #if (SPI2_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void SPI2_CyBtldrCommStart(void);
        void SPI2_CyBtldrCommStop (void);
        void SPI2_CyBtldrCommReset(void);
        cystatus SPI2_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus SPI2_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (SPI2_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPI2)
        #define CyBtldrCommStart    SPI2_CyBtldrCommStart
        #define CyBtldrCommStop     SPI2_CyBtldrCommStop
        #define CyBtldrCommReset    SPI2_CyBtldrCommReset
        #define CyBtldrCommWrite    SPI2_CyBtldrCommWrite
        #define CyBtldrCommRead     SPI2_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPI2) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI2_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define SPI2_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define SPI2_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define SPI2_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define SPI2_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef SPI2_SPI_BYTE_TO_BYTE
    #define SPI2_SPI_BYTE_TO_BYTE   (256u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef SPI2_UART_BYTE_TO_BYTE
    #define SPI2_UART_BYTE_TO_BYTE  (2500u)
#endif /* SPI2_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_SPI2_H) */


/* [] END OF FILE */
