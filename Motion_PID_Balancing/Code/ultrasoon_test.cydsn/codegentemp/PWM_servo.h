/*******************************************************************************
* File Name: PWM_servo.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the PWM_servo
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_PWM_servo_H)
#define CY_TCPWM_PWM_servo_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} PWM_servo_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  PWM_servo_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define PWM_servo_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define PWM_servo_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define PWM_servo_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define PWM_servo_QUAD_ENCODING_MODES            (0lu)
#define PWM_servo_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define PWM_servo_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define PWM_servo_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define PWM_servo_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define PWM_servo_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define PWM_servo_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define PWM_servo_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define PWM_servo_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define PWM_servo_TC_RUN_MODE                    (0lu)
#define PWM_servo_TC_COUNTER_MODE                (0lu)
#define PWM_servo_TC_COMP_CAP_MODE               (2lu)
#define PWM_servo_TC_PRESCALER                   (0lu)

/* Signal modes */
#define PWM_servo_TC_RELOAD_SIGNAL_MODE          (0lu)
#define PWM_servo_TC_COUNT_SIGNAL_MODE           (3lu)
#define PWM_servo_TC_START_SIGNAL_MODE           (0lu)
#define PWM_servo_TC_STOP_SIGNAL_MODE            (0lu)
#define PWM_servo_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define PWM_servo_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define PWM_servo_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define PWM_servo_TC_START_SIGNAL_PRESENT        (0lu)
#define PWM_servo_TC_STOP_SIGNAL_PRESENT         (0lu)
#define PWM_servo_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PWM_servo_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define PWM_servo_PWM_KILL_EVENT                 (0lu)
#define PWM_servo_PWM_STOP_EVENT                 (0lu)
#define PWM_servo_PWM_MODE                       (4lu)
#define PWM_servo_PWM_OUT_N_INVERT               (0lu)
#define PWM_servo_PWM_OUT_INVERT                 (0lu)
#define PWM_servo_PWM_ALIGN                      (0lu)
#define PWM_servo_PWM_RUN_MODE                   (0lu)
#define PWM_servo_PWM_DEAD_TIME_CYCLE            (0lu)
#define PWM_servo_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define PWM_servo_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define PWM_servo_PWM_COUNT_SIGNAL_MODE          (3lu)
#define PWM_servo_PWM_START_SIGNAL_MODE          (0lu)
#define PWM_servo_PWM_STOP_SIGNAL_MODE           (0lu)
#define PWM_servo_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define PWM_servo_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define PWM_servo_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define PWM_servo_PWM_START_SIGNAL_PRESENT       (0lu)
#define PWM_servo_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define PWM_servo_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PWM_servo_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define PWM_servo_TC_PERIOD_VALUE                (65535lu)
#define PWM_servo_TC_COMPARE_VALUE               (65535lu)
#define PWM_servo_TC_COMPARE_BUF_VALUE           (65535lu)
#define PWM_servo_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define PWM_servo_PWM_PERIOD_VALUE               (2000lu)
#define PWM_servo_PWM_PERIOD_BUF_VALUE           (65535lu)
#define PWM_servo_PWM_PERIOD_SWAP                (0lu)
#define PWM_servo_PWM_COMPARE_VALUE              (50lu)
#define PWM_servo_PWM_COMPARE_BUF_VALUE          (65535lu)
#define PWM_servo_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define PWM_servo__LEFT 0
#define PWM_servo__RIGHT 1
#define PWM_servo__CENTER 2
#define PWM_servo__ASYMMETRIC 3

#define PWM_servo__X1 0
#define PWM_servo__X2 1
#define PWM_servo__X4 2

#define PWM_servo__PWM 4
#define PWM_servo__PWM_DT 5
#define PWM_servo__PWM_PR 6

#define PWM_servo__INVERSE 1
#define PWM_servo__DIRECT 0

#define PWM_servo__CAPTURE 2
#define PWM_servo__COMPARE 0

#define PWM_servo__TRIG_LEVEL 3
#define PWM_servo__TRIG_RISING 0
#define PWM_servo__TRIG_FALLING 1
#define PWM_servo__TRIG_BOTH 2

#define PWM_servo__INTR_MASK_TC 1
#define PWM_servo__INTR_MASK_CC_MATCH 2
#define PWM_servo__INTR_MASK_NONE 0
#define PWM_servo__INTR_MASK_TC_CC 3

