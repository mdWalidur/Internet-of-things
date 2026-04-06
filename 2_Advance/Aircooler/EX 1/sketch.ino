// Lab 7 - Exercise 1: Servo Sweep 0° → 180° → 0°
// Servo on pin 5 — exact lab code from 7-air-cooler.pdf

#include <Servo.h>

Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(5);
  Serial.begin(9600);
  Serial.println("=== Lab 7 Exercise 1: Servo Sweep ===");
}

void loop() {
  // Sweep 0 → 180
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    Serial.print("Position: ");
    Serial.println(pos);
    delay(15);
  }

  // Sweep 180 → 0
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    Serial.print("Position: ");
    Serial.println(pos);
    delay(15);
  }
}