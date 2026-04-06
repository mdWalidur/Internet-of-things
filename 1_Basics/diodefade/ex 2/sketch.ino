// Lab 3 Exercise 2: LED slowly fades in then fades out

#define LED_PIN 9

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== LED Fade In & Out ===");
}

void loop() {
  // Fade IN: 0 → 255 (dark to bright)
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(LED_PIN, brightness);
    delay(8);
  }
  Serial.println("MAX brightness reached ↑");

  // Fade OUT: 255 → 0 (bright to dark)
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(LED_PIN, brightness);
    delay(8);
  }
  Serial.println("OFF - starting again ↓");
}