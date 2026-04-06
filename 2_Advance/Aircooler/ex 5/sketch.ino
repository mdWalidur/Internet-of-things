// Lab 7 - Exercise 5: Emergency shutdown with touch sensor ISR
// DHT22 on pin 2, Servo on pin 5, Relay on pin 7, Touch on pin 3
// Pin 3 is used because it supports interrupts on Arduino Uno (pins 2 and 3)

#include <Servo.h>
#include <DHT.h>

#define DHT_PIN      2
#define DHT_TYPE     DHT22
#define SERVO_PIN    5
#define RELAY_PIN    7
#define TOUCH_PIN    3   // must be pin 2 or 3 on Uno for interrupts
#define TEMP_MIN     0
#define TEMP_MAX     50
#define TEMP_LIMIT   28

DHT dht(DHT_PIN, DHT_TYPE);
Servo myservo;

// volatile = can be changed inside an interrupt
volatile bool emergencyStop = false;

// ISR - runs IMMEDIATELY when touch sensor is pressed
// Keep it short: just set the flag
void myISR() {
  emergencyStop = true;
}

void shutdown() {
  myservo.write(0);               // servo to 0°
  digitalWrite(RELAY_PIN, LOW);   // relay OFF = fan OFF
  Serial.println("🛑 EMERGENCY STOP! System shut down.");
  Serial.println("   Reset Arduino to restart.");
  while (true) {
    // infinite loop — system halted forever
    // program does NOT resume when touch is released
  }
}

void setup() {
  Serial.begin(9600);
  dht.begin();
  myservo.attach(SERVO_PIN);
  myservo.write(0);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  pinMode(TOUCH_PIN, INPUT);

  // Attach interrupt: call myISR when TOUCH_PIN goes LOW→HIGH (RISING)
  attachInterrupt(digitalPinToInterrupt(TOUCH_PIN), myISR, RISING);

  Serial.println("=== Lab 7 Exercise 5: Emergency Stop ===");
  Serial.println("Touch sensor active. Touch = SHUTDOWN.");
}

void loop() {
  // Check emergency flag at start of every loop
  if (emergencyStop) {
    shutdown();
  }

  delay(2000);

  // Check again after delay (in case touch happened during delay)
  if (emergencyStop) {
    shutdown();
  }

  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT22 read error!");
    return;
  }

  // Servo = thermometer pointer
  int angle = map(temperature, TEMP_MIN, TEMP_MAX, 0, 180);
  angle = constrain(angle, 0, 180);
  myservo.write(angle);

  // Relay = fan switch
  if (temperature > TEMP_LIMIT) {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("🔥 HOT! Relay ON (fan running)");
  } else {
    digitalWrite(RELAY_PIN, LOW);
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