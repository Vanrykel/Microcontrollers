/*******************************************************************************
* File Name: ADC_SAR_INT.c
* Version 2.50
*
*  Description:
*    This file contains the code that operates during the ADC_SAR interrupt
*    service routine.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_SAR.h"



/******************************************************************************
* Custom Declarations and Variables
* - add user inlcude files, prototypes and variables between the following
*   #START and #END tags
******************************************************************************/
/* `#START ADC_SYS_VAR`  */

/* Filter coefficients */
/* Q = 6 coefficients*/
#define FILTER_63Hz_in0 113
#define FILTER_63Hz_in2 -113
#define FILTER_63Hz_out1 32744
#define FILTER_63Hz_out2 -16361

//#define FILTER_160Hz_in0 285
//#define FILTER_160Hz_in2 -285
//#define FILTER_160Hz_out1 32704
//#define FILTER_160Hz_out2 -16327
//
//#define FILTER_400Hz_in0 711
//#define FILTER_400Hz_in2 -711
//#define FILTER_400Hz_out1 32581
//#define FILTER_400Hz_out2 -16242
//
//#define FILTER_1000Hz_in0 1760
//#define FILTER_1000Hz_in2 -1760
//#define FILTER_1000Hz_out1 32139
//#define FILTER_1000Hz_out2 -16032
//
//#define FILTER_2500Hz_in0 4239
//#define FILTER_2500Hz_in2 -4239
//#define FILTER_2500Hz_out1 30256
//#define FILTER_2500Hz_out2 -15536
//
//#define FILTER_6250Hz_in0 9041
//#define FILTER_6250Hz_in2 -9041
//#define FILTER_6250Hz_out1 22084
//#define FILTER_6250Hz_out2 -14576
//
//#define FILTER_16000Hz_in0 12591
//#define FILTER_16000Hz_in2 -12591
//#define FILTER_16000Hz_out1 -1394
//#define FILTER_16000Hz_out2 -13866

/* Q = 8 Coefficients */
//#define FILTER_63Hz_in0 84
//#define FILTER_63Hzxn_1 0
//#define FILTER_63Hz_in2 -84
//#define FILTER_63Hz_out1 32750
//#define FILTER_63Hz_out2 -16367


#define FILTER_160Hz_in0 214
#define FILTER_160Hzxn_1 0
#define FILTER_160Hz_in2 -214
#define FILTER_160Hz_out1 32718
#define FILTER_160Hz_out2 -16341

#define FILTER_400Hz_in0 534
#define FILTER_400Hzxn_1 0
#define FILTER_400Hz_in2 -534
#define FILTER_400Hz_out1 32616
#define FILTER_400Hz_out2 -16277

#define FILTER_1000Hz_in0 1324
#define FILTER_1000Hzxn_1 0
#define FILTER_1000Hz_in2 -1324
#define FILTER_1000Hz_out1 32226
#define FILTER_1000Hz_out2 -16119

#define FILTER_2500Hz_in0 3200
#define FILTER_2500Hzxn_1 0
#define FILTER_2500Hz_in2 -3200
#define FILTER_2500Hz_out1 30453
#define FILTER_2500Hz_out2 -15744

#define FILTER_4000Hz_in0 4869
#define FILTER_4000Hzxn_1 0
#define FILTER_4000Hz_in2 -4869
#define FILTER_4000Hz_out1 27716
#define FILTER_4000Hz_out2 -15410

#define FILTER_6250Hz_in0 6876
#define FILTER_6250Hzxn_1 0
#define FILTER_6250Hz_in2 -6876
#define FILTER_6250Hz_out1 22393
#define FILTER_6250Hz_out2 -15009

#define FILTER_16000Hz_in0 9628 * 5
#define FILTER_16000Hzxn_1 0
#define FILTER_16000Hz_in2 -9628 * 5
#define FILTER_16000Hz_out1 -1421
#define FILTER_16000Hz_out2 -14458


#define PEAKSHIFT 7
#define PEAKSHIFT_63Hz 6
#define PEAKDEADZONE 5
#define UPDATECOUNT 1800

