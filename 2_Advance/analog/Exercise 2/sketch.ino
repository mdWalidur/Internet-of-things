// Lab 5 - Exercise 2: Rotary Angle Sensor → Serial Monitor
// Potentiometer on A0

#define POT_PIN A0

void setup() {
  pinMode(POT_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("=== Exercise 2: Potentiometer Reading ===");
}

void loop() {
  int value = analogRead(POT_PIN);  // reads 0–1023

  Serial.print("Sensor Value: ");
  Serial.println(value);

  delay(200);
}