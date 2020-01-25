#include "project.h"
#include <stdio.h>
#include <stdlib.h>

//motor drivers I2C address
#define MD03ADD 0xB0 >> 1  //write address
#define MD04ADD 0xB2 >> 1  //write address

//number of motordrivers
#define n_motor 2 

//constant values
#define DEFAULT_SPEED 50
#define DEFAULT_ACCEL 128

//registers
#define COMMAND 0x00       //used to send the direction and to activate the other registers
#define STATUS 0x01        //not writable, returns the status
#define SPEED 0x02         //determines the maximum drive speed of the cart (higher value -> faster)
#define ACCEL 0x03         //determines the acceleration speed of the cart (higher value -> longer acceleration time)
#define TEMP 0x04          //not writable, returns the tempreture of the motor driver
#define M_CURRENT 0x05     //not writable, returns the Current of the motor driver
#define UNUSED 0x06        //unnused register
#define SOFTRV 0x07        //register reset 

//Direction values
const uint8_t Start_F = 0x01; // Forward
const uint8_t Start_R = 0x02; // Reverse
const uint8_t Stop = 0x00;    // Immediate Stop

//global values
uint8_t echo_flag = 0; // Echo ID
uint16_t dist;         // distance cart to obstruction

typedef struct  //data struct writable value
{
    uint8_t direction[ n_motor ];
    uint8_t speed[ n_motor ];
    uint8_t accel[ n_motor ];
    struct sData *next;
    struct sData *prev;
} sData;

//flags
uint8_t flag_direct[ n_motor ] = { 0, 0 }; 
uint8_t flag_spd[ n_motor ] = { 0, 0 };    
uint8_t flag_accel[ n_motor ] = { 0, 0 };  

//BLE global
CYBLE_CONN_HANDLE_T connHandle;    

//functions
void sendData( uint32_t address , uint8_t reg, uint8_t val );
void UpdateBLEcharacteristic( uint8 *pu8Data, uint8 u8DataLen, uint16 attrHandle ); 
void eventhandler( uint32 event, void *eventParam );    

//function definitions
void sendData( uint32_t address, uint8_t reg, uint8_t val ) 
{
    I2C_1_I2CMasterSendStart( address, 0, 0 );  //connecting to the motor driver
    I2C_1_I2CMasterWriteByte( reg, 0 );         //select required data register
    I2C_1_I2CMasterWriteByte( val, 0 );         //write value
    I2C_1_I2CMasterSendStop( 0 );               //stops I2C
}

void UpdateBLEcharacteristic( uint8 *pu8Data, uint8 u8DataLen, uint16 attrHandle )
{ 

  CYBLE_GATT_HANDLE_VALUE_PAIR_T Handle;  //Bluetooth attriute handler

  Handle.attrHandle = attrHandle; 
  Handle.value.val = pu8Data;     
  Handle.value.len = u8DataLen;  

  CyBle_GattsWriteAttributeValue( &Handle, 0x00u, &cyBle_connHandle, CYBLE_GATT_DB_PEER_INITIATED );
}


CY_ISR( isr_2_R_handler )
{
        echo_flag = 4; 
        UltraSone_2_Echo_R_ClearInterrupt();
}

CY_ISR( isr_2_L_handler ) 
{
        echo_flag = 3; 
        UltraSone_2_Echo_L_ClearInterrupt();
}

CY_ISR( UltraSone_2_Echo_intr_handler ) 
{
        dist = ( Timer_2_ReadCapture() * 0.0343 ) / 2; // in cm
        
        Timer_2_ClearInterrupt( Timer_1_INTR_MASK_CC_MATCH ); 
}    

CY_ISR( isr_1_M_handler ) 
{
            echo_flag = 2; 
            UltraSone_1_Echo_M_ClearInterrupt();
}
CY_ISR( isr_1_L_handler ) 
{
            echo_flag = 3; 
            UltraSone_1_Echo_L_ClearInterrupt();
}
CY_ISR( isr_1_R_handler ) 
{
            echo_flag = 4; 
            UltraSone_1_Echo_R_ClearInterrupt();
}
CY_ISR( UltraSone_1_Echo_intr_handler ) 
{       
        dist = ( Timer_1_ReadCapture() * 0.0343 ) / 2; // in cm

        Timer_1_ClearInterrupt( Timer_1_INTR_MASK_CC_MATCH );
}

