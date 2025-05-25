#include <Arduino.h>
#include <WiFi.h>
#include "game.h"
#include "GameServer.h" 
#include "joystick.h"

// Задайте свои данные WiFi
const char* ssid = "Buza5";
const char* password = "+79051833394";

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
