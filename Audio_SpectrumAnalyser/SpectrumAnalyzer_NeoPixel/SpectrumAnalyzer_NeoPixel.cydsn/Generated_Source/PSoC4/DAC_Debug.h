/*******************************************************************************
* File Name: DAC_Debug.h  
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

#if !defined(CY_PINS_DAC_Debug_H) /* Pins DAC_Debug_H */
#define CY_PINS_DAC_Debug_H

#include "cytypes.h"
#include "cyfitter.h"
#include "DAC_Debug_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    DAC_Debug_Write(uint8 value) ;
void    DAC_Debug_SetDriveMode(uint8 mode) ;
uint8   DAC_Debug_ReadDataReg(void) ;
uint8   DAC_Debug_Read(void) ;
uint8   DAC_Debug_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DAC_Debug_DRIVE_MODE_BITS        (3)
#define DAC_Debug_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - DAC_Debug_DRIVE_MODE_BITS))
#define DAC_Debug_DRIVE_MODE_SHIFT       (0x00u)
#define DAC_Debug_DRIVE_MODE_MASK        (0x07u << DAC_Debug_DRIVE_MODE_SHIFT)

#define DAC_Debug_DM_ALG_HIZ         (0x00u << DAC_Debug_DRIVE_MODE_SHIFT)
#define DAC_Debug_DM_DIG_HIZ         (0x01u << DAC_Debug_DRIVE_MODE_SHIFT)
#define DAC_Debug_DM_RES_UP          (0x02u << DAC_Debug_DRIVE_MODE_SHIFT)
#define DAC_Debug_DM_RES_DWN         (0x03u << DAC_Debug_DRIVE_MODE_SHIFT)
#define DAC_Debug_DM_OD_LO           (0x04u << DAC_Debug_DRIVE_MODE_SHIFT)
#define DAC_Debug_DM_OD_HI           (0x05u << DAC_Debug_DRIVE_MODE_SHIFT)
#define DAC_Debug_DM_STRONG          (0x06u << DAC_Debug_DRIVE_MODE_SHIFT)
#define DAC_Debug_DM_RES_UPDWN       (0x07u << DAC_Debug_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define DAC_Debug_MASK               DAC_Debug__MASK
#define DAC_Debug_SHIFT              DAC_Debug__SHIFT
#define DAC_Debug_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DAC_Debug_PS                     (* (reg32 *) DAC_Debug__PS)
/* Port Configuration */
#define DAC_Debug_PC                     (* (reg32 *) DAC_Debug__PC)
/* Data Register */
#define DAC_Debug_DR                     (* (reg32 *) DAC_Debug__DR)
/* Input Buffer Disable Override */
#define DAC_Debug_INP_DIS                (* (reg32 *) DAC_Debug__PC2)


#if defined(DAC_Debug__INTSTAT)  /* Interrupt Registers */

    #define DAC_Debug_INTSTAT                (* (reg32 *) DAC_Debug__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins DAC_Debug_H */


/* [] END OF FILE */
