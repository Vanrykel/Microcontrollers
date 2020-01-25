/*******************************************************************************
* File Name: ledForward.h  
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

#if !defined(CY_PINS_ledForward_ALIASES_H) /* Pins ledForward_ALIASES_H */
#define CY_PINS_ledForward_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ledForward_0			(ledForward__0__PC)
#define ledForward_0_PS		(ledForward__0__PS)
#define ledForward_0_PC		(ledForward__0__PC)
#define ledForward_0_DR		(ledForward__0__DR)
#define ledForward_0_SHIFT	(ledForward__0__SHIFT)
#define ledForward_0_INTR	((uint16)((uint16)0x0003u << (ledForward__0__SHIFT*2u)))

#define ledForward_INTR_ALL	 ((uint16)(ledForward_0_INTR))


#endif /* End Pins ledForward_ALIASES_H */


/* [] END OF FILE */
