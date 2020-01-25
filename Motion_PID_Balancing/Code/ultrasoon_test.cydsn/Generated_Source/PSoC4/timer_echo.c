/*******************************************************************************
* File Name: timer_echo.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the timer_echo
*  component
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

#include "timer_echo.h"

uint8 timer_echo_initVar = 0u;


/*******************************************************************************
* Function Name: timer_echo_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default timer_echo configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (timer_echo__QUAD == timer_echo_CONFIG)
        timer_echo_CONTROL_REG = timer_echo_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        timer_echo_TRIG_CONTROL1_REG  = timer_echo_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        timer_echo_SetInterruptMode(timer_echo_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        timer_echo_SetCounterMode(timer_echo_COUNT_DOWN);
        timer_echo_WritePeriod(timer_echo_QUAD_PERIOD_INIT_VALUE);
        timer_echo_WriteCounter(timer_echo_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (timer_echo__QUAD == timer_echo_CONFIG) */

    #if (timer_echo__TIMER == timer_echo_CONFIG)
        timer_echo_CONTROL_REG = timer_echo_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        timer_echo_TRIG_CONTROL1_REG  = timer_echo_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        timer_echo_SetInterruptMode(timer_echo_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        timer_echo_WritePeriod(timer_echo_TC_PERIOD_VALUE );

        #if (timer_echo__COMPARE == timer_echo_TC_COMP_CAP_MODE)
            timer_echo_WriteCompare(timer_echo_TC_COMPARE_VALUE);

            #if (1u == timer_echo_TC_COMPARE_SWAP)
                timer_echo_SetCompareSwap(1u);
                timer_echo_WriteCompareBuf(timer_echo_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == timer_echo_TC_COMPARE_SWAP) */
        #endif  /* (timer_echo__COMPARE == timer_echo_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (timer_echo_CY_TCPWM_V2 && timer_echo_TIMER_UPDOWN_CNT_USED && !timer_echo_CY_TCPWM_4000)
            timer_echo_WriteCounter(1u);
        #elif(timer_echo__COUNT_DOWN == timer_echo_TC_COUNTER_MODE)
            timer_echo_WriteCounter(timer_echo_TC_PERIOD_VALUE);
        #else
            timer_echo_WriteCounter(0u);
        #endif /* (timer_echo_CY_TCPWM_V2 && timer_echo_TIMER_UPDOWN_CNT_USED && !timer_echo_CY_TCPWM_4000) */
    #endif  /* (timer_echo__TIMER == timer_echo_CONFIG) */

    #if (timer_echo__PWM_SEL == timer_echo_CONFIG)
        timer_echo_CONTROL_REG = timer_echo_CTRL_PWM_BASE_CONFIG;

        #if (timer_echo__PWM_PR == timer_echo_PWM_MODE)
            timer_echo_CONTROL_REG |= timer_echo_CTRL_PWM_RUN_MODE;
            timer_echo_WriteCounter(timer_echo_PWM_PR_INIT_VALUE);
        #else
            timer_echo_CONTROL_REG |= timer_echo_CTRL_PWM_ALIGN | timer_echo_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (timer_echo_CY_TCPWM_V2 && timer_echo_PWM_UPDOWN_CNT_USED && !timer_echo_CY_TCPWM_4000)
                timer_echo_WriteCounter(1u);
            #elif (timer_echo__RIGHT == timer_echo_PWM_ALIGN)
                timer_echo_WriteCounter(timer_echo_PWM_PERIOD_VALUE);
            #else 
                timer_echo_WriteCounter(0u);
            #endif  /* (timer_echo_CY_TCPWM_V2 && timer_echo_PWM_UPDOWN_CNT_USED && !timer_echo_CY_TCPWM_4000) */
        #endif  /* (timer_echo__PWM_PR == timer_echo_PWM_MODE) */

        #if (timer_echo__PWM_DT == timer_echo_PWM_MODE)
            timer_echo_CONTROL_REG |= timer_echo_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (timer_echo__PWM_DT == timer_echo_PWM_MODE) */

        #if (timer_echo__PWM == timer_echo_PWM_MODE)
            timer_echo_CONTROL_REG |= timer_echo_CTRL_PWM_PRESCALER;
        #endif  /* (timer_echo__PWM == timer_echo_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        timer_echo_TRIG_CONTROL1_REG  = timer_echo_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        timer_echo_SetInterruptMode(timer_echo_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (timer_echo__PWM_PR == timer_echo_PWM_MODE)
            timer_echo_TRIG_CONTROL2_REG =
                    (timer_echo_CC_MATCH_NO_CHANGE    |
                    timer_echo_OVERLOW_NO_CHANGE      |
                    timer_echo_UNDERFLOW_NO_CHANGE);
        #else
            #if (timer_echo__LEFT == timer_echo_PWM_ALIGN)
                timer_echo_TRIG_CONTROL2_REG = timer_echo_PWM_MODE_LEFT;
            #endif  /* ( timer_echo_PWM_LEFT == timer_echo_PWM_ALIGN) */

            #if (timer_echo__RIGHT == timer_echo_PWM_ALIGN)
                timer_echo_TRIG_CONTROL2_REG = timer_echo_PWM_MODE_RIGHT;
            #endif  /* ( timer_echo_PWM_RIGHT == timer_echo_PWM_ALIGN) */

            #if (timer_echo__CENTER == timer_echo_PWM_ALIGN)
                timer_echo_TRIG_CONTROL2_REG = timer_echo_PWM_MODE_CENTER;
            #endif  /* ( timer_echo_PWM_CENTER == timer_echo_PWM_ALIGN) */

            #if (timer_echo__ASYMMETRIC == timer_echo_PWM_ALIGN)
                timer_echo_TRIG_CONTROL2_REG = timer_echo_PWM_MODE_ASYM;
            #endif  /* (timer_echo__ASYMMETRIC == timer_echo_PWM_ALIGN) */
        #endif  /* (timer_echo__PWM_PR == timer_echo_PWM_MODE) */

        /* Set other values from customizer */
        timer_echo_WritePeriod(timer_echo_PWM_PERIOD_VALUE );
        timer_echo_WriteCompare(timer_echo_PWM_COMPARE_VALUE);

        #if (1u == timer_echo_PWM_COMPARE_SWAP)
            timer_echo_SetCompareSwap(1u);
            timer_echo_WriteCompareBuf(timer_echo_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == timer_echo_PWM_COMPARE_SWAP) */

        #if (1u == timer_echo_PWM_PERIOD_SWAP)
            timer_echo_SetPeriodSwap(1u);
            timer_echo_WritePeriodBuf(timer_echo_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == timer_echo_PWM_PERIOD_SWAP) */
    #endif  /* (timer_echo__PWM_SEL == timer_echo_CONFIG) */
    
}


