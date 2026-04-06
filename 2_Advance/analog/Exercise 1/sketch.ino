#define TOUCH_PIN A0
#define LED_PIN   8

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(TOUCH_PIN);  // reads 0–1023
  Serial.println(value);              // print raw value

  if (value > 512) {                  // above half = "touched"
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}