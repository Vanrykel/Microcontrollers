/*******************************************************************************
* File Name: PWM_160Hz.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the PWM_160Hz
*  component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_160Hz.h"
#include "CyLib.h"

uint8 PWM_160Hz_initVar = 0u;


/*******************************************************************************
* Function Name: PWM_160Hz_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default PWM_160Hz configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (PWM_160Hz__QUAD == PWM_160Hz_CONFIG)
        PWM_160Hz_CONTROL_REG =
        (((uint32)(PWM_160Hz_QUAD_ENCODING_MODES     << PWM_160Hz_QUAD_MODE_SHIFT))       |
         ((uint32)(PWM_160Hz_CONFIG                  << PWM_160Hz_MODE_SHIFT)));
    #endif  /* (PWM_160Hz__QUAD == PWM_160Hz_CONFIG) */

    #if (PWM_160Hz__PWM_SEL == PWM_160Hz_CONFIG)
        PWM_160Hz_CONTROL_REG =
        (((uint32)(PWM_160Hz_PWM_STOP_EVENT          << PWM_160Hz_PWM_STOP_KILL_SHIFT))    |
         ((uint32)(PWM_160Hz_PWM_OUT_INVERT          << PWM_160Hz_INV_OUT_SHIFT))         |
         ((uint32)(PWM_160Hz_PWM_OUT_N_INVERT        << PWM_160Hz_INV_COMPL_OUT_SHIFT))     |
         ((uint32)(PWM_160Hz_PWM_MODE                << PWM_160Hz_MODE_SHIFT)));

        #if (PWM_160Hz__PWM_PR == PWM_160Hz_PWM_MODE)
            PWM_160Hz_CONTROL_REG |=
            ((uint32)(PWM_160Hz_PWM_RUN_MODE         << PWM_160Hz_ONESHOT_SHIFT));

            PWM_160Hz_WriteCounter(PWM_160Hz_PWM_PR_INIT_VALUE);
        #else
            PWM_160Hz_CONTROL_REG |=
            (((uint32)(PWM_160Hz_PWM_ALIGN           << PWM_160Hz_UPDOWN_SHIFT))          |
             ((uint32)(PWM_160Hz_PWM_KILL_EVENT      << PWM_160Hz_PWM_SYNC_KILL_SHIFT)));
        #endif  /* (PWM_160Hz__PWM_PR == PWM_160Hz_PWM_MODE) */

        #if (PWM_160Hz__PWM_DT == PWM_160Hz_PWM_MODE)
            PWM_160Hz_CONTROL_REG |=
            ((uint32)(PWM_160Hz_PWM_DEAD_TIME_CYCLE  << PWM_160Hz_PRESCALER_SHIFT));
        #endif  /* (PWM_160Hz__PWM_DT == PWM_160Hz_PWM_MODE) */

        #if (PWM_160Hz__PWM == PWM_160Hz_PWM_MODE)
            PWM_160Hz_CONTROL_REG |=
            ((uint32)PWM_160Hz_PWM_PRESCALER         << PWM_160Hz_PRESCALER_SHIFT);
        #endif  /* (PWM_160Hz__PWM == PWM_160Hz_PWM_MODE) */
    #endif  /* (PWM_160Hz__PWM_SEL == PWM_160Hz_CONFIG) */

    #if (PWM_160Hz__TIMER == PWM_160Hz_CONFIG)
        PWM_160Hz_CONTROL_REG =
        (((uint32)(PWM_160Hz_TC_PRESCALER            << PWM_160Hz_PRESCALER_SHIFT))   |
         ((uint32)(PWM_160Hz_TC_COUNTER_MODE         << PWM_160Hz_UPDOWN_SHIFT))      |
         ((uint32)(PWM_160Hz_TC_RUN_MODE             << PWM_160Hz_ONESHOT_SHIFT))     |
         ((uint32)(PWM_160Hz_TC_COMP_CAP_MODE        << PWM_160Hz_MODE_SHIFT)));
    #endif  /* (PWM_160Hz__TIMER == PWM_160Hz_CONFIG) */

    /* Set values from customizer to CTRL1 */
    #if (PWM_160Hz__QUAD == PWM_160Hz_CONFIG)
        PWM_160Hz_TRIG_CONTROL1_REG  =
        (((uint32)(PWM_160Hz_QUAD_PHIA_SIGNAL_MODE   << PWM_160Hz_COUNT_SHIFT))       |
         ((uint32)(PWM_160Hz_QUAD_INDEX_SIGNAL_MODE  << PWM_160Hz_RELOAD_SHIFT))      |
         ((uint32)(PWM_160Hz_QUAD_STOP_SIGNAL_MODE   << PWM_160Hz_STOP_SHIFT))        |
         ((uint32)(PWM_160Hz_QUAD_PHIB_SIGNAL_MODE   << PWM_160Hz_START_SHIFT)));
    #endif  /* (PWM_160Hz__QUAD == PWM_160Hz_CONFIG) */

    #if (PWM_160Hz__PWM_SEL == PWM_160Hz_CONFIG)
        PWM_160Hz_TRIG_CONTROL1_REG  =
        (((uint32)(PWM_160Hz_PWM_SWITCH_SIGNAL_MODE  << PWM_160Hz_CAPTURE_SHIFT))     |
         ((uint32)(PWM_160Hz_PWM_COUNT_SIGNAL_MODE   << PWM_160Hz_COUNT_SHIFT))       |
         ((uint32)(PWM_160Hz_PWM_RELOAD_SIGNAL_MODE  << PWM_160Hz_RELOAD_SHIFT))      |
         ((uint32)(PWM_160Hz_PWM_STOP_SIGNAL_MODE    << PWM_160Hz_STOP_SHIFT))        |
         ((uint32)(PWM_160Hz_PWM_START_SIGNAL_MODE   << PWM_160Hz_START_SHIFT)));
    #endif  /* (PWM_160Hz__PWM_SEL == PWM_160Hz_CONFIG) */

    #if (PWM_160Hz__TIMER == PWM_160Hz_CONFIG)
        PWM_160Hz_TRIG_CONTROL1_REG  =
        (((uint32)(PWM_160Hz_TC_CAPTURE_SIGNAL_MODE  << PWM_160Hz_CAPTURE_SHIFT))     |
         ((uint32)(PWM_160Hz_TC_COUNT_SIGNAL_MODE    << PWM_160Hz_COUNT_SHIFT))       |
         ((uint32)(PWM_160Hz_TC_RELOAD_SIGNAL_MODE   << PWM_160Hz_RELOAD_SHIFT))      |
         ((uint32)(PWM_160Hz_TC_STOP_SIGNAL_MODE     << PWM_160Hz_STOP_SHIFT))        |
         ((uint32)(PWM_160Hz_TC_START_SIGNAL_MODE    << PWM_160Hz_START_SHIFT)));
    #endif  /* (PWM_160Hz__TIMER == PWM_160Hz_CONFIG) */

    /* Set values from customizer to INTR */
    #if (PWM_160Hz__QUAD == PWM_160Hz_CONFIG)
        PWM_160Hz_SetInterruptMode(PWM_160Hz_QUAD_INTERRUPT_MASK);
    #endif  /* (PWM_160Hz__QUAD == PWM_160Hz_CONFIG) */

    #if (PWM_160Hz__PWM_SEL == PWM_160Hz_CONFIG)
        PWM_160Hz_SetInterruptMode(PWM_160Hz_PWM_INTERRUPT_MASK);
    #endif  /* (PWM_160Hz__PWM_SEL == PWM_160Hz_CONFIG) */

    #if (PWM_160Hz__TIMER == PWM_160Hz_CONFIG)
        PWM_160Hz_SetInterruptMode(PWM_160Hz_TC_INTERRUPT_MASK);
    #endif  /* (PWM_160Hz__TIMER == PWM_160Hz_CONFIG) */

    /* Set other values from customizer */
    #if (PWM_160Hz__TIMER == PWM_160Hz_CONFIG)
        PWM_160Hz_WritePeriod(PWM_160Hz_TC_PERIOD_VALUE );
        #if (PWM_160Hz__COMPARE == PWM_160Hz_TC_COMP_CAP_MODE)
            PWM_160Hz_WriteCompare(PWM_160Hz_TC_COMPARE_VALUE);

            #if (1u == PWM_160Hz_TC_COMPARE_SWAP)
                PWM_160Hz_SetCompareSwap(1u);
                PWM_160Hz_WriteCompareBuf(PWM_160Hz_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == PWM_160Hz_TC_COMPARE_SWAP) */
        #endif  /* (PWM_160Hz__COMPARE == PWM_160Hz_TC_COMP_CAP_MODE) */
    #endif  /* (PWM_160Hz__TIMER == PWM_160Hz_CONFIG) */

    #if (PWM_160Hz__PWM_SEL == PWM_160Hz_CONFIG)
        PWM_160Hz_WritePeriod(PWM_160Hz_PWM_PERIOD_VALUE );
        PWM_160Hz_WriteCompare(PWM_160Hz_PWM_COMPARE_VALUE);

        #if (1u == PWM_160Hz_PWM_COMPARE_SWAP)
            PWM_160Hz_SetCompareSwap(1u);
            PWM_160Hz_WriteCompareBuf(PWM_160Hz_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == PWM_160Hz_PWM_COMPARE_SWAP) */

        #if (1u == PWM_160Hz_PWM_PERIOD_SWAP)
            PWM_160Hz_SetPeriodSwap(1u);
            PWM_160Hz_WritePeriodBuf(PWM_160Hz_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == PWM_160Hz_PWM_PERIOD_SWAP) */

        /* Set values from customizer to CTRL2 */
        #if (PWM_160Hz__PWM_PR == PWM_160Hz_PWM_MODE)
            PWM_160Hz_TRIG_CONTROL2_REG =
                    (PWM_160Hz_CC_MATCH_NO_CHANGE    |
                    PWM_160Hz_OVERLOW_NO_CHANGE      |
                    PWM_160Hz_UNDERFLOW_NO_CHANGE);
        #else
            #if (PWM_160Hz__LEFT == PWM_160Hz_PWM_ALIGN)
                PWM_160Hz_TRIG_CONTROL2_REG = PWM_160Hz_PWM_MODE_LEFT;
            #endif  /* ( PWM_160Hz_PWM_LEFT == PWM_160Hz_PWM_ALIGN) */

            #if (PWM_160Hz__RIGHT == PWM_160Hz_PWM_ALIGN)
                PWM_160Hz_TRIG_CONTROL2_REG = PWM_160Hz_PWM_MODE_RIGHT;
            #endif  /* ( PWM_160Hz_PWM_RIGHT == PWM_160Hz_PWM_ALIGN) */

            #if (PWM_160Hz__CENTER == PWM_160Hz_PWM_ALIGN)
                PWM_160Hz_TRIG_CONTROL2_REG = PWM_160Hz_PWM_MODE_CENTER;
            #endif  /* ( PWM_160Hz_PWM_CENTER == PWM_160Hz_PWM_ALIGN) */

            #if (PWM_160Hz__ASYMMETRIC == PWM_160Hz_PWM_ALIGN)
                PWM_160Hz_TRIG_CONTROL2_REG = PWM_160Hz_PWM_MODE_ASYM;
            #endif  /* (PWM_160Hz__ASYMMETRIC == PWM_160Hz_PWM_ALIGN) */
        #endif  /* (PWM_160Hz__PWM_PR == PWM_160Hz_PWM_MODE) */
    #endif  /* (PWM_160Hz__PWM_SEL == PWM_160Hz_CONFIG) */
}


