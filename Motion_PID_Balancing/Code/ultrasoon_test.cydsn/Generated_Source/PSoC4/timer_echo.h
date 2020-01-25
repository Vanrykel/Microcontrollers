/*******************************************************************************
* File Name: timer_echo.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the timer_echo
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

#if !defined(CY_TCPWM_timer_echo_H)
#define CY_TCPWM_timer_echo_H


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
} timer_echo_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  timer_echo_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define timer_echo_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define timer_echo_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define timer_echo_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define timer_echo_QUAD_ENCODING_MODES            (0lu)
#define timer_echo_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define timer_echo_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define timer_echo_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define timer_echo_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define timer_echo_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define timer_echo_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define timer_echo_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define timer_echo_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define timer_echo_TC_RUN_MODE                    (0lu)
#define timer_echo_TC_COUNTER_MODE                (0lu)
#define timer_echo_TC_COMP_CAP_MODE               (2lu)
#define timer_echo_TC_PRESCALER                   (0lu)

/* Signal modes */
#define timer_echo_TC_RELOAD_SIGNAL_MODE          (0lu)
#define timer_echo_TC_COUNT_SIGNAL_MODE           (3lu)
#define timer_echo_TC_START_SIGNAL_MODE           (0lu)
#define timer_echo_TC_STOP_SIGNAL_MODE            (1lu)
#define timer_echo_TC_CAPTURE_SIGNAL_MODE         (1lu)

/* Signal present */
#define timer_echo_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define timer_echo_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define timer_echo_TC_START_SIGNAL_PRESENT        (1lu)
#define timer_echo_TC_STOP_SIGNAL_PRESENT         (1lu)
#define timer_echo_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define timer_echo_TC_INTERRUPT_MASK              (2lu)

/* PWM Mode */
/* Parameters */
#define timer_echo_PWM_KILL_EVENT                 (0lu)
#define timer_echo_PWM_STOP_EVENT                 (0lu)
#define timer_echo_PWM_MODE                       (4lu)
#define timer_echo_PWM_OUT_N_INVERT               (0lu)
#define timer_echo_PWM_OUT_INVERT                 (0lu)
#define timer_echo_PWM_ALIGN                      (0lu)
#define timer_echo_PWM_RUN_MODE                   (0lu)
#define timer_echo_PWM_DEAD_TIME_CYCLE            (0lu)
#define timer_echo_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define timer_echo_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define timer_echo_PWM_COUNT_SIGNAL_MODE          (3lu)
#define timer_echo_PWM_START_SIGNAL_MODE          (0lu)
#define timer_echo_PWM_STOP_SIGNAL_MODE           (0lu)
#define timer_echo_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define timer_echo_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define timer_echo_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define timer_echo_PWM_START_SIGNAL_PRESENT       (0lu)
#define timer_echo_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define timer_echo_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define timer_echo_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define timer_echo_TC_PERIOD_VALUE                (65535lu)
#define timer_echo_TC_COMPARE_VALUE               (65535lu)
#define timer_echo_TC_COMPARE_BUF_VALUE           (65535lu)
#define timer_echo_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define timer_echo_PWM_PERIOD_VALUE               (65535lu)
#define timer_echo_PWM_PERIOD_BUF_VALUE           (65535lu)
#define timer_echo_PWM_PERIOD_SWAP                (0lu)
#define timer_echo_PWM_COMPARE_VALUE              (65535lu)
#define timer_echo_PWM_COMPARE_BUF_VALUE          (65535lu)
#define timer_echo_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define timer_echo__LEFT 0
#define timer_echo__RIGHT 1
#define timer_echo__CENTER 2
#define timer_echo__ASYMMETRIC 3

#define timer_echo__X1 0
#define timer_echo__X2 1
#define timer_echo__X4 2

#define timer_echo__PWM 4
#define timer_echo__PWM_DT 5
#define timer_echo__PWM_PR 6

#define timer_echo__INVERSE 1
#define timer_echo__DIRECT 0

#define timer_echo__CAPTURE 2
#define timer_echo__COMPARE 0

#define timer_echo__TRIG_LEVEL 3
#define timer_echo__TRIG_RISING 0
#define timer_echo__TRIG_FALLING 1
#define timer_echo__TRIG_BOTH 2

