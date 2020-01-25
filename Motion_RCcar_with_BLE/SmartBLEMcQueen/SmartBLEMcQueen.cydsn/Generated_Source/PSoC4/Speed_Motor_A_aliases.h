/*******************************************************************************
* File Name: Speed_Motor_A.h  
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

#if !defined(CY_PINS_Speed_Motor_A_ALIASES_H) /* Pins Speed_Motor_A_ALIASES_H */
#define CY_PINS_Speed_Motor_A_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Speed_Motor_A_0			(Speed_Motor_A__0__PC)
#define Speed_Motor_A_0_PS		(Speed_Motor_A__0__PS)
#define Speed_Motor_A_0_PC		(Speed_Motor_A__0__PC)
#define Speed_Motor_A_0_DR		(Speed_Motor_A__0__DR)
#define Speed_Motor_A_0_SHIFT	(Speed_Motor_A__0__SHIFT)
#define Speed_Motor_A_0_INTR	((uint16)((uint16)0x0003u << (Speed_Motor_A__0__SHIFT*2u)))

#define Speed_Motor_A_INTR_ALL	 ((uint16)(Speed_Motor_A_0_INTR))


#endif /* End Pins Speed_Motor_A_ALIASES_H */


/* [] END OF FILE */
