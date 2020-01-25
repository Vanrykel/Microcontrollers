#include <cybtldr_api.h>
#include <cybtldr_command.h>
#include <cybtldr_parse.h>
#include <cybtldr_utils.h>
#include <communication_api.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h> 
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

#define SERIAL_TX_BUFFER_SIZE 64
#define SERIAL_RX_BUFFER_SIZE 64

#ifdef DEBUG_ESP_PORT
#define DEBUG_MSG(...) DEBUG_ESP_PORT.printf( __VA_ARGS__ )
#else
#define DEBUG_MSG(...)
#endif

#define TARGET_DEVICE PSoC_4

ESP8266WiFiMulti wifiMulti;     // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'
ESP8266WebServer server(8080);    // Create a webserver object that listens for HTTP request on port 8080

CyBtldr_CommunicationsData comm1;

uint16 BootloadStringImage(const char * bootloadImagePtr[],unsigned int lineCount )
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
  DEBUG_MSG("Initialization of variables\n");
  /* Parse the first line(header) of cyacd file to extract 
     siliconID, siliconRev and packetChkSumType */
  err = CyBtldr_ParseHeader(lineLen ,(unsigned char *)bootloadImagePtr[lineCntr] , &siliconID , &siliconRev ,&packetChkSumType);
  DEBUG_MSG("Header parsed\n");
  /* Set the packet checksum type for communicating with bootloader. 
     The packet checksum type to be used is determined from the 
     cyacd file header information */
  CyBtldr_SetCheckSumType((CyBtldr_ChecksumType)packetChkSumType);
  DEBUG_MSG("ChecksumType set \n");
  if(err==CYRET_SUCCESS)
  {
    DEBUG_MSG("succes\n");
    
    /* Start Bootloader operation */
    err = CyBtldr_StartBootloadOperation(&comm1 ,siliconID, siliconRev ,&blVer);
    DEBUG_MSG("Bootloadoperation succes \n");
    lineCntr++ ;
    
    while((err == CYRET_SUCCESS)&& ( lineCntr <  lineCount ))
    {
    
            /* Get the string length for the line*/
      lineLen =  strlen(bootloadImagePtr[lineCntr]);
      
      /*Parse row data*/
      err = CyBtldr_ParseRowData((unsigned int)lineLen,(unsigned char *)bootloadImagePtr[lineCntr], &arrayId, &rowNum, rowData, &rowSize, &checksum);
        
      DEBUG_MSG("ParseRowData complete \n");
      if (CYRET_SUCCESS == err)
            {
              Serial1.write("succes\n");
        /* Program Row */
        err = CyBtldr_ProgramRow(arrayId, rowNum, rowData, rowSize);
        DEBUG_MSG("Row programmed \n");
              if (CYRET_SUCCESS == err)
        {
          /* Verify Row . Check whether the checksum received from bootloader matches
          * the expected row checksum stored in cyacd file*/
          DEBUG_MSG("Succes\n");
          checksum2 = (unsigned char)(checksum + arrayId + rowNum + (rowNum >> 8) + rowSize + (rowSize >> 8));
          err = CyBtldr_VerifyRow(arrayId, rowNum, checksum2);
        }
            }
            DEBUG_MSG("End of program");
      /* Increment the linCntr */
      lineCntr++;
    }
    /* End Bootloader Operation */
    CyBtldr_EndBootloadOperation();
  }
  return(err);

}
const char *stringImage_6[] = {"04C811931100",
":00002C00800010002011160000011800000118000080B500AF024B83F3088800F0F5F8C0460010002080B500AF0F4B0F4A12688021C9020A431A60182000F0CEF90A4B0A4A12680A490A401A60094B0A4A1A600A4B802212061A60044B00221A60074B00221A60BD4680BDC04600010B40FFFFFBFF04010B400600008008010B400C020B4083",
":00002D008080B582B000AF72B6FB1D00221A7023E0FB1D1A78131C5B009B185B002C4A9B183B603B681A78597809020A43997809040A43DB781B061343191C3B681A795B791B0213439BB2081C191C00F023F9FB1D1A78FB1D01321A70FB1D1B78012BD7D91C4BEE2212021A601B4B992212041A601A4B992212041A60194A194B1B78DBB2FE",
":00002E008002210B43DBB21370164A164B1B78DBB23C218B43DBB214210B43DBB21370104A0F4B1B78DBB216210B43DBB213700E4B80221A600D4B0E4A1A600E4BD82212011A60FFF76FFF00F0F5F8BD4602B080BDF01C00000C00014000500F4030500F4000700F4001700F400000044008000440800140000803044010B5064C2378002BC7",
":00002F008007D1054B002B02D0044800E000BF0123237010BDE800002000000000EC1C000008B5084B002B03D00748084900E000BF07480368002B00D108BD064B002BFBD09847F9E700000000EC1C0000EC000020D00000200000000080B500AF00F0D4F8031CDB43DBB2181C00F0A8F8642000F003FA00F0D7F8031E01D100F0E1F8EDE7ED",
":000030008080B500AFFEE7C04680B586B000AF224B7B61224B3B61204B7B6135E03B691B68FB603B695B68BB603B699B683B6000237B600CE0FB681A68BB681A60BB680433BB60FB680433FB607B6804337B607A683B689A42EED13B69DB683B6000237B6008E0BB6800221A60BB680433BB607B6804337B607A683B689A42F2D13B691033EC",
":00003100803B617B69013B7B617B69002BC6D100F0FFF9FFF7A1FFFEE701000000501D000080B582B000AF00237B600FE07B68032B04D8134B7A689200D35800E0114B124A796889008B507B6801337B607B682F2BECD9FFF7D5FE0D4B00221A600C4B1B68002B02D10A4B00221A608023DB058022D205126801210A431A60BD4602B080BDAB",
":0000320080001600000118000000000020C8000020C000002080B582B000AF786039607A683B68101C00211A1C00F0D8F9BD4602B080BDC04680B500AFBD4680BD80B584B000AF021CFB1D1A700E4B1B68DAB20F23FB1804218A431A70FB1D1B789B00DBB204221340D9B20F23FB180F22BA1812780A431A70034B0F22BA1812781A60BD46F2",
":000033008004B080BD0000044080B500AF044B1B68042213409B08DBB2181CBD4680BDC0460400044080B500AF044B1B6880221340DB09DBB2181CBD4680BDC0460400044080B500AF034B40221A6000F005F9BD4680BDC046C000002090B585B000AF78600C23FC1800F04AF9031C23707B68022B00D8B4E07B68302B00D9B0E05E4B1B786F",
":0000340080DBB21A1E7B689A420AD35C4A0F23FB1812781A705A4A0E23FB1812781A703FE0584B1B78DBB21A1E7B689A420AD3564A0F23FB1812781A70544A0E23FB1812781A702DE0524B1B78DBB21A1E7B689A420AD3504A0F23FB1812781A704E4A0E23FB1812781A701BE04C4B1B78DBB21A1E7B689A420AD34A4A0F23FB1812781A7057",
":0000350080484A0E23FB1812781A7009E0464A0F23FB1812781A70454A0E23FB1812781A707B68DA1E0B23FB1841498A5C1A700B23FB181B782F2B0DD97B682A2B0AD93D4B19221A60052000F0CFF80D23FB1819221A7007E0374B1B68DAB20D23FB183F210A401A700B23FA180D23FB1812781B789A4208D22F4B7A68033A2D498A5C1A608E",
":0000360080052000F0B1F87B68284A9A180A23FB1812781A70284B0A22BA1812781A60274B0F22BA1812781A60254B0E22BA1812781A60052000F084F80B23FA180D23FB1812781B789A4209D91A4B7A68033A18498A5C1A60052000F087F803E002E0002000F030F80C23FB181B78181C00F08AF8BD4605B090BDC046C0F1FF0FC1F1FF0F03",
":0000370080C2F1FF0FC3F1FF0FC4F1FF0FC5F1FF0FC6F1FF0FC7F1FF0FC8F1FF0FC9F1FF0FCAF1FF0FCBF1FF0FCCF1FF0FCDF1FF0FFC1C00002CFF0B4028FF0B401CFF0B4020FF0B4080B582B000AF021CFB1D1A7001BEBD4602B080BD80B500AF044B044A12681204120C03490A431A60BD4680BD0CED00E00400FA0580B582B000AF786058",
":000038008009E00C4B1B68181C00F02EF87B680A4A944663447B607A6880231B029A42F0D8064B1B687A685343181C00F01DF8BD4602B080BDE00000200080FFFFD800002080B582B000AF021CBB1D1A80BB1D1B88044A12785343181C00F006F8BD4602B080BDC046DC0000200230800804D0C0460138FDD1C046C046C0467047EFF31080FA",
":000039008072B6704780F310887047C046C046C0460E4B70B500251E1C0D4CE41AA410A54204D0AB00F35898470135F8E700F03EF8084B00251E1C084CE41AA410A54204D0AB00F35898470135F8E770BD381D0000381D0000381D0000401D0000031C8218934202D019700133FAE770470000000000300F40000400400F400004030405061E",
":00003A00800708090A0B0C0E0F101112131415161718191B1C1D1E1F2021222325262728292A2B2E2F3031323334350000F8B5C046F8BC08BC9E467047A1170000A1180000F8B5C046F8BC08BC9E46704779170000601D0000D000002018000000200000000000000000366E01C05D0000180000000000E02E0000000000000000000000004E",
":0000FF00800000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000050111600002B0000008007000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000058"
};


