
#include "project.h"

int16 i =0;
int distance = 0;
int speed = 0; //Speed from the cart from 0 to 100

void fullstop();
void safetyslowdown();

static int correctieLinks = 500;
static int correctieRechts = 500;

uint16 fingerPos = 0xFFFF;
uint16 fingerPosOld = 0xFFFF; 

int loc = 0;


CY_ISR(Timer_ISR_handler)
{  
    Timer_ClearInterrupt(Timer_INTR_MASK_CC_MATCH);
    i= Timer_ReadCounter();    
    // from HC 04 Ultra Sonic module's datasheet, each 58 uS = 1 cm
    
    distance =i/58;
    // please note that measured distance above 400 cm is not reliable
    Trigger_Write(1);
    CyDelayUs(10);
    // for 10 uS
    Trigger_Write(0);
}

CY_ISR(speedLeftFunc)
{
        loc++;
}
CY_ISR(speedRightFunc)
{
        loc--;   
}

void fullstop()
{
    if ( distance == 30 )
    {
        correctieLinks= 0;  
        correctieRechts =0; 
    }
}

void safetyslowdown() // reduce the cart his speed when it comes within a meter. 
{
    int tempDistance = speed % 2;
    if (distance == 100)
    {
        for(int i = 0; i < tempDistance ; i++)
        {
            correctieLinks--;
            correctieRechts--; 
        }
    }
}


// wanneer deze functie wordt opgeroepen -> pak status led -> steek in database
void updateLeft()
{
    // is voor temphandle tussenfuncties te maken
    CYBLE_GATTS_HANDLE_VALUE_NTF_T tempHandle;
    int left = (!red_Read());
    
    // als de bluetooth niet cnnected is stop dan 
    if ( CyBle_GetState() !=CYBLE_STATE_CONNECTED)
    return; 
    
    // char die led noemt linken aan de tempHandle
    tempHandle.attrHandle = CYBLE_LEDCAPSENSE_LEFT_CHAR_HANDLE;
    
    //lees de waarde van de pin en toggle het omdat het actief laag is ( voor android logischer te maken ) 
    tempHandle.value.val = ( uint8 * ) &left;
    
    //het is 1 byte 
    tempHandle.value.len = 1;
    
    // schrijf het in de database 
    CyBle_GattsWriteAttributeValue(&tempHandle, 0, &cyBle_connHandle, 0); 
}
void updateRight()
{
    // is voor temphandle tussenfuncties te maken
    CYBLE_GATTS_HANDLE_VALUE_NTF_T tempHandle;
    int right = (!yellow_Read());
    
    // als de bluetooth niet cnnected is stop dan 
    if ( CyBle_GetState() !=CYBLE_STATE_CONNECTED)
    return; 
    
    // char die led noemt linken aan de tempHandle
    tempHandle.attrHandle = CYBLE_LEDCAPSENSE_RIGHT_CHAR_HANDLE;
    
    //lees de waarde van de pin en toggle het omdat het actief laag is ( voor android logischer te maken ) 
    tempHandle.value.val = ( uint8 * ) &right;
    
    //het is 1 byte 
    tempHandle.value.len = 1;
    
    // schrijf het in de database 
    CyBle_GattsWriteAttributeValue(&tempHandle, 0, &cyBle_connHandle, 0); 
}

void updateUp()
{
    // is voor temphandle tussenfuncties te maken
    CYBLE_GATTS_HANDLE_VALUE_NTF_T tempHandle;
    int up = (!yellow_Read());
    
    // als de bluetooth niet cnnected is stop dan 
    if ( CyBle_GetState() !=CYBLE_STATE_CONNECTED)
    return; 
    
    // char die led noemt linken aan de tempHandle
    tempHandle.attrHandle = CYBLE_LEDCAPSENSE_UP_CHAR_HANDLE;
    
    //lees de waarde van de pin en toggle het omdat het actief laag is ( voor android logischer te maken ) 
    tempHandle.value.val = ( uint8 * ) &up;
    
    //het is 1 byte 
    tempHandle.value.len = 1;
    
    // schrijf het in de database 
    CyBle_GattsWriteAttributeValue(&tempHandle, 0, &cyBle_connHandle, 0); 
}

