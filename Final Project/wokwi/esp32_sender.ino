#include <WiFi.h>
#include "DHTesp.h"
#include <PubSubClient.h>

const int DHT_PIN = 15;
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* MQTT_BROKER = "broker.hivemq.com";
const char* MQTT_CLIENT_ID = "TobiasClient";
const char* MQTT_TOPIC = "example/topic";

DHTesp dhtSensor;
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("=== SMART ROOM MONITOR START ===");
  
  // DHT Setup
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  delay(2000);  // DHT stabilize
  Serial.println("DHT22 ready on pin 15");
  
  // WiFi
  Serial.print("Connecting WiFi '"); Serial.print(ssid); Serial.print("'...");
  WiFi.begin(ssid, password, 6);
  int wifi_tries = 0;
  while (WiFi.status() != WL_CONNECTED && wifi_tries < 20) {
    delay(500);
    Serial.print(".");
    wifi_tries++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi OK! IP: " + WiFi.localIP().toString());
  } else {
    Serial.println("\nWiFi FAIL - Restarting...");
    ESP.restart();
    return;
  }
  
  // MQTT
  client.setServer(MQTT_BROKER, 1883);
  Serial.print("MQTT connect to "); Serial.print(MQTT_BROKER); Serial.print("...");
  int mqtt_tries = 0;
  while (!client.connected() && mqtt_tries < 10) {
    if (client.connect(MQTT_CLIENT_ID)) {
      Serial.println("\nMQTT OK!");
      client.publish(MQTT_TOPIC, "{\"device\":\"ESP32\",\"status\":\"online\"}");
      break;
    } else {
      Serial.print(" fail(" + String(client.state()) + ") ");
      delay(2000);
      mqtt_tries++;
    }
  }
  if (!client.connected()) {
    Serial.println("\nMQTT FAIL - Continuing without...");
  }
  Serial.println("Setup complete!");
}

void loop() {
  // Read sensor
  delay(1000);  // DHT rate limit
  TempAndHumidity data = dhtSensor.getTempAndHumidity();
  
  // Publish if connected
  if (client.connected()) {
    String json = "{\"temp\":" + String(data.temperature, 1) + 
                  ",\"hum\":" + String(data.humidity, 1) + 
                  ",\"uptime\":" + String(millis()/1000) + "}";
    client.publish(MQTT_TOPIC, json.c_str());
  }
  
  // Print
  Serial.println("T:" + String(data.temperature, 1) + "°C H:" + 
                 String(data.humidity, 1) + "%");
  
  delay(2000);
}