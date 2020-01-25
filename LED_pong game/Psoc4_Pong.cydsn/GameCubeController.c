#include "GameCubeController.h"
#include "stdio.h"
#include "stdint.h"

/*
*   Function: readController
*
*   Gets:
*   -(UINT8)controller: which controller has to be selected? one = controller one, all other: controller 2
*   -(UINT8)rumble    : enable vibrating of controller.  zero = off, all other: on
*
*   Returns: UINT64 with all buttons and joysticks
*
*   
*   ##MSB## (bit 60) START,Y,X,B,A,1,L,R,RL,D-UP,D-DOWN,D-RIGHT,D-LEFT,
*                    Joystick Xval(8bit), Joystick Yval(8bit), 
*                    C-Stick Xval(8bit), C-stick Yval(8-bit), 
*                    Left buttonval(8-bit), Right buttonval(8-bit) ##LSB##(bit 0)
*
*   Warning: -interrupts are disabled for most of the function
*            -Names of Input/output need to be Controller1 and Controller2, (input and output enabled)
*            -!!3.43V!!
*   Version: 2
*/
uint64 readController(uint8 controller, uint8 rumble) //controller 1 -> 1, anything else: 2 ; rumble: 0 -> off, 1 -> on
{
    //defines
    #define initNoRumble 0b0100000000000011000000001
    #define initRumble   0b0100000000000011000000010 //
    
    //vars
    uint32 sendingSequence;              //used to temp store init sequence and send
    _Bool readBuffer[61];                //buffer to store readings from controller
    uint64 formattedData;                //formatted data to return
    reg32 *controllerDR, *controllerPS, controllerSHIFT ,controllerMASK; //used to store mem location of controller data pins (you can change the pin later)
    int16 counter = 0;                   //declare before use (cycles)
    
    //perform checks for settings(controller/rumble)
    if(controller == 1)
    {
        controllerDR = &Controller1_DR;
        controllerPS = &Controller1_PS;
        controllerMASK = Controller1_MASK;
        controllerSHIFT = Controller1_SHIFT;
    }
    else
    {
        controllerDR = &Controller2_DR;
        controllerPS = &Controller2_PS;
        controllerMASK = Controller2_MASK;
        controllerSHIFT = Controller2_SHIFT;
    }
    
    if(rumble == 0)
    {
        sendingSequence = initNoRumble;
    }
    else
    {
        sendingSequence = initRumble;
    }
    
    //##time sensitive code##
    CyGlobalIntDisable;
    
    //This bit-bangs the 24 bits to the controller
    for(int i = 24; i >= 0; --i)
    {
        
        if(((sendingSequence >> i) & 0x000001)  == 0)   //ZERO sequence
        {
            *controllerDR &= ~controllerMASK;
            CyDelayCycles(50);
            *controllerDR |= controllerMASK;
            
            
        }
        else                                     //ONE sequence
        {
            *controllerDR &= ~controllerMASK;
            CyDelayCycles(1);
            *controllerDR |= controllerMASK;
            CyDelayCycles(39);
        }
    }
    
    //this reads the returned 60 bytes (only button data)


    CyDelayCycles(310);                          //sync to start bit 
    for(counter; counter <= 8; ++counter)
    {
        readBuffer[counter] = ((*controllerPS & controllerMASK) >> controllerSHIFT);
        CyDelayCycles(50);                       //sync to next bit
    }
    
    CyDelayCycles(5);                            //resync
    for(counter; counter <= 17; ++counter)
    {
        readBuffer[counter] = ((*controllerPS & controllerMASK) >> controllerSHIFT);
        CyDelayCycles(50);
    }
    
    CyDelayCycles(5);
    for(counter; counter <= 26; ++counter)
    {
        readBuffer[counter] = ((*controllerPS & controllerMASK) >> controllerSHIFT);
        CyDelayCycles(50);
    }
    
    CyDelayCycles(5);
    for(counter; counter <= 35; ++counter)
    {
        readBuffer[counter] = ((*controllerPS & controllerMASK) >> controllerSHIFT);
        CyDelayCycles(50);
    }
    
    CyDelayCycles(5);
    for(counter; counter <= 44; ++counter)
    {
        readBuffer[counter] = ((*controllerPS & controllerMASK) >> controllerSHIFT);
        CyDelayCycles(50);
    }
    
    CyDelayCycles(5);
    for(counter; counter <= 53; ++counter)
    {
        readBuffer[counter] = ((*controllerPS & controllerMASK) >> controllerSHIFT);
        CyDelayCycles(50);
    }
    
    CyDelayCycles(5);
    for(counter; counter <= 60; ++counter)
    {
        readBuffer[counter] = ((*controllerPS & controllerMASK) >> controllerSHIFT);
        CyDelayCycles(50);
    }


        
    //debug_DR |= debug_MASK;
    //debug_DR &= ~debug_MASK;
    //### end of time sensitive code###
    
    CyGlobalIntEnable;
    
    #ifdef debugging
    for(int i = 0; i <= 60; ++i)
    {
        if(readBuffer[i] == 0)
        {
            UART_UartPutString("0");
        }
        else
        {
            UART_UartPutString("1");
        }
        if(i == 8)
        {
           UART_UartPutString(" "); 
        }
        if(i == 12)
        {
           UART_UartPutString("-"); 
        }
        if(i == 17)
        {
           UART_UartPutString(" "); 
        }
        if(i == 26)
        {
           UART_UartPutString(" "); 
        }
        if(i == 35)
        {
           UART_UartPutString(" "); 
        }
        if(i == 44)
        {
           UART_UartPutString(" "); 
        }
        if(i == 53)
        {
           UART_UartPutString(" "); 
        }
    }
    UART_UartPutString("\r\n");
    #endif
    
    //formatting it to return
    for(int i = 0; i<=60; ++i)
    {
        if(readBuffer[i] == 1)
        {
            formattedData = ((formattedData <<1) | 0x0000000000000001);
        }
        else
        {
            formattedData = formattedData << 1;
        }
        
    }
    
    return formattedData;
}