// Lab 5 - Exercise 4: Potentiometer → LED Brightness
// Potentiometer on A0, LED on pin 9 (PWM ~ pin)
// map() converts 0–1023 → 0–255 for analogWrite

#define POT_PIN A0
#define LED_PIN 9   // must be PWM pin (~)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== Exercise 4: Pot controls LED Brightness ===");
}

void loop() {
  int potValue   = analogRead(POT_PIN);           // 0–1023
  int brightness = map(potValue, 0, 1023, 0, 255); // remap to 0–255

  analogWrite(LED_PIN, brightness);  // set LED brightness

  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print("  → Brightness: ");
  Serial.println(brightness);

  delay(100);
}