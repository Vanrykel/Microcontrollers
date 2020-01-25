/*******************************************************************************
* File Name: BTTNDOWN.h
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
#if !defined(CY_ISR_BTTNDOWN_H)
#define CY_ISR_BTTNDOWN_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void BTTNDOWN_Start(void);
void BTTNDOWN_StartEx(cyisraddress address);
void BTTNDOWN_Stop(void);

CY_ISR_PROTO(BTTNDOWN_Interrupt);

void BTTNDOWN_SetVector(cyisraddress address);
cyisraddress BTTNDOWN_GetVector(void);

void BTTNDOWN_SetPriority(uint8 priority);
uint8 BTTNDOWN_GetPriority(void);

void BTTNDOWN_Enable(void);
uint8 BTTNDOWN_GetState(void);
void BTTNDOWN_Disable(void);

void BTTNDOWN_SetPending(void);
void BTTNDOWN_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the BTTNDOWN ISR. */
#define BTTNDOWN_INTC_VECTOR            ((reg32 *) BTTNDOWN__INTC_VECT)

/* Address of the BTTNDOWN ISR priority. */
#define BTTNDOWN_INTC_PRIOR             ((reg32 *) BTTNDOWN__INTC_PRIOR_REG)

/* Priority of the BTTNDOWN interrupt. */
#define BTTNDOWN_INTC_PRIOR_NUMBER      BTTNDOWN__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable BTTNDOWN interrupt. */
#define BTTNDOWN_INTC_SET_EN            ((reg32 *) BTTNDOWN__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the BTTNDOWN interrupt. */
#define BTTNDOWN_INTC_CLR_EN            ((reg32 *) BTTNDOWN__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the BTTNDOWN interrupt state to pending. */
#define BTTNDOWN_INTC_SET_PD            ((reg32 *) BTTNDOWN__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the BTTNDOWN interrupt. */
#define BTTNDOWN_INTC_CLR_PD            ((reg32 *) BTTNDOWN__INTC_CLR_PD_REG)



#endif /* CY_ISR_BTTNDOWN_H */


/* [] END OF FILE */
