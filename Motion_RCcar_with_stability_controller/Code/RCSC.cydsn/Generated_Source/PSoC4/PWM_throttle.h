/*******************************************************************************
* File Name: PWM_throttle.h  
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

#if !defined(CY_PINS_PWM_throttle_H) /* Pins PWM_throttle_H */
#define CY_PINS_PWM_throttle_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWM_throttle_aliases.h"


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
} PWM_throttle_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PWM_throttle_Read(void);
void    PWM_throttle_Write(uint8 value);
uint8   PWM_throttle_ReadDataReg(void);
#if defined(PWM_throttle__PC) || (CY_PSOC4_4200L) 
    void    PWM_throttle_SetDriveMode(uint8 mode);
#endif
void    PWM_throttle_SetInterruptMode(uint16 position, uint16 mode);
uint8   PWM_throttle_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PWM_throttle_Sleep(void); 
void PWM_throttle_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PWM_throttle__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PWM_throttle_DRIVE_MODE_BITS        (3)
    #define PWM_throttle_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWM_throttle_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PWM_throttle_SetDriveMode() function.
         *  @{
         */
        #define PWM_throttle_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PWM_throttle_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PWM_throttle_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PWM_throttle_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PWM_throttle_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PWM_throttle_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PWM_throttle_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PWM_throttle_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PWM_throttle_MASK               PWM_throttle__MASK
#define PWM_throttle_SHIFT              PWM_throttle__SHIFT
#define PWM_throttle_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PWM_throttle_SetInterruptMode() function.
     *  @{
     */
        #define PWM_throttle_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PWM_throttle_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PWM_throttle_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PWM_throttle_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PWM_throttle__SIO)
    #define PWM_throttle_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PWM_throttle__PC) && (CY_PSOC4_4200L)
    #define PWM_throttle_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PWM_throttle_USBIO_DISABLE              ((uint32)(~PWM_throttle_USBIO_ENABLE))
    #define PWM_throttle_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PWM_throttle_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PWM_throttle_USBIO_ENTER_SLEEP          ((uint32)((1u << PWM_throttle_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PWM_throttle_USBIO_SUSPEND_DEL_SHIFT)))
    #define PWM_throttle_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PWM_throttle_USBIO_SUSPEND_SHIFT)))
    #define PWM_throttle_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PWM_throttle_USBIO_SUSPEND_DEL_SHIFT)))
    #define PWM_throttle_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PWM_throttle__PC)
    /* Port Configuration */
    #define PWM_throttle_PC                 (* (reg32 *) PWM_throttle__PC)
#endif
/* Pin State */
#define PWM_throttle_PS                     (* (reg32 *) PWM_throttle__PS)
/* Data Register */
#define PWM_throttle_DR                     (* (reg32 *) PWM_throttle__DR)
/* Input Buffer Disable Override */
#define PWM_throttle_INP_DIS                (* (reg32 *) PWM_throttle__PC2)

/* Interrupt configuration Registers */
#define PWM_throttle_INTCFG                 (* (reg32 *) PWM_throttle__INTCFG)
#define PWM_throttle_INTSTAT                (* (reg32 *) PWM_throttle__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PWM_throttle_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PWM_throttle__SIO)
    #define PWM_throttle_SIO_REG            (* (reg32 *) PWM_throttle__SIO)
#endif /* (PWM_throttle__SIO_CFG) */

/* USBIO registers */
#if !defined(PWM_throttle__PC) && (CY_PSOC4_4200L)
    #define PWM_throttle_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PWM_throttle_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PWM_throttle_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PWM_throttle_DRIVE_MODE_SHIFT       (0x00u)
#define PWM_throttle_DRIVE_MODE_MASK        (0x07u << PWM_throttle_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PWM_throttle_H */


/* [] END OF FILE */
