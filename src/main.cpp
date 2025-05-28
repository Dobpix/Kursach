#include <Arduino.h>
#include <WiFi.h>
#include "game.h"
#include "GameServer.h" 
#include "joystick.h"

// Задайте свои данные WiFi
const char* ssid = "RMP-Q23";
const char* password = "88888888";

Game game; 
GameServer server(&game); 
Joystick joystick;

void setup() {
    Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected!");
    Serial.print("IP address: ");   
    Serial.println(WiFi.localIP());

    server.begin();
}

void loop() {
    server.handleClient();
    int dir = joystick.processing();
    if (dir) game.step(dir);
    delay(50);
}


// ищем значения в положении покоя для джойстика
// #include <Arduino.h>

// #define X_PIN 39
// #define Y_PIN 36

// void setup() {
//   Serial.begin(9600);        
// }

// void loop() {
//   int x_read = analogRead(X_PIN);  
//   int y_read = analogRead(Y_PIN);  
//   Serial.print("X: ");
//   Serial.print(x_read);
//   Serial.print(", Y: ");
//   Serial.println(y_read);
//   delay(100);  
// }

// #include <WiFi.h>
// #include <WebServer.h>

// /*Put your SSID & Password*/
// const char* ssid = "RMP-Q23";      // Enter SSID here
// const char* password = "88888888";  // Enter Password here

// WebServer server(80);

// uint8_t LED1pin = 2;
// bool LED1status = LOW;

// void handle_OnConnect();
// void handle_led1on();
// void handle_led1off();
// void handle_NotFound();
// String SendHTML(bool led1stat);

// void setup() {
//   Serial.begin(9600);
//   delay(1000);
//   pinMode(LED1pin, OUTPUT);
//   digitalWrite(LED1pin, LED1status);

//   Serial.println("Connecting to ");
//   Serial.println(ssid);

//   // Connect to your local wi-fi network
//   WiFi.begin(ssid, password);

//   // Check wi-fi is connected to wi-fi network
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.print(".");
//   }
//   Serial.println("");
//   Serial.println("WiFi connected..!");
//   Serial.print("Got IP: ");  
//   Serial.println(WiFi.localIP());

//   server.on("/", handle_OnConnect);
//   server.on("/led1on", handle_led1on);
//   server.on("/led1off", handle_led1off);
//   server.onNotFound(handle_NotFound);

//   server.begin();
//   Serial.println("HTTP server started");
// }

// void loop() {
//   server.handleClient();
//   digitalWrite(LED1pin, LED1status);
// }

// void handle_OnConnect() {
//   Serial.println("GPIO2 Status: " + String(LED1status ? "ON" : "OFF"));
//   server.send(200, "text/html", SendHTML(LED1status)); 
// }

// void handle_led1on() {
//   LED1status = HIGH;
//   Serial.println("GPIO2 Status: ON");
//   server.send(200, "text/html", SendHTML(LED1status)); 
// }

// void handle_led1off() {
//   LED1status = LOW;
//   Serial.println("GPIO2 Status: OFF");
//   server.send(200, "text/html", SendHTML(LED1status)); 
// }

// void handle_NotFound(){
//   server.send(404, "text/plain", "Not found");
// }

// String SendHTML(bool led1stat){
//   String ptr = "<!DOCTYPE html> <html>\n";
//   ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
//   ptr +="<title>LED Control</title>\n";
//   ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
//   ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
//   ptr +=".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
//   ptr +=".button-on {background-color: #3498db;}\n";
//   ptr +=".button-on:active {background-color: #2980b9;}\n";
//   ptr +=".button-off {background-color: #34495e;}\n";
//   ptr +=".button-off:active {background-color: #2c3e50;}\n";
//   ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
//   ptr +="</style>\n";
//   ptr +="</head>\n";
//   ptr +="<body>\n";
//   ptr +="<h1>ESP32 Web Server</h1>\n";
//   ptr +="<h3>Using Station(STA) Mode</h3>\n";
  
//   if(led1stat) {
//     ptr +="<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";
//   } else {
//     ptr +="<p>LED1 Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";
//   }

//   ptr +="</body>\n";
//   ptr +="</html>\n";
//   return ptr;
// }