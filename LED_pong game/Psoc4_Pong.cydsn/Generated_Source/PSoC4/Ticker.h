/*******************************************************************************
* File Name: Ticker.h
* Version 2.80
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_TIMER_Ticker_H)
#define CY_TIMER_Ticker_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Ticker_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define Ticker_Resolution                 16u
#define Ticker_UsingFixedFunction         0u
#define Ticker_UsingHWCaptureCounter      0u
#define Ticker_SoftwareCaptureMode        0u
#define Ticker_SoftwareTriggerMode        0u
#define Ticker_UsingHWEnable              0u
#define Ticker_EnableTriggerMode          0u
#define Ticker_InterruptOnCaptureCount    0u
#define Ticker_RunModeUsed                0u
#define Ticker_ControlRegRemoved          0u

#if defined(Ticker_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define Ticker_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (Ticker_UsingFixedFunction)
    #define Ticker_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define Ticker_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End Ticker_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!Ticker_UsingFixedFunction)

        uint16 TimerUdb;
        uint8 InterruptMaskValue;
        #if (Ticker_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!Ticker_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}Ticker_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    Ticker_Start(void) ;
void    Ticker_Stop(void) ;

void    Ticker_SetInterruptMode(uint8 interruptMode) ;
uint8   Ticker_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define Ticker_GetInterruptSource() Ticker_ReadStatusRegister()

#if(!Ticker_UDB_CONTROL_REG_REMOVED)
    uint8   Ticker_ReadControlRegister(void) ;
    void    Ticker_WriteControlRegister(uint8 control) ;
#endif /* (!Ticker_UDB_CONTROL_REG_REMOVED) */

uint16  Ticker_ReadPeriod(void) ;
void    Ticker_WritePeriod(uint16 period) ;
uint16  Ticker_ReadCounter(void) ;
void    Ticker_WriteCounter(uint16 counter) ;
uint16  Ticker_ReadCapture(void) ;
void    Ticker_SoftwareCapture(void) ;

#if(!Ticker_UsingFixedFunction) /* UDB Prototypes */
    #if (Ticker_SoftwareCaptureMode)
        void    Ticker_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!Ticker_UsingFixedFunction) */

    #if (Ticker_SoftwareTriggerMode)
        void    Ticker_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (Ticker_SoftwareTriggerMode) */

    #if (Ticker_EnableTriggerMode)
        void    Ticker_EnableTrigger(void) ;
        void    Ticker_DisableTrigger(void) ;
    #endif /* (Ticker_EnableTriggerMode) */


    #if(Ticker_InterruptOnCaptureCount)
        void    Ticker_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (Ticker_InterruptOnCaptureCount) */

    #if (Ticker_UsingHWCaptureCounter)
        void    Ticker_SetCaptureCount(uint8 captureCount) ;
        uint8   Ticker_ReadCaptureCount(void) ;
    #endif /* (Ticker_UsingHWCaptureCounter) */

    void Ticker_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void Ticker_Init(void)          ;
void Ticker_Enable(void)        ;
void Ticker_SaveConfig(void)    ;
void Ticker_RestoreConfig(void) ;
void Ticker_Sleep(void)         ;
void Ticker_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define Ticker__B_TIMER__CM_NONE 0
#define Ticker__B_TIMER__CM_RISINGEDGE 1
#define Ticker__B_TIMER__CM_FALLINGEDGE 2
#define Ticker__B_TIMER__CM_EITHEREDGE 3
#define Ticker__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define Ticker__B_TIMER__TM_NONE 0x00u
#define Ticker__B_TIMER__TM_RISINGEDGE 0x04u
#define Ticker__B_TIMER__TM_FALLINGEDGE 0x08u
#define Ticker__B_TIMER__TM_EITHEREDGE 0x0Cu
#define Ticker__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define Ticker_INIT_PERIOD             199u
#define Ticker_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << Ticker_CTRL_CAP_MODE_SHIFT))
#define Ticker_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << Ticker_CTRL_TRIG_MODE_SHIFT))
#if (Ticker_UsingFixedFunction)
    #define Ticker_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << Ticker_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << Ticker_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define Ticker_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << Ticker_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Ticker_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Ticker_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (Ticker_UsingFixedFunction) */
