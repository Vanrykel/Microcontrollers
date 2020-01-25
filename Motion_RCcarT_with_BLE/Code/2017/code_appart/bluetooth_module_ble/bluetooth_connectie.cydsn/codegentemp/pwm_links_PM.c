/*******************************************************************************
* File Name: pwm_links_PM.c
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

#include "pwm_links.h"

static pwm_links_backupStruct pwm_links_backup;


/*******************************************************************************
* Function Name: pwm_links_SaveConfig
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
*  pwm_links_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void pwm_links_SaveConfig(void) 
{

    #if(!pwm_links_UsingFixedFunction)
        #if(!pwm_links_PWMModeIsCenterAligned)
            pwm_links_backup.PWMPeriod = pwm_links_ReadPeriod();
        #endif /* (!pwm_links_PWMModeIsCenterAligned) */
        pwm_links_backup.PWMUdb = pwm_links_ReadCounter();
        #if (pwm_links_UseStatus)
            pwm_links_backup.InterruptMaskValue = pwm_links_STATUS_MASK;
        #endif /* (pwm_links_UseStatus) */

        #if(pwm_links_DeadBandMode == pwm_links__B_PWM__DBM_256_CLOCKS || \
            pwm_links_DeadBandMode == pwm_links__B_PWM__DBM_2_4_CLOCKS)
            pwm_links_backup.PWMdeadBandValue = pwm_links_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(pwm_links_KillModeMinTime)
             pwm_links_backup.PWMKillCounterPeriod = pwm_links_ReadKillTime();
        #endif /* (pwm_links_KillModeMinTime) */

        #if(pwm_links_UseControl)
            pwm_links_backup.PWMControlRegister = pwm_links_ReadControlRegister();
        #endif /* (pwm_links_UseControl) */
    #endif  /* (!pwm_links_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: pwm_links_RestoreConfig
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
*  pwm_links_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void pwm_links_RestoreConfig(void) 
{
        #if(!pwm_links_UsingFixedFunction)
            #if(!pwm_links_PWMModeIsCenterAligned)
                pwm_links_WritePeriod(pwm_links_backup.PWMPeriod);
            #endif /* (!pwm_links_PWMModeIsCenterAligned) */

            pwm_links_WriteCounter(pwm_links_backup.PWMUdb);

            #if (pwm_links_UseStatus)
                pwm_links_STATUS_MASK = pwm_links_backup.InterruptMaskValue;
            #endif /* (pwm_links_UseStatus) */

            #if(pwm_links_DeadBandMode == pwm_links__B_PWM__DBM_256_CLOCKS || \
                pwm_links_DeadBandMode == pwm_links__B_PWM__DBM_2_4_CLOCKS)
                pwm_links_WriteDeadTime(pwm_links_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(pwm_links_KillModeMinTime)
                pwm_links_WriteKillTime(pwm_links_backup.PWMKillCounterPeriod);
            #endif /* (pwm_links_KillModeMinTime) */

            #if(pwm_links_UseControl)
                pwm_links_WriteControlRegister(pwm_links_backup.PWMControlRegister);
            #endif /* (pwm_links_UseControl) */
        #endif  /* (!pwm_links_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: pwm_links_Sleep
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
*  pwm_links_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void pwm_links_Sleep(void) 
{
    #if(pwm_links_UseControl)
        if(pwm_links_CTRL_ENABLE == (pwm_links_CONTROL & pwm_links_CTRL_ENABLE))
        {
            /*Component is enabled */
            pwm_links_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            pwm_links_backup.PWMEnableState = 0u;
        }
    #endif /* (pwm_links_UseControl) */

    /* Stop component */
    pwm_links_Stop();

    /* Save registers configuration */
    pwm_links_SaveConfig();
}


/*******************************************************************************
* Function Name: pwm_links_Wakeup
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
*  pwm_links_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void pwm_links_Wakeup(void) 
{
     /* Restore registers values */
    pwm_links_RestoreConfig();

    if(pwm_links_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        pwm_links_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
