# Internet of Things 

This repository contains my solutions for course exercises and Final project in the Internet of Things.  
All **Basic**, **Advanced**, and **Communication** tasks are stored in a single repository, following the course requirements.

---

## 📁 Repository Structure

### **1_Basics/**
Solutions to the Basic exercises:

- **helloworld/** — Hello World examples
  - [ex 1](https://wokwi.com/projects/460504251990994945) | [ex 2](https://wokwi.com/projects/460504251990994945) | [ex 3](https://wokwi.com/projects/460504251990994945)

- **diode/** — Diode exercises
  - 1_2_Diode.ino (main example)
  - [ex 1](https://wokwi.com/projects/460504251990994945) | [ex 2](https://wokwi.com/projects/460504251990994945) | [ex 3](https://wokwi.com/projects/460505546354316289)

- **diodefade/** — Diode Fade exercises
  - 1_3_DiodeFade.ino (main example)
  - [ex 1](https://wokwi.com/projects/460506066697594881) | [ex 2](https://wokwi.com/projects/460506066697594881)

- **button/** — Button exercises
  - 1_4_Button.ino (main example)
  - [ex 1](https://wokwi.com/projects/460506630306178049) | [ex 2](https://wokwi.com/projects/460506630306178049) | [ex 3](https://wokwi.com/projects/460506630306178049) | [ex 4](https://wokwi.com/projects/460506630306178049) | [ex 5](https://wokwi.com/projects/460506630306178049) | [ex 6](https://wokwi.com/projects/460506630306178049)

---

### **2_Advance/**
Solutions to the Advanced exercises:

- **analog/** — Analog exercises
  - [Exercise 1](https://wokwi.com/projects/460492551199952897) | [Exercise 2](https://wokwi.com/projects/460492551199952897) | [Exercise 3](https://wokwi.com/projects/460492551199952897) | [Exercise 4](https://wokwi.com/projects/460492551199952897) | [Exercise 5](https://wokwi.com/projects/460492551199952897)
  - [Exercise 6](https://wokwi.com/projects/460492551199952897) | [Exercise 7](https://wokwi.com/projects/460492551199952897) | [Exercise 8](https://wokwi.com/projects/460492551199952897) | [Exercise 9](https://wokwi.com/projects/460492551199952897) | [Exercise 10](https://wokwi.com/projects/460492551199952897)
  - [Exercise 11](https://wokwi.com/projects/460492551199952897) | [Exercise 12](https://wokwi.com/projects/460492551199952897) | [Exercise 13](https://wokwi.com/projects/460492551199952897) | [Exercise 14](https://wokwi.com/projects/460492551199952897) | [Exercise 15](https://wokwi.com/projects/460492551199952897)

- **moreTechniques/** — More Techniques exercises
  - [Exercise 1](https://wokwi.com/projects/460492551199952897) | [Exercise 2](https://wokwi.com/projects/460492551199952897) | [Exercise 3](https://wokwi.com/projects/460492551199952897)

- **Aircooler/** — Air Cooler project
  - [EX 1](https://wokwi.com/projects/460492551199952897) | [ex 2](https://wokwi.com/projects/460492551199952897) | [ex 3](https://wokwi.com/projects/460492551199952897) | [ex 4](https://wokwi.com/projects/460492551199952897) | [ex 5](https://wokwi.com/projects/460492551199952897)

- **Optional/** — Optional exercises
  - 2_4_TransmitData_OPTIONAL.md

> Note: Task 'TransmitData' is optional. It helps understand how communication protocols (like I2C) transmit bit sequences.

---

### **3_Communication/**
Solutions to the Communication exercises:

- **communitationBasics/** — Communication Basics
  - [Exercise send](https://wokwi.com/projects/460499925111011329)
  - [Exercise receive](https://wokwi.com/projects/460499925111011329)
  - Exercise combined
  - Exercise adding some GUI

- **Adddatabase/** — Adding Database
  - 3_2_AddingDatabase.md

---

## 📌 Folder Organization

All exercises are organized in the following structure:
- `1_Basics/` — Fundamental IoT concepts
- `2_Advance/` — Advanced techniques and projects
- `3_Communication/` — Communication protocols and database integration

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
