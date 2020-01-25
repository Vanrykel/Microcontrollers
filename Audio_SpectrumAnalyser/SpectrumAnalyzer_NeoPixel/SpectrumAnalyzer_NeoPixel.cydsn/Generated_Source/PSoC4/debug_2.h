/*******************************************************************************
* File Name: debug_2.h  
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

#if !defined(CY_PINS_debug_2_H) /* Pins debug_2_H */
#define CY_PINS_debug_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "debug_2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    debug_2_Write(uint8 value) ;
void    debug_2_SetDriveMode(uint8 mode) ;
uint8   debug_2_ReadDataReg(void) ;
uint8   debug_2_Read(void) ;
uint8   debug_2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define debug_2_DRIVE_MODE_BITS        (3)
#define debug_2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - debug_2_DRIVE_MODE_BITS))
#define debug_2_DRIVE_MODE_SHIFT       (0x00u)
#define debug_2_DRIVE_MODE_MASK        (0x07u << debug_2_DRIVE_MODE_SHIFT)

#define debug_2_DM_ALG_HIZ         (0x00u << debug_2_DRIVE_MODE_SHIFT)
#define debug_2_DM_DIG_HIZ         (0x01u << debug_2_DRIVE_MODE_SHIFT)
#define debug_2_DM_RES_UP          (0x02u << debug_2_DRIVE_MODE_SHIFT)
#define debug_2_DM_RES_DWN         (0x03u << debug_2_DRIVE_MODE_SHIFT)
#define debug_2_DM_OD_LO           (0x04u << debug_2_DRIVE_MODE_SHIFT)
#define debug_2_DM_OD_HI           (0x05u << debug_2_DRIVE_MODE_SHIFT)
#define debug_2_DM_STRONG          (0x06u << debug_2_DRIVE_MODE_SHIFT)
#define debug_2_DM_RES_UPDWN       (0x07u << debug_2_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define debug_2_MASK               debug_2__MASK
#define debug_2_SHIFT              debug_2__SHIFT
#define debug_2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define debug_2_PS                     (* (reg32 *) debug_2__PS)
/* Port Configuration */
#define debug_2_PC                     (* (reg32 *) debug_2__PC)
/* Data Register */
#define debug_2_DR                     (* (reg32 *) debug_2__DR)
/* Input Buffer Disable Override */
#define debug_2_INP_DIS                (* (reg32 *) debug_2__PC2)


#if defined(debug_2__INTSTAT)  /* Interrupt Registers */

    #define debug_2_INTSTAT                (* (reg32 *) debug_2__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins debug_2_H */


/* [] END OF FILE */
