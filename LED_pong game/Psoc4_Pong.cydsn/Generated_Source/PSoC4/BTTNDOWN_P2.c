/*******************************************************************************
* File Name: BTTNDOWN_P2.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <BTTNDOWN_P2.h>
#include "cyapicallbacks.h"

#if !defined(BTTNDOWN_P2__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START BTTNDOWN_P2_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: BTTNDOWN_P2_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void BTTNDOWN_P2_Start(void)
{
    /* For all we know the interrupt is active. */
    BTTNDOWN_P2_Disable();

    /* Set the ISR to point to the BTTNDOWN_P2 Interrupt. */
    BTTNDOWN_P2_SetVector(&BTTNDOWN_P2_Interrupt);

    /* Set the priority. */
    BTTNDOWN_P2_SetPriority((uint8)BTTNDOWN_P2_INTC_PRIOR_NUMBER);

    /* Enable it. */
    BTTNDOWN_P2_Enable();
}


/*******************************************************************************
* Function Name: BTTNDOWN_P2_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void BTTNDOWN_P2_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    BTTNDOWN_P2_Disable();

    /* Set the ISR to point to the BTTNDOWN_P2 Interrupt. */
    BTTNDOWN_P2_SetVector(address);

    /* Set the priority. */
    BTTNDOWN_P2_SetPriority((uint8)BTTNDOWN_P2_INTC_PRIOR_NUMBER);

    /* Enable it. */
    BTTNDOWN_P2_Enable();
}


/*******************************************************************************
* Function Name: BTTNDOWN_P2_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void BTTNDOWN_P2_Stop(void)
{
    /* Disable this interrupt. */
    BTTNDOWN_P2_Disable();

    /* Set the ISR to point to the passive one. */
    BTTNDOWN_P2_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: BTTNDOWN_P2_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for BTTNDOWN_P2.
*
*   Add custom code between the START and END comments to keep the next version
*   of this file from over-writing your code.
*
*   Note You may use either the default ISR by using this API, or you may define
*   your own separate ISR through ISR_StartEx().
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(BTTNDOWN_P2_Interrupt)
{
    #ifdef BTTNDOWN_P2_INTERRUPT_INTERRUPT_CALLBACK
        BTTNDOWN_P2_Interrupt_InterruptCallback();
    #endif /* BTTNDOWN_P2_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START BTTNDOWN_P2_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: BTTNDOWN_P2_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling BTTNDOWN_P2_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use BTTNDOWN_P2_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void BTTNDOWN_P2_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + BTTNDOWN_P2__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: BTTNDOWN_P2_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress BTTNDOWN_P2_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + BTTNDOWN_P2__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: BTTNDOWN_P2_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling BTTNDOWN_P2_Start or BTTNDOWN_P2_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after BTTNDOWN_P2_Start or BTTNDOWN_P2_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void BTTNDOWN_P2_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((BTTNDOWN_P2__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *BTTNDOWN_P2_INTC_PRIOR = (*BTTNDOWN_P2_INTC_PRIOR & (uint32)(~BTTNDOWN_P2__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: BTTNDOWN_P2_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 BTTNDOWN_P2_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((BTTNDOWN_P2__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*BTTNDOWN_P2_INTC_PRIOR & BTTNDOWN_P2__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: BTTNDOWN_P2_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void BTTNDOWN_P2_Enable(void)
{
    /* Enable the general interrupt. */
    *BTTNDOWN_P2_INTC_SET_EN = BTTNDOWN_P2__INTC_MASK;
}


/*******************************************************************************
* Function Name: BTTNDOWN_P2_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 BTTNDOWN_P2_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*BTTNDOWN_P2_INTC_SET_EN & (uint32)BTTNDOWN_P2__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: BTTNDOWN_P2_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void BTTNDOWN_P2_Disable(void)
{
    /* Disable the general interrupt. */
    *BTTNDOWN_P2_INTC_CLR_EN = BTTNDOWN_P2__INTC_MASK;
}


/*******************************************************************************
* Function Name: BTTNDOWN_P2_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void BTTNDOWN_P2_SetPending(void)
{
    *BTTNDOWN_P2_INTC_SET_PD = BTTNDOWN_P2__INTC_MASK;
}


/*******************************************************************************
* Function Name: BTTNDOWN_P2_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void BTTNDOWN_P2_ClearPending(void)
{
    *BTTNDOWN_P2_INTC_CLR_PD = BTTNDOWN_P2__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */