/*******************************************************************************
* File Name: tickrate.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_tickrate_H)
#define CY_ISR_tickrate_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void tickrate_Start(void);
void tickrate_StartEx(cyisraddress address);
void tickrate_Stop(void);

CY_ISR_PROTO(tickrate_Interrupt);

void tickrate_SetVector(cyisraddress address);
cyisraddress tickrate_GetVector(void);

void tickrate_SetPriority(uint8 priority);
uint8 tickrate_GetPriority(void);

void tickrate_Enable(void);
uint8 tickrate_GetState(void);
void tickrate_Disable(void);

void tickrate_SetPending(void);
void tickrate_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the tickrate ISR. */
#define tickrate_INTC_VECTOR            ((reg32 *) tickrate__INTC_VECT)

/* Address of the tickrate ISR priority. */
#define tickrate_INTC_PRIOR             ((reg32 *) tickrate__INTC_PRIOR_REG)

/* Priority of the tickrate interrupt. */
#define tickrate_INTC_PRIOR_NUMBER      tickrate__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable tickrate interrupt. */
#define tickrate_INTC_SET_EN            ((reg32 *) tickrate__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the tickrate interrupt. */
#define tickrate_INTC_CLR_EN            ((reg32 *) tickrate__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the tickrate interrupt state to pending. */
#define tickrate_INTC_SET_PD            ((reg32 *) tickrate__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the tickrate interrupt. */
#define tickrate_INTC_CLR_PD            ((reg32 *) tickrate__INTC_CLR_PD_REG)



#endif /* CY_ISR_tickrate_H */


/* [] END OF FILE */
