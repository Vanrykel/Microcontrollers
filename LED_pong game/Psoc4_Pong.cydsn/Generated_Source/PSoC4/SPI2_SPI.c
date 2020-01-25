/***************************************************************************//**
* \file SPI2_SPI.c
* \version 4.0
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  SPI mode.
*
* Note:
*
*******************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI2_PVT.h"
#include "SPI2_SPI_UART_PVT.h"

#if(SPI2_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    const SPI2_SPI_INIT_STRUCT SPI2_configSpi =
    {
        SPI2_SPI_MODE,
        SPI2_SPI_SUB_MODE,
        SPI2_SPI_CLOCK_MODE,
        SPI2_SPI_OVS_FACTOR,
        SPI2_SPI_MEDIAN_FILTER_ENABLE,
        SPI2_SPI_LATE_MISO_SAMPLE_ENABLE,
        SPI2_SPI_WAKE_ENABLE,
        SPI2_SPI_RX_DATA_BITS_NUM,
        SPI2_SPI_TX_DATA_BITS_NUM,
        SPI2_SPI_BITS_ORDER,
        SPI2_SPI_TRANSFER_SEPARATION,
        0u,
        NULL,
        0u,
        NULL,
        (uint32) SPI2_SCB_IRQ_INTERNAL,
        SPI2_SPI_INTR_RX_MASK,
        SPI2_SPI_RX_TRIGGER_LEVEL,
        SPI2_SPI_INTR_TX_MASK,
        SPI2_SPI_TX_TRIGGER_LEVEL,
        (uint8) SPI2_SPI_BYTE_MODE_ENABLE,
        (uint8) SPI2_SPI_FREE_RUN_SCLK_ENABLE,
        (uint8) SPI2_SPI_SS_POLARITY
    };


    /*******************************************************************************
    * Function Name: SPI2_SpiInit
    ****************************************************************************//**
    *
    *  Configures the SPI2 for SPI operation.
    *
    *  This function is intended specifically to be used when the SPI2 
    *  configuration is set to “Unconfigured SPI2” in the customizer. 
    *  After initializing the SPI2 in SPI mode using this function, 
    *  the component can be enabled using the SPI2_Start() or 
    * SPI2_Enable() function.
    *  This function uses a pointer to a structure that provides the configuration 
    *  settings. This structure contains the same information that would otherwise 
    *  be provided by the customizer settings.
    *
    *  \param config: pointer to a structure that contains the following list of 
    *   fields. These fields match the selections available in the customizer. 
    *   Refer to the customizer for further description of the settings.
    *
    *******************************************************************************/
    void SPI2_SpiInit(const SPI2_SPI_INIT_STRUCT *config)
    {
        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Configure pins */
            SPI2_SetPins(SPI2_SCB_MODE_SPI, config->mode, SPI2_DUMMY_PARAM);

            /* Store internal configuration */
            SPI2_scbMode       = (uint8) SPI2_SCB_MODE_SPI;
            SPI2_scbEnableWake = (uint8) config->enableWake;
            SPI2_scbEnableIntr = (uint8) config->enableInterrupt;

            /* Set RX direction internal variables */
            SPI2_rxBuffer      =         config->rxBuffer;
            SPI2_rxDataBits    = (uint8) config->rxDataBits;
            SPI2_rxBufferSize  =         config->rxBufferSize;

            /* Set TX direction internal variables */
            SPI2_txBuffer      =         config->txBuffer;
            SPI2_txDataBits    = (uint8) config->txDataBits;
            SPI2_txBufferSize  =         config->txBufferSize;

            /* Configure SPI interface */
            SPI2_CTRL_REG     = SPI2_GET_CTRL_OVS(config->oversample)           |
                                            SPI2_GET_CTRL_BYTE_MODE(config->enableByteMode) |
                                            SPI2_GET_CTRL_EC_AM_MODE(config->enableWake)    |
                                            SPI2_CTRL_SPI;

            SPI2_SPI_CTRL_REG = SPI2_GET_SPI_CTRL_CONTINUOUS    (config->transferSeperation)  |
                                            SPI2_GET_SPI_CTRL_SELECT_PRECEDE(config->submode &
                                                                          SPI2_SPI_MODE_TI_PRECEDES_MASK) |
                                            SPI2_GET_SPI_CTRL_SCLK_MODE     (config->sclkMode)            |
                                            SPI2_GET_SPI_CTRL_LATE_MISO_SAMPLE(config->enableLateSampling)|
                                            SPI2_GET_SPI_CTRL_SCLK_CONTINUOUS(config->enableFreeRunSclk)  |
                                            SPI2_GET_SPI_CTRL_SSEL_POLARITY (config->polaritySs)          |
                                            SPI2_GET_SPI_CTRL_SUB_MODE      (config->submode)             |
                                            SPI2_GET_SPI_CTRL_MASTER_MODE   (config->mode);

            /* Configure RX direction */
            SPI2_RX_CTRL_REG     =  SPI2_GET_RX_CTRL_DATA_WIDTH(config->rxDataBits)         |
                                                SPI2_GET_RX_CTRL_BIT_ORDER (config->bitOrder)           |
                                                SPI2_GET_RX_CTRL_MEDIAN    (config->enableMedianFilter) |
                                                SPI2_SPI_RX_CTRL;

            SPI2_RX_FIFO_CTRL_REG = SPI2_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(config->rxTriggerLevel);

            /* Configure TX direction */
            SPI2_TX_CTRL_REG      = SPI2_GET_TX_CTRL_DATA_WIDTH(config->txDataBits) |
                                                SPI2_GET_TX_CTRL_BIT_ORDER (config->bitOrder)   |
                                                SPI2_SPI_TX_CTRL;

            SPI2_TX_FIFO_CTRL_REG = SPI2_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(config->txTriggerLevel);

            /* Configure interrupt with SPI handler but do not enable it */
            CyIntDisable    (SPI2_ISR_NUMBER);
            CyIntSetPriority(SPI2_ISR_NUMBER, SPI2_ISR_PRIORITY);
            (void) CyIntSetVector(SPI2_ISR_NUMBER, &SPI2_SPI_UART_ISR);

            /* Configure interrupt sources */
            SPI2_INTR_I2C_EC_MASK_REG = SPI2_NO_INTR_SOURCES;
            SPI2_INTR_SPI_EC_MASK_REG = SPI2_NO_INTR_SOURCES;
            SPI2_INTR_SLAVE_MASK_REG  = SPI2_GET_SPI_INTR_SLAVE_MASK(config->rxInterruptMask);
            SPI2_INTR_MASTER_MASK_REG = SPI2_GET_SPI_INTR_MASTER_MASK(config->txInterruptMask);
            SPI2_INTR_RX_MASK_REG     = SPI2_GET_SPI_INTR_RX_MASK(config->rxInterruptMask);
            SPI2_INTR_TX_MASK_REG     = SPI2_GET_SPI_INTR_TX_MASK(config->txInterruptMask);
            
            /* Configure TX interrupt sources to restore. */
            SPI2_IntrTxMask = LO16(SPI2_INTR_TX_MASK_REG);

            /* Set active SS0 */
            SPI2_SpiSetActiveSlaveSelect(SPI2_SPI_SLAVE_SELECT0);

            /* Clear RX buffer indexes */
            SPI2_rxBufferHead     = 0u;
            SPI2_rxBufferTail     = 0u;
            SPI2_rxBufferOverflow = 0u;

            /* Clear TX buffer indexes */
            SPI2_txBufferHead = 0u;
            SPI2_txBufferTail = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: SPI2_SpiInit
    ****************************************************************************//**
    *
    *  Configures the SCB for the SPI operation.
    *
    *******************************************************************************/
    void SPI2_SpiInit(void)
    {
        /* Configure SPI interface */
        SPI2_CTRL_REG     = SPI2_SPI_DEFAULT_CTRL;
        SPI2_SPI_CTRL_REG = SPI2_SPI_DEFAULT_SPI_CTRL;

        /* Configure TX and RX direction */
        SPI2_RX_CTRL_REG      = SPI2_SPI_DEFAULT_RX_CTRL;
        SPI2_RX_FIFO_CTRL_REG = SPI2_SPI_DEFAULT_RX_FIFO_CTRL;

        /* Configure TX and RX direction */
        SPI2_TX_CTRL_REG      = SPI2_SPI_DEFAULT_TX_CTRL;
        SPI2_TX_FIFO_CTRL_REG = SPI2_SPI_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with SPI handler but do not enable it */
    #if(SPI2_SCB_IRQ_INTERNAL)
            CyIntDisable    (SPI2_ISR_NUMBER);
            CyIntSetPriority(SPI2_ISR_NUMBER, SPI2_ISR_PRIORITY);
            (void) CyIntSetVector(SPI2_ISR_NUMBER, &SPI2_SPI_UART_ISR);
    #endif /* (SPI2_SCB_IRQ_INTERNAL) */

        /* Configure interrupt sources */
        SPI2_INTR_I2C_EC_MASK_REG = SPI2_SPI_DEFAULT_INTR_I2C_EC_MASK;
        SPI2_INTR_SPI_EC_MASK_REG = SPI2_SPI_DEFAULT_INTR_SPI_EC_MASK;
        SPI2_INTR_SLAVE_MASK_REG  = SPI2_SPI_DEFAULT_INTR_SLAVE_MASK;
        SPI2_INTR_MASTER_MASK_REG = SPI2_SPI_DEFAULT_INTR_MASTER_MASK;
        SPI2_INTR_RX_MASK_REG     = SPI2_SPI_DEFAULT_INTR_RX_MASK;
        SPI2_INTR_TX_MASK_REG     = SPI2_SPI_DEFAULT_INTR_TX_MASK;

        /* Configure TX interrupt sources to restore. */
        SPI2_IntrTxMask = LO16(SPI2_INTR_TX_MASK_REG);
            
        /* Set active SS0 for master */
    #if (SPI2_SPI_MASTER_CONST)
        SPI2_SpiSetActiveSlaveSelect(SPI2_SPI_SLAVE_SELECT0);
    #endif /* (SPI2_SPI_MASTER_CONST) */

    #if(SPI2_INTERNAL_RX_SW_BUFFER_CONST)
        SPI2_rxBufferHead     = 0u;
        SPI2_rxBufferTail     = 0u;
        SPI2_rxBufferOverflow = 0u;
    #endif /* (SPI2_INTERNAL_RX_SW_BUFFER_CONST) */

    #if(SPI2_INTERNAL_TX_SW_BUFFER_CONST)
        SPI2_txBufferHead = 0u;
        SPI2_txBufferTail = 0u;
    #endif /* (SPI2_INTERNAL_TX_SW_BUFFER_CONST) */
    }
#endif /* (SPI2_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: SPI2_SpiPostEnable
****************************************************************************//**
*
*  Restores HSIOM settings for the SPI master output pins (SCLK and/or SS0-SS3) 
*  to be controlled by the SCB SPI.
*
*******************************************************************************/
void SPI2_SpiPostEnable(void)
{
#if(SPI2_SCB_MODE_UNCONFIG_CONST_CFG)

    if (SPI2_CHECK_SPI_MASTER)
    {
    #if (SPI2_SCLK_PIN)
        /* Set SCB SPI to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SCLK_HSIOM_REG, SPI2_SCLK_HSIOM_MASK,
                                       SPI2_SCLK_HSIOM_POS, SPI2_SCLK_HSIOM_SEL_SPI);
    #endif /* (SPI2_SCLK_PIN) */

    #if (SPI2_SS0_PIN)
        /* Set SCB SPI to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SS0_HSIOM_REG, SPI2_SS0_HSIOM_MASK,
                                       SPI2_SS0_HSIOM_POS, SPI2_SS0_HSIOM_SEL_SPI);
    #endif /* (SPI2_SS0_PIN) */

    #if (SPI2_SS1_PIN)
        /* Set SCB SPI to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SS1_HSIOM_REG, SPI2_SS1_HSIOM_MASK,
                                       SPI2_SS1_HSIOM_POS, SPI2_SS1_HSIOM_SEL_SPI);
    #endif /* (SPI2_SS1_PIN) */

    #if (SPI2_SS2_PIN)
        /* Set SCB SPI to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SS2_HSIOM_REG, SPI2_SS2_HSIOM_MASK,
                                       SPI2_SS2_HSIOM_POS, SPI2_SS2_HSIOM_SEL_SPI);
    #endif /* (SPI2_SS2_PIN) */

    #if (SPI2_SS3_PIN)
        /* Set SCB SPI to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SS3_HSIOM_REG, SPI2_SS3_HSIOM_MASK,
                                       SPI2_SS3_HSIOM_POS, SPI2_SS3_HSIOM_SEL_SPI);
    #endif /* (SPI2_SS3_PIN) */
    }

#else

    #if (SPI2_SPI_MASTER_SCLK_PIN)
        /* Set SCB SPI to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SCLK_M_HSIOM_REG, SPI2_SCLK_M_HSIOM_MASK,
                                       SPI2_SCLK_M_HSIOM_POS, SPI2_SCLK_M_HSIOM_SEL_SPI);
    #endif /* (SPI2_MISO_SDA_TX_PIN_PIN) */

    #if (SPI2_SPI_MASTER_SS0_PIN)
        /* Set SCB SPI to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SS0_M_HSIOM_REG, SPI2_SS0_M_HSIOM_MASK,
                                       SPI2_SS0_M_HSIOM_POS, SPI2_SS0_M_HSIOM_SEL_SPI);
    #endif /* (SPI2_SPI_MASTER_SS0_PIN) */

    #if (SPI2_SPI_MASTER_SS1_PIN)
        /* Set SCB SPI to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SS1_M_HSIOM_REG, SPI2_SS1_M_HSIOM_MASK,
                                       SPI2_SS1_M_HSIOM_POS, SPI2_SS1_M_HSIOM_SEL_SPI);
    #endif /* (SPI2_SPI_MASTER_SS1_PIN) */

    #if (SPI2_SPI_MASTER_SS2_PIN)
        /* Set SCB SPI to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SS2_M_HSIOM_REG, SPI2_SS2_M_HSIOM_MASK,
                                       SPI2_SS2_M_HSIOM_POS, SPI2_SS2_M_HSIOM_SEL_SPI);
    #endif /* (SPI2_SPI_MASTER_SS2_PIN) */

    #if (SPI2_SPI_MASTER_SS3_PIN)
        /* Set SCB SPI to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SS3_M_HSIOM_REG, SPI2_SS3_M_HSIOM_MASK,
                                       SPI2_SS3_M_HSIOM_POS, SPI2_SS3_M_HSIOM_SEL_SPI);
    #endif /* (SPI2_SPI_MASTER_SS3_PIN) */

#endif /* (SPI2_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Restore TX interrupt sources. */
    SPI2_SetTxInterruptMode(SPI2_IntrTxMask);
}


/*******************************************************************************
* Function Name: SPI2_SpiStop
****************************************************************************//**
*
*  Changes the HSIOM settings for the SPI master output pins 
*  (SCLK and/or SS0-SS3) to keep them inactive after the block is disabled. 
*  The output pins are controlled by the GPIO data register.
*
*******************************************************************************/
void SPI2_SpiStop(void)
{
#if(SPI2_SCB_MODE_UNCONFIG_CONST_CFG)

    if (SPI2_CHECK_SPI_MASTER)
    {
    #if (SPI2_SCLK_PIN)
        /* Set output pin state after block is disabled */
        SPI2_spi_sclk_Write(SPI2_GET_SPI_SCLK_INACTIVE);

        /* Set GPIO to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SCLK_HSIOM_REG, SPI2_SCLK_HSIOM_MASK,
                                       SPI2_SCLK_HSIOM_POS, SPI2_SCLK_HSIOM_SEL_GPIO);
    #endif /* (SPI2_spi_sclk_PIN) */

    #if (SPI2_SS0_PIN)
        /* Set output pin state after block is disabled */
        SPI2_spi_ss0_Write(SPI2_GET_SPI_SS0_INACTIVE);

        /* Set GPIO to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SS0_HSIOM_REG, SPI2_SS0_HSIOM_MASK,
                                       SPI2_SS0_HSIOM_POS, SPI2_SS0_HSIOM_SEL_GPIO);
    #endif /* (SPI2_spi_ss0_PIN) */

    #if (SPI2_SS1_PIN)
        /* Set output pin state after block is disabled */
        SPI2_spi_ss1_Write(SPI2_GET_SPI_SS1_INACTIVE);

        /* Set GPIO to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SS1_HSIOM_REG, SPI2_SS1_HSIOM_MASK,
                                       SPI2_SS1_HSIOM_POS, SPI2_SS1_HSIOM_SEL_GPIO);
    #endif /* (SPI2_SS1_PIN) */

    #if (SPI2_SS2_PIN)
        /* Set output pin state after block is disabled */
        SPI2_spi_ss2_Write(SPI2_GET_SPI_SS2_INACTIVE);

        /* Set GPIO to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SS2_HSIOM_REG, SPI2_SS2_HSIOM_MASK,
                                       SPI2_SS2_HSIOM_POS, SPI2_SS2_HSIOM_SEL_GPIO);
    #endif /* (SPI2_SS2_PIN) */

    #if (SPI2_SS3_PIN)
        /* Set output pin state after block is disabled */
        SPI2_spi_ss3_Write(SPI2_GET_SPI_SS3_INACTIVE);

        /* Set GPIO to drive output pin */
        SPI2_SET_HSIOM_SEL(SPI2_SS3_HSIOM_REG, SPI2_SS3_HSIOM_MASK,
                                       SPI2_SS3_HSIOM_POS, SPI2_SS3_HSIOM_SEL_GPIO);
    #endif /* (SPI2_SS3_PIN) */
    
        /* Store TX interrupt sources (exclude level triggered) for master. */
        SPI2_IntrTxMask = LO16(SPI2_GetTxInterruptMode() & SPI2_INTR_SPIM_TX_RESTORE);
    }
    else
    {
        /* Store TX interrupt sources (exclude level triggered) for slave. */
        SPI2_IntrTxMask = LO16(SPI2_GetTxInterruptMode() & SPI2_INTR_SPIS_TX_RESTORE);
    }

#else

#if (SPI2_SPI_MASTER_SCLK_PIN)
    /* Set output pin state after block is disabled */
    SPI2_sclk_m_Write(SPI2_GET_SPI_SCLK_INACTIVE);

    /* Set GPIO to drive output pin */
    SPI2_SET_HSIOM_SEL(SPI2_SCLK_M_HSIOM_REG, SPI2_SCLK_M_HSIOM_MASK,
                                   SPI2_SCLK_M_HSIOM_POS, SPI2_SCLK_M_HSIOM_SEL_GPIO);
#endif /* (SPI2_MISO_SDA_TX_PIN_PIN) */

#if (SPI2_SPI_MASTER_SS0_PIN)
    /* Set output pin state after block is disabled */
    SPI2_ss0_m_Write(SPI2_GET_SPI_SS0_INACTIVE);

    /* Set GPIO to drive output pin */
    SPI2_SET_HSIOM_SEL(SPI2_SS0_M_HSIOM_REG, SPI2_SS0_M_HSIOM_MASK,
                                   SPI2_SS0_M_HSIOM_POS, SPI2_SS0_M_HSIOM_SEL_GPIO);
#endif /* (SPI2_SPI_MASTER_SS0_PIN) */

#if (SPI2_SPI_MASTER_SS1_PIN)
    /* Set output pin state after block is disabled */
    SPI2_ss1_m_Write(SPI2_GET_SPI_SS1_INACTIVE);

    /* Set GPIO to drive output pin */
    SPI2_SET_HSIOM_SEL(SPI2_SS1_M_HSIOM_REG, SPI2_SS1_M_HSIOM_MASK,
                                   SPI2_SS1_M_HSIOM_POS, SPI2_SS1_M_HSIOM_SEL_GPIO);
#endif /* (SPI2_SPI_MASTER_SS1_PIN) */

#if (SPI2_SPI_MASTER_SS2_PIN)
    /* Set output pin state after block is disabled */
    SPI2_ss2_m_Write(SPI2_GET_SPI_SS2_INACTIVE);

    /* Set GPIO to drive output pin */
    SPI2_SET_HSIOM_SEL(SPI2_SS2_M_HSIOM_REG, SPI2_SS2_M_HSIOM_MASK,
                                   SPI2_SS2_M_HSIOM_POS, SPI2_SS2_M_HSIOM_SEL_GPIO);
#endif /* (SPI2_SPI_MASTER_SS2_PIN) */

#if (SPI2_SPI_MASTER_SS3_PIN)
    /* Set output pin state after block is disabled */
    SPI2_ss3_m_Write(SPI2_GET_SPI_SS3_INACTIVE);

    /* Set GPIO to drive output pin */
    SPI2_SET_HSIOM_SEL(SPI2_SS3_M_HSIOM_REG, SPI2_SS3_M_HSIOM_MASK,
                                   SPI2_SS3_M_HSIOM_POS, SPI2_SS3_M_HSIOM_SEL_GPIO);
#endif /* (SPI2_SPI_MASTER_SS3_PIN) */

    #if (SPI2_SPI_MASTER_CONST)
        /* Store TX interrupt sources (exclude level triggered). */
        SPI2_IntrTxMask = LO16(SPI2_GetTxInterruptMode() & SPI2_INTR_SPIM_TX_RESTORE);
    #else
        /* Store TX interrupt sources (exclude level triggered). */
        SPI2_IntrTxMask = LO16(SPI2_GetTxInterruptMode() & SPI2_INTR_SPIS_TX_RESTORE);
    #endif /* (SPI2_SPI_MASTER_CONST) */

#endif /* (SPI2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (SPI2_SPI_MASTER_CONST)
    /*******************************************************************************
    * Function Name: SPI2_SetActiveSlaveSelect
    ****************************************************************************//**
    *
    *  Selects one of the four slave select lines to be active during the transfer.
    *  After initialization the active slave select line is 0.
    *  The component should be in one of the following states to change the active
    *  slave select signal source correctly:
    *   - The component is disabled.
    *   - The component has completed transfer (TX FIFO is empty and the
    *     SCB_INTR_MASTER_SPI_DONE status is set).
    *
    *  This function does not check that these conditions are met.
    *  This function is only applicable to SPI Master mode of operation.
    *
    *  \param slaveSelect: slave select line which will be active while the following
    *   transfer.
    *   - SPI2_SPI_SLAVE_SELECT0 - Slave select 0.
    *   - SPI2_SPI_SLAVE_SELECT1 - Slave select 1.
    *   - SPI2_SPI_SLAVE_SELECT2 - Slave select 2.
    *   - SPI2_SPI_SLAVE_SELECT3 - Slave select 3.
    *
    *******************************************************************************/
    void SPI2_SpiSetActiveSlaveSelect(uint32 slaveSelect)
    {
        uint32 spiCtrl;

        spiCtrl = SPI2_SPI_CTRL_REG;

        spiCtrl &= (uint32) ~SPI2_SPI_CTRL_SLAVE_SELECT_MASK;
        spiCtrl |= (uint32)  SPI2_GET_SPI_CTRL_SS(slaveSelect);

        SPI2_SPI_CTRL_REG = spiCtrl;
    }
#endif /* (SPI2_SPI_MASTER_CONST) */


#if !(SPI2_CY_SCBIP_V0 || SPI2_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: SPI2_SpiSetSlaveSelectPolarity
    ****************************************************************************//**
    *
    *  Sets active polarity for slave select line.
    *  The component should be in one of the following states to change the active
    *  slave select signal source correctly:
    *   - The component is disabled.
    *   - The component has completed transfer.
    *  
    *  This function does not check that these conditions are met.
    *
    *  \param slaveSelect: slave select line to change active polarity.
    *   - SPI2_SPI_SLAVE_SELECT0 - Slave select 0.
    *   - SPI2_SPI_SLAVE_SELECT1 - Slave select 1.
    *   - SPI2_SPI_SLAVE_SELECT2 - Slave select 2.
    *   - SPI2_SPI_SLAVE_SELECT3 - Slave select 3.
    *
    *  \param polarity: active polarity of slave select line.
    *   - SPI2_SPI_SS_ACTIVE_LOW  - Slave select is active low.
    *   - SPI2_SPI_SS_ACTIVE_HIGH - Slave select is active high.
    *
    *******************************************************************************/
    void SPI2_SpiSetSlaveSelectPolarity(uint32 slaveSelect, uint32 polarity)
    {
        uint32 ssPolarity;

        /* Get position of the polarity bit associated with slave select line */
        ssPolarity = SPI2_GET_SPI_CTRL_SSEL_POLARITY((uint32) 1u << slaveSelect);

        if (0u != polarity)
        {
            SPI2_SPI_CTRL_REG |= (uint32)  ssPolarity;
        }
        else
        {
            SPI2_SPI_CTRL_REG &= (uint32) ~ssPolarity;
        }
    }
#endif /* !(SPI2_CY_SCBIP_V0 || SPI2_CY_SCBIP_V1) */


#if(SPI2_SPI_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: SPI2_SpiSaveConfig
    ****************************************************************************//**
    *
    *  Clears INTR_SPI_EC.WAKE_UP and enables it. This interrupt
    *  source triggers when the master assigns the SS line and wakes up the device.
    *
    *******************************************************************************/
    void SPI2_SpiSaveConfig(void)
    {
        /* Clear and enable SPI wakeup interrupt source */
        SPI2_ClearSpiExtClkInterruptSource(SPI2_INTR_SPI_EC_WAKE_UP);
        SPI2_SetSpiExtClkInterruptMode(SPI2_INTR_SPI_EC_WAKE_UP);
    }


    /*******************************************************************************
    * Function Name: SPI2_SpiRestoreConfig
    ****************************************************************************//**
    *
    *  Disables the INTR_SPI_EC.WAKE_UP interrupt source. After wakeup
    *  slave does not drive the MISO line and the master receives 0xFF.
    *
    *******************************************************************************/
    void SPI2_SpiRestoreConfig(void)
    {
        /* Disable SPI wakeup interrupt source */
        SPI2_SetSpiExtClkInterruptMode(SPI2_NO_INTR_SOURCES);
    }
#endif /* (SPI2_SPI_WAKE_ENABLE_CONST) */


/* [] END OF FILE */
