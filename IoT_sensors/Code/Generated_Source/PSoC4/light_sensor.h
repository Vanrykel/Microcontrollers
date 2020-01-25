/*******************************************************************************
* File Name: light_sensor.h  
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

#if !defined(CY_PINS_light_sensor_H) /* Pins light_sensor_H */
#define CY_PINS_light_sensor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "light_sensor_aliases.h"


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
} light_sensor_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   light_sensor_Read(void);
void    light_sensor_Write(uint8 value);
uint8   light_sensor_ReadDataReg(void);
#if defined(light_sensor__PC) || (CY_PSOC4_4200L) 
    void    light_sensor_SetDriveMode(uint8 mode);
#endif
void    light_sensor_SetInterruptMode(uint16 position, uint16 mode);
uint8   light_sensor_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void light_sensor_Sleep(void); 
void light_sensor_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(light_sensor__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define light_sensor_DRIVE_MODE_BITS        (3)
    #define light_sensor_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - light_sensor_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the light_sensor_SetDriveMode() function.
         *  @{
         */
        #define light_sensor_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define light_sensor_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define light_sensor_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define light_sensor_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define light_sensor_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define light_sensor_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define light_sensor_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define light_sensor_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define light_sensor_MASK               light_sensor__MASK
#define light_sensor_SHIFT              light_sensor__SHIFT
#define light_sensor_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in light_sensor_SetInterruptMode() function.
     *  @{
     */
        #define light_sensor_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define light_sensor_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define light_sensor_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define light_sensor_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(light_sensor__SIO)
    #define light_sensor_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(light_sensor__PC) && (CY_PSOC4_4200L)
    #define light_sensor_USBIO_ENABLE               ((uint32)0x80000000u)
    #define light_sensor_USBIO_DISABLE              ((uint32)(~light_sensor_USBIO_ENABLE))
    #define light_sensor_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define light_sensor_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define light_sensor_USBIO_ENTER_SLEEP          ((uint32)((1u << light_sensor_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << light_sensor_USBIO_SUSPEND_DEL_SHIFT)))
    #define light_sensor_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << light_sensor_USBIO_SUSPEND_SHIFT)))
    #define light_sensor_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << light_sensor_USBIO_SUSPEND_DEL_SHIFT)))
    #define light_sensor_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(light_sensor__PC)
    /* Port Configuration */
    #define light_sensor_PC                 (* (reg32 *) light_sensor__PC)
#endif
/* Pin State */
#define light_sensor_PS                     (* (reg32 *) light_sensor__PS)
/* Data Register */
#define light_sensor_DR                     (* (reg32 *) light_sensor__DR)
/* Input Buffer Disable Override */
#define light_sensor_INP_DIS                (* (reg32 *) light_sensor__PC2)

/* Interrupt configuration Registers */
#define light_sensor_INTCFG                 (* (reg32 *) light_sensor__INTCFG)
#define light_sensor_INTSTAT                (* (reg32 *) light_sensor__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define light_sensor_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(light_sensor__SIO)
    #define light_sensor_SIO_REG            (* (reg32 *) light_sensor__SIO)
#endif /* (light_sensor__SIO_CFG) */

/* USBIO registers */
#if !defined(light_sensor__PC) && (CY_PSOC4_4200L)
    #define light_sensor_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define light_sensor_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define light_sensor_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define light_sensor_DRIVE_MODE_SHIFT       (0x00u)
#define light_sensor_DRIVE_MODE_MASK        (0x07u << light_sensor_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins light_sensor_H */


/* [] END OF FILE */
