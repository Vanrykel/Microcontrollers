/***************************************************************************//**
* \file CYBLE_gatt.c
* \version 3.50
* 
* \brief
*  This file contains the source code for the GATT API of the BLE Component.
* 
********************************************************************************
* \copyright
* Copyright 2014-2018, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#include "BLE_eventHandler.h"


/***************************************
* Global variables
***************************************/

CYBLE_STATE_T cyBle_state;

#if ((CYBLE_MODE_PROFILE) && (CYBLE_BONDING_REQUIREMENT == CYBLE_BONDING_YES))
    
#if(CYBLE_MODE_PROFILE)
    #if defined(__ARMCC_VERSION)
        CY_ALIGN(CYDEV_FLS_ROW_SIZE) const CY_BLE_FLASH_STORAGE cyBle_flashStorage CY_SECTION(".cy_checksum_exclude") =
    #elif defined (__GNUC__)
        const CY_BLE_FLASH_STORAGE cyBle_flashStorage CY_SECTION(".cy_checksum_exclude")
            CY_ALIGN(CYDEV_FLS_ROW_SIZE) =
    #elif defined (__ICCARM__)
        #pragma data_alignment=CY_FLASH_SIZEOF_ROW
        #pragma location=".cy_checksum_exclude"
        const CY_BLE_FLASH_STORAGE cyBle_flashStorage =
    #endif  /* (__ARMCC_VERSION) */
    {
        { 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u }, 
        {{
            0x03u, 0x00u,
            0x03u, 0x00u,
            0x03u, 0x00u,
            0x03u, 0x00u,
        },
        {
            0x03u, 0x00u,
            0x03u, 0x00u,
            0x03u, 0x00u,
            0x03u, 0x00u,
        },
        {
            0x03u, 0x00u,
            0x03u, 0x00u,
            0x03u, 0x00u,
            0x03u, 0x00u,
        },
        {
            0x03u, 0x00u,
            0x03u, 0x00u,
            0x03u, 0x00u,
            0x03u, 0x00u,
        },
        {
            0x03u, 0x00u,
            0x03u, 0x00u,
            0x03u, 0x00u,
            0x03u, 0x00u,
        }}, 
        0x08u, /* CYBLE_GATT_DB_CCCD_COUNT */ 
        0x05u, /* CYBLE_GAP_MAX_BONDED_DEVICE */ 
    };
#endif /* (CYBLE_MODE_PROFILE) */

#endif  /* (CYBLE_MODE_PROFILE) && (CYBLE_BONDING_REQUIREMENT == CYBLE_BONDING_YES) */

