// Final Code for Lab 3: PWM Blink + Fade In/Out

const int ledPin = 9; // PWM pin (~ symbol)

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  // --- Task 3: Blink using analogWrite ---
  analogWrite(ledPin, 255); // LED ON (full brightness)
  delay(1000);              // 1 second

  analogWrite(ledPin, 0);   // LED OFF
  delay(1000);              // 1 second

  // --- Task 4: Fade IN (0 → 255) ---
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);
    delay(10); // fade speed
  }

  // --- Fade OUT (255 → 0) ---
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(10);
  }
}
