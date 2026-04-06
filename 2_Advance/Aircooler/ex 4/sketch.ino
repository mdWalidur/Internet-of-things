// Lab 7 - Exercise 4: Temp → Servo + Relay ON when temp > 28°C
// DHT22 on pin 2, Servo on pin 5, Relay on pin 7

#include <Servo.h>
#include <DHT.h>

#define DHT_PIN    2
#define DHT_TYPE   DHT22
#define SERVO_PIN  5
#define RELAY_PIN  7
#define TEMP_MIN   0
#define TEMP_MAX   50
#define TEMP_LIMIT 28  // relay activates above this

DHT dht(DHT_PIN, DHT_TYPE);
Servo myservo;

void setup() {
  Serial.begin(9600);
  dht.begin();
  myservo.attach(SERVO_PIN);
  myservo.write(0);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // relay OFF at start
  Serial.println("=== Lab 7 Exercise 4: Temp + Relay ===");
}

void loop() {
  delay(2000);

  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT22 read error!");
    return;
  }

  // Servo = thermometer
  int angle = map(temperature, TEMP_MIN, TEMP_MAX, 0, 180);
  angle = constrain(angle, 0, 180);
  myservo.write(angle);

  // Relay = cooling switch
  if (temperature > TEMP_LIMIT) {
    digitalWrite(RELAY_PIN, HIGH);  // close relay = fan ON
    Serial.println("🔥 HOT! Relay ON (fan running)");
  } else {
    digitalWrite(RELAY_PIN, LOW);   // open relay = fan OFF
    Serial.println("✅ Cool. Relay OFF");
  }

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("°C | Humidity: ");
  Serial.print(humidity);
  Serial.print("% | Servo: ");
  Serial.print(angle);
  Serial.println("°");
}