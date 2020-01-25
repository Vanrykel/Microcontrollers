/*******************************************************************************
* File Name: encoderInput.h  
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

#if !defined(CY_PINS_encoderInput_H) /* Pins encoderInput_H */
#define CY_PINS_encoderInput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "encoderInput_aliases.h"


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
} encoderInput_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   encoderInput_Read(void);
void    encoderInput_Write(uint8 value);
uint8   encoderInput_ReadDataReg(void);
#if defined(encoderInput__PC) || (CY_PSOC4_4200L) 
    void    encoderInput_SetDriveMode(uint8 mode);
#endif
void    encoderInput_SetInterruptMode(uint16 position, uint16 mode);
uint8   encoderInput_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void encoderInput_Sleep(void); 
void encoderInput_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(encoderInput__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define encoderInput_DRIVE_MODE_BITS        (3)
    #define encoderInput_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - encoderInput_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the encoderInput_SetDriveMode() function.
         *  @{
         */
        #define encoderInput_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define encoderInput_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define encoderInput_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define encoderInput_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define encoderInput_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define encoderInput_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define encoderInput_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define encoderInput_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define encoderInput_MASK               encoderInput__MASK
#define encoderInput_SHIFT              encoderInput__SHIFT
#define encoderInput_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in encoderInput_SetInterruptMode() function.
     *  @{
     */
        #define encoderInput_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define encoderInput_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define encoderInput_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define encoderInput_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(encoderInput__SIO)
    #define encoderInput_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(encoderInput__PC) && (CY_PSOC4_4200L)
    #define encoderInput_USBIO_ENABLE               ((uint32)0x80000000u)
    #define encoderInput_USBIO_DISABLE              ((uint32)(~encoderInput_USBIO_ENABLE))
    #define encoderInput_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define encoderInput_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define encoderInput_USBIO_ENTER_SLEEP          ((uint32)((1u << encoderInput_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << encoderInput_USBIO_SUSPEND_DEL_SHIFT)))
    #define encoderInput_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << encoderInput_USBIO_SUSPEND_SHIFT)))
    #define encoderInput_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << encoderInput_USBIO_SUSPEND_DEL_SHIFT)))
    #define encoderInput_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(encoderInput__PC)
    /* Port Configuration */
    #define encoderInput_PC                 (* (reg32 *) encoderInput__PC)
#endif
/* Pin State */
#define encoderInput_PS                     (* (reg32 *) encoderInput__PS)
/* Data Register */
#define encoderInput_DR                     (* (reg32 *) encoderInput__DR)
/* Input Buffer Disable Override */
#define encoderInput_INP_DIS                (* (reg32 *) encoderInput__PC2)

/* Interrupt configuration Registers */
#define encoderInput_INTCFG                 (* (reg32 *) encoderInput__INTCFG)
#define encoderInput_INTSTAT                (* (reg32 *) encoderInput__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define encoderInput_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(encoderInput__SIO)
    #define encoderInput_SIO_REG            (* (reg32 *) encoderInput__SIO)
#endif /* (encoderInput__SIO_CFG) */

/* USBIO registers */
#if !defined(encoderInput__PC) && (CY_PSOC4_4200L)
    #define encoderInput_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define encoderInput_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define encoderInput_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define encoderInput_DRIVE_MODE_SHIFT       (0x00u)
#define encoderInput_DRIVE_MODE_MASK        (0x07u << encoderInput_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins encoderInput_H */


/* [] END OF FILE */
