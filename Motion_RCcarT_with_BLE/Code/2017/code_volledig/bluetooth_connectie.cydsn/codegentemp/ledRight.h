/*******************************************************************************
* File Name: ledRight.h  
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

#if !defined(CY_PINS_ledRight_H) /* Pins ledRight_H */
#define CY_PINS_ledRight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ledRight_aliases.h"


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
} ledRight_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ledRight_Read(void);
void    ledRight_Write(uint8 value);
uint8   ledRight_ReadDataReg(void);
#if defined(ledRight__PC) || (CY_PSOC4_4200L) 
    void    ledRight_SetDriveMode(uint8 mode);
#endif
void    ledRight_SetInterruptMode(uint16 position, uint16 mode);
uint8   ledRight_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ledRight_Sleep(void); 
void ledRight_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ledRight__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ledRight_DRIVE_MODE_BITS        (3)
    #define ledRight_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ledRight_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ledRight_SetDriveMode() function.
         *  @{
         */
        #define ledRight_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ledRight_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ledRight_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ledRight_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ledRight_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ledRight_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ledRight_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ledRight_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ledRight_MASK               ledRight__MASK
#define ledRight_SHIFT              ledRight__SHIFT
#define ledRight_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ledRight_SetInterruptMode() function.
     *  @{
     */
        #define ledRight_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ledRight_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ledRight_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ledRight_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ledRight__SIO)
    #define ledRight_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ledRight__PC) && (CY_PSOC4_4200L)
    #define ledRight_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ledRight_USBIO_DISABLE              ((uint32)(~ledRight_USBIO_ENABLE))
    #define ledRight_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ledRight_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ledRight_USBIO_ENTER_SLEEP          ((uint32)((1u << ledRight_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ledRight_USBIO_SUSPEND_DEL_SHIFT)))
    #define ledRight_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ledRight_USBIO_SUSPEND_SHIFT)))
    #define ledRight_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ledRight_USBIO_SUSPEND_DEL_SHIFT)))
    #define ledRight_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ledRight__PC)
    /* Port Configuration */
    #define ledRight_PC                 (* (reg32 *) ledRight__PC)
#endif
/* Pin State */
#define ledRight_PS                     (* (reg32 *) ledRight__PS)
/* Data Register */
#define ledRight_DR                     (* (reg32 *) ledRight__DR)
/* Input Buffer Disable Override */
#define ledRight_INP_DIS                (* (reg32 *) ledRight__PC2)

/* Interrupt configuration Registers */
#define ledRight_INTCFG                 (* (reg32 *) ledRight__INTCFG)
#define ledRight_INTSTAT                (* (reg32 *) ledRight__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ledRight_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ledRight__SIO)
    #define ledRight_SIO_REG            (* (reg32 *) ledRight__SIO)
#endif /* (ledRight__SIO_CFG) */

/* USBIO registers */
#if !defined(ledRight__PC) && (CY_PSOC4_4200L)
    #define ledRight_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ledRight_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ledRight_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ledRight_DRIVE_MODE_SHIFT       (0x00u)
#define ledRight_DRIVE_MODE_MASK        (0x07u << ledRight_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ledRight_H */


/* [] END OF FILE */
