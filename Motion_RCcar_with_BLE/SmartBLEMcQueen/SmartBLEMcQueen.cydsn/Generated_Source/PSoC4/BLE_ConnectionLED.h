/*******************************************************************************
* File Name: BLE_ConnectionLED.h  
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

#if !defined(CY_PINS_BLE_ConnectionLED_H) /* Pins BLE_ConnectionLED_H */
#define CY_PINS_BLE_ConnectionLED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BLE_ConnectionLED_aliases.h"


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
} BLE_ConnectionLED_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   BLE_ConnectionLED_Read(void);
void    BLE_ConnectionLED_Write(uint8 value);
uint8   BLE_ConnectionLED_ReadDataReg(void);
#if defined(BLE_ConnectionLED__PC) || (CY_PSOC4_4200L) 
    void    BLE_ConnectionLED_SetDriveMode(uint8 mode);
#endif
void    BLE_ConnectionLED_SetInterruptMode(uint16 position, uint16 mode);
uint8   BLE_ConnectionLED_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void BLE_ConnectionLED_Sleep(void); 
void BLE_ConnectionLED_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(BLE_ConnectionLED__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define BLE_ConnectionLED_DRIVE_MODE_BITS        (3)
    #define BLE_ConnectionLED_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BLE_ConnectionLED_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the BLE_ConnectionLED_SetDriveMode() function.
         *  @{
         */
        #define BLE_ConnectionLED_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define BLE_ConnectionLED_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define BLE_ConnectionLED_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define BLE_ConnectionLED_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define BLE_ConnectionLED_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define BLE_ConnectionLED_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define BLE_ConnectionLED_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define BLE_ConnectionLED_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define BLE_ConnectionLED_MASK               BLE_ConnectionLED__MASK
#define BLE_ConnectionLED_SHIFT              BLE_ConnectionLED__SHIFT
#define BLE_ConnectionLED_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BLE_ConnectionLED_SetInterruptMode() function.
     *  @{
     */
        #define BLE_ConnectionLED_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define BLE_ConnectionLED_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define BLE_ConnectionLED_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define BLE_ConnectionLED_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(BLE_ConnectionLED__SIO)
    #define BLE_ConnectionLED_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(BLE_ConnectionLED__PC) && (CY_PSOC4_4200L)
    #define BLE_ConnectionLED_USBIO_ENABLE               ((uint32)0x80000000u)
    #define BLE_ConnectionLED_USBIO_DISABLE              ((uint32)(~BLE_ConnectionLED_USBIO_ENABLE))
    #define BLE_ConnectionLED_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define BLE_ConnectionLED_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define BLE_ConnectionLED_USBIO_ENTER_SLEEP          ((uint32)((1u << BLE_ConnectionLED_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << BLE_ConnectionLED_USBIO_SUSPEND_DEL_SHIFT)))
    #define BLE_ConnectionLED_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << BLE_ConnectionLED_USBIO_SUSPEND_SHIFT)))
    #define BLE_ConnectionLED_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << BLE_ConnectionLED_USBIO_SUSPEND_DEL_SHIFT)))
    #define BLE_ConnectionLED_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(BLE_ConnectionLED__PC)
    /* Port Configuration */
    #define BLE_ConnectionLED_PC                 (* (reg32 *) BLE_ConnectionLED__PC)
#endif
/* Pin State */
#define BLE_ConnectionLED_PS                     (* (reg32 *) BLE_ConnectionLED__PS)
/* Data Register */
#define BLE_ConnectionLED_DR                     (* (reg32 *) BLE_ConnectionLED__DR)
/* Input Buffer Disable Override */
#define BLE_ConnectionLED_INP_DIS                (* (reg32 *) BLE_ConnectionLED__PC2)

/* Interrupt configuration Registers */
#define BLE_ConnectionLED_INTCFG                 (* (reg32 *) BLE_ConnectionLED__INTCFG)
#define BLE_ConnectionLED_INTSTAT                (* (reg32 *) BLE_ConnectionLED__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define BLE_ConnectionLED_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(BLE_ConnectionLED__SIO)
    #define BLE_ConnectionLED_SIO_REG            (* (reg32 *) BLE_ConnectionLED__SIO)
#endif /* (BLE_ConnectionLED__SIO_CFG) */

/* USBIO registers */
#if !defined(BLE_ConnectionLED__PC) && (CY_PSOC4_4200L)
    #define BLE_ConnectionLED_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define BLE_ConnectionLED_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define BLE_ConnectionLED_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define BLE_ConnectionLED_DRIVE_MODE_SHIFT       (0x00u)
#define BLE_ConnectionLED_DRIVE_MODE_MASK        (0x07u << BLE_ConnectionLED_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins BLE_ConnectionLED_H */


/* [] END OF FILE */
