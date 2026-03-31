#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22
#define LEDPIN 13

DHT dht(DHTPIN, DHTTYPE);

const float TEMP_THRESHOLD = 28.0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("ERROR,NaN,NaN");
    delay(2000);
    return;
  }

  if (t > TEMP_THRESHOLD) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }

  unsigned long ts = millis();
  Serial.print(ts);
  Serial.print(",");
  Serial.print(t, 2);
  Serial.print(",");
  Serial.println(h, 2);

  delay(1000);
}