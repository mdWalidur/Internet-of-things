// Lab 2 Exercise 1: LED ON 0.5s, OFF 2s using delay()
#define LED_PIN 9

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED ON
  delay(500);                   // wait 0.5 seconds
  digitalWrite(LED_PIN, LOW);   // LED OFF
  delay(2000);                  // wait 2 seconds
}