/*******************************************************************************
* File Name: LATCH.h  
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

#if !defined(CY_PINS_LATCH_H) /* Pins LATCH_H */
#define CY_PINS_LATCH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LATCH_aliases.h"


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
} LATCH_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LATCH_Read(void);
void    LATCH_Write(uint8 value);
uint8   LATCH_ReadDataReg(void);
#if defined(LATCH__PC) || (CY_PSOC4_4200L) 
    void    LATCH_SetDriveMode(uint8 mode);
#endif
void    LATCH_SetInterruptMode(uint16 position, uint16 mode);
uint8   LATCH_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LATCH_Sleep(void); 
void LATCH_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LATCH__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LATCH_DRIVE_MODE_BITS        (3)
    #define LATCH_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LATCH_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LATCH_SetDriveMode() function.
         *  @{
         */
        #define LATCH_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LATCH_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LATCH_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LATCH_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LATCH_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LATCH_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LATCH_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LATCH_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LATCH_MASK               LATCH__MASK
#define LATCH_SHIFT              LATCH__SHIFT
#define LATCH_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LATCH_SetInterruptMode() function.
     *  @{
     */
        #define LATCH_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LATCH_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LATCH_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LATCH_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LATCH__SIO)
    #define LATCH_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LATCH__PC) && (CY_PSOC4_4200L)
    #define LATCH_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LATCH_USBIO_DISABLE              ((uint32)(~LATCH_USBIO_ENABLE))
    #define LATCH_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LATCH_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LATCH_USBIO_ENTER_SLEEP          ((uint32)((1u << LATCH_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LATCH_USBIO_SUSPEND_DEL_SHIFT)))
    #define LATCH_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LATCH_USBIO_SUSPEND_SHIFT)))
    #define LATCH_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LATCH_USBIO_SUSPEND_DEL_SHIFT)))
    #define LATCH_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LATCH__PC)
    /* Port Configuration */
    #define LATCH_PC                 (* (reg32 *) LATCH__PC)
#endif
/* Pin State */
#define LATCH_PS                     (* (reg32 *) LATCH__PS)
/* Data Register */
#define LATCH_DR                     (* (reg32 *) LATCH__DR)
/* Input Buffer Disable Override */
#define LATCH_INP_DIS                (* (reg32 *) LATCH__PC2)

/* Interrupt configuration Registers */
#define LATCH_INTCFG                 (* (reg32 *) LATCH__INTCFG)
#define LATCH_INTSTAT                (* (reg32 *) LATCH__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LATCH_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LATCH__SIO)
    #define LATCH_SIO_REG            (* (reg32 *) LATCH__SIO)
#endif /* (LATCH__SIO_CFG) */

/* USBIO registers */
#if !defined(LATCH__PC) && (CY_PSOC4_4200L)
    #define LATCH_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LATCH_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LATCH_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LATCH_DRIVE_MODE_SHIFT       (0x00u)
#define LATCH_DRIVE_MODE_MASK        (0x07u << LATCH_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LATCH_H */


/* [] END OF FILE */
