/*
* Company:       Logsun Systems
* mail_ID:       info@logsun.com
*
* Platform:      ESP32-Dev Board
* Title:         SD_Card Sample Code
* Description:   The code performs following operations to test the SD card connector.
                 - Create file on SD card with name "test.txt"
                 - Writes some data in file
                 - Append another data in file.
                    Open the Serial Terminal,
                    Set the baud rate to 115200.
                 - Reset the board
                 - Observe the process.
                   
* Date:         14th October 2021
* author:       Shreyas Deshpande.
*/

#include"microSD.h"

void setup()
{
    Serial.begin(115200);
    delay(200);

    Serial.println("Initializing the SD card");

    SPIClass spi = SPIClass(VSPI);
    spi.begin(SCK,MISO,MOSI,CS);
    delay(100);

    if(!SD.begin(CS,spi,80000000)){
        Serial.println("SD card Initialization Faild");
        while(1);
    }
    else{
        Serial.println("SD card Succesfully initialized");
    }


    uint8_t cardType = SD.cardType();

  if(cardType == CARD_NONE){
    Serial.println("No SD card attached");
    return;
  }

  Serial.print("SD Card Type: ");
  if(cardType == CARD_MMC){
    Serial.println("MMC");
  } else if(cardType == CARD_SD){
    Serial.println("SDSC");
  } else if(cardType == CARD_SDHC){
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }

  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD Card Size: %lluMB\n", cardSize);


    //Creating file on SD card

    writeFile(SD,"/test.txt","Hello from Logsun, Test message\n\n");

    delay(400);

    appendFile(SD,"/test.txt","This is appended Message");



}

void loop()
{

}



void writeFile(fs::FS &fs, const char * path, const char * message){
  Serial.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_WRITE);
  if(!file){
    Serial.println("Failed to open file for writing");
    return;
  }
  if(file.print(message)){
    Serial.println("File written");
  } else {
    Serial.println("Write failed");
  }
  file.close();

  return;
}


void appendFile(fs::FS &fs, const char * path, const char * message){
  Serial.printf("Appending to file: %s\n", path);

  File file = fs.open(path, FILE_APPEND);
  if(!file){
    Serial.println("Failed to open file for appending");
    return;
  }
  if(file.print(message)){
      Serial.println("Message appended");
  } else {
    Serial.println("Append failed");
  }
  file.close();

  return;
}
