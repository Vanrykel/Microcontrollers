/*******************************************************************************
* File Name: Ticker_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Ticker.h"

static Ticker_backupStruct Ticker_backup;


/*******************************************************************************
* Function Name: Ticker_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Ticker_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Ticker_SaveConfig(void) 
{
    #if (!Ticker_UsingFixedFunction)
        Ticker_backup.TimerUdb = Ticker_ReadCounter();
        Ticker_backup.InterruptMaskValue = Ticker_STATUS_MASK;
        #if (Ticker_UsingHWCaptureCounter)
            Ticker_backup.TimerCaptureCounter = Ticker_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Ticker_UDB_CONTROL_REG_REMOVED)
            Ticker_backup.TimerControlRegister = Ticker_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Ticker_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Ticker_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Ticker_RestoreConfig(void) 
{   
    #if (!Ticker_UsingFixedFunction)

        Ticker_WriteCounter(Ticker_backup.TimerUdb);
        Ticker_STATUS_MASK =Ticker_backup.InterruptMaskValue;
        #if (Ticker_UsingHWCaptureCounter)
            Ticker_SetCaptureCount(Ticker_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Ticker_UDB_CONTROL_REG_REMOVED)
            Ticker_WriteControlRegister(Ticker_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Ticker_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Ticker_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Ticker_Sleep(void) 
{
    #if(!Ticker_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Ticker_CTRL_ENABLE == (Ticker_CONTROL & Ticker_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Ticker_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Ticker_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Ticker_Stop();
    Ticker_SaveConfig();
}


/*******************************************************************************
* Function Name: Ticker_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Ticker_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Ticker_Wakeup(void) 
{
    Ticker_RestoreConfig();
    #if(!Ticker_UDB_CONTROL_REG_REMOVED)
        if(Ticker_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Ticker_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
