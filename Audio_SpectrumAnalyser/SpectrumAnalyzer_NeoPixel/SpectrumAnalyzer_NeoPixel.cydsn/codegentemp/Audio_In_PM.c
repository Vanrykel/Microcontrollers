/*******************************************************************************
* File Name: Audio_In.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Audio_In.h"

static Audio_In_BACKUP_STRUCT  Audio_In_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Audio_In_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Audio_In_SUT.c usage_Audio_In_Sleep_Wakeup
*******************************************************************************/
void Audio_In_Sleep(void)
{
    #if defined(Audio_In__PC)
        Audio_In_backup.pcState = Audio_In_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Audio_In_backup.usbState = Audio_In_CR1_REG;
            Audio_In_USB_POWER_REG |= Audio_In_USBIO_ENTER_SLEEP;
            Audio_In_CR1_REG &= Audio_In_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Audio_In__SIO)
        Audio_In_backup.sioState = Audio_In_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Audio_In_SIO_REG &= (uint32)(~Audio_In_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Audio_In_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Audio_In_Sleep() for an example usage.
*******************************************************************************/
void Audio_In_Wakeup(void)
{
    #if defined(Audio_In__PC)
        Audio_In_PC = Audio_In_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Audio_In_USB_POWER_REG &= Audio_In_USBIO_EXIT_SLEEP_PH1;
            Audio_In_CR1_REG = Audio_In_backup.usbState;
            Audio_In_USB_POWER_REG &= Audio_In_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Audio_In__SIO)
        Audio_In_SIO_REG = Audio_In_backup.sioState;
    #endif
}


/* [] END OF FILE */
