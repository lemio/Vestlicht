/*
This code controls a trafic light in the living room of 'de tempel van Shostakovich'
A cronjob controlls the
*/


#include "FS.h"

#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

NewRemoteTransmitter transmitter(20231262, D8, 260, 3);

/*
Include the neccesary libraries
*/
#define AMOUNT_OF_LIGHTS 4


bool state[AMOUNT_OF_LIGHTS] = {0,0,0,0};

const char* ssid = "The Shostakovich Network";
const char* password = "Password";

unsigned long timer = 0;
unsigned long shostTimer = 0;
KaKuTransmitter kaKuTransmitter(D8);

//Set a static IP adress (to make sure the router can find it)
IPAddress ip(192, 168, 1, 230);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);

const int led = BUILTIN_LED;
/*
The root function (what the user sees), just display the HTML in html.ino
*/

void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/html", page);
  digitalWrite(led, 0);
}
/*
Error message
*/
void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}
/*
The main setup function
*/
void setup(void){
  pinMode(D4,OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.config(ip,gateway,subnet);
  WiFi.begin(ssid, password);
  Serial.println("");

  Serial.begin(115200);
  pinMode(5, OUTPUT);
  SPIFFS.begin();
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
 server.on("/shost", [](){
      server.send(200, "text/html", "sound played");
      shostTimer = millis();

 });
  server.on("/get", [](){
    String message = "[";
     message += state[0];
    message += state[1];
     message += state[2];
      message += "]";
    server.send(200, "text/html", message);

  });
  server.on("/send", [](){
     state[server.arg(1).toInt()-1] = (server.arg(2)=="1");
     if (server.arg(1).toInt() == 3){
            kaKuTransmitter.sendSignal(server.arg(0)[0],server.arg(1).toInt(),(server.arg(2)=="1"));
        //digitalWrite(D4, (server.arg(2)=="1"));
        }else{
          if (server.arg(1).toInt() == 4){
            if (server.arg(2)=="1"){
              transmitter.send(0x16766036,24);
              }else{
              transmitter.send(0x16766033,24);
              }
            }
          transmitter.sendUnit(server.arg(1).toInt()-1,(server.arg(2)=="1"));
        }

      if (server.arg(2)=="1"){
        timer = millis();
        }
      server.send(200, "text/html", "done");
    });
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
  setupOTA();
}

void loop(void){
  ArduinoOTA.handle();
  server.handleClient();
  if (millis()> timer + 1800000){
    timer = millis();
    kaKuTransmitter.sendSignal('A',3,false);
    transmitter.sendUnit(0, false);
    transmitter.sendUnit(1,false);
    kaKuTransmitter.sendSignal('A',2,false);
    kaKuTransmitter.sendSignal('A',1,false);
    transmitter.send(0x16766033,24);
    state[0] = 0;
    state[1] = 0;
    state[2] = 0;
    state[3] = 0;
    }
}
