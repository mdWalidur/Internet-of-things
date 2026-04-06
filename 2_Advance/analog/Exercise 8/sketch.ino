// Lab 5 - Exercise 8: LED turns ON when serial message received
// LED on pin 8
// Type anything in Serial Monitor → LED turns ON for 2 seconds

#define LED_PIN 8

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== Exercise 8: Serial → LED ===");
  Serial.println("Type any message and press Enter to turn on LED!");
}

void loop() {
  if (Serial.available() > 0) {
    // Read and clear the serial buffer
    String message = Serial.readString();

    Serial.print("Received: ");
    Serial.println(message);
    Serial.println("LED ON!");

    // Turn LED ON
    digitalWrite(LED_PIN, HIGH);
    delay(2000);  // stay on 2 seconds

    // Turn LED OFF
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF - waiting for next message...");
  }
}