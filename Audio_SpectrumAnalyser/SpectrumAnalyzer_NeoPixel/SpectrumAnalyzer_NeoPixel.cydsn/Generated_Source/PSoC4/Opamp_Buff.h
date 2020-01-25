/*******************************************************************************
* File Name: Opamp_Buff.h
* Version 1.0
*
* Description:
*  This file contains the function prototypes and constants used in
*  the OpAmp (Analog Buffer) Component.
*
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_OPAMP_Opamp_Buff_H)
#define CY_OPAMP_Opamp_Buff_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*   Data Struct Definition
***************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Opamp_Buff_BACKUP_STRUCT;

/* Component init state */
extern uint32 Opamp_Buff_initVar;


/**************************************
*        Function Prototypes
**************************************/
void Opamp_Buff_Init(void);
void Opamp_Buff_Enable(void);
void Opamp_Buff_Start(void);
void Opamp_Buff_Stop(void);
void Opamp_Buff_SetPower(uint32 power);
void Opamp_Buff_PumpControl(uint32 onOff);
void Opamp_Buff_Sleep(void);
void Opamp_Buff_Wakeup(void);
void Opamp_Buff_SaveConfig(void);
void Opamp_Buff_RestoreConfig(void);


/**************************************
*           API Constants
**************************************/
#define Opamp_Buff_LOWPOWER                   (1u)
#define Opamp_Buff_MEDPOWER                   (2u)
#define Opamp_Buff_HIGHPOWER                  (3u)

#define Opamp_Buff_OUTPUT_CURRENT             (0u)
#define Opamp_Buff_POWER                      (3u)
#define Opamp_Buff_MODE                       (1u)
#define Opamp_Buff_OA_COMP_TRIM_VALUE         (3u)


/**************************************
*             Registers
**************************************/
#define Opamp_Buff_OA_CTRL                    (*(reg32 *)Opamp_Buff_cy_psoc4_abuf__CTBM_CTB_CTRL)
#define Opamp_Buff_OA_RES_CTRL                (*(reg32 *)Opamp_Buff_cy_psoc4_abuf__OA_RES_CTRL)
#define Opamp_Buff_OA_COMP_TRIM_REG           (*(reg32 *)Opamp_Buff_cy_psoc4_abuf__OA_COMP_TRIM)

/* Bit Field  OA_CTRL */
#define Opamp_Buff_OA_CTB_EN_SHIFT            (31u)

/* PUMP ON/OFF defines */
#define Opamp_Buff_PUMPON                     (1u)
#define Opamp_Buff_PUMPOFF                    (0u)

#define Opamp_Buff_PUMP_PROTECT_MASK          (1u)

/* Bit Field  OA_CTRL */
#define Opamp_Buff_OA_PWR_MODE_MASK           (0x3u)
#define Opamp_Buff_OA_DRIVE_STR_SEL_MASK      (0x4u)
#define Opamp_Buff_OA_DRIVE_STR_SEL_10X       (0x4u)
#define Opamp_Buff_OA_PUMP_EN_MASK            (0x800u)
#define Opamp_Buff_OA_PUMP_CTRL_SHIFT         (11u)

#endif    /* CY_OPAMP_Opamp_Buff_H */


/* [] END OF FILE */