/*******************************************************************************
* Function Name: timer_echo_Enable
********************************************************************************
*
* Summary:
*  Enables the timer_echo.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    timer_echo_BLOCK_CONTROL_REG |= timer_echo_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (timer_echo__PWM_SEL == timer_echo_CONFIG)
        #if (0u == timer_echo_PWM_START_SIGNAL_PRESENT)
            timer_echo_TriggerCommand(timer_echo_MASK, timer_echo_CMD_START);
        #endif /* (0u == timer_echo_PWM_START_SIGNAL_PRESENT) */
    #endif /* (timer_echo__PWM_SEL == timer_echo_CONFIG) */

    #if (timer_echo__TIMER == timer_echo_CONFIG)
        #if (0u == timer_echo_TC_START_SIGNAL_PRESENT)
            timer_echo_TriggerCommand(timer_echo_MASK, timer_echo_CMD_START);
        #endif /* (0u == timer_echo_TC_START_SIGNAL_PRESENT) */
    #endif /* (timer_echo__TIMER == timer_echo_CONFIG) */
    
    #if (timer_echo__QUAD == timer_echo_CONFIG)
        #if (0u != timer_echo_QUAD_AUTO_START)
            timer_echo_TriggerCommand(timer_echo_MASK, timer_echo_CMD_RELOAD);
        #endif /* (0u != timer_echo_QUAD_AUTO_START) */
    #endif  /* (timer_echo__QUAD == timer_echo_CONFIG) */
}


/*******************************************************************************
* Function Name: timer_echo_Start
********************************************************************************
*
* Summary:
*  Initializes the timer_echo with default customizer
*  values when called the first time and enables the timer_echo.
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
*  timer_echo_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time timer_echo_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the timer_echo_Start() routine.
*
*******************************************************************************/
void timer_echo_Start(void)
{
    if (0u == timer_echo_initVar)
    {
        timer_echo_Init();
        timer_echo_initVar = 1u;
    }

    timer_echo_Enable();
}


/*******************************************************************************
* Function Name: timer_echo_Stop
********************************************************************************
*
* Summary:
*  Disables the timer_echo.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_BLOCK_CONTROL_REG &= (uint32)~timer_echo_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the timer_echo. This function is used when
*  configured as a generic timer_echo and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the timer_echo to operate in
*   Values:
*   - timer_echo_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - timer_echo_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - timer_echo_MODE_QUAD - Quadrature decoder
*         - timer_echo_MODE_PWM - PWM
*         - timer_echo_MODE_PWM_DT - PWM with dead time
*         - timer_echo_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_CONTROL_REG &= (uint32)~timer_echo_MODE_MASK;
    timer_echo_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - timer_echo_MODE_X1 - Counts on phi 1 rising
*         - timer_echo_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - timer_echo_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_CONTROL_REG &= (uint32)~timer_echo_QUAD_MODE_MASK;
    timer_echo_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - timer_echo_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - timer_echo_PRESCALE_DIVBY2    - Divide by 2
*         - timer_echo_PRESCALE_DIVBY4    - Divide by 4
*         - timer_echo_PRESCALE_DIVBY8    - Divide by 8
*         - timer_echo_PRESCALE_DIVBY16   - Divide by 16
*         - timer_echo_PRESCALE_DIVBY32   - Divide by 32
*         - timer_echo_PRESCALE_DIVBY64   - Divide by 64
*         - timer_echo_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_CONTROL_REG &= (uint32)~timer_echo_PRESCALER_MASK;
    timer_echo_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the timer_echo runs
*  continuously or stops when terminal count is reached.  By default the
*  timer_echo operates in the continuous mode.
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
void timer_echo_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_CONTROL_REG &= (uint32)~timer_echo_ONESHOT_MASK;
    timer_echo_CONTROL_REG |= ((uint32)((oneShotEnable & timer_echo_1BIT_MASK) <<
                                                               timer_echo_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
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
void timer_echo_SetPWMMode(uint32 modeMask)
{
    timer_echo_TRIG_CONTROL2_REG = (modeMask & timer_echo_6BIT_MASK);
}



/*******************************************************************************
* Function Name: timer_echo_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
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
void timer_echo_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_CONTROL_REG &= (uint32)~timer_echo_PWM_SYNC_KILL_MASK;
    timer_echo_CONTROL_REG |= ((uint32)((syncKillEnable & timer_echo_1BIT_MASK)  <<
                                               timer_echo_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_SetPWMStopOnKill
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
void timer_echo_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_CONTROL_REG &= (uint32)~timer_echo_PWM_STOP_KILL_MASK;
    timer_echo_CONTROL_REG |= ((uint32)((stopOnKillEnable & timer_echo_1BIT_MASK)  <<
                                                         timer_echo_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_CONTROL_REG &= (uint32)~timer_echo_PRESCALER_MASK;
    timer_echo_CONTROL_REG |= ((uint32)((deadTime & timer_echo_8BIT_MASK) <<
                                                          timer_echo_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_SetPWMInvert
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
*         - timer_echo_INVERT_LINE   - Inverts the line output
*         - timer_echo_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_CONTROL_REG &= (uint32)~timer_echo_INV_OUT_MASK;
    timer_echo_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: timer_echo_WriteCounter
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
void timer_echo_WriteCounter(uint32 count)
{
    timer_echo_COUNTER_REG = (count & timer_echo_16BIT_MASK);
}


/*******************************************************************************
* Function Name: timer_echo_ReadCounter
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
uint32 timer_echo_ReadCounter(void)
{
    return (timer_echo_COUNTER_REG & timer_echo_16BIT_MASK);
}


/*******************************************************************************
* Function Name: timer_echo_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - timer_echo_COUNT_UP       - Counts up
*     - timer_echo_COUNT_DOWN     - Counts down
*     - timer_echo_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - timer_echo_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_CONTROL_REG &= (uint32)~timer_echo_UPDOWN_MASK;
    timer_echo_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_WritePeriod
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
void timer_echo_WritePeriod(uint32 period)
{
    timer_echo_PERIOD_REG = (period & timer_echo_16BIT_MASK);
}


/*******************************************************************************
* Function Name: timer_echo_ReadPeriod
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
uint32 timer_echo_ReadPeriod(void)
{
    return (timer_echo_PERIOD_REG & timer_echo_16BIT_MASK);
}


/*******************************************************************************
* Function Name: timer_echo_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
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
void timer_echo_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_CONTROL_REG &= (uint32)~timer_echo_RELOAD_CC_MASK;
    timer_echo_CONTROL_REG |= (swapEnable & timer_echo_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_WritePeriodBuf
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
void timer_echo_WritePeriodBuf(uint32 periodBuf)
{
    timer_echo_PERIOD_BUF_REG = (periodBuf & timer_echo_16BIT_MASK);
}


/*******************************************************************************
* Function Name: timer_echo_ReadPeriodBuf
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
uint32 timer_echo_ReadPeriodBuf(void)
{
    return (timer_echo_PERIOD_BUF_REG & timer_echo_16BIT_MASK);
}


/*******************************************************************************
* Function Name: timer_echo_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
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
void timer_echo_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_CONTROL_REG &= (uint32)~timer_echo_RELOAD_PERIOD_MASK;
    timer_echo_CONTROL_REG |= ((uint32)((swapEnable & timer_echo_1BIT_MASK) <<
                                                            timer_echo_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_WriteCompare
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
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void timer_echo_WriteCompare(uint32 compare)
{
    #if (timer_echo_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (timer_echo_CY_TCPWM_4000) */

    #if (timer_echo_CY_TCPWM_4000)
        currentMode = ((timer_echo_CONTROL_REG & timer_echo_UPDOWN_MASK) >> timer_echo_UPDOWN_SHIFT);

        if (((uint32)timer_echo__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)timer_echo__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (timer_echo_CY_TCPWM_4000) */
    
    timer_echo_COMP_CAP_REG = (compare & timer_echo_16BIT_MASK);
}


