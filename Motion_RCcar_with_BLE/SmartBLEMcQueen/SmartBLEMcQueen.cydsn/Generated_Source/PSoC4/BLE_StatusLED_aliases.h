/*******************************************************************************
* File Name: BLE_StatusLED.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BLE_StatusLED_ALIASES_H) /* Pins BLE_StatusLED_ALIASES_H */
#define CY_PINS_BLE_StatusLED_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define BLE_StatusLED_0			(BLE_StatusLED__0__PC)
#define BLE_StatusLED_0_PS		(BLE_StatusLED__0__PS)
#define BLE_StatusLED_0_PC		(BLE_StatusLED__0__PC)
#define BLE_StatusLED_0_DR		(BLE_StatusLED__0__DR)
#define BLE_StatusLED_0_SHIFT	(BLE_StatusLED__0__SHIFT)
#define BLE_StatusLED_0_INTR	((uint16)((uint16)0x0003u << (BLE_StatusLED__0__SHIFT*2u)))

#define BLE_StatusLED_INTR_ALL	 ((uint16)(BLE_StatusLED_0_INTR))


#endif /* End Pins BLE_StatusLED_ALIASES_H */


/* [] END OF FILE */
