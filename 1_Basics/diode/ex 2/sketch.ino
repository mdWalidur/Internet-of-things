// Lab 2 Exercise 2: LED blink using millis() — Arduino NOT blocked
// This means other code can run while LED is blinking

#define LED_PIN 9

unsigned long lastChange = 0;  // when did LED last change?
bool ledState = false;         // is LED currently ON or OFF?

// LED is ON for 500ms, OFF for 2000ms
const int ON_TIME  = 500;
const int OFF_TIME = 2000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();

  // How long should current state last?
  int waitTime = ledState ? ON_TIME : OFF_TIME;

  if (now - lastChange >= waitTime) {
    ledState = !ledState;                    // flip ON/OFF
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    lastChange = now;                        // reset timer
  }

  // Arduino is FREE here — not blocked by delay!
  // Other code can run in this space
}