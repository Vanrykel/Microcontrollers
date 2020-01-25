/*******************************************************************************
* File Name: BTTNUP.h
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
#if !defined(CY_ISR_BTTNUP_H)
#define CY_ISR_BTTNUP_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void BTTNUP_Start(void);
void BTTNUP_StartEx(cyisraddress address);
void BTTNUP_Stop(void);

CY_ISR_PROTO(BTTNUP_Interrupt);

void BTTNUP_SetVector(cyisraddress address);
cyisraddress BTTNUP_GetVector(void);

void BTTNUP_SetPriority(uint8 priority);
uint8 BTTNUP_GetPriority(void);

void BTTNUP_Enable(void);
uint8 BTTNUP_GetState(void);
void BTTNUP_Disable(void);

void BTTNUP_SetPending(void);
void BTTNUP_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the BTTNUP ISR. */
#define BTTNUP_INTC_VECTOR            ((reg32 *) BTTNUP__INTC_VECT)

/* Address of the BTTNUP ISR priority. */
#define BTTNUP_INTC_PRIOR             ((reg32 *) BTTNUP__INTC_PRIOR_REG)

/* Priority of the BTTNUP interrupt. */
#define BTTNUP_INTC_PRIOR_NUMBER      BTTNUP__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable BTTNUP interrupt. */
#define BTTNUP_INTC_SET_EN            ((reg32 *) BTTNUP__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the BTTNUP interrupt. */
#define BTTNUP_INTC_CLR_EN            ((reg32 *) BTTNUP__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the BTTNUP interrupt state to pending. */
#define BTTNUP_INTC_SET_PD            ((reg32 *) BTTNUP__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the BTTNUP interrupt. */
#define BTTNUP_INTC_CLR_PD            ((reg32 *) BTTNUP__INTC_CLR_PD_REG)



#endif /* CY_ISR_BTTNUP_H */


/* [] END OF FILE */
