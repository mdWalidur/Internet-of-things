// Lab 4 Exercise 5: Short press → LED, Long press → Buzzer
// Short = less than 5 seconds, Long = more than 5 seconds

#define BUTTON_PIN 2
#define LED_PIN    3
#define BUZZ_PIN   4
#define LONG_PRESS 5000   // 5000ms = 5 seconds

unsigned long pressStart = 0;
bool pressing = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN,    OUTPUT);
  pinMode(BUZZ_PIN,   OUTPUT);
  Serial.begin(9600);
  Serial.println("=== Ready. Press the button! ===");
}

void loop() {
  bool btn = digitalRead(BUTTON_PIN);

  // Button just pressed (HIGH → LOW)
  if (btn == LOW && !pressing) {
    pressStart = millis();
    pressing = true;
    Serial.println("Button pressed... holding");
  }

  // Button just released (LOW → HIGH)
  if (btn == HIGH && pressing) {
    unsigned long duration = millis() - pressStart;
    pressing = false;

    Serial.print("Held for: ");
    Serial.print(duration);
    Serial.println("ms");

    if (duration < LONG_PRESS) {
      // Short press → LED on 2 seconds
      Serial.println("SHORT press → LED ON for 2s");
      digitalWrite(LED_PIN, HIGH);
      delay(2000);
      digitalWrite(LED_PIN, LOW);
    } else {
      // Long press → Buzzer on 2 seconds
      Serial.println("LONG press → BUZZER ON for 2s");
      digitalWrite(BUZZ_PIN, HIGH);
      delay(2000);
      digitalWrite(BUZZ_PIN, LOW);
    }

    Serial.println("=== Ready. Press the button! ===");
  }
}