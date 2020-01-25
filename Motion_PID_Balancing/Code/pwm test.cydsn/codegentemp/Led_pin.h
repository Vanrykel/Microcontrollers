/*******************************************************************************
* File Name: Led_pin.h  
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

#if !defined(CY_PINS_Led_pin_H) /* Pins Led_pin_H */
#define CY_PINS_Led_pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Led_pin_aliases.h"


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
} Led_pin_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Led_pin_Read(void);
void    Led_pin_Write(uint8 value);
uint8   Led_pin_ReadDataReg(void);
#if defined(Led_pin__PC) || (CY_PSOC4_4200L) 
    void    Led_pin_SetDriveMode(uint8 mode);
#endif
void    Led_pin_SetInterruptMode(uint16 position, uint16 mode);
uint8   Led_pin_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Led_pin_Sleep(void); 
void Led_pin_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Led_pin__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Led_pin_DRIVE_MODE_BITS        (3)
    #define Led_pin_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Led_pin_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Led_pin_SetDriveMode() function.
         *  @{
         */
        #define Led_pin_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Led_pin_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Led_pin_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Led_pin_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Led_pin_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Led_pin_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Led_pin_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Led_pin_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Led_pin_MASK               Led_pin__MASK
#define Led_pin_SHIFT              Led_pin__SHIFT
#define Led_pin_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Led_pin_SetInterruptMode() function.
     *  @{
     */
        #define Led_pin_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Led_pin_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Led_pin_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Led_pin_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Led_pin__SIO)
    #define Led_pin_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Led_pin__PC) && (CY_PSOC4_4200L)
    #define Led_pin_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Led_pin_USBIO_DISABLE              ((uint32)(~Led_pin_USBIO_ENABLE))
    #define Led_pin_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Led_pin_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Led_pin_USBIO_ENTER_SLEEP          ((uint32)((1u << Led_pin_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Led_pin_USBIO_SUSPEND_DEL_SHIFT)))
    #define Led_pin_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Led_pin_USBIO_SUSPEND_SHIFT)))
    #define Led_pin_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Led_pin_USBIO_SUSPEND_DEL_SHIFT)))
    #define Led_pin_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Led_pin__PC)
    /* Port Configuration */
    #define Led_pin_PC                 (* (reg32 *) Led_pin__PC)
#endif
/* Pin State */
#define Led_pin_PS                     (* (reg32 *) Led_pin__PS)
/* Data Register */
#define Led_pin_DR                     (* (reg32 *) Led_pin__DR)
/* Input Buffer Disable Override */
#define Led_pin_INP_DIS                (* (reg32 *) Led_pin__PC2)

/* Interrupt configuration Registers */
#define Led_pin_INTCFG                 (* (reg32 *) Led_pin__INTCFG)
#define Led_pin_INTSTAT                (* (reg32 *) Led_pin__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Led_pin_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Led_pin__SIO)
    #define Led_pin_SIO_REG            (* (reg32 *) Led_pin__SIO)
#endif /* (Led_pin__SIO_CFG) */

/* USBIO registers */
#if !defined(Led_pin__PC) && (CY_PSOC4_4200L)
    #define Led_pin_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Led_pin_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Led_pin_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Led_pin_DRIVE_MODE_SHIFT       (0x00u)
#define Led_pin_DRIVE_MODE_MASK        (0x07u << Led_pin_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Led_pin_H */


/* [] END OF FILE */
