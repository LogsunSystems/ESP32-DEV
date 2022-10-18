/*
* Company:       Logsun Systems
* mail_ID:       info@logsun.com
*
* Platform:      ESP32-Dev Board
* Title:         RS-485 Trasnmitter Sample Code
* Description:   The code performs following operations to test the onboard RS-485
                 - Configures the RS-485 hardware in transmit mode.
                 - Transmit the count over RS-485
				 - Increment the count
				 - For more information please read the RS485 section of User Manual.
                   
* Date:         14th October 2021
* author:       Shreyas Deshpande.
*/


#define REDEPIN GPIO_NUM_5

/*
    REDEPIN = 0  => Receive Data

    REDEPIN = 1  => Transmit Data

*/

int count = 0;

void setup()
{
    pinMode(REDEPIN,OUTPUT); //Define Direction Pin as OUTPUT
    digitalWrite(REDEPIN,HIGH); // Put RS-485 in Transmit mode
    Serial.begin(115200);   //Initialize Serial Port
}


void loop()
{
    
    Serial.println(count);  //Send the count over RS-485
    count++;        //Increment the count
    delay(1000);

    if(count == 101){
        count = 0;
    }

    


}