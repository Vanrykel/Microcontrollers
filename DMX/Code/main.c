#include "project.h"

//Dmx limit (512 max. =513 / 1 min. =2)
uint16 DMXdata[513];
//update count to number of dmx data channels
uint16 count = 33;

int main(void)
{
    CyGlobalIntEnable; 
    //clear array
    for(int i = 0; i < count;i++)
    {
        DMXdata[i] = 0;
    }
    
    //first data is always 0!
    DMXdata[0]=0;
    
    //programmable data
    DMXdata[1]=0;
    DMXdata[2]=0;
    DMXdata[3]=0;
    DMXdata[4]=0;
    
    /*
    DMXdata[0]=0b00000000;
    DMXdata[1]=0b01100000;
    DMXdata[2]=0b00001101;
    DMXdata[3]=0b11111111;
    DMXdata[4]=0b10000000;
    DMXdata[5]=0b00110000;
    DMXdata[6]=0b00000110;
    DMXdata[7]=0b00000000;
    DMXdata[8]=0b11000000;
    DMXdata[8]=0b00110000;
    */
    
    //...    
    
    for(;;)
    {
        //End/Start of data
        SPI_Stop();      
        Pin_1_SetDriveMode(Pin_1_DM_RES_UP);
        CyDelayUs(7500);
        SPI_Start();   
        SPI_SpiUartWriteTxData(0);
        //CyDelayUs(160);
        
        
        SPI_SpiUartWriteTxData(0b0000000000000000);
        SPI_SpiUartWriteTxData(0b0000000000001111);
        for(int i = 0;i<33;i++)
        {
            uint16 temp = 0b0000000000000000;
            temp = temp^0b0001111000000000;
            temp = temp^DMXdata[i];
            //temp = temp<<4;
            
            SPI_SpiUartWriteTxData(temp);
            
            
        }
        //data write-time
        CyDelayUs((count*10)-4); 
    }
 
}