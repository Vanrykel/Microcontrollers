/*******************************************************************************
* File Name: PWM_2500Hz_PM.c
* Version 3.0
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include "cytypes.h"
#include "PWM_2500Hz.h"

static PWM_2500Hz_backupStruct PWM_2500Hz_backup;


/*******************************************************************************
* Function Name: PWM_2500Hz_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  PWM_2500Hz_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void PWM_2500Hz_SaveConfig(void) 
{
    
    #if(!PWM_2500Hz_UsingFixedFunction)
        #if(!PWM_2500Hz_PWMModeIsCenterAligned)
            PWM_2500Hz_backup.PWMPeriod = PWM_2500Hz_ReadPeriod();
        #endif /* (!PWM_2500Hz_PWMModeIsCenterAligned) */
        PWM_2500Hz_backup.PWMUdb = PWM_2500Hz_ReadCounter();
        #if (PWM_2500Hz_UseStatus)
            PWM_2500Hz_backup.InterruptMaskValue = PWM_2500Hz_STATUS_MASK;
        #endif /* (PWM_2500Hz_UseStatus) */
        
        #if(PWM_2500Hz_DeadBandMode == PWM_2500Hz__B_PWM__DBM_256_CLOCKS || \
            PWM_2500Hz_DeadBandMode == PWM_2500Hz__B_PWM__DBM_2_4_CLOCKS)
            PWM_2500Hz_backup.PWMdeadBandValue = PWM_2500Hz_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */
        
        #if(PWM_2500Hz_KillModeMinTime)
             PWM_2500Hz_backup.PWMKillCounterPeriod = PWM_2500Hz_ReadKillTime();
        #endif /* (PWM_2500Hz_KillModeMinTime) */
        
        #if(PWM_2500Hz_UseControl)
            PWM_2500Hz_backup.PWMControlRegister = PWM_2500Hz_ReadControlRegister();
        #endif /* (PWM_2500Hz_UseControl) */
    #endif  /* (!PWM_2500Hz_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_2500Hz_RestoreConfig
********************************************************************************
* 
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  PWM_2500Hz_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_2500Hz_RestoreConfig(void) 
{
        #if(!PWM_2500Hz_UsingFixedFunction)
            #if(!PWM_2500Hz_PWMModeIsCenterAligned)
                PWM_2500Hz_WritePeriod(PWM_2500Hz_backup.PWMPeriod);
            #endif /* (!PWM_2500Hz_PWMModeIsCenterAligned) */
            PWM_2500Hz_WriteCounter(PWM_2500Hz_backup.PWMUdb);
            #if (PWM_2500Hz_UseStatus)
                PWM_2500Hz_STATUS_MASK = PWM_2500Hz_backup.InterruptMaskValue;
            #endif /* (PWM_2500Hz_UseStatus) */
            
            #if(PWM_2500Hz_DeadBandMode == PWM_2500Hz__B_PWM__DBM_256_CLOCKS || \
                PWM_2500Hz_DeadBandMode == PWM_2500Hz__B_PWM__DBM_2_4_CLOCKS)
                PWM_2500Hz_WriteDeadTime(PWM_2500Hz_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
            #if(PWM_2500Hz_KillModeMinTime)
                PWM_2500Hz_WriteKillTime(PWM_2500Hz_backup.PWMKillCounterPeriod);
            #endif /* (PWM_2500Hz_KillModeMinTime) */
            
            #if(PWM_2500Hz_UseControl)
                PWM_2500Hz_WriteControlRegister(PWM_2500Hz_backup.PWMControlRegister); 
            #endif /* (PWM_2500Hz_UseControl) */
        #endif  /* (!PWM_2500Hz_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_2500Hz_Sleep
********************************************************************************
* 
* Summary:
*  Disables block's operation and saves the user configuration. Should be called 
*  just prior to entering sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  PWM_2500Hz_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_2500Hz_Sleep(void) 
{
    #if(PWM_2500Hz_UseControl)
        if(PWM_2500Hz_CTRL_ENABLE == (PWM_2500Hz_CONTROL & PWM_2500Hz_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_2500Hz_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_2500Hz_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_2500Hz_UseControl) */

    /* Stop component */
    PWM_2500Hz_Stop();
    
    /* Save registers configuration */
    PWM_2500Hz_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_2500Hz_Wakeup
********************************************************************************
* 
* Summary:
*  Restores and enables the user configuration. Should be called just after 
*  awaking from sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  PWM_2500Hz_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_2500Hz_Wakeup(void) 
{
     /* Restore registers values */
    PWM_2500Hz_RestoreConfig();
    
    if(PWM_2500Hz_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_2500Hz_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
