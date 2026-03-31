import paho.mqtt.client as mqtt
import sqlite3
import json
from flask import Flask, render_template, jsonify
from datetime import datetime

app = Flask(__name__)
MQTT_BROKER = "broker.hivemq.com"
MQTT_TOPIC = "example/topic"
client = mqtt.Client()

# DB setup
conn = sqlite3.connect('sensordata.db', check_same_thread=False)
conn.execute('''CREATE TABLE IF NOT EXISTS readings 
                (id INTEGER PRIMARY KEY, temp REAL, hum REAL, timestamp TEXT)''')
conn.commit()
conn.close()

def on_connect(client, userdata, flags, rc):
    client.subscribe(MQTT_TOPIC)
    print("MQTT subscribed")

def on_message(client, userdata, msg):
    try:
        data = json.loads(msg.payload)
        conn = sqlite3.connect('sensordata.db')
        conn.execute("INSERT INTO readings (temp, hum, timestamp) VALUES (?, ?, ?)",
                     (data['temp'], data['hum'], datetime.now().isoformat()))
        conn.commit()
        conn.close()
        print(f"Stored: {data}")
    except Exception as e:
        print(f"Error: {e}")

client.on_connect = on_connect
client.on_message = on_message
client.connect(MQTT_BROKER, 1883, 60)
client.loop_start()

@app.route('/')
def dashboard():
    conn = sqlite3.connect('sensordata.db')
    readings = conn.execute("SELECT * FROM readings ORDER BY id DESC LIMIT 50").fetchall()
    conn.close()
    return render_template('dashboard.html', readings=readings)

@app.route('/api/latest')
def api_latest():
    conn = sqlite3.connect('sensordata.db')
    latest = conn.execute("SELECT * FROM readings ORDER BY id DESC LIMIT 1").fetchone()
    conn.close()
    return jsonify(latest) if latest else jsonify({})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)