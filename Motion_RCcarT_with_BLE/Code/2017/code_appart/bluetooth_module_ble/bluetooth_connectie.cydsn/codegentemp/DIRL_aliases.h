/*******************************************************************************
* File Name: DIRL.h  
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

#if !defined(CY_PINS_DIRL_ALIASES_H) /* Pins DIRL_ALIASES_H */
#define CY_PINS_DIRL_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DIRL_0			(DIRL__0__PC)
#define DIRL_0_PS		(DIRL__0__PS)
#define DIRL_0_PC		(DIRL__0__PC)
#define DIRL_0_DR		(DIRL__0__DR)
#define DIRL_0_SHIFT	(DIRL__0__SHIFT)
#define DIRL_0_INTR	((uint16)((uint16)0x0003u << (DIRL__0__SHIFT*2u)))

#define DIRL_INTR_ALL	 ((uint16)(DIRL_0_INTR))


#endif /* End Pins DIRL_ALIASES_H */


/* [] END OF FILE */
