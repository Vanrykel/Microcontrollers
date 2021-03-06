/*******************************************************************************
* File Name: Controller2.h  
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

#if !defined(CY_PINS_Controller2_H) /* Pins Controller2_H */
#define CY_PINS_Controller2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Controller2_aliases.h"


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
} Controller2_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Controller2_Read(void);
void    Controller2_Write(uint8 value);
uint8   Controller2_ReadDataReg(void);
#if defined(Controller2__PC) || (CY_PSOC4_4200L) 
    void    Controller2_SetDriveMode(uint8 mode);
#endif
void    Controller2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Controller2_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Controller2_Sleep(void); 
void Controller2_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Controller2__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Controller2_DRIVE_MODE_BITS        (3)
    #define Controller2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Controller2_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Controller2_SetDriveMode() function.
         *  @{
         */
        #define Controller2_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Controller2_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Controller2_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Controller2_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Controller2_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Controller2_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Controller2_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Controller2_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Controller2_MASK               Controller2__MASK
#define Controller2_SHIFT              Controller2__SHIFT
#define Controller2_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Controller2_SetInterruptMode() function.
     *  @{
     */
        #define Controller2_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Controller2_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Controller2_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Controller2_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Controller2__SIO)
    #define Controller2_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Controller2__PC) && (CY_PSOC4_4200L)
    #define Controller2_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Controller2_USBIO_DISABLE              ((uint32)(~Controller2_USBIO_ENABLE))
    #define Controller2_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Controller2_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Controller2_USBIO_ENTER_SLEEP          ((uint32)((1u << Controller2_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Controller2_USBIO_SUSPEND_DEL_SHIFT)))
    #define Controller2_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Controller2_USBIO_SUSPEND_SHIFT)))
    #define Controller2_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Controller2_USBIO_SUSPEND_DEL_SHIFT)))
    #define Controller2_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Controller2__PC)
    /* Port Configuration */
    #define Controller2_PC                 (* (reg32 *) Controller2__PC)
#endif
/* Pin State */
#define Controller2_PS                     (* (reg32 *) Controller2__PS)
/* Data Register */
#define Controller2_DR                     (* (reg32 *) Controller2__DR)
/* Input Buffer Disable Override */
#define Controller2_INP_DIS                (* (reg32 *) Controller2__PC2)

/* Interrupt configuration Registers */
#define Controller2_INTCFG                 (* (reg32 *) Controller2__INTCFG)
#define Controller2_INTSTAT                (* (reg32 *) Controller2__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Controller2_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Controller2__SIO)
    #define Controller2_SIO_REG            (* (reg32 *) Controller2__SIO)
#endif /* (Controller2__SIO_CFG) */

/* USBIO registers */
#if !defined(Controller2__PC) && (CY_PSOC4_4200L)
    #define Controller2_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Controller2_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Controller2_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Controller2_DRIVE_MODE_SHIFT       (0x00u)
#define Controller2_DRIVE_MODE_MASK        (0x07u << Controller2_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Controller2_H */


/* [] END OF FILE */