/*******************************************************************************
* Function Name: PWM_160Hz_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM_160Hz.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    PWM_160Hz_BLOCK_CONTROL_REG |= PWM_160Hz_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Statr Timer or PWM if start input is absent */
    #if (PWM_160Hz__PWM_SEL == PWM_160Hz_CONFIG)
        #if (0u == PWM_160Hz_PWM_START_SIGNAL_PRESENT)
            PWM_160Hz_TriggerCommand(PWM_160Hz_MASK, PWM_160Hz_CMD_START);
        #endif /* (0u == PWM_160Hz_PWM_START_SIGNAL_PRESENT) */
    #endif /* (PWM_160Hz__PWM_SEL == PWM_160Hz_CONFIG) */

    #if (PWM_160Hz__TIMER == PWM_160Hz_CONFIG)
        #if (0u == PWM_160Hz_TC_START_SIGNAL_PRESENT)
            PWM_160Hz_TriggerCommand(PWM_160Hz_MASK, PWM_160Hz_CMD_START);
        #endif /* (0u == PWM_160Hz_TC_START_SIGNAL_PRESENT) */
    #endif /* (PWM_160Hz__TIMER == PWM_160Hz_CONFIG) */
}


/*******************************************************************************
* Function Name: PWM_160Hz_Start
********************************************************************************
*
* Summary:
*  Initialize the PWM_160Hz with default customizer
*  values when called the first time and enables the PWM_160Hz.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_160Hz_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time PWM_160Hz_Start() is called. This allows
*  enable/disable component without re-initialization in all subsequent calls
*  to the PWM_160Hz_Start() routine.
*
*******************************************************************************/
void PWM_160Hz_Start(void)
{
    if (0u == PWM_160Hz_initVar)
    {
        PWM_160Hz_Init();
        PWM_160Hz_initVar = 1u;
    }

    PWM_160Hz_Enable();
}