#define timer_echo__INTR_MASK_TC 1
#define timer_echo__INTR_MASK_CC_MATCH 2
#define timer_echo__INTR_MASK_NONE 0
#define timer_echo__INTR_MASK_TC_CC 3

#define timer_echo__UNCONFIG 8
#define timer_echo__TIMER 1
#define timer_echo__QUAD 3
#define timer_echo__PWM_SEL 7

#define timer_echo__COUNT_UP 0
#define timer_echo__COUNT_DOWN 1
#define timer_echo__COUNT_UPDOWN0 2
#define timer_echo__COUNT_UPDOWN1 3


/* Prescaler */
#define timer_echo_PRESCALE_DIVBY1                ((uint32)(0u << timer_echo_PRESCALER_SHIFT))
#define timer_echo_PRESCALE_DIVBY2                ((uint32)(1u << timer_echo_PRESCALER_SHIFT))
#define timer_echo_PRESCALE_DIVBY4                ((uint32)(2u << timer_echo_PRESCALER_SHIFT))
#define timer_echo_PRESCALE_DIVBY8                ((uint32)(3u << timer_echo_PRESCALER_SHIFT))
#define timer_echo_PRESCALE_DIVBY16               ((uint32)(4u << timer_echo_PRESCALER_SHIFT))
#define timer_echo_PRESCALE_DIVBY32               ((uint32)(5u << timer_echo_PRESCALER_SHIFT))
#define timer_echo_PRESCALE_DIVBY64               ((uint32)(6u << timer_echo_PRESCALER_SHIFT))
#define timer_echo_PRESCALE_DIVBY128              ((uint32)(7u << timer_echo_PRESCALER_SHIFT))

/* TCPWM set modes */
#define timer_echo_MODE_TIMER_COMPARE             ((uint32)(timer_echo__COMPARE         <<  \
                                                                  timer_echo_MODE_SHIFT))
#define timer_echo_MODE_TIMER_CAPTURE             ((uint32)(timer_echo__CAPTURE         <<  \
                                                                  timer_echo_MODE_SHIFT))
#define timer_echo_MODE_QUAD                      ((uint32)(timer_echo__QUAD            <<  \
                                                                  timer_echo_MODE_SHIFT))
#define timer_echo_MODE_PWM                       ((uint32)(timer_echo__PWM             <<  \
                                                                  timer_echo_MODE_SHIFT))
#define timer_echo_MODE_PWM_DT                    ((uint32)(timer_echo__PWM_DT          <<  \
                                                                  timer_echo_MODE_SHIFT))
#define timer_echo_MODE_PWM_PR                    ((uint32)(timer_echo__PWM_PR          <<  \
                                                                  timer_echo_MODE_SHIFT))

/* Quad Modes */
#define timer_echo_MODE_X1                        ((uint32)(timer_echo__X1              <<  \
                                                                  timer_echo_QUAD_MODE_SHIFT))
#define timer_echo_MODE_X2                        ((uint32)(timer_echo__X2              <<  \
                                                                  timer_echo_QUAD_MODE_SHIFT))
#define timer_echo_MODE_X4                        ((uint32)(timer_echo__X4              <<  \
                                                                  timer_echo_QUAD_MODE_SHIFT))

/* Counter modes */
#define timer_echo_COUNT_UP                       ((uint32)(timer_echo__COUNT_UP        <<  \
                                                                  timer_echo_UPDOWN_SHIFT))
#define timer_echo_COUNT_DOWN                     ((uint32)(timer_echo__COUNT_DOWN      <<  \
                                                                  timer_echo_UPDOWN_SHIFT))
#define timer_echo_COUNT_UPDOWN0                  ((uint32)(timer_echo__COUNT_UPDOWN0   <<  \
                                                                  timer_echo_UPDOWN_SHIFT))
#define timer_echo_COUNT_UPDOWN1                  ((uint32)(timer_echo__COUNT_UPDOWN1   <<  \
                                                                  timer_echo_UPDOWN_SHIFT))

/* PWM output invert */
#define timer_echo_INVERT_LINE                    ((uint32)(timer_echo__INVERSE         <<  \
                                                                  timer_echo_INV_OUT_SHIFT))
#define timer_echo_INVERT_LINE_N                  ((uint32)(timer_echo__INVERSE         <<  \
                                                                  timer_echo_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define timer_echo_TRIG_RISING                    ((uint32)timer_echo__TRIG_RISING)
