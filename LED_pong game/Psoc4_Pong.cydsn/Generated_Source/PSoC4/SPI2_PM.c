/***************************************************************************//**
* \file SPI2_PM.c
* \version 4.0
*
* \brief
*  This file provides the source code to the Power Management support for
*  the SCB Component.
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

#include "SPI2.h"
#include "SPI2_PVT.h"

#if(SPI2_SCB_MODE_I2C_INC)
    #include "SPI2_I2C_PVT.h"
#endif /* (SPI2_SCB_MODE_I2C_INC) */

#if(SPI2_SCB_MODE_EZI2C_INC)
    #include "SPI2_EZI2C_PVT.h"
#endif /* (SPI2_SCB_MODE_EZI2C_INC) */

#if(SPI2_SCB_MODE_SPI_INC || SPI2_SCB_MODE_UART_INC)
    #include "SPI2_SPI_UART_PVT.h"
#endif /* (SPI2_SCB_MODE_SPI_INC || SPI2_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(SPI2_SCB_MODE_UNCONFIG_CONST_CFG || \
   (SPI2_SCB_MODE_I2C_CONST_CFG   && (!SPI2_I2C_WAKE_ENABLE_CONST))   || \
   (SPI2_SCB_MODE_EZI2C_CONST_CFG && (!SPI2_EZI2C_WAKE_ENABLE_CONST)) || \
   (SPI2_SCB_MODE_SPI_CONST_CFG   && (!SPI2_SPI_WAKE_ENABLE_CONST))   || \
   (SPI2_SCB_MODE_UART_CONST_CFG  && (!SPI2_UART_WAKE_ENABLE_CONST)))

    SPI2_BACKUP_STRUCT SPI2_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: SPI2_Sleep
****************************************************************************//**
*
*  Prepares the SPI2 component to enter Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has an influence on this 
*  function implementation:
*  - Checked: configures the component to be wakeup source from Deep Sleep.
*  - Unchecked: stores the current component state (enabled or disabled) and 
*    disables the component. See SCB_Stop() function for details about component 
*    disabling.
*
*  Call the SPI2_Sleep() function before calling the 
*  CyPmSysDeepSleep() function. 
*  Refer to the PSoC Creator System Reference Guide for more information about 
*  power management functions and Low power section of this document for the 
*  selected mode.
*
*  This function should not be called before entering Sleep.
*
*******************************************************************************/
void SPI2_Sleep(void)
{
#if(SPI2_SCB_MODE_UNCONFIG_CONST_CFG)

    if(SPI2_SCB_WAKE_ENABLE_CHECK)
    {
        if(SPI2_SCB_MODE_I2C_RUNTM_CFG)
        {
            SPI2_I2CSaveConfig();
        }
        else if(SPI2_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SPI2_EzI2CSaveConfig();
        }
    #if(!SPI2_CY_SCBIP_V1)
        else if(SPI2_SCB_MODE_SPI_RUNTM_CFG)
        {
            SPI2_SpiSaveConfig();
        }
        else if(SPI2_SCB_MODE_UART_RUNTM_CFG)
        {
            SPI2_UartSaveConfig();
        }
    #endif /* (!SPI2_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        SPI2_backup.enableState = (uint8) SPI2_GET_CTRL_ENABLED;

        if(0u != SPI2_backup.enableState)
        {
            SPI2_Stop();
        }
    }

#else

    #if (SPI2_SCB_MODE_I2C_CONST_CFG && SPI2_I2C_WAKE_ENABLE_CONST)
        SPI2_I2CSaveConfig();

    #elif (SPI2_SCB_MODE_EZI2C_CONST_CFG && SPI2_EZI2C_WAKE_ENABLE_CONST)
        SPI2_EzI2CSaveConfig();

    #elif (SPI2_SCB_MODE_SPI_CONST_CFG && SPI2_SPI_WAKE_ENABLE_CONST)
        SPI2_SpiSaveConfig();

    #elif (SPI2_SCB_MODE_UART_CONST_CFG && SPI2_UART_WAKE_ENABLE_CONST)
        SPI2_UartSaveConfig();

    #else

        SPI2_backup.enableState = (uint8) SPI2_GET_CTRL_ENABLED;

        if(0u != SPI2_backup.enableState)
        {
            SPI2_Stop();
        }

    #endif /* defined (SPI2_SCB_MODE_I2C_CONST_CFG) && (SPI2_I2C_WAKE_ENABLE_CONST) */

#endif /* (SPI2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SPI2_Wakeup
****************************************************************************//**
*
*  Prepares the SPI2 component for Active mode operation after 
*  Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has influence on this 
*  function implementation:
*  - Checked: restores the component Active mode configuration.
*  - Unchecked: enables the component if it was enabled before enter Deep Sleep.
*
*  This function should not be called after exiting Sleep.
*
*  \sideeffect
*   Calling the SPI2_Wakeup() function without first calling the 
*   SPI2_Sleep() function may produce unexpected behavior.
*
*******************************************************************************/
void SPI2_Wakeup(void)
{
#if(SPI2_SCB_MODE_UNCONFIG_CONST_CFG)

    if(SPI2_SCB_WAKE_ENABLE_CHECK)
    {
        if(SPI2_SCB_MODE_I2C_RUNTM_CFG)
        {
            SPI2_I2CRestoreConfig();
        }
        else if(SPI2_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SPI2_EzI2CRestoreConfig();
        }
    #if(!SPI2_CY_SCBIP_V1)
        else if(SPI2_SCB_MODE_SPI_RUNTM_CFG)
        {
            SPI2_SpiRestoreConfig();
        }
        else if(SPI2_SCB_MODE_UART_RUNTM_CFG)
        {
            SPI2_UartRestoreConfig();
        }
    #endif /* (!SPI2_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != SPI2_backup.enableState)
        {
            SPI2_Enable();
        }
    }

#else

    #if (SPI2_SCB_MODE_I2C_CONST_CFG  && SPI2_I2C_WAKE_ENABLE_CONST)
        SPI2_I2CRestoreConfig();

    #elif (SPI2_SCB_MODE_EZI2C_CONST_CFG && SPI2_EZI2C_WAKE_ENABLE_CONST)
        SPI2_EzI2CRestoreConfig();

    #elif (SPI2_SCB_MODE_SPI_CONST_CFG && SPI2_SPI_WAKE_ENABLE_CONST)
        SPI2_SpiRestoreConfig();

    #elif (SPI2_SCB_MODE_UART_CONST_CFG && SPI2_UART_WAKE_ENABLE_CONST)
        SPI2_UartRestoreConfig();

    #else

        if(0u != SPI2_backup.enableState)
        {
            SPI2_Enable();
        }

    #endif /* (SPI2_I2C_WAKE_ENABLE_CONST) */

#endif /* (SPI2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
