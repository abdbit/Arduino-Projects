// For OLED display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define screenWidth 128
#define screenHeight 64

Adafruit_SSD1306 display(screenWidth,screenHeight);


// For servo motor
#include <Servo.h>


// const int led = 4;
const int mSensor = 2;
int motionDetected;

const int mSensor2 = 4;
int motionDetected2;

// Servo motor
Servo s1; 


void setup() 
{
//  pinMode(led, OUTPUT);
 pinMode(mSensor, INPUT);  
 pinMode(mSensor2, INPUT);
 Serial.begin(9600);

 s1.attach(9);

 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}

void loop()
{
 motionDetected = digitalRead(mSensor);
 motionDetected2 = digitalRead(mSensor2);
 
 if (motionDetected){ 
  s1.write(180);
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(21,22);
  display.print("Right");
  display.display();
  Serial.print("right\n");
 } 

 if (motionDetected2) {
  s1.write(0);
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(30,22);
  display.print("Left");
  display.display();
  Serial.print("left\n");
 }

}  