/*******************************************************************************
* File Name: SPEEDR.h  
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

#if !defined(CY_PINS_SPEEDR_H) /* Pins SPEEDR_H */
#define CY_PINS_SPEEDR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SPEEDR_aliases.h"


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
} SPEEDR_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   SPEEDR_Read(void);
void    SPEEDR_Write(uint8 value);
uint8   SPEEDR_ReadDataReg(void);
#if defined(SPEEDR__PC) || (CY_PSOC4_4200L) 
    void    SPEEDR_SetDriveMode(uint8 mode);
#endif
void    SPEEDR_SetInterruptMode(uint16 position, uint16 mode);
uint8   SPEEDR_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void SPEEDR_Sleep(void); 
void SPEEDR_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(SPEEDR__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define SPEEDR_DRIVE_MODE_BITS        (3)
    #define SPEEDR_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SPEEDR_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the SPEEDR_SetDriveMode() function.
         *  @{
         */
        #define SPEEDR_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define SPEEDR_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define SPEEDR_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define SPEEDR_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define SPEEDR_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define SPEEDR_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define SPEEDR_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define SPEEDR_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define SPEEDR_MASK               SPEEDR__MASK
#define SPEEDR_SHIFT              SPEEDR__SHIFT
#define SPEEDR_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SPEEDR_SetInterruptMode() function.
     *  @{
     */
        #define SPEEDR_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define SPEEDR_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define SPEEDR_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define SPEEDR_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(SPEEDR__SIO)
    #define SPEEDR_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(SPEEDR__PC) && (CY_PSOC4_4200L)
    #define SPEEDR_USBIO_ENABLE               ((uint32)0x80000000u)
    #define SPEEDR_USBIO_DISABLE              ((uint32)(~SPEEDR_USBIO_ENABLE))
    #define SPEEDR_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define SPEEDR_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define SPEEDR_USBIO_ENTER_SLEEP          ((uint32)((1u << SPEEDR_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << SPEEDR_USBIO_SUSPEND_DEL_SHIFT)))
    #define SPEEDR_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << SPEEDR_USBIO_SUSPEND_SHIFT)))
    #define SPEEDR_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << SPEEDR_USBIO_SUSPEND_DEL_SHIFT)))
    #define SPEEDR_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(SPEEDR__PC)
    /* Port Configuration */
    #define SPEEDR_PC                 (* (reg32 *) SPEEDR__PC)
#endif
/* Pin State */
#define SPEEDR_PS                     (* (reg32 *) SPEEDR__PS)
/* Data Register */
#define SPEEDR_DR                     (* (reg32 *) SPEEDR__DR)
/* Input Buffer Disable Override */
#define SPEEDR_INP_DIS                (* (reg32 *) SPEEDR__PC2)

/* Interrupt configuration Registers */
#define SPEEDR_INTCFG                 (* (reg32 *) SPEEDR__INTCFG)
#define SPEEDR_INTSTAT                (* (reg32 *) SPEEDR__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define SPEEDR_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(SPEEDR__SIO)
    #define SPEEDR_SIO_REG            (* (reg32 *) SPEEDR__SIO)
#endif /* (SPEEDR__SIO_CFG) */

/* USBIO registers */
#if !defined(SPEEDR__PC) && (CY_PSOC4_4200L)
    #define SPEEDR_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define SPEEDR_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define SPEEDR_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define SPEEDR_DRIVE_MODE_SHIFT       (0x00u)
#define SPEEDR_DRIVE_MODE_MASK        (0x07u << SPEEDR_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins SPEEDR_H */


/* [] END OF FILE */
