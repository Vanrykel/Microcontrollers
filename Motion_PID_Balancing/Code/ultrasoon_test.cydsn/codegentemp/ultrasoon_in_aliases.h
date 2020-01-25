/*******************************************************************************
* File Name: ultrasoon_in.h  
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

#if !defined(CY_PINS_ultrasoon_in_ALIASES_H) /* Pins ultrasoon_in_ALIASES_H */
#define CY_PINS_ultrasoon_in_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ultrasoon_in_0			(ultrasoon_in__0__PC)
#define ultrasoon_in_0_PS		(ultrasoon_in__0__PS)
#define ultrasoon_in_0_PC		(ultrasoon_in__0__PC)
#define ultrasoon_in_0_DR		(ultrasoon_in__0__DR)
#define ultrasoon_in_0_SHIFT	(ultrasoon_in__0__SHIFT)
#define ultrasoon_in_0_INTR	((uint16)((uint16)0x0003u << (ultrasoon_in__0__SHIFT*2u)))

#define ultrasoon_in_INTR_ALL	 ((uint16)(ultrasoon_in_0_INTR))


#endif /* End Pins ultrasoon_in_ALIASES_H */


/* [] END OF FILE */
