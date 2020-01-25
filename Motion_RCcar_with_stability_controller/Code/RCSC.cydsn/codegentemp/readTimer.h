/*******************************************************************************
* File Name: readTimer.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the readTimer
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

#if !defined(CY_TCPWM_readTimer_H)
#define CY_TCPWM_readTimer_H


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
} readTimer_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  readTimer_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define readTimer_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define readTimer_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define readTimer_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define readTimer_QUAD_ENCODING_MODES            (0lu)
#define readTimer_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define readTimer_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define readTimer_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define readTimer_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define readTimer_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define readTimer_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define readTimer_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define readTimer_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define readTimer_TC_RUN_MODE                    (0lu)
#define readTimer_TC_COUNTER_MODE                (0lu)
#define readTimer_TC_COMP_CAP_MODE               (2lu)
#define readTimer_TC_PRESCALER                   (0lu)

/* Signal modes */
#define readTimer_TC_RELOAD_SIGNAL_MODE          (0lu)
#define readTimer_TC_COUNT_SIGNAL_MODE           (3lu)
#define readTimer_TC_START_SIGNAL_MODE           (0lu)
#define readTimer_TC_STOP_SIGNAL_MODE            (0lu)
#define readTimer_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define readTimer_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define readTimer_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define readTimer_TC_START_SIGNAL_PRESENT        (0lu)
#define readTimer_TC_STOP_SIGNAL_PRESENT         (0lu)
#define readTimer_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define readTimer_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define readTimer_PWM_KILL_EVENT                 (0lu)
#define readTimer_PWM_STOP_EVENT                 (0lu)
#define readTimer_PWM_MODE                       (4lu)
#define readTimer_PWM_OUT_N_INVERT               (0lu)
#define readTimer_PWM_OUT_INVERT                 (0lu)
#define readTimer_PWM_ALIGN                      (0lu)
#define readTimer_PWM_RUN_MODE                   (0lu)
#define readTimer_PWM_DEAD_TIME_CYCLE            (0lu)
#define readTimer_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define readTimer_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define readTimer_PWM_COUNT_SIGNAL_MODE          (3lu)
#define readTimer_PWM_START_SIGNAL_MODE          (0lu)
#define readTimer_PWM_STOP_SIGNAL_MODE           (0lu)
#define readTimer_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define readTimer_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define readTimer_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define readTimer_PWM_START_SIGNAL_PRESENT       (0lu)
#define readTimer_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define readTimer_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define readTimer_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define readTimer_TC_PERIOD_VALUE                (10lu)
#define readTimer_TC_COMPARE_VALUE               (1000lu)
#define readTimer_TC_COMPARE_BUF_VALUE           (65535lu)
#define readTimer_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define readTimer_PWM_PERIOD_VALUE               (65535lu)
#define readTimer_PWM_PERIOD_BUF_VALUE           (65535lu)
#define readTimer_PWM_PERIOD_SWAP                (0lu)
#define readTimer_PWM_COMPARE_VALUE              (65535lu)
#define readTimer_PWM_COMPARE_BUF_VALUE          (65535lu)
#define readTimer_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define readTimer__LEFT 0
#define readTimer__RIGHT 1
#define readTimer__CENTER 2
#define readTimer__ASYMMETRIC 3

#define readTimer__X1 0
#define readTimer__X2 1
#define readTimer__X4 2

#define readTimer__PWM 4
#define readTimer__PWM_DT 5
#define readTimer__PWM_PR 6

#define readTimer__INVERSE 1
#define readTimer__DIRECT 0

#define readTimer__CAPTURE 2
#define readTimer__COMPARE 0

#define readTimer__TRIG_LEVEL 3
#define readTimer__TRIG_RISING 0
#define readTimer__TRIG_FALLING 1
#define readTimer__TRIG_BOTH 2

#define readTimer__INTR_MASK_TC 1
#define readTimer__INTR_MASK_CC_MATCH 2
#define readTimer__INTR_MASK_NONE 0
#define readTimer__INTR_MASK_TC_CC 3

