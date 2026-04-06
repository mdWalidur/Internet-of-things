// Lab 5 - Exercise 7: Serial Monitor Send & Receive
// Exact lab code from 5-Analog.pdf + helpful output added

int incomingByte = 0;  // for incoming serial data

void setup() {
  Serial.begin(9600);
  Serial.println("=== Exercise 7: Serial Receive ===");
  Serial.println("Type a message in Serial Monitor and press Send!");
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);  // prints as decimal number
  }
}