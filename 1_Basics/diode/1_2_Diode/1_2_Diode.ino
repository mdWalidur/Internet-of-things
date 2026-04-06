const int LED_PIN = 13;

unsigned long previousMillis = 0;
unsigned long startMillis = 0;
unsigned long currentMillis = 0;

bool ledState = LOW;
unsigned long ledInterval = 2000;   // off time
unsigned long onTime = 500;         // on time
unsigned long lastToggleTime = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  startMillis = millis();
  previousMillis = millis();
  lastToggleTime = millis();
}

void loop() {
  currentMillis = millis();

  if (ledState == HIGH && currentMillis - lastToggleTime >= onTime) {
    ledState = LOW;
    digitalWrite(LED_PIN, ledState);
    lastToggleTime = currentMillis;
  }

  if (ledState == LOW && currentMillis - lastToggleTime >= ledInterval) {
    ledState = HIGH;
    digitalWrite(LED_PIN, ledState);
    lastToggleTime = currentMillis;
  }

  Serial.print("Running for ");
  Serial.print((currentMillis - startMillis) / 1000);
  Serial.println(" seconds");

  delay(100);
}