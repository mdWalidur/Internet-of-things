// Lab 9: Receive MQTT messages via subscription
// Board: ESP32
// Broker: broker.hivemq.com
// Topic: student/lab9/hello (same topic as send exercise)

#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid       = "Wokwi-GUEST";
const char* password   = "";
const char* mqttServer = "broker.hivemq.com";
const int   mqttPort   = 1883;
const char* topic      = "student/lab9/hello";
const char* clientId   = "esp32-lab9-receiver01"; // different from sender!

WiFiClient   espClient;
PubSubClient client(espClient);

// This function runs AUTOMATICALLY when a message arrives
void onMessageReceived(char* topic, byte* payload, unsigned int length) {
  // Convert payload bytes to a readable string
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.println("📨 Message received!");
  Serial.print("   Topic  : ");
  Serial.println(topic);
  Serial.print("   Message: ");
  Serial.println(message);
  Serial.println("----------------------------");
}

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

      // Subscribe to the topic
      client.subscribe(topic);
      Serial.print("✅ Subscribed to: ");
      Serial.println(topic);
      Serial.println("Waiting for messages...");
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
  client.setCallback(onMessageReceived); // register the receive function
  connectMQTT();
}

void loop() {
  // Reconnect if connection drops
  if (!client.connected()) {
    connectMQTT();
  }
  // MUST call this — it checks for incoming messages
  client.loop();
}