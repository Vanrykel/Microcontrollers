/*******************************************************************************
* File Name: light_sensor.h  
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

#if !defined(CY_PINS_light_sensor_ALIASES_H) /* Pins light_sensor_ALIASES_H */
#define CY_PINS_light_sensor_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define light_sensor_0			(light_sensor__0__PC)
#define light_sensor_0_PS		(light_sensor__0__PS)
#define light_sensor_0_PC		(light_sensor__0__PC)
#define light_sensor_0_DR		(light_sensor__0__DR)
#define light_sensor_0_SHIFT	(light_sensor__0__SHIFT)
#define light_sensor_0_INTR	((uint16)((uint16)0x0003u << (light_sensor__0__SHIFT*2u)))

#define light_sensor_INTR_ALL	 ((uint16)(light_sensor_0_INTR))


#endif /* End Pins light_sensor_ALIASES_H */


/* [] END OF FILE */
