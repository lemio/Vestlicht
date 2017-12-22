const char page[] PROGMEM = R"=====(
  <body>
<svg style=" z-index: -100;position:fixed; top:0; left:0; height:100%; width:100%" version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
   width="480px" height="800px" viewBox="0 0 480 800" style="enable-background:new 0 0 480 800;" xml:space="preserve">
<rect x="70.688" y="21.011" style="fill:#666666;" width="340.861" height="758.065"/>
<circle style="fill:red;" cx="240" cy="160.24" r="102.151" id="red_circle"/>
<circle style="fill:orange;" cx="240" cy="400" r="102.151" id="orange_circle"/>
<circle style="fill:green;" cx="240" cy="639.76" r="102.151" id="green_circle"/>
<g>
  <path style="fill:none;stroke:#000000;stroke-width:14;stroke-linecap:round;stroke-linejoin:round;" d="M342.151,160.24
    c0-56.417-45.734-102.151-102.151-102.151c-56.416,0-102.15,45.734-102.15,102.151"/>
</g>
<g>
  <path style="fill:none;stroke:#000000;stroke-width:14;stroke-linecap:round;stroke-linejoin:round;" d="M342.151,400
    c0-56.417-45.734-102.151-102.151-102.151c-56.416,0-102.15,45.734-102.15,102.151"/>
</g>
<g>
  <path style="fill:none;stroke:#000000;stroke-width:14;stroke-linecap:round;stroke-linejoin:round;" d="M342.151,639.76
    c0-56.416-45.734-102.15-102.151-102.15c-56.416,0-102.15,45.734-102.15,102.15"/>
</g>
</svg>
<div style="height: 33%; width: 100%; z-index: -1;" onclick="changeRed();" id="red_area"></div>
<div style="height: 33%; width: 100%; z-index: -1;" onclick="changeOrange();" id="orange_area"></div>
<div style="height: 33%; width: 100%; z-index: -1;" onclick="changeGreen();" id="green_area"></div>
<script type="text/javascript">
  window.onload = function() {
    refresh();
    setInterval(refresh, 3000);
    }
  function refresh(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
    console.log("state change")
  if (xhttp.readyState == 4 && xhttp.status == 200) {
    console.log(xhttp.responseText.charAt(1));
    document.getElementById("red_circle").style.fill = (xhttp.responseText.charAt(1) == "1") ? "red" : "black";
    document.getElementById("orange_circle").style.fill = (xhttp.responseText.charAt(2) == "1") ? "orange" : "black";
    document.getElementById("green_circle").style.fill = (xhttp.responseText.charAt(3) == "1") ? "green" : "black";
  }
  };
    xhttp.open("GET", "get",true);
    xhttp.send();
    
    }
function changeRed (){
  var xhttp = new XMLHttpRequest();
  if (document.getElementById("red_circle").style.fill == 'red'){
    xhttp.open("GET", "send?a=A&port=1&state=0",true);
    document.getElementById("red_circle").style.fill = "black";
  }else{
    xhttp.open("GET", "send?a=A&port=1&state=1",true);
    document.getElementById("red_circle").style.fill = "red";
    }
    xhttp.send();
  }
function changeGreen (){
  var xhttp = new XMLHttpRequest();
  if (document.getElementById("green_circle").style.fill == 'green'){
    document.getElementById("green_circle").style.fill = "black";
    xhttp.open("GET", "send?a=A&port=3&state=0",true);
  }else{
    document.getElementById("green_circle").style.fill = "green";
    xhttp.open("GET", "send?a=A&port=3&state=1",true);
    }
    xhttp.send();
  }
function changeOrange (){
  var xhttp = new XMLHttpRequest();
  if (document.getElementById("orange_circle").style.fill == 'orange'){
    document.getElementById("orange_circle").style.fill = "black";
    xhttp.open("GET", "send?a=A&port=2&state=0",true);
  }else{
    document.getElementById("orange_circle").style.fill = "orange";
    xhttp.open("GET", "send?a=A&port=2&state=1",true);
    }
    xhttp.send();
}
  </script>
