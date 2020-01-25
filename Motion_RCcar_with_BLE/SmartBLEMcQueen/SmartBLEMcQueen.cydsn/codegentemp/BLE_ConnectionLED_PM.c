/*******************************************************************************
* File Name: BLE_ConnectionLED.c  
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
#include "BLE_ConnectionLED.h"

static BLE_ConnectionLED_BACKUP_STRUCT  BLE_ConnectionLED_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: BLE_ConnectionLED_Sleep
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
*  \snippet BLE_ConnectionLED_SUT.c usage_BLE_ConnectionLED_Sleep_Wakeup
*******************************************************************************/
void BLE_ConnectionLED_Sleep(void)
{
    #if defined(BLE_ConnectionLED__PC)
        BLE_ConnectionLED_backup.pcState = BLE_ConnectionLED_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            BLE_ConnectionLED_backup.usbState = BLE_ConnectionLED_CR1_REG;
            BLE_ConnectionLED_USB_POWER_REG |= BLE_ConnectionLED_USBIO_ENTER_SLEEP;
            BLE_ConnectionLED_CR1_REG &= BLE_ConnectionLED_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(BLE_ConnectionLED__SIO)
        BLE_ConnectionLED_backup.sioState = BLE_ConnectionLED_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        BLE_ConnectionLED_SIO_REG &= (uint32)(~BLE_ConnectionLED_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: BLE_ConnectionLED_Wakeup
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
*  Refer to BLE_ConnectionLED_Sleep() for an example usage.
*******************************************************************************/
void BLE_ConnectionLED_Wakeup(void)
{
    #if defined(BLE_ConnectionLED__PC)
        BLE_ConnectionLED_PC = BLE_ConnectionLED_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            BLE_ConnectionLED_USB_POWER_REG &= BLE_ConnectionLED_USBIO_EXIT_SLEEP_PH1;
            BLE_ConnectionLED_CR1_REG = BLE_ConnectionLED_backup.usbState;
            BLE_ConnectionLED_USB_POWER_REG &= BLE_ConnectionLED_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(BLE_ConnectionLED__SIO)
        BLE_ConnectionLED_SIO_REG = BLE_ConnectionLED_backup.sioState;
    #endif
}


/* [] END OF FILE */
