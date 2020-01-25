/*******************************************************************************
* File Name: readTimer.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the readTimer
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

#include "readTimer.h"

uint8 readTimer_initVar = 0u;


/*******************************************************************************
* Function Name: readTimer_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default readTimer configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (readTimer__QUAD == readTimer_CONFIG)
        readTimer_CONTROL_REG = readTimer_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        readTimer_TRIG_CONTROL1_REG  = readTimer_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        readTimer_SetInterruptMode(readTimer_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        readTimer_SetCounterMode(readTimer_COUNT_DOWN);
        readTimer_WritePeriod(readTimer_QUAD_PERIOD_INIT_VALUE);
        readTimer_WriteCounter(readTimer_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (readTimer__QUAD == readTimer_CONFIG) */

    #if (readTimer__TIMER == readTimer_CONFIG)
        readTimer_CONTROL_REG = readTimer_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        readTimer_TRIG_CONTROL1_REG  = readTimer_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        readTimer_SetInterruptMode(readTimer_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        readTimer_WritePeriod(readTimer_TC_PERIOD_VALUE );

        #if (readTimer__COMPARE == readTimer_TC_COMP_CAP_MODE)
            readTimer_WriteCompare(readTimer_TC_COMPARE_VALUE);

            #if (1u == readTimer_TC_COMPARE_SWAP)
                readTimer_SetCompareSwap(1u);
                readTimer_WriteCompareBuf(readTimer_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == readTimer_TC_COMPARE_SWAP) */
        #endif  /* (readTimer__COMPARE == readTimer_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (readTimer_CY_TCPWM_V2 && readTimer_TIMER_UPDOWN_CNT_USED && !readTimer_CY_TCPWM_4000)
            readTimer_WriteCounter(1u);
        #elif(readTimer__COUNT_DOWN == readTimer_TC_COUNTER_MODE)
            readTimer_WriteCounter(readTimer_TC_PERIOD_VALUE);
        #else
            readTimer_WriteCounter(0u);
        #endif /* (readTimer_CY_TCPWM_V2 && readTimer_TIMER_UPDOWN_CNT_USED && !readTimer_CY_TCPWM_4000) */
    #endif  /* (readTimer__TIMER == readTimer_CONFIG) */

    #if (readTimer__PWM_SEL == readTimer_CONFIG)
        readTimer_CONTROL_REG = readTimer_CTRL_PWM_BASE_CONFIG;

        #if (readTimer__PWM_PR == readTimer_PWM_MODE)
            readTimer_CONTROL_REG |= readTimer_CTRL_PWM_RUN_MODE;
            readTimer_WriteCounter(readTimer_PWM_PR_INIT_VALUE);
        #else
            readTimer_CONTROL_REG |= readTimer_CTRL_PWM_ALIGN | readTimer_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (readTimer_CY_TCPWM_V2 && readTimer_PWM_UPDOWN_CNT_USED && !readTimer_CY_TCPWM_4000)
                readTimer_WriteCounter(1u);
            #elif (readTimer__RIGHT == readTimer_PWM_ALIGN)
                readTimer_WriteCounter(readTimer_PWM_PERIOD_VALUE);
            #else 
                readTimer_WriteCounter(0u);
            #endif  /* (readTimer_CY_TCPWM_V2 && readTimer_PWM_UPDOWN_CNT_USED && !readTimer_CY_TCPWM_4000) */
        #endif  /* (readTimer__PWM_PR == readTimer_PWM_MODE) */

        #if (readTimer__PWM_DT == readTimer_PWM_MODE)
            readTimer_CONTROL_REG |= readTimer_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (readTimer__PWM_DT == readTimer_PWM_MODE) */

        #if (readTimer__PWM == readTimer_PWM_MODE)
            readTimer_CONTROL_REG |= readTimer_CTRL_PWM_PRESCALER;
        #endif  /* (readTimer__PWM == readTimer_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        readTimer_TRIG_CONTROL1_REG  = readTimer_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        readTimer_SetInterruptMode(readTimer_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (readTimer__PWM_PR == readTimer_PWM_MODE)
            readTimer_TRIG_CONTROL2_REG =
                    (readTimer_CC_MATCH_NO_CHANGE    |
                    readTimer_OVERLOW_NO_CHANGE      |
                    readTimer_UNDERFLOW_NO_CHANGE);
        #else
            #if (readTimer__LEFT == readTimer_PWM_ALIGN)
                readTimer_TRIG_CONTROL2_REG = readTimer_PWM_MODE_LEFT;
            #endif  /* ( readTimer_PWM_LEFT == readTimer_PWM_ALIGN) */

            #if (readTimer__RIGHT == readTimer_PWM_ALIGN)
                readTimer_TRIG_CONTROL2_REG = readTimer_PWM_MODE_RIGHT;
            #endif  /* ( readTimer_PWM_RIGHT == readTimer_PWM_ALIGN) */

            #if (readTimer__CENTER == readTimer_PWM_ALIGN)
                readTimer_TRIG_CONTROL2_REG = readTimer_PWM_MODE_CENTER;
            #endif  /* ( readTimer_PWM_CENTER == readTimer_PWM_ALIGN) */

            #if (readTimer__ASYMMETRIC == readTimer_PWM_ALIGN)
                readTimer_TRIG_CONTROL2_REG = readTimer_PWM_MODE_ASYM;
            #endif  /* (readTimer__ASYMMETRIC == readTimer_PWM_ALIGN) */
        #endif  /* (readTimer__PWM_PR == readTimer_PWM_MODE) */

        /* Set other values from customizer */
        readTimer_WritePeriod(readTimer_PWM_PERIOD_VALUE );
        readTimer_WriteCompare(readTimer_PWM_COMPARE_VALUE);

        #if (1u == readTimer_PWM_COMPARE_SWAP)
            readTimer_SetCompareSwap(1u);
            readTimer_WriteCompareBuf(readTimer_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == readTimer_PWM_COMPARE_SWAP) */

        #if (1u == readTimer_PWM_PERIOD_SWAP)
            readTimer_SetPeriodSwap(1u);
            readTimer_WritePeriodBuf(readTimer_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == readTimer_PWM_PERIOD_SWAP) */
    #endif  /* (readTimer__PWM_SEL == readTimer_CONFIG) */
    
}