</body>
)=====";

const char pageFust[] PROGMEM = R"=====(

<body style="background-color: black;">
<svg style=" z-index: -100;position:fixed; top:0; left:0; height:100%; width:100%" version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
  viewBox="0 0 1080 1920" enable-background="new 0 0 1080 1920" xml:space="preserve">
   <path fill="#8C6239" d="M817.2,418.3C817.2,418.3,817.2,418.3,817.2,418.3L817.2,418.3H667c-7.5,0-15,0-22.5,0c0,0,0,0,0,0l-18.2,0
    c0,0,0,0,0,0c-15.1,0-30.3,0-45.4,0c0,0,0,0,0,0l-18.2,0c0,0,0,0,0,0c-15.1,0-30.3,0-45.4,0c0,0,0,0,0,0.1l-18.2,0c0,0,0,0,0-0.1
    c-15.1,0-30.3,0-45.4,0c0,0,0,0,0,0.1l-18.2,0c0,0,0-0.1,0-0.1c-15.1,0-30.3,0-45.4,0c0,0,0,0.1,0,0.1l-18.2,0c0,0,0-0.1,0-0.1
    c-15.1,0-30.3,0-45.4,0c0,0,0,0.1,0,0.1l-18.2,0c0,0,0-0.1,0-0.1c-15.1,0-30.3,0-45.4,0c0,0,0,0.1-0.1,0.1l-0.2,0l0,0.6
    c-103.7,264.2-103.6,569.9,0.3,834v0h0c15.1,0,30.3,0,45.4,0h18.2c15.1,0,30.3,0,45.4,0h18.2c15.1,0,30.3,0,45.4,0h18.2
    c15.1,0,30.3,0,45.4,0h18.2c15.1,0,30.3,0,45.4,0h18.2c15.1,0,30.3,0,45.4,0h18.2c15.1,0,30.3,0,45.4,0h18.2c15.1,0,30.3,0,45.4,0
    h18.2c15.1,0,30.3,0,45.4,0C921.2,988.7,921.2,682.6,817.2,418.3z"/>
   <polygon fill="#000000" stroke="#000000" stroke-width="0" stroke-miterlimit="10" points="963.2,1724.8 133.3,1724.8
    271.6,1292.2 824.9,1292.2 " id="fustLight"/>
   <path fill="#754C24" d="M817.2,418.3C817.2,418.3,817.2,418.3,817.2,418.3L817.2,418.3H667c-7.5,0-15,0-22.5,0c0,0,0,0,0,0l-18.2,0
    c0,0,0,0,0,0c-15.1,0-30.3,0-45.4,0c0,0,0,0,0,0l-18.2,0c0,0,0,0,0,0c-15.1,0-30.3,0-45.4,0c0,0,0,0,0,0.1l-18.2,0c0,0,0,0,0-0.1
    c-15.1,0-30.3,0-45.4,0c0,0,0,0,0,0.1l-18.2,0c0,0,0-0.1,0-0.1c-15.1,0-30.3,0-45.4,0c0,0,0,0.1,0,0.1l-18.2,0c0,0,0-0.1,0-0.1
    c-15.1,0-30.3,0-45.4,0c0,0,0,0.1,0,0.1l-18.2,0c0,0,0-0.1,0-0.1c-15.1,0-30.3,0-45.4,0c0,0,0,0.1-0.1,0.1l-0.2,0l0,0.6
    c-103.7,264.2-103.6,569.9,0.3,834v0h0c15.1,0,30.3,0,45.4,0h18.2c15.1,0,30.3,0,45.4,0h18.2c15.1,0,30.3,0,45.4,0h18.2
    c15.1,0,30.3,0,45.4,0h18.2c15.1,0,30.3,0,45.4,0h18.2c15.1,0,30.3,0,45.4,0h18.2c15.1,0,30.3,0,45.4,0h18.2c15.1,0,30.3,0,45.4,0
    h18.2c15.1,0,30.3,0,45.4,0C921.2,988.7,921.2,682.6,817.2,418.3z M812.2,1096.7l-21.4,0c30.4-170.8,30.4-351.4,0-522.2l21.3,0
    C845.2,745.3,845.2,925.8,812.2,1096.7z M342.5,574.6l21.3,0c-21.3,170.8-21.3,351.4,0,522.2l-21.3,0
    C318.6,926,318.6,745.4,342.5,574.6z M417.2,574.6l21.3,0c-12.3,170.8-12.3,351.4,0,522.2l-21.3,0
    C402.4,926,402.4,745.4,417.2,574.6z M492,574.6l21.3,0c-3.2,170.8-3.2,351.4,0,522.2l-21.3,0C486.1,925.9,486.1,745.4,492,574.6z
     M566.7,574.6l21.3,0c5.8,170.8,5.8,351.4,0,522.2l-21.3,0C569.9,925.9,569.9,745.4,566.7,574.6z M641.4,574.5l21.3,0
    c14.9,170.8,14.9,351.4,0,522.2l-21.3,0C653.7,925.9,653.7,745.3,641.4,574.5z M716.1,574.5l21.3,0c23.9,170.8,23.9,351.4,0,522.2
    l-21.3,0C737.5,925.9,737.5,745.3,716.1,574.5z M807.7,552.6l-21,0c-7.4-38.1-16.3-75.7-26.8-112.6l18.7,0
    C790,476.9,799.7,514.5,807.7,552.6z M734.3,552.7l-21,0c-5.2-38.1-11.5-75.7-18.8-112.6l18.7,0
    C721.4,476.9,728.4,514.5,734.3,552.7z M647.6,440.1c5.1,36.8,9.5,74.4,13.1,112.6l-21,0c-3-38.1-6.6-75.7-10.8-112.6L647.6,440.1z
     M582.1,440.1c2,36.8,3.7,74.4,5.1,112.6l-21,0c-0.8-38.1-1.7-75.7-2.9-112.6L582.1,440.1z M516.6,440.2
    c-1.1,36.8-2.1,74.4-2.9,112.6l-21,0c1.4-38.1,3.1-75.7,5.1-112.6L516.6,440.2z M451.1,440.2c-4.2,36.8-7.8,74.4-10.8,112.6l-21,0
    c3.6-38.1,8-75.7,13.1-112.6L451.1,440.2z M385.5,440.2c-7.3,36.8-13.6,74.4-18.8,112.6l-21,0c5.8-38.1,12.9-75.7,21.1-112.6
    L385.5,440.2z M320,440.2c-10.5,36.8-19.4,74.4-26.8,112.6l-21,0c8-38.1,17.7-75.7,29.1-112.6L320,440.2z M267.8,574.7l21.4,0
    c-30.4,170.8-30.4,351.4,0,522.2l-21.3,0C234.8,926,234.8,745.5,267.8,574.7z M301.4,1231.3c-11.4-36.9-21.1-74.5-29.1-112.6l21,0
    c7.4,38.2,16.4,75.8,26.8,112.6H301.4z M366.9,1231.3c-8.2-36.9-15.3-74.5-21.1-112.7l21,0c5.2,38.2,11.5,75.8,18.8,112.7H366.9z
     M432.4,1231.3c-5.1-36.9-9.5-74.5-13.1-112.7l21,0c3,38.2,6.6,75.8,10.8,112.7H432.4z M497.9,1231.3c-2-36.9-3.7-74.5-5.1-112.7
    l21,0c0.8,38.2,1.7,75.8,2.9,112.7H497.9z M563.4,1231.3c1.1-36.9,2.1-74.5,2.9-112.7l21,0c-1.4,38.2-3.1,75.8-5.1,112.7H563.4z
     M628.9,1231.3c4.2-36.9,7.9-74.6,10.9-112.8l21,0c-3.6,38.2-8,75.9-13.1,112.8H628.9z M694.4,1231.3c7.4-36.9,13.6-74.6,18.9-112.8
    l21,0c-5.8,38.2-12.9,75.9-21.1,112.8H694.4z M759.9,1231.3c10.5-36.9,19.4-74.6,26.9-112.8l21,0c-8,38.2-17.8,75.9-29.1,112.8
    H759.9z"/>
   <line fill="none" stroke="#000000" stroke-width="16.5082" stroke-miterlimit="10" x1="540" y1="418.2" x2="540" y2="0"/>
   </svg>
