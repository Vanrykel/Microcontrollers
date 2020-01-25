/*******************************************************************************
* File Name: BTTNDOWN_P2.h
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
#if !defined(CY_ISR_BTTNDOWN_P2_H)
#define CY_ISR_BTTNDOWN_P2_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void BTTNDOWN_P2_Start(void);
void BTTNDOWN_P2_StartEx(cyisraddress address);
void BTTNDOWN_P2_Stop(void);

CY_ISR_PROTO(BTTNDOWN_P2_Interrupt);

void BTTNDOWN_P2_SetVector(cyisraddress address);
cyisraddress BTTNDOWN_P2_GetVector(void);

void BTTNDOWN_P2_SetPriority(uint8 priority);
uint8 BTTNDOWN_P2_GetPriority(void);

void BTTNDOWN_P2_Enable(void);
uint8 BTTNDOWN_P2_GetState(void);
void BTTNDOWN_P2_Disable(void);

void BTTNDOWN_P2_SetPending(void);
void BTTNDOWN_P2_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the BTTNDOWN_P2 ISR. */
#define BTTNDOWN_P2_INTC_VECTOR            ((reg32 *) BTTNDOWN_P2__INTC_VECT)

/* Address of the BTTNDOWN_P2 ISR priority. */
#define BTTNDOWN_P2_INTC_PRIOR             ((reg32 *) BTTNDOWN_P2__INTC_PRIOR_REG)

/* Priority of the BTTNDOWN_P2 interrupt. */
#define BTTNDOWN_P2_INTC_PRIOR_NUMBER      BTTNDOWN_P2__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable BTTNDOWN_P2 interrupt. */
#define BTTNDOWN_P2_INTC_SET_EN            ((reg32 *) BTTNDOWN_P2__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the BTTNDOWN_P2 interrupt. */
#define BTTNDOWN_P2_INTC_CLR_EN            ((reg32 *) BTTNDOWN_P2__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the BTTNDOWN_P2 interrupt state to pending. */
#define BTTNDOWN_P2_INTC_SET_PD            ((reg32 *) BTTNDOWN_P2__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the BTTNDOWN_P2 interrupt. */
#define BTTNDOWN_P2_INTC_CLR_PD            ((reg32 *) BTTNDOWN_P2__INTC_CLR_PD_REG)



#endif /* CY_ISR_BTTNDOWN_P2_H */


/* [] END OF FILE */
