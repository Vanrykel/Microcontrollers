/***************************************************************************//**
* \file SPI2_SPI_UART_INT.c
* \version 4.0
*
* \brief
*  This file provides the source code to the Interrupt Service Routine for
*  the SCB Component in SPI and UART modes.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI2_PVT.h"
#include "SPI2_SPI_UART_PVT.h"
#include "cyapicallbacks.h"

#if (SPI2_SCB_IRQ_INTERNAL)
/*******************************************************************************
* Function Name: SPI2_SPI_UART_ISR
****************************************************************************//**
*
*  Handles the Interrupt Service Routine for the SCB SPI or UART modes.
*
*******************************************************************************/
CY_ISR(SPI2_SPI_UART_ISR)
{
#if (SPI2_INTERNAL_RX_SW_BUFFER_CONST)
    uint32 locHead;
#endif /* (SPI2_INTERNAL_RX_SW_BUFFER_CONST) */

#if (SPI2_INTERNAL_TX_SW_BUFFER_CONST)
    uint32 locTail;
#endif /* (SPI2_INTERNAL_TX_SW_BUFFER_CONST) */

#ifdef SPI2_SPI_UART_ISR_ENTRY_CALLBACK
    SPI2_SPI_UART_ISR_EntryCallback();
#endif /* SPI2_SPI_UART_ISR_ENTRY_CALLBACK */

    if (NULL != SPI2_customIntrHandler)
    {
        SPI2_customIntrHandler();
    }

    #if(SPI2_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        SPI2_ClearSpiExtClkInterruptSource(SPI2_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if (SPI2_CHECK_RX_SW_BUFFER)
    {
        if (SPI2_CHECK_INTR_RX_MASKED(SPI2_INTR_RX_NOT_EMPTY))
        {
            do
            {
                /* Move local head index */
                locHead = (SPI2_rxBufferHead + 1u);

                /* Adjust local head index */
                if (SPI2_INTERNAL_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if (locHead == SPI2_rxBufferTail)
                {
                    #if (SPI2_CHECK_UART_RTS_CONTROL_FLOW)
                    {
                        /* There is no space in the software buffer - disable the
                        * RX Not Empty interrupt source. The data elements are
                        * still being received into the RX FIFO until the RTS signal
                        * stops the transmitter. After the data element is read from the
                        * buffer, the RX Not Empty interrupt source is enabled to
                        * move the next data element in the software buffer.
                        */
                        SPI2_INTR_RX_MASK_REG &= ~SPI2_INTR_RX_NOT_EMPTY;
                        break;
                    }
                    #else
                    {
                        /* Overflow: through away received data element */
                        (void) SPI2_RX_FIFO_RD_REG;
                        SPI2_rxBufferOverflow = (uint8) SPI2_INTR_RX_OVERFLOW;
                    }
                    #endif
                }
                else
                {
                    /* Store received data */
                    SPI2_PutWordInRxBuffer(locHead, SPI2_RX_FIFO_RD_REG);

                    /* Move head index */
                    SPI2_rxBufferHead = locHead;
                }
            }
            while(0u != SPI2_GET_RX_FIFO_ENTRIES);

            SPI2_ClearRxInterruptSource(SPI2_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if (SPI2_CHECK_TX_SW_BUFFER)
    {
        if (SPI2_CHECK_INTR_TX_MASKED(SPI2_INTR_TX_NOT_FULL))
        {
            do
            {
                /* Check for room in TX software buffer */
                if (SPI2_txBufferHead != SPI2_txBufferTail)
                {
                    /* Move local tail index */
                    locTail = (SPI2_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if (SPI2_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    SPI2_TX_FIFO_WR_REG = SPI2_GetWordFromTxBuffer(locTail);

                    /* Move tail index */
                    SPI2_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is empty: complete transfer */
                    SPI2_DISABLE_INTR_TX(SPI2_INTR_TX_NOT_FULL);
                    break;
                }
            }
            while (SPI2_SPI_UART_FIFO_SIZE != SPI2_GET_TX_FIFO_ENTRIES);

            SPI2_ClearTxInterruptSource(SPI2_INTR_TX_NOT_FULL);
        }
    }
    #endif

#ifdef SPI2_SPI_UART_ISR_EXIT_CALLBACK
    SPI2_SPI_UART_ISR_ExitCallback();
#endif /* SPI2_SPI_UART_ISR_EXIT_CALLBACK */

}

#endif /* (SPI2_SCB_IRQ_INTERNAL) */


/* [] END OF FILE */