void eventhandler( uint32 event, void *eventParam ) 
{   
    CyGlobalIntDisable;  //prevents timouts
    uint8 SPEEDt[ n_motor ]; 
    uint8 ACCELt[ n_motor ]; 
    uint8 Direction[ n_motor ]; 
   
CYBLE_GATTS_WRITE_REQ_PARAM_T *wrReqParam;  //parameter write
   
    switch( event )
    {
    
        case CYBLE_EVT_STACK_ON:  // BLE stack is on. Start BLE advertisement  
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED: 
            CyBle_GappStartAdvertisement( CYBLE_ADVERTISING_FAST ); 
            
            
            UpdateBLEcharacteristic( SPEEDt, sizeof( SPEEDt ), CYBLE_BLE_MOTOR_SPEED_CHAR_INDEX ); 
            UpdateBLEcharacteristic( ACCELt, sizeof( ACCELt ), CYBLE_BLE_MOTOR_ACCELERATION_CHAR_INDEX );
            UpdateBLEcharacteristic( Direction, sizeof( Direction ), CYBLE_BLE_MOTOR_DIRECTION_CHAR_INDEX );
            
            
            sendData( MD03ADD, ACCEL, DEFAULT_ACCEL );
            sendData( MD03ADD, SPEED, 0 );
            sendData( MD04ADD, ACCEL, DEFAULT_ACCEL );
            sendData( MD04ADD, SPEED, 0 );
            sendData( MD03ADD, COMMAND, Direction[0] );
            sendData( MD04ADD, COMMAND, Direction[1] );
            
        break;

        case CYBLE_EVT_GAP_DEVICE_CONNECTED:
        
                 UpdateBLEcharacteristic( SPEEDt, sizeof( SPEEDt ), CYBLE_BLE_MOTOR_SPEED_CHAR_INDEX );
                 UpdateBLEcharacteristic( ACCELt, sizeof( ACCELt ), CYBLE_BLE_MOTOR_ACCELERATION_CHAR_INDEX );
                 UpdateBLEcharacteristic( Direction, sizeof( Direction ), CYBLE_BLE_MOTOR_DIRECTION_CHAR_INDEX );
        break;
        case CYBLE_EVT_GATT_CONNECT_IND: 
                connHandle = *( CYBLE_CONN_HANDLE_T* ) eventParam; 
                UpdateBLEcharacteristic( SPEEDt, sizeof( SPEEDt ), CYBLE_BLE_MOTOR_SPEED_CHAR_INDEX );
                UpdateBLEcharacteristic( ACCELt, sizeof( ACCELt ), CYBLE_BLE_MOTOR_ACCELERATION_CHAR_INDEX );
                UpdateBLEcharacteristic( Direction, sizeof( Direction ), CYBLE_BLE_MOTOR_DIRECTION_CHAR_INDEX );
                
                break;
         
        case CYBLE_EVT_GATTS_WRITE_REQ: 
            
            wrReqParam = ( CYBLE_GATTS_WRITE_REQ_PARAM_T* ) eventParam; 

            
            if( CYBLE_BLE_MOTOR_SPEED_CHAR_HANDLE == wrReqParam->handleValPair.attrHandle )  
            {
                CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair, 0x00u, &connHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);
                
                
                SPEEDt[0] = wrReqParam->handleValPair.value.val[0];
                SPEEDt[1] = wrReqParam->handleValPair.value.val[1];
                
                
                UpdateBLEcharacteristic( SPEEDt, sizeof( SPEEDt ), CYBLE_BLE_MOTOR_SPEED_CHAR_HANDLE ); 
                
                
                sendData( MD03ADD, ACCEL, flag_accel[0] );
                sendData( MD04ADD, ACCEL, flag_accel[1] );
                
                sendData( MD03ADD, SPEED, SPEEDt[0] );
                sendData( MD04ADD, SPEED, SPEEDt[1] );
                
                sendData( MD04ADD, COMMAND, flag_direct[1] );
                sendData( MD03ADD, COMMAND, flag_direct[0] );
                
                
                flag_spd[0] = SPEEDt[0];
                flag_spd[1] = SPEEDt[1];
            }
            
            if( CYBLE_BLE_MOTOR_ACCELERATION_CHAR_HANDLE == wrReqParam->handleValPair.attrHandle )
            {
                CyBle_GattsWriteAttributeValue( &wrReqParam->handleValPair, 0x00u, &connHandle, CYBLE_GATT_DB_LOCALLY_INITIATED );
               
                ACCELt[0] = wrReqParam->handleValPair.value.val[0];
                ACCELt[1] = wrReqParam->handleValPair.value.val[1];
            
                UpdateBLEcharacteristic( ACCELt, sizeof( ACCELt ), CYBLE_BLE_MOTOR_ACCELERATION_CHAR_HANDLE );
            
                sendData( MD03ADD, ACCEL, ACCELt[0] );
                sendData( MD04ADD, ACCEL, ACCELt[1] );
                
                sendData( MD03ADD, SPEED, flag_spd[0] );
                sendData( MD04ADD, SPEED, flag_spd[1] );
                
                sendData( MD04ADD, COMMAND, flag_direct[1] );
                sendData( MD03ADD, COMMAND, flag_direct[0] );
                
                flag_accel[0] = ACCELt[0];
                flag_accel[1] = ACCELt[1];
            }
            
            if( CYBLE_BLE_MOTOR_DIRECTION_CHAR_HANDLE == wrReqParam->handleValPair.attrHandle )
            {                
                CyBle_GattsWriteAttributeValue( &wrReqParam->handleValPair, 0x00u, &connHandle, CYBLE_GATT_DB_LOCALLY_INITIATED );
           
                Direction[0] = wrReqParam->handleValPair.value.val[0];
                Direction[1] = wrReqParam->handleValPair.value.val[1];
            
                UpdateBLEcharacteristic( Direction, sizeof( Direction ), CYBLE_BLE_MOTOR_DIRECTION_CHAR_HANDLE );
                
                sendData( MD03ADD, ACCEL, flag_accel[0] );
                sendData( MD04ADD, ACCEL, flag_accel[1] );
                
                sendData( MD03ADD, SPEED, flag_spd[0] );
                sendData( MD04ADD, SPEED, flag_spd[1] );
                
                sendData( MD04ADD, COMMAND, Direction[1] );
                CyDelay(500);   // "Synchronizes" MD04
                sendData( MD03ADD, COMMAND, Direction[0] );
                
                flag_direct[0] = Direction[0];
                flag_direct[1] = Direction[1];          
            }
            CyBle_GattsWriteRsp( connHandle );
            break;
            
        default:
            break;
    }
}