#define PWM_servo__UNCONFIG 8
#define PWM_servo__TIMER 1
#define PWM_servo__QUAD 3
#define PWM_servo__PWM_SEL 7

#define PWM_servo__COUNT_UP 0
#define PWM_servo__COUNT_DOWN 1
#define PWM_servo__COUNT_UPDOWN0 2
#define PWM_servo__COUNT_UPDOWN1 3


/* Prescaler */
#define PWM_servo_PRESCALE_DIVBY1                ((uint32)(0u << PWM_servo_PRESCALER_SHIFT))
#define PWM_servo_PRESCALE_DIVBY2                ((uint32)(1u << PWM_servo_PRESCALER_SHIFT))
#define PWM_servo_PRESCALE_DIVBY4                ((uint32)(2u << PWM_servo_PRESCALER_SHIFT))
#define PWM_servo_PRESCALE_DIVBY8                ((uint32)(3u << PWM_servo_PRESCALER_SHIFT))
#define PWM_servo_PRESCALE_DIVBY16               ((uint32)(4u << PWM_servo_PRESCALER_SHIFT))
#define PWM_servo_PRESCALE_DIVBY32               ((uint32)(5u << PWM_servo_PRESCALER_SHIFT))
#define PWM_servo_PRESCALE_DIVBY64               ((uint32)(6u << PWM_servo_PRESCALER_SHIFT))
#define PWM_servo_PRESCALE_DIVBY128              ((uint32)(7u << PWM_servo_PRESCALER_SHIFT))

/* TCPWM set modes */
#define PWM_servo_MODE_TIMER_COMPARE             ((uint32)(PWM_servo__COMPARE         <<  \
                                                                  PWM_servo_MODE_SHIFT))
#define PWM_servo_MODE_TIMER_CAPTURE             ((uint32)(PWM_servo__CAPTURE         <<  \
                                                                  PWM_servo_MODE_SHIFT))
#define PWM_servo_MODE_QUAD                      ((uint32)(PWM_servo__QUAD            <<  \
                                                                  PWM_servo_MODE_SHIFT))
#define PWM_servo_MODE_PWM                       ((uint32)(PWM_servo__PWM             <<  \
                                                                  PWM_servo_MODE_SHIFT))
#define PWM_servo_MODE_PWM_DT                    ((uint32)(PWM_servo__PWM_DT          <<  \
                                                                  PWM_servo_MODE_SHIFT))
#define PWM_servo_MODE_PWM_PR                    ((uint32)(PWM_servo__PWM_PR          <<  \
                                                                  PWM_servo_MODE_SHIFT))

/* Quad Modes */
#define PWM_servo_MODE_X1                        ((uint32)(PWM_servo__X1              <<  \
                                                                  PWM_servo_QUAD_MODE_SHIFT))
#define PWM_servo_MODE_X2                        ((uint32)(PWM_servo__X2              <<  \
                                                                  PWM_servo_QUAD_MODE_SHIFT))
#define PWM_servo_MODE_X4                        ((uint32)(PWM_servo__X4              <<  \
                                                                  PWM_servo_QUAD_MODE_SHIFT))

/* Counter modes */
#define PWM_servo_COUNT_UP                       ((uint32)(PWM_servo__COUNT_UP        <<  \
                                                                  PWM_servo_UPDOWN_SHIFT))
#define PWM_servo_COUNT_DOWN                     ((uint32)(PWM_servo__COUNT_DOWN      <<  \
                                                                  PWM_servo_UPDOWN_SHIFT))
#define PWM_servo_COUNT_UPDOWN0                  ((uint32)(PWM_servo__COUNT_UPDOWN0   <<  \
                                                                  PWM_servo_UPDOWN_SHIFT))
#define PWM_servo_COUNT_UPDOWN1                  ((uint32)(PWM_servo__COUNT_UPDOWN1   <<  \
                                                                  PWM_servo_UPDOWN_SHIFT))

/* PWM output invert */
#define PWM_servo_INVERT_LINE                    ((uint32)(PWM_servo__INVERSE         <<  \
                                                                  PWM_servo_INV_OUT_SHIFT))
#define PWM_servo_INVERT_LINE_N                  ((uint32)(PWM_servo__INVERSE         <<  \
                                                                  PWM_servo_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define PWM_servo_TRIG_RISING                    ((uint32)PWM_servo__TRIG_RISING)
