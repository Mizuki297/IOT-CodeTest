#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
const char *ssid = "STAFF_WiFi_ByIT";
const char *password = "";
int mot1up = D1;
int mot1down = D2;
int mot2up = D3;
int mot2down = D4;

WiFiServer server(100);


void setup() {
  Serial.begin(115200);
  delay (10);
pinMode(mot1up,OUTPUT);
pinMode(mot1down,OUTPUT);
pinMode(mot2up,OUTPUT);
pinMode(mot2down,OUTPUT);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  server.begin();
  Serial.println("Server started");
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
 WiFiClient client = server.available();
 if (!client){
  return;
 }
 Serial.println("new client");
 while(!client.available()){
    delay(1);
 }
 String request = client.readStringUntil('\r');
 Serial.println(request);
 client.flush();
 
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  
   int value = LOW;
  if (request.indexOf("/UP") != -1)  {
    analogWrite(mot1up, 1024);
    analogWrite(mot1down, 0);
    analogWrite(mot2up, 1024);
    analogWrite(mot2down, 0);
    value = HIGH;
  }
  if (request.indexOf("/DOWN") != -1)  {
    analogWrite(mot1up, 0);
    analogWrite(mot1down, 1024);
    analogWrite(mot2up, 0);
    analogWrite(mot2down, 1024);
    value = LOW;
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  
   if(value == HIGH) {
    client.print("UP");
  } else {
    client.print("DOWN");
  }
  client.println("<br><br>");
  client.println("<a href=\"/UP\"\"><button>Turn UP </button></a>");
  client.println("<a href=\"/DOWN\"\"><button>Turn DOWN </button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
 

