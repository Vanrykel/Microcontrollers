/*******************************************************************************
* File Name: pwm_rechts_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "pwm_rechts.h"

static pwm_rechts_backupStruct pwm_rechts_backup;


/*******************************************************************************
* Function Name: pwm_rechts_SaveConfig
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
*  pwm_rechts_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void pwm_rechts_SaveConfig(void) 
{

    #if(!pwm_rechts_UsingFixedFunction)
        #if(!pwm_rechts_PWMModeIsCenterAligned)
            pwm_rechts_backup.PWMPeriod = pwm_rechts_ReadPeriod();
        #endif /* (!pwm_rechts_PWMModeIsCenterAligned) */
        pwm_rechts_backup.PWMUdb = pwm_rechts_ReadCounter();
        #if (pwm_rechts_UseStatus)
            pwm_rechts_backup.InterruptMaskValue = pwm_rechts_STATUS_MASK;
        #endif /* (pwm_rechts_UseStatus) */

        #if(pwm_rechts_DeadBandMode == pwm_rechts__B_PWM__DBM_256_CLOCKS || \
            pwm_rechts_DeadBandMode == pwm_rechts__B_PWM__DBM_2_4_CLOCKS)
            pwm_rechts_backup.PWMdeadBandValue = pwm_rechts_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(pwm_rechts_KillModeMinTime)
             pwm_rechts_backup.PWMKillCounterPeriod = pwm_rechts_ReadKillTime();
        #endif /* (pwm_rechts_KillModeMinTime) */

        #if(pwm_rechts_UseControl)
            pwm_rechts_backup.PWMControlRegister = pwm_rechts_ReadControlRegister();
        #endif /* (pwm_rechts_UseControl) */
    #endif  /* (!pwm_rechts_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: pwm_rechts_RestoreConfig
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
*  pwm_rechts_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void pwm_rechts_RestoreConfig(void) 
{
        #if(!pwm_rechts_UsingFixedFunction)
            #if(!pwm_rechts_PWMModeIsCenterAligned)
                pwm_rechts_WritePeriod(pwm_rechts_backup.PWMPeriod);
            #endif /* (!pwm_rechts_PWMModeIsCenterAligned) */

            pwm_rechts_WriteCounter(pwm_rechts_backup.PWMUdb);

            #if (pwm_rechts_UseStatus)
                pwm_rechts_STATUS_MASK = pwm_rechts_backup.InterruptMaskValue;
            #endif /* (pwm_rechts_UseStatus) */

            #if(pwm_rechts_DeadBandMode == pwm_rechts__B_PWM__DBM_256_CLOCKS || \
                pwm_rechts_DeadBandMode == pwm_rechts__B_PWM__DBM_2_4_CLOCKS)
                pwm_rechts_WriteDeadTime(pwm_rechts_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(pwm_rechts_KillModeMinTime)
                pwm_rechts_WriteKillTime(pwm_rechts_backup.PWMKillCounterPeriod);
            #endif /* (pwm_rechts_KillModeMinTime) */

            #if(pwm_rechts_UseControl)
                pwm_rechts_WriteControlRegister(pwm_rechts_backup.PWMControlRegister);
            #endif /* (pwm_rechts_UseControl) */
        #endif  /* (!pwm_rechts_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: pwm_rechts_Sleep
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
*  pwm_rechts_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void pwm_rechts_Sleep(void) 
{
    #if(pwm_rechts_UseControl)
        if(pwm_rechts_CTRL_ENABLE == (pwm_rechts_CONTROL & pwm_rechts_CTRL_ENABLE))
        {
            /*Component is enabled */
            pwm_rechts_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            pwm_rechts_backup.PWMEnableState = 0u;
        }
    #endif /* (pwm_rechts_UseControl) */

    /* Stop component */
    pwm_rechts_Stop();

    /* Save registers configuration */
    pwm_rechts_SaveConfig();
}


/*******************************************************************************
* Function Name: pwm_rechts_Wakeup
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
*  pwm_rechts_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void pwm_rechts_Wakeup(void) 
{
     /* Restore registers values */
    pwm_rechts_RestoreConfig();

    if(pwm_rechts_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        pwm_rechts_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
