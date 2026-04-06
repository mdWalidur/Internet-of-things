// Lab 7 - Exercise 3: Temperature controls servo position
// DHT22 on pin 2, Servo on pin 5
// Servo acts as a thermometer pointer

#include <Servo.h>
#include <DHT.h>

#define DHT_PIN  2
#define DHT_TYPE DHT22
#define SERVO_PIN 5

// Temperature range for servo mapping
#define TEMP_MIN 0    // 0°C   → servo 0°
#define TEMP_MAX 50   // 50°C  → servo 180°

DHT dht(DHT_PIN, DHT_TYPE);
Servo myservo;

void setup() {
  Serial.begin(9600);
  dht.begin();
  myservo.attach(SERVO_PIN);
  myservo.write(0);  // start at 0°
  Serial.println("=== Lab 7 Exercise 3: Temperature → Servo ===");
}

void loop() {
  delay(2000);  // DHT22 needs 2s between readings

  float temperature = dht.readTemperature();  // Celsius
  float humidity    = dht.readHumidity();

  // Check if reading is valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT22 read error!");
    return;
  }

  // Map temperature to servo angle
  int angle = map(temperature, TEMP_MIN, TEMP_MAX, 0, 180);
  angle = constrain(angle, 0, 180);  // keep within 0–180

  myservo.write(angle);

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("°C  | Humidity: ");
  Serial.print(humidity);
  Serial.print("%  | Servo angle: ");
  Serial.print(angle);
  Serial.println("°");
}