#define readTimer__UNCONFIG 8
#define readTimer__TIMER 1
#define readTimer__QUAD 3
#define readTimer__PWM_SEL 7

#define readTimer__COUNT_UP 0
#define readTimer__COUNT_DOWN 1
#define readTimer__COUNT_UPDOWN0 2
#define readTimer__COUNT_UPDOWN1 3


/* Prescaler */
#define readTimer_PRESCALE_DIVBY1                ((uint32)(0u << readTimer_PRESCALER_SHIFT))
#define readTimer_PRESCALE_DIVBY2                ((uint32)(1u << readTimer_PRESCALER_SHIFT))
#define readTimer_PRESCALE_DIVBY4                ((uint32)(2u << readTimer_PRESCALER_SHIFT))
#define readTimer_PRESCALE_DIVBY8                ((uint32)(3u << readTimer_PRESCALER_SHIFT))
#define readTimer_PRESCALE_DIVBY16               ((uint32)(4u << readTimer_PRESCALER_SHIFT))
#define readTimer_PRESCALE_DIVBY32               ((uint32)(5u << readTimer_PRESCALER_SHIFT))
#define readTimer_PRESCALE_DIVBY64               ((uint32)(6u << readTimer_PRESCALER_SHIFT))
#define readTimer_PRESCALE_DIVBY128              ((uint32)(7u << readTimer_PRESCALER_SHIFT))

/* TCPWM set modes */
#define readTimer_MODE_TIMER_COMPARE             ((uint32)(readTimer__COMPARE         <<  \
                                                                  readTimer_MODE_SHIFT))
#define readTimer_MODE_TIMER_CAPTURE             ((uint32)(readTimer__CAPTURE         <<  \
                                                                  readTimer_MODE_SHIFT))
#define readTimer_MODE_QUAD                      ((uint32)(readTimer__QUAD            <<  \
                                                                  readTimer_MODE_SHIFT))
#define readTimer_MODE_PWM                       ((uint32)(readTimer__PWM             <<  \
                                                                  readTimer_MODE_SHIFT))
#define readTimer_MODE_PWM_DT                    ((uint32)(readTimer__PWM_DT          <<  \
                                                                  readTimer_MODE_SHIFT))
#define readTimer_MODE_PWM_PR                    ((uint32)(readTimer__PWM_PR          <<  \
                                                                  readTimer_MODE_SHIFT))

/* Quad Modes */
#define readTimer_MODE_X1                        ((uint32)(readTimer__X1              <<  \
                                                                  readTimer_QUAD_MODE_SHIFT))
#define readTimer_MODE_X2                        ((uint32)(readTimer__X2              <<  \
                                                                  readTimer_QUAD_MODE_SHIFT))
#define readTimer_MODE_X4                        ((uint32)(readTimer__X4              <<  \
                                                                  readTimer_QUAD_MODE_SHIFT))

/* Counter modes */
#define readTimer_COUNT_UP                       ((uint32)(readTimer__COUNT_UP        <<  \
                                                                  readTimer_UPDOWN_SHIFT))
#define readTimer_COUNT_DOWN                     ((uint32)(readTimer__COUNT_DOWN      <<  \
                                                                  readTimer_UPDOWN_SHIFT))
#define readTimer_COUNT_UPDOWN0                  ((uint32)(readTimer__COUNT_UPDOWN0   <<  \
                                                                  readTimer_UPDOWN_SHIFT))
#define readTimer_COUNT_UPDOWN1                  ((uint32)(readTimer__COUNT_UPDOWN1   <<  \
                                                                  readTimer_UPDOWN_SHIFT))

/* PWM output invert */
#define readTimer_INVERT_LINE                    ((uint32)(readTimer__INVERSE         <<  \
                                                                  readTimer_INV_OUT_SHIFT))
#define readTimer_INVERT_LINE_N                  ((uint32)(readTimer__INVERSE         <<  \
                                                                  readTimer_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define readTimer_TRIG_RISING                    ((uint32)readTimer__TRIG_RISING)
#define readTimer_TRIG_FALLING                   ((uint32)readTimer__TRIG_FALLING)
#define readTimer_TRIG_BOTH                      ((uint32)readTimer__TRIG_BOTH)
#define readTimer_TRIG_LEVEL                     ((uint32)readTimer__TRIG_LEVEL)

