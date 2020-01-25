/*******************************************************************************
* File Name: Clock_125.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock_125_H)
#define CY_CLOCK_Clock_125_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Clock_125_StartEx(uint32 alignClkDiv);
#define Clock_125_Start() \
    Clock_125_StartEx(Clock_125__PA_DIV_ID)

#else

void Clock_125_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Clock_125_Stop(void);

void Clock_125_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Clock_125_GetDividerRegister(void);
uint8  Clock_125_GetFractionalDividerRegister(void);

#define Clock_125_Enable()                         Clock_125_Start()
#define Clock_125_Disable()                        Clock_125_Stop()
#define Clock_125_SetDividerRegister(clkDivider, reset)  \
    Clock_125_SetFractionalDividerRegister((clkDivider), 0u)
#define Clock_125_SetDivider(clkDivider)           Clock_125_SetDividerRegister((clkDivider), 1u)
#define Clock_125_SetDividerValue(clkDivider)      Clock_125_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Clock_125_DIV_ID     Clock_125__DIV_ID

#define Clock_125_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Clock_125_CTRL_REG   (*(reg32 *)Clock_125__CTRL_REGISTER)
#define Clock_125_DIV_REG    (*(reg32 *)Clock_125__DIV_REGISTER)

#define Clock_125_CMD_DIV_SHIFT          (0u)
#define Clock_125_CMD_PA_DIV_SHIFT       (8u)
#define Clock_125_CMD_DISABLE_SHIFT      (30u)
#define Clock_125_CMD_ENABLE_SHIFT       (31u)

#define Clock_125_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Clock_125_CMD_DISABLE_SHIFT))
#define Clock_125_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Clock_125_CMD_ENABLE_SHIFT))

#define Clock_125_DIV_FRAC_MASK  (0x000000F8u)
#define Clock_125_DIV_FRAC_SHIFT (3u)
#define Clock_125_DIV_INT_MASK   (0xFFFFFF00u)
#define Clock_125_DIV_INT_SHIFT  (8u)

#else 

#define Clock_125_DIV_REG        (*(reg32 *)Clock_125__REGISTER)
#define Clock_125_ENABLE_REG     Clock_125_DIV_REG
#define Clock_125_DIV_FRAC_MASK  Clock_125__FRAC_MASK
#define Clock_125_DIV_FRAC_SHIFT (16u)
#define Clock_125_DIV_INT_MASK   Clock_125__DIVIDER_MASK
#define Clock_125_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Clock_125_H) */

/* [] END OF FILE */
