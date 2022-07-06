/*
* Company:       Logsun Systems
* mail_ID:       info@logsun.com
*
* Platform:      ESP32-Dev Board
* Title:         GPIO Test
* Description:   Test All GPIO Ports of ESP32-Dev Board
                 - Connect a 330 Ohm Resistor to Cathode of LED
                 - Connect another pin of Resistor to GND on the Board
                 - Upload this code to board
                 - Connect the Anode of the LED one by one to all 
                   GPIO pins Populated on connector X6
 Note:           - GPIO Pin 34 - 39 are Input only pins hence not used in this code
                 - GPIO Pin 6 - 11 are connected to Internal SPI Flash hence can't 
                   be used
* Date:         06th October 2021
* author:       Shreyas Deshpande.
*/

#include "GPIO_ESP32.h""

void setup()
{
  delay(500);
    pinMode(GPIO_0,OUTPUT);
    pinMode(GPIO_2,OUTPUT);
    pinMode(TXD0,OUTPUT);
    pinMode(RXD0,OUTPUT);
    pinMode(GPIO_4,OUTPUT);
    pinMode(GPIO_5,OUTPUT);
    pinMode(GPIO_12,OUTPUT);
    pinMode(GPIO_13,OUTPUT);
    pinMode(GPIO_14,OUTPUT);
    pinMode(GPIO_15,OUTPUT);
    pinMode(GPIO_16,OUTPUT);
    pinMode(GPIO_17,OUTPUT);
    pinMode(GPIO_18,OUTPUT);
    pinMode(GPIO_19,OUTPUT);
    pinMode(GPIO_21,OUTPUT);
    pinMode(GPIO_22,OUTPUT);
    pinMode(GPIO_23,OUTPUT);
    pinMode(GPIO_25,OUTPUT);
    pinMode(GPIO_26,OUTPUT);
    pinMode(GPIO_27,OUTPUT);
    pinMode(GPIO_32,OUTPUT);
    pinMode(GPIO_33,OUTPUT);


}

void loop()
{
    digitalWrite(GPIO_0,HIGH);
    digitalWrite(TXD0,HIGH);
    digitalWrite(RXD0,HIGH);
    digitalWrite(GPIO_2,HIGH);
    digitalWrite(GPIO_4,HIGH);
    digitalWrite(GPIO_5,HIGH);
    digitalWrite(GPIO_12,HIGH);
    digitalWrite(GPIO_13,HIGH);
    digitalWrite(GPIO_14,HIGH);
    digitalWrite(GPIO_15,HIGH);
    digitalWrite(GPIO_16,HIGH);
    digitalWrite(GPIO_17,HIGH);
    digitalWrite(GPIO_18,HIGH);
    digitalWrite(GPIO_19,HIGH);
    digitalWrite(GPIO_21,HIGH);
    digitalWrite(GPIO_22,HIGH);
    digitalWrite(GPIO_23,HIGH);
    digitalWrite(GPIO_25,HIGH);
    digitalWrite(GPIO_26,HIGH);
    digitalWrite(GPIO_27,HIGH);
    digitalWrite(GPIO_32,HIGH);
    digitalWrite(GPIO_33,HIGH);


    delay(1000);

    digitalWrite(GPIO_0,LOW);
    digitalWrite(TXD0,LOW);
    digitalWrite(RXD0,LOW);
    digitalWrite(GPIO_2,LOW);
    digitalWrite(GPIO_4,LOW);
    digitalWrite(GPIO_5,LOW);
    digitalWrite(GPIO_12,LOW);
    digitalWrite(GPIO_13,LOW);
    digitalWrite(GPIO_14,LOW);
    digitalWrite(GPIO_15,LOW);
    digitalWrite(GPIO_16,LOW);
    digitalWrite(GPIO_17,LOW);
    digitalWrite(GPIO_18,LOW);
    digitalWrite(GPIO_19,LOW);
    digitalWrite(GPIO_21,LOW);
    digitalWrite(GPIO_22,LOW);
    digitalWrite(GPIO_23,LOW);
    digitalWrite(GPIO_25,LOW);
    digitalWrite(GPIO_26,LOW);
    digitalWrite(GPIO_27,LOW);
    digitalWrite(GPIO_32,LOW);
    digitalWrite(GPIO_33,LOW);

    delay(1000);

}