#define PWM_servo_TRIG_FALLING                   ((uint32)PWM_servo__TRIG_FALLING)
#define PWM_servo_TRIG_BOTH                      ((uint32)PWM_servo__TRIG_BOTH)
#define PWM_servo_TRIG_LEVEL                     ((uint32)PWM_servo__TRIG_LEVEL)

/* Interrupt mask */
#define PWM_servo_INTR_MASK_TC                   ((uint32)PWM_servo__INTR_MASK_TC)
#define PWM_servo_INTR_MASK_CC_MATCH             ((uint32)PWM_servo__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define PWM_servo_CC_MATCH_SET                   (0x00u)
#define PWM_servo_CC_MATCH_CLEAR                 (0x01u)
#define PWM_servo_CC_MATCH_INVERT                (0x02u)
#define PWM_servo_CC_MATCH_NO_CHANGE             (0x03u)
#define PWM_servo_OVERLOW_SET                    (0x00u)
#define PWM_servo_OVERLOW_CLEAR                  (0x04u)
#define PWM_servo_OVERLOW_INVERT                 (0x08u)
#define PWM_servo_OVERLOW_NO_CHANGE              (0x0Cu)
#define PWM_servo_UNDERFLOW_SET                  (0x00u)
#define PWM_servo_UNDERFLOW_CLEAR                (0x10u)
#define PWM_servo_UNDERFLOW_INVERT               (0x20u)
#define PWM_servo_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define PWM_servo_PWM_MODE_LEFT                  (PWM_servo_CC_MATCH_CLEAR        |   \
                                                         PWM_servo_OVERLOW_SET           |   \
                                                         PWM_servo_UNDERFLOW_NO_CHANGE)
#define PWM_servo_PWM_MODE_RIGHT                 (PWM_servo_CC_MATCH_SET          |   \
                                                         PWM_servo_OVERLOW_NO_CHANGE     |   \
                                                         PWM_servo_UNDERFLOW_CLEAR)
#define PWM_servo_PWM_MODE_ASYM                  (PWM_servo_CC_MATCH_INVERT       |   \
                                                         PWM_servo_OVERLOW_SET           |   \
                                                         PWM_servo_UNDERFLOW_CLEAR)

#if (PWM_servo_CY_TCPWM_V2)
    #if(PWM_servo_CY_TCPWM_4000)
        #define PWM_servo_PWM_MODE_CENTER                (PWM_servo_CC_MATCH_INVERT       |   \
                                                                 PWM_servo_OVERLOW_NO_CHANGE     |   \
                                                                 PWM_servo_UNDERFLOW_CLEAR)
    #else
        #define PWM_servo_PWM_MODE_CENTER                (PWM_servo_CC_MATCH_INVERT       |   \
                                                                 PWM_servo_OVERLOW_SET           |   \
                                                                 PWM_servo_UNDERFLOW_CLEAR)
    #endif /* (PWM_servo_CY_TCPWM_4000) */
#else
    #define PWM_servo_PWM_MODE_CENTER                (PWM_servo_CC_MATCH_INVERT       |   \
                                                             PWM_servo_OVERLOW_NO_CHANGE     |   \
                                                             PWM_servo_UNDERFLOW_CLEAR)
#endif /* (PWM_servo_CY_TCPWM_NEW) */

/* Command operations without condition */
#define PWM_servo_CMD_CAPTURE                    (0u)
#define PWM_servo_CMD_RELOAD                     (8u)
#define PWM_servo_CMD_STOP                       (16u)
#define PWM_servo_CMD_START                      (24u)

/* Status */
#define PWM_servo_STATUS_DOWN                    (1u)
#define PWM_servo_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   PWM_servo_Init(void);
void   PWM_servo_Enable(void);
void   PWM_servo_Start(void);
void   PWM_servo_Stop(void);

void   PWM_servo_SetMode(uint32 mode);
void   PWM_servo_SetCounterMode(uint32 counterMode);
void   PWM_servo_SetPWMMode(uint32 modeMask);
void   PWM_servo_SetQDMode(uint32 qdMode);

void   PWM_servo_SetPrescaler(uint32 prescaler);
void   PWM_servo_TriggerCommand(uint32 mask, uint32 command);
void   PWM_servo_SetOneShot(uint32 oneShotEnable);
uint32 PWM_servo_ReadStatus(void);

void   PWM_servo_SetPWMSyncKill(uint32 syncKillEnable);
void   PWM_servo_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   PWM_servo_SetPWMDeadTime(uint32 deadTime);
void   PWM_servo_SetPWMInvert(uint32 mask);

