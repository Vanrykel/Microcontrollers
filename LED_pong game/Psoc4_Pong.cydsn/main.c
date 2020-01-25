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
#include "font.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "math.h"
#define debugging

uint64 readController(uint8 controller, uint8 rumble);
#define START_BUTTON 0x1000000000000000
#define Y_BUTTON	 0x0800000000000000
#define X_BUTTON	 0x0400000000000000
#define B_BUTTON	 0x0200000000000000
#define A_BUTTON	 0x0100000000000000
#define L_BUTTON	 0x0040000000000000
#define R_BUTTON	 0x0020000000000000
#define RL_BUTTON	 0x0010000000000000
#define UP_BUTTON	 0x0008000000000000
#define DOWN_BUTTON  0x0004000000000000
#define RIGHT_BUTTON 0x0002000000000000
#define LEFT_BUTTON  0x0001000000000000
#define JOY_XVAL	 0x0000FF0000000000 //>>40
#define JOY_YVAL	 0x000000FF00000000 //>>32
#define C_XVAL		 0x00000000FF000000 //>>24
#define C_YVAL		 0x0000000000FF0000 //>>16
#define R_VAL		 0x000000000000FF00 //>>8
#define L_VAL		 0x00000000000000FF

typedef int bool;
#define true 1
#define false 0


#define bigX 10                  // Number of MOD-LED8x8RGB in columns
#define bigY 5                 // Number of MOD-LED8x8RGB in rows
#define NumberX bigX*bigY       // Total number of MOD-LED8x8RGBs connected together 
#define tickspeed 10           // standaard 60
#define maxrounds 3

enum LedColor {
  Red = 1, //001
  Green = 2, //010
  Cyan = 3, //011
  Blue = 4, //100
  Purple = 5, //101
  Yellow = 6, //110
  White = 7 //111
};

unsigned char dataArray[NumberX*24];
                
enum LedColor color = 1;
unsigned char cX = 9;   // positie van string placement
unsigned char cY = 28;

int BalkLinks = 10;
int BalkRechts = 10;
int MoveBalk = 1;
int BallX = 40;//1;
int BallY = 15; //4;
int BallMovex=1;
int BallMovey=0;
int MoveTeller = 0;
int Speed = tickspeed;
int Starter, ronde, punt =0;    // verloop van game
int SizeTeller=0;
int BalkHit=0;
int LokatieBalkL=1; 
int LokatieBalkR=80;

 char NameP1[7]={"Gilles"}; 
char NameP2[7]= {"Dennis"};
char *P1NamePtr = &NameP1[7];
 char *P2NamePtr = &NameP1[7];
 char Winner1[13] = {"Player 1 WON "};
 char Winner2[13] = {"Player 2 WON "};

unsigned int rondes = 48;
//unsigned int ScoreP1_1 = 48;   // = 0
//unsigned int ScoreP1_2 = 48;
//unsigned int ScoreP2_1 = 48;
//unsigned int ScoreP2_2 = 48;


//char ScoreP1_1C = 

int player1score, player2score  = 0;

char ScoreP1[2]= {"00"}; 
char ScoreP2[2]= {"00"};
//unsigned char *P1Ptr ;
//unsigned char *P2Ptr;

void drawRectangle (int x1, int y1, int x2, int y2);
void drawPixel(int X, int Y);
void drawString( char c[]);
void drawChar(unsigned char c);
void display();
void clearBORD();
void clearALL();
void drawLine (int x1, int y1, int x2, int y2);

void hitdetect();   // collision & bounce calcs
void ticker();
void StartGame();
void DrawGame(int DirectionX, int DirectionY);
void DrawScoreBoard();


uint64 Controller1;
uint64 Controller2;
void PinUP_P1_Handler();
void PinDOWN_P1_Handler();
void PinUP_P2_Handler();
void PinDOWN_P2_Handler();

unsigned char start[6] = {"START"};


void PinUP_P1_Handler()
{
    BalkLinks++;
   // MoveBalkLinks(MoveBalk);
    //MoveTeller++;
    
}

void PinDOWN_P1_Handler()
{
   BalkLinks--;
    //MoveBalkRechts(MoveBalk);
    //MoveTeller++;
    
}

void PinUP_P2_Handler()
{
    BalkRechts++;
   // MoveBalkLinks(MoveBalk);
   // MoveTeller++;
   
}

void PinDOWN_P2_Handler()
{
   BalkRechts--;
    //MoveBalkRechts(MoveBalk);
   
}

