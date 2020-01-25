#include "project.h"
#include "stdio.h"

static int temperature;
static int humidity;
char temp[16];
uint16 proxCounter = 1;
uint16 gasValue = 0;
uint8 proximityValue;
uint8 flameValue;
float gasVolt;

int DHT_read()
{
    uint8 IState;
    IState = CyEnterCriticalSection();
    uint8 bits[5];
        uint8 cnt = 7;
        uint8 idx = 0;
    int calc = 0;
    int timeout = 0;
    for (int i = 0; i < 5; i++ )
        bits[i] = 0;    
    DHT11_Write(0u);
    CyDelay(19);
    DHT11_Write(1u);
    while (DHT11_Read() == 1)
    {
        timeout++;
        if (timeout > 500)
            goto r99;                   //DHT error function
    }
    while(DHT11_Read() == 0) 
    {         
        timeout++; 
        if(timeout > 500)
            goto r99;                   //DHT error function
    } 
    calc = timeout; 
    timeout = 0; 
    while(DHT11_Read() == 1); 
    for (int i = 0; i < 40; i++) 
    { 
        timeout = 0; 
        while(DHT11_Read() == 0); 
        while(DHT11_Read() == 1) 
            timeout++;
        //Data acquiring point
        if ((timeout) > (calc / 2))
            bits[idx] |= (1 << cnt);
        if (cnt == 0)                   //next byte?
        {
   		    cnt = 7;                    // restart at MSB
   		    idx++;                      //next byte!
   	    } 
        else
        {
            cnt--;
        }
   } 
   humidity = bits[0];  
   temperature = bits[2];  
   CyExitCriticalSection(IState); 
   CyDelay(1); 
   return 0; 
   r99:                                 //Goto label for error in DHT reading
       humidity    = 0;  
       temperature = 0;  
       CyExitCriticalSection(IState); 
       return 99; 
}

//Function to make the buzzer beep
void Beep(uint16 time)
{
    PWM_Start();
    CyDelay(time);
    PWM_Stop();
}

void WriteLCD(char stat)
{
    switch (stat)
    {
        //Print temperature, humidity, gasvalue and proximity value on screen
        case 'p':
            LCD_ClearDisplay();
            LCD_Position(0u , 0u);
            sprintf(temp, "Temp: %d", temperature);
            LCD_PrintString(temp);
            LCD_WriteData(223);
            LCD_WriteData('C');     
            LCD_Position(1u , 0u);
            sprintf(temp, "Hum: %d", humidity);
            LCD_PrintString(temp);
            LCD_WriteData(37);
            CyDelay(2000);
    
            LCD_ClearDisplay();
            LCD_Position(0u , 0u);
            sprintf(temp, "Gas: %d", gasValue);
            LCD_PrintString(temp);
            LCD_Position(1u , 0u);
            sprintf(temp, "Prox: %d", proximityValue);
            LCD_PrintString(temp);
            CyDelay(2000);
            break;
        //Print fire warning on screen
        case 'f':
            LCD_ClearDisplay();
            LCD_Position(0u , 0u);
            LCD_PrintString("WARNING");
            LCD_Position(1u , 0u);
            LCD_WriteData(33);
            LCD_PrintString(" FIRE ");
            LCD_WriteData(33);
            CyDelay(100);
            break;
         case 'w':
            LCD_ClearDisplay();
            LCD_Position(0u , 0u);
            LCD_PrintString("WARNING");
            LCD_Position(1u , 0u);
            LCD_WriteData(33);
            LCD_PrintString(" HIGH CO2 ");
            LCD_WriteData(33);
            CyDelay(100);
            break;           
        case 'c':
            LCD_ClearDisplay();
            LCD_Position(0u , 0u);
            LCD_PrintString("WARNING");
            sprintf(temp, "%d", gasValue);
            LCD_Position(0u , 9u);
            LCD_PrintString(temp);
            LCD_Position(1u , 0u);
            LCD_WriteData(33);
            LCD_PrintString(" GAS ");
            LCD_WriteData(33);
            CyDelay(100);
            break;
        default:
            LCD_ClearDisplay();
            LCD_Position(0u , 0u);
            LCD_PrintString("PSoC 042 BLE");
            CyDelay(1000);
            break;
    }
}

void WriteLED(char stat) {
        //Write status LED
        switch(stat)
        {
            case 'n':
                RED_Write(1);
                GREEN_Write(0);
                BLUE_Write(1);
                break;
            case 'c':
                RED_Write(0);
                GREEN_Write(1);
                BLUE_Write(1);
                break;
            case 'w':
                RED_Write(0);
                GREEN_Write(0);
                BLUE_Write(1);
                break;
            case 'b':
                RED_Write(1);
                GREEN_Write(1);
                BLUE_Write(0);
                break;
            default:
                RED_Write(0);
                GREEN_Write(0);
                BLUE_Write(0);
                break;
        }   
}

int main(void)
{
    char ledStat;
    char lcdStat;
    //Initialize
    CyGlobalIntEnable;
    LCD_Start();
    ADC_Start();
    ADC_StartConvert();
    /* Enable the proximity widget explicitly and start CapSense component. 
	* Initialization of the baseline is done when the first connection 
	* happens  */
    CapSense_EnableWidget(CapSense_PROXIMITYSENSOR0__PROX);
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    
    for(;;)
    {
        //Calculate temperature and humidity
        DHT_read();
        ledStat = 'n';
        lcdStat = 'p';
        
        //Read proximity value
        //Check if proxCounter has reached its counting value
        if(0 == (--proxCounter))
        {
            //Set 'proxCounter' to the PROX_COUNTER_VALUE. This counter prevents sending 
		    //of large number of CapSense proximity data to BLE Central device
            proxCounter = 5;
            //Scan the Proximity Widget
            CapSense_ScanWidget(CapSense_PROXIMITYSENSOR0__PROX);
            //Wait for CapSense scanning to be complete. This could take about 5 ms
            while (CapSense_IsBusy())
            {
            }
            //Update CapSense Baseline
            CapSense_UpdateEnabledBaselines();
            //Get the Diffcount between proximity raw data and baseline
            proximityValue = CapSense_GetDiffCountData(CapSense_PROXIMITYSENSOR0__PROX);
        }        
        
        //Read gasValue
        if (ADC_IsEndConversion(ADC_RETURN_STATUS))
        {
            gasValue = ADC_GetResult16(0);
        } 
        
        //Read flame and light sensor value
        flameValue = flame_sensor_Read();
        if (flameValue == 0) {
            Beep(200);
            ledStat = 'c';
            lcdStat = 'f';
        } else if (gasValue > 1400) {
            Beep(200);
            ledStat = 'c';
            lcdStat = 'c';
        } else if (gasValue > 1200 && gasValue < 1400) {
            ledStat = 'w';
            lcdStat = 'w';   
        }
        
        //Turn on light LCD
        if (proximityValue > 5) {
            LCD_trans_1_Write(1);
            LCD_trans_2_Write(1);
            WriteLCD(lcdStat);
        } else {
            LCD_trans_1_Write(0);
            LCD_trans_2_Write(0);
        }
        WriteLED(ledStat);
        CyDelay(500);
    }
}