void   PWM_servo_SetInterruptMode(uint32 interruptMask);
uint32 PWM_servo_GetInterruptSourceMasked(void);
uint32 PWM_servo_GetInterruptSource(void);
void   PWM_servo_ClearInterrupt(uint32 interruptMask);
void   PWM_servo_SetInterrupt(uint32 interruptMask);

void   PWM_servo_WriteCounter(uint32 count);
uint32 PWM_servo_ReadCounter(void);

uint32 PWM_servo_ReadCapture(void);
uint32 PWM_servo_ReadCaptureBuf(void);

void   PWM_servo_WritePeriod(uint32 period);
uint32 PWM_servo_ReadPeriod(void);
void   PWM_servo_WritePeriodBuf(uint32 periodBuf);
uint32 PWM_servo_ReadPeriodBuf(void);

void   PWM_servo_WriteCompare(uint32 compare);
uint32 PWM_servo_ReadCompare(void);
void   PWM_servo_WriteCompareBuf(uint32 compareBuf);
uint32 PWM_servo_ReadCompareBuf(void);

void   PWM_servo_SetPeriodSwap(uint32 swapEnable);
void   PWM_servo_SetCompareSwap(uint32 swapEnable);

void   PWM_servo_SetCaptureMode(uint32 triggerMode);
void   PWM_servo_SetReloadMode(uint32 triggerMode);
void   PWM_servo_SetStartMode(uint32 triggerMode);
void   PWM_servo_SetStopMode(uint32 triggerMode);
void   PWM_servo_SetCountMode(uint32 triggerMode);

void   PWM_servo_SaveConfig(void);
void   PWM_servo_RestoreConfig(void);
void   PWM_servo_Sleep(void);
void   PWM_servo_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define PWM_servo_BLOCK_CONTROL_REG              (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PWM_servo_BLOCK_CONTROL_PTR              ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PWM_servo_COMMAND_REG                    (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PWM_servo_COMMAND_PTR                    ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PWM_servo_INTRRUPT_CAUSE_REG             (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PWM_servo_INTRRUPT_CAUSE_PTR             ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PWM_servo_CONTROL_REG                    (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__CTRL )
#define PWM_servo_CONTROL_PTR                    ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__CTRL )
#define PWM_servo_STATUS_REG                     (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__STATUS )
#define PWM_servo_STATUS_PTR                     ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__STATUS )
#define PWM_servo_COUNTER_REG                    (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__COUNTER )
#define PWM_servo_COUNTER_PTR                    ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__COUNTER )
#define PWM_servo_COMP_CAP_REG                   (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__CC )
#define PWM_servo_COMP_CAP_PTR                   ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__CC )
#define PWM_servo_COMP_CAP_BUF_REG               (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__CC_BUFF )
#define PWM_servo_COMP_CAP_BUF_PTR               ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__CC_BUFF )
#define PWM_servo_PERIOD_REG                     (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__PERIOD )
#define PWM_servo_PERIOD_PTR                     ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__PERIOD )
#define PWM_servo_PERIOD_BUF_REG                 (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PWM_servo_PERIOD_BUF_PTR                 ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PWM_servo_TRIG_CONTROL0_REG              (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PWM_servo_TRIG_CONTROL0_PTR              ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PWM_servo_TRIG_CONTROL1_REG              (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PWM_servo_TRIG_CONTROL1_PTR              ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PWM_servo_TRIG_CONTROL2_REG              (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PWM_servo_TRIG_CONTROL2_PTR              ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PWM_servo_INTERRUPT_REQ_REG              (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__INTR )
#define PWM_servo_INTERRUPT_REQ_PTR              ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__INTR )
#define PWM_servo_INTERRUPT_SET_REG              (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__INTR_SET )
#define PWM_servo_INTERRUPT_SET_PTR              ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__INTR_SET )
#define PWM_servo_INTERRUPT_MASK_REG             (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__INTR_MASK )
#define PWM_servo_INTERRUPT_MASK_PTR             ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__INTR_MASK )
#define PWM_servo_INTERRUPT_MASKED_REG           (*(reg32 *) PWM_servo_cy_m0s8_tcpwm_1__INTR_MASKED )
#define PWM_servo_INTERRUPT_MASKED_PTR           ( (reg32 *) PWM_servo_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define PWM_servo_MASK                           ((uint32)PWM_servo_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define PWM_servo_RELOAD_CC_SHIFT                (0u)
#define PWM_servo_RELOAD_PERIOD_SHIFT            (1u)
#define PWM_servo_PWM_SYNC_KILL_SHIFT            (2u)
#define PWM_servo_PWM_STOP_KILL_SHIFT            (3u)
#define PWM_servo_PRESCALER_SHIFT                (8u)
#define PWM_servo_UPDOWN_SHIFT                   (16u)
#define PWM_servo_ONESHOT_SHIFT                  (18u)
#define PWM_servo_QUAD_MODE_SHIFT                (20u)
#define PWM_servo_INV_OUT_SHIFT                  (20u)
#define PWM_servo_INV_COMPL_OUT_SHIFT            (21u)
#define PWM_servo_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define PWM_servo_RELOAD_CC_MASK                 ((uint32)(PWM_servo_1BIT_MASK        <<  \
                                                                            PWM_servo_RELOAD_CC_SHIFT))
#define PWM_servo_RELOAD_PERIOD_MASK             ((uint32)(PWM_servo_1BIT_MASK        <<  \
                                                                            PWM_servo_RELOAD_PERIOD_SHIFT))