int main()
{ 
    
    CyGlobalIntEnable;
UART_Start();
    srand((unsigned) time(0));
    SPI_Start();
   //SPI2_Start(); // SPI voor Scoreboard?
   // UART_Start();
    SPI_SpiUartClearTxBuffer();
    
   // drawString(start);
    //CyDelay(2000);
    display();
    clearALL();
    
    Starter=0;
    ronde = 0;
    StartGame();
    DrawScoreBoard();

    for(;;)
    {
/*-------------Read Controller------------------------*/
        CyGlobalIntDisable;
        Controller1=readController(1,0);
        CyDelay(10);
        Controller2=readController(2,0);
        CyDelay(10);
        CyGlobalIntEnable;
       
/*-------------Manage Input Controls------------------*/ 
        if ((Controller1 & UP_BUTTON) != 0)
        {
            PinUP_P1_Handler();
              //UART_UartPutString("UP1");
        }
        
         if ((Controller1 & DOWN_BUTTON) !=0)
        {
            PinDOWN_P1_Handler();
              //UART_UartPutString("DOWN1");
        }
        
         if ((Controller2 & UP_BUTTON) !=0)
        {
            PinUP_P2_Handler();
            //UART_UartPutString("UP2");
        }
         if ((Controller2 & DOWN_BUTTON) !=0)
        {
            PinDOWN_P2_Handler();
              //UART_UartPutString("DOWN2");
        }
        
/*-------------Start Game Control------------------*/
        
         if ((Controller1 & START_BUTTON) !=0)
        {
            clearALL();
            Starter = 1;
            ronde = 0;
            LokatieBalkL = 1; 
            LokatieBalkR = 80;
            char ScoreP1[2]= {"00"}; 
            char ScoreP2[2]= {"00"};
            DrawScoreBoard();
        }
/*-------------Game Verloop------------------*/        
        if (ronde < maxrounds && Starter==1)
        {
           ticker();
           DrawGame(BallX, BallY);
         //DrawScoreBoard();
        }
//        else if (punt==1)
//        {
//            DrawScoreBoard();
//           ticker();
//           DrawGame(rand()%40+20, rand()%12+5);
//           punt = 0;
//           ronde++;
//
//        }
        
        else if (ronde >= maxrounds)
        {
            clearBORD();
            char GameEnd[13] = "Game Finished";
            
            color = 1;
            cX = (bigX * 8) - 77; ;
            cY = 16 ;
            drawString(GameEnd);
            
/*-------------Print Scores------------*/           
           
            
            if(player1score>player2score){
            color = 4;
            cY = cY - 9;
            cX = (bigX * 8) - 75; ;
            drawString(Winner1);
            }
            else if(player2score>player1score){
            color = 6;
            cY = cY - 9;
            cX = (bigX * 8) - 75; 
            drawString(Winner2);
            }
            
            Starter =0;
            display();
            
            //clearALL();
            //CyDelay(500);

            
          
        }
        
        CyDelay(2); // Delay voor SPI bus
    }

}   


void StartGame()
{
    color = 4;
    //drawLine( 1, 6, 1, 11);
    drawLine( 1, 10, 1, 15); //Stel hier de breedte balk in
    color = 6;
    //drawLine( 80, 6, 80, 11);
    drawLine((bigX*8), 10, (bigX*8), 15);
    DrawScoreBoard();
    CyDelay(10);
    clearBORD(); 
}

void DrawGame(int BallX, int BallY)
{    
    if((BalkHit==1) && (BallX==40) && LokatieBalkL<32){
        LokatieBalkL = LokatieBalkL +8;
        LokatieBalkR = LokatieBalkR -8;
        BalkHit =0;
    }
    
    color = 4;
    drawLine( LokatieBalkL, BalkLinks, LokatieBalkL, BalkLinks+5);
    color = 5;
    drawLine( LokatieBalkR, BalkRechts, LokatieBalkR, BalkRechts+5);
    color = 2;
    drawPixel(BallX, BallY);
    CyDelay(10);
    display();
    clearBORD();
    
}

void ticker()
{
    
    hitdetect();
    BallX = BallX + BallMovex;
    BallY = BallY + BallMovey;
  
}

