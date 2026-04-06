// Lab 6 - Exercise 3: LED blink according to bitmask
// Works for ANY 8-bit bitmask input
// LED on pin 8

#define LED_PIN    8
#define BIT_DELAY  200  // ms per bit (change to make faster/slower)

// ===== CHANGE THIS BITMASK TO TEST DIFFERENT PATTERNS =====
// 10101010 = fast blinking
// 11001100 = slow blinking
// 10001000 = short on, long off
// 11111111 = always on
// 00000000 = always off
String bitmask = "10001000";
// ===========================================================

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.print("Bitmask: ");
  Serial.println(bitmask);
  Serial.println("Starting LED pattern...");
}

void loop() {
  for (int i = 0; i < bitmask.length(); i++) {
    if (bitmask[i] == '1') {
      digitalWrite(LED_PIN, HIGH);  // LED ON
      Serial.print("1 ");
    } else {
      digitalWrite(LED_PIN, LOW);   // LED OFF
      Serial.print("0 ");
    }
    delay(BIT_DELAY);  // wait per bit
  }
  Serial.println();  // new line after each full pattern
}