/*******************************************************************************
* Function Name: readTimer_Enable
********************************************************************************
*
* Summary:
*  Enables the readTimer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    readTimer_BLOCK_CONTROL_REG |= readTimer_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (readTimer__PWM_SEL == readTimer_CONFIG)
        #if (0u == readTimer_PWM_START_SIGNAL_PRESENT)
            readTimer_TriggerCommand(readTimer_MASK, readTimer_CMD_START);
        #endif /* (0u == readTimer_PWM_START_SIGNAL_PRESENT) */
    #endif /* (readTimer__PWM_SEL == readTimer_CONFIG) */

    #if (readTimer__TIMER == readTimer_CONFIG)
        #if (0u == readTimer_TC_START_SIGNAL_PRESENT)
            readTimer_TriggerCommand(readTimer_MASK, readTimer_CMD_START);
        #endif /* (0u == readTimer_TC_START_SIGNAL_PRESENT) */
    #endif /* (readTimer__TIMER == readTimer_CONFIG) */
    
    #if (readTimer__QUAD == readTimer_CONFIG)
        #if (0u != readTimer_QUAD_AUTO_START)
            readTimer_TriggerCommand(readTimer_MASK, readTimer_CMD_RELOAD);
        #endif /* (0u != readTimer_QUAD_AUTO_START) */
    #endif  /* (readTimer__QUAD == readTimer_CONFIG) */
}


/*******************************************************************************
* Function Name: readTimer_Start
********************************************************************************
*
* Summary:
*  Initializes the readTimer with default customizer
*  values when called the first time and enables the readTimer.
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
*  readTimer_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time readTimer_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the readTimer_Start() routine.
*
*******************************************************************************/
void readTimer_Start(void)
{
    if (0u == readTimer_initVar)
    {
        readTimer_Init();
        readTimer_initVar = 1u;
    }

    readTimer_Enable();
}


