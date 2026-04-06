// Lab 5 - Exercise 5: Servo Motor Sweep
// Servo on pin 5 — sweeps 0° → 180° → 0° continuously
// Exactly the lab code from 5-Analog.pdf

#include <Servo.h>

Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(5);  // servo on pin 5
  Serial.begin(9600);
  Serial.println("=== Exercise 5: Servo Sweep ===");
}

void loop() {
  // Sweep 0 → 180 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    Serial.print("Position: ");
    Serial.println(pos);
    delay(15);
  }

  // Sweep 180 → 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    Serial.print("Position: ");
    Serial.println(pos);
    delay(15);
  }
}