/* Interrupt mask */
#define readTimer_INTR_MASK_TC                   ((uint32)readTimer__INTR_MASK_TC)
#define readTimer_INTR_MASK_CC_MATCH             ((uint32)readTimer__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define readTimer_CC_MATCH_SET                   (0x00u)
#define readTimer_CC_MATCH_CLEAR                 (0x01u)
#define readTimer_CC_MATCH_INVERT                (0x02u)
#define readTimer_CC_MATCH_NO_CHANGE             (0x03u)
#define readTimer_OVERLOW_SET                    (0x00u)
#define readTimer_OVERLOW_CLEAR                  (0x04u)
#define readTimer_OVERLOW_INVERT                 (0x08u)
#define readTimer_OVERLOW_NO_CHANGE              (0x0Cu)
#define readTimer_UNDERFLOW_SET                  (0x00u)
#define readTimer_UNDERFLOW_CLEAR                (0x10u)
#define readTimer_UNDERFLOW_INVERT               (0x20u)
#define readTimer_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define readTimer_PWM_MODE_LEFT                  (readTimer_CC_MATCH_CLEAR        |   \
                                                         readTimer_OVERLOW_SET           |   \
                                                         readTimer_UNDERFLOW_NO_CHANGE)
#define readTimer_PWM_MODE_RIGHT                 (readTimer_CC_MATCH_SET          |   \
                                                         readTimer_OVERLOW_NO_CHANGE     |   \
                                                         readTimer_UNDERFLOW_CLEAR)
#define readTimer_PWM_MODE_ASYM                  (readTimer_CC_MATCH_INVERT       |   \
                                                         readTimer_OVERLOW_SET           |   \
                                                         readTimer_UNDERFLOW_CLEAR)

#if (readTimer_CY_TCPWM_V2)
    #if(readTimer_CY_TCPWM_4000)
        #define readTimer_PWM_MODE_CENTER                (readTimer_CC_MATCH_INVERT       |   \
                                                                 readTimer_OVERLOW_NO_CHANGE     |   \
                                                                 readTimer_UNDERFLOW_CLEAR)
    #else
        #define readTimer_PWM_MODE_CENTER                (readTimer_CC_MATCH_INVERT       |   \
                                                                 readTimer_OVERLOW_SET           |   \
                                                                 readTimer_UNDERFLOW_CLEAR)
    #endif /* (readTimer_CY_TCPWM_4000) */
#else
    #define readTimer_PWM_MODE_CENTER                (readTimer_CC_MATCH_INVERT       |   \
                                                             readTimer_OVERLOW_NO_CHANGE     |   \
                                                             readTimer_UNDERFLOW_CLEAR)
#endif /* (readTimer_CY_TCPWM_NEW) */

/* Command operations without condition */
#define readTimer_CMD_CAPTURE                    (0u)
#define readTimer_CMD_RELOAD                     (8u)
#define readTimer_CMD_STOP                       (16u)
#define readTimer_CMD_START                      (24u)

/* Status */
#define readTimer_STATUS_DOWN                    (1u)
#define readTimer_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   readTimer_Init(void);
void   readTimer_Enable(void);
void   readTimer_Start(void);
void   readTimer_Stop(void);

void   readTimer_SetMode(uint32 mode);
void   readTimer_SetCounterMode(uint32 counterMode);
void   readTimer_SetPWMMode(uint32 modeMask);
void   readTimer_SetQDMode(uint32 qdMode);

void   readTimer_SetPrescaler(uint32 prescaler);
void   readTimer_TriggerCommand(uint32 mask, uint32 command);
void   readTimer_SetOneShot(uint32 oneShotEnable);
uint32 readTimer_ReadStatus(void);

void   readTimer_SetPWMSyncKill(uint32 syncKillEnable);
void   readTimer_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   readTimer_SetPWMDeadTime(uint32 deadTime);
void   readTimer_SetPWMInvert(uint32 mask);

