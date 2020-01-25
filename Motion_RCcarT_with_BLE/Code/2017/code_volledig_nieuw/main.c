
#include "project.h"
uint16 fingerPos = 0xFFFF;
uint16 fingerPosOld = 0xFFFF; 

// 0 nontifications off - 1 nontifications onn
int capsenseNotify; 

// wanneer deze functie wordt opgeroepen -> pak status led -> steek in database
void updateLed()
{
    // is voor temphandle tussenfuncties te maken
    CYBLE_GATTS_HANDLE_VALUE_NTF_T tempHandle;
    int currentLed = (!red_Read());
    
    // als de bluetooth niet cnnected is stop dan 
    if ( CyBle_GetState() !=CYBLE_STATE_CONNECTED)
    return; 
    
    // char die led noemt linken aan de tempHandle
    tempHandle.attrHandle = CYBLE_LEDCAPSENSE_LED_CHAR_HANDLE;
    
    //lees de waarde van de pin en toggle het omdat het actief laag is ( voor android logischer te maken ) 
    tempHandle.value.val = ( uint8 * ) &currentLed;
    
    //het is 1 byte 
    tempHandle.value.len = 1;
    
    // schrijf het in de database 
    CyBle_GattsWriteAttributeValue(&tempHandle, 0, &cyBle_connHandle, 0); 
}




void updateCapsense ()
{ 
    if( CyBle_GetState() != CYBLE_STATE_CONNECTED ) 
    return; 
    CYBLE_GATTS_HANDLE_VALUE_NTF_T tempHandle; 
     tempHandle.attrHandle = CYBLE_LEDCAPSENSE_CAPSENSE_CHAR_HANDLE;
    
    //lees de waarde van de pin en toggle het omdat het actief laag is ( voor android logischer te maken ) 
    tempHandle.value.val = ( uint8 * ) &fingerPos;
    
    //het is 1 byte 
    tempHandle.value.len = 2;
    
    // schrijf het in de database 
    CyBle_GattsWriteAttributeValue(&tempHandle, 0, &cyBle_connHandle, 0); 
    // wanneer er een waarde wordt verandert wordt dit hier geregistreerd
    if(capsenseNotify && (fingerPos != fingerPosOld))
    {
        CyBle_GattsNotification(cyBle_connHandle, &tempHandle); 
        fingerPosOld = fingerPos; 
    }
}




// Wat er moet gebeuren met gebeurtenissen / events
void BleCallBack(uint32 event, void * eventParam) 
{
    CYBLE_GATTS_WRITE_REQ_PARAM_T * wrReqParam;
    switch(event) 
    {
        case CYBLE_EVT_STACK_ON :
        
        // wanneer disconected is => geen meldingen meegeven en de advertising event strarten ??   LAAT BLUE LED BLINKEN
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED : 
            capsenseNotify = 0;
            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            pwm_Start();
        break;
            
        // Wanneer connectie vanuit gsm is geactiveerd => alle vars updaten 
        case CYBLE_EVT_GATT_CONNECT_IND:
            updateLed();
            updateCapsense();
            pwm_Stop();       
        break;
           
        // Wanner gsm iets in de database wil schrijven 
        case CYBLE_EVT_GATTS_WRITE_REQ : 
            wrReqParam = (CYBLE_GATTS_WRITE_CMD_REQ_PARAM_T *) eventParam; 
            // kijken of de gsm de LED wilt veranderen
            if (wrReqParam->handleValPair.attrHandle == CYBLE_LEDCAPSENSE_LED_CHAR_HANDLE)
            {
                // kijken of het mag 
                if (CYBLE_GATT_ERR_NONE == CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair,0, &cyBle_connHandle, CYBLE_GATT_DB_PEER_INITIATED))
                {
                    red_Write(!wrReqParam->handleValPair.value.val[0]);
                    uint32 test = (!wrReqParam->handleValPair.value.val[0]);
                 
                    // response terug geven 
                    CyBle_GattsWriteRsp(cyBle_connHandle);
                    
                }
            }
            
            // wanneer de gsm een nontification van de capsense wilt ontvangen
            if(wrReqParam->handleValPair.attrHandle == CYBLE_LEDCAPSENSE_CAPSENSE_CAPSENSECCCD_DESC_HANDLE)
            {
                CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair, 0, &cyBle_connHandle, CYBLE_GATT_DB_PEER_INITIATED);
                capsenseNotify = wrReqParam->handleValPair.value.val[0] &0x01;
                // response terug geven 
                CyBle_GattsWriteRsp(cyBle_connHandle);
                
            }
            break; 
            
            default: 
            break; 
    }
} 
            
            
            
            
        
            
            
        
    
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    // wekrt de ruis weg 
    capsense_Start();
    capsense_InitializeEnabledBaselines();
    CyBle_Start(BleCallBack);
    
    for(;;)
    {
       
        if ( !capsense_IsBusy())
        {
            fingerPos = capsense_GetCentroidPos(capsense_TOTAL_SENSOR_COUNT);
            capsense_UpdateEnabledBaselines();
            capsense_ScanEnabledWidgets();
            updateCapsense();
        }
         CyBle_ProcessEvents();
        CyBle_EnterLPM(CYBLE_BLESS_DEEPSLEEP);
    }
}


    /* [] END OF FILE */
