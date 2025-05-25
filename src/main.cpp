#include <Arduino.h>
#include <WiFi.h>
#include "game.h"
#include "server.h"

// Задайте свои данные WiFi
const char* ssid = "Buza5"; // Введите SSID вашей сети
const char* password = "+79051833394";

Game game;
Server server(&game);

void setup() {
    Serial.begin(9600);
    // Подключение к WiFi
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
