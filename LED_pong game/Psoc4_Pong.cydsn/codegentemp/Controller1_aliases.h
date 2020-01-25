/*******************************************************************************
* File Name: Controller1.h  
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

#if !defined(CY_PINS_Controller1_ALIASES_H) /* Pins Controller1_ALIASES_H */
#define CY_PINS_Controller1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Controller1_0			(Controller1__0__PC)
#define Controller1_0_PS		(Controller1__0__PS)
#define Controller1_0_PC		(Controller1__0__PC)
#define Controller1_0_DR		(Controller1__0__DR)
#define Controller1_0_SHIFT	(Controller1__0__SHIFT)
#define Controller1_0_INTR	((uint16)((uint16)0x0003u << (Controller1__0__SHIFT*2u)))

#define Controller1_INTR_ALL	 ((uint16)(Controller1_0_INTR))


#endif /* End Pins Controller1_ALIASES_H */


/* [] END OF FILE */