<div style="height: 100%; width: 100%; z-index: -1;" onclick="changeFust();" id="fust_area"></div>
<script type="text/javascript">
  window.onload = function() {
    refresh();
    setInterval(refresh, 3000);
    }
  function refresh(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
    console.log("state change")
  if (xhttp.readyState == 4 && xhttp.status == 200) {
    document.getElementById("fustLight").style.fill = (xhttp.responseText.charAt(4) == "1") ? "yellow" : "black";
  }
  };
    xhttp.open("GET", "get",true);
    xhttp.send();
    }
function changeFust (){
  var xhttp = new XMLHttpRequest();
  if (document.getElementById("fustLight").style.fill == 'yellow'){
    document.getElementById("fustLight").style.fill = "black";
    xhttp.open("GET", "send?a=A&port=4&state=0",true);
  }else{
    document.getElementById("fustLight").style.fill = "yellow";
    xhttp.open("GET", "send?a=A&port=4&state=1",true);
    }
    xhttp.send();
}
  </script>
</body>
)=====";

#include <RemoteReceiver.h>
#include <RemoteSwitch.h>

#include <NewRemoteReceiver.h>
#include <NewRemoteTransmitter.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>

void setupOTA();
/*
This code controls a trafic light in the living room of 'de tempel van Shostakovich'
A cronjob controlls the
*/


