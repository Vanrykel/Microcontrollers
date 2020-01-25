#include "project.h"
#include <stdio.h>
#define ALERT 0u

uint8_t echo_flag = 0;
uint16_t dist;
char sout[5];

CY_ISR(UltraSone_1_Echo_intr_handler)
{
    dist = (Timer_1_ReadCapture()*0.0343)/2;
    echo_flag = 1;
   
    Timer_1_ClearInterrupt( Timer_1_INTR_MASK_CC_MATCH );
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_1_Start();

    Timer_1_Start();
    
    
    UltraSone_1_Echo_intr_StartEx(UltraSone_1_Echo_intr_handler);
  

    for(;;)
    {
        
        while(echo_flag == 1 && dist <= 255)
        {
            //UART_1_UartPostEnable();
            sprintf(sout,"%d",dist);
            UART_1_UartPutString(sout);
            //UART_1_tx_Write(*sout);
            //UART_1_UartPutChar(sout);
            //UART_1_UartPutCRLF(0u);
      
        
            CyGlobalIntDisable;
            echo_flag = 0;
            CyGlobalIntEnable;
        
           } 
    }
}

/* [] END OF FILE */
