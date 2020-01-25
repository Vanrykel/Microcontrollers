#include <string.h>
#include "./cypress/device.h"
#include "./cypress/cybtldr_parse.h"
#include "./cypress/cybtldr_command.h"
//#include "./cypress/communication_api.h"
#include "./cypress/cybtldr_api.h"
#include "./cypress/StringImage.h"

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  delay(100);
}

/* Macros to choose among PSoC 3, PSoC 4 and PSoC 5LP as a target device */
#define PSoC_4     2
/* If your target device is PSoC 4 or PSoC 5LP, change the value of this Macro
   to "PSoC_4" or "PSoC_5LP" respectively */
#define TARGET_DEVICE PSoC_4

/* This function bootloads the .cyacd file. It sends command packets and 
   flash data to the target. Based on the response from the target, it decides
   whether to continue bootloading or end it. */
uint16 BootloadStringImage(const char *bootloadImagePtr[],unsigned int lineCount );

/* This structure contains function pointers to the four communication layer 
   functions contained in the communication_api.c / .h */
CyBtldr_CommunicationsData comm1 ;

/* toggle alternates between the two bootloadable files 
   (Hello and Bye) of (Green and Blue) */
uint8 toggle = 0;


void loop()
{
    /* error holds the success / failure message of the bootload operation */
  uint16 error = 0;

  /* Initialize the communication structure element -comm1 */
  //comm1.OpenConnection = &OpenConnection;
  //comm1.CloseConnection = &CloseConnection;
  //comm1.ReadData = &ReadData;
  //comm1.WriteData =&WriteData;
  //comm1.MaxTransferSize =64;
        
    while(1) {
      error = BootloadStringImage(stringImage_5,LINE_CNT_5);
      
      if (error == CYRET_SUCCESS) {
        digitalWrite(LED_BUILTIN, LOW);   
        delay(1000);                      
        digitalWrite(LED_BUILTIN, HIGH);  
        delay(2000); 
      }
    }
    return;
} 


/****************************************************************************************************
* Function Name: BootloadStringImage
*****************************************************************************************************
*
* Summary:
*  Bootloads the .cyacd file contents which is stored as string array
*
* Parameters:  
* bootloadImagePtr - Pointer to the string array
* lineCount - No. of lines in the .cyacd file(No: of rows in the string array)
*
* Return: 
*  Returns a flag to indicate whether the bootload operation was successful or not
*
*
****************************************************************************************************/
uint16 BootloadStringImage(const char *bootloadImagePtr[],unsigned int lineCount )
{
  uint16 err=0;
  unsigned char arrayId; 
  unsigned short rowNum;
  unsigned short rowSize; 
  unsigned char checksum ;
  unsigned char checksum2;
  unsigned long blVer=0;
  /* rowData buffer size should be equal to the length of data to be sent for
  *  each flash row. It equals 288 , if ECC  is disabled in the bootloadable project,
  *  else 255 (in the case of PSoC 4 the flash row size is 128) */
  unsigned char rowData[288];
  unsigned int lineLen;
  unsigned long  siliconID;
  unsigned char siliconRev;
  unsigned char packetChkSumType;
  unsigned int lineCntr ;
  
  /* Initialize line counter */
  lineCntr = 0;
  
  /* Get length of the first line in cyacd file*/
  lineLen = strlen(bootloadImagePtr[lineCntr]);
  
  /* Parse the first line(header) of cyacd file to extract 
     siliconID, siliconRev and packetChkSumType */
  err = CyBtldr_ParseHeader(lineLen ,(unsigned char *)bootloadImagePtr[lineCntr] , &siliconID , &siliconRev ,&packetChkSumType);
      
  /* Set the packet checksum type for communicating with bootloader. 
     The packet checksum type to be used is determined from the 
     cyacd file header information */
  //CyBtldr_SetCheckSumType((CyBtldr_ChecksumType)packetChkSumType);
  
  if(err==CYRET_SUCCESS)
  {
    /* Start Bootloader operation */
    err = CyBtldr_StartBootloadOperation(&comm1 ,siliconID, siliconRev ,&blVer);
    lineCntr++ ;
    while((err == CYRET_SUCCESS)&& ( lineCntr <  lineCount ))
    {
    
            /* Get the string length for the line*/
      lineLen =  strlen(bootloadImagePtr[lineCntr]);
      
      /*Parse row data*/
      err = CyBtldr_ParseRowData((unsigned int)lineLen,(unsigned char *)bootloadImagePtr[lineCntr], &arrayId, &rowNum, rowData, &rowSize, &checksum);
            
      
      if (CYRET_SUCCESS == err)
            {
        /* Program Row */
        err = CyBtldr_ProgramRow(arrayId, rowNum, rowData, rowSize);
        
              if (CYRET_SUCCESS == err)
        {
          /* Verify Row . Check whether the checksum received from bootloader matches
          * the expected row checksum stored in cyacd file*/
          checksum2 = (unsigned char)(checksum + arrayId + rowNum + (rowNum >> 8) + rowSize + (rowSize >> 8));
          err = CyBtldr_VerifyRow(arrayId, rowNum, checksum2);
        }
            }
      /* Increment the linCntr */
      lineCntr++;
    }
    /* End Bootloader Operation */
    CyBtldr_EndBootloadOperation();
  }
  return(err);

}


/* [] END OF FILE */

