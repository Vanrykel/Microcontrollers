/*******************************************************************************
* File Name: ledLeft.h  
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

#if !defined(CY_PINS_ledLeft_ALIASES_H) /* Pins ledLeft_ALIASES_H */
#define CY_PINS_ledLeft_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ledLeft_0			(ledLeft__0__PC)
#define ledLeft_0_PS		(ledLeft__0__PS)
#define ledLeft_0_PC		(ledLeft__0__PC)
#define ledLeft_0_DR		(ledLeft__0__DR)
#define ledLeft_0_SHIFT	(ledLeft__0__SHIFT)
#define ledLeft_0_INTR	((uint16)((uint16)0x0003u << (ledLeft__0__SHIFT*2u)))

#define ledLeft_INTR_ALL	 ((uint16)(ledLeft_0_INTR))


#endif /* End Pins ledLeft_ALIASES_H */


/* [] END OF FILE */