#if(CYBLE_GATT_ROLE_SERVER)
    
    const CYBLE_GATTS_T cyBle_gatts =
{
    0x000Cu,    /* Handle of the GATT service */
    0x000Eu,    /* Handle of the Service Changed characteristic */
    0x000Fu,    /* Handle of the Client Characteristic Configuration descriptor */
};
    
    static uint8 cyBle_attValues[0x4Eu] = {
    /* Device Name */
    (uint8)'B', (uint8)'L', (uint8)'E', (uint8)'_', (uint8)'C', (uint8)'A', (uint8)'R', (uint8)'T',

    /* Appearance */
    0x80u, 0x01u,

    /* Peripheral Preferred Connection Parameters */
    0x3Cu, 0x00u, 0x40u, 0x00u, 0x00u, 0x00u, 0xFFu, 0xFFu,

    /* Central Address Resolution */
    0x00u,

    /* Resolvable Private Address Only */
    0x00u,

    /* Service Changed */
    0x00u, 0x00u, 0x00u, 0x00u,

    /* SPEED */
    0x00u, 0x00u,

    /* Characteristic User Description */
    (uint8)'s', (uint8)'p', (uint8)'e', (uint8)'e', (uint8)'d',

    /* ACCELERATION */
    0x00u, 0x00u,

    /* Characteristic User Description */
    (uint8)'a', (uint8)'c', (uint8)'c', (uint8)'e', (uint8)'l', (uint8)'e', (uint8)'r', (uint8)'a', (uint8)'t',
    (uint8)'i', (uint8)'o', (uint8)'n',

    /* Direction */
    0x00u, 0x00u,

    /* Characteristic User Description */
    (uint8)'d', (uint8)'i', (uint8)'r', (uint8)'e', (uint8)'c', (uint8)'t', (uint8)'i', (uint8)'o', (uint8)'n',

    /* Temperature */
    0x00u, 0x00u,

    /* Characteristic User Description */
    (uint8)'t', (uint8)'e', (uint8)'m', (uint8)'p', (uint8)'e', (uint8)'r', (uint8)'a', (uint8)'t', (uint8)'u',
    (uint8)'r', (uint8)'e',

    /* Current */
    0x00u, 0x00u,

    /* Characteristic User Description */
    (uint8)'c', (uint8)'u', (uint8)'r', (uint8)'r', (uint8)'e', (uint8)'n', (uint8)'t',

};
#if(CYBLE_GATT_DB_CCCD_COUNT != 0u)
uint8 cyBle_attValuesCCCD[CYBLE_GATT_DB_CCCD_COUNT];
#endif /* CYBLE_GATT_DB_CCCD_COUNT != 0u */

const uint8 cyBle_attUuid128[][16u] = {
    /* BLE_Motor */
    { 0x46u, 0xA8u, 0x63u, 0x8Eu, 0x7Au, 0xA6u, 0xEFu, 0x91u, 0xC1u, 0x4Eu, 0xA6u, 0x46u, 0xF7u, 0x91u, 0xABu, 0x99u },
    /* SPEED */
    { 0x4Au, 0x42u, 0xAAu, 0xDCu, 0x98u, 0x27u, 0x0Cu, 0x91u, 0xE2u, 0x41u, 0x25u, 0x04u, 0xEAu, 0x58u, 0x5Fu, 0x70u },
    /* ACCELERATION */
    { 0x04u, 0x95u, 0x38u, 0xFFu, 0x59u, 0xD3u, 0xAAu, 0xA2u, 0x4Fu, 0x43u, 0x45u, 0x03u, 0x08u, 0x31u, 0xFFu, 0x72u },
    /* Direction */
    { 0x2Au, 0x4Fu, 0x01u, 0xD4u, 0xFDu, 0xC4u, 0x46u, 0xB5u, 0xDBu, 0x40u, 0x54u, 0xEAu, 0x6Bu, 0x46u, 0x0Bu, 0xEAu },
    /* Temperature */
    { 0x5Cu, 0x3Du, 0x0Au, 0xFAu, 0x2Eu, 0x01u, 0x4Eu, 0x87u, 0xF5u, 0x4Au, 0x06u, 0xD6u, 0x90u, 0xCFu, 0x46u, 0x97u },
    /* Current */
    { 0xBAu, 0x62u, 0x46u, 0x8Eu, 0xE3u, 0x8Fu, 0xA8u, 0x87u, 0xBFu, 0x49u, 0x6Du, 0x04u, 0xD9u, 0xF7u, 0xE3u, 0xB7u },
};

