/*******************************************************************************
* File Name: BLE_ConnectionLED.h  
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

#if !defined(CY_PINS_BLE_ConnectionLED_ALIASES_H) /* Pins BLE_ConnectionLED_ALIASES_H */
#define CY_PINS_BLE_ConnectionLED_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define BLE_ConnectionLED_0			(BLE_ConnectionLED__0__PC)
#define BLE_ConnectionLED_0_PS		(BLE_ConnectionLED__0__PS)
#define BLE_ConnectionLED_0_PC		(BLE_ConnectionLED__0__PC)
#define BLE_ConnectionLED_0_DR		(BLE_ConnectionLED__0__DR)
#define BLE_ConnectionLED_0_SHIFT	(BLE_ConnectionLED__0__SHIFT)
#define BLE_ConnectionLED_0_INTR	((uint16)((uint16)0x0003u << (BLE_ConnectionLED__0__SHIFT*2u)))

#define BLE_ConnectionLED_INTR_ALL	 ((uint16)(BLE_ConnectionLED_0_INTR))


#endif /* End Pins BLE_ConnectionLED_ALIASES_H */


/* [] END OF FILE */
