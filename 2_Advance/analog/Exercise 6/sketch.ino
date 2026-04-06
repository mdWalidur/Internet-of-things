// Lab 5 - Exercise 6: Potentiometer → Servo Position
// Potentiometer on A0, Servo on pin 5
// Turn knob → servo turns same amount

#include <Servo.h>

#define POT_PIN A0

Servo myservo;

void setup() {
  myservo.attach(5);
  Serial.begin(9600);
  Serial.println("=== Exercise 6: Pot controls Servo ===");
}

void loop() {
  int potValue  = analogRead(POT_PIN);           // 0–1023
  int angle     = map(potValue, 0, 1023, 0, 180); // remap to 0–180°

  myservo.write(angle);

  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print("  → Angle: ");
  Serial.print(angle);
  Serial.println("°");

  delay(15);
}