CYBLE_GATTS_ATT_GEN_VAL_LEN_T cyBle_attValuesLen[CYBLE_GATT_DB_ATT_VAL_COUNT] = {
    { 0x0008u, (void *)&cyBle_attValues[0] }, /* Device Name */
    { 0x0002u, (void *)&cyBle_attValues[8] }, /* Appearance */
    { 0x0008u, (void *)&cyBle_attValues[10] }, /* Peripheral Preferred Connection Parameters */
    { 0x0001u, (void *)&cyBle_attValues[18] }, /* Central Address Resolution */
    { 0x0001u, (void *)&cyBle_attValues[19] }, /* Resolvable Private Address Only */
    { 0x0004u, (void *)&cyBle_attValues[20] }, /* Service Changed */
    { 0x0002u, (void *)&cyBle_attValuesCCCD[0] }, /* Client Characteristic Configuration */
    { 0x0010u, (void *)&cyBle_attUuid128[0] }, /* BLE_Motor UUID */
    { 0x0010u, (void *)&cyBle_attUuid128[1] }, /* SPEED UUID */
    { 0x0002u, (void *)&cyBle_attValues[24] }, /* SPEED */
    { 0x0005u, (void *)&cyBle_attValues[26] }, /* Characteristic User Description */
    { 0x0002u, (void *)&cyBle_attValuesCCCD[2] }, /* Client Characteristic Configuration */
    { 0x0010u, (void *)&cyBle_attUuid128[2] }, /* ACCELERATION UUID */
    { 0x0002u, (void *)&cyBle_attValues[31] }, /* ACCELERATION */
    { 0x000Cu, (void *)&cyBle_attValues[33] }, /* Characteristic User Description */
    { 0x0002u, (void *)&cyBle_attValuesCCCD[4] }, /* Client Characteristic Configuration */
    { 0x0010u, (void *)&cyBle_attUuid128[3] }, /* Direction UUID */
    { 0x0002u, (void *)&cyBle_attValues[45] }, /* Direction */
    { 0x0009u, (void *)&cyBle_attValues[47] }, /* Characteristic User Description */
    { 0x0002u, (void *)&cyBle_attValuesCCCD[6] }, /* Client Characteristic Configuration */
    { 0x0010u, (void *)&cyBle_attUuid128[4] }, /* Temperature UUID */
    { 0x0002u, (void *)&cyBle_attValues[56] }, /* Temperature */
    { 0x000Bu, (void *)&cyBle_attValues[58] }, /* Characteristic User Description */
    { 0x0010u, (void *)&cyBle_attUuid128[5] }, /* Current UUID */
    { 0x0002u, (void *)&cyBle_attValues[69] }, /* Current */
    { 0x0007u, (void *)&cyBle_attValues[71] }, /* Characteristic User Description */
};