#define timer_echo_TRIG_FALLING                   ((uint32)timer_echo__TRIG_FALLING)
#define timer_echo_TRIG_BOTH                      ((uint32)timer_echo__TRIG_BOTH)
#define timer_echo_TRIG_LEVEL                     ((uint32)timer_echo__TRIG_LEVEL)

/* Interrupt mask */
#define timer_echo_INTR_MASK_TC                   ((uint32)timer_echo__INTR_MASK_TC)
#define timer_echo_INTR_MASK_CC_MATCH             ((uint32)timer_echo__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define timer_echo_CC_MATCH_SET                   (0x00u)
#define timer_echo_CC_MATCH_CLEAR                 (0x01u)
#define timer_echo_CC_MATCH_INVERT                (0x02u)
#define timer_echo_CC_MATCH_NO_CHANGE             (0x03u)
#define timer_echo_OVERLOW_SET                    (0x00u)
#define timer_echo_OVERLOW_CLEAR                  (0x04u)
#define timer_echo_OVERLOW_INVERT                 (0x08u)
#define timer_echo_OVERLOW_NO_CHANGE              (0x0Cu)
#define timer_echo_UNDERFLOW_SET                  (0x00u)
#define timer_echo_UNDERFLOW_CLEAR                (0x10u)
#define timer_echo_UNDERFLOW_INVERT               (0x20u)
#define timer_echo_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define timer_echo_PWM_MODE_LEFT                  (timer_echo_CC_MATCH_CLEAR        |   \
                                                         timer_echo_OVERLOW_SET           |   \
                                                         timer_echo_UNDERFLOW_NO_CHANGE)
#define timer_echo_PWM_MODE_RIGHT                 (timer_echo_CC_MATCH_SET          |   \
                                                         timer_echo_OVERLOW_NO_CHANGE     |   \
                                                         timer_echo_UNDERFLOW_CLEAR)
#define timer_echo_PWM_MODE_ASYM                  (timer_echo_CC_MATCH_INVERT       |   \
                                                         timer_echo_OVERLOW_SET           |   \
                                                         timer_echo_UNDERFLOW_CLEAR)

#if (timer_echo_CY_TCPWM_V2)
    #if(timer_echo_CY_TCPWM_4000)
        #define timer_echo_PWM_MODE_CENTER                (timer_echo_CC_MATCH_INVERT       |   \
                                                                 timer_echo_OVERLOW_NO_CHANGE     |   \
                                                                 timer_echo_UNDERFLOW_CLEAR)
    #else
        #define timer_echo_PWM_MODE_CENTER                (timer_echo_CC_MATCH_INVERT       |   \
                                                                 timer_echo_OVERLOW_SET           |   \
                                                                 timer_echo_UNDERFLOW_CLEAR)
    #endif /* (timer_echo_CY_TCPWM_4000) */
#else
    #define timer_echo_PWM_MODE_CENTER                (timer_echo_CC_MATCH_INVERT       |   \
                                                             timer_echo_OVERLOW_NO_CHANGE     |   \
                                                             timer_echo_UNDERFLOW_CLEAR)
#endif /* (timer_echo_CY_TCPWM_NEW) */

/* Command operations without condition */
#define timer_echo_CMD_CAPTURE                    (0u)
#define timer_echo_CMD_RELOAD                     (8u)
#define timer_echo_CMD_STOP                       (16u)
#define timer_echo_CMD_START                      (24u)

/* Status */
#define timer_echo_STATUS_DOWN                    (1u)
#define timer_echo_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   timer_echo_Init(void);
void   timer_echo_Enable(void);
void   timer_echo_Start(void);
void   timer_echo_Stop(void);

void   timer_echo_SetMode(uint32 mode);
void   timer_echo_SetCounterMode(uint32 counterMode);
void   timer_echo_SetPWMMode(uint32 modeMask);
void   timer_echo_SetQDMode(uint32 qdMode);

void   timer_echo_SetPrescaler(uint32 prescaler);
void   timer_echo_TriggerCommand(uint32 mask, uint32 command);
void   timer_echo_SetOneShot(uint32 oneShotEnable);
uint32 timer_echo_ReadStatus(void);

void   timer_echo_SetPWMSyncKill(uint32 syncKillEnable);
void   timer_echo_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   timer_echo_SetPWMDeadTime(uint32 deadTime);
void   timer_echo_SetPWMInvert(uint32 mask);

