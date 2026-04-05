# Internet of Things 

This repository contains my solutions for course exercises and Final project in the Internet of Things.  
All **Basic**, **Advanced**, and **Communication** tasks are stored in a single repository, following the course requirements.

---

## 📁 Repository Structure

### **1_Basics/**
Solutions to the Basic exercises:
- `1_1_HelloWorld.md` [text](https://wokwi.com/projects/460487496102619137)
- `1_2_Diode.md`
- `1_3_DiodeFade.md`
- `1_4_Button.md`

---

### **2_Advance/**
Solutions to the Advanced exercises:
- `2_1_Analog.md` — from **5 Analog.pdf**
- `2_2_MoreTechniques.md` — from **6 more techniques.pdf**
- `2_3_AirCooler.md` — from **7 air cooler.pdf**
- `2_4_TransmitData_OPTIONAL.md` — from **8 transmit data OPTIONAL.pdf**

> Note: Task 'transmit data' is optional. It helps understand how communication protocols (like I2C) transmit bit sequences.

---

### **3_Communication/**
Solutions to the Communication exercises:
- `3_1_CommunicationBasics.md` — from **9 communication basics.pdf**
- `3_2_AddingDatabase.md` — from **10 adding a database.pdf**

---
transmit data
## 📌 Folder names

To make the structure easy to navigate:

- Folder names match the exercise groups:
  - `1_Basics`
  - `2_Advance`
  - `3_Communication`

  ------

# Final Project Smart Room Monitor 🌡️

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