const CYBLE_GATTS_DB_T cyBle_gattDB[0x22u] = {
    { 0x0001u, 0x2800u /* Primary service                     */, 0x00000001u /*           */, 0x000Bu, {{0x1800u, NULL}}                           },
    { 0x0002u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd        */, 0x0003u, {{0x2A00u, NULL}}                           },
    { 0x0003u, 0x2A00u /* Device Name                         */, 0x01020001u /* rd        */, 0x0003u, {{0x0008u, (void *)&cyBle_attValuesLen[0]}} },
    { 0x0004u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd        */, 0x0005u, {{0x2A01u, NULL}}                           },
    { 0x0005u, 0x2A01u /* Appearance                          */, 0x01020001u /* rd        */, 0x0005u, {{0x0002u, (void *)&cyBle_attValuesLen[1]}} },
    { 0x0006u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd        */, 0x0007u, {{0x2A04u, NULL}}                           },
    { 0x0007u, 0x2A04u /* Peripheral Preferred Connection Par */, 0x01020001u /* rd        */, 0x0007u, {{0x0008u, (void *)&cyBle_attValuesLen[2]}} },
    { 0x0008u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd        */, 0x0009u, {{0x2AA6u, NULL}}                           },
    { 0x0009u, 0x2AA6u /* Central Address Resolution          */, 0x01020001u /* rd        */, 0x0009u, {{0x0001u, (void *)&cyBle_attValuesLen[3]}} },
    { 0x000Au, 0x2803u /* Characteristic                      */, 0x00020001u /* rd        */, 0x000Bu, {{0x2AC9u, NULL}}                           },
    { 0x000Bu, 0x2AC9u /* Resolvable Private Address Only     */, 0x01020001u /* rd        */, 0x000Bu, {{0x0001u, (void *)&cyBle_attValuesLen[4]}} },
    { 0x000Cu, 0x2800u /* Primary service                     */, 0x00000001u /*           */, 0x000Fu, {{0x1801u, NULL}}                           },
    { 0x000Du, 0x2803u /* Characteristic                      */, 0x00200001u /* ind       */, 0x000Fu, {{0x2A05u, NULL}}                           },
    { 0x000Eu, 0x2A05u /* Service Changed                     */, 0x01200000u /* ind       */, 0x000Fu, {{0x0004u, (void *)&cyBle_attValuesLen[5]}} },
    { 0x000Fu, 0x2902u /* Client Characteristic Configuration */, 0x010A0101u /* rd,wr     */, 0x000Fu, {{0x0002u, (void *)&cyBle_attValuesLen[6]}} },
    { 0x0010u, 0x2800u /* Primary service                     */, 0x08000001u /*           */, 0x0022u, {{0x0010u, (void *)&cyBle_attValuesLen[7]}} },
    { 0x0011u, 0x2803u /* Characteristic                      */, 0x001A0001u /* rd,wr,ntf */, 0x0014u, {{0x0010u, (void *)&cyBle_attValuesLen[8]}} },
    { 0x0012u, 0x58EAu /* SPEED                               */, 0x091A0101u /* rd,wr,ntf */, 0x0014u, {{0x0002u, (void *)&cyBle_attValuesLen[9]}} },
    { 0x0013u, 0x2901u /* Characteristic User Description     */, 0x01020101u /* rd        */, 0x0013u, {{0x0005u, (void *)&cyBle_attValuesLen[10]}} },
    { 0x0014u, 0x2902u /* Client Characteristic Configuration */, 0x010A0101u /* rd,wr     */, 0x0014u, {{0x0002u, (void *)&cyBle_attValuesLen[11]}} },
    { 0x0015u, 0x2803u /* Characteristic                      */, 0x001A0001u /* rd,wr,ntf */, 0x0018u, {{0x0010u, (void *)&cyBle_attValuesLen[12]}} },
    { 0x0016u, 0x3108u /* ACCELERATION                        */, 0x091A0101u /* rd,wr,ntf */, 0x0018u, {{0x0002u, (void *)&cyBle_attValuesLen[13]}} },
    { 0x0017u, 0x2903u /* Characteristic User Description     */, 0x01020101u /* rd        */, 0x0017u, {{0x000Cu, (void *)&cyBle_attValuesLen[14]}} },
    { 0x0018u, 0x2904u /* Client Characteristic Configuration */, 0x010A0101u /* rd,wr     */, 0x0018u, {{0x0002u, (void *)&cyBle_attValuesLen[15]}} },
    { 0x0019u, 0x2803u /* Characteristic                      */, 0x001A0001u /* rd,wr,ntf */, 0x001Cu, {{0x0010u, (void *)&cyBle_attValuesLen[16]}} },
    { 0x001Au, 0x466Bu /* Direction                           */, 0x091A0101u /* rd,wr,ntf */, 0x001Cu, {{0x0002u, (void *)&cyBle_attValuesLen[17]}} },
    { 0x001Bu, 0x2907u /* Characteristic User Description     */, 0x01020101u /* rd        */, 0x001Bu, {{0x0009u, (void *)&cyBle_attValuesLen[18]}} },
    { 0x001Cu, 0x2908u /* Client Characteristic Configuration */, 0x010A0101u /* rd,wr     */, 0x001Cu, {{0x0002u, (void *)&cyBle_attValuesLen[19]}} },
    { 0x001Du, 0x2803u /* Characteristic                      */, 0x00020001u /* rd        */, 0x001Fu, {{0x0010u, (void *)&cyBle_attValuesLen[20]}} },
    { 0x001Eu, 0xCF90u /* Temperature                         */, 0x09020001u /* rd        */, 0x001Fu, {{0x0002u, (void *)&cyBle_attValuesLen[21]}} },
    { 0x001Fu, 0x2905u /* Characteristic User Description     */, 0x01020001u /* rd        */, 0x001Fu, {{0x000Bu, (void *)&cyBle_attValuesLen[22]}} },
    { 0x0020u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd        */, 0x0022u, {{0x0010u, (void *)&cyBle_attValuesLen[23]}} },
    { 0x0021u, 0xF7D9u /* Current                             */, 0x09020001u /* rd        */, 0x0022u, {{0x0002u, (void *)&cyBle_attValuesLen[24]}} },
    { 0x0022u, 0x2906u /* Characteristic User Description     */, 0x01020001u /* rd        */, 0x0022u, {{0x0007u, (void *)&cyBle_attValuesLen[25]}} },
};