void updateDown()
{
    // is voor temphandle tussenfuncties te maken
    CYBLE_GATTS_HANDLE_VALUE_NTF_T tempHandle;
    int down = (!red_Read());
    
    // als de bluetooth niet cnnected is stop dan 
    if ( CyBle_GetState() !=CYBLE_STATE_CONNECTED)
    return; 
    
    // char die led noemt linken aan de tempHandle
    tempHandle.attrHandle = CYBLE_LEDCAPSENSE_DOWN_CHAR_HANDLE;
    
    //lees de waarde van de pin en toggle het omdat het actief laag is ( voor android logischer te maken ) 
    tempHandle.value.val = ( uint8 * ) &down;
    
    //het is 1 byte 
    tempHandle.value.len = 1;
    
    // schrijf het in de database 
    CyBle_GattsWriteAttributeValue(&tempHandle, 0, &cyBle_connHandle, 0); 
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
            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            pwm_Start();
        break;
            
        // Wanneer connectie vanuit gsm is geactiveerd => alle vars updaten 
        case CYBLE_EVT_GATT_CONNECT_IND:
            
            updateLeft();
            updateRight();
            updateUp();
            updateDown();
            pwm_Stop();       
        break;
           
        // Wanner gsm iets in de database wil schrijven 
        case CYBLE_EVT_GATTS_WRITE_REQ :
       
            wrReqParam = (CYBLE_GATTS_WRITE_CMD_REQ_PARAM_T *) eventParam; 
            // kijken of de gsm de LED wilt veranderen
       
            if (wrReqParam->handleValPair.attrHandle == CYBLE_LEDCAPSENSE_LEFT_CHAR_HANDLE)
            {
                
                // kijken of het mag 
                if (CYBLE_GATT_ERR_NONE == CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair,0, &cyBle_connHandle, CYBLE_GATT_DB_PEER_INITIATED))
                {
                    //red_Write(!wrReqParam->handleValPair.value.val[0]);
                    uint16 links = wrReqParam->handleValPair.value.val[0] ;
                    if (links != 0 ) 
                    {                       
                        yellow_Write(0); 
                        pwm_rechts_Start();                      
                    }
                    else 
                    {
                        yellow_Write(1); 
                        pwm_rechts_Stop();                      
                    }
                 
                    // response terug geven 
                    CyBle_GattsWriteRsp(cyBle_connHandle);
                    
                }
            }
             if (wrReqParam->handleValPair.attrHandle == CYBLE_LEDCAPSENSE_RIGHT_CHAR_HANDLE)
            {
                // kijken of het mag 
                if (CYBLE_GATT_ERR_NONE == CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair,0, &cyBle_connHandle, CYBLE_GATT_DB_PEER_INITIATED))
                {
                    //yellow_Write(!wrReqParam->handleValPair.value.val[0]);
                    uint16 rechts = wrReqParam->handleValPair.value.val[0] ;
                    if (rechts != 0 ) 
                    {
                        red_Write(0);
                        yellow_Write(0); 
                        pwm_links_Start();
                        
                    }
                    else 
                    {
                        red_Write(1);
                        yellow_Write(1); 
                        pwm_links_Stop(); 
                    }
                 
                    // response terug geven 
                    CyBle_GattsWriteRsp(cyBle_connHandle);
                    
                }
            }  
            
            if (wrReqParam->handleValPair.attrHandle == CYBLE_LEDCAPSENSE_UP_CHAR_HANDLE)
            {
                // kijken of het mag 
                if (CYBLE_GATT_ERR_NONE == CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair,0, &cyBle_connHandle, CYBLE_GATT_DB_PEER_INITIATED))
                {
                  //  yellow_Write(!wrReqParam->handleValPair.value.val[0]);
                    uint16 vooruit = wrReqParam->handleValPair.value.val[0] ;
                    if (vooruit != 0 ) 
                    {
                        red_Write(0);
                        pwm_links_Start();
                        pwm_links_WriteCompare(correctieLinks);
                        pwm_rechts_Start(); 
                        pwm_rechts_WriteCompare(correctieRechts);
                        pwm_rechts_WriteCompare(200);
                    }
                    else 
                    {
                        red_Write(1);
                        pwm_links_Stop();
                        pwm_rechts_Stop();
                       
                    }
                    // response terug geven 
                    CyBle_GattsWriteRsp(cyBle_connHandle);
               }
            }
    
            if (wrReqParam->handleValPair.attrHandle == CYBLE_LEDCAPSENSE_DOWN_CHAR_HANDLE)
            {
                // kijken of het mag 
                if (CYBLE_GATT_ERR_NONE == CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair,0, &cyBle_connHandle, CYBLE_GATT_DB_PEER_INITIATED))
                {
                    //yellow_Write(!wrReqParam->handleValPair.value.val[0]);
                     uint16 achteruit = wrReqParam->handleValPair.value.val[0] ;
                    if (achteruit != 0 ) 
                    {
                        DIRL_Write(1);
                        DIRR_Write(1);
                        red_Write(0);
                        pwm_links_Start();
                        pwm_links_WriteCompare(correctieLinks);
                        pwm_rechts_Start();
                        pwm_rechts_WriteCompare(correctieRechts); 
                        
                    }
                    else 
                    {
                        DIRL_Write(0);
                        DIRR_Write(0);
                        red_Write(1);
                        pwm_links_Stop();
                        pwm_rechts_Stop(); 
                    }
                }
            }
                 
                    // response terug geven 
                    CyBle_GattsWriteRsp(cyBle_connHandle);   
           
            default: 
            break; 
    }   
}
           
int main(void)
{
    CyGlobalIntEnable; 
    
    CyBle_Start(BleCallBack);
    
    
    isr_1_StartEx(speedLeftFunc);
    isr_2_StartEx(speedRightFunc);

    
    for(;;)
    {
        void safetyslowdown();
        void fullstop();
        
        // Triggers the Ultra Sonic Sensor 
        Trigger_Write(1);    
        CyDelayUs(10);
        // for 10 uS
        Trigger_Write(0);
        
        fullstop();
        safetyslowdown();

        CyBle_ProcessEvents();
        CyBle_EnterLPM(CYBLE_BLESS_DEEPSLEEP);
    }
}



  
  

