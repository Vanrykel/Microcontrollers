/*******************************************************************************
* File Name: P16KHz.h  
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

#if !defined(CY_PINS_P16KHz_H) /* Pins P16KHz_H */
#define CY_PINS_P16KHz_H

#include "cytypes.h"
#include "cyfitter.h"
#include "P16KHz_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    P16KHz_Write(uint8 value) ;
void    P16KHz_SetDriveMode(uint8 mode) ;
uint8   P16KHz_ReadDataReg(void) ;
uint8   P16KHz_Read(void) ;
uint8   P16KHz_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define P16KHz_DRIVE_MODE_BITS        (3)
#define P16KHz_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - P16KHz_DRIVE_MODE_BITS))
#define P16KHz_DRIVE_MODE_SHIFT       (0x00u)
#define P16KHz_DRIVE_MODE_MASK        (0x07u << P16KHz_DRIVE_MODE_SHIFT)

#define P16KHz_DM_ALG_HIZ         (0x00u << P16KHz_DRIVE_MODE_SHIFT)
#define P16KHz_DM_DIG_HIZ         (0x01u << P16KHz_DRIVE_MODE_SHIFT)
#define P16KHz_DM_RES_UP          (0x02u << P16KHz_DRIVE_MODE_SHIFT)
#define P16KHz_DM_RES_DWN         (0x03u << P16KHz_DRIVE_MODE_SHIFT)
#define P16KHz_DM_OD_LO           (0x04u << P16KHz_DRIVE_MODE_SHIFT)
#define P16KHz_DM_OD_HI           (0x05u << P16KHz_DRIVE_MODE_SHIFT)
#define P16KHz_DM_STRONG          (0x06u << P16KHz_DRIVE_MODE_SHIFT)
#define P16KHz_DM_RES_UPDWN       (0x07u << P16KHz_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define P16KHz_MASK               P16KHz__MASK
#define P16KHz_SHIFT              P16KHz__SHIFT
#define P16KHz_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P16KHz_PS                     (* (reg32 *) P16KHz__PS)
/* Port Configuration */
#define P16KHz_PC                     (* (reg32 *) P16KHz__PC)
/* Data Register */
#define P16KHz_DR                     (* (reg32 *) P16KHz__DR)
/* Input Buffer Disable Override */
#define P16KHz_INP_DIS                (* (reg32 *) P16KHz__PC2)


#if defined(P16KHz__INTSTAT)  /* Interrupt Registers */

    #define P16KHz_INTSTAT                (* (reg32 *) P16KHz__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins P16KHz_H */


/* [] END OF FILE */
