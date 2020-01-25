#include <project.h>

int16 i =0;
int distance = 0;
int speed = 0; //Speed from the cart from 0 to 100
void fullstop();
void safetyslowdown();



CY_ISR(Timer_ISR_handler)
{
    
    Timer_ClearInterrupt(Timer_INTR_MASK_CC_MATCH);
    i= Timer_ReadCounter();    
    // from HC 04 Ultra Sonic module's datasheet, each 58 uS = 1 cm
    
    distance =i/58;
    // please note that measured distance above 400 cm is not reliable
    Trigger_Write(1);
    CyDelayUs(10);
    // for 10 uS
    Trigger_Write(0);

    

}


int main(void)
{
// Start Timer
    Timer_Start();
// Enable Global Interrupt and start ISR  
    CyGlobalIntEnable; 
    ISR_StartEx(Timer_ISR_handler);
   

             
    for(;;)
    {
        // Triggers the Ultra Sonic Sensor 
        Trigger_Write(1);    
        CyDelayUs(10);
        // for 10 uS
        Trigger_Write(0);
        
        fullstop();
        safetyslowdown();
    }
    
}

void fullstop() // brings the cart to a full stop when it reaches within 30cm
{
    if ( distance == 30 )
    {
          speed = 0;  
    }
}

void safetyslowdown() // reduce the cart his speed when it comes within a meter. 
{
    int tempDistance = speed % 2;
    if (distance == 100)
    {
        for(int i = 0; i < tempDistance ; i++)
        {
            speed--;
        }
    }
}    
        

