#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>

const char* ssid  = "Arduino01";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);

  Serial.println("Connecting to");
  Serial.println(ssid);
  WiFi.begin(ssid);
   
    while (WiFi.status() != WL_CONNECTED)
{
            delay(500);
            Serial.print(".");
    }
    Serial.println(""); 
    Serial.println("WiFi connected");
  Serial.println("IP address: ");   
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
