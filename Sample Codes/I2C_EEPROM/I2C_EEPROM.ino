/*
* Company:       Logsun Systems
* mail_ID:       info@logsun.com
*
* Platform:      ESP32-Dev Board
* Title:         I2C EEPROM Sample Code
* Description:   The code performs following operations to test the onboard I2C EEPROM
                 - Writes ASCII characters from 33 to 127 in EPPTOM
                 - Read the EEPROM locations to verify the Write Operation
                 - Upload this code to board
                 - Open the Serial Terminal, Set the baud rate to 115200.
                 - Observe ethe output
                   
* Date:         06th October 2021
* author:       Shreyas Deshpande.
*/


#include "I2C_EEPROM.h"

int Address =0;
byte Data = 33;
char Read_Data = '\0';


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
delay(50);
Wire.begin();
delay(50);
Serial.println("************ EEPROM Read/Write Test ************");
}


void loop() {
//   put your main code here, to run repeatedly:
  Serial.println("\nWriting to EEPROM");
  Serial.println("Address: "+ String(Address));
  Serial.println("Data: " + String(Data));

  Write_EEPROM(PAGE_1,Address,Data);
  delay(25);

  Serial.println("\nReading From EEPROM");

  Read_Data = Read_EEPROM(PAGE_1,Address);

  Serial.println("Data => "+String(Read_Data));
  delay(275);
  Address++;
  Data++;
  Serial.println("\n\n");
  if(Address>=128)
  {
    Address =0;
    Data = 33;
  }
  
  
}
