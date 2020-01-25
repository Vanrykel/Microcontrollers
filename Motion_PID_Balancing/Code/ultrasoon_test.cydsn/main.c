/* ========================================
 *
 * Copyright Michiel Devue & Bram Willems, 2020
 * All Rights Reserved
 * Free to use for non commercial purposes
 * ========================================
*/
#include "project.h"
#include <stdio.h>

#define Kp 1 // factor voor error
#define Ki 0.1 // factor voor integraal
#define Kd 100 // factor voor derivaat



void pulse_ultrasoon();
int begrens(int onbegrensd, int onderwaarde, int bovenwaarde);
int berekenhoek(int error, int integraal, int derivaat, int hoek);
    uint8_t echo_flag = 0;  
    uint16_t echo_distance;  
    char serial_output[20];
    
CY_ISR( Timer_Int_Handler ) {  
    // read centimeters  
    echo_distance = timer_echo_ReadCapture();  
    echo_flag = 1;  
  
  
    timer_echo_ClearInterrupt ( timer_echo_INTR_MASK_CC_MATCH );  
}  

int main(void)
{
      
    CyGlobalIntEnable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_1_Start();
    UART_Start();
    timer_echo_Start();
    PWM_servo_Start();
    ADC_Start();
    
    int error;
    int proces;
    long integraal;
    long derivaat;
    int teller;
    int pot;
    int inballans = 0;
    int previous;
    // Registration of Timer ISR  
    Timer_echo_int_StartEx(Timer_Int_Handler); 
    proces = 0;
    integraal = 22000;
    
    for(;;)
    {
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        pot = ADC_GetResult16(0);
        
       while(echo_flag == 1){
              
  
  
            CyGlobalIntDisable; /* Disable global interrupts, so the flag gets cleared. */  
            echo_flag = 0;  
            CyGlobalIntEnable; /* Enable global interrupts after the flag is cleared. */  
            int hoek;
        	int setpoint;
        	int vorige_error;

//            if (echo_distance>10000){
//                proces = 0 ;
//                integraal = 0;
//            };
//            if (echo_distance<2000){
                if (((echo_distance < (proces+300)) && (echo_distance > (proces-300)) && (echo_distance<2000)) || proces == 0){
                    proces=echo_distance;
                    teller = 0;
                }
                else{
                    teller = teller + 1;
                    if (teller == 10){
                        proces=echo_distance;
                        teller = 0;
                    }
                };
//            };

           
            
            sprintf(serial_output, "Fout:%d  Meet:%d  Proces:%d  Setp:%d  Der:%ld  Int:%ld", teller, (echo_distance/50), (proces/50), (setpoint/50), derivaat,  integraal);
            
            if((setpoint/50)>(echo_distance/50)-1 || (setpoint/50)<(echo_distance/50)+1){
                inballans += 1;
            }else{
                inballans = 0;
            }
            if(inballans >= 50){
                CySysPmSleep();
            }
            UART_UartPutString(serial_output);  
            UART_UartPutCRLF(0U);
            
            CyGlobalIntDisable; /* Disable global interrupts, so the flag gets cleared. */  
            echo_flag = 0;  
            CyGlobalIntEnable; /* Enable global interrupts after the flag is cleared. */ 
            
            hoek=0;
        	vorige_error = error;
            
            // zorg dat setpoint stabiel is
            setpoint = (((pot/6)+10)*50);
            if (((setpoint/50) > (previous/50)+2) || ((setpoint/50) < (previous/50)-2)) {
                previous = setpoint;
            }
            else {
                setpoint = previous;    
            };
            
            // bereken de huidige aftand tussen bal en gewenst punt
            error = (setpoint - proces)/100;
            
            // bereken de integraal
            integraal = integraal + error;
 
            // bereken de derivaat
            derivaat = error - vorige_error;
            
            // bereken waarde voor potmeter
            hoek = berekenhoek(error, integraal, derivaat, hoek);
            
            // zet hoek op pwm
            PWM_servo_WriteCompare(hoek);
        }
    }
}
int begrens(int onbegrensd, int onderwaarde, int bovenwaarde){
    if (onbegrensd < onderwaarde)
        onbegrensd = onderwaarde;
	else if (onbegrensd > bovenwaarde)
        onbegrensd = bovenwaarde;
	return onbegrensd;
}
int berekenhoek(int error, int integraal, int derivaat, int hoek){
    hoek = (Kp * error) + ((Ki * integraal)/50) + (Kd * derivaat); //
	hoek = 230 - hoek;
	hoek=begrens(hoek, 170, 190);
	return hoek;
}

/* [] END OF FILE */
