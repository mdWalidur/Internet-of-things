# Smart Room Monitor 🌡️

## Description
IoT project: ESP32 + DHT22 sensor publishes 
temperature/humidity via MQTT. 
Python Flask server receives data and shows 
live graph on web dashboard.

## Tech Stack
- ESP32 (Wokwi simulator)
- DHT22 sensor
- MQTT (test.mosquitto.org)
- Python Flask + Socket.IO
- Chart.js live dashboard

## Setup
1. Open Wokwi: (https://wokwi.com/projects/460027800656399361)
2. Run Python: pip install -r requirements.txt
3. Start server: python app.py
4. Open: http://localhost:5000

## Architecture
ESP32 → MQTT → Python → Socket.IO → Browser
