/*
*Comapany:      Logsun Sytems, Pune
*E-mail:        info@logsunonline.com
*Title:         Connect to WiFi
*Author:        Shreyas Deshpande

*Description:   This code demonstrates how to connect to 
                WiFi Network
*/

#include "WiFi.h"

const char* SSID = "Your WiFi SSID";
const char* Password = "Your WiFi Network's Password";

void setup(){
    Serial.begin(115200);

    Serial.println("\nConnecting to " + String(SSID));

    Serial.println("\n\n");

    WiFi.begin(SSID,Password);

    while(WiFi.status()!= WL_CONNECTED)
    {
        Serial.print(". ");
        delay(1000);
    }

    Serial.println("\n\nConnectd to WiFi Succesfully");



}

void loop(){

}