#endif /* (CYBLE_GATT_ROLE_SERVER) */

#if(CYBLE_GATT_ROLE_CLIENT)
    
CYBLE_CLIENT_STATE_T cyBle_clientState;
CYBLE_GATTC_T cyBle_gattc;
CYBLE_GATT_ATTR_HANDLE_RANGE_T cyBle_gattcDiscoveryRange;
    
#endif /* (CYBLE_GATT_ROLE_CLIENT) */


#if(CYBLE_GATT_ROLE_SERVER)

/****************************************************************************** 
* Function Name: CyBle_GattsReInitGattDb
***************************************************************************//**
* 
*  Reinitializes the GATT database.
* 
*  \return
*  CYBLE_API_RESULT_T: A function result states if it succeeded or failed with
*  error codes:

*  Errors codes                          | Description
*  ------------                          | -----------
*  CYBLE_ERROR_OK						 | GATT database was reinitialized successfully.
*  CYBLE_ERROR_INVALID_STATE             | If the function is called in any state except CYBLE_STATE_DISCONNECTED.
*  CYBLE_ERROR_INVALID_PARAMETER         | If the Database has zero entries or is a NULL pointer.
* 
******************************************************************************/
CYBLE_API_RESULT_T CyBle_GattsReInitGattDb(void)
{
    CYBLE_API_RESULT_T apiResult;
    
    if(CyBle_GetState() == CYBLE_STATE_DISCONNECTED)
    {
        apiResult = CyBle_GattsDbRegister(cyBle_gattDB, CYBLE_GATT_DB_INDEX_COUNT, CYBLE_GATT_DB_MAX_VALUE_LEN);
    }
    else
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    
    return(apiResult);
}


/****************************************************************************** 
* Function Name: CyBle_GattsWriteEventHandler
***************************************************************************//**
* 
*  Handles the Write Request Event for GATT service.
* 
*  \param eventParam: The pointer to the data structure specified by the event.
* 
*  \return
*  CYBLE_GATT_ERR_CODE_T: A function returns one of the following status 
*  values.

*  Errors codes                          | Description
*  --------------------                  | -----------
*  CYBLE_GATT_ERR_NONE                   | Write is successful.
* 
******************************************************************************/
CYBLE_GATT_ERR_CODE_T CyBle_GattsWriteEventHandler(CYBLE_GATTS_WRITE_REQ_PARAM_T *eventParam)
{
    CYBLE_GATT_ERR_CODE_T gattErr = CYBLE_GATT_ERR_NONE;
    
    /* Client Characteristic Configuration descriptor write request */
    if(eventParam->handleValPair.attrHandle == cyBle_gatts.cccdHandle)
    {
        /* Store value to database */
        gattErr = CyBle_GattsWriteAttributeValue(&eventParam->handleValPair, 0u, 
                        &eventParam->connHandle, CYBLE_GATT_DB_PEER_INITIATED);
        
        if(gattErr == CYBLE_GATT_ERR_NONE)
        {
            if(CYBLE_IS_INDICATION_ENABLED_IN_PTR(eventParam->handleValPair.value.val))
            {
                CyBle_ApplCallback((uint32)CYBLE_EVT_GATTS_INDICATION_ENABLED, eventParam);
            }
            else
            {
                CyBle_ApplCallback((uint32)CYBLE_EVT_GATTS_INDICATION_DISABLED, eventParam);
            }
        }
        cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
    }
    return (gattErr);
}


