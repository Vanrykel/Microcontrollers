/*******************************************************************************
* File Name: timer_echo_PM.c
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

#include "timer_echo.h"

static timer_echo_BACKUP_STRUCT timer_echo_backup;


/*******************************************************************************
* Function Name: timer_echo_SaveConfig
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
void timer_echo_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: timer_echo_Sleep
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
void timer_echo_Sleep(void)
{
    if(0u != (timer_echo_BLOCK_CONTROL_REG & timer_echo_MASK))
    {
        timer_echo_backup.enableState = 1u;
    }
    else
    {
        timer_echo_backup.enableState = 0u;
    }

    timer_echo_Stop();
    timer_echo_SaveConfig();
}


/*******************************************************************************
* Function Name: timer_echo_RestoreConfig
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
void timer_echo_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: timer_echo_Wakeup
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
void timer_echo_Wakeup(void)
{
    timer_echo_RestoreConfig();

    if(0u != timer_echo_backup.enableState)
    {
        timer_echo_Enable();
    }
}


/* [] END OF FILE */
