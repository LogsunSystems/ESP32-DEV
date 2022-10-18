#ifndef MICROSD_H
#define MICROSD_H

#include<Arduino.h>

#include "FS.h"
#include <SD.h>
#include "SPI.h"

#define MOSI    GPIO_NUM_15
#define MISO    GPIO_NUM_2
#define SCK     GPIO_NUM_14
#define CS      GPIO_NUM_17


void writeFile(fs::FS &fs, const char * path, const char * message);
void appendFile(fs::FS &fs, const char * path, const char * message);


#endif