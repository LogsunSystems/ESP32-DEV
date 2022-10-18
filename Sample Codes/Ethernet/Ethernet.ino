/*
* Company:       Logsun Systems
* mail_ID:       info@logsun.com
*
* Platform:      ESP32-Dev Board
* Title:         Ethernet Sample Code
* Description:   The code performs following operations to test the onboard Ethernet
                 - Start the ETH instance
                 - Assign the IP address on connecting the Ethernet Cable
                 - Connect to Google.com
                 - Displays the Response on Serial Monitor.
                 - To see the response,
                    Open the Serial Terminal,
                    Set the baud rate to 115200.
                 - Reset the board & Observe the output
                   
* Date:         06th May 2021
* author:       Shreyas Deshpande.
*/


#define ETH_PHY_ADDR  1
#include <ETH.h>

static bool eth_connected = false;

void WiFiEvent(WiFiEvent_t event)
{
  switch (event) {
    case SYSTEM_EVENT_ETH_START:
      Serial.println("ETH Started");
      //set eth hostname here
      ETH.setHostname("esp32-ethernet");
      break;
    case SYSTEM_EVENT_ETH_CONNECTED:
      Serial.println("ETH Connected");
      break;
    case SYSTEM_EVENT_ETH_GOT_IP:
      Serial.print("ETH MAC: ");
      Serial.print(ETH.macAddress());
      Serial.print(", IPv4: ");
      Serial.print(ETH.localIP());
      if (ETH.fullDuplex()) {
        Serial.print(", FULL_DUPLEX");
      }
      Serial.print(", ");
      Serial.print(ETH.linkSpeed());
      Serial.println("Mbps");
      eth_connected = true;
      break;
    case SYSTEM_EVENT_ETH_DISCONNECTED:
      Serial.println("ETH Disconnected");
      eth_connected = false;
      break;
    case SYSTEM_EVENT_ETH_STOP:
      Serial.println("ETH Stopped");
      eth_connected = false;
      break;
    default:
      break;
  }
}

void testClient(const char * host, uint16_t port)
{
  Serial.print("\nconnecting to ");
  Serial.println(host);

  WiFiClient client;
  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    return;
  }
  client.printf("GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
  while (client.connected() && !client.available());
  while (client.available()) {
    Serial.write(client.read());
  }

  Serial.println("closing connection\n");
  client.stop();
}

void setup()
{
  Serial.begin(115200);
  WiFi.onEvent(WiFiEvent);
  ETH.begin();
}


void loop()
{
  if (eth_connected) {
    testClient("google.com", 80);
  }
  delay(10000);
}
