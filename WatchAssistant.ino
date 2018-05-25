#include "Event.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#include <Time.h>
#include <TimeLib.h>
#include <SoftwareSerial.h>
#include <Commands>

  
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

#if (SSD1306_LCDHEIGHT != 64)
#error(SSD1306_LCDHEIGHT);
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

SoftwareSerial mySerial(10, 11); // RX, TX
String buffer = "";
String tag = "";
short identifierCount = 0;


void setup(){
  Serial.begin(9600);
  initializeDisplay();
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  Serial.write("Loading Watch Assistant");
}

void loop(){
  handleSerial();
    
  renderClockType1();
  
}
void handleSerial(){
  if (mySerial.available()){
    /*if(c!='#'){
      if(identifierCount==0){
        buffer+=c;
      } else {
        tag+=c;
      }
    } else {
      if(identifierCount==1){
          identifierCount=0;
          flushBuffer();
      } else {
       identifierCount++; 
      }
    }
    */
   Serial.println( mySerial.read());
  }
}

void flushBuffer(){
 parseCommand(tag, buffer); //TAG IS THE COMMAND, BUFFER IS THE ARGUMENT.
 tag = "";
 buffer = "";
}

void parseCommand(String tag, String buffer){
  Serial.println("Parsing command: "+tag+","+buffer);
  if(tag=="time"){
   syncTimeCommand(buffer);
   
  }
}




void initializeDisplay(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  testDrawString("\nWatch\n Assistant");
  display.display();
  delay(1500);
  display.clearDisplay();
}


void testDrawString(String str){
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  int a[] = {1,7,2,5,15,4,12,9,14,11,6,8,16,13,17,3,10};
  for(int16_t i = 0;i<str.length();i++){
    int row = 0;
    int col = a[i];
    if(col>6){
       row = 5;
      col-=7; 
    }
    display.setCursor(col*12,row*6);
    display.write(str[a[i]]);
    delay(100);
    display.display();
  }
}


void renderClockType1(){
  display.clearDisplay();
  display.setTextSize(5);
  display.setCursor(0, 0);
  display.setTextWrap(false);
  int8_t hour_time = hour();
  if(hour_time==0)
    hour_time = (uint8_t) 12;
  else if(hour_time>=13)
    hour_time -= (uint8_t) 12;
    
  if(hour_time<=9)
  {
    display.setCursor(30, 0);
    display.print(hour_time);
  }
  else
    display.print(hour_time);
    
  display.setCursor(50, 0);
  display.print(":");
  display.setCursor(70, 0);
  int8_t minute_time = minute();
  
  if(minute_time<=9){ 
    display.print("0");
    display.setCursor(99, 0);
    display.print(minute_time);
  }
  else
    display.print(minute_time);
    
    
  display.setTextSize(2);

  char *wkdy[7] = {"SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT"};
  display.setCursor(5, 43);
  display.print(wkdy[weekday()-1]);
  display.setCursor(60, 43);
  display.print(month());
  display.setCursor(78, 43);
  display.print("/");
  display.setCursor(95, 43);
  display.print(day());
  display.display();
}