/*******************************************************************************
* Function Name: timer_echo_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 timer_echo_ReadCompare(void)
{
    #if (timer_echo_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (timer_echo_CY_TCPWM_4000) */

    #if (timer_echo_CY_TCPWM_4000)
        currentMode = ((timer_echo_CONTROL_REG & timer_echo_UPDOWN_MASK) >> timer_echo_UPDOWN_SHIFT);
        
        regVal = timer_echo_COMP_CAP_REG;
        
        if (((uint32)timer_echo__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)timer_echo__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & timer_echo_16BIT_MASK);
    #else
        return (timer_echo_COMP_CAP_REG & timer_echo_16BIT_MASK);
    #endif /* (timer_echo_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: timer_echo_WriteCompareBuf
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
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void timer_echo_WriteCompareBuf(uint32 compareBuf)
{
    #if (timer_echo_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (timer_echo_CY_TCPWM_4000) */

    #if (timer_echo_CY_TCPWM_4000)
        currentMode = ((timer_echo_CONTROL_REG & timer_echo_UPDOWN_MASK) >> timer_echo_UPDOWN_SHIFT);

        if (((uint32)timer_echo__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)timer_echo__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (timer_echo_CY_TCPWM_4000) */
    
    timer_echo_COMP_CAP_BUF_REG = (compareBuf & timer_echo_16BIT_MASK);
}


/*******************************************************************************
* Function Name: timer_echo_ReadCompareBuf
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
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 timer_echo_ReadCompareBuf(void)
{
    #if (timer_echo_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (timer_echo_CY_TCPWM_4000) */

    #if (timer_echo_CY_TCPWM_4000)
        currentMode = ((timer_echo_CONTROL_REG & timer_echo_UPDOWN_MASK) >> timer_echo_UPDOWN_SHIFT);

        regVal = timer_echo_COMP_CAP_BUF_REG;
        
        if (((uint32)timer_echo__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)timer_echo__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & timer_echo_16BIT_MASK);
    #else
        return (timer_echo_COMP_CAP_BUF_REG & timer_echo_16BIT_MASK);
    #endif /* (timer_echo_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: timer_echo_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 timer_echo_ReadCapture(void)
{
    return (timer_echo_COMP_CAP_REG & timer_echo_16BIT_MASK);
}


/*******************************************************************************
* Function Name: timer_echo_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 timer_echo_ReadCaptureBuf(void)
{
    return (timer_echo_COMP_CAP_BUF_REG & timer_echo_16BIT_MASK);
}


/*******************************************************************************
* Function Name: timer_echo_SetCaptureMode
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
*     - timer_echo_TRIG_LEVEL     - Level
*     - timer_echo_TRIG_RISING    - Rising edge
*     - timer_echo_TRIG_FALLING   - Falling edge
*     - timer_echo_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_TRIG_CONTROL1_REG &= (uint32)~timer_echo_CAPTURE_MASK;
    timer_echo_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - timer_echo_TRIG_LEVEL     - Level
*     - timer_echo_TRIG_RISING    - Rising edge
*     - timer_echo_TRIG_FALLING   - Falling edge
*     - timer_echo_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_TRIG_CONTROL1_REG &= (uint32)~timer_echo_RELOAD_MASK;
    timer_echo_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << timer_echo_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - timer_echo_TRIG_LEVEL     - Level
*     - timer_echo_TRIG_RISING    - Rising edge
*     - timer_echo_TRIG_FALLING   - Falling edge
*     - timer_echo_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_TRIG_CONTROL1_REG &= (uint32)~timer_echo_START_MASK;
    timer_echo_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << timer_echo_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - timer_echo_TRIG_LEVEL     - Level
*     - timer_echo_TRIG_RISING    - Rising edge
*     - timer_echo_TRIG_FALLING   - Falling edge
*     - timer_echo_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_TRIG_CONTROL1_REG &= (uint32)~timer_echo_STOP_MASK;
    timer_echo_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << timer_echo_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - timer_echo_TRIG_LEVEL     - Level
*     - timer_echo_TRIG_RISING    - Rising edge
*     - timer_echo_TRIG_FALLING   - Falling edge
*     - timer_echo_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_TRIG_CONTROL1_REG &= (uint32)~timer_echo_COUNT_MASK;
    timer_echo_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << timer_echo_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - timer_echo_CMD_CAPTURE    - Trigger Capture/Switch command
*     - timer_echo_CMD_RELOAD     - Trigger Reload/Index command
*     - timer_echo_CMD_STOP       - Trigger Stop/Kill command
*     - timer_echo_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    timer_echo_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: timer_echo_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the timer_echo.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - timer_echo_STATUS_DOWN    - Set if counting down
*     - timer_echo_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 timer_echo_ReadStatus(void)
{
    return ((timer_echo_STATUS_REG >> timer_echo_RUNNING_STATUS_SHIFT) |
            (timer_echo_STATUS_REG & timer_echo_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: timer_echo_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - timer_echo_INTR_MASK_TC       - Terminal count mask
*     - timer_echo_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetInterruptMode(uint32 interruptMask)
{
    timer_echo_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: timer_echo_GetInterruptSourceMasked
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
*     - timer_echo_INTR_MASK_TC       - Terminal count mask
*     - timer_echo_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 timer_echo_GetInterruptSourceMasked(void)
{
    return (timer_echo_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: timer_echo_GetInterruptSource
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
*     - timer_echo_INTR_MASK_TC       - Terminal count mask
*     - timer_echo_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 timer_echo_GetInterruptSource(void)
{
    return (timer_echo_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: timer_echo_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - timer_echo_INTR_MASK_TC       - Terminal count mask
*     - timer_echo_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_ClearInterrupt(uint32 interruptMask)
{
    timer_echo_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: timer_echo_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - timer_echo_INTR_MASK_TC       - Terminal count mask
*     - timer_echo_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void timer_echo_SetInterrupt(uint32 interruptMask)
{
    timer_echo_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