/*******************************************************************************
* Function Name: readTimer_Stop
********************************************************************************
*
* Summary:
*  Disables the readTimer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_BLOCK_CONTROL_REG &= (uint32)~readTimer_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the readTimer. This function is used when
*  configured as a generic readTimer and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the readTimer to operate in
*   Values:
*   - readTimer_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - readTimer_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - readTimer_MODE_QUAD - Quadrature decoder
*         - readTimer_MODE_PWM - PWM
*         - readTimer_MODE_PWM_DT - PWM with dead time
*         - readTimer_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_CONTROL_REG &= (uint32)~readTimer_MODE_MASK;
    readTimer_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - readTimer_MODE_X1 - Counts on phi 1 rising
*         - readTimer_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - readTimer_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_CONTROL_REG &= (uint32)~readTimer_QUAD_MODE_MASK;
    readTimer_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - readTimer_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - readTimer_PRESCALE_DIVBY2    - Divide by 2
*         - readTimer_PRESCALE_DIVBY4    - Divide by 4
*         - readTimer_PRESCALE_DIVBY8    - Divide by 8
*         - readTimer_PRESCALE_DIVBY16   - Divide by 16
*         - readTimer_PRESCALE_DIVBY32   - Divide by 32
*         - readTimer_PRESCALE_DIVBY64   - Divide by 64
*         - readTimer_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_CONTROL_REG &= (uint32)~readTimer_PRESCALER_MASK;
    readTimer_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the readTimer runs
*  continuously or stops when terminal count is reached.  By default the
*  readTimer operates in the continuous mode.
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
void readTimer_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_CONTROL_REG &= (uint32)~readTimer_ONESHOT_MASK;
    readTimer_CONTROL_REG |= ((uint32)((oneShotEnable & readTimer_1BIT_MASK) <<
                                                               readTimer_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_SetPWMMode
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
void readTimer_SetPWMMode(uint32 modeMask)
{
    readTimer_TRIG_CONTROL2_REG = (modeMask & readTimer_6BIT_MASK);
}



/*******************************************************************************
* Function Name: readTimer_SetPWMSyncKill
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
void readTimer_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_CONTROL_REG &= (uint32)~readTimer_PWM_SYNC_KILL_MASK;
    readTimer_CONTROL_REG |= ((uint32)((syncKillEnable & readTimer_1BIT_MASK)  <<
                                               readTimer_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_SetPWMStopOnKill
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
void readTimer_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_CONTROL_REG &= (uint32)~readTimer_PWM_STOP_KILL_MASK;
    readTimer_CONTROL_REG |= ((uint32)((stopOnKillEnable & readTimer_1BIT_MASK)  <<
                                                         readTimer_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_SetPWMDeadTime
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
void readTimer_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_CONTROL_REG &= (uint32)~readTimer_PRESCALER_MASK;
    readTimer_CONTROL_REG |= ((uint32)((deadTime & readTimer_8BIT_MASK) <<
                                                          readTimer_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_SetPWMInvert
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
*         - readTimer_INVERT_LINE   - Inverts the line output
*         - readTimer_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_CONTROL_REG &= (uint32)~readTimer_INV_OUT_MASK;
    readTimer_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: readTimer_WriteCounter
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
void readTimer_WriteCounter(uint32 count)
{
    readTimer_COUNTER_REG = (count & readTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: readTimer_ReadCounter
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
uint32 readTimer_ReadCounter(void)
{
    return (readTimer_COUNTER_REG & readTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: readTimer_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - readTimer_COUNT_UP       - Counts up
*     - readTimer_COUNT_DOWN     - Counts down
*     - readTimer_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - readTimer_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_CONTROL_REG &= (uint32)~readTimer_UPDOWN_MASK;
    readTimer_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_WritePeriod
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
void readTimer_WritePeriod(uint32 period)
{
    readTimer_PERIOD_REG = (period & readTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: readTimer_ReadPeriod
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
uint32 readTimer_ReadPeriod(void)
{
    return (readTimer_PERIOD_REG & readTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: readTimer_SetCompareSwap
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
void readTimer_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_CONTROL_REG &= (uint32)~readTimer_RELOAD_CC_MASK;
    readTimer_CONTROL_REG |= (swapEnable & readTimer_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_WritePeriodBuf
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
void readTimer_WritePeriodBuf(uint32 periodBuf)
{
    readTimer_PERIOD_BUF_REG = (periodBuf & readTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: readTimer_ReadPeriodBuf
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
uint32 readTimer_ReadPeriodBuf(void)
{
    return (readTimer_PERIOD_BUF_REG & readTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: readTimer_SetPeriodSwap
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
void readTimer_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_CONTROL_REG &= (uint32)~readTimer_RELOAD_PERIOD_MASK;
    readTimer_CONTROL_REG |= ((uint32)((swapEnable & readTimer_1BIT_MASK) <<
                                                            readTimer_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_WriteCompare
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
void readTimer_WriteCompare(uint32 compare)
{
    #if (readTimer_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (readTimer_CY_TCPWM_4000) */

    #if (readTimer_CY_TCPWM_4000)
        currentMode = ((readTimer_CONTROL_REG & readTimer_UPDOWN_MASK) >> readTimer_UPDOWN_SHIFT);

        if (((uint32)readTimer__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)readTimer__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (readTimer_CY_TCPWM_4000) */
    
    readTimer_COMP_CAP_REG = (compare & readTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: readTimer_ReadCompare
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
uint32 readTimer_ReadCompare(void)
{
    #if (readTimer_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (readTimer_CY_TCPWM_4000) */

    #if (readTimer_CY_TCPWM_4000)
        currentMode = ((readTimer_CONTROL_REG & readTimer_UPDOWN_MASK) >> readTimer_UPDOWN_SHIFT);
        
        regVal = readTimer_COMP_CAP_REG;
        
        if (((uint32)readTimer__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)readTimer__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & readTimer_16BIT_MASK);
    #else
        return (readTimer_COMP_CAP_REG & readTimer_16BIT_MASK);
    #endif /* (readTimer_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: readTimer_WriteCompareBuf
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
void readTimer_WriteCompareBuf(uint32 compareBuf)
{
    #if (readTimer_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (readTimer_CY_TCPWM_4000) */

    #if (readTimer_CY_TCPWM_4000)
        currentMode = ((readTimer_CONTROL_REG & readTimer_UPDOWN_MASK) >> readTimer_UPDOWN_SHIFT);

        if (((uint32)readTimer__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)readTimer__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (readTimer_CY_TCPWM_4000) */
    
    readTimer_COMP_CAP_BUF_REG = (compareBuf & readTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: readTimer_ReadCompareBuf
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
uint32 readTimer_ReadCompareBuf(void)
{
    #if (readTimer_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (readTimer_CY_TCPWM_4000) */

    #if (readTimer_CY_TCPWM_4000)
        currentMode = ((readTimer_CONTROL_REG & readTimer_UPDOWN_MASK) >> readTimer_UPDOWN_SHIFT);

        regVal = readTimer_COMP_CAP_BUF_REG;
        
        if (((uint32)readTimer__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)readTimer__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & readTimer_16BIT_MASK);
    #else
        return (readTimer_COMP_CAP_BUF_REG & readTimer_16BIT_MASK);
    #endif /* (readTimer_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: readTimer_ReadCapture
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
uint32 readTimer_ReadCapture(void)
{
    return (readTimer_COMP_CAP_REG & readTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: readTimer_ReadCaptureBuf
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
uint32 readTimer_ReadCaptureBuf(void)
{
    return (readTimer_COMP_CAP_BUF_REG & readTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: readTimer_SetCaptureMode
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
*     - readTimer_TRIG_LEVEL     - Level
*     - readTimer_TRIG_RISING    - Rising edge
*     - readTimer_TRIG_FALLING   - Falling edge
*     - readTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_TRIG_CONTROL1_REG &= (uint32)~readTimer_CAPTURE_MASK;
    readTimer_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - readTimer_TRIG_LEVEL     - Level
*     - readTimer_TRIG_RISING    - Rising edge
*     - readTimer_TRIG_FALLING   - Falling edge
*     - readTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_TRIG_CONTROL1_REG &= (uint32)~readTimer_RELOAD_MASK;
    readTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << readTimer_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - readTimer_TRIG_LEVEL     - Level
*     - readTimer_TRIG_RISING    - Rising edge
*     - readTimer_TRIG_FALLING   - Falling edge
*     - readTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_TRIG_CONTROL1_REG &= (uint32)~readTimer_START_MASK;
    readTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << readTimer_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - readTimer_TRIG_LEVEL     - Level
*     - readTimer_TRIG_RISING    - Rising edge
*     - readTimer_TRIG_FALLING   - Falling edge
*     - readTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_TRIG_CONTROL1_REG &= (uint32)~readTimer_STOP_MASK;
    readTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << readTimer_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - readTimer_TRIG_LEVEL     - Level
*     - readTimer_TRIG_RISING    - Rising edge
*     - readTimer_TRIG_FALLING   - Falling edge
*     - readTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_TRIG_CONTROL1_REG &= (uint32)~readTimer_COUNT_MASK;
    readTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << readTimer_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_TriggerCommand
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
*     - readTimer_CMD_CAPTURE    - Trigger Capture/Switch command
*     - readTimer_CMD_RELOAD     - Trigger Reload/Index command
*     - readTimer_CMD_STOP       - Trigger Stop/Kill command
*     - readTimer_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    readTimer_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: readTimer_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the readTimer.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - readTimer_STATUS_DOWN    - Set if counting down
*     - readTimer_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 readTimer_ReadStatus(void)
{
    return ((readTimer_STATUS_REG >> readTimer_RUNNING_STATUS_SHIFT) |
            (readTimer_STATUS_REG & readTimer_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: readTimer_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - readTimer_INTR_MASK_TC       - Terminal count mask
*     - readTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_SetInterruptMode(uint32 interruptMask)
{
    readTimer_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: readTimer_GetInterruptSourceMasked
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
*     - readTimer_INTR_MASK_TC       - Terminal count mask
*     - readTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 readTimer_GetInterruptSourceMasked(void)
{
    return (readTimer_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: readTimer_GetInterruptSource
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
*     - readTimer_INTR_MASK_TC       - Terminal count mask
*     - readTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 readTimer_GetInterruptSource(void)
{
    return (readTimer_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: readTimer_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - readTimer_INTR_MASK_TC       - Terminal count mask
*     - readTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_ClearInterrupt(uint32 interruptMask)
{
    readTimer_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: readTimer_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - readTimer_INTR_MASK_TC       - Terminal count mask
*     - readTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void readTimer_SetInterrupt(uint32 interruptMask)
{
    readTimer_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
