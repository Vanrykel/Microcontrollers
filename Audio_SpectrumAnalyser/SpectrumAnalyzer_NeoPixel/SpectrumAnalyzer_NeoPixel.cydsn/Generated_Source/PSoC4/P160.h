/*******************************************************************************
* File Name: P160.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_P160_H) /* Pins P160_H */
#define CY_PINS_P160_H

#include "cytypes.h"
#include "cyfitter.h"
#include "P160_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    P160_Write(uint8 value) ;
void    P160_SetDriveMode(uint8 mode) ;
uint8   P160_ReadDataReg(void) ;
uint8   P160_Read(void) ;
uint8   P160_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define P160_DRIVE_MODE_BITS        (3)
#define P160_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - P160_DRIVE_MODE_BITS))
#define P160_DRIVE_MODE_SHIFT       (0x00u)
#define P160_DRIVE_MODE_MASK        (0x07u << P160_DRIVE_MODE_SHIFT)

#define P160_DM_ALG_HIZ         (0x00u << P160_DRIVE_MODE_SHIFT)
#define P160_DM_DIG_HIZ         (0x01u << P160_DRIVE_MODE_SHIFT)
#define P160_DM_RES_UP          (0x02u << P160_DRIVE_MODE_SHIFT)
#define P160_DM_RES_DWN         (0x03u << P160_DRIVE_MODE_SHIFT)
#define P160_DM_OD_LO           (0x04u << P160_DRIVE_MODE_SHIFT)
#define P160_DM_OD_HI           (0x05u << P160_DRIVE_MODE_SHIFT)
#define P160_DM_STRONG          (0x06u << P160_DRIVE_MODE_SHIFT)
#define P160_DM_RES_UPDWN       (0x07u << P160_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define P160_MASK               P160__MASK
#define P160_SHIFT              P160__SHIFT
#define P160_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P160_PS                     (* (reg32 *) P160__PS)
/* Port Configuration */
#define P160_PC                     (* (reg32 *) P160__PC)
/* Data Register */
#define P160_DR                     (* (reg32 *) P160__DR)
/* Input Buffer Disable Override */
#define P160_INP_DIS                (* (reg32 *) P160__PC2)


#if defined(P160__INTSTAT)  /* Interrupt Registers */

    #define P160_INTSTAT                (* (reg32 *) P160__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins P160_H */


/* [] END OF FILE */
