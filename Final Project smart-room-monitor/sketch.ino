#include <WiFi.h>
#include "DHTesp.h"
#include <PubSubClient.h>

// ── Config ──────────────────────────────
const int DHT_PIN = 15;
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* MQTT_BROKER = "test.mosquitto.org";
const char* MQTT_TOPIC = "smart/room";

// ── Objects ─────────────────────────────
DHTesp dhtSensor;
WiFiClient espClient;
PubSubClient mqttClient(espClient);

// ── Auto-Reconnect ───────────────────────
void reconnectMQTT() {
  if (!mqttClient.connected()) {
    Serial.print("🔄 Reconnecting MQTT...");
    String clientId = "ESP32-" + String(random(0xffff), HEX);
    if (mqttClient.connect(clientId.c_str())) {
      Serial.println(" ✅ Reconnected!");
      mqttClient.publish(MQTT_TOPIC, "{\"status\":\"reconnected\"}");
    } else {
      Serial.println(" ❌ Failed state: " + String(mqttClient.state()));
    }
  }
}

// ── Setup ────────────────────────────────
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n🚀 Smart Room Monitor Starting...");

  // DHT22
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  Serial.println("✅ DHT22 ready (GPIO15)");

  // WiFi
  Serial.print("📶 WiFi connecting");
  WiFi.begin(ssid, password, 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi: " + WiFi.localIP().toString());

  // MQTT
  mqttClient.setServer(MQTT_BROKER, 1883);
  Serial.print("📡 MQTT connecting");
  for (int i = 0; i < 5; i++) {
    Serial.print(".");
    String clientId = "ESP32-" + String(random(0xffff), HEX);
    if (mqttClient.connect(clientId.c_str())) {
      Serial.println("\n✅ MQTT connected!");
      mqttClient.publish(MQTT_TOPIC, "{\"status\":\"online\"}");
      break;
    }
    Serial.print(" [" + String(mqttClient.state()) + "]");
    delay(1000);
  }
  Serial.println("Setup done!\n");
}

// ── Loop ─────────────────────────────────
void loop() {
  // Auto-reconnect if dropped
  reconnectMQTT();

  // Read sensor
  TempAndHumidity data = dhtSensor.getTempAndHumidity();

  // Build JSON
  String payload = "{";
  payload += "\"temp\":"     + String(data.temperature, 1) + ",";
  payload += "\"humidity\":" + String(data.humidity, 1)    + ",";
  payload += "\"uptime\":"   + String(millis() / 1000);
  payload += "}";

  // Publish
  if (mqttClient.connected()) {
    mqttClient.publish(MQTT_TOPIC, payload.c_str());
    Serial.print("📤 Sent: ");
  } else {
    Serial.print("⚠️ Not sent: ");
  }

  Serial.println("🌡️ T:" + String(data.temperature, 1) +
                 "°C 💧 H:" + String(data.humidity, 1) + "%");

  mqttClient.loop();
  delay(2000);
}