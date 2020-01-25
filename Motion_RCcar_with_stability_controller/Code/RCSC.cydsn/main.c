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
#include "mpu6500.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_DUTY_VALUE 30
#define MAX_DUTY_OUT_VALUE 999
#define DEFAULT_DUTY 500
#define STEERING_OFFSET 100
#define THROTTLE_OFFSET 2200

void ProcessMPUData(void);
long map(long x, long in_min, long in_max, long out_min, long out_max);
void rcsc_func(void);

int16_t CAX, CAY, CAZ; //current acceleration values
int16_t CGX, CGY, CGZ; //current gyroscope values
float yaw_rate, accelX, accelY, speed = 0; //speed is in m/s, yaw rate degree/s
uint8_t ctrl_value = 0xFF;
//UARTINTERFACEchar buff[16], buff2[16], buff3[16];
//UARTINTERFACEchar str[128]; //print buffer
//unused const uint8_t overcorrection = 50; //percentage
uint16_t servoPeakLeft = 23122; //hardcoded servo extremes
uint16_t servoPeakRight = 12692;
uint16_t servoCenter = 18074;// = (servoPeakLeft + servoPeakRight)/2;
int16_t steeringPos, throttlePos;
uint16_t throttleCenter = 15591;
uint16_t throttleHigh = 24176;
uint16_t throttleLow = 12825;
int16_t finalTurnRate = 0;
int16_t steerAngleLow = -1;
int16_t steerAngleHigh = 1;
bool security = false;

//AN
    uint32 highCaptureCount = 0;

CY_ISR(mpureader_isr)
{
    ProcessMPUData();
    //UART_CPANEL_UartPutString("fire");
    readTimer_ClearInterrupt(readTimer_INTR_MASK_TC);
    //UART_CPANEL_UartPutString("4 done\n");
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Initialize timers for pwm read
    Timer_1_Start();
    Timer_2_Start();
    
    //Init timer for mpu read
    INT_125_StartEx(mpureader_isr);
    readTimer_Start();
    
    //Initialize program
    PWM_Start();
    I2C_MPU6500_Start();
    MPU6500_Init();
    MPU6500_Initialize();
    //UARTINTERFACEUART_CPANEL_Start();

    for(;;)
    {
        steeringPos = Timer_1_ReadCapture();
        throttlePos = Timer_2_ReadCapture();
        
        //Security if for some reason receiver disconnects
        if(steeringPos > servoPeakLeft+1000 || steeringPos < servoPeakRight+1000 || throttlePos < throttleLow+1000 || throttlePos > throttleHigh+1000)
        {
            steeringPos = servoCenter;
            throttlePos = throttleLow;
            security = true;
        }
        else
        {
            steeringPos = map(steeringPos, servoPeakLeft, servoPeakRight, -50, 50);
            throttlePos = map(throttlePos, throttleLow, throttleHigh, -50, 50);
            security = false;
        }
        //Dynamic servo alignment //hardcoded to save processor time
        /*if(highCaptureCount > servoPeakLeft)
        {
            servoPeakLeft = (uint16_t)highCaptureCount;
            servoCenter = (servoPeakLeft + servoPeakRight)/2;
        }
        if(highCaptureCount < servoPeakRight)
        {
            servoPeakRight = (uint16_t)highCaptureCount;
            servoCenter = (servoPeakLeft + servoPeakRight)/2;
        }*/
        
        //UARTINTERFACEitoa(speed, buff2, 10);
        //UARTINTERFACEitoa(yaw_rate, buff3, 10);
        //UARTINTERFACEsprintf(str, "Byte is: %s \t %s \t %hd \t %hd\n",buff3, buff2, steeringPos, throttlePos);
        //sprintf(str, "%s\n", buff3);
        //UARTINTERFACEUART_CPANEL_UartPutString(str);
        rcsc_func(); //Run the magic
        
        //UARTINTERFACECyDelay(10);
        
        //UART_CPANEL_UartPutString("5 done\n");
    }
    
}

void ProcessMPUData()
{
	MPU6500_getMotion6Alt(&CAX, &CAY, &CAZ, &CGX, &CGY, &CGZ);
                                                                      //0.0000611 * 4 = 1 / (125Hz / 65.5) Calculation
    accelX = (float)CAX * 0.0004885;
    accelY = (float)CAY * 0.0004885;
    if(accelX < 0)
    {
        accelX = accelX * (-1);
    }
    if(accelY < 0)
    {
        accelY = accelY * (-1);
    }
    speed = sqrt((pow(accelX, 2) + pow(accelY, 2)));
    //angle_pitch += (float)CGX;// * 0.0004885;                                   // Calculate the traveled pitch angle and add this to the angle_pitch variable
    //angle_roll += (float)CGY;// * 0.0004885;                                    // Calculate the traveled roll angle and add this to the angle_roll variable
    yaw_rate = ((float)CGZ + 298.2150538) * 0.0004885;                                       // Yaw rate in degrees per second
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//Magic happens here
void rcsc_func()
{
    ProcessMPUData();
    
    //int turnRateM = yaw_rate * abs(
    //PWM_WriteCompare(turnRate);
    int turnRateSetPoint = steeringPos;
    int turnRateMeasured = yaw_rate * abs(throttlePos); // degrees/s * speed
    int steeringAngle = turnRateSetPoint + (turnRateMeasured * steeringPos / 100);  // Compensation depending on the pot value
    int finalValue;

    //Active steeringlearner
    if(steeringAngle < steerAngleLow)
    {
        steerAngleLow = steeringAngle;
    }
    if(steeringAngle > steerAngleHigh)
    {
        steerAngleHigh = steeringAngle;
    }

    steeringAngle = map(steeringAngle, steerAngleLow, steerAngleHigh, -50, 50); // range = -50 to 50

    // Control steering servo (MRSC mode only)
    if(security == true)
    {
        
    }
    else
    {
        finalValue = map(steeringAngle, -50, 50, servoPeakRight, servoPeakLeft); // 45 - 135°
        PWM_WriteCompare(finalValue);
    }
}

/* [] END OF FILE */
