/*
 * SD card pinOut:
 * MISO 50
 * MOSI 51
 * SCK 52
 * SDCS 53
 * 
 * LiquidCrystal:
 * SDA --> SDA
 * SCL --> SCl
 * 
 * FingerPrint:
 * black(FingerPrint Tx) --> A8(Arduino Rx)
 * White(FingerPrint Rx) --> A9(Arduino Tx)
 * white --> Gnd
 * white --> +5v
 * 
 * Keypad: face the buttons of the keypad in front of you
 * the left most 4 pins(first one is N/C) are col pins the other 4s are rows pins
 * leave the first and last pin.
 * 
 * col pins --> 22 , 24 , 26 
 * row pins --> 30 , 32 , 34 , 36
 * 
 * 
 * 
 */


#define SD_CS_PIN 53
#define sw 14 //(Tx3)

#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include<Wire.h>
#include<Keypad.h>
#include <SoftwareSerial.h>
#include <SdFat.h>
#include <FPS_GT511C3.h>

SdFat SD;
File myFile;
String mainString;

//for mega use 62(A8),63(A9)
//for uno or nano you can use 2,3
FPS_GT511C3 fps(62,63); //A8,A9

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3',},
  {'4','5','6',},
  {'7','8','9',},
  {'*','0','#'}
};
byte rowPins[ROWS] = {30, 32, 34, 36}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {22, 24, 26}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  Serial.begin(9600);
//  delay(100);
  fps.Open();

  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  
  pinMode(sw,INPUT);
  pinMode(10, OUTPUT);
  //ask for admin fingerprint if it is brand new
  fps.SetLED(false);
  if(!fps.CheckEnrolled(0) & !fps.CheckEnrolled(1) & !fps.CheckEnrolled(2) )
  {
//    Serial.println("Brand New");
//    Serial.println("Please Add Admin");
    
    lcd.clear();
    lcd.print("Add Admin");
    while(!Enroll(0));
  }

  if (!SD.begin(SD_CS_PIN))
  {
//    Serial.println("SD card initialization failed!");
    
    lcd.clear();
    lcd.print("SD card failed");
  }

  //if it is not brand new, then
  else
  {
//    Serial.println("Welcome");
    
    lcd.clear();
    lcd.setCursor(5,0); //col,row
    lcd.print("Welcome");
  }
}


void loop() {
  char sw_key;
  sw_key = keypad.getKey();
  while(sw_key!= '*')
  {
    sw_key = keypad.getKey();
  }

//while doing using switch
//  while(!digitalRead(sw));
//  delay(500); //debouncing
  int ID = identify_ID();
  if(ID==0 || ID==1 || ID==2)//admin
  {
//    Serial.println("Welcome Admin");
    admin_menu();
  }
}
