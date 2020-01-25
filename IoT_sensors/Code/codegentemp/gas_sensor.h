/*******************************************************************************
* File Name: gas_sensor.h  
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

#if !defined(CY_PINS_gas_sensor_H) /* Pins gas_sensor_H */
#define CY_PINS_gas_sensor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "gas_sensor_aliases.h"


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
} gas_sensor_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   gas_sensor_Read(void);
void    gas_sensor_Write(uint8 value);
uint8   gas_sensor_ReadDataReg(void);
#if defined(gas_sensor__PC) || (CY_PSOC4_4200L) 
    void    gas_sensor_SetDriveMode(uint8 mode);
#endif
void    gas_sensor_SetInterruptMode(uint16 position, uint16 mode);
uint8   gas_sensor_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void gas_sensor_Sleep(void); 
void gas_sensor_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(gas_sensor__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define gas_sensor_DRIVE_MODE_BITS        (3)
    #define gas_sensor_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - gas_sensor_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the gas_sensor_SetDriveMode() function.
         *  @{
         */
        #define gas_sensor_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define gas_sensor_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define gas_sensor_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define gas_sensor_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define gas_sensor_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define gas_sensor_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define gas_sensor_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define gas_sensor_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define gas_sensor_MASK               gas_sensor__MASK
#define gas_sensor_SHIFT              gas_sensor__SHIFT
#define gas_sensor_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in gas_sensor_SetInterruptMode() function.
     *  @{
     */
        #define gas_sensor_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define gas_sensor_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define gas_sensor_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define gas_sensor_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(gas_sensor__SIO)
    #define gas_sensor_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(gas_sensor__PC) && (CY_PSOC4_4200L)
    #define gas_sensor_USBIO_ENABLE               ((uint32)0x80000000u)
    #define gas_sensor_USBIO_DISABLE              ((uint32)(~gas_sensor_USBIO_ENABLE))
    #define gas_sensor_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define gas_sensor_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define gas_sensor_USBIO_ENTER_SLEEP          ((uint32)((1u << gas_sensor_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << gas_sensor_USBIO_SUSPEND_DEL_SHIFT)))
    #define gas_sensor_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << gas_sensor_USBIO_SUSPEND_SHIFT)))
    #define gas_sensor_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << gas_sensor_USBIO_SUSPEND_DEL_SHIFT)))
    #define gas_sensor_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(gas_sensor__PC)
    /* Port Configuration */
    #define gas_sensor_PC                 (* (reg32 *) gas_sensor__PC)
#endif
/* Pin State */
#define gas_sensor_PS                     (* (reg32 *) gas_sensor__PS)
/* Data Register */
#define gas_sensor_DR                     (* (reg32 *) gas_sensor__DR)
/* Input Buffer Disable Override */
#define gas_sensor_INP_DIS                (* (reg32 *) gas_sensor__PC2)

/* Interrupt configuration Registers */
#define gas_sensor_INTCFG                 (* (reg32 *) gas_sensor__INTCFG)
#define gas_sensor_INTSTAT                (* (reg32 *) gas_sensor__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define gas_sensor_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(gas_sensor__SIO)
    #define gas_sensor_SIO_REG            (* (reg32 *) gas_sensor__SIO)
#endif /* (gas_sensor__SIO_CFG) */

/* USBIO registers */
#if !defined(gas_sensor__PC) && (CY_PSOC4_4200L)
    #define gas_sensor_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define gas_sensor_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define gas_sensor_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define gas_sensor_DRIVE_MODE_SHIFT       (0x00u)
#define gas_sensor_DRIVE_MODE_MASK        (0x07u << gas_sensor_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins gas_sensor_H */


/* [] END OF FILE */
