/*
* Company:       Logsun Systems
* mail_ID:       info@logsun.com
*
* Platform:      ESP32-Dev Board
* Title:         Relay Test
* Description:   This code is to test therelays on the ESP32-DEV board

* Date:         13th October 2021
* author:       Shreyas Deshpande
*/

//Define the Relay pins

#define  RELAY_1    32
#define  RELAY_2    33

void setup()
{
    //Conffigure Relay Pins as OUTPUT Pins
    pinMode(RELAY_1,OUTPUT);
    pinMode(RELAY_2,OUTPUT);

    //Initially turn OFF both relays
    digitalWrite(RELAY_1,LOW);
    digitalWrite(RELAY_2,LOW);
    delay(100);
}

void loop()
{
    //Turn ON both relays
    digitalWrite(RELAY_1,HIGH);
    digitalWrite(RELAY_2,HIGH);
    
    delay(2500);//wait for 2.5 Seconds

    //Turn OFF both relays
    digitalWrite(RELAY_1,LOW);
    digitalWrite(RELAY_2,LOW);

    delay(2500);//wait for 2.5 Seconds
}