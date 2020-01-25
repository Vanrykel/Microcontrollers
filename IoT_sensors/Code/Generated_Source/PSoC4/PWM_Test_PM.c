/*******************************************************************************
* File Name: PWM_Test_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_Test.h"

static PWM_Test_BACKUP_STRUCT PWM_Test_backup;


/*******************************************************************************
* Function Name: PWM_Test_SaveConfig
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
void PWM_Test_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_Test_Sleep
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
void PWM_Test_Sleep(void)
{
    if(0u != (PWM_Test_BLOCK_CONTROL_REG & PWM_Test_MASK))
    {
        PWM_Test_backup.enableState = 1u;
    }
    else
    {
        PWM_Test_backup.enableState = 0u;
    }

    PWM_Test_Stop();
    PWM_Test_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Test_RestoreConfig
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
void PWM_Test_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_Test_Wakeup
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
void PWM_Test_Wakeup(void)
{
    PWM_Test_RestoreConfig();

    if(0u != PWM_Test_backup.enableState)
    {
        PWM_Test_Enable();
    }
}


/* [] END OF FILE */
