/*******************************************************************************
* File Name: SPEEDL.c  
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
#include "SPEEDL.h"

static SPEEDL_BACKUP_STRUCT  SPEEDL_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: SPEEDL_Sleep
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
*  \snippet SPEEDL_SUT.c usage_SPEEDL_Sleep_Wakeup
*******************************************************************************/
void SPEEDL_Sleep(void)
{
    #if defined(SPEEDL__PC)
        SPEEDL_backup.pcState = SPEEDL_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            SPEEDL_backup.usbState = SPEEDL_CR1_REG;
            SPEEDL_USB_POWER_REG |= SPEEDL_USBIO_ENTER_SLEEP;
            SPEEDL_CR1_REG &= SPEEDL_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SPEEDL__SIO)
        SPEEDL_backup.sioState = SPEEDL_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        SPEEDL_SIO_REG &= (uint32)(~SPEEDL_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: SPEEDL_Wakeup
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
*  Refer to SPEEDL_Sleep() for an example usage.
*******************************************************************************/
void SPEEDL_Wakeup(void)
{
    #if defined(SPEEDL__PC)
        SPEEDL_PC = SPEEDL_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            SPEEDL_USB_POWER_REG &= SPEEDL_USBIO_EXIT_SLEEP_PH1;
            SPEEDL_CR1_REG = SPEEDL_backup.usbState;
            SPEEDL_USB_POWER_REG &= SPEEDL_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SPEEDL__SIO)
        SPEEDL_SIO_REG = SPEEDL_backup.sioState;
    #endif
}


/* [] END OF FILE */
