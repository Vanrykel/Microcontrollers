/*******************************************************************************
* File Name: ledOutput.h  
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

#if !defined(CY_PINS_ledOutput_ALIASES_H) /* Pins ledOutput_ALIASES_H */
#define CY_PINS_ledOutput_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ledOutput_0			(ledOutput__0__PC)
#define ledOutput_0_PS		(ledOutput__0__PS)
#define ledOutput_0_PC		(ledOutput__0__PC)
#define ledOutput_0_DR		(ledOutput__0__DR)
#define ledOutput_0_SHIFT	(ledOutput__0__SHIFT)
#define ledOutput_0_INTR	((uint16)((uint16)0x0003u << (ledOutput__0__SHIFT*2u)))

#define ledOutput_INTR_ALL	 ((uint16)(ledOutput_0_INTR))


#endif /* End Pins ledOutput_ALIASES_H */


/* [] END OF FILE */
