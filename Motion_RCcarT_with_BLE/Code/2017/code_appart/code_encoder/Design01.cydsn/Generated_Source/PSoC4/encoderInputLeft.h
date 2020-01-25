/*******************************************************************************
* File Name: encoderInputLeft.h  
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

#if !defined(CY_PINS_encoderInputLeft_H) /* Pins encoderInputLeft_H */
#define CY_PINS_encoderInputLeft_H

#include "cytypes.h"
#include "cyfitter.h"
#include "encoderInputLeft_aliases.h"


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
} encoderInputLeft_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   encoderInputLeft_Read(void);
void    encoderInputLeft_Write(uint8 value);
uint8   encoderInputLeft_ReadDataReg(void);
#if defined(encoderInputLeft__PC) || (CY_PSOC4_4200L) 
    void    encoderInputLeft_SetDriveMode(uint8 mode);
#endif
void    encoderInputLeft_SetInterruptMode(uint16 position, uint16 mode);
uint8   encoderInputLeft_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void encoderInputLeft_Sleep(void); 
void encoderInputLeft_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(encoderInputLeft__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define encoderInputLeft_DRIVE_MODE_BITS        (3)
    #define encoderInputLeft_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - encoderInputLeft_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the encoderInputLeft_SetDriveMode() function.
         *  @{
         */
        #define encoderInputLeft_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define encoderInputLeft_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define encoderInputLeft_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define encoderInputLeft_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define encoderInputLeft_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define encoderInputLeft_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define encoderInputLeft_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define encoderInputLeft_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define encoderInputLeft_MASK               encoderInputLeft__MASK
#define encoderInputLeft_SHIFT              encoderInputLeft__SHIFT
#define encoderInputLeft_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in encoderInputLeft_SetInterruptMode() function.
     *  @{
     */
        #define encoderInputLeft_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define encoderInputLeft_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define encoderInputLeft_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define encoderInputLeft_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(encoderInputLeft__SIO)
    #define encoderInputLeft_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(encoderInputLeft__PC) && (CY_PSOC4_4200L)
    #define encoderInputLeft_USBIO_ENABLE               ((uint32)0x80000000u)
    #define encoderInputLeft_USBIO_DISABLE              ((uint32)(~encoderInputLeft_USBIO_ENABLE))
    #define encoderInputLeft_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define encoderInputLeft_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define encoderInputLeft_USBIO_ENTER_SLEEP          ((uint32)((1u << encoderInputLeft_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << encoderInputLeft_USBIO_SUSPEND_DEL_SHIFT)))
    #define encoderInputLeft_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << encoderInputLeft_USBIO_SUSPEND_SHIFT)))
    #define encoderInputLeft_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << encoderInputLeft_USBIO_SUSPEND_DEL_SHIFT)))
    #define encoderInputLeft_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(encoderInputLeft__PC)
    /* Port Configuration */
    #define encoderInputLeft_PC                 (* (reg32 *) encoderInputLeft__PC)
#endif
/* Pin State */
#define encoderInputLeft_PS                     (* (reg32 *) encoderInputLeft__PS)
/* Data Register */
#define encoderInputLeft_DR                     (* (reg32 *) encoderInputLeft__DR)
/* Input Buffer Disable Override */
#define encoderInputLeft_INP_DIS                (* (reg32 *) encoderInputLeft__PC2)

/* Interrupt configuration Registers */
#define encoderInputLeft_INTCFG                 (* (reg32 *) encoderInputLeft__INTCFG)
#define encoderInputLeft_INTSTAT                (* (reg32 *) encoderInputLeft__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define encoderInputLeft_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(encoderInputLeft__SIO)
    #define encoderInputLeft_SIO_REG            (* (reg32 *) encoderInputLeft__SIO)
#endif /* (encoderInputLeft__SIO_CFG) */

/* USBIO registers */
#if !defined(encoderInputLeft__PC) && (CY_PSOC4_4200L)
    #define encoderInputLeft_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define encoderInputLeft_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define encoderInputLeft_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define encoderInputLeft_DRIVE_MODE_SHIFT       (0x00u)
#define encoderInputLeft_DRIVE_MODE_MASK        (0x07u << encoderInputLeft_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins encoderInputLeft_H */


/* [] END OF FILE */
