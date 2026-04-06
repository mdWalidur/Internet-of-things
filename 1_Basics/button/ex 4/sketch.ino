#define BUTTON_PIN 2
#define LED_PIN    3

bool ledState    = false;
bool lastBtn     = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN,    OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool currentBtn = digitalRead(BUTTON_PIN);

  // Detect press moment (HIGH → LOW transition)
  if (lastBtn == HIGH && currentBtn == LOW) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    Serial.println(ledState ? "LED ON" : "LED OFF");
  }

  lastBtn = currentBtn;
  delay(50);  // debounce
}