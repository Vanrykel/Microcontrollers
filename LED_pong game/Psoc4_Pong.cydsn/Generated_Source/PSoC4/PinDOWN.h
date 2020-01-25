/*******************************************************************************
* File Name: PinDOWN.h  
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

#if !defined(CY_PINS_PinDOWN_H) /* Pins PinDOWN_H */
#define CY_PINS_PinDOWN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PinDOWN_aliases.h"


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
} PinDOWN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PinDOWN_Read(void);
void    PinDOWN_Write(uint8 value);
uint8   PinDOWN_ReadDataReg(void);
#if defined(PinDOWN__PC) || (CY_PSOC4_4200L) 
    void    PinDOWN_SetDriveMode(uint8 mode);
#endif
void    PinDOWN_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinDOWN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PinDOWN_Sleep(void); 
void PinDOWN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PinDOWN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PinDOWN_DRIVE_MODE_BITS        (3)
    #define PinDOWN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PinDOWN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PinDOWN_SetDriveMode() function.
         *  @{
         */
        #define PinDOWN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PinDOWN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PinDOWN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PinDOWN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PinDOWN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PinDOWN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PinDOWN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PinDOWN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PinDOWN_MASK               PinDOWN__MASK
#define PinDOWN_SHIFT              PinDOWN__SHIFT
#define PinDOWN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinDOWN_SetInterruptMode() function.
     *  @{
     */
        #define PinDOWN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PinDOWN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PinDOWN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PinDOWN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PinDOWN__SIO)
    #define PinDOWN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PinDOWN__PC) && (CY_PSOC4_4200L)
    #define PinDOWN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PinDOWN_USBIO_DISABLE              ((uint32)(~PinDOWN_USBIO_ENABLE))
    #define PinDOWN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PinDOWN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PinDOWN_USBIO_ENTER_SLEEP          ((uint32)((1u << PinDOWN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PinDOWN_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinDOWN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PinDOWN_USBIO_SUSPEND_SHIFT)))
    #define PinDOWN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PinDOWN_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinDOWN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PinDOWN__PC)
    /* Port Configuration */
    #define PinDOWN_PC                 (* (reg32 *) PinDOWN__PC)
#endif
/* Pin State */
#define PinDOWN_PS                     (* (reg32 *) PinDOWN__PS)
/* Data Register */
#define PinDOWN_DR                     (* (reg32 *) PinDOWN__DR)
/* Input Buffer Disable Override */
#define PinDOWN_INP_DIS                (* (reg32 *) PinDOWN__PC2)

/* Interrupt configuration Registers */
#define PinDOWN_INTCFG                 (* (reg32 *) PinDOWN__INTCFG)
#define PinDOWN_INTSTAT                (* (reg32 *) PinDOWN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PinDOWN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PinDOWN__SIO)
    #define PinDOWN_SIO_REG            (* (reg32 *) PinDOWN__SIO)
#endif /* (PinDOWN__SIO_CFG) */

/* USBIO registers */
#if !defined(PinDOWN__PC) && (CY_PSOC4_4200L)
    #define PinDOWN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PinDOWN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PinDOWN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PinDOWN_DRIVE_MODE_SHIFT       (0x00u)
#define PinDOWN_DRIVE_MODE_MASK        (0x07u << PinDOWN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PinDOWN_H */


/* [] END OF FILE */
