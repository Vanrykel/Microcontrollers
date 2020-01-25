/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>
#define B 0x0u

uint8 flag = 0;
uint16_t dist;
char8 sout[20];

CY_ISR(intr_handler)
{
    dist = Timer_2_ReadCapture();
    flag = 1;
    
    Timer_2_SetCaptureCount(0);
    
    
}
int main(void)
{
    
    PWM_2_Start();
    Timer_2_Start();
    UART_2_Start();
    CyGlobalIntEnable; /* Enable global interrupts. */

    UltraSone_1_Echo_intr_StartEx(intr_handler);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    if(flag == 1)
    {
         sprintf(sout,"%u cm",dist);
         UART_2_PutString(sout);
         UART_2_PutCRLF(B);
         CyGlobalIntDisable
         flag = 0;
         CyGlobalIntEnable
    }
    
    for(;;)
    {
        
    }
}

/* [] END OF FILE */
