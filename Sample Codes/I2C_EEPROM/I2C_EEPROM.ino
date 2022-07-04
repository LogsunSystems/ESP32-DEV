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
