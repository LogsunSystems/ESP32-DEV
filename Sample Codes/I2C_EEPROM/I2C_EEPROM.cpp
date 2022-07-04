#include "I2C_EEPROM.h"

char Read_EEPROM(byte Page, int ADD)
{
    char data1 = '\0';
   Wire.beginTransmission(Page);
    delay(5);
    // Wire.write((uint8_t)(ADD >> 8) & 0xFF); //Uncomment if EEPROM is greator than 512 bytes
    // delay(5);
    Wire.write((uint8_t)ADD & 0xFF);
    delay(5);
    Wire.endTransmission();
    delay(5);
    Wire.requestFrom((uint8_t)Page, (uint8_t)1);

    delay(5);
    while (Wire.available())
    {
      data1 = Wire.read();
    }
    Wire.endTransmission();

    return data1;
    
}

void Write_EEPROM(byte Page, int Add, char sdata)
{
  Wire.beginTransmission(Page);
    //Add=1;

    delay(5);
    // Wire.write((uint8_t)(Add >> 8) & 0xFF); //uncomment if EEPROM is grgeator than 512 bytes
    // delay(5);
    Wire.write((uint8_t)Add & 0xFF);
    delay(5);
    Wire.write(sdata);
    Wire.endTransmission();
    delay(5);
}