#endif /* (CYBLE_GATT_ROLE_SERVER) */

#if(CYBLE_GATT_ROLE_CLIENT)

/****************************************************************************** 
* Function Name: CyBle_GattcStartDiscovery
***************************************************************************//**
* 
*  Starts the automatic server discovery process. 
*   
*   Discovery procedure is based on the user configuration. It discovers only services, characteristics, 
*   descriptors which were declared in the GATT database.
*   Discovery procedure has the following flow:
*   - discovering primary services by BLE Stack function CyBle_GattcDiscoverAllPrimaryServices();
*   - discovering included services by BLE Stack function CyBle_GattcFindIncludedServices();
*   - discovering characteristics for available services by BLE Stack function CyBle_GattcDiscoverAllCharacteristics();
*   - discovering characteristic descriptors by BLE Stack function CyBle_GattcDiscoverAllCharacteristicDescriptors();
*
*   During the discovery procedure the discovery-specific stack events are handled by the component 
*   and thus aren’t passed to the application callback: CYBLE_EVT_GATTC_READ_BY_GROUP_TYPE_RSP,
*   CYBLE_EVT_GATTC_READ_BY_TYPE_RSP, CYBLE_EVT_GATTC_FIND_INFO_RSP, CYBLE_EVT_GATTC_ERROR_RSP.              
*   
*   After the discovery procedure all information about available services is stored in CYBLE_DISC_SRVC_INFO_T structures,
*   and discovered attributes handles are stored in service-specific client structures, such as CYBLE_BASC_T for 
*   Battery Service or CYBLE_HRSC_T for Heart Rate Service.
*
*  \param connHandle: The handle which consists of the device ID and ATT connection ID.
* 
*  \return
*  CYBLE_API_RESULT_T : Return value indicates if the function succeeded or
*                        failed. Following are the possible error codes.
*
*   <table>	
*   <tr>
*	  <th>Errors codes</th>
*	  <th>Description</th>
*	</tr>
*	<tr>
*	  <td>CYBLE_ERROR_OK</td>
*	  <td>On successful operation</td>
*	</tr>
*	<tr>
*	  <td>CYBLE_ERROR_INVALID_PARAMETER</td>
*	  <td>'connHandle' value does not represent any existing entry.</td>
*	</tr>
*	<tr>
*	  <td>CYBLE_ERROR_INVALID_OPERATION</td>
*	  <td>The operation is not permitted</td>
*	</tr>
*   <tr>
*	  <td>CYBLE_ERROR_MEMORY_ALLOCATION_FAILED</td>
*	  <td>Memory allocation failed</td>
*	</tr>
*   <tr>
*	  <td>CYBLE_ERROR_INVALID_STATE</td>
*	  <td>If the function is called in any state except connected or discovered</td>
*	</tr>
*   </table>
*
*  \events
*   The following events may be generated after calling this function:
*   * CYBLE_EVT_GATTC_DISCOVERY_COMPLETE  - event is generated when the remote device was successfully discovered. 
*   * CYBLE_EVT_GATTC_ERROR_RSP  		- is generated if the device discovery has failed.
*   * CYBLE_EVT_GATTC_SRVC_DUPLICATION 	- is generated if duplicate service record was found during the server device
*        								  discovery.
*   * CYBLE_EVT_GATTC_CHAR_DUPLICATION 	- is generated if duplicate service's characteristic descriptor record was found
*        								  during the server device discovery.
*   * CYBLE_EVT_GATTC_DESCR_DUPLICATION - is generated if duplicate service's characteristic descriptor record was found
*        								  during the server device discovery.
*  
******************************************************************************/
CYBLE_API_RESULT_T CyBle_GattcStartDiscovery(CYBLE_CONN_HANDLE_T connHandle)
{
    uint8 j;
    CYBLE_API_RESULT_T apiResult;
    
    if((CyBle_GetState() != CYBLE_STATE_CONNECTED) || 
       ((CyBle_GetClientState() != CYBLE_CLIENT_STATE_CONNECTED) && 
        (CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED))) 
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else
    {
        /* Clean old discovery information */
        for(j = 0u; j < (uint8) CYBLE_SRVI_COUNT; j++)
        {
            (void)memset(&cyBle_serverInfo[j].range, 0, sizeof(cyBle_serverInfo[0].range));
        }

        cyBle_connHandle = connHandle;
        cyBle_gattcDiscoveryRange.startHandle = CYBLE_GATT_ATTR_HANDLE_START_RANGE;
        cyBle_gattcDiscoveryRange.endHandle = CYBLE_GATT_ATTR_HANDLE_END_RANGE;
        
        CyBle_ServiceInit();
        
        apiResult = CyBle_GattcDiscoverAllPrimaryServices(connHandle);

        if(apiResult == CYBLE_ERROR_OK)
        {
            CyBle_SetClientState(CYBLE_CLIENT_STATE_SRVC_DISCOVERING);
            cyBle_eventHandlerFlag |= CYBLE_AUTO_DISCOVERY;
        }
    }
    
    return (apiResult);
}


