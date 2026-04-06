// Lab 5 - Exercise 15: Serial message → Servo position
// Send "0" to "180" in Serial Monitor → servo moves to that angle
// Servo on pin 5

#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(5);
  myservo.write(0);  // start at 0°
  Serial.begin(9600);
  Serial.println("=== Exercise 15: Serial → Servo ===");
  Serial.println("Type a number 0-180 and press Enter!");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');  // read full number
    input.trim();                                  // remove spaces/newlines

    int angle = input.toInt();  // convert "90" → 90

    // Validate angle is within 0–180
    if (angle >= 0 && angle <= 180) {
      myservo.write(angle);
      Serial.print("Moving servo to: ");
      Serial.print(angle);
      Serial.println("°");
    } else {
      Serial.println("Error! Enter a number between 0 and 180.");
    }
  }
}