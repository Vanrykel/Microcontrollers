/*******************************************************************************
* File Name: PinUP.h  
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

#if !defined(CY_PINS_PinUP_ALIASES_H) /* Pins PinUP_ALIASES_H */
#define CY_PINS_PinUP_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PinUP_0			(PinUP__0__PC)
#define PinUP_0_PS		(PinUP__0__PS)
#define PinUP_0_PC		(PinUP__0__PC)
#define PinUP_0_DR		(PinUP__0__DR)
#define PinUP_0_SHIFT	(PinUP__0__SHIFT)
#define PinUP_0_INTR	((uint16)((uint16)0x0003u << (PinUP__0__SHIFT*2u)))

#define PinUP_INTR_ALL	 ((uint16)(PinUP_0_INTR))


#endif /* End Pins PinUP_ALIASES_H */


/* [] END OF FILE */