void   readTimer_SetInterruptMode(uint32 interruptMask);
uint32 readTimer_GetInterruptSourceMasked(void);
uint32 readTimer_GetInterruptSource(void);
void   readTimer_ClearInterrupt(uint32 interruptMask);
void   readTimer_SetInterrupt(uint32 interruptMask);

void   readTimer_WriteCounter(uint32 count);
uint32 readTimer_ReadCounter(void);

uint32 readTimer_ReadCapture(void);
uint32 readTimer_ReadCaptureBuf(void);

void   readTimer_WritePeriod(uint32 period);
uint32 readTimer_ReadPeriod(void);
void   readTimer_WritePeriodBuf(uint32 periodBuf);
uint32 readTimer_ReadPeriodBuf(void);

void   readTimer_WriteCompare(uint32 compare);
uint32 readTimer_ReadCompare(void);
void   readTimer_WriteCompareBuf(uint32 compareBuf);
uint32 readTimer_ReadCompareBuf(void);

void   readTimer_SetPeriodSwap(uint32 swapEnable);
void   readTimer_SetCompareSwap(uint32 swapEnable);

void   readTimer_SetCaptureMode(uint32 triggerMode);
void   readTimer_SetReloadMode(uint32 triggerMode);
void   readTimer_SetStartMode(uint32 triggerMode);
void   readTimer_SetStopMode(uint32 triggerMode);
void   readTimer_SetCountMode(uint32 triggerMode);

void   readTimer_SaveConfig(void);
void   readTimer_RestoreConfig(void);
void   readTimer_Sleep(void);
void   readTimer_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define readTimer_BLOCK_CONTROL_REG              (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define readTimer_BLOCK_CONTROL_PTR              ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define readTimer_COMMAND_REG                    (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define readTimer_COMMAND_PTR                    ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define readTimer_INTRRUPT_CAUSE_REG             (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define readTimer_INTRRUPT_CAUSE_PTR             ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define readTimer_CONTROL_REG                    (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__CTRL )
#define readTimer_CONTROL_PTR                    ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__CTRL )
#define readTimer_STATUS_REG                     (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__STATUS )
#define readTimer_STATUS_PTR                     ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__STATUS )
#define readTimer_COUNTER_REG                    (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__COUNTER )
#define readTimer_COUNTER_PTR                    ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__COUNTER )
#define readTimer_COMP_CAP_REG                   (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__CC )
#define readTimer_COMP_CAP_PTR                   ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__CC )
#define readTimer_COMP_CAP_BUF_REG               (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__CC_BUFF )
#define readTimer_COMP_CAP_BUF_PTR               ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__CC_BUFF )
#define readTimer_PERIOD_REG                     (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__PERIOD )
#define readTimer_PERIOD_PTR                     ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__PERIOD )
#define readTimer_PERIOD_BUF_REG                 (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define readTimer_PERIOD_BUF_PTR                 ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define readTimer_TRIG_CONTROL0_REG              (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define readTimer_TRIG_CONTROL0_PTR              ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define readTimer_TRIG_CONTROL1_REG              (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define readTimer_TRIG_CONTROL1_PTR              ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define readTimer_TRIG_CONTROL2_REG              (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define readTimer_TRIG_CONTROL2_PTR              ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define readTimer_INTERRUPT_REQ_REG              (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__INTR )
#define readTimer_INTERRUPT_REQ_PTR              ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__INTR )
#define readTimer_INTERRUPT_SET_REG              (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__INTR_SET )
#define readTimer_INTERRUPT_SET_PTR              ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__INTR_SET )
#define readTimer_INTERRUPT_MASK_REG             (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__INTR_MASK )
#define readTimer_INTERRUPT_MASK_PTR             ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__INTR_MASK )
#define readTimer_INTERRUPT_MASKED_REG           (*(reg32 *) readTimer_cy_m0s8_tcpwm_1__INTR_MASKED )
#define readTimer_INTERRUPT_MASKED_PTR           ( (reg32 *) readTimer_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define readTimer_MASK                           ((uint32)readTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define readTimer_RELOAD_CC_SHIFT                (0u)
#define readTimer_RELOAD_PERIOD_SHIFT            (1u)
#define readTimer_PWM_SYNC_KILL_SHIFT            (2u)
#define readTimer_PWM_STOP_KILL_SHIFT            (3u)
#define readTimer_PRESCALER_SHIFT                (8u)
#define readTimer_UPDOWN_SHIFT                   (16u)
#define readTimer_ONESHOT_SHIFT                  (18u)
#define readTimer_QUAD_MODE_SHIFT                (20u)
#define readTimer_INV_OUT_SHIFT                  (20u)
#define readTimer_INV_COMPL_OUT_SHIFT            (21u)
#define readTimer_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define readTimer_RELOAD_CC_MASK                 ((uint32)(readTimer_1BIT_MASK        <<  \
                                                                            readTimer_RELOAD_CC_SHIFT))
#define readTimer_RELOAD_PERIOD_MASK             ((uint32)(readTimer_1BIT_MASK        <<  \
                                                                            readTimer_RELOAD_PERIOD_SHIFT))
