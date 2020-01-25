/*******************************************************************************
* File Name: UltraSone_1_Trig.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_UltraSone_1_Trig_H) /* Pins UltraSone_1_Trig_H */
#define CY_PINS_UltraSone_1_Trig_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "UltraSone_1_Trig_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 UltraSone_1_Trig__PORT == 15 && ((UltraSone_1_Trig__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    UltraSone_1_Trig_Write(uint8 value);
void    UltraSone_1_Trig_SetDriveMode(uint8 mode);
uint8   UltraSone_1_Trig_ReadDataReg(void);
uint8   UltraSone_1_Trig_Read(void);
void    UltraSone_1_Trig_SetInterruptMode(uint16 position, uint16 mode);
uint8   UltraSone_1_Trig_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the UltraSone_1_Trig_SetDriveMode() function.
     *  @{
     */
        #define UltraSone_1_Trig_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define UltraSone_1_Trig_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define UltraSone_1_Trig_DM_RES_UP          PIN_DM_RES_UP
        #define UltraSone_1_Trig_DM_RES_DWN         PIN_DM_RES_DWN
        #define UltraSone_1_Trig_DM_OD_LO           PIN_DM_OD_LO
        #define UltraSone_1_Trig_DM_OD_HI           PIN_DM_OD_HI
        #define UltraSone_1_Trig_DM_STRONG          PIN_DM_STRONG
        #define UltraSone_1_Trig_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define UltraSone_1_Trig_MASK               UltraSone_1_Trig__MASK
#define UltraSone_1_Trig_SHIFT              UltraSone_1_Trig__SHIFT
#define UltraSone_1_Trig_WIDTH              1u

/* Interrupt constants */
#if defined(UltraSone_1_Trig__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in UltraSone_1_Trig_SetInterruptMode() function.
     *  @{
     */
        #define UltraSone_1_Trig_INTR_NONE      (uint16)(0x0000u)
        #define UltraSone_1_Trig_INTR_RISING    (uint16)(0x0001u)
        #define UltraSone_1_Trig_INTR_FALLING   (uint16)(0x0002u)
        #define UltraSone_1_Trig_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define UltraSone_1_Trig_INTR_MASK      (0x01u) 
#endif /* (UltraSone_1_Trig__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UltraSone_1_Trig_PS                     (* (reg8 *) UltraSone_1_Trig__PS)
/* Data Register */
#define UltraSone_1_Trig_DR                     (* (reg8 *) UltraSone_1_Trig__DR)
/* Port Number */
#define UltraSone_1_Trig_PRT_NUM                (* (reg8 *) UltraSone_1_Trig__PRT) 
/* Connect to Analog Globals */                                                  
#define UltraSone_1_Trig_AG                     (* (reg8 *) UltraSone_1_Trig__AG)                       
/* Analog MUX bux enable */
#define UltraSone_1_Trig_AMUX                   (* (reg8 *) UltraSone_1_Trig__AMUX) 
/* Bidirectional Enable */                                                        
#define UltraSone_1_Trig_BIE                    (* (reg8 *) UltraSone_1_Trig__BIE)
/* Bit-mask for Aliased Register Access */
#define UltraSone_1_Trig_BIT_MASK               (* (reg8 *) UltraSone_1_Trig__BIT_MASK)
/* Bypass Enable */
#define UltraSone_1_Trig_BYP                    (* (reg8 *) UltraSone_1_Trig__BYP)
/* Port wide control signals */                                                   
#define UltraSone_1_Trig_CTL                    (* (reg8 *) UltraSone_1_Trig__CTL)
/* Drive Modes */
#define UltraSone_1_Trig_DM0                    (* (reg8 *) UltraSone_1_Trig__DM0) 
#define UltraSone_1_Trig_DM1                    (* (reg8 *) UltraSone_1_Trig__DM1)
#define UltraSone_1_Trig_DM2                    (* (reg8 *) UltraSone_1_Trig__DM2) 
/* Input Buffer Disable Override */
#define UltraSone_1_Trig_INP_DIS                (* (reg8 *) UltraSone_1_Trig__INP_DIS)
/* LCD Common or Segment Drive */
#define UltraSone_1_Trig_LCD_COM_SEG            (* (reg8 *) UltraSone_1_Trig__LCD_COM_SEG)
/* Enable Segment LCD */
#define UltraSone_1_Trig_LCD_EN                 (* (reg8 *) UltraSone_1_Trig__LCD_EN)
/* Slew Rate Control */
#define UltraSone_1_Trig_SLW                    (* (reg8 *) UltraSone_1_Trig__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define UltraSone_1_Trig_PRTDSI__CAPS_SEL       (* (reg8 *) UltraSone_1_Trig__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define UltraSone_1_Trig_PRTDSI__DBL_SYNC_IN    (* (reg8 *) UltraSone_1_Trig__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define UltraSone_1_Trig_PRTDSI__OE_SEL0        (* (reg8 *) UltraSone_1_Trig__PRTDSI__OE_SEL0) 
#define UltraSone_1_Trig_PRTDSI__OE_SEL1        (* (reg8 *) UltraSone_1_Trig__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define UltraSone_1_Trig_PRTDSI__OUT_SEL0       (* (reg8 *) UltraSone_1_Trig__PRTDSI__OUT_SEL0) 
#define UltraSone_1_Trig_PRTDSI__OUT_SEL1       (* (reg8 *) UltraSone_1_Trig__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define UltraSone_1_Trig_PRTDSI__SYNC_OUT       (* (reg8 *) UltraSone_1_Trig__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(UltraSone_1_Trig__SIO_CFG)
    #define UltraSone_1_Trig_SIO_HYST_EN        (* (reg8 *) UltraSone_1_Trig__SIO_HYST_EN)
    #define UltraSone_1_Trig_SIO_REG_HIFREQ     (* (reg8 *) UltraSone_1_Trig__SIO_REG_HIFREQ)
    #define UltraSone_1_Trig_SIO_CFG            (* (reg8 *) UltraSone_1_Trig__SIO_CFG)
    #define UltraSone_1_Trig_SIO_DIFF           (* (reg8 *) UltraSone_1_Trig__SIO_DIFF)
#endif /* (UltraSone_1_Trig__SIO_CFG) */

/* Interrupt Registers */
#if defined(UltraSone_1_Trig__INTSTAT)
    #define UltraSone_1_Trig_INTSTAT            (* (reg8 *) UltraSone_1_Trig__INTSTAT)
    #define UltraSone_1_Trig_SNAP               (* (reg8 *) UltraSone_1_Trig__SNAP)
    
	#define UltraSone_1_Trig_0_INTTYPE_REG 		(* (reg8 *) UltraSone_1_Trig__0__INTTYPE)
#endif /* (UltraSone_1_Trig__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_UltraSone_1_Trig_H */


/* [] END OF FILE */
