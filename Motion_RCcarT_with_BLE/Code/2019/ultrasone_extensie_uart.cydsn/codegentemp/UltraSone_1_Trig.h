/*******************************************************************************
* File Name: UltraSone_1_Trig.h  
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

#if !defined(CY_PINS_UltraSone_1_Trig_H) /* Pins UltraSone_1_Trig_H */
#define CY_PINS_UltraSone_1_Trig_H

#include "cytypes.h"
#include "cyfitter.h"
#include "UltraSone_1_Trig_aliases.h"


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
} UltraSone_1_Trig_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   UltraSone_1_Trig_Read(void);
void    UltraSone_1_Trig_Write(uint8 value);
uint8   UltraSone_1_Trig_ReadDataReg(void);
#if defined(UltraSone_1_Trig__PC) || (CY_PSOC4_4200L) 
    void    UltraSone_1_Trig_SetDriveMode(uint8 mode);
#endif
void    UltraSone_1_Trig_SetInterruptMode(uint16 position, uint16 mode);
uint8   UltraSone_1_Trig_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void UltraSone_1_Trig_Sleep(void); 
void UltraSone_1_Trig_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(UltraSone_1_Trig__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define UltraSone_1_Trig_DRIVE_MODE_BITS        (3)
    #define UltraSone_1_Trig_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - UltraSone_1_Trig_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the UltraSone_1_Trig_SetDriveMode() function.
         *  @{
         */
        #define UltraSone_1_Trig_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define UltraSone_1_Trig_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define UltraSone_1_Trig_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define UltraSone_1_Trig_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define UltraSone_1_Trig_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define UltraSone_1_Trig_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define UltraSone_1_Trig_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define UltraSone_1_Trig_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define UltraSone_1_Trig_MASK               UltraSone_1_Trig__MASK
#define UltraSone_1_Trig_SHIFT              UltraSone_1_Trig__SHIFT
#define UltraSone_1_Trig_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in UltraSone_1_Trig_SetInterruptMode() function.
     *  @{
     */
        #define UltraSone_1_Trig_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define UltraSone_1_Trig_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define UltraSone_1_Trig_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define UltraSone_1_Trig_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(UltraSone_1_Trig__SIO)
    #define UltraSone_1_Trig_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(UltraSone_1_Trig__PC) && (CY_PSOC4_4200L)
    #define UltraSone_1_Trig_USBIO_ENABLE               ((uint32)0x80000000u)
    #define UltraSone_1_Trig_USBIO_DISABLE              ((uint32)(~UltraSone_1_Trig_USBIO_ENABLE))
    #define UltraSone_1_Trig_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define UltraSone_1_Trig_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define UltraSone_1_Trig_USBIO_ENTER_SLEEP          ((uint32)((1u << UltraSone_1_Trig_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << UltraSone_1_Trig_USBIO_SUSPEND_DEL_SHIFT)))
    #define UltraSone_1_Trig_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << UltraSone_1_Trig_USBIO_SUSPEND_SHIFT)))
    #define UltraSone_1_Trig_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << UltraSone_1_Trig_USBIO_SUSPEND_DEL_SHIFT)))
    #define UltraSone_1_Trig_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(UltraSone_1_Trig__PC)
    /* Port Configuration */
    #define UltraSone_1_Trig_PC                 (* (reg32 *) UltraSone_1_Trig__PC)
#endif
/* Pin State */
#define UltraSone_1_Trig_PS                     (* (reg32 *) UltraSone_1_Trig__PS)
/* Data Register */
#define UltraSone_1_Trig_DR                     (* (reg32 *) UltraSone_1_Trig__DR)
/* Input Buffer Disable Override */
#define UltraSone_1_Trig_INP_DIS                (* (reg32 *) UltraSone_1_Trig__PC2)

/* Interrupt configuration Registers */
#define UltraSone_1_Trig_INTCFG                 (* (reg32 *) UltraSone_1_Trig__INTCFG)
#define UltraSone_1_Trig_INTSTAT                (* (reg32 *) UltraSone_1_Trig__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define UltraSone_1_Trig_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(UltraSone_1_Trig__SIO)
    #define UltraSone_1_Trig_SIO_REG            (* (reg32 *) UltraSone_1_Trig__SIO)
#endif /* (UltraSone_1_Trig__SIO_CFG) */

/* USBIO registers */
#if !defined(UltraSone_1_Trig__PC) && (CY_PSOC4_4200L)
    #define UltraSone_1_Trig_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define UltraSone_1_Trig_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define UltraSone_1_Trig_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define UltraSone_1_Trig_DRIVE_MODE_SHIFT       (0x00u)
#define UltraSone_1_Trig_DRIVE_MODE_MASK        (0x07u << UltraSone_1_Trig_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins UltraSone_1_Trig_H */


/* [] END OF FILE */
