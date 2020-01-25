#include "project.h"

uint8 FORWARD  = 0;
uint8 BACKWARD = 0;
uint8 LEFT     = 0;
uint8 RIGHT    = 0;
    
//Function to update the LED status in the GATT database.
void update_GATT_LED()
{
    if(CyBle_GetState() != CYBLE_STATE_CONNECTED)
        return;
    
    CYBLE_GATTS_HANDLE_VALUE_NTF_T tempHandle;
    
    uint8 red_State = !BLE_StatusLED_Read();
    
    tempHandle.attrHandle =  CYBLE_BLE_CAR_LED_CHAR_HANDLE;
    tempHandle.value.val  = (uint8 *) &red_State;
    tempHandle.value.len  = 1;
    CyBle_GattsWriteAttributeValue(&tempHandle, 0, &cyBle_connHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);
}

void BleCallBack(uint32 event, void* eventParam)
{
    CYBLE_GATTS_WRITE_REQ_PARAM_T *wrReqParam;
    
    switch(event)
    {
        case CYBLE_EVT_STACK_ON:
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            PWM_Start();
        break;
            
        case CYBLE_EVT_GATT_CONNECT_IND:
            update_GATT_LED();
            PWM_Stop();
        break;
            
        case CYBLE_EVT_GATTS_WRITE_REQ:
            wrReqParam = (CYBLE_GATTS_WRITE_REQ_PARAM_T *) eventParam;
            
            if(wrReqParam->handleValPair.attrHandle == CYBLE_BLE_CAR_LED_CHAR_HANDLE)
            {
                if(CYBLE_GATT_ERR_NONE == CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair, 0, &cyBle_connHandle, CYBLE_GATT_DB_PEER_INITIATED))
                {
                    BLE_StatusLED_Write(!wrReqParam->handleValPair.value.val[0]);
                    CyBle_GattsWriteRsp(cyBle_connHandle);
                }
            }  
            
            if(wrReqParam->handleValPair.attrHandle == CYBLE_BLE_CAR_BUTTON_LEFT_CHAR_HANDLE)
            {
                if(CYBLE_GATT_ERR_NONE == CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair, 0, &cyBle_connHandle, CYBLE_GATT_DB_PEER_INITIATED))
                {
                    LEFT = wrReqParam->handleValPair.value.val[0];
                    CyBle_GattsWriteRsp(cyBle_connHandle);
                }
            }
            
            if(wrReqParam->handleValPair.attrHandle == CYBLE_BLE_CAR_BUTTON_RIGHT_CHAR_HANDLE)
            {
                if(CYBLE_GATT_ERR_NONE == CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair, 0, &cyBle_connHandle, CYBLE_GATT_DB_PEER_INITIATED))
                {
                    RIGHT = wrReqParam->handleValPair.value.val[0];
                    CyBle_GattsWriteRsp(cyBle_connHandle);
                }
            } 
            
            if(wrReqParam->handleValPair.attrHandle == CYBLE_BLE_CAR_BUTTON_FORWARD_CHAR_HANDLE)
            {
                if(CYBLE_GATT_ERR_NONE == CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair, 0, &cyBle_connHandle, CYBLE_GATT_DB_PEER_INITIATED))
                {
                    FORWARD = wrReqParam->handleValPair.value.val[0];
                    CyBle_GattsWriteRsp(cyBle_connHandle);
                }
            } 
            
            if(wrReqParam->handleValPair.attrHandle == CYBLE_BLE_CAR_BUTTON_BACKWARD_CHAR_HANDLE)
            {
                if(CYBLE_GATT_ERR_NONE == CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair, 0, &cyBle_connHandle, CYBLE_GATT_DB_PEER_INITIATED))
                {
                    BACKWARD = wrReqParam->handleValPair.value.val[0];
                    CyBle_GattsWriteRsp(cyBle_connHandle);
                }
            } 
            break;
            
        default:
            break;
    }                  
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    CyBle_Start(BleCallBack);
    
    for(;;)
    {   
        if(FORWARD && BACKWARD)
        {
            Direction_Motor_A_Write(0);
            Speed_Motor_A_Write(0);
            Direction_Motor_B_Write(0);
            Speed_Motor_B_Write(0);
        }
        
        else if(FORWARD)
        {
            if(LEFT && RIGHT)
            {
                Direction_Motor_A_Write(1);  
                Speed_Motor_A_Write(1); 
                Direction_Motor_B_Write(0);
                Speed_Motor_B_Write(0); 
            }
            else if(LEFT)
            {                
                Direction_Motor_A_Write(1);  
                Speed_Motor_A_Write(1);  
                Direction_Motor_B_Write(0);
                Speed_Motor_B_Write(1);
            }
            else if(RIGHT)
            {
                Direction_Motor_A_Write(1);  
                Speed_Motor_A_Write(1);
                Direction_Motor_B_Write(1);
                Speed_Motor_B_Write(1);
            }
            else
            {
                Direction_Motor_A_Write(1);  
                Speed_Motor_A_Write(1);  
                Direction_Motor_B_Write(0);
                Speed_Motor_B_Write(0);
            }        
        }
        
        else if(BACKWARD)
        {
            if(LEFT && RIGHT)
            {
                Direction_Motor_A_Write(0);  
                Speed_Motor_A_Write(1); 
                Direction_Motor_B_Write(0);
                Speed_Motor_B_Write(0); 
            }
            else if(LEFT)
            {                
                Direction_Motor_A_Write(0);  
                Speed_Motor_A_Write(1);  
                Direction_Motor_B_Write(0);
                Speed_Motor_B_Write(1);
            }
            else if(RIGHT)
            {
                Direction_Motor_A_Write(0);  
                Speed_Motor_A_Write(1);
                Direction_Motor_B_Write(1);
                Speed_Motor_B_Write(1);
            }
            else
            {
                Direction_Motor_A_Write(0);  
                Speed_Motor_A_Write(1);  
                Direction_Motor_B_Write(0);
                Speed_Motor_B_Write(0);
            }        
        }

        else
        {
            Direction_Motor_A_Write(0);
            Speed_Motor_A_Write(0);
            Direction_Motor_B_Write(0);
            Speed_Motor_B_Write(0);
        }
        

        CyBle_ProcessEvents();
        CyBle_EnterLPM(CYBLE_BLESS_DEEPSLEEP);
    }
}


/* [] END OF FILE */
