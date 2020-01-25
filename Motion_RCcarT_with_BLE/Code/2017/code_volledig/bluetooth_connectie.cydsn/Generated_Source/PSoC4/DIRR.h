/*******************************************************************************
* File Name: DIRR.h  
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

#if !defined(CY_PINS_DIRR_H) /* Pins DIRR_H */
#define CY_PINS_DIRR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "DIRR_aliases.h"


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
} DIRR_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   DIRR_Read(void);
void    DIRR_Write(uint8 value);
uint8   DIRR_ReadDataReg(void);
#if defined(DIRR__PC) || (CY_PSOC4_4200L) 
    void    DIRR_SetDriveMode(uint8 mode);
#endif
void    DIRR_SetInterruptMode(uint16 position, uint16 mode);
uint8   DIRR_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void DIRR_Sleep(void); 
void DIRR_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(DIRR__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define DIRR_DRIVE_MODE_BITS        (3)
    #define DIRR_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - DIRR_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the DIRR_SetDriveMode() function.
         *  @{
         */
        #define DIRR_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define DIRR_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define DIRR_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define DIRR_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define DIRR_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define DIRR_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define DIRR_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define DIRR_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define DIRR_MASK               DIRR__MASK
#define DIRR_SHIFT              DIRR__SHIFT
#define DIRR_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DIRR_SetInterruptMode() function.
     *  @{
     */
        #define DIRR_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define DIRR_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define DIRR_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define DIRR_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(DIRR__SIO)
    #define DIRR_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(DIRR__PC) && (CY_PSOC4_4200L)
    #define DIRR_USBIO_ENABLE               ((uint32)0x80000000u)
    #define DIRR_USBIO_DISABLE              ((uint32)(~DIRR_USBIO_ENABLE))
    #define DIRR_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define DIRR_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define DIRR_USBIO_ENTER_SLEEP          ((uint32)((1u << DIRR_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << DIRR_USBIO_SUSPEND_DEL_SHIFT)))
    #define DIRR_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << DIRR_USBIO_SUSPEND_SHIFT)))
    #define DIRR_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << DIRR_USBIO_SUSPEND_DEL_SHIFT)))
    #define DIRR_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(DIRR__PC)
    /* Port Configuration */
    #define DIRR_PC                 (* (reg32 *) DIRR__PC)
#endif
/* Pin State */
#define DIRR_PS                     (* (reg32 *) DIRR__PS)
/* Data Register */
#define DIRR_DR                     (* (reg32 *) DIRR__DR)
/* Input Buffer Disable Override */
#define DIRR_INP_DIS                (* (reg32 *) DIRR__PC2)

/* Interrupt configuration Registers */
#define DIRR_INTCFG                 (* (reg32 *) DIRR__INTCFG)
#define DIRR_INTSTAT                (* (reg32 *) DIRR__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define DIRR_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(DIRR__SIO)
    #define DIRR_SIO_REG            (* (reg32 *) DIRR__SIO)
#endif /* (DIRR__SIO_CFG) */

/* USBIO registers */
#if !defined(DIRR__PC) && (CY_PSOC4_4200L)
    #define DIRR_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define DIRR_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define DIRR_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define DIRR_DRIVE_MODE_SHIFT       (0x00u)
#define DIRR_DRIVE_MODE_MASK        (0x07u << DIRR_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins DIRR_H */


/* [] END OF FILE */
