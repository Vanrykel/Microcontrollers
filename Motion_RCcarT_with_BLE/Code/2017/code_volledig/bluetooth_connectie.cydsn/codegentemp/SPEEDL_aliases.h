/*******************************************************************************
* File Name: SPEEDL.h  
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

#if !defined(CY_PINS_SPEEDL_ALIASES_H) /* Pins SPEEDL_ALIASES_H */
#define CY_PINS_SPEEDL_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define SPEEDL_0			(SPEEDL__0__PC)
#define SPEEDL_0_PS		(SPEEDL__0__PS)
#define SPEEDL_0_PC		(SPEEDL__0__PC)
#define SPEEDL_0_DR		(SPEEDL__0__DR)
#define SPEEDL_0_SHIFT	(SPEEDL__0__SHIFT)
#define SPEEDL_0_INTR	((uint16)((uint16)0x0003u << (SPEEDL__0__SHIFT*2u)))

#define SPEEDL_INTR_ALL	 ((uint16)(SPEEDL_0_INTR))


#endif /* End Pins SPEEDL_ALIASES_H */


/* [] END OF FILE */
