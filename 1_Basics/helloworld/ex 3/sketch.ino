// Lab 1 Exercise 3: Count seconds, reset to 0 when it reaches 10

int counter = 0;  // our manual counter variable

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Counter: ");
  Serial.println(counter);

  counter++;  // add 1 each second

  // Reset back to 0 when counter reaches 10
  if (counter >= 10) {
    counter = 0;
  }

  delay(1000);
}