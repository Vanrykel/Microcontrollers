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

// Event handler
void stackHandler(uint32 eventCode, void *eventParam);
void iasHandler(uint32 eventCode, void *eventParam);

void stackHandler(uint32 eventCode, void *eventParam)
{
    switch (eventCode)
    {
        case CYBLE_EVT_STACK_ON:
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            break;
    }
}

void iasHandler(uint32 eventCode, void *eventParam)
{
    CYBLE_IAS_CHAR_VALUE_T *param = (CYBLE_IAS_CHAR_VALUE_T *) eventParam;
    
    if (*param->value->val == 0)
    {
        PWM_LED_WriteCompare(0);
    }
    else if (*param->value->val == 1)
    {
        PWM_LED_WriteCompare(500);
    }
    else
    {
        PWM_LED_WriteCompare(1000);
    }
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    CyBle_Start(stackHandler);
    CyBle_IasRegisterAttrCallback(iasHandler);
    
    PWM_LED_Start();
    
    for(;;)
    {
        /* Place your application code here. */
        CyBle_ProcessEvents();
    }
}

/* [] END OF FILE */
