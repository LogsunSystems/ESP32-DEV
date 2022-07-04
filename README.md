# ESP32-DEV

## Introduction

The ESP32-DEV board is based on **ESP32 WROOM32D** module of the _espressif_. The board is suitable for one who want to experiment on the _ESP32_ chip. The board has many on-board interfacing options available. The salient features of the board are as following,

* can use 12V or 24 V Industrial power supply 
* Li-Po/ Li-ion battery connector with charger _(Optional)_
* Mini USB interface for programming as well as serial out
* No need to press any button while uploading the program
* 4K I2C EEPROM
* RS-485 Interface
* RJ-45 Connector for Ethernet
* 2 channel Relays
* micro SD card Interface
* Unique UEXT connector
* 40 Pin GPIO Header
* On-board Reset Button
 
## System Requirement
* A PC with Windows 7 or later / Linux / Mac
* [Arduino IDE](https://www.arduino.cc/en/software)
* A brain to write code...

## Adding the ESP32 board in Arduino IDE

* Open _Arduino IDE_
* Go to _File -> Preferences_
* Copy this _[https://dl.espressif.com/dl/package_esp32_index.json](https://dl.espressif.com/dl/package_esp32_index.json)_ URL
* Then Go to _Tools -> Boards -> Board Manager_
* Serach For _ESP32_
* Install the board package.
* Reastart the Arduino IDE if required
* Select _Olimex-EVB_ from the board

## Libraries Required

* SD
* ETH
* WiFi
* SPI
* Wire
