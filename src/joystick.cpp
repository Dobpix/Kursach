#include "joystick.h"

#define X_PIN 39
#define Y_PIN 36

int Joystick::processing() {
    int x = analogRead(X_PIN);
    int y = analogRead(Y_PIN);

    if (y == 0) {
        Serial.println("forward");
        return 1;
    }
    if (y == 4095) {
        Serial.println("backward");
        return 2;
    }
    if (x == 0) {
        Serial.println("left");
        return 3;
    }
    if (x == 4095) {
        Serial.println("right");
        return 4;
    }
    return 0;
}