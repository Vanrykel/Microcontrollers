/*******************************************************************************
* File Name: ultrasoon_out.h  
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

#if !defined(CY_PINS_ultrasoon_out_ALIASES_H) /* Pins ultrasoon_out_ALIASES_H */
#define CY_PINS_ultrasoon_out_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ultrasoon_out_0			(ultrasoon_out__0__PC)
#define ultrasoon_out_0_PS		(ultrasoon_out__0__PS)
#define ultrasoon_out_0_PC		(ultrasoon_out__0__PC)
#define ultrasoon_out_0_DR		(ultrasoon_out__0__DR)
#define ultrasoon_out_0_SHIFT	(ultrasoon_out__0__SHIFT)
#define ultrasoon_out_0_INTR	((uint16)((uint16)0x0003u << (ultrasoon_out__0__SHIFT*2u)))

#define ultrasoon_out_INTR_ALL	 ((uint16)(ultrasoon_out_0_INTR))


#endif /* End Pins ultrasoon_out_ALIASES_H */


/* [] END OF FILE */
