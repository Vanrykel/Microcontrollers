/*******************************************************************************
* File Name: encoderInputLeft.h  
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

#if !defined(CY_PINS_encoderInputLeft_ALIASES_H) /* Pins encoderInputLeft_ALIASES_H */
#define CY_PINS_encoderInputLeft_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define encoderInputLeft_0			(encoderInputLeft__0__PC)
#define encoderInputLeft_0_PS		(encoderInputLeft__0__PS)
#define encoderInputLeft_0_PC		(encoderInputLeft__0__PC)
#define encoderInputLeft_0_DR		(encoderInputLeft__0__DR)
#define encoderInputLeft_0_SHIFT	(encoderInputLeft__0__SHIFT)
#define encoderInputLeft_0_INTR	((uint16)((uint16)0x0003u << (encoderInputLeft__0__SHIFT*2u)))

#define encoderInputLeft_INTR_ALL	 ((uint16)(encoderInputLeft_0_INTR))


#endif /* End Pins encoderInputLeft_ALIASES_H */


/* [] END OF FILE */