void setup(void){
Serial1.begin(115200); // Start the Serial communication to send messages to the computer
Serial1.write("start\n");
       
  delay(10);
  Serial.println('\n');

  wifiMulti.addAP("WiFi-2.4-10C8", "****");   // add Wi-Fi networks you want to connect to
  wifiMulti.addAP("wifi.pxl-ea-ict.be", "elektronica");
  wifiMulti.addAP("linksys", "****");

  Serial.println("Connecting ...");
  int i = 0;
  while (wifiMulti.run() != WL_CONNECTED) { // Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
    delay(250);
    Serial.print('.');
  }
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());               // Tell us what network we're connected to
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());            // Send the IP address of the ESP8266 to the computer

  if (MDNS.begin("esp8266")) {              // Start the mDNS responder for esp8266.local
    Serial.println("mDNS responder started");
  } else {
    Serial.println("Error setting up MDNS responder!");
  }

  server.on("/", HTTP_GET, handleRoot);        // Call the 'handleRoot' function when a client requests URI "/"
  server.on("/login", HTTP_POST, handleLogin); // Call the 'handleLogin' function when a POST request is made to URI "/login"
  server.onNotFound(handleNotFound);           // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"

  server.begin();                            // Actually start the server
  Serial.println("HTTP server started");
}

void loop(){
server.handleClient();                     // Listen for HTTP requests from clients
//char * bootloadImagePtr[];
//server.arg("HEX-code").toCharArray(bootloadImagePtr[], 20);
delay(2000);
BootloadStringImage(stringImage_6,17);
}

void handleRoot() {                          // When URI / is requested, send a web page with a button to toggle the LED
  server.send(200, "text/html", "<form action=\"/login\" method=\"POST\"><input type=\"text\" name=\"HEX-code\" placeholder=\"HEX-code\"></br><input type=\"submit\" value=\"upload\"></form><p>Upload your HEX-code ...</p>");
}

void handleLogin() {                         // If a POST request is made to URI /login
if(server.arg("HEX-code") == NULL) { // If the POST request has no content
    server.send(400, "text/plain", "400: Invalid Request");         // The request is invalid, so send HTTP status 400
    return;
  }
  if(server.arg("HEX-code") != NULL) { // If POST request has content
    server.send(200, "text/html", "<h1>hex code:<br> " + server.arg("HEX-code") + "</h1><p>this is your hex code</p>"); //print HEX-code
  } else {                                                                              // Username and password don't match
    server.send(401, "text/plain", "401: Unauthorized");
  }

//char * bootloadImagePtr[];
//server.arg("HEX-code").toCharArray(bootloadImagePtr[], 20);
  
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}
