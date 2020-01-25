/*******************************************************************************
* File Name: LATCH.h  
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

#if !defined(CY_PINS_LATCH_ALIASES_H) /* Pins LATCH_ALIASES_H */
#define CY_PINS_LATCH_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LATCH_0			(LATCH__0__PC)
#define LATCH_0_PS		(LATCH__0__PS)
#define LATCH_0_PC		(LATCH__0__PC)
#define LATCH_0_DR		(LATCH__0__DR)
#define LATCH_0_SHIFT	(LATCH__0__SHIFT)
#define LATCH_0_INTR	((uint16)((uint16)0x0003u << (LATCH__0__SHIFT*2u)))

#define LATCH_INTR_ALL	 ((uint16)(LATCH_0_INTR))


#endif /* End Pins LATCH_ALIASES_H */


/* [] END OF FILE */
