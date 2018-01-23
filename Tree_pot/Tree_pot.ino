#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "test-tree-pot.firebaseio.com"
#define FIREBASE_KEY "edMKdiiklnsqEzUyXUMOSsd7PypLElblJNVxehDw"
#define wifi_ssid "STAFF_WiFi_ByIT"
#define wifi_password ""

const int sensortem = D4;

const String headfire = "Tree pot";
const String ChildTem = "Temperature"; 
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid,wifi_password);
  Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
}
  Firebase.begin(FIREBASE_HOST,FIREBASE_KEY);
  pinMode(sensortem,INPUT);

}

void loop() {
  int Tem = convertTemperature(digitalRead(sensortem));
  Firebase.setInt(ChildTem + "/Temperature",Tem);
  delay(1000);
}
int convertTemperature(int value) {
  
}


