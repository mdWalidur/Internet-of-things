// Lab 5 - Exercise 3: Potentiometer → LED ON/OFF
// Potentiometer on A0, LED on pin 8
// Above half (>512) = LED ON | Below half (<512) = LED OFF

#define POT_PIN A0
#define LED_PIN 8

void setup() {
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== Exercise 3: Pot controls LED ===");
}

void loop() {
  int value = analogRead(POT_PIN);  // 0–1023

  Serial.print("Value: ");
  Serial.print(value);

  if (value > 512) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("  → LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("  → LED OFF");
  }

  delay(200);
}