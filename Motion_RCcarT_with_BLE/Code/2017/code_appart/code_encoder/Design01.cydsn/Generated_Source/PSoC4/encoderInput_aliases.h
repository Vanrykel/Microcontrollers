/*******************************************************************************
* File Name: encoderInput.h  
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

#if !defined(CY_PINS_encoderInput_ALIASES_H) /* Pins encoderInput_ALIASES_H */
#define CY_PINS_encoderInput_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define encoderInput_0			(encoderInput__0__PC)
#define encoderInput_0_PS		(encoderInput__0__PS)
#define encoderInput_0_PC		(encoderInput__0__PC)
#define encoderInput_0_DR		(encoderInput__0__DR)
#define encoderInput_0_SHIFT	(encoderInput__0__SHIFT)
#define encoderInput_0_INTR	((uint16)((uint16)0x0003u << (encoderInput__0__SHIFT*2u)))

#define encoderInput_INTR_ALL	 ((uint16)(encoderInput_0_INTR))


#endif /* End Pins encoderInput_ALIASES_H */


/* [] END OF FILE */
