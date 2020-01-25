/*******************************************************************************
* File Name: ledRight.h  
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

#if !defined(CY_PINS_ledRight_ALIASES_H) /* Pins ledRight_ALIASES_H */
#define CY_PINS_ledRight_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ledRight_0			(ledRight__0__PC)
#define ledRight_0_PS		(ledRight__0__PS)
#define ledRight_0_PC		(ledRight__0__PC)
#define ledRight_0_DR		(ledRight__0__DR)
#define ledRight_0_SHIFT	(ledRight__0__SHIFT)
#define ledRight_0_INTR	((uint16)((uint16)0x0003u << (ledRight__0__SHIFT*2u)))

#define ledRight_INTR_ALL	 ((uint16)(ledRight_0_INTR))


#endif /* End Pins ledRight_ALIASES_H */


/* [] END OF FILE */