/* Bit shift for Fixed point */
#define BITSHIFT 14
#include "project.h"

	uint32 count;

	int16 Filter_in;
	int16 Filter_in_1;
	int16 Filter_in_2;
	
	/* Filter 1 - 63Hz */
	int32 Filt_1_Out;
	int32 Filt_1_Out_1, Filt_1_Out_2;
	
	uint32 Filt_1_rms, Filt_2_rms, Filt_3_rms, Filt_4_rms, Filt_5_rms, Filt_6_rms, Filt_7_rms, Filt_8_rms;
	uint32 Filt_1_peak, Filt_2_peak, Filt_3_peak, Filt_4_peak, Filt_5_peak, Filt_6_peak, Filt_7_peak, Filt_8_peak;
	uint32 Filt_1_peak_1, Filt_2_peak_1, Filt_3_peak_1, Filt_4_peak_1, Filt_5_peak_1, Filt_6_peak_1, Filt_7_peak_1, Filter_8_peak_1;


	/* Filter 2 - 160Hz */
	int32 Filt_2_Out;
	int32 Filt_2_Out_1, Filt_2_Out_2;
	
	
	/* Filter 3 - 400Hz */
	int32 Filt_3_Out;
	int32 Filt_3_Out_1, Filt_3_Out_2;
	
	/* Filter 4 - 1000Hz */
	int32 Filt_4_Out;
	int32 Filt_4_Out_1, Filt_4_Out_2;
	
	/* Filter 5 - 2500Hz */
	int32 Filt_5_Out;
	int32 Filt_5_Out_1, Filt_5_Out_2;
	
	/* Filter 6 - 4000Hz */
	int32 Filt_6_Out;
	int32 Filt_6_Out_1, Filt_6_Out_2;
	
	/* Filter 7 - 6250Hz */
	int32 Filt_7_Out;
	int32 Filt_7_Out_1, Filt_7_Out_2;

	/* Filter 8 - 16000Hz */
	int32 Filt_8_Out;
	int32 Filt_8_Out_1, Filt_8_Out_2;


	extern void WritetoLED(uint8 row, uint8 value);

/* `#END`  */