/*******************************************************************************
* Function Name: PWM_160Hz_Stop
********************************************************************************
*
* Summary:
*  Disables the PWM_160Hz.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_BLOCK_CONTROL_REG &= (uint32)~PWM_160Hz_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the PWM_160Hz. This function is used when
*  configured as a generic PWM_160Hz and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the PWM_160Hz to operate in
*   Values:
*   - PWM_160Hz_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - PWM_160Hz_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - PWM_160Hz_MODE_QUAD - Quadrature decoder
*         - PWM_160Hz_MODE_PWM - PWM
*         - PWM_160Hz_MODE_PWM_DT - PWM with dead time
*         - PWM_160Hz_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_CONTROL_REG &= (uint32)~PWM_160Hz_MODE_MASK;
    PWM_160Hz_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of 3 supported modes.
*  Is functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - PWM_160Hz_MODE_X1 - Counts on phi 1 rising
*         - PWM_160Hz_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - PWM_160Hz_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_CONTROL_REG &= (uint32)~PWM_160Hz_QUAD_MODE_MASK;
    PWM_160Hz_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to PWM with dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - PWM_160Hz_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - PWM_160Hz_PRESCALE_DIVBY2    - Divide by 2
*         - PWM_160Hz_PRESCALE_DIVBY4    - Divide by 4
*         - PWM_160Hz_PRESCALE_DIVBY8    - Divide by 8
*         - PWM_160Hz_PRESCALE_DIVBY16   - Divide by 16
*         - PWM_160Hz_PRESCALE_DIVBY32   - Divide by 32
*         - PWM_160Hz_PRESCALE_DIVBY64   - Divide by 64
*         - PWM_160Hz_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_CONTROL_REG &= (uint32)~PWM_160Hz_PRESCALER_MASK;
    PWM_160Hz_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM_160Hz runs
*  continuously or stops when terminal count is reached.  By default the
*  PWM_160Hz operates in continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_CONTROL_REG &= (uint32)~PWM_160Hz_ONESHOT_MASK;
    PWM_160Hz_CONTROL_REG |= ((uint32)((oneShotEnable & PWM_160Hz_1BIT_MASK) <<
                                                               PWM_160Hz_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the 3 must be ORed together to form the
*  mode.
*
* Parameters:
*  modeMask: Combination of the 3 mode settings.  Mask must include a value for
*  each of the 3 or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be 
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetPWMMode(uint32 modeMask)
{
    PWM_160Hz_TRIG_CONTROL2_REG = (modeMask & PWM_160Hz_6BIT_MASK);
}



/*******************************************************************************
* Function Name: PWM_160Hz_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes an asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to PWM and
*  PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_CONTROL_REG &= (uint32)~PWM_160Hz_PWM_SYNC_KILL_MASK;
    PWM_160Hz_CONTROL_REG |= ((uint32)((syncKillEnable & PWM_160Hz_1BIT_MASK)  <<
                                               PWM_160Hz_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_CONTROL_REG &= (uint32)~PWM_160Hz_PWM_STOP_KILL_MASK;
    PWM_160Hz_CONTROL_REG |= ((uint32)((stopOnKillEnable & PWM_160Hz_1BIT_MASK)  <<
                                                         PWM_160Hz_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_CONTROL_REG &= (uint32)~PWM_160Hz_PRESCALER_MASK;
    PWM_160Hz_CONTROL_REG |= ((uint32)((deadTime & PWM_160Hz_8BIT_MASK) <<
                                                          PWM_160Hz_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - PWM_160Hz_INVERT_LINE   - Inverts the line output
*         - PWM_160Hz_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_CONTROL_REG &= (uint32)~PWM_160Hz_INV_OUT_MASK;
    PWM_160Hz_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: PWM_160Hz_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_WriteCounter(uint32 count)
{
    PWM_160Hz_COUNTER_REG = (count & PWM_160Hz_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM_160Hz_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 PWM_160Hz_ReadCounter(void)
{
    return (PWM_160Hz_COUNTER_REG & PWM_160Hz_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and PWM with pseudo random output.
*
* Parameters:
*  counterMode: Enumerated couner type values
*   Values:
*     - PWM_160Hz_COUNT_UP       - Counts up
*     - PWM_160Hz_COUNT_DOWN     - Counts down
*     - PWM_160Hz_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - PWM_160Hz_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_CONTROL_REG &= (uint32)~PWM_160Hz_UPDOWN_MASK;
    PWM_160Hz_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_WritePeriod(uint32 period)
{
    PWM_160Hz_PERIOD_REG = (period & PWM_160Hz_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM_160Hz_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 PWM_160Hz_ReadPeriod(void)
{
    return (PWM_160Hz_PERIOD_REG & PWM_160Hz_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in Timer/Counter mode(without capture) the swap occurs
*  at a TC event. In PWM mode the swap occurs at the next TC event following
*  a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_CONTROL_REG &= (uint32)~PWM_160Hz_RELOAD_CC_MASK;
    PWM_160Hz_CONTROL_REG |= (swapEnable & PWM_160Hz_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_WritePeriodBuf(uint32 periodBuf)
{
    PWM_160Hz_PERIOD_BUF_REG = (periodBuf & PWM_160Hz_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM_160Hz_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 PWM_160Hz_ReadPeriodBuf(void)
{
    return (PWM_160Hz_PERIOD_BUF_REG & PWM_160Hz_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In PWM mode the swap occurs at the next TC event following a hardware switch
*  event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_CONTROL_REG &= (uint32)~PWM_160Hz_RELOAD_PERIOD_MASK;
    PWM_160Hz_CONTROL_REG |= ((uint32)((swapEnable & PWM_160Hz_1BIT_MASK) <<
                                                            PWM_160Hz_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_WriteCompare(uint32 compare)
{
    PWM_160Hz_COMP_CAP_REG = (compare & PWM_160Hz_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM_160Hz_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
*******************************************************************************/
uint32 PWM_160Hz_ReadCompare(void)
{
    return (PWM_160Hz_COMP_CAP_REG & PWM_160Hz_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM_160Hz_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_WriteCompareBuf(uint32 compareBuf)
{
   PWM_160Hz_COMP_CAP_BUF_REG = (compareBuf & PWM_160Hz_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM_160Hz_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
*******************************************************************************/
uint32 PWM_160Hz_ReadCompareBuf(void)
{
    return (PWM_160Hz_COMP_CAP_BUF_REG & PWM_160Hz_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM_160Hz_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 PWM_160Hz_ReadCapture(void)
{
    return (PWM_160Hz_COMP_CAP_REG & PWM_160Hz_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM_160Hz_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 PWM_160Hz_ReadCaptureBuf(void)
{
    return (PWM_160Hz_COMP_CAP_BUF_REG & PWM_160Hz_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM_160Hz_TRIG_LEVEL     - Level
*     - PWM_160Hz_TRIG_RISING    - Rising edge
*     - PWM_160Hz_TRIG_FALLING   - Falling edge
*     - PWM_160Hz_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_TRIG_CONTROL1_REG &= (uint32)~PWM_160Hz_CAPTURE_MASK;
    PWM_160Hz_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM_160Hz_TRIG_LEVEL     - Level
*     - PWM_160Hz_TRIG_RISING    - Rising edge
*     - PWM_160Hz_TRIG_FALLING   - Falling edge
*     - PWM_160Hz_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_TRIG_CONTROL1_REG &= (uint32)~PWM_160Hz_RELOAD_MASK;
    PWM_160Hz_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PWM_160Hz_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM_160Hz_TRIG_LEVEL     - Level
*     - PWM_160Hz_TRIG_RISING    - Rising edge
*     - PWM_160Hz_TRIG_FALLING   - Falling edge
*     - PWM_160Hz_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_TRIG_CONTROL1_REG &= (uint32)~PWM_160Hz_START_MASK;
    PWM_160Hz_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PWM_160Hz_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM_160Hz_TRIG_LEVEL     - Level
*     - PWM_160Hz_TRIG_RISING    - Rising edge
*     - PWM_160Hz_TRIG_FALLING   - Falling edge
*     - PWM_160Hz_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_TRIG_CONTROL1_REG &= (uint32)~PWM_160Hz_STOP_MASK;
    PWM_160Hz_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PWM_160Hz_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM_160Hz_TRIG_LEVEL     - Level
*     - PWM_160Hz_TRIG_RISING    - Rising edge
*     - PWM_160Hz_TRIG_FALLING   - Falling edge
*     - PWM_160Hz_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_TRIG_CONTROL1_REG &= (uint32)~PWM_160Hz_COUNT_MASK;
    PWM_160Hz_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PWM_160Hz_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: Combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - PWM_160Hz_CMD_CAPTURE    - Trigger Capture command
*     - PWM_160Hz_CMD_RELOAD     - Trigger Reload command
*     - PWM_160Hz_CMD_STOP       - Trigger Stop command
*     - PWM_160Hz_CMD_START      - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM_160Hz_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM_160Hz_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the PWM_160Hz.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - PWM_160Hz_STATUS_DOWN    - Set if counting down
*     - PWM_160Hz_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 PWM_160Hz_ReadStatus(void)
{
    return ((PWM_160Hz_STATUS_REG >> PWM_160Hz_RUNNING_STATUS_SHIFT) |
            (PWM_160Hz_STATUS_REG & PWM_160Hz_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - PWM_160Hz_INTR_MASK_TC       - Terminal count mask
*     - PWM_160Hz_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetInterruptMode(uint32 interruptMask)
{
    PWM_160Hz_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: PWM_160Hz_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - PWM_160Hz_INTR_MASK_TC       - Terminal count mask
*     - PWM_160Hz_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PWM_160Hz_GetInterruptSourceMasked(void)
{
    return (PWM_160Hz_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: PWM_160Hz_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - PWM_160Hz_INTR_MASK_TC       - Terminal count mask
*     - PWM_160Hz_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PWM_160Hz_GetInterruptSource(void)
{
    return (PWM_160Hz_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: PWM_160Hz_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - PWM_160Hz_INTR_MASK_TC       - Terminal count mask
*     - PWM_160Hz_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_ClearInterrupt(uint32 interruptMask)
{
    PWM_160Hz_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: PWM_160Hz_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - PWM_160Hz_INTR_MASK_TC       - Terminal count mask
*     - PWM_160Hz_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PWM_160Hz_SetInterrupt(uint32 interruptMask)
{
    PWM_160Hz_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
