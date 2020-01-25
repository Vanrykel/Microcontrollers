/*******************************************************************************
* File Name: isr_1_L.h
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
#if !defined(CY_ISR_isr_1_L_H)
#define CY_ISR_isr_1_L_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_1_L_Start(void);
void isr_1_L_StartEx(cyisraddress address);
void isr_1_L_Stop(void);

CY_ISR_PROTO(isr_1_L_Interrupt);

void isr_1_L_SetVector(cyisraddress address);
cyisraddress isr_1_L_GetVector(void);

void isr_1_L_SetPriority(uint8 priority);
uint8 isr_1_L_GetPriority(void);

void isr_1_L_Enable(void);
uint8 isr_1_L_GetState(void);
void isr_1_L_Disable(void);

void isr_1_L_SetPending(void);
void isr_1_L_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_1_L ISR. */
#define isr_1_L_INTC_VECTOR            ((reg32 *) isr_1_L__INTC_VECT)

/* Address of the isr_1_L ISR priority. */
#define isr_1_L_INTC_PRIOR             ((reg32 *) isr_1_L__INTC_PRIOR_REG)

/* Priority of the isr_1_L interrupt. */
#define isr_1_L_INTC_PRIOR_NUMBER      isr_1_L__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_1_L interrupt. */
#define isr_1_L_INTC_SET_EN            ((reg32 *) isr_1_L__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_1_L interrupt. */
#define isr_1_L_INTC_CLR_EN            ((reg32 *) isr_1_L__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_1_L interrupt state to pending. */
#define isr_1_L_INTC_SET_PD            ((reg32 *) isr_1_L__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_1_L interrupt. */
#define isr_1_L_INTC_CLR_PD            ((reg32 *) isr_1_L__INTC_CLR_PD_REG)



#endif /* CY_ISR_isr_1_L_H */


/* [] END OF FILE */
