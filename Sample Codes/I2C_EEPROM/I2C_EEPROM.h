#include<stdint.h>
#include<arduino.h>
#include <Wire.h>



#define PAGE_1  0x50U
#define PAGE_2  0x51U

char Read_EEPROM(byte, int);
void Write_EEPROM(byte, int, char);
