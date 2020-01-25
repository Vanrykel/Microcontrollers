/*******************************************************************************
* File Name: DIRR.h  
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

#if !defined(CY_PINS_DIRR_ALIASES_H) /* Pins DIRR_ALIASES_H */
#define CY_PINS_DIRR_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DIRR_0			(DIRR__0__PC)
#define DIRR_0_PS		(DIRR__0__PS)
#define DIRR_0_PC		(DIRR__0__PC)
#define DIRR_0_DR		(DIRR__0__DR)
#define DIRR_0_SHIFT	(DIRR__0__SHIFT)
#define DIRR_0_INTR	((uint16)((uint16)0x0003u << (DIRR__0__SHIFT*2u)))

#define DIRR_INTR_ALL	 ((uint16)(DIRR_0_INTR))


#endif /* End Pins DIRR_ALIASES_H */


/* [] END OF FILE */
