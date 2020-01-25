/*******************************************************************************
* File Name: UltraSone_1_Echo_intr.h
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
#if !defined(CY_ISR_UltraSone_1_Echo_intr_H)
#define CY_ISR_UltraSone_1_Echo_intr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void UltraSone_1_Echo_intr_Start(void);
void UltraSone_1_Echo_intr_StartEx(cyisraddress address);
void UltraSone_1_Echo_intr_Stop(void);

CY_ISR_PROTO(UltraSone_1_Echo_intr_Interrupt);

void UltraSone_1_Echo_intr_SetVector(cyisraddress address);
cyisraddress UltraSone_1_Echo_intr_GetVector(void);

void UltraSone_1_Echo_intr_SetPriority(uint8 priority);
uint8 UltraSone_1_Echo_intr_GetPriority(void);

void UltraSone_1_Echo_intr_Enable(void);
uint8 UltraSone_1_Echo_intr_GetState(void);
void UltraSone_1_Echo_intr_Disable(void);

void UltraSone_1_Echo_intr_SetPending(void);
void UltraSone_1_Echo_intr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the UltraSone_1_Echo_intr ISR. */
#define UltraSone_1_Echo_intr_INTC_VECTOR            ((reg32 *) UltraSone_1_Echo_intr__INTC_VECT)

/* Address of the UltraSone_1_Echo_intr ISR priority. */
#define UltraSone_1_Echo_intr_INTC_PRIOR             ((reg32 *) UltraSone_1_Echo_intr__INTC_PRIOR_REG)

/* Priority of the UltraSone_1_Echo_intr interrupt. */
#define UltraSone_1_Echo_intr_INTC_PRIOR_NUMBER      UltraSone_1_Echo_intr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable UltraSone_1_Echo_intr interrupt. */
#define UltraSone_1_Echo_intr_INTC_SET_EN            ((reg32 *) UltraSone_1_Echo_intr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the UltraSone_1_Echo_intr interrupt. */
#define UltraSone_1_Echo_intr_INTC_CLR_EN            ((reg32 *) UltraSone_1_Echo_intr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the UltraSone_1_Echo_intr interrupt state to pending. */
#define UltraSone_1_Echo_intr_INTC_SET_PD            ((reg32 *) UltraSone_1_Echo_intr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the UltraSone_1_Echo_intr interrupt. */
#define UltraSone_1_Echo_intr_INTC_CLR_PD            ((reg32 *) UltraSone_1_Echo_intr__INTC_CLR_PD_REG)



#endif /* CY_ISR_UltraSone_1_Echo_intr_H */


/* [] END OF FILE */
