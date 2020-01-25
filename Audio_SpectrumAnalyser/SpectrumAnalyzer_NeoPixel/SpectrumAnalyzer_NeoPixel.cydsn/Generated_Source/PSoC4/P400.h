/*******************************************************************************
* File Name: P400.h  
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

#if !defined(CY_PINS_P400_H) /* Pins P400_H */
#define CY_PINS_P400_H

#include "cytypes.h"
#include "cyfitter.h"
#include "P400_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    P400_Write(uint8 value) ;
void    P400_SetDriveMode(uint8 mode) ;
uint8   P400_ReadDataReg(void) ;
uint8   P400_Read(void) ;
uint8   P400_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define P400_DRIVE_MODE_BITS        (3)
#define P400_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - P400_DRIVE_MODE_BITS))
#define P400_DRIVE_MODE_SHIFT       (0x00u)
#define P400_DRIVE_MODE_MASK        (0x07u << P400_DRIVE_MODE_SHIFT)

#define P400_DM_ALG_HIZ         (0x00u << P400_DRIVE_MODE_SHIFT)
#define P400_DM_DIG_HIZ         (0x01u << P400_DRIVE_MODE_SHIFT)
#define P400_DM_RES_UP          (0x02u << P400_DRIVE_MODE_SHIFT)
#define P400_DM_RES_DWN         (0x03u << P400_DRIVE_MODE_SHIFT)
#define P400_DM_OD_LO           (0x04u << P400_DRIVE_MODE_SHIFT)
#define P400_DM_OD_HI           (0x05u << P400_DRIVE_MODE_SHIFT)
#define P400_DM_STRONG          (0x06u << P400_DRIVE_MODE_SHIFT)
#define P400_DM_RES_UPDWN       (0x07u << P400_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define P400_MASK               P400__MASK
#define P400_SHIFT              P400__SHIFT
#define P400_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P400_PS                     (* (reg32 *) P400__PS)
/* Port Configuration */
#define P400_PC                     (* (reg32 *) P400__PC)
/* Data Register */
#define P400_DR                     (* (reg32 *) P400__DR)
/* Input Buffer Disable Override */
#define P400_INP_DIS                (* (reg32 *) P400__PC2)


#if defined(P400__INTSTAT)  /* Interrupt Registers */

    #define P400_INTSTAT                (* (reg32 *) P400__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins P400_H */


/* [] END OF FILE */