void hitdetect()
{
  if(	BallMovex == 1 && BallX == ((LokatieBalkR-1))  )
	{
		if (BallY == BalkRechts || BallY == BalkRechts+1)
		{
		BallMovex = BallMovex * -1;
		BallMovey = -1;
            BalkHit++;
		}
		else if (BallY == BalkRechts+2 || BallY == BalkRechts+3)
		{
		BallMovex = BallMovex * -1;
		BallMovey = 0;
            BalkHit++;
		}
		else if (BallY == BalkRechts+4 || BallY == BalkRechts+5)
		{
		BallMovex = BallMovex * -1;
		BallMovey = 1;
             BalkHit++;
		}

	}
	else if ( BallMovex == -1 && BallX == (LokatieBalkL+1))
	{
		if (BallY == BalkLinks || BallY == BalkLinks+1)
		{
		BallMovex = BallMovex * -1;
		BallMovey = -1;
             BalkHit++;
		}
		else if (BallY == BalkLinks+2 || BallY == BalkLinks+3)
		{
		BallMovex = BallMovex * -1;
		BallMovey = 0;
             BalkHit++;
		}
		else if (BallY == BalkLinks+4 || BallY == BalkLinks+5)
		{
		BallMovex = BallMovex * -1;
		BallMovey = 1;
             BalkHit++;}
	}
    
    if (BallY == ((bigY-2)*8) || BallY == 1)
    {
        BallMovey = BallMovey * -1;
    }

    /*-------Score updates---------*/  
 else if (BallX <= LokatieBalkL)
    {

        if(ScoreP2[1]<'9'){
            player2score++;
             sprintf(&ScoreP2[1], "%d", player2score); //Zet integer rechts om in een string en plaats in array links
        }
        else{
            player2score = 1;
            sprintf(&ScoreP2[0], "%d", player2score);
            ScoreP1[1] = '0';
        }
        readController(1,1);
        LokatieBalkL = 1;
        LokatieBalkR = 80;
        BalkHit = 0;
        BallX = rand()%40+25;
        BallY = rand()%24;
        BallMovex = BallMovex*-1;
        ronde++;
        CyDelay(500);
        
        DrawScoreBoard();
        //DrawGame(BallX, BallY);
  
    }
    
  else if (BallX >=LokatieBalkR)
    {     
        if(ScoreP1[1]<'9'){
          player1score++;
          sprintf(&ScoreP1[1], "%d", player1score); //Zet integer rechts om in een string en plaats in array links
        }
        else{
            player1score = 1;
            sprintf(&ScoreP1[0], "%d", player1score);
            ScoreP1[1] = '0';
        }
        readController(2,1);
        LokatieBalkL = 1;
        LokatieBalkR = 80;
        BalkHit = 0;
        BallX = rand()%40+21;
        BallY = rand()%24;
        BallMovex = BallMovex*-1;
        ronde++;
        CyDelay(500);
        
        DrawScoreBoard();
        //DrawGame(BallX, BallY);
    }

}

void DrawScoreBoard()
{
    //ScoreP1[1]++;
    clearALL();
    
/*-----------ScoreBoard---------*/  
    color = 7;
    //drawRectangle (1, 25, 80 ,40);
    drawLine(1,25,80,25);
    
/*-------Player 1 score---------*/ 
    
 //sprintf(buffer, "Temperature: %d\n\r", datain[y]); //Zet integer rechts om in een string en plaats in array links
    color = 4;
    cX = (bigX * 8) - 78; ;
    cY = 33 ;
    drawString(NameP1);
    
    CyDelay(10);
 
    cX = (bigX * 8) - 68; ;
    cY = 25 ;
    drawString(ScoreP1);
    
/*-------Player 2 score---------*/    
    color = 6;
    cX = (bigX * 8) - 38; ;
    cY = 33 ;
    drawString(NameP2);
    
    CyDelay(10);
   
    cX = (bigX * 8) - 25;
    cY = 25 ; 
    drawString(ScoreP2);
    
display();
clearBORD();

}

void drawChar(unsigned char c) {  //draw static character  if within the Font limit
   unsigned char b,i;
   signed char k;
   if (c<32 || c>125) c=32;

   for(k=0;k<5;k++) {
      b = FontLookup[c-32][k];
      for(i=0;i<8;i++)
         if (b & (1<<(7-i))) drawPixel(k+cX,i+cY);	// SPP since our 0, 0 coordinates are in the top left corner instead of bottom left, the letters should be mirrored horizontally ==> (1<<7) replaced with (7-i)
   }
}

void drawString( char c[]) {  //draw static string
      for(int i=0; c[i];i++) {
         drawChar(c[i]);
         cX +=6;
      }
}

