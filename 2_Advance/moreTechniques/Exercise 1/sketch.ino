// Lab 6 - Exercise 1: Light sensor calibration
// Potentiometer on A0 simulates light sensor, LED on pin 8
// First 5 seconds = calibration phase
// After 5 seconds = LED turns ON when dark (below min)

#define SENSOR_PIN A0
#define LED_PIN    8

int sensorValue = 0;
int sensorMin   = 1023;  // start high so any value is lower
int sensorMax   = 0;     // start low so any value is higher

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);

  // CALIBRATION PHASE: first 5 seconds
  Serial.println("=== Calibrating... Move the sensor now! ===");
  Serial.println("You have 5 seconds...");

  while (millis() < 5000) {
    sensorValue = analogRead(SENSOR_PIN);

    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;  // record highest value
    }
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;  // record lowest value
    }
  }

  // Print calibration results
  Serial.println("=== Calibration Complete! ===");
  Serial.print("Min light value: ");
  Serial.println(sensorMin);
  Serial.print("Max light value: ");
  Serial.println(sensorMax);
  Serial.println("Now monitoring... LED turns ON when dark!");
}

void loop() {
  sensorValue = analogRead(SENSOR_PIN);

  Serial.print("Current light: ");
  Serial.print(sensorValue);

  // Turn LED ON when dark (below calibrated minimum threshold)
  if (sensorValue <= sensorMin) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("  → DARK! LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("  → Light OK. LED OFF");
  }

  delay(200);
}