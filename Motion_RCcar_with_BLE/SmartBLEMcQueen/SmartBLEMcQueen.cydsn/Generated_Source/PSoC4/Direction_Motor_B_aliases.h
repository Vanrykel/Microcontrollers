/*******************************************************************************
* File Name: Direction_Motor_B.h  
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

#if !defined(CY_PINS_Direction_Motor_B_ALIASES_H) /* Pins Direction_Motor_B_ALIASES_H */
#define CY_PINS_Direction_Motor_B_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Direction_Motor_B_0			(Direction_Motor_B__0__PC)
#define Direction_Motor_B_0_PS		(Direction_Motor_B__0__PS)
#define Direction_Motor_B_0_PC		(Direction_Motor_B__0__PC)
#define Direction_Motor_B_0_DR		(Direction_Motor_B__0__DR)
#define Direction_Motor_B_0_SHIFT	(Direction_Motor_B__0__SHIFT)
#define Direction_Motor_B_0_INTR	((uint16)((uint16)0x0003u << (Direction_Motor_B__0__SHIFT*2u)))

#define Direction_Motor_B_INTR_ALL	 ((uint16)(Direction_Motor_B_0_INTR))


#endif /* End Pins Direction_Motor_B_ALIASES_H */


/* [] END OF FILE */
