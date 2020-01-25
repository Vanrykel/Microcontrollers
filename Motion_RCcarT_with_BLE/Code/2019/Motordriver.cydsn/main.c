#include "project.h"

// DEVICE
#define MD03ADD 0xB0 >> 1  //write address
#define MD04ADD 0xB2 >> 1  //write address
#define n_motor 2
#define DEFAULT_SPEED 50
#define DEFAULT_ACCEL 128

// REGISTERS
#define COMMAND 0x00
#define STATUS 0x01
#define SPEED 0x02
#define ACCEL 0x03
#define TEMP 0x04
#define M_CURRENT 0x05
#define UNUSED 0x06
#define SOFTRV 0x07

// EXTERNALS
extern const uint8_t Start_F;
extern const uint8_t Start_R;
extern const uint8_t Stop;
const uint8_t Start_F = 0x01;
const uint8_t Start_R = 0x02;
const uint8_t Stop = 0x00;


uint8 SPEEDt[n_motor];
uint8 ACCELt[n_motor];

void sendData(uint32_t address ,uint8_t reg, uint8_t val) ;
void UpdateBLEcharacteristic(uint8* pu8Data, uint8 u8DataLen, uint16 attrHandle) ;
void eventhandler(uint32 event, void * eventParam) ;

void sendData(uint32_t address ,uint8_t reg, uint8_t val){
    
    I2C_Master_I2CMasterSendStart(address,0,0) ;
    I2C_Master_I2CMasterWriteByte(reg,0) ;
    I2C_Master_I2CMasterWriteByte(val,0) ;
    I2C_Master_I2CMasterSendStop(0) ;
}

int main(void)
{
    CyGlobalIntEnable;
    
    int spd = 0x90 ;
    I2C_Master_Start();

    sendData(MD03ADD, ACCEL, 100) ;
    sendData(MD04ADD, ACCEL, 100) ;
    
    sendData(MD03ADD,SPEED, spd) ;
    sendData(MD04ADD,SPEED, spd) ;
    
    sendData(MD04ADD,COMMAND, Start_F) ;
    CyDelay(1000);
    sendData(MD03ADD,COMMAND, Start_F) ;
    
    CyDelay(7000) ;

    sendData(MD03ADD,SPEED, 0) ;
    sendData(MD04ADD,SPEED, 0) ;
    sendData(MD04ADD,COMMAND, Start_F) ;
    sendData(MD03ADD,COMMAND, Start_F) ;
    CyDelay(5000);
    sendData(MD03ADD,COMMAND, Stop);
    sendData(MD04ADD,COMMAND, Stop);
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
