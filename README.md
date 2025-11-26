\# 🧊 Remote Monitoring of Coke Cans in a Fridge

\### ESP32 • DS18B20 Temperature Sensor • Ultrasonic Sensor • MQTT (Mosquitto) • Node-RED Dashboard



This project monitors the \*\*temperature\*\* and \*\*remaining Coke cans\*\* inside a fridge using an \*\*ESP32\*\*, and displays everything live on a \*\*Node-RED dashboard\*\*.



The system uses:

\- \*\*DS18B20\*\* to measure temperature  

\- \*\*Ultrasonic (HC-SR04)\*\* to measure can height  

\- \*\*MQTT (Mosquitto Broker)\*\* to transfer data  

\- \*\*Node-RED Dashboard\*\* to visualize temperature, distance, and can count  



---



\## 🚀 Features



✔️ Real-time fridge temperature  

✔️ Ultrasonic level reading  

✔️ Automatic calculation of total \*\*can count\*\*  

✔️ MQTT communication using \*\*Mosquitto Broker\*\*  

✔️ Clean Node-RED dashboard  

✔️ Works with \*\*Wokwi simulation\*\* or real hardware  

✔️ Ideal IoT project for learning MQTT + ESP32  



---



\## 🛠️ Hardware Components



| Component | Quantity | Purpose |

|----------|----------|---------|

| ESP32 Dev Board | 1 | Main controller |

| DS18B20 Digital Temperature Sensor | 1 | Measure fridge temperature |

| HC-SR04 Ultrasonic Sensor | 1 | Measure can height (stock level) |

| 4.7kΩ resistor | 1 | DS18B20 pull-up |

| Jumper wires | — | Connections |

| USB cable | 1 | Power + programming |



---



\## 🔌 Wiring Diagram



\### \*\*DS18B20 Connections\*\*

| DS18B20 | ESP32 |

|---------|--------|

| VDD | 3.3V |

| GND | GND |

| DATA | GPIO 4 |

\*\*4.7kΩ resistor between DATA ↔ 3.3V\*\*



\### \*\*HC-SR04 Connections\*\*

| HC-SR04 | ESP32 |

|---------|--------|

| VCC | 5V |

| GND | GND |

| TRIG | GPIO 13 |

| ECHO | GPIO 12 |



---



\## 🔧 Software \& Tools Used



| Tool | Purpose |

|------|---------|

| Arduino IDE | ESP32 programming |

| Mosquitto Broker | MQTT communication |

| MQTT Explorer| Debugging topic values |

| Node-RED + Dashboard | Visualization |

| Wokwi Simulator | Testing hardware online |



---



\## 🧩 MQTT Topics Used



Topic | Description

------|-------------

`fridge/temp` | Temperature (°C)

`fridge/level` | Ultrasonic distance (cm)

`fridge/count` | Calculated Coke can count

`fridge/status` | ESP32 online status



---



\## 📊 Node-RED Dashboard UI



Your dashboard includes:



\- \*\*Temperature Gauge\*\*

\- \*\*Ultrasonic Level Gauge\*\*

\- \*\*Can Count (Numeric)\*\*

\- \*\*Chart for Temperature History\*\*

\- \*\*Chart for Distance History\*\*

\- \*\*Status Indicator (Online/Offline)\*\*



---



\## 📥 Node-RED Flow Import



You can import the `.json` file included in this repository:





