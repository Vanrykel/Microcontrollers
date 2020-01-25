/*******************************************************************************
* File Name: P6_25KHz.h  
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

#if !defined(CY_PINS_P6_25KHz_H) /* Pins P6_25KHz_H */
#define CY_PINS_P6_25KHz_H

#include "cytypes.h"
#include "cyfitter.h"
#include "P6_25KHz_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    P6_25KHz_Write(uint8 value) ;
void    P6_25KHz_SetDriveMode(uint8 mode) ;
uint8   P6_25KHz_ReadDataReg(void) ;
uint8   P6_25KHz_Read(void) ;
uint8   P6_25KHz_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define P6_25KHz_DRIVE_MODE_BITS        (3)
#define P6_25KHz_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - P6_25KHz_DRIVE_MODE_BITS))
#define P6_25KHz_DRIVE_MODE_SHIFT       (0x00u)
#define P6_25KHz_DRIVE_MODE_MASK        (0x07u << P6_25KHz_DRIVE_MODE_SHIFT)

#define P6_25KHz_DM_ALG_HIZ         (0x00u << P6_25KHz_DRIVE_MODE_SHIFT)
#define P6_25KHz_DM_DIG_HIZ         (0x01u << P6_25KHz_DRIVE_MODE_SHIFT)
#define P6_25KHz_DM_RES_UP          (0x02u << P6_25KHz_DRIVE_MODE_SHIFT)
#define P6_25KHz_DM_RES_DWN         (0x03u << P6_25KHz_DRIVE_MODE_SHIFT)
#define P6_25KHz_DM_OD_LO           (0x04u << P6_25KHz_DRIVE_MODE_SHIFT)
#define P6_25KHz_DM_OD_HI           (0x05u << P6_25KHz_DRIVE_MODE_SHIFT)
#define P6_25KHz_DM_STRONG          (0x06u << P6_25KHz_DRIVE_MODE_SHIFT)
#define P6_25KHz_DM_RES_UPDWN       (0x07u << P6_25KHz_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define P6_25KHz_MASK               P6_25KHz__MASK
#define P6_25KHz_SHIFT              P6_25KHz__SHIFT
#define P6_25KHz_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P6_25KHz_PS                     (* (reg32 *) P6_25KHz__PS)
/* Port Configuration */
#define P6_25KHz_PC                     (* (reg32 *) P6_25KHz__PC)
/* Data Register */
#define P6_25KHz_DR                     (* (reg32 *) P6_25KHz__DR)
/* Input Buffer Disable Override */
#define P6_25KHz_INP_DIS                (* (reg32 *) P6_25KHz__PC2)


#if defined(P6_25KHz__INTSTAT)  /* Interrupt Registers */

    #define P6_25KHz_INTSTAT                (* (reg32 *) P6_25KHz__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins P6_25KHz_H */


/* [] END OF FILE */