#define PWM_servo_PWM_SYNC_KILL_MASK             ((uint32)(PWM_servo_1BIT_MASK        <<  \
                                                                            PWM_servo_PWM_SYNC_KILL_SHIFT))
#define PWM_servo_PWM_STOP_KILL_MASK             ((uint32)(PWM_servo_1BIT_MASK        <<  \
                                                                            PWM_servo_PWM_STOP_KILL_SHIFT))
#define PWM_servo_PRESCALER_MASK                 ((uint32)(PWM_servo_8BIT_MASK        <<  \
                                                                            PWM_servo_PRESCALER_SHIFT))
#define PWM_servo_UPDOWN_MASK                    ((uint32)(PWM_servo_2BIT_MASK        <<  \
                                                                            PWM_servo_UPDOWN_SHIFT))
#define PWM_servo_ONESHOT_MASK                   ((uint32)(PWM_servo_1BIT_MASK        <<  \
                                                                            PWM_servo_ONESHOT_SHIFT))
#define PWM_servo_QUAD_MODE_MASK                 ((uint32)(PWM_servo_3BIT_MASK        <<  \
                                                                            PWM_servo_QUAD_MODE_SHIFT))
#define PWM_servo_INV_OUT_MASK                   ((uint32)(PWM_servo_2BIT_MASK        <<  \
                                                                            PWM_servo_INV_OUT_SHIFT))
#define PWM_servo_MODE_MASK                      ((uint32)(PWM_servo_3BIT_MASK        <<  \
                                                                            PWM_servo_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define PWM_servo_CAPTURE_SHIFT                  (0u)
#define PWM_servo_COUNT_SHIFT                    (2u)
#define PWM_servo_RELOAD_SHIFT                   (4u)
#define PWM_servo_STOP_SHIFT                     (6u)
#define PWM_servo_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define PWM_servo_CAPTURE_MASK                   ((uint32)(PWM_servo_2BIT_MASK        <<  \
                                                                  PWM_servo_CAPTURE_SHIFT))
#define PWM_servo_COUNT_MASK                     ((uint32)(PWM_servo_2BIT_MASK        <<  \
                                                                  PWM_servo_COUNT_SHIFT))
#define PWM_servo_RELOAD_MASK                    ((uint32)(PWM_servo_2BIT_MASK        <<  \
                                                                  PWM_servo_RELOAD_SHIFT))
#define PWM_servo_STOP_MASK                      ((uint32)(PWM_servo_2BIT_MASK        <<  \
                                                                  PWM_servo_STOP_SHIFT))
#define PWM_servo_START_MASK                     ((uint32)(PWM_servo_2BIT_MASK        <<  \
                                                                  PWM_servo_START_SHIFT))

/* MASK */
#define PWM_servo_1BIT_MASK                      ((uint32)0x01u)
#define PWM_servo_2BIT_MASK                      ((uint32)0x03u)
#define PWM_servo_3BIT_MASK                      ((uint32)0x07u)
#define PWM_servo_6BIT_MASK                      ((uint32)0x3Fu)
#define PWM_servo_8BIT_MASK                      ((uint32)0xFFu)
#define PWM_servo_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define PWM_servo_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define PWM_servo_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(PWM_servo_QUAD_ENCODING_MODES     << PWM_servo_QUAD_MODE_SHIFT))       |\
         ((uint32)(PWM_servo_CONFIG                  << PWM_servo_MODE_SHIFT)))

