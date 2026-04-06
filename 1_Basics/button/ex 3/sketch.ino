#define BUTTON_PIN 2
#define LED_PIN    3
#define BUZZ_PIN   4

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN,    OUTPUT);
  pinMode(BUZZ_PIN,   OUTPUT);
}

void loop() {
  int btn = digitalRead(BUTTON_PIN);
  if (btn == LOW) {             // pressed
    digitalWrite(BUZZ_PIN, HIGH);
    digitalWrite(LED_PIN,  LOW);
  } else {                      // not pressed
    digitalWrite(BUZZ_PIN, LOW);
    digitalWrite(LED_PIN,  HIGH);
  }
}