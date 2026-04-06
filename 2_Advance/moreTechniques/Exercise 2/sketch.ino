// Lab 6 - Exercise 2: Running average of sound sensor (10 values)
// Potentiometer on A0 simulates sound sensor
// Prints RAW and AVERAGE values for Serial Plotter comparison

#define INPUT_PIN   A0
#define NUM_READINGS 10

int readings[NUM_READINGS];  // array of last 10 readings
int readIndex = 0;
int total     = 0;
int average   = 0;

void setup() {
  Serial.begin(9600);
  // Initialize all readings to 0
  for (int i = 0; i < NUM_READINGS; i++) {
    readings[i] = 0;
  }
}

void loop() {
  // Remove oldest value from total
  total = total - readings[readIndex];

  // Read new sensor value
  readings[readIndex] = analogRead(INPUT_PIN);

  // Add new value to total
  total = total + readings[readIndex];

  // Move to next index (loops back to 0 after 9)
  readIndex = (readIndex + 1) % NUM_READINGS;

  // Calculate average
  average = total / NUM_READINGS;

  // Print BOTH values for Serial Plotter
  // Serial Plotter reads "Raw:value Average:value" format
  Serial.print("Raw:");
  Serial.print(readings[(readIndex - 1 + NUM_READINGS) % NUM_READINGS]);
  Serial.print(" Average:");
  Serial.println(average);

  delay(20);
}