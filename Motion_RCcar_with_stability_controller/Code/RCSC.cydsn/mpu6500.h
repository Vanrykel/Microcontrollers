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
#include <stdint.h>
#include <stdbool.h>

#ifndef _MPU6500_H_
#define _MPU6500_H_

#define MPU6500_DEFAULT_ADDRESS     0x68
#define MPU6500_RA_ACCEL_XOUT_H     0x3B
#define MPU6500_RA_GYRO_CONFIG      0x1B
#define MPU6500_GCONFIG_FS_SEL_BIT      4
#define MPU6500_GCONFIG_FS_SEL_LENGTH   2
#define MPU6500_CLOCK_PLL_XGYRO         0x01
#define MPU6500_GYRO_FS_250         0x00
#define MPU6500_ACCEL_FS_2          0x00
#define MPU6500_RA_ACCEL_XOUT_H     0x3B
#define MPU6500_RA_PWR_MGMT_1       0x6B
#define MPU6500_PWR1_CLKSEL_BIT         2
#define MPU6500_PWR1_CLKSEL_LENGTH      3
#define MPU6500_RA_ACCEL_CONFIG     0x1C
#define MPU6500_ACONFIG_AFS_SEL_BIT         4
#define MPU6500_ACONFIG_AFS_SEL_LENGTH      2
#define MPU6500_PWR1_SLEEP_BIT          6

uint8_t devAddr;
uint8_t buffer[22];

extern void I2CReadBytes(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data);
extern void I2CReadByte(uint8_t Address, uint8_t Register, uint8_t *value);
extern void I2CWriteBytes(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data);
extern void I2CWriteByte(uint8_t Address, uint8_t Register, uint8_t value);
extern void I2CWriteBits(uint8_t Address, uint8_t Register, uint8_t bitStart, uint8_t length, uint8_t value);
extern void I2CReadBits(uint8_t Address, uint8_t Register, uint8_t bitStart, uint8_t length, uint8_t *value);
extern void I2CWriteBit(uint8_t Address, uint8_t Register, uint8_t bitNum, uint8_t value);

void MPU6500_Init();
void MPU6500_Initialize();

void MPU6500_setClockSource(uint8_t source);

void MPU6500_setFullScaleGyroRange(uint8_t range);

void MPU6500_setFullScaleAccelRange(uint8_t range);

void MPU6500_setSleepEnabled(bool enabled);

//Weird data?
void MPU6500_getMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);

//Zelfde data van arduino lib
void MPU6500_getMotion6Alt(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);
    
#endif /* _MPU6500_H_ */

/* [] END OF FILE */
