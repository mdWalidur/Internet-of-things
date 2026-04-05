void setup() {
  Serial.begin(9600);
  Serial.println("=== Exercise 1 Started ===");
}

void loop() {
  // PART 1: Your name (change "YourName" to yours)
  Serial.print("Name: Md Walidur Rahman");
  
  // PART 2: Count seconds since start
  static int counter = 0;
  Serial.print(" | Seconds: ");
  Serial.print(counter);
  
  // PART 3: Reset counter at 10
  counter++;
  if (counter >= 11) {
    counter = 0;
    Serial.println(" | RESET!");
  } else {
    Serial.println("");
  }
  
  delay(1000);
}