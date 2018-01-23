#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char *ssid = "My NodeMCU";
const char *password = "";
int statemot = 0;
int mot1up = D1;
int mot1down = D2;
int mot2up = D3;
int mot2down = D4;
ESP8266WebServer server(80);

void handleRoot() {
    response();
}
void handleSTOP(){
  statemot = 0;
  delay(500);
    analogWrite(mot1up,0);
  analogWrite(mot1down,0);
  analogWrite(mot2up,0);
  analogWrite(mot2down,0);
  response();
}
void handleUP() {
  statemot = 1;
  delay(500);
    analogWrite(mot1up,1024);
  analogWrite(mot1down,0);
  analogWrite(mot2up,1024);
  analogWrite(mot2down,0);
  response();
}

void handleDOWN() {
  statemot = 2;
  delay(500);
    analogWrite(mot1up,0);
  analogWrite(mot1down,1024);
  analogWrite(mot2up,0);
  analogWrite(mot2down,1024);
  response();
}

void handleLIFT(){
  statemot = 3;
  delay(500);
  analogWrite(mot1up,400);
  analogWrite(mot1down,0);
  analogWrite(mot2up,1024);
  analogWrite(mot2down,0);
  response();
}
void handleRIGTH(){
  statemot = 4;
  delay(500);
  analogWrite(mot1up,1024);
  analogWrite(mot1down,0);
  analogWrite(mot2up,400);
  analogWrite(mot2down,0);
  response();
}

const String HtmlHtml = "<html><head>"
    "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /></head>";
const String HtmlHtmlClose = "</html>";
const String HtmlTitle = "<h1>My CAR: ESP8266 AP WebServer TEST</h1><br/>\n";
const String HtmlmotStateUp = "<big>Car is going <b>UP</b></big><br/>\n";
const String HtmlmotStateDown = "<big>Car is going <b>DOWN</b></big><br/>\n";
const String HtmlmotStateStop = "<big>Car is going <b>STOP</b></big><br/>\n";
const String HtmlmotStateLift = "<big>Car is going <b>LIFT</b></big><br/>\n";
const String HtmlmotStateRigth = "<big>Car is going <b>RIGTH</b></big><br/>\n";
const String HtmlButtons = 
    "<a href=\"LIFT\"><button style=\"display: block; width: 50%;\">LIFT</button></a>"
    "<a href=\"RIGTH\"><button style=\"display: block; width: 50%;\">RIGTH</button></a><br/>"
    "<a href=\"UP\"><button style=\"display: block; width: 100%;\">UP</button></a><br/>"
    "<a href=\"DOWN\"><button style=\"display: block; width: 100%;\">DOWN</button></a><br/>"
    "<a href=\"STOP\"><button style=\"display: block; width: 100%;\">STOP</button></a><br/>";

void response(){
  String htmlRes = HtmlHtml + HtmlTitle;
  if(statemot == 0){
    htmlRes += HtmlmotStateStop;
  }else if(statemot == 1){
    htmlRes += HtmlmotStateUp;
  }else if(statemot == 2){
    htmlRes += HtmlmotStateDown;
  }else if(statemot == 3){
    htmlRes += HtmlmotStateLift;
  }else if(statemot == 4){
    htmlRes += HtmlmotStateRigth;
  }

  htmlRes += HtmlButtons;
  htmlRes += HtmlHtmlClose;

  server.send(200, "text/html", htmlRes);
}

void setup() {
    delay(1000);
    Serial.begin(9600);
    Serial.println();

    WiFi.softAP(ssid, password);

    IPAddress apip = WiFi.softAPIP();
    Serial.print("visit: \n");
    Serial.println(apip);
    server.on("/", handleRoot);
    server.on("/UP", handleUP);
    server.on("/DOWN", handleDOWN);
    server.on("/STOP",handleSTOP);
    server.on("/LIFT",handleLIFT);
    server.on("/RIGTH",handleRIGTH);
    server.begin();
    Serial.println("HTTP server beginned");
    pinMode(mot1up,OUTPUT);
    pinMode(mot1down,OUTPUT);
    pinMode(mot2up,OUTPUT);
    pinMode(mot2down,OUTPUT);
}

void loop() {
    server.handleClient();
}
