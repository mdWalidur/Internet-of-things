#define BUTTON_PIN 2
#define LED_PIN    3

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int btn = digitalRead(BUTTON_PIN);
  if (btn == LOW) {           // LOW = pressed (INPUT_PULLUP logic)
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}