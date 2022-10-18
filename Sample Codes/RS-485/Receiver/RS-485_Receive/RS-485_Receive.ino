/*
* Company:       Logsun Systems
* mail_ID:       info@logsun.com
*
* Platform:      ESP32-Dev Board
* Title:         RS-485 Recevier Sample Code
* Description:   The code performs following operations to test the onboard RS-485
                 - Configures the RS-485 hardware in recevicer mode.
                 - Wait for data to receive
                 - Put the RS-485 in transmit mode.
                 - Send the received data back to trasnmitter.
                 - To see the response,
                    Open the Serial Terminal,
                    Set the baud rate to 115200.
                 - Reset the board
                 - Send some data and wait for response.
                 - If you see the data you have entered returns back, RS-485 is working.
                   
* Date:         14th October 2021
* author:       Shreyas Deshpande.
*/


#define REDEPIN GPIO_NUM_5

/*
    REDEPIN = 0  => Receive Data

    REDEPIN = 1  => Transmit Data

*/

String Data = "";
char Buff[100] = {'\0'};


void setup()
{
    pinMode(REDEPIN,OUTPUT);
    Data.reserve(100);
    digitalWrite(REDEPIN,LOW);

    Serial.begin(115200);
}


void loop()
{
    
  if(Serial.available()){
    Data = Serial.readString();

    Serial.flush();
    delay(1000);
    digitalWrite(REDEPIN,HIGH);
    delay(100);
    Data.toCharArray(Buff,Data.length()+1);
    for(int i=0;i<Data.length();i++){
      Serial.print(Buff[i]);
      delay(100);
    }
    Serial.print("\n");
    delay(120);

    delay(100);
    digitalWrite(REDEPIN,LOW);
    delay(100);

  }

      


}
