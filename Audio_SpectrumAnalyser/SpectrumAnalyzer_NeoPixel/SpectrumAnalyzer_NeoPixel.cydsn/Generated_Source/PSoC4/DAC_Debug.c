/*******************************************************************************
* File Name: DAC_Debug.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "DAC_Debug.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        DAC_Debug_PC =   (DAC_Debug_PC & \
                                (uint32)(~(uint32)(DAC_Debug_DRIVE_MODE_IND_MASK << (DAC_Debug_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (DAC_Debug_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: DAC_Debug_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void DAC_Debug_Write(uint8 value) 
{
    uint8 drVal = (uint8)(DAC_Debug_DR & (uint8)(~DAC_Debug_MASK));
    drVal = (drVal | ((uint8)(value << DAC_Debug_SHIFT) & DAC_Debug_MASK));
    DAC_Debug_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: DAC_Debug_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void DAC_Debug_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(DAC_Debug__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: DAC_Debug_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro DAC_Debug_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 DAC_Debug_Read(void) 
{
    return (uint8)((DAC_Debug_PS & DAC_Debug_MASK) >> DAC_Debug_SHIFT);
}


/*******************************************************************************
* Function Name: DAC_Debug_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 DAC_Debug_ReadDataReg(void) 
{
    return (uint8)((DAC_Debug_DR & DAC_Debug_MASK) >> DAC_Debug_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(DAC_Debug_INTSTAT) 

    /*******************************************************************************
    * Function Name: DAC_Debug_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 DAC_Debug_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(DAC_Debug_INTSTAT & DAC_Debug_MASK);
		DAC_Debug_INTSTAT = maskedStatus;
        return maskedStatus >> DAC_Debug_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */