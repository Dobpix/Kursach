// ищем значения в положении покоя для джойстика
#include <Arduino.h>

#define X_PIN 2
#define Y_PIN 4

void setup() {
  Serial.begin(9600);        
}

void loop() {
  int x_read = analogRead(X_PIN);  
  int y_read = analogRead(Y_PIN);  
  Serial.print("X: ");
  Serial.print(x_read);
  Serial.print(", Y: ");
  Serial.println(y_read);
  delay(100);  
}


