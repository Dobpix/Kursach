#include "joystick.h"

#define X_PIN 39
#define Y_PIN 36

int lastDirection = 0;  // глобальная переменная для хранения предыдущего направления

int Joystick::processing() {
    int x = analogRead(X_PIN);
    int y = analogRead(Y_PIN);

    int currentDir = 0;

    if (y == 0 && x < 2000 && x > 1800) {
        currentDir = 1; // forward
    }
    else if (y == 4095 && x < 2000 && x > 1800) {
        currentDir = 2; // backward
    }
    else if (x == 0 && y < 2000 && y > 1800) {
        currentDir = 3; // left
    }
    else if (x == 4095 && y < 2000 && y > 1800) {
        currentDir = 4; // right
    }

    if (currentDir != lastDirection) {
        lastDirection = currentDir;
        switch (currentDir) {
            case 1: Serial.println("forward"); break;
            case 2: Serial.println("backward"); break;
            case 3: Serial.println("left"); break;
            case 4: Serial.println("right"); break;
        }
        return currentDir;
    }

    return 0;
}
