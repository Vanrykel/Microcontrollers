/*******************************************************************************
* File Name: PWM_160Hz_PM.c
* Version 1.0
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_160Hz.h"

static PWM_160Hz_BACKUP_STRUCT PWM_160Hz_backup;


/*******************************************************************************
* Function Name: PWM_160Hz_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_160Hz_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_Sleep(void)
{
    if(0u != (PWM_160Hz_BLOCK_CONTROL_REG & PWM_160Hz_MASK))
    {
        PWM_160Hz_backup.enableState = 1u;
    }
    else
    {
        PWM_160Hz_backup.enableState = 0u;
    }

    PWM_160Hz_Stop();
    PWM_160Hz_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_160Hz_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_160Hz_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_Wakeup(void)
{
    PWM_160Hz_RestoreConfig();

    if(0u != PWM_160Hz_backup.enableState)
    {
        PWM_160Hz_Enable();
    }
}


/* [] END OF FILE */