/****************************************************************************** 
* Function Name: CyBle_GattcStartPartialDiscovery
***************************************************************************//**
* 
*  Starts the automatic server discovery process as per the range provided
*  on a GATT Server to which it is connected. This function could be used for 
*  partial server discovery after indication received to the Service Changed
*  Characteristic Value. 
* 
*  \param connHandle: The handle which consists of the device ID and ATT connection ID.
*  \param startHandle: Start of affected attribute handle range.
*  \param endHandle: End of affected attribute handle range.
* 
*  \return
*	CYBLE_API_RESULT_T : Return value indicates if the function succeeded or
*                        failed. Following are the possible error codes.
*
*   <table>	
*   <tr>
*	  <th>Errors codes</th>
*	  <th>Description</th>
*	</tr>
*	<tr>
*	  <td>CYBLE_ERROR_OK</td>
*	  <td>On successful operation</td>
*	</tr>
*	<tr>
*	  <td>CYBLE_ERROR_INVALID_PARAMETER</td>
*	  <td>'connHandle' value does not represent any existing entry.</td>
*	</tr>
*	<tr>
*	  <td>CYBLE_ERROR_INVALID_OPERATION</td>
*	  <td>The operation is not permitted</td>
*	</tr>
*   <tr>
*	  <td>CYBLE_ERROR_MEMORY_ALLOCATION_FAILED</td>
*	  <td>Memory allocation failed</td>
*	</tr>
*   <tr>
*	  <td>CYBLE_ERROR_INVALID_STATE</td>
*	  <td>If the function is called in any state except connected or discovered</td>
*	</tr>
*   </table>
* 
*  \events
*  Two events may be generated after calling this function:
*  CYBLE_EVT_GATTC_DISCOVERY_COMPLETE or CYBLE_EVT_GATTC_ERROR_RSP.
*  The CYBLE_EVT_GATTC_DISCOVERY_COMPLETE event is 
*  generated when the remote device was successfully discovered. The
*  CYBLE_EVT_GATTC_ERROR_RSP is generated if the device discovery is failed.
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_GattcStartPartialDiscovery(CYBLE_CONN_HANDLE_T connHandle,
                        CYBLE_GATT_DB_ATTR_HANDLE_T startHandle, CYBLE_GATT_DB_ATTR_HANDLE_T endHandle)
{
    uint8 j;
    CYBLE_API_RESULT_T apiResult;
    
    if((CyBle_GetState() != CYBLE_STATE_CONNECTED) || 
       ((CyBle_GetClientState() != CYBLE_CLIENT_STATE_CONNECTED) && 
        (CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED))) 
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else
    {
        /* Clean old discovery information of affected attribute range */
        for(j = 0u; j < (uint8) CYBLE_SRVI_COUNT; j++)
        {
            if((cyBle_serverInfo[j].range.startHandle >= startHandle) &&
               (cyBle_serverInfo[j].range.startHandle <= endHandle))
            {
                (void)memset(&cyBle_serverInfo[j].range, 0, sizeof(cyBle_serverInfo[0].range));
            }
        }

        cyBle_connHandle = connHandle;
        cyBle_gattcDiscoveryRange.startHandle = startHandle;
        cyBle_gattcDiscoveryRange.endHandle = endHandle;

        CyBle_ServiceInit();

        apiResult = CyBle_GattcDiscoverPrimaryServices(connHandle, &cyBle_gattcDiscoveryRange);

        if(apiResult == CYBLE_ERROR_OK)
        {
            CyBle_SetClientState(CYBLE_CLIENT_STATE_SRVC_DISCOVERING);
            cyBle_eventHandlerFlag |= CYBLE_AUTO_DISCOVERY;
        }
    }
    
    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_GattcDiscoverCharacteristicsEventHandler
