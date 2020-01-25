/*******************************************************************************
* File Name: UltraSone_2_Trig.c  
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
#include "UltraSone_2_Trig.h"

static UltraSone_2_Trig_BACKUP_STRUCT  UltraSone_2_Trig_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: UltraSone_2_Trig_Sleep
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
*  \snippet UltraSone_2_Trig_SUT.c usage_UltraSone_2_Trig_Sleep_Wakeup
*******************************************************************************/
void UltraSone_2_Trig_Sleep(void)
{
    #if defined(UltraSone_2_Trig__PC)
        UltraSone_2_Trig_backup.pcState = UltraSone_2_Trig_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            UltraSone_2_Trig_backup.usbState = UltraSone_2_Trig_CR1_REG;
            UltraSone_2_Trig_USB_POWER_REG |= UltraSone_2_Trig_USBIO_ENTER_SLEEP;
            UltraSone_2_Trig_CR1_REG &= UltraSone_2_Trig_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(UltraSone_2_Trig__SIO)
        UltraSone_2_Trig_backup.sioState = UltraSone_2_Trig_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        UltraSone_2_Trig_SIO_REG &= (uint32)(~UltraSone_2_Trig_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: UltraSone_2_Trig_Wakeup
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
*  Refer to UltraSone_2_Trig_Sleep() for an example usage.
*******************************************************************************/
void UltraSone_2_Trig_Wakeup(void)
{
    #if defined(UltraSone_2_Trig__PC)
        UltraSone_2_Trig_PC = UltraSone_2_Trig_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            UltraSone_2_Trig_USB_POWER_REG &= UltraSone_2_Trig_USBIO_EXIT_SLEEP_PH1;
            UltraSone_2_Trig_CR1_REG = UltraSone_2_Trig_backup.usbState;
            UltraSone_2_Trig_USB_POWER_REG &= UltraSone_2_Trig_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(UltraSone_2_Trig__SIO)
        UltraSone_2_Trig_SIO_REG = UltraSone_2_Trig_backup.sioState;
    #endif
}


/* [] END OF FILE */
