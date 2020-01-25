/*******************************************************************************
* File Name: yellow.h  
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

#if !defined(CY_PINS_yellow_ALIASES_H) /* Pins yellow_ALIASES_H */
#define CY_PINS_yellow_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define yellow_0			(yellow__0__PC)
#define yellow_0_PS		(yellow__0__PS)
#define yellow_0_PC		(yellow__0__PC)
#define yellow_0_DR		(yellow__0__DR)
#define yellow_0_SHIFT	(yellow__0__SHIFT)
#define yellow_0_INTR	((uint16)((uint16)0x0003u << (yellow__0__SHIFT*2u)))

#define yellow_INTR_ALL	 ((uint16)(yellow_0_INTR))


#endif /* End Pins yellow_ALIASES_H */


/* [] END OF FILE */