***************************************************************************//**
* 
*  This function is called on receiving a CYBLE_EVT_GATTC_READ_BY_TYPE_RSP
*  event. Based on the service UUID, an appropriate data structure is populated
*  using the data received as part of the callback.
* 
*  \param discCharInfo: The pointer to a characteristic information structure.
* 
* \return
*  None
* 
******************************************************************************/
void CyBle_GattcDiscoverCharacteristicsEventHandler(CYBLE_DISC_CHAR_INFO_T *discCharInfo)
{
    if(discCharInfo->uuid.uuid16 == CYBLE_UUID_CHAR_SERVICE_CHANGED)
    {
        CyBle_CheckStoreCharHandle(cyBle_gattc.serviceChanged);
    }
}


/******************************************************************************
* Function Name: CyBle_GattcDiscoverCharDescriptorsEventHandler
***************************************************************************//**
* 
*  This function is called on receiving a "CYBLE_EVT_GATTC_FIND_INFO_RSP" event.
*  Based on the descriptor UUID, an appropriate data structure is populated 
*  using the data received as part of the callback.
* 
*  \param discDescrInfo: The pointer to a descriptor information structure.
*  \param discoveryService: The index of the service instance
* 
* \return
*  None
* 
******************************************************************************/
void CyBle_GattcDiscoverCharDescriptorsEventHandler(CYBLE_DISC_DESCR_INFO_T *discDescrInfo)
{
    if(discDescrInfo->uuid.uuid16 == CYBLE_UUID_CHAR_CLIENT_CONFIG)
    {
        CyBle_CheckStoreCharDescrHandle(cyBle_gattc.cccdHandle);
    }
}


/******************************************************************************
* Function Name: CyBle_GattcIndicationEventHandler
***************************************************************************//**
* 
*  Handles the Indication Event.
* 
*  \param eventParam: The pointer to the data structure specified by the event.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_GattcIndicationEventHandler(CYBLE_GATTC_HANDLE_VALUE_IND_PARAM_T *eventParam)
{
    if(cyBle_gattc.serviceChanged.valueHandle == eventParam->handleValPair.attrHandle)
    {
        CyBle_ApplCallback((uint32)CYBLE_EVT_GATTC_INDICATION, eventParam);
        cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
    }
}


#endif /* (CYBLE_GATT_ROLE_CLIENT) */


/* [] END OF FILE */
