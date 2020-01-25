/*******************************************************************************
* File Name: SPEEDL.h  
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

#if !defined(CY_PINS_SPEEDL_H) /* Pins SPEEDL_H */
#define CY_PINS_SPEEDL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SPEEDL_aliases.h"


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
} SPEEDL_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   SPEEDL_Read(void);
void    SPEEDL_Write(uint8 value);
uint8   SPEEDL_ReadDataReg(void);
#if defined(SPEEDL__PC) || (CY_PSOC4_4200L) 
    void    SPEEDL_SetDriveMode(uint8 mode);
#endif
void    SPEEDL_SetInterruptMode(uint16 position, uint16 mode);
uint8   SPEEDL_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void SPEEDL_Sleep(void); 
void SPEEDL_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(SPEEDL__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define SPEEDL_DRIVE_MODE_BITS        (3)
    #define SPEEDL_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SPEEDL_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the SPEEDL_SetDriveMode() function.
         *  @{
         */
        #define SPEEDL_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define SPEEDL_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define SPEEDL_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define SPEEDL_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define SPEEDL_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define SPEEDL_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define SPEEDL_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define SPEEDL_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define SPEEDL_MASK               SPEEDL__MASK
#define SPEEDL_SHIFT              SPEEDL__SHIFT
#define SPEEDL_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SPEEDL_SetInterruptMode() function.
     *  @{
     */
        #define SPEEDL_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define SPEEDL_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define SPEEDL_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define SPEEDL_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(SPEEDL__SIO)
    #define SPEEDL_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(SPEEDL__PC) && (CY_PSOC4_4200L)
    #define SPEEDL_USBIO_ENABLE               ((uint32)0x80000000u)
    #define SPEEDL_USBIO_DISABLE              ((uint32)(~SPEEDL_USBIO_ENABLE))
    #define SPEEDL_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define SPEEDL_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define SPEEDL_USBIO_ENTER_SLEEP          ((uint32)((1u << SPEEDL_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << SPEEDL_USBIO_SUSPEND_DEL_SHIFT)))
    #define SPEEDL_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << SPEEDL_USBIO_SUSPEND_SHIFT)))
    #define SPEEDL_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << SPEEDL_USBIO_SUSPEND_DEL_SHIFT)))
    #define SPEEDL_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(SPEEDL__PC)
    /* Port Configuration */
    #define SPEEDL_PC                 (* (reg32 *) SPEEDL__PC)
#endif
/* Pin State */
#define SPEEDL_PS                     (* (reg32 *) SPEEDL__PS)
/* Data Register */
#define SPEEDL_DR                     (* (reg32 *) SPEEDL__DR)
/* Input Buffer Disable Override */
#define SPEEDL_INP_DIS                (* (reg32 *) SPEEDL__PC2)

/* Interrupt configuration Registers */
#define SPEEDL_INTCFG                 (* (reg32 *) SPEEDL__INTCFG)
#define SPEEDL_INTSTAT                (* (reg32 *) SPEEDL__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define SPEEDL_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(SPEEDL__SIO)
    #define SPEEDL_SIO_REG            (* (reg32 *) SPEEDL__SIO)
#endif /* (SPEEDL__SIO_CFG) */

/* USBIO registers */
#if !defined(SPEEDL__PC) && (CY_PSOC4_4200L)
    #define SPEEDL_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define SPEEDL_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define SPEEDL_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define SPEEDL_DRIVE_MODE_SHIFT       (0x00u)
#define SPEEDL_DRIVE_MODE_MASK        (0x07u << SPEEDL_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins SPEEDL_H */


/* [] END OF FILE */
