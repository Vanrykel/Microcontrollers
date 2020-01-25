/*******************************************************************************
* File Name: buzzer.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_buzzer_H) /* Pins buzzer_H */
#define CY_PINS_buzzer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "buzzer_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} buzzer_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   buzzer_Read(void);
void    buzzer_Write(uint8 value);
uint8   buzzer_ReadDataReg(void);
#if defined(buzzer__PC) || (CY_PSOC4_4200L) 
    void    buzzer_SetDriveMode(uint8 mode);
#endif
void    buzzer_SetInterruptMode(uint16 position, uint16 mode);
uint8   buzzer_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void buzzer_Sleep(void); 
void buzzer_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(buzzer__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define buzzer_DRIVE_MODE_BITS        (3)
    #define buzzer_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - buzzer_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the buzzer_SetDriveMode() function.
         *  @{
         */
        #define buzzer_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define buzzer_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define buzzer_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define buzzer_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define buzzer_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define buzzer_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define buzzer_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define buzzer_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define buzzer_MASK               buzzer__MASK
#define buzzer_SHIFT              buzzer__SHIFT
#define buzzer_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in buzzer_SetInterruptMode() function.
     *  @{
     */
        #define buzzer_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define buzzer_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define buzzer_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define buzzer_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(buzzer__SIO)
    #define buzzer_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(buzzer__PC) && (CY_PSOC4_4200L)
    #define buzzer_USBIO_ENABLE               ((uint32)0x80000000u)
    #define buzzer_USBIO_DISABLE              ((uint32)(~buzzer_USBIO_ENABLE))
    #define buzzer_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define buzzer_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define buzzer_USBIO_ENTER_SLEEP          ((uint32)((1u << buzzer_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << buzzer_USBIO_SUSPEND_DEL_SHIFT)))
    #define buzzer_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << buzzer_USBIO_SUSPEND_SHIFT)))
    #define buzzer_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << buzzer_USBIO_SUSPEND_DEL_SHIFT)))
    #define buzzer_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(buzzer__PC)
    /* Port Configuration */
    #define buzzer_PC                 (* (reg32 *) buzzer__PC)
#endif
/* Pin State */
#define buzzer_PS                     (* (reg32 *) buzzer__PS)
/* Data Register */
#define buzzer_DR                     (* (reg32 *) buzzer__DR)
/* Input Buffer Disable Override */
#define buzzer_INP_DIS                (* (reg32 *) buzzer__PC2)

/* Interrupt configuration Registers */
#define buzzer_INTCFG                 (* (reg32 *) buzzer__INTCFG)
#define buzzer_INTSTAT                (* (reg32 *) buzzer__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define buzzer_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(buzzer__SIO)
    #define buzzer_SIO_REG            (* (reg32 *) buzzer__SIO)
#endif /* (buzzer__SIO_CFG) */

/* USBIO registers */
#if !defined(buzzer__PC) && (CY_PSOC4_4200L)
    #define buzzer_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define buzzer_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define buzzer_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define buzzer_DRIVE_MODE_SHIFT       (0x00u)
#define buzzer_DRIVE_MODE_MASK        (0x07u << buzzer_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins buzzer_H */


/* [] END OF FILE */
