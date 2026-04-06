// Lab 4 Exercise 6: Long press detected WHILE still holding
// Like a phone power button — buzzer fires AT 5 seconds, no need to release

#define BUTTON_PIN 2
#define LED_PIN    3
#define BUZZ_PIN   4
#define LONG_PRESS 5000   // 5 seconds

unsigned long pressStart     = 0;
bool pressing                = false;
bool longPressTriggered      = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN,    OUTPUT);
  pinMode(BUZZ_PIN,   OUTPUT);
  Serial.begin(9600);
  Serial.println("=== Ready. Press the button! ===");
}

void loop() {
  bool btn = digitalRead(BUTTON_PIN);

  // Button just pressed
  if (btn == LOW && !pressing) {
    pressStart         = millis();
    pressing           = true;
    longPressTriggered = false;
    Serial.println("Button pressed... holding");
  }

  // Button still held — check if 5 seconds reached
  if (btn == LOW && pressing && !longPressTriggered) {
    unsigned long heldFor = millis() - pressStart;

    if (heldFor >= LONG_PRESS) {
      longPressTriggered = true;   // only trigger once
      Serial.println("5s reached → BUZZER ON! (still holding)");
      digitalWrite(BUZZ_PIN, HIGH);
      delay(2000);
      digitalWrite(BUZZ_PIN, LOW);
      Serial.println("=== Ready. Press the button! ===");
    }
  }

  // Button released
  if (btn == HIGH && pressing) {
    pressing = false;

    if (!longPressTriggered) {
      // Released before 5s = short press → LED
      Serial.println("Short press → LED ON for 2s");
      digitalWrite(LED_PIN, HIGH);
      delay(2000);
      digitalWrite(LED_PIN, LOW);
      Serial.println("=== Ready. Press the button! ===");
    }
  }
}