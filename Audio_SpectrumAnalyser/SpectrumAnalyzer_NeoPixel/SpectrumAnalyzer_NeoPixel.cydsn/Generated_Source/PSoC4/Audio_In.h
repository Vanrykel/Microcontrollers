/*******************************************************************************
* File Name: Audio_In.h  
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

#if !defined(CY_PINS_Audio_In_H) /* Pins Audio_In_H */
#define CY_PINS_Audio_In_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Audio_In_aliases.h"


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
} Audio_In_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Audio_In_Read(void);
void    Audio_In_Write(uint8 value);
uint8   Audio_In_ReadDataReg(void);
#if defined(Audio_In__PC) || (CY_PSOC4_4200L) 
    void    Audio_In_SetDriveMode(uint8 mode);
#endif
void    Audio_In_SetInterruptMode(uint16 position, uint16 mode);
uint8   Audio_In_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Audio_In_Sleep(void); 
void Audio_In_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Audio_In__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Audio_In_DRIVE_MODE_BITS        (3)
    #define Audio_In_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Audio_In_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Audio_In_SetDriveMode() function.
         *  @{
         */
        #define Audio_In_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Audio_In_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Audio_In_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Audio_In_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Audio_In_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Audio_In_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Audio_In_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Audio_In_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Audio_In_MASK               Audio_In__MASK
#define Audio_In_SHIFT              Audio_In__SHIFT
#define Audio_In_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Audio_In_SetInterruptMode() function.
     *  @{
     */
        #define Audio_In_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Audio_In_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Audio_In_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Audio_In_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Audio_In__SIO)
    #define Audio_In_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Audio_In__PC) && (CY_PSOC4_4200L)
    #define Audio_In_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Audio_In_USBIO_DISABLE              ((uint32)(~Audio_In_USBIO_ENABLE))
    #define Audio_In_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Audio_In_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Audio_In_USBIO_ENTER_SLEEP          ((uint32)((1u << Audio_In_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Audio_In_USBIO_SUSPEND_DEL_SHIFT)))
    #define Audio_In_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Audio_In_USBIO_SUSPEND_SHIFT)))
    #define Audio_In_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Audio_In_USBIO_SUSPEND_DEL_SHIFT)))
    #define Audio_In_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Audio_In__PC)
    /* Port Configuration */
    #define Audio_In_PC                 (* (reg32 *) Audio_In__PC)
#endif
/* Pin State */
#define Audio_In_PS                     (* (reg32 *) Audio_In__PS)
/* Data Register */
#define Audio_In_DR                     (* (reg32 *) Audio_In__DR)
/* Input Buffer Disable Override */
#define Audio_In_INP_DIS                (* (reg32 *) Audio_In__PC2)

/* Interrupt configuration Registers */
#define Audio_In_INTCFG                 (* (reg32 *) Audio_In__INTCFG)
#define Audio_In_INTSTAT                (* (reg32 *) Audio_In__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Audio_In_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Audio_In__SIO)
    #define Audio_In_SIO_REG            (* (reg32 *) Audio_In__SIO)
#endif /* (Audio_In__SIO_CFG) */

/* USBIO registers */
#if !defined(Audio_In__PC) && (CY_PSOC4_4200L)
    #define Audio_In_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Audio_In_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Audio_In_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Audio_In_DRIVE_MODE_SHIFT       (0x00u)
#define Audio_In_DRIVE_MODE_MASK        (0x07u << Audio_In_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Audio_In_H */


/* [] END OF FILE */
