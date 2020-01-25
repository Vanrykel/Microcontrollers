/*******************************************************************************
* File Name: SPEEDR.h  
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

#if !defined(CY_PINS_SPEEDR_ALIASES_H) /* Pins SPEEDR_ALIASES_H */
#define CY_PINS_SPEEDR_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define SPEEDR_0			(SPEEDR__0__PC)
#define SPEEDR_0_PS		(SPEEDR__0__PS)
#define SPEEDR_0_PC		(SPEEDR__0__PC)
#define SPEEDR_0_DR		(SPEEDR__0__DR)
#define SPEEDR_0_SHIFT	(SPEEDR__0__SHIFT)
#define SPEEDR_0_INTR	((uint16)((uint16)0x0003u << (SPEEDR__0__SHIFT*2u)))

#define SPEEDR_INTR_ALL	 ((uint16)(SPEEDR_0_INTR))


#endif /* End Pins SPEEDR_ALIASES_H */


/* [] END OF FILE */
