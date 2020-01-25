/*******************************************************************************
* File Name: DHT11.h  
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

#if !defined(CY_PINS_DHT11_H) /* Pins DHT11_H */
#define CY_PINS_DHT11_H

#include "cytypes.h"
#include "cyfitter.h"
#include "DHT11_aliases.h"


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
} DHT11_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   DHT11_Read(void);
void    DHT11_Write(uint8 value);
uint8   DHT11_ReadDataReg(void);
#if defined(DHT11__PC) || (CY_PSOC4_4200L) 
    void    DHT11_SetDriveMode(uint8 mode);
#endif
void    DHT11_SetInterruptMode(uint16 position, uint16 mode);
uint8   DHT11_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void DHT11_Sleep(void); 
void DHT11_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(DHT11__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define DHT11_DRIVE_MODE_BITS        (3)
    #define DHT11_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - DHT11_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the DHT11_SetDriveMode() function.
         *  @{
         */
        #define DHT11_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define DHT11_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define DHT11_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define DHT11_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define DHT11_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define DHT11_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define DHT11_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define DHT11_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define DHT11_MASK               DHT11__MASK
#define DHT11_SHIFT              DHT11__SHIFT
#define DHT11_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DHT11_SetInterruptMode() function.
     *  @{
     */
        #define DHT11_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define DHT11_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define DHT11_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define DHT11_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(DHT11__SIO)
    #define DHT11_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(DHT11__PC) && (CY_PSOC4_4200L)
    #define DHT11_USBIO_ENABLE               ((uint32)0x80000000u)
    #define DHT11_USBIO_DISABLE              ((uint32)(~DHT11_USBIO_ENABLE))
    #define DHT11_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define DHT11_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define DHT11_USBIO_ENTER_SLEEP          ((uint32)((1u << DHT11_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << DHT11_USBIO_SUSPEND_DEL_SHIFT)))
    #define DHT11_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << DHT11_USBIO_SUSPEND_SHIFT)))
    #define DHT11_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << DHT11_USBIO_SUSPEND_DEL_SHIFT)))
    #define DHT11_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(DHT11__PC)
    /* Port Configuration */
    #define DHT11_PC                 (* (reg32 *) DHT11__PC)
#endif
/* Pin State */
#define DHT11_PS                     (* (reg32 *) DHT11__PS)
/* Data Register */
#define DHT11_DR                     (* (reg32 *) DHT11__DR)
/* Input Buffer Disable Override */
#define DHT11_INP_DIS                (* (reg32 *) DHT11__PC2)

/* Interrupt configuration Registers */
#define DHT11_INTCFG                 (* (reg32 *) DHT11__INTCFG)
#define DHT11_INTSTAT                (* (reg32 *) DHT11__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define DHT11_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(DHT11__SIO)
    #define DHT11_SIO_REG            (* (reg32 *) DHT11__SIO)
#endif /* (DHT11__SIO_CFG) */

/* USBIO registers */
#if !defined(DHT11__PC) && (CY_PSOC4_4200L)
    #define DHT11_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define DHT11_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define DHT11_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define DHT11_DRIVE_MODE_SHIFT       (0x00u)
#define DHT11_DRIVE_MODE_MASK        (0x07u << DHT11_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins DHT11_H */


/* [] END OF FILE */
