/*******************************************************************************
* File Name: readTimer_PM.c
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

#include "readTimer.h"

static readTimer_BACKUP_STRUCT readTimer_backup;


/*******************************************************************************
* Function Name: readTimer_SaveConfig
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
void readTimer_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: readTimer_Sleep
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
void readTimer_Sleep(void)
{
    if(0u != (readTimer_BLOCK_CONTROL_REG & readTimer_MASK))
    {
        readTimer_backup.enableState = 1u;
    }
    else
    {
        readTimer_backup.enableState = 0u;
    }

    readTimer_Stop();
    readTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: readTimer_RestoreConfig
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
void readTimer_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: readTimer_Wakeup
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
void readTimer_Wakeup(void)
{
    readTimer_RestoreConfig();

    if(0u != readTimer_backup.enableState)
    {
        readTimer_Enable();
    }
}


/* [] END OF FILE */