#include "FS.h"


#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
NewRemoteTransmitter transmitter(20231262, D8, 260, 3);

/*
Include the neccesary libraries
*/
#define AMOUNT_OF_LIGHTS 4


bool state[AMOUNT_OF_LIGHTS] = {0,0,0,0};

const char* ssid = "The Shostakovich Network";
const char* password = "Bonkerdbewoner04";

unsigned long timer = 0;
unsigned long shostTimer = 0;
KaKuSwitch kaKuTransmitter(D8);

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
  if (server.hostHeader() == "vestfust.lemio.nl"){
       server.send(200, "text/html", pageFust);
    }else{
       server.send(200, "text/html", page);
    }
  digitalWrite(led, 0);
}
/*
Error message
*/
void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "Host: ";
  message += server.hostHeader();
  message += "\nURI: ";
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
  mySwitch.enableTransmit(D8);
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
     message += state[3];
      message += "]";
    server.send(200, "text/html", message);

  });
  server.on("/send", [](){
     state[server.arg(1).toInt()-1] = (server.arg(2)=="1");
     printf("port: %i & value: %i",server.arg(1).toInt()-1,(server.arg(2)=="1"));
     if (server.arg(1).toInt() == 3){
            kaKuTransmitter.sendSignal(server.arg(0)[0],server.arg(1).toInt(),(server.arg(2)=="1"));
        //digitalWrite(D4, (server.arg(2)=="1"));
        }else{
          if (server.arg(1).toInt() == 4){
            if (server.arg(2)=="1"){
              mySwitch.send(16766036,24);
              }else{
              mySwitch.send(16766033,24);
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
    mySwitch.send(16766033,24);
    state[0] = 0;
    state[1] = 0;
    state[2] = 0;
    state[3] = 0;
    }
}
