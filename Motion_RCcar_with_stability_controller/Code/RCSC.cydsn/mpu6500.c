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
#include "mpu6500.h"
//#include "i2cfunc.c"

void MPU6050_setFullScaleGyroRange(uint8_t range) {
    I2CWriteBits(devAddr, MPU6500_RA_GYRO_CONFIG, MPU6500_GCONFIG_FS_SEL_BIT, MPU6500_GCONFIG_FS_SEL_LENGTH, range);
}

//Initialize
void MPU6500_Init(){
    devAddr = MPU6500_DEFAULT_ADDRESS;
}

void MPU6500_Initialize() {
    MPU6500_setClockSource(MPU6500_CLOCK_PLL_XGYRO);
    MPU6500_setFullScaleGyroRange(MPU6500_GYRO_FS_250);
    MPU6500_setFullScaleAccelRange(MPU6500_ACCEL_FS_2);
    MPU6500_setSleepEnabled(false);
}

void MPU6500_setClockSource(uint8_t source) {
    I2CWriteBits(devAddr, MPU6500_RA_PWR_MGMT_1, MPU6500_PWR1_CLKSEL_BIT, MPU6500_PWR1_CLKSEL_LENGTH, source);
}

void MPU6500_setFullScaleGyroRange(uint8_t range) {
    I2CWriteBits(devAddr, MPU6500_RA_GYRO_CONFIG, MPU6500_GCONFIG_FS_SEL_BIT, MPU6500_GCONFIG_FS_SEL_LENGTH, range);
}

void MPU6500_setFullScaleAccelRange(uint8_t range) {
    I2CWriteBits(devAddr, MPU6500_RA_ACCEL_CONFIG, MPU6500_ACONFIG_AFS_SEL_BIT, MPU6500_ACONFIG_AFS_SEL_LENGTH, range);
}

void MPU6500_setSleepEnabled(bool enabled) {
    I2CWriteBit(devAddr, MPU6500_RA_PWR_MGMT_1, MPU6500_PWR1_SLEEP_BIT, enabled);
}

void MPU6500_getMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz) {
    I2CReadBytes(devAddr, MPU6500_RA_ACCEL_XOUT_H, 14, buffer);
    
    //fixme the following code needs to be examined. causes a interrupt to NMI_VECTOR
    *ax = (((int16_t)buffer[0]) << 8) | buffer[1];
    *ay = (((int16_t)buffer[2]) << 8) | buffer[3];
    *az = (((int16_t)buffer[4]) << 8) | buffer[5];
    *gx = (((int16_t)buffer[8]) << 8) | buffer[9];
    *gy = (((int16_t)buffer[10]) << 8) | buffer[11];
    *gz = (((int16_t)buffer[12]) << 8) | buffer[13];
}

void MPU6500_getMotion6Alt(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz) {
    I2CReadBytes(devAddr, MPU6500_RA_ACCEL_XOUT_H, 14, buffer);
    
    //fixme the following code needs to be examined. causes a interrupt to NMI_VECTOR
    /**ax = (((int16_t)buffer[0]) << 8) | buffer[1];
    *ay = (((int16_t)buffer[2]) << 8) | buffer[3];
    *az = (((int16_t)buffer[4]) << 8) | buffer[5];
    *gx = (((int16_t)buffer[8]) << 8) | buffer[9];
    *gy = (((int16_t)buffer[10]) << 8) | buffer[11];
    *gz = (((int16_t)buffer[12]) << 8) | buffer[13];*/
    *ax = (buffer[0] << 8) | buffer[1];
    *ay = (buffer[2] << 8) | buffer[3];
    *az = (buffer[4] << 8) | buffer[5];
    *gx = (buffer[8] << 8) | buffer[9];
    *gy = (buffer[10] << 8) | buffer[11];
    *gz = (buffer[12] << 8) | buffer[13];
}

/* [] END OF FILE */