#if(ADC_SAR_IRQ_REMOVE == 0u)


    /******************************************************************************
    * Function Name: ADC_SAR_ISR
    *******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  No.
    *
    ******************************************************************************/
    CY_ISR( ADC_SAR_ISR )
    {
        uint32 intr_status;

        /* Read interrupt status register */
        intr_status = ADC_SAR_SAR_INTR_REG;

        #ifdef ADC_SAR_ISR_INTERRUPT_CALLBACK
            ADC_SAR_ISR_InterruptCallback();
        #endif /* ADC_SAR_ISR_INTERRUPT_CALLBACK */


        /************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        *************************************************************************/
        /* `#START MAIN_ADC_ISR`  */
			Filter_in = ADC_SAR_GetResult16(0);
			Filter_in = Filter_in << 4;
			
			Filt_1_Out = (Filter_in * FILTER_63Hz_in0 + Filter_in_2 * FILTER_63Hz_in2 + Filt_1_Out_1 * FILTER_63Hz_out1 + Filt_1_Out_2 * FILTER_63Hz_out2) >> BITSHIFT;

			Filt_2_Out = (Filter_in * FILTER_160Hz_in0 + Filter_in_2 * FILTER_160Hz_in2 + Filt_2_Out_1 * FILTER_160Hz_out1 + Filt_2_Out_2 * FILTER_160Hz_out2) >> BITSHIFT;

			Filt_3_Out = (Filter_in * FILTER_400Hz_in0 + Filter_in_2 * FILTER_400Hz_in2 + Filt_3_Out_1 * FILTER_400Hz_out1 + Filt_3_Out_2 * FILTER_400Hz_out2) >> BITSHIFT;

			Filt_4_Out = (Filter_in * FILTER_1000Hz_in0 + Filter_in_2 * FILTER_1000Hz_in2 + Filt_4_Out_1 * FILTER_1000Hz_out1 + Filt_4_Out_2 * FILTER_1000Hz_out2) >> BITSHIFT;

			Filt_5_Out = (Filter_in * FILTER_2500Hz_in0 + Filter_in_2 * FILTER_2500Hz_in2 + Filt_5_Out_1 * FILTER_2500Hz_out1 + Filt_5_Out_2 * FILTER_2500Hz_out2) >> BITSHIFT;
			
			Filt_6_Out = (Filter_in * FILTER_4000Hz_in0 + Filter_in_2 * FILTER_4000Hz_in2 + Filt_6_Out_1 * FILTER_4000Hz_out1 + Filt_6_Out_2 * FILTER_4000Hz_out2) >> BITSHIFT;

			Filt_7_Out = (Filter_in * FILTER_6250Hz_in0 + Filter_in_2 * FILTER_6250Hz_in2 + Filt_7_Out_1 * FILTER_6250Hz_out1 + Filt_7_Out_2 * FILTER_6250Hz_out2) >> BITSHIFT;

			Filt_8_Out = (Filter_in * FILTER_16000Hz_in0 + Filter_in_2 * FILTER_16000Hz_in2 + Filt_8_Out_1 * FILTER_16000Hz_out1 + Filt_8_Out_2 * FILTER_16000Hz_out2) >> BITSHIFT;
			

			/* Peak Detection */
			if(Filt_1_Out > (int32) Filt_1_peak)
			{
				Filt_1_rms = Filt_1_Out;
				Filt_1_peak = Filt_1_Out;
			}
			
			/*Filt 2*/
			if(Filt_2_Out > (int32) Filt_2_peak)
			{
				Filt_2_rms = Filt_2_Out;
				Filt_2_peak = Filt_2_Out;
			}

			/*Filt 3*/
			if(Filt_3_Out > (int32) Filt_3_peak)
			{
				Filt_3_rms = Filt_3_Out;
				Filt_3_peak = Filt_3_Out;
			}
			
			/*Filt 4*/
			if(Filt_4_Out > (int32) Filt_4_peak)
			{
				Filt_4_rms = Filt_4_Out;
				Filt_4_peak = Filt_4_Out;
			}

			/*Filt 5*/
			if(Filt_5_Out > (int32) Filt_5_peak)
			{
				Filt_5_rms = Filt_5_Out;
				Filt_5_peak = Filt_5_Out;
			}

			/*Filt 6*/
			if(Filt_6_Out > (int32) Filt_6_peak)
			{
				Filt_6_rms = Filt_6_Out;
				Filt_6_peak = Filt_6_Out;
			}

			/*Filt 7*/
			if(Filt_7_Out > (int32) Filt_7_peak)
			{
				Filt_7_rms = Filt_7_Out;
				Filt_7_peak = Filt_7_Out;
			}

			/*Filt 8*/
			if(Filt_8_Out > (int32) Filt_8_peak)
			{
				Filt_8_rms = Filt_8_Out;
				Filt_8_peak = Filt_8_Out;
			}
			/* Reset Peak detector and 								  		*/
			/* update the frequency components once every 900 counts */
			if(count==UPDATECOUNT)
			{
				/* Check if peak is greater than deadzone to avoid false positives */
				if((Filt_8_rms>>PEAKSHIFT) > PEAKDEADZONE)
				{
					WritetoLED(0, (uint8) (Filt_8_rms>>PEAKSHIFT));
				}
				else
				{
					WritetoLED(0, 0);
				}
				
				/* Reset Peak detector */
				Filt_8_peak = 0;
				Filt_8_rms = 0;
				
				
				if((Filt_7_rms>>PEAKSHIFT) > PEAKDEADZONE)
				{
					WritetoLED(1, (uint8) (Filt_7_rms>>PEAKSHIFT));
				}
				else
				{
					WritetoLED(1, 0);
				}
				
				/* Reset Peak detector */
				Filt_7_peak = 0;
				Filt_7_rms = 0;
				
				/* Check if peak is greater than deadzone to avoid false positives */
				if((Filt_6_rms>>PEAKSHIFT) > PEAKDEADZONE)
				{
					WritetoLED(2, (uint8) (Filt_6_rms>>PEAKSHIFT));
				}
				else
				{
					WritetoLED(2, 0);
				}
				
				/* Reset Peak detector */
				Filt_6_peak = 0;
				Filt_6_rms = 0;
				
				if((Filt_5_rms>>PEAKSHIFT) > PEAKDEADZONE)
				{
					WritetoLED(3, (uint8) (Filt_5_rms>>PEAKSHIFT));
				}
				else
				{
					WritetoLED(3, 0);
				}
				
				/* Reset Peak detector */
				Filt_5_peak = 0;
				Filt_5_rms = 0;
			
			
				if((Filt_4_rms>>PEAKSHIFT) > PEAKDEADZONE)
				{
					WritetoLED(4, (uint8) (Filt_4_rms>>PEAKSHIFT));
				}
				else
				{
					WritetoLED(4, 0);
				}
				
				/* Reset Peak detector */
				Filt_4_peak = 0;
				Filt_4_rms = 0;
			
			
				if((Filt_3_rms>>PEAKSHIFT) > PEAKDEADZONE)
				{
					WritetoLED(5, (uint8) (Filt_3_rms>>PEAKSHIFT));
				}
				else
				{
					WritetoLED(5, 0);
				}
				
				/* Reset Peak detector */

				Filt_3_peak = 0;
				Filt_3_rms = 0;

				WritetoLED(6, (uint8) (Filt_2_rms>>PEAKSHIFT));
				WritetoLED(7, (uint8) (Filt_1_rms>>PEAKSHIFT_63Hz));
				
				/* Reset Peak detector */
				Filt_1_peak = 0;
				Filt_1_rms = 0;

				Filt_2_peak = 0;
				Filt_2_rms = 0;
				
				Control_Reg_NeoWrite_Write(1);
				StripLights_Trigger(1);

				count = 0;
			}			


			/* Store History */
			Filter_in_2 = Filter_in_1;
			Filter_in_1 = Filter_in;

			Filt_1_Out_2 = Filt_1_Out_1;
			Filt_1_Out_1 = Filt_1_Out;
			
			Filt_2_Out_2 = Filt_2_Out_1;
			Filt_2_Out_1 = Filt_2_Out;
			
			Filt_3_Out_2 = Filt_3_Out_1;
			Filt_3_Out_1 = Filt_3_Out;
			
			Filt_4_Out_2 = Filt_4_Out_1;
			Filt_4_Out_1 = Filt_4_Out;
			
			Filt_5_Out_2 = Filt_5_Out_1;
			Filt_5_Out_1 = Filt_5_Out;
			
			Filt_6_Out_2 = Filt_6_Out_1;
			Filt_6_Out_1 = Filt_6_Out;
			
			Filt_7_Out_2 = Filt_7_Out_1;
			Filt_7_Out_1 = Filt_7_Out;
			
			/* Increment loop counter */
			count++;
			
        /* `#END`  */
        
        /* Clear handled interrupt */
        ADC_SAR_SAR_INTR_REG = intr_status;
    }

#endif   /* End ADC_SAR_IRQ_REMOVE */


/* [] END OF FILE */
