#include <Arduino.h>
#include <Wire.h>
#include <TinyGPS.h>
#include <LiquidCrystal.h>
#include <LCD1602BigNumbers.h>
#include <lcdPilot.h>

#include "SpacePoint.h"
#include "GY80.h"

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>



// OLED display TWI address
#define OLED_ADDR   0x3C //AKA 0x78>>1  (//  0x78, 0x7A)



#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


LiquidCrystal lcd(40, 41, 42, 43, 44, 45);
LCD1602BigNumbers BigNum(&lcd);
GY80 sensor = GY80();
TinyGPSPlus gps;

lcdPilot lcdPilot(&lcd);

void setup() {
  // Delay
  delay(500);
  


  // PIN de FPS
    pinMode(13, OUTPUT); 
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial3.begin(38400);
  Wire.begin();  //ST 
  Wire.setClock(400000 );

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.setRotation( 2 ); 
  display.clearDisplay();
  // display a pixel in each corner of the screen
  display.drawPixel(0, 0, WHITE);
  display.drawPixel(127, 0, WHITE);
  display.drawPixel(0, 63, WHITE);
  display.drawPixel(127, 63, WHITE);

  // display a line of text
  display.setTextSize(4);
  display.setTextWrap(false);
  display.setTextColor(WHITE);
  display.setCursor(27,30);
  display.print("Hello, world!");

  display.display();
  display.dim(true);

  //sensor.setup();
  SpacePoint_init();
  lcd.begin(20, 4);
  lcdPilot.begin();

  //OLED DRIVER TEST
  Wire.setClock(400000 );
}
SpacePointQuat Quaternion;
  int c=127;

TinyGPSLocation lastposition; 
void loop() {
  // put your main code here, to run repeatedly:
 

  
  


  SpacePointEuler Euler;
  SpacePoint_poolData(&Quaternion);
  Euler = SpacePoint_quatToEuler(&Quaternion);
  float angle = Euler.yaw;
  if (angle<0)  {
    angle=360 + angle;
  }

   


 // angle = sensor.getValues();
 // Serial.println(angle);
   digitalWrite(13, HIGH);
   int byte_nmea = Serial3.available();
   for(int i=0;i<byte_nmea;i++) {
     gps.encode( Serial3.read());
   }
  digitalWrite(13, LOW);
 int bute=angle/5;
 lcdPilot.set(angle);
lcd.setCursor(0,1);
 lcd.print(angle);


    // Draw GPS on Oled
    display.clearDisplay();
    // display.setCursor(0,0);
    // display.print( gps.speed.knots());
    // display.setCursor(0,30);
    // display.print( gps.course.deg());


    // display.setCursor(0,0);
    // display.print( gps.location.lat(),8);
    // display.setCursor(0,20);
      display.print( angle,5);

        display.setCursor(0,0);
    // display.print(TinyGPSPlus::distanceBetween(lastposition, gps.location),8);

    lastposition = gps.location;
    //


    
  display.display();

 


  // BigNum.writeBigNumber(angle, 12,3);
    
 
 
}