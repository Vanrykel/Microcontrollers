/*******************************************************************************
* File Name: PWM_1000Hz_PM.c
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
#include "PWM_1000Hz.h"

static PWM_1000Hz_backupStruct PWM_1000Hz_backup;


/*******************************************************************************
* Function Name: PWM_1000Hz_SaveConfig
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
*  PWM_1000Hz_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void PWM_1000Hz_SaveConfig(void) 
{
    
    #if(!PWM_1000Hz_UsingFixedFunction)
        #if(!PWM_1000Hz_PWMModeIsCenterAligned)
            PWM_1000Hz_backup.PWMPeriod = PWM_1000Hz_ReadPeriod();
        #endif /* (!PWM_1000Hz_PWMModeIsCenterAligned) */
        PWM_1000Hz_backup.PWMUdb = PWM_1000Hz_ReadCounter();
        #if (PWM_1000Hz_UseStatus)
            PWM_1000Hz_backup.InterruptMaskValue = PWM_1000Hz_STATUS_MASK;
        #endif /* (PWM_1000Hz_UseStatus) */
        
        #if(PWM_1000Hz_DeadBandMode == PWM_1000Hz__B_PWM__DBM_256_CLOCKS || \
            PWM_1000Hz_DeadBandMode == PWM_1000Hz__B_PWM__DBM_2_4_CLOCKS)
            PWM_1000Hz_backup.PWMdeadBandValue = PWM_1000Hz_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */
        
        #if(PWM_1000Hz_KillModeMinTime)
             PWM_1000Hz_backup.PWMKillCounterPeriod = PWM_1000Hz_ReadKillTime();
        #endif /* (PWM_1000Hz_KillModeMinTime) */
        
        #if(PWM_1000Hz_UseControl)
            PWM_1000Hz_backup.PWMControlRegister = PWM_1000Hz_ReadControlRegister();
        #endif /* (PWM_1000Hz_UseControl) */
    #endif  /* (!PWM_1000Hz_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_1000Hz_RestoreConfig
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
*  PWM_1000Hz_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_1000Hz_RestoreConfig(void) 
{
        #if(!PWM_1000Hz_UsingFixedFunction)
            #if(!PWM_1000Hz_PWMModeIsCenterAligned)
                PWM_1000Hz_WritePeriod(PWM_1000Hz_backup.PWMPeriod);
            #endif /* (!PWM_1000Hz_PWMModeIsCenterAligned) */
            PWM_1000Hz_WriteCounter(PWM_1000Hz_backup.PWMUdb);
            #if (PWM_1000Hz_UseStatus)
                PWM_1000Hz_STATUS_MASK = PWM_1000Hz_backup.InterruptMaskValue;
            #endif /* (PWM_1000Hz_UseStatus) */
            
            #if(PWM_1000Hz_DeadBandMode == PWM_1000Hz__B_PWM__DBM_256_CLOCKS || \
                PWM_1000Hz_DeadBandMode == PWM_1000Hz__B_PWM__DBM_2_4_CLOCKS)
                PWM_1000Hz_WriteDeadTime(PWM_1000Hz_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
            #if(PWM_1000Hz_KillModeMinTime)
                PWM_1000Hz_WriteKillTime(PWM_1000Hz_backup.PWMKillCounterPeriod);
            #endif /* (PWM_1000Hz_KillModeMinTime) */
            
            #if(PWM_1000Hz_UseControl)
                PWM_1000Hz_WriteControlRegister(PWM_1000Hz_backup.PWMControlRegister); 
            #endif /* (PWM_1000Hz_UseControl) */
        #endif  /* (!PWM_1000Hz_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_1000Hz_Sleep
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
*  PWM_1000Hz_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_1000Hz_Sleep(void) 
{
    #if(PWM_1000Hz_UseControl)
        if(PWM_1000Hz_CTRL_ENABLE == (PWM_1000Hz_CONTROL & PWM_1000Hz_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_1000Hz_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_1000Hz_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_1000Hz_UseControl) */

    /* Stop component */
    PWM_1000Hz_Stop();
    
    /* Save registers configuration */
    PWM_1000Hz_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_1000Hz_Wakeup
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
*  PWM_1000Hz_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_1000Hz_Wakeup(void) 
{
     /* Restore registers values */
    PWM_1000Hz_RestoreConfig();
    
    if(PWM_1000Hz_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_1000Hz_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