void drawLine (int x1, int y1, int x2, int y2) {      //draw a line from x1,y1 to x2,y2
   int dx, dy, sx, sy, err, e2;

   dx = abs (x2-x1);
   dy = abs (y2-y1);
   if (x1<x2) sx = 1;
      else sx = -1;
   if (y1<y2) sy = 1;
      else sy = -1;
   err = dx-dy;
   do {
      drawPixel (x1, y1);
      if ((x1 == x2) && (y1 == y2))
         break;
      e2 = 2*err;
      if (e2 > -dy) {
         err = err - dy;
		 x1 = x1+sx;
      }
      if (e2 < dx) {
         err = err + dx;
		 y1 = y1 + sy;
      }
   } while (1);
	return;
}

void drawRectangle (int x1, int y1, int x2, int y2) {  //draw a rectangle from x1,y1 to x2,y2
   drawLine (x1, y1, x1, y2);
   drawLine (x1, y1, x2, y1);
   drawLine (x2, y1, x2, y2);
   drawLine (x1, y2, x2, y2);
   return;
}


void drawPixel(int X, int Y) {
    
   if (Y<=bigY*8 && X<=bigX*8 && X>0 && Y>0) {
      if (Y>8) X=X+(bigX*8)*((Y-1)/8);
      Y=Y%8;
      if (Y==0) Y=8;
      
      int p;
      p=NumberX-((X-1)/8)-1;

      dataArray[3*(Y-1)+24*p]&=~(1<<((X-1)%8));                  //turn off chosen drawPixel
      dataArray[3*(Y-1)+1+24*p]&=~(1<<((X-1)%8));
      dataArray[3*(Y-1)+2+24*p]&=~(1<<((X-1)%8));

      if (color&1) dataArray[3*(Y-1)+24*p]|=(1<<((X-1)%8));      //set color to the drawPixel
      if (color&2) dataArray[3*(Y-1)+1+24*p]|=(1<<((X-1)%8));
      if (color&4) dataArray[3*(Y-1)+2+24*p]|=(1<<((X-1)%8));
   }  
  }

  void display() {
    char i;
    SPI_SpiUartPutArray(dataArray,(24*NumberX));
   
    
//    unsigned char *dataArrayAddr = dataArray;
    
//       //SPI_SpiUartPutArray(dataArray,24);
//       SPI_SpiUartPutArray(dataArrayAddr,(24*NumberX)/2);
//        //SPI2_SpiUartPutArray((dataArrayAddr + (24*NumberX)/2),(24*NumberX)/2);
//    
    
//    for(int i =0;i<((24*NumberX)/2);i++)
//    {
//    SPI_mosi_m_Write(dataArray[i]);
//    SPI_mosi_m_Write(dataArray[((24*NumberX)/2)+i]);
//    }
    
}
void clearBORD() {
   int i;
    for (i=20*24;i<50*24;i++)
      dataArray[i] = 0x00;   
  }
void clearALL() {
  int i;
    for (i=0;i<NumberX*24;i++)
      dataArray[i] = 0x00;   
  }

uint64 readController(uint8 controller, uint8 rumble) //controller 1 -> 1, anything else: 2 ; rumble: 0 -> off, 1 -> on
{
    //defines
    #define initNoRumble 0b0100000000000011000000001
    #define initRumble   0b0100000000000011000000010
    
    //vars
    uint32 sendingSequence;              //used to temp store init sequence and send
    _Bool readBuffer[61];                //buffer to store readings from controller
    uint64 formattedData;                //formatted data to return
    reg32 *controllerDR, controllerMASK; //used to store mem location of controller data pins (you can change the pin later)
    int16 counter = 0;                   //declare before use (cycles)
    
    //perform checks for settings(controller/rumble)
    if(controller == 1)
    {
        controllerDR = &Controller1_DR;
        controllerMASK = Controller1_MASK;
    }
    else
    {
        controllerDR = &Controller2_DR;
        controllerMASK = Controller2_MASK;
    }
    
    if(rumble == 0)
    {
        sendingSequence = initNoRumble;
    }
    else
    {
        sendingSequence = initRumble;
    }
    
    //##time sensitive code##
    CyGlobalIntDisable;
    
    //This bit-bangs the 24 bits to the controller
    for(int i = 24; i >= 0; --i)
    {
        
        if(((sendingSequence >> i) & 0x000001)  == 0)   //ZERO sequence
        {
            *controllerDR &= ~controllerMASK;
            CyDelayCycles(50);
            *controllerDR |= controllerMASK;
            
            
        }
        else                                     //ONE sequence
        {
            *controllerDR &= ~controllerMASK;
            CyDelayCycles(1);
            *controllerDR |= controllerMASK;
            CyDelayCycles(39);
        }
    }
    
    //this reads the returned 60 bytes (only button data)
    if(controller == 1)
    {
        CyDelayCycles(310);                          //sync to start bit
        for(counter; counter <= 8; ++counter)
        {
            readBuffer[counter] = Controller1_Read();
            CyDelayCycles(50);                       //sync to next bit
        }
        
        CyDelayCycles(5);                            //resync
        for(counter; counter <= 17; ++counter)
        {
            readBuffer[counter] = Controller1_Read();
            CyDelayCycles(50);
        }
        
        CyDelayCycles(5);
        for(counter; counter <= 26; ++counter)
        {
            readBuffer[counter] = Controller1_Read();
            CyDelayCycles(50);
        }
        
        CyDelayCycles(5);
        for(counter; counter <= 35; ++counter)
        {
            readBuffer[counter] = Controller1_Read();
            CyDelayCycles(50);
        }
        
        CyDelayCycles(5);
        for(counter; counter <= 44; ++counter)
        {
            readBuffer[counter] = Controller1_Read();
            CyDelayCycles(50);
        }
        
        CyDelayCycles(5);
        for(counter; counter <= 53; ++counter)
        {
            readBuffer[counter] = Controller1_Read();
            CyDelayCycles(50);
        }
        
        CyDelayCycles(5);
        for(counter; counter <= 60; ++counter)
        {
            readBuffer[counter] = Controller1_Read();
            CyDelayCycles(50);
        }
    }
    else //HOTFIX
    {
        CyDelayCycles(300);                          //sync to start bit
        for(counter; counter <= 8; ++counter)
        {
            readBuffer[counter] = Controller2_Read();
            CyDelayCycles(50);                       //sync to next bit
        }
        
        CyDelayCycles(5);                            //resync
        for(counter; counter <= 17; ++counter)
        {
            readBuffer[counter] = Controller2_Read();
            CyDelayCycles(50);
        }
        
        CyDelayCycles(5);
        for(counter; counter <= 26; ++counter)
        {
            readBuffer[counter] = Controller2_Read();
            CyDelayCycles(50);
        }
        
        CyDelayCycles(5);
        for(counter; counter <= 35; ++counter)
        {
            readBuffer[counter] = Controller2_Read();
            CyDelayCycles(50);
        }
        
        CyDelayCycles(5);
        for(counter; counter <= 44; ++counter)
        {
            readBuffer[counter] = Controller2_Read();
            CyDelayCycles(50);
        }
        
        CyDelayCycles(5);
        for(counter; counter <= 53; ++counter)
        {
            readBuffer[counter] = Controller2_Read();
            CyDelayCycles(50);
        }
        
        CyDelayCycles(5);
        for(counter; counter <= 60; ++counter)
        {
            readBuffer[counter] = Controller2_Read();
            CyDelayCycles(50);
        }
    }
        
    //debug_DR |= debug_MASK;
    //debug_DR &= ~debug_MASK;
    //### end of time sensitive code###
    
    CyGlobalIntEnable;
    
    #ifdef debugging
    for(int i = 0; i <= 60; ++i)
    {
        if(readBuffer[i] == 0)
        {
            UART_UartPutString("0");
        }
        else
        {
            UART_UartPutString("1");
        }
        if(i == 8)
        {
           UART_UartPutString(" "); 
        }
        if(i == 12)
        {
           UART_UartPutString("-"); 
        }
        if(i == 17)
        {
           UART_UartPutString(" "); 
        }
        if(i == 26)
        {
           UART_UartPutString(" "); 
        }
        if(i == 35)
        {
           UART_UartPutString(" "); 
        }
        if(i == 44)
        {
           UART_UartPutString(" "); 
        }
        if(i == 53)
        {
           UART_UartPutString(" "); 
        }
    }
    UART_UartPutString("\r\n");
    #endif
    
    //formatting it to return
    for(int i = 0; i<=60; ++i)
    {
        if(readBuffer[i] == 1)
        {
            formattedData = ((formattedData <<1) | 0x0000000000000001);
        }
        else
        {
            formattedData = formattedData << 1;
        }
        
    }
    
    return formattedData;
}
/* [] END OF FILE */
