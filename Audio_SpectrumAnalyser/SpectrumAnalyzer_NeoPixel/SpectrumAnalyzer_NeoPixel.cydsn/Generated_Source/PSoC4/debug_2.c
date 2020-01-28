/*******************************************************************************
* File Name: debug_2.c  
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
#include "debug_2.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        debug_2_PC =   (debug_2_PC & \
                                (uint32)(~(uint32)(debug_2_DRIVE_MODE_IND_MASK << (debug_2_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (debug_2_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: debug_2_Write
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
void debug_2_Write(uint8 value) 
{
    uint8 drVal = (uint8)(debug_2_DR & (uint8)(~debug_2_MASK));
    drVal = (drVal | ((uint8)(value << debug_2_SHIFT) & debug_2_MASK));
    debug_2_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: debug_2_SetDriveMode
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
void debug_2_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(debug_2__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: debug_2_Read
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
*  Macro debug_2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 debug_2_Read(void) 
{
    return (uint8)((debug_2_PS & debug_2_MASK) >> debug_2_SHIFT);
}


/*******************************************************************************
* Function Name: debug_2_ReadDataReg
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
uint8 debug_2_ReadDataReg(void) 
{
    return (uint8)((debug_2_DR & debug_2_MASK) >> debug_2_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(debug_2_INTSTAT) 

    /*******************************************************************************
    * Function Name: debug_2_ClearInterrupt
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
    uint8 debug_2_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(debug_2_INTSTAT & debug_2_MASK);
		debug_2_INTSTAT = maskedStatus;
        return maskedStatus >> debug_2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