void   timer_echo_SetInterruptMode(uint32 interruptMask);
uint32 timer_echo_GetInterruptSourceMasked(void);
uint32 timer_echo_GetInterruptSource(void);
void   timer_echo_ClearInterrupt(uint32 interruptMask);
void   timer_echo_SetInterrupt(uint32 interruptMask);

void   timer_echo_WriteCounter(uint32 count);
uint32 timer_echo_ReadCounter(void);

uint32 timer_echo_ReadCapture(void);
uint32 timer_echo_ReadCaptureBuf(void);

void   timer_echo_WritePeriod(uint32 period);
uint32 timer_echo_ReadPeriod(void);
void   timer_echo_WritePeriodBuf(uint32 periodBuf);
uint32 timer_echo_ReadPeriodBuf(void);

void   timer_echo_WriteCompare(uint32 compare);
uint32 timer_echo_ReadCompare(void);
void   timer_echo_WriteCompareBuf(uint32 compareBuf);
uint32 timer_echo_ReadCompareBuf(void);

void   timer_echo_SetPeriodSwap(uint32 swapEnable);
void   timer_echo_SetCompareSwap(uint32 swapEnable);

void   timer_echo_SetCaptureMode(uint32 triggerMode);
void   timer_echo_SetReloadMode(uint32 triggerMode);
void   timer_echo_SetStartMode(uint32 triggerMode);
void   timer_echo_SetStopMode(uint32 triggerMode);
void   timer_echo_SetCountMode(uint32 triggerMode);

void   timer_echo_SaveConfig(void);
void   timer_echo_RestoreConfig(void);
void   timer_echo_Sleep(void);
void   timer_echo_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define timer_echo_BLOCK_CONTROL_REG              (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define timer_echo_BLOCK_CONTROL_PTR              ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define timer_echo_COMMAND_REG                    (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define timer_echo_COMMAND_PTR                    ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define timer_echo_INTRRUPT_CAUSE_REG             (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define timer_echo_INTRRUPT_CAUSE_PTR             ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define timer_echo_CONTROL_REG                    (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__CTRL )
#define timer_echo_CONTROL_PTR                    ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__CTRL )
#define timer_echo_STATUS_REG                     (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__STATUS )
#define timer_echo_STATUS_PTR                     ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__STATUS )
#define timer_echo_COUNTER_REG                    (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__COUNTER )
#define timer_echo_COUNTER_PTR                    ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__COUNTER )
#define timer_echo_COMP_CAP_REG                   (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__CC )
#define timer_echo_COMP_CAP_PTR                   ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__CC )
#define timer_echo_COMP_CAP_BUF_REG               (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__CC_BUFF )
#define timer_echo_COMP_CAP_BUF_PTR               ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__CC_BUFF )
#define timer_echo_PERIOD_REG                     (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__PERIOD )
#define timer_echo_PERIOD_PTR                     ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__PERIOD )
#define timer_echo_PERIOD_BUF_REG                 (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define timer_echo_PERIOD_BUF_PTR                 ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define timer_echo_TRIG_CONTROL0_REG              (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define timer_echo_TRIG_CONTROL0_PTR              ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define timer_echo_TRIG_CONTROL1_REG              (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define timer_echo_TRIG_CONTROL1_PTR              ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define timer_echo_TRIG_CONTROL2_REG              (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define timer_echo_TRIG_CONTROL2_PTR              ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define timer_echo_INTERRUPT_REQ_REG              (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__INTR )
#define timer_echo_INTERRUPT_REQ_PTR              ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__INTR )
#define timer_echo_INTERRUPT_SET_REG              (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__INTR_SET )
#define timer_echo_INTERRUPT_SET_PTR              ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__INTR_SET )
#define timer_echo_INTERRUPT_MASK_REG             (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__INTR_MASK )
#define timer_echo_INTERRUPT_MASK_PTR             ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__INTR_MASK )
#define timer_echo_INTERRUPT_MASKED_REG           (*(reg32 *) timer_echo_cy_m0s8_tcpwm_1__INTR_MASKED )
#define timer_echo_INTERRUPT_MASKED_PTR           ( (reg32 *) timer_echo_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define timer_echo_MASK                           ((uint32)timer_echo_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define timer_echo_RELOAD_CC_SHIFT                (0u)
#define timer_echo_RELOAD_PERIOD_SHIFT            (1u)
#define timer_echo_PWM_SYNC_KILL_SHIFT            (2u)
#define timer_echo_PWM_STOP_KILL_SHIFT            (3u)
#define timer_echo_PRESCALER_SHIFT                (8u)
#define timer_echo_UPDOWN_SHIFT                   (16u)
#define timer_echo_ONESHOT_SHIFT                  (18u)
#define timer_echo_QUAD_MODE_SHIFT                (20u)
#define timer_echo_INV_OUT_SHIFT                  (20u)
#define timer_echo_INV_COMPL_OUT_SHIFT            (21u)
#define timer_echo_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define timer_echo_RELOAD_CC_MASK                 ((uint32)(timer_echo_1BIT_MASK        <<  \
                                                                            timer_echo_RELOAD_CC_SHIFT))
#define timer_echo_RELOAD_PERIOD_MASK             ((uint32)(timer_echo_1BIT_MASK        <<  \
                                                                            timer_echo_RELOAD_PERIOD_SHIFT))
#define timer_echo_PWM_SYNC_KILL_MASK             ((uint32)(timer_echo_1BIT_MASK        <<  \
                                                                            timer_echo_PWM_SYNC_KILL_SHIFT))
#define timer_echo_PWM_STOP_KILL_MASK             ((uint32)(timer_echo_1BIT_MASK        <<  \
                                                                            timer_echo_PWM_STOP_KILL_SHIFT))
#define timer_echo_PRESCALER_MASK                 ((uint32)(timer_echo_8BIT_MASK        <<  \
                                                                            timer_echo_PRESCALER_SHIFT))
#define timer_echo_UPDOWN_MASK                    ((uint32)(timer_echo_2BIT_MASK        <<  \
                                                                            timer_echo_UPDOWN_SHIFT))
#define timer_echo_ONESHOT_MASK                   ((uint32)(timer_echo_1BIT_MASK        <<  \
                                                                            timer_echo_ONESHOT_SHIFT))
#define timer_echo_QUAD_MODE_MASK                 ((uint32)(timer_echo_3BIT_MASK        <<  \
                                                                            timer_echo_QUAD_MODE_SHIFT))
#define timer_echo_INV_OUT_MASK                   ((uint32)(timer_echo_2BIT_MASK        <<  \
                                                                            timer_echo_INV_OUT_SHIFT))
#define timer_echo_MODE_MASK                      ((uint32)(timer_echo_3BIT_MASK        <<  \
                                                                            timer_echo_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define timer_echo_CAPTURE_SHIFT                  (0u)
#define timer_echo_COUNT_SHIFT                    (2u)
#define timer_echo_RELOAD_SHIFT                   (4u)
#define timer_echo_STOP_SHIFT                     (6u)
#define timer_echo_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define timer_echo_CAPTURE_MASK                   ((uint32)(timer_echo_2BIT_MASK        <<  \
                                                                  timer_echo_CAPTURE_SHIFT))
#define timer_echo_COUNT_MASK                     ((uint32)(timer_echo_2BIT_MASK        <<  \
                                                                  timer_echo_COUNT_SHIFT))
#define timer_echo_RELOAD_MASK                    ((uint32)(timer_echo_2BIT_MASK        <<  \
                                                                  timer_echo_RELOAD_SHIFT))
#define timer_echo_STOP_MASK                      ((uint32)(timer_echo_2BIT_MASK        <<  \
                                                                  timer_echo_STOP_SHIFT))
#define timer_echo_START_MASK                     ((uint32)(timer_echo_2BIT_MASK        <<  \
                                                                  timer_echo_START_SHIFT))

/* MASK */
#define timer_echo_1BIT_MASK                      ((uint32)0x01u)
#define timer_echo_2BIT_MASK                      ((uint32)0x03u)
#define timer_echo_3BIT_MASK                      ((uint32)0x07u)
#define timer_echo_6BIT_MASK                      ((uint32)0x3Fu)
#define timer_echo_8BIT_MASK                      ((uint32)0xFFu)
#define timer_echo_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define timer_echo_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define timer_echo_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(timer_echo_QUAD_ENCODING_MODES     << timer_echo_QUAD_MODE_SHIFT))       |\
         ((uint32)(timer_echo_CONFIG                  << timer_echo_MODE_SHIFT)))

