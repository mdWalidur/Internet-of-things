void setup() {
  Serial.begin(9600);
}

void loop() {
  int seconds = millis() / 1000;  // millis() = ms since start
  Serial.print("Seconds since start: ");
  Serial.println(seconds);
  delay(1000);
}