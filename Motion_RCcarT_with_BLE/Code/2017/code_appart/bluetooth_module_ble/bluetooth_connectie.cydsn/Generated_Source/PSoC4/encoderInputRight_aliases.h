/*******************************************************************************
* File Name: encoderInputRight.h  
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

#if !defined(CY_PINS_encoderInputRight_ALIASES_H) /* Pins encoderInputRight_ALIASES_H */
#define CY_PINS_encoderInputRight_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define encoderInputRight_0			(encoderInputRight__0__PC)
#define encoderInputRight_0_PS		(encoderInputRight__0__PS)
#define encoderInputRight_0_PC		(encoderInputRight__0__PC)
#define encoderInputRight_0_DR		(encoderInputRight__0__DR)
#define encoderInputRight_0_SHIFT	(encoderInputRight__0__SHIFT)
#define encoderInputRight_0_INTR	((uint16)((uint16)0x0003u << (encoderInputRight__0__SHIFT*2u)))

#define encoderInputRight_INTR_ALL	 ((uint16)(encoderInputRight_0_INTR))


#endif /* End Pins encoderInputRight_ALIASES_H */


/* [] END OF FILE */
