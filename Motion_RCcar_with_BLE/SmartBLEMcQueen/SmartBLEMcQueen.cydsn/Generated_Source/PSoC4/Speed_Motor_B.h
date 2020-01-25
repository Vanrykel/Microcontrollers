/*******************************************************************************
* File Name: Speed_Motor_B.h  
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

#if !defined(CY_PINS_Speed_Motor_B_H) /* Pins Speed_Motor_B_H */
#define CY_PINS_Speed_Motor_B_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Speed_Motor_B_aliases.h"


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
} Speed_Motor_B_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Speed_Motor_B_Read(void);
void    Speed_Motor_B_Write(uint8 value);
uint8   Speed_Motor_B_ReadDataReg(void);
#if defined(Speed_Motor_B__PC) || (CY_PSOC4_4200L) 
    void    Speed_Motor_B_SetDriveMode(uint8 mode);
#endif
void    Speed_Motor_B_SetInterruptMode(uint16 position, uint16 mode);
uint8   Speed_Motor_B_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Speed_Motor_B_Sleep(void); 
void Speed_Motor_B_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Speed_Motor_B__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Speed_Motor_B_DRIVE_MODE_BITS        (3)
    #define Speed_Motor_B_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Speed_Motor_B_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Speed_Motor_B_SetDriveMode() function.
         *  @{
         */
        #define Speed_Motor_B_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Speed_Motor_B_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Speed_Motor_B_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Speed_Motor_B_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Speed_Motor_B_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Speed_Motor_B_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Speed_Motor_B_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Speed_Motor_B_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Speed_Motor_B_MASK               Speed_Motor_B__MASK
#define Speed_Motor_B_SHIFT              Speed_Motor_B__SHIFT
#define Speed_Motor_B_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Speed_Motor_B_SetInterruptMode() function.
     *  @{
     */
        #define Speed_Motor_B_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Speed_Motor_B_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Speed_Motor_B_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Speed_Motor_B_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Speed_Motor_B__SIO)
    #define Speed_Motor_B_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Speed_Motor_B__PC) && (CY_PSOC4_4200L)
    #define Speed_Motor_B_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Speed_Motor_B_USBIO_DISABLE              ((uint32)(~Speed_Motor_B_USBIO_ENABLE))
    #define Speed_Motor_B_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Speed_Motor_B_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Speed_Motor_B_USBIO_ENTER_SLEEP          ((uint32)((1u << Speed_Motor_B_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Speed_Motor_B_USBIO_SUSPEND_DEL_SHIFT)))
    #define Speed_Motor_B_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Speed_Motor_B_USBIO_SUSPEND_SHIFT)))
    #define Speed_Motor_B_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Speed_Motor_B_USBIO_SUSPEND_DEL_SHIFT)))
    #define Speed_Motor_B_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Speed_Motor_B__PC)
    /* Port Configuration */
    #define Speed_Motor_B_PC                 (* (reg32 *) Speed_Motor_B__PC)
#endif
/* Pin State */
#define Speed_Motor_B_PS                     (* (reg32 *) Speed_Motor_B__PS)
/* Data Register */
#define Speed_Motor_B_DR                     (* (reg32 *) Speed_Motor_B__DR)
/* Input Buffer Disable Override */
#define Speed_Motor_B_INP_DIS                (* (reg32 *) Speed_Motor_B__PC2)

/* Interrupt configuration Registers */
#define Speed_Motor_B_INTCFG                 (* (reg32 *) Speed_Motor_B__INTCFG)
#define Speed_Motor_B_INTSTAT                (* (reg32 *) Speed_Motor_B__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Speed_Motor_B_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Speed_Motor_B__SIO)
    #define Speed_Motor_B_SIO_REG            (* (reg32 *) Speed_Motor_B__SIO)
#endif /* (Speed_Motor_B__SIO_CFG) */

/* USBIO registers */
#if !defined(Speed_Motor_B__PC) && (CY_PSOC4_4200L)
    #define Speed_Motor_B_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Speed_Motor_B_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Speed_Motor_B_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Speed_Motor_B_DRIVE_MODE_SHIFT       (0x00u)
#define Speed_Motor_B_DRIVE_MODE_MASK        (0x07u << Speed_Motor_B_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Speed_Motor_B_H */


/* [] END OF FILE */
