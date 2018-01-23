#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#define ConfigWiFi_Pin D1
#define ESP_AP_NAME "ESP8266 Config AP"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFiManager wifiManager;
  wifiManager.autoConnect(ESP_AP_NAME);
  while (WiFi.status() != WL_CONNECTED){
    delay(250);
    Serial.print(".");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
 

}