#define timer_echo_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(timer_echo_PWM_STOP_EVENT          << timer_echo_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(timer_echo_PWM_OUT_INVERT          << timer_echo_INV_OUT_SHIFT))         |\
         ((uint32)(timer_echo_PWM_OUT_N_INVERT        << timer_echo_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(timer_echo_PWM_MODE                << timer_echo_MODE_SHIFT)))

#define timer_echo_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(timer_echo_PWM_RUN_MODE         << timer_echo_ONESHOT_SHIFT))
            
#define timer_echo_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(timer_echo_PWM_ALIGN            << timer_echo_UPDOWN_SHIFT))

#define timer_echo_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(timer_echo_PWM_KILL_EVENT      << timer_echo_PWM_SYNC_KILL_SHIFT))

#define timer_echo_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(timer_echo_PWM_DEAD_TIME_CYCLE  << timer_echo_PRESCALER_SHIFT))

#define timer_echo_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(timer_echo_PWM_PRESCALER        << timer_echo_PRESCALER_SHIFT))

#define timer_echo_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(timer_echo_TC_PRESCALER            << timer_echo_PRESCALER_SHIFT))       |\
         ((uint32)(timer_echo_TC_COUNTER_MODE         << timer_echo_UPDOWN_SHIFT))          |\
         ((uint32)(timer_echo_TC_RUN_MODE             << timer_echo_ONESHOT_SHIFT))         |\
         ((uint32)(timer_echo_TC_COMP_CAP_MODE        << timer_echo_MODE_SHIFT)))
        
#define timer_echo_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(timer_echo_QUAD_PHIA_SIGNAL_MODE   << timer_echo_COUNT_SHIFT))           |\
         ((uint32)(timer_echo_QUAD_INDEX_SIGNAL_MODE  << timer_echo_RELOAD_SHIFT))          |\
         ((uint32)(timer_echo_QUAD_STOP_SIGNAL_MODE   << timer_echo_STOP_SHIFT))            |\
         ((uint32)(timer_echo_QUAD_PHIB_SIGNAL_MODE   << timer_echo_START_SHIFT)))

#define timer_echo_PWM_SIGNALS_MODES                                                              \
        (((uint32)(timer_echo_PWM_SWITCH_SIGNAL_MODE  << timer_echo_CAPTURE_SHIFT))         |\
         ((uint32)(timer_echo_PWM_COUNT_SIGNAL_MODE   << timer_echo_COUNT_SHIFT))           |\
         ((uint32)(timer_echo_PWM_RELOAD_SIGNAL_MODE  << timer_echo_RELOAD_SHIFT))          |\
         ((uint32)(timer_echo_PWM_STOP_SIGNAL_MODE    << timer_echo_STOP_SHIFT))            |\
         ((uint32)(timer_echo_PWM_START_SIGNAL_MODE   << timer_echo_START_SHIFT)))

#define timer_echo_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(timer_echo_TC_CAPTURE_SIGNAL_MODE  << timer_echo_CAPTURE_SHIFT))         |\
         ((uint32)(timer_echo_TC_COUNT_SIGNAL_MODE    << timer_echo_COUNT_SHIFT))           |\
         ((uint32)(timer_echo_TC_RELOAD_SIGNAL_MODE   << timer_echo_RELOAD_SHIFT))          |\
         ((uint32)(timer_echo_TC_STOP_SIGNAL_MODE     << timer_echo_STOP_SHIFT))            |\
         ((uint32)(timer_echo_TC_START_SIGNAL_MODE    << timer_echo_START_SHIFT)))
        
#define timer_echo_TIMER_UPDOWN_CNT_USED                                                          \
                ((timer_echo__COUNT_UPDOWN0 == timer_echo_TC_COUNTER_MODE)                  ||\
                 (timer_echo__COUNT_UPDOWN1 == timer_echo_TC_COUNTER_MODE))

#define timer_echo_PWM_UPDOWN_CNT_USED                                                            \
                ((timer_echo__CENTER == timer_echo_PWM_ALIGN)                               ||\
                 (timer_echo__ASYMMETRIC == timer_echo_PWM_ALIGN))               
        
#define timer_echo_PWM_PR_INIT_VALUE              (1u)
#define timer_echo_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_timer_echo_H */

/* [] END OF FILE */
