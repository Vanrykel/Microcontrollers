
#include "project.h"
int loc = 0;
CY_ISR(speedLeftFunc)
{
        loc++;
}
CY_ISR(speedRightFunc)
{
        loc--;   
}


int main(void)
{
    CyGlobalIntEnable; 
    isr_1_StartEx(speedLeftFunc);
    isr_2_StartEx(speedRightFunc);
    
    for(;;)
    {
        if(loc < 0)
        {
            ledRight_Write(0);
            ledLeft_Write(1);
            ledForward_Write(1);
        }
        else if(loc > 0)
        {
            ledLeft_Write(0);
            ledRight_Write(1);
            ledForward_Write(1);
        }
        else if(loc == 0 )
        {
            ledForward_Write(0);
            ledRight_Write(1);
            ledLeft_Write(1);
        }
    }
}
//{}

