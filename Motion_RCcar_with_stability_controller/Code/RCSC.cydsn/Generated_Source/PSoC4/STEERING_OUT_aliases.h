/*******************************************************************************
* File Name: STEERING_OUT.h  
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

#if !defined(CY_PINS_STEERING_OUT_ALIASES_H) /* Pins STEERING_OUT_ALIASES_H */
#define CY_PINS_STEERING_OUT_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define STEERING_OUT_0			(STEERING_OUT__0__PC)
#define STEERING_OUT_0_PS		(STEERING_OUT__0__PS)
#define STEERING_OUT_0_PC		(STEERING_OUT__0__PC)
#define STEERING_OUT_0_DR		(STEERING_OUT__0__DR)
#define STEERING_OUT_0_SHIFT	(STEERING_OUT__0__SHIFT)
#define STEERING_OUT_0_INTR	((uint16)((uint16)0x0003u << (STEERING_OUT__0__SHIFT*2u)))

#define STEERING_OUT_INTR_ALL	 ((uint16)(STEERING_OUT_0_INTR))


#endif /* End Pins STEERING_OUT_ALIASES_H */


/* [] END OF FILE */