#define PWM_servo_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(PWM_servo_PWM_STOP_EVENT          << PWM_servo_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(PWM_servo_PWM_OUT_INVERT          << PWM_servo_INV_OUT_SHIFT))         |\
         ((uint32)(PWM_servo_PWM_OUT_N_INVERT        << PWM_servo_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(PWM_servo_PWM_MODE                << PWM_servo_MODE_SHIFT)))

#define PWM_servo_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(PWM_servo_PWM_RUN_MODE         << PWM_servo_ONESHOT_SHIFT))
            
#define PWM_servo_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(PWM_servo_PWM_ALIGN            << PWM_servo_UPDOWN_SHIFT))

#define PWM_servo_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(PWM_servo_PWM_KILL_EVENT      << PWM_servo_PWM_SYNC_KILL_SHIFT))

#define PWM_servo_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(PWM_servo_PWM_DEAD_TIME_CYCLE  << PWM_servo_PRESCALER_SHIFT))

#define PWM_servo_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(PWM_servo_PWM_PRESCALER        << PWM_servo_PRESCALER_SHIFT))

#define PWM_servo_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(PWM_servo_TC_PRESCALER            << PWM_servo_PRESCALER_SHIFT))       |\
         ((uint32)(PWM_servo_TC_COUNTER_MODE         << PWM_servo_UPDOWN_SHIFT))          |\
         ((uint32)(PWM_servo_TC_RUN_MODE             << PWM_servo_ONESHOT_SHIFT))         |\
         ((uint32)(PWM_servo_TC_COMP_CAP_MODE        << PWM_servo_MODE_SHIFT)))
        
#define PWM_servo_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(PWM_servo_QUAD_PHIA_SIGNAL_MODE   << PWM_servo_COUNT_SHIFT))           |\
         ((uint32)(PWM_servo_QUAD_INDEX_SIGNAL_MODE  << PWM_servo_RELOAD_SHIFT))          |\
         ((uint32)(PWM_servo_QUAD_STOP_SIGNAL_MODE   << PWM_servo_STOP_SHIFT))            |\
         ((uint32)(PWM_servo_QUAD_PHIB_SIGNAL_MODE   << PWM_servo_START_SHIFT)))

#define PWM_servo_PWM_SIGNALS_MODES                                                              \
        (((uint32)(PWM_servo_PWM_SWITCH_SIGNAL_MODE  << PWM_servo_CAPTURE_SHIFT))         |\
         ((uint32)(PWM_servo_PWM_COUNT_SIGNAL_MODE   << PWM_servo_COUNT_SHIFT))           |\
         ((uint32)(PWM_servo_PWM_RELOAD_SIGNAL_MODE  << PWM_servo_RELOAD_SHIFT))          |\
         ((uint32)(PWM_servo_PWM_STOP_SIGNAL_MODE    << PWM_servo_STOP_SHIFT))            |\
         ((uint32)(PWM_servo_PWM_START_SIGNAL_MODE   << PWM_servo_START_SHIFT)))

#define PWM_servo_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(PWM_servo_TC_CAPTURE_SIGNAL_MODE  << PWM_servo_CAPTURE_SHIFT))         |\
         ((uint32)(PWM_servo_TC_COUNT_SIGNAL_MODE    << PWM_servo_COUNT_SHIFT))           |\
         ((uint32)(PWM_servo_TC_RELOAD_SIGNAL_MODE   << PWM_servo_RELOAD_SHIFT))          |\
         ((uint32)(PWM_servo_TC_STOP_SIGNAL_MODE     << PWM_servo_STOP_SHIFT))            |\
         ((uint32)(PWM_servo_TC_START_SIGNAL_MODE    << PWM_servo_START_SHIFT)))
        
#define PWM_servo_TIMER_UPDOWN_CNT_USED                                                          \
                ((PWM_servo__COUNT_UPDOWN0 == PWM_servo_TC_COUNTER_MODE)                  ||\
                 (PWM_servo__COUNT_UPDOWN1 == PWM_servo_TC_COUNTER_MODE))

#define PWM_servo_PWM_UPDOWN_CNT_USED                                                            \
                ((PWM_servo__CENTER == PWM_servo_PWM_ALIGN)                               ||\
                 (PWM_servo__ASYMMETRIC == PWM_servo_PWM_ALIGN))               
        
#define PWM_servo_PWM_PR_INIT_VALUE              (1u)
#define PWM_servo_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_PWM_servo_H */

/* [] END OF FILE */
