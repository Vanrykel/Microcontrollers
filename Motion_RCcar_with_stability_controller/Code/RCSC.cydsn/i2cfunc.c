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

#include <project.h>

//Code to read bytes from I2C module
void I2CReadBytes(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data)
{
    I2C_MPU6500_I2CMasterSendStart(Address, 0, 10);
    I2C_MPU6500_I2CMasterWriteByte(Register, 10);
    I2C_MPU6500_I2CMasterSendRestart(Address, 1, 10);
    uint8 i = 0;
    while((Nbytes - 1))
    {
        I2C_MPU6500_I2CMasterReadByte(I2C_MPU6500_I2C_ACK_DATA, (Data + i), 10);
        i++;
        Nbytes--;
    }
    I2C_MPU6500_I2CMasterReadByte(I2C_MPU6500_I2C_NAK_DATA, (Data + i), 10);
    I2C_MPU6500_I2CMasterSendStop(0);
}

void I2CReadByte(uint8_t Address, uint8_t Register, uint8_t *value) {
	I2CReadBytes(Address, Register, 1, value);
}

void I2CReadBits(uint8_t Address, uint8_t Register, uint8_t bitStart, uint8_t length, uint8_t *value) 
{
   	uint8_t mask = ((1 << length) - 1) << (bitStart - length + 1);
    I2CReadByte(Address, Register, value);
    *value &= mask;
    *value >>= (bitStart - length + 1);
}

//Code to write bytes to I2C module
void I2CWriteBytes(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data)
{
    I2C_MPU6500_I2CMasterSendStart(Address, 0, 10);
    I2C_MPU6500_I2CMasterWriteByte(Register, 10);
    uint8 i = 0;
    while(Nbytes)
    {
        I2C_MPU6500_I2CMasterWriteByte(*(Data + 1), 10);
        i++;
        Nbytes--;
    }
    I2C_MPU6500_I2CMasterSendStop(0);
}

void I2CWriteByte(uint8_t Address, uint8_t Register, uint8_t value) 
{
	I2CWriteBytes(Address, Register, 1, &value);
}

void I2CWriteBits(uint8_t Address, uint8_t Register, uint8_t bitStart, uint8_t length, uint8_t value)
{
    uint8_t b;
	uint8_t mask = ((1 << length) - 1) << (bitStart - length + 1);
	I2CReadByte(Address, Register, &b);
	value <<= (bitStart - length + 1);
	value &= mask;
	b &= ~(mask);
	b |= value;
	I2CWriteByte(Address, Register, b);	
}

void I2CWriteBit(uint8_t Address, uint8_t Register, uint8_t bitNum, uint8_t value)
{
	uint8_t b;
	I2CReadByte(Address, Register, &b);
	b = (value != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	I2CWriteByte(Address, Register, b);
}

/* [] END OF FILE */