int main( void )
{
   
    CyGlobalIntDisable; //prevents timeouts
    //sData data;
    
    I2C_1_Start();
    
    // initialize start values
    sendData( MD03ADD, ACCEL, DEFAULT_ACCEL );
    flag_accel[0] = DEFAULT_ACCEL;
    sendData( MD03ADD, SPEED, 0 );
    flag_spd[0] = 0;
    sendData( MD04ADD, ACCEL, DEFAULT_ACCEL );
    flag_accel[1] = DEFAULT_ACCEL;
    sendData( MD04ADD, SPEED, 0 );
    flag_spd[1] = 0;
    sendData( MD03ADD, COMMAND, Stop );
    flag_direct[0] = Stop;
    sendData( MD04ADD, COMMAND, Stop );
    flag_direct[1] = Stop;

    PWM_1_Start();
    Timer_1_Start();
    Timer_2_Start();

    CyGlobalIntDisable;
    
    CyBle_Start( eventhandler );

    //unnused
    /*for ( int i = 0; i < 2; ++i )
    {
        data.direction[i] = flag_direct[i];
        data.speed[i] = flag_spd[i];
        data.accel[i] = flag_accel[i];
    }*/

    for( ;; ) 
    { 
        
        CyBle_ProcessEvents();
        CyGlobalIntEnable;   
        
        // enable US sensors in terms of direction
        if( flag_direct[0] == Start_F && flag_direct[1] == Start_F )
        {
            
            UltraSone_2_Echo_intr_Stop();
                isr_2_R_Stop();
                isr_2_L_Stop();
                
            
            UltraSone_1_Echo_intr_StartEx( UltraSone_1_Echo_intr_handler );       
                isr_1_M_StartEx( isr_1_M_handler );
                isr_1_L_StartEx( isr_1_L_handler );
                isr_1_R_StartEx( isr_1_R_handler );
        }
        else if( flag_direct[0] == Start_R && flag_direct[1] == Start_R )
        {
            UltraSone_1_Echo_intr_Stop();
                isr_1_M_Stop();
                isr_1_R_Stop();
                isr_1_L_Stop();
                
            UltraSone_2_Echo_intr_StartEx( UltraSone_2_Echo_intr_handler );
                isr_2_L_StartEx( isr_2_L_handler );
                isr_2_R_StartEx( isr_2_R_handler );
        }
        
        //distance management
        while( dist <= 28 && echo_flag != 0 )
            {
                CyGlobalIntDisable; 
                
                //CRITICAL DISTANCE
                if( dist < 7 )
                {
                    flag_accel[0] = 100;
                    flag_accel[1] = 100;
                    flag_spd[0] = 0;
                    flag_spd[1] = 0;
                
                    sendData( MD03ADD, ACCEL, flag_accel[0] );
                    sendData( MD04ADD, ACCEL, flag_accel[1] );
            
                    sendData( MD03ADD, SPEED, flag_spd[0] );
                    sendData( MD04ADD, SPEED, flag_spd[1] );

                    sendData( MD03ADD, COMMAND, Stop );
                    sendData( MD04ADD, COMMAND, Stop );
                }
                else
                
                {
                    flag_accel[0] = 0;
                    flag_accel[1] = 0;
                    
                    sendData( MD03ADD, ACCEL, flag_accel[0] );
                    sendData( MD04ADD, ACCEL, flag_accel[1] );
                //LED_R_M_Write( 0 );
                    
                    //echo ID management
                    if( echo_flag == 2 )
                    {
                        
                        LED_G_L_Write( 1 );
                        LED_B_R_Write( 1 );
                        LED_R_M_Write( 0 );
                        
                        //slowing down
                        flag_spd[0] = flag_spd[0] <= 0 ? 0: flag_spd[0]--;
                        flag_spd[1] = flag_spd[1] <= 0 ? 0: flag_spd[1]--;
                        
                        sendData( MD03ADD, SPEED, flag_spd[0] );
                        sendData( MD04ADD, SPEED, flag_spd[1] );
                        
                        sendData( MD04ADD, COMMAND, flag_direct[1] );
                        sendData( MD03ADD, COMMAND, flag_direct[0] );
                    }
                    else if( echo_flag == 3 )
                    {
                        LED_R_M_Write( 1 );
                        LED_B_R_Write( 1 );
                        LED_G_L_Write( 0 );
                        
                        // Turning to safety
                                     
                        sendData( MD04ADD, SPEED, flag_spd[0] );
                        sendData( MD03ADD, SPEED, 0 );
                        
                        sendData( MD04ADD, COMMAND, flag_direct[1] );
                        sendData( MD03ADD, COMMAND, flag_direct[0] );
                    }
                    else if( echo_flag == 4 )
                    {
                        LED_G_L_Write( 1 );
                        LED_R_M_Write( 1 );
                        LED_B_R_Write( 0 );
                                                
                        sendData( MD03ADD, SPEED, flag_spd[1] );
                        sendData( MD04ADD, SPEED, 0 );
                        
                        sendData( MD04ADD, COMMAND, flag_direct[1] );
                        sendData( MD03ADD, COMMAND, flag_direct[0] );     
                    }
                }
                break;
            }           
            //safe distance
            if( dist > 28 )
            {
                CyGlobalIntDisable;
                LED_R_M_Write( 1 );
                LED_G_L_Write( 1 );
                LED_B_R_Write( 1 );          
            }       
    }    
} /* [] END OF FILE */