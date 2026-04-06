// Lab 9: Send "Hello World!" to MQTT broker
// Board: ESP32
// Broker: broker.hivemq.com

#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid       = "Wokwi-GUEST";
const char* password   = "";
const char* mqttServer = "broker.hivemq.com";
const int   mqttPort   = 1883;
const char* topic      = "student/lab9/hello";
const char* clientId   = "esp32-lab9-student01";

WiFiClient   espClient;
PubSubClient client(espClient);

void connectWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected! IP: " + WiFi.localIP().toString());
}

void connectMQTT() {
  Serial.print("Connecting to MQTT broker");
  while (!client.connected()) {
    if (client.connect(clientId)) {
      Serial.println("\nMQTT connected!");
    } else {
      Serial.print(".");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  connectWiFi();
  client.setServer(mqttServer, mqttPort);
  connectMQTT();

  bool success = client.publish(topic, "Hello World!");
  if (success) {
    Serial.println("✅ Message sent: 'Hello World!'");
    Serial.print("   Topic: ");
    Serial.println(topic);
  } else {
    Serial.println("❌ Publish failed.");
  }
}

void loop() {
  if (!client.connected()) {
    connectMQTT();
  }
  client.loop();

  static unsigned long lastMsg = 0;
  if (millis() - lastMsg > 5000) {
    lastMsg = millis();
    client.publish(topic, "Hello World!");
    Serial.println("📤 Sent: Hello World!");
  }
}