#define readTimer_PWM_SYNC_KILL_MASK             ((uint32)(readTimer_1BIT_MASK        <<  \
                                                                            readTimer_PWM_SYNC_KILL_SHIFT))
#define readTimer_PWM_STOP_KILL_MASK             ((uint32)(readTimer_1BIT_MASK        <<  \
                                                                            readTimer_PWM_STOP_KILL_SHIFT))
#define readTimer_PRESCALER_MASK                 ((uint32)(readTimer_8BIT_MASK        <<  \
                                                                            readTimer_PRESCALER_SHIFT))
#define readTimer_UPDOWN_MASK                    ((uint32)(readTimer_2BIT_MASK        <<  \
                                                                            readTimer_UPDOWN_SHIFT))
#define readTimer_ONESHOT_MASK                   ((uint32)(readTimer_1BIT_MASK        <<  \
                                                                            readTimer_ONESHOT_SHIFT))
#define readTimer_QUAD_MODE_MASK                 ((uint32)(readTimer_3BIT_MASK        <<  \
                                                                            readTimer_QUAD_MODE_SHIFT))
#define readTimer_INV_OUT_MASK                   ((uint32)(readTimer_2BIT_MASK        <<  \
                                                                            readTimer_INV_OUT_SHIFT))
#define readTimer_MODE_MASK                      ((uint32)(readTimer_3BIT_MASK        <<  \
                                                                            readTimer_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define readTimer_CAPTURE_SHIFT                  (0u)
#define readTimer_COUNT_SHIFT                    (2u)
#define readTimer_RELOAD_SHIFT                   (4u)
#define readTimer_STOP_SHIFT                     (6u)
#define readTimer_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define readTimer_CAPTURE_MASK                   ((uint32)(readTimer_2BIT_MASK        <<  \
                                                                  readTimer_CAPTURE_SHIFT))
#define readTimer_COUNT_MASK                     ((uint32)(readTimer_2BIT_MASK        <<  \
                                                                  readTimer_COUNT_SHIFT))
#define readTimer_RELOAD_MASK                    ((uint32)(readTimer_2BIT_MASK        <<  \
                                                                  readTimer_RELOAD_SHIFT))
#define readTimer_STOP_MASK                      ((uint32)(readTimer_2BIT_MASK        <<  \
                                                                  readTimer_STOP_SHIFT))
#define readTimer_START_MASK                     ((uint32)(readTimer_2BIT_MASK        <<  \
                                                                  readTimer_START_SHIFT))

/* MASK */
#define readTimer_1BIT_MASK                      ((uint32)0x01u)
#define readTimer_2BIT_MASK                      ((uint32)0x03u)
#define readTimer_3BIT_MASK                      ((uint32)0x07u)
#define readTimer_6BIT_MASK                      ((uint32)0x3Fu)
#define readTimer_8BIT_MASK                      ((uint32)0xFFu)
#define readTimer_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define readTimer_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define readTimer_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(readTimer_QUAD_ENCODING_MODES     << readTimer_QUAD_MODE_SHIFT))       |\
         ((uint32)(readTimer_CONFIG                  << readTimer_MODE_SHIFT)))

#define readTimer_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(readTimer_PWM_STOP_EVENT          << readTimer_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(readTimer_PWM_OUT_INVERT          << readTimer_INV_OUT_SHIFT))         |\
         ((uint32)(readTimer_PWM_OUT_N_INVERT        << readTimer_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(readTimer_PWM_MODE                << readTimer_MODE_SHIFT)))

#define readTimer_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(readTimer_PWM_RUN_MODE         << readTimer_ONESHOT_SHIFT))
            
#define readTimer_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(readTimer_PWM_ALIGN            << readTimer_UPDOWN_SHIFT))

#define readTimer_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(readTimer_PWM_KILL_EVENT      << readTimer_PWM_SYNC_KILL_SHIFT))

#define readTimer_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(readTimer_PWM_DEAD_TIME_CYCLE  << readTimer_PRESCALER_SHIFT))

#define readTimer_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(readTimer_PWM_PRESCALER        << readTimer_PRESCALER_SHIFT))

#define readTimer_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(readTimer_TC_PRESCALER            << readTimer_PRESCALER_SHIFT))       |\
         ((uint32)(readTimer_TC_COUNTER_MODE         << readTimer_UPDOWN_SHIFT))          |\
         ((uint32)(readTimer_TC_RUN_MODE             << readTimer_ONESHOT_SHIFT))         |\
         ((uint32)(readTimer_TC_COMP_CAP_MODE        << readTimer_MODE_SHIFT)))
        
#define readTimer_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(readTimer_QUAD_PHIA_SIGNAL_MODE   << readTimer_COUNT_SHIFT))           |\
         ((uint32)(readTimer_QUAD_INDEX_SIGNAL_MODE  << readTimer_RELOAD_SHIFT))          |\
         ((uint32)(readTimer_QUAD_STOP_SIGNAL_MODE   << readTimer_STOP_SHIFT))            |\
         ((uint32)(readTimer_QUAD_PHIB_SIGNAL_MODE   << readTimer_START_SHIFT)))

#define readTimer_PWM_SIGNALS_MODES                                                              \
        (((uint32)(readTimer_PWM_SWITCH_SIGNAL_MODE  << readTimer_CAPTURE_SHIFT))         |\
         ((uint32)(readTimer_PWM_COUNT_SIGNAL_MODE   << readTimer_COUNT_SHIFT))           |\
         ((uint32)(readTimer_PWM_RELOAD_SIGNAL_MODE  << readTimer_RELOAD_SHIFT))          |\
         ((uint32)(readTimer_PWM_STOP_SIGNAL_MODE    << readTimer_STOP_SHIFT))            |\
         ((uint32)(readTimer_PWM_START_SIGNAL_MODE   << readTimer_START_SHIFT)))

#define readTimer_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(readTimer_TC_CAPTURE_SIGNAL_MODE  << readTimer_CAPTURE_SHIFT))         |\
         ((uint32)(readTimer_TC_COUNT_SIGNAL_MODE    << readTimer_COUNT_SHIFT))           |\
         ((uint32)(readTimer_TC_RELOAD_SIGNAL_MODE   << readTimer_RELOAD_SHIFT))          |\
         ((uint32)(readTimer_TC_STOP_SIGNAL_MODE     << readTimer_STOP_SHIFT))            |\
         ((uint32)(readTimer_TC_START_SIGNAL_MODE    << readTimer_START_SHIFT)))
        
#define readTimer_TIMER_UPDOWN_CNT_USED                                                          \
                ((readTimer__COUNT_UPDOWN0 == readTimer_TC_COUNTER_MODE)                  ||\
                 (readTimer__COUNT_UPDOWN1 == readTimer_TC_COUNTER_MODE))

#define readTimer_PWM_UPDOWN_CNT_USED                                                            \
                ((readTimer__CENTER == readTimer_PWM_ALIGN)                               ||\
                 (readTimer__ASYMMETRIC == readTimer_PWM_ALIGN))               
        
#define readTimer_PWM_PR_INIT_VALUE              (1u)
#define readTimer_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_readTimer_H */

/* [] END OF FILE */
