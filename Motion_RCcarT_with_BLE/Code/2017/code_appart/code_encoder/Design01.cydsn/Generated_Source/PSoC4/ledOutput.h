/*******************************************************************************
* File Name: ledOutput.h  
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

#if !defined(CY_PINS_ledOutput_H) /* Pins ledOutput_H */
#define CY_PINS_ledOutput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ledOutput_aliases.h"


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
} ledOutput_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ledOutput_Read(void);
void    ledOutput_Write(uint8 value);
uint8   ledOutput_ReadDataReg(void);
#if defined(ledOutput__PC) || (CY_PSOC4_4200L) 
    void    ledOutput_SetDriveMode(uint8 mode);
#endif
void    ledOutput_SetInterruptMode(uint16 position, uint16 mode);
uint8   ledOutput_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ledOutput_Sleep(void); 
void ledOutput_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ledOutput__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ledOutput_DRIVE_MODE_BITS        (3)
    #define ledOutput_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ledOutput_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ledOutput_SetDriveMode() function.
         *  @{
         */
        #define ledOutput_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ledOutput_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ledOutput_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ledOutput_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ledOutput_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ledOutput_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ledOutput_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ledOutput_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ledOutput_MASK               ledOutput__MASK
#define ledOutput_SHIFT              ledOutput__SHIFT
#define ledOutput_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ledOutput_SetInterruptMode() function.
     *  @{
     */
        #define ledOutput_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ledOutput_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ledOutput_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ledOutput_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ledOutput__SIO)
    #define ledOutput_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ledOutput__PC) && (CY_PSOC4_4200L)
    #define ledOutput_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ledOutput_USBIO_DISABLE              ((uint32)(~ledOutput_USBIO_ENABLE))
    #define ledOutput_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ledOutput_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ledOutput_USBIO_ENTER_SLEEP          ((uint32)((1u << ledOutput_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ledOutput_USBIO_SUSPEND_DEL_SHIFT)))
    #define ledOutput_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ledOutput_USBIO_SUSPEND_SHIFT)))
    #define ledOutput_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ledOutput_USBIO_SUSPEND_DEL_SHIFT)))
    #define ledOutput_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ledOutput__PC)
    /* Port Configuration */
    #define ledOutput_PC                 (* (reg32 *) ledOutput__PC)
#endif
/* Pin State */
#define ledOutput_PS                     (* (reg32 *) ledOutput__PS)
/* Data Register */
#define ledOutput_DR                     (* (reg32 *) ledOutput__DR)
/* Input Buffer Disable Override */
#define ledOutput_INP_DIS                (* (reg32 *) ledOutput__PC2)

/* Interrupt configuration Registers */
#define ledOutput_INTCFG                 (* (reg32 *) ledOutput__INTCFG)
#define ledOutput_INTSTAT                (* (reg32 *) ledOutput__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ledOutput_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ledOutput__SIO)
    #define ledOutput_SIO_REG            (* (reg32 *) ledOutput__SIO)
#endif /* (ledOutput__SIO_CFG) */

/* USBIO registers */
#if !defined(ledOutput__PC) && (CY_PSOC4_4200L)
    #define ledOutput_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ledOutput_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ledOutput_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ledOutput_DRIVE_MODE_SHIFT       (0x00u)
#define ledOutput_DRIVE_MODE_MASK        (0x07u << ledOutput_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ledOutput_H */


/* [] END OF FILE */
