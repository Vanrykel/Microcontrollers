/*******************************************************************************
* File Name: ledForward.h  
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

#if !defined(CY_PINS_ledForward_H) /* Pins ledForward_H */
#define CY_PINS_ledForward_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ledForward_aliases.h"


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
} ledForward_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ledForward_Read(void);
void    ledForward_Write(uint8 value);
uint8   ledForward_ReadDataReg(void);
#if defined(ledForward__PC) || (CY_PSOC4_4200L) 
    void    ledForward_SetDriveMode(uint8 mode);
#endif
void    ledForward_SetInterruptMode(uint16 position, uint16 mode);
uint8   ledForward_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ledForward_Sleep(void); 
void ledForward_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ledForward__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ledForward_DRIVE_MODE_BITS        (3)
    #define ledForward_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ledForward_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ledForward_SetDriveMode() function.
         *  @{
         */
        #define ledForward_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ledForward_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ledForward_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ledForward_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ledForward_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ledForward_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ledForward_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ledForward_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ledForward_MASK               ledForward__MASK
#define ledForward_SHIFT              ledForward__SHIFT
#define ledForward_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ledForward_SetInterruptMode() function.
     *  @{
     */
        #define ledForward_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ledForward_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ledForward_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ledForward_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ledForward__SIO)
    #define ledForward_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ledForward__PC) && (CY_PSOC4_4200L)
    #define ledForward_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ledForward_USBIO_DISABLE              ((uint32)(~ledForward_USBIO_ENABLE))
    #define ledForward_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ledForward_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ledForward_USBIO_ENTER_SLEEP          ((uint32)((1u << ledForward_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ledForward_USBIO_SUSPEND_DEL_SHIFT)))
    #define ledForward_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ledForward_USBIO_SUSPEND_SHIFT)))
    #define ledForward_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ledForward_USBIO_SUSPEND_DEL_SHIFT)))
    #define ledForward_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ledForward__PC)
    /* Port Configuration */
    #define ledForward_PC                 (* (reg32 *) ledForward__PC)
#endif
/* Pin State */
#define ledForward_PS                     (* (reg32 *) ledForward__PS)
/* Data Register */
#define ledForward_DR                     (* (reg32 *) ledForward__DR)
/* Input Buffer Disable Override */
#define ledForward_INP_DIS                (* (reg32 *) ledForward__PC2)

/* Interrupt configuration Registers */
#define ledForward_INTCFG                 (* (reg32 *) ledForward__INTCFG)
#define ledForward_INTSTAT                (* (reg32 *) ledForward__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ledForward_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ledForward__SIO)
    #define ledForward_SIO_REG            (* (reg32 *) ledForward__SIO)
#endif /* (ledForward__SIO_CFG) */

/* USBIO registers */
#if !defined(ledForward__PC) && (CY_PSOC4_4200L)
    #define ledForward_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ledForward_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ledForward_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ledForward_DRIVE_MODE_SHIFT       (0x00u)
#define ledForward_DRIVE_MODE_MASK        (0x07u << ledForward_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ledForward_H */


/* [] END OF FILE */
