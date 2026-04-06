// Lab 2 Exercise 3: Blink LED + print seconds — simultaneously
// millis() allows both to happen at the same time

#define LED_PIN 9

unsigned long lastLedChange  = 0;
unsigned long lastSecPrint   = 0;
bool ledState = false;

const int ON_TIME  = 500;
const int OFF_TIME = 2000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== Lab 2 Exercise 3: Blink + Timer ===");
}

void loop() {
  unsigned long now = millis();

  // --- LED blink logic ---
  int waitTime = ledState ? ON_TIME : OFF_TIME;
  if (now - lastLedChange >= waitTime) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    lastLedChange = now;
    Serial.println(ledState ? "LED ON 💡" : "LED OFF");
  }

  // --- Print seconds every 1 second ---
  if (now - lastSecPrint >= 1000) {
    lastSecPrint = now;
    Serial.print("Running for: ");
    Serial.print(now / 1000);
    Serial.println(" seconds");
  }
}