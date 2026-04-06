// Lab 5 - Exercise 14: Potentiometer controls buzzer pitch
// Potentiometer on A0, Buzzer on pin 8
// Turn knob → buzzer pitch changes

#define POT_PIN    A0
#define BUZZER_PIN 8

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== Exercise 14: Pot controls Buzzer Pitch ===");
}

void loop() {
  int potValue = analogRead(POT_PIN);          // 0–1023
  int frequency = map(potValue, 0, 1023, 100, 2000); // 100Hz–2000Hz

  tone(BUZZER_PIN, frequency);  // play frequency

  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print("  → Frequency: ");
  Serial.print(frequency);
  Serial.println(" Hz");

  delay(50);
}