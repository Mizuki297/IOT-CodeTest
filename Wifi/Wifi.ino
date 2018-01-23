#include <ESP8266WiFi.h>
#define WIFI_SSID "LAPTOP-N8IDRCOR 7614"
#define WIFI_PASS "&t071F53"
void setup() {
  pinMode(D1,OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.println("Connecting...");

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }
  Serial.println();
  Serial.println("Connecting");
  Serial.print("IP : ");
  Serial.println(WiFi.localIP());
  digitalWrite(D1,HIGH);


}

void loop() {

}
