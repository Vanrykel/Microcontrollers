/*******************************************************************************
* File Name: PinDOWN.h  
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

#if !defined(CY_PINS_PinDOWN_ALIASES_H) /* Pins PinDOWN_ALIASES_H */
#define CY_PINS_PinDOWN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PinDOWN_0			(PinDOWN__0__PC)
#define PinDOWN_0_PS		(PinDOWN__0__PS)
#define PinDOWN_0_PC		(PinDOWN__0__PC)
#define PinDOWN_0_DR		(PinDOWN__0__DR)
#define PinDOWN_0_SHIFT	(PinDOWN__0__SHIFT)
#define PinDOWN_0_INTR	((uint16)((uint16)0x0003u << (PinDOWN__0__SHIFT*2u)))

#define PinDOWN_INTR_ALL	 ((uint16)(PinDOWN_0_INTR))


#endif /* End Pins PinDOWN_ALIASES_H */


/* [] END OF FILE */
