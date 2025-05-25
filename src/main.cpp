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
        delay(500);
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
}