#define Ticker_INIT_CAPTURE_COUNT      (2u)
#define Ticker_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << Ticker_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (Ticker_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define Ticker_STATUS         (*(reg8 *) Ticker_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Ticker_STATUS_MASK    (*(reg8 *) Ticker_TimerHW__SR0 )
    #define Ticker_CONTROL        (*(reg8 *) Ticker_TimerHW__CFG0)
    #define Ticker_CONTROL2       (*(reg8 *) Ticker_TimerHW__CFG1)
    #define Ticker_CONTROL2_PTR   ( (reg8 *) Ticker_TimerHW__CFG1)
    #define Ticker_RT1            (*(reg8 *) Ticker_TimerHW__RT1)
    #define Ticker_RT1_PTR        ( (reg8 *) Ticker_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Ticker_CONTROL3       (*(reg8 *) Ticker_TimerHW__CFG2)
        #define Ticker_CONTROL3_PTR   ( (reg8 *) Ticker_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Ticker_GLOBAL_ENABLE  (*(reg8 *) Ticker_TimerHW__PM_ACT_CFG)
    #define Ticker_GLOBAL_STBY_ENABLE  (*(reg8 *) Ticker_TimerHW__PM_STBY_CFG)

    #define Ticker_CAPTURE_LSB         (* (reg16 *) Ticker_TimerHW__CAP0 )
    #define Ticker_CAPTURE_LSB_PTR       ((reg16 *) Ticker_TimerHW__CAP0 )
    #define Ticker_PERIOD_LSB          (* (reg16 *) Ticker_TimerHW__PER0 )
    #define Ticker_PERIOD_LSB_PTR        ((reg16 *) Ticker_TimerHW__PER0 )
    #define Ticker_COUNTER_LSB         (* (reg16 *) Ticker_TimerHW__CNT_CMP0 )
    #define Ticker_COUNTER_LSB_PTR       ((reg16 *) Ticker_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define Ticker_BLOCK_EN_MASK                     Ticker_TimerHW__PM_ACT_MSK
    #define Ticker_BLOCK_STBY_EN_MASK                Ticker_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define Ticker_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define Ticker_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define Ticker_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define Ticker_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define Ticker_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define Ticker_CTRL_ENABLE                        ((uint8)((uint8)0x01u << Ticker_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Ticker_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define Ticker_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << Ticker_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define Ticker_CTRL_MODE_SHIFT                 0x01u
        #define Ticker_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << Ticker_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define Ticker_CTRL_RCOD_SHIFT        0x02u
        #define Ticker_CTRL_ENBL_SHIFT        0x00u
        #define Ticker_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define Ticker_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << Ticker_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define Ticker_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << Ticker_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define Ticker_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << Ticker_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define Ticker_CTRL_RCOD       ((uint8)((uint8)0x03u << Ticker_CTRL_RCOD_SHIFT))
        #define Ticker_CTRL_ENBL       ((uint8)((uint8)0x80u << Ticker_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Ticker_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define Ticker_RT1_MASK                        ((uint8)((uint8)0x03u << Ticker_RT1_SHIFT))
    #define Ticker_SYNC                            ((uint8)((uint8)0x03u << Ticker_RT1_SHIFT))
    #define Ticker_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define Ticker_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << Ticker_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define Ticker_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << Ticker_SYNCDSI_SHIFT))

    #define Ticker_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << Ticker_CTRL_MODE_SHIFT))
    #define Ticker_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << Ticker_CTRL_MODE_SHIFT))
    #define Ticker_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << Ticker_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Ticker_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Ticker_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Ticker_STATUS_TC_INT_MASK_SHIFT        (Ticker_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Ticker_STATUS_CAPTURE_INT_MASK_SHIFT   (Ticker_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define Ticker_STATUS_TC                       ((uint8)((uint8)0x01u << Ticker_STATUS_TC_SHIFT))
    #define Ticker_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << Ticker_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define Ticker_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << Ticker_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define Ticker_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << Ticker_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define Ticker_STATUS              (* (reg8 *) Ticker_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define Ticker_STATUS_MASK         (* (reg8 *) Ticker_TimerUDB_rstSts_stsreg__MASK_REG)
    #define Ticker_STATUS_AUX_CTRL     (* (reg8 *) Ticker_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Ticker_CONTROL             (* (reg8 *) Ticker_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(Ticker_Resolution <= 8u) /* 8-bit Timer */
        #define Ticker_CAPTURE_LSB         (* (reg8 *) Ticker_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define Ticker_CAPTURE_LSB_PTR       ((reg8 *) Ticker_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define Ticker_PERIOD_LSB          (* (reg8 *) Ticker_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define Ticker_PERIOD_LSB_PTR        ((reg8 *) Ticker_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define Ticker_COUNTER_LSB         (* (reg8 *) Ticker_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define Ticker_COUNTER_LSB_PTR       ((reg8 *) Ticker_TimerUDB_sT16_timerdp_u0__A0_REG )
    #elif(Ticker_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define Ticker_CAPTURE_LSB         (* (reg16 *) Ticker_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define Ticker_CAPTURE_LSB_PTR       ((reg16 *) Ticker_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define Ticker_PERIOD_LSB          (* (reg16 *) Ticker_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define Ticker_PERIOD_LSB_PTR        ((reg16 *) Ticker_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define Ticker_COUNTER_LSB         (* (reg16 *) Ticker_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define Ticker_COUNTER_LSB_PTR       ((reg16 *) Ticker_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define Ticker_CAPTURE_LSB         (* (reg16 *) Ticker_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define Ticker_CAPTURE_LSB_PTR       ((reg16 *) Ticker_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define Ticker_PERIOD_LSB          (* (reg16 *) Ticker_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define Ticker_PERIOD_LSB_PTR        ((reg16 *) Ticker_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define Ticker_COUNTER_LSB         (* (reg16 *) Ticker_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
            #define Ticker_COUNTER_LSB_PTR       ((reg16 *) Ticker_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(Ticker_Resolution <= 24u)/* 24-bit Timer */
        #define Ticker_CAPTURE_LSB         (* (reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define Ticker_CAPTURE_LSB_PTR       ((reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define Ticker_PERIOD_LSB          (* (reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define Ticker_PERIOD_LSB_PTR        ((reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define Ticker_COUNTER_LSB         (* (reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define Ticker_COUNTER_LSB_PTR       ((reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define Ticker_CAPTURE_LSB         (* (reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define Ticker_CAPTURE_LSB_PTR       ((reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define Ticker_PERIOD_LSB          (* (reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define Ticker_PERIOD_LSB_PTR        ((reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define Ticker_COUNTER_LSB         (* (reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define Ticker_COUNTER_LSB_PTR       ((reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define Ticker_CAPTURE_LSB         (* (reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define Ticker_CAPTURE_LSB_PTR       ((reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define Ticker_PERIOD_LSB          (* (reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define Ticker_PERIOD_LSB_PTR        ((reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define Ticker_COUNTER_LSB         (* (reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
            #define Ticker_COUNTER_LSB_PTR       ((reg32 *) Ticker_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define Ticker_COUNTER_LSB_PTR_8BIT       ((reg8 *) Ticker_TimerUDB_sT16_timerdp_u0__A0_REG )
    
    #if (Ticker_UsingHWCaptureCounter)
        #define Ticker_CAP_COUNT              (*(reg8 *) Ticker_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Ticker_CAP_COUNT_PTR          ( (reg8 *) Ticker_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Ticker_CAPTURE_COUNT_CTRL     (*(reg8 *) Ticker_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define Ticker_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) Ticker_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (Ticker_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define Ticker_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define Ticker_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define Ticker_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define Ticker_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define Ticker_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define Ticker_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << Ticker_CTRL_INTCNT_SHIFT))
    #define Ticker_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << Ticker_CTRL_TRIG_MODE_SHIFT))
    #define Ticker_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << Ticker_CTRL_TRIG_EN_SHIFT))
    #define Ticker_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << Ticker_CTRL_CAP_MODE_SHIFT))
    #define Ticker_CTRL_ENABLE                    ((uint8)((uint8)0x01u << Ticker_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define Ticker_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define Ticker_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define Ticker_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define Ticker_STATUS_TC_INT_MASK_SHIFT       Ticker_STATUS_TC_SHIFT
    #define Ticker_STATUS_CAPTURE_INT_MASK_SHIFT  Ticker_STATUS_CAPTURE_SHIFT
    #define Ticker_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define Ticker_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define Ticker_STATUS_FIFOFULL_INT_MASK_SHIFT Ticker_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define Ticker_STATUS_TC                      ((uint8)((uint8)0x01u << Ticker_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define Ticker_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << Ticker_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Ticker_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << Ticker_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Ticker_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << Ticker_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define Ticker_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << Ticker_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define Ticker_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << Ticker_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Ticker_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << Ticker_STATUS_FIFOFULL_SHIFT))

    #define Ticker_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define Ticker_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define Ticker_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define Ticker_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define Ticker_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define Ticker_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_TIMER_Ticker_H */


/* [] END OF FILE */
