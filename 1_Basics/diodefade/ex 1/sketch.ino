// Lab 3 Exercise 1: Blink using analogWrite
// PIN 9 has PWM (~) on Arduino Uno

#define LED_PIN 9

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN, 255);  // Full brightness ON
  delay(1000);                // 1 second
  analogWrite(LED_PIN, 0);    // OFF
  delay(1000);                // 1 second
}