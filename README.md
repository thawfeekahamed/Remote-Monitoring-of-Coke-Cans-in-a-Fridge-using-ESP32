# 🧊 Remote Monitoring of Coke Cans in a Fridge using ESP32 and MQTT Protocol  
### Real-Time Temperature and Inventory Monitoring via Smartphone

![IoT](https://img.shields.io/badge/IoT-ESP32-blue?logo=espressif)
![MQTT](https://img.shields.io/badge/Protocol-MQTT-purple?logo=vercel)
![Blynk](https://img.shields.io/badge/Platform-Blynk-green?logo=blynk)
![License](https://img.shields.io/badge/License-MIT-green)
![Build](https://img.shields.io/badge/Build-Stable-success)

---

## 🧭 Project Overview

This project demonstrates an **IoT-based remote monitoring system** for tracking both the **temperature** and **availability of Coke cans in a refrigerator**. Using the **ESP32 microcontroller** and the **MQTT (Message Queuing Telemetry Transport)** protocol, the system provides **real-time updates on a smartphone** through a mobile application built on **Blynk**.

The system addresses a common inconvenience — the need to manually check fridge conditions. It allows users to remotely monitor their drinks’ temperature and availability anytime, anywhere, ensuring beverages are always ready at the optimal temperature.

---

## 🎯 Project Objectives

- Develop an IoT system for **real-time monitoring** of fridge temperature and Coke availability.  
- Implement **MQTT** for reliable data transmission between ESP32 and mobile devices.  
- Utilize **Blynk** for mobile-based visualization and alerts.  
- Ensure users receive **instant notifications** on their smartphones.  
- Evaluate the system’s performance in terms of **accuracy**, **latency**, and **usability**.

---

## 🔬 Concept and Working Principle

The system integrates **temperature and proximity sensors** with an **ESP32 board** that connects to Wi-Fi and communicates using the MQTT protocol.

1. **Temperature Sensing:**  
   The **DS18B20** digital sensor continuously measures the internal temperature of the fridge.  

2. **Coke Detection:**  
   An **ultrasonic or IR sensor** detects the number of Coke cans based on object distance.  

3. **Data Communication:**  
   The ESP32 collects sensor data and publishes it to an **MQTT broker** under defined topics (e.g., `esp/temperature` and `esp/notification`).  

4. **Smartphone Interface:**  
   Using **Blynk**, the data is visualized as live graphs, and notifications are sent to alert the user if Coke is available and if the temperature drops below a specified threshold.

5. **Notification Logic:**  
   - Temperature updates every **5 seconds**.  
   - Availability status published every **30 minutes**.  
   - Alerts generated when temperature falls below **8°C** or Coke cans are unavailable.

---

## ⚙️ Hardware Components

| Component | Quantity | Description |
|------------|-----------|-------------|
| **ESP32 Board** | 1 | Central microcontroller with Wi-Fi & Bluetooth |
| **DS18B20 Temperature Sensor** | 1 | Measures fridge temperature |
| **Ultrasonic/IR Sensor** | 2 | Detects Coke can presence |
| **Breadboard** | 1 | Prototyping platform |
| **Jumper Wires** | 25 | Circuit connections |
| **USB Cable** | 1 | ESP32 power & data interface |

---

## 💻 Software and Tools

| Tool | Description |
|------|-------------|
| **Arduino IDE / uPyCraft IDE** | Used to code and upload firmware to ESP32 |
| **MQTT Protocol** | Enables publish–subscribe data transfer |
| **Blynk Cloud / App** | Real-time data visualization and notification system |
| **Wi-Fi Network** | Wireless communication medium |
| **Serial Monitor** | Debugging and performance validation |

---

## 🧩 System Architecture


---

## 📜 Methodology Summary

1. **Hardware Setup:** Connect sensors to ESP32 and ensure stable power supply.  
2. **Wi-Fi Configuration:** Connect ESP32 to a local network.  
3. **MQTT Communication:** Publish sensor data under topics:
   - `esp/temperature`
   - `esp/notification`
4. **Mobile Dashboard:** Configure Blynk dashboard with widgets for:
   - Real-time temperature graph.
   - Coke availability indicator.
   - Text-based notifications.
5. **Testing:** Validate sensor readings, update intervals, and alert accuracy.  

---

## 🧠 Algorithm Outline

1. Initialize Wi-Fi, MQTT, and sensors.  
2. Collect temperature and distance data.  
3. Publish data to MQTT broker.  
4. Evaluate thresholds (e.g., Coke available & temperature < 8°C).  
5. Send notifications and update Blynk interface.  
6. Repeat cycle every few seconds.  

---

## 📊 Results and Analysis

### ✅ Real-Time Monitoring
- Temperature readings published every **5 seconds** ensured continuous updates.  
- The MQTT protocol provided **low-latency and reliable** message delivery.  

### ✅ Notification System
- Notifications sent every **30 minutes** successfully informed users about Coke status.  
- Conditional logic ensured alerts were meaningful and timely.  

### ✅ Visualization
- Blynk dashboard effectively displayed graphs for temperature variation and availability.  

### ✅ Performance Evaluation
- **Accuracy:** ±0.5°C (DS18B20)  
- **Update latency:** <1s (MQTT)  
- **Notification delay:** ~30s (push alert interval)  
- **User satisfaction:** Easy-to-use mobile interface and reliable operation.  

---

## 💰 Project Budget

| Item | Quantity | Unit Price (LKR) | Total (LKR) |
|------|-----------|------------------|--------------|
| ESP32 Board | 1 | 1700 | 1700 |
| DS18B20 Sensor | 1 | 130 | 130 |
| Ultrasonic Sensors | 2 | 350 | 700 |
| Jumper Wires | 25 | 10 | 250 |
| Breadboard | 1 | 400 | 400 |
| **Total** |  |  | **3180 LKR** |

---


📽 **Video Demonstration:** [Google Drive Link](https://drive.google.com/drive/folders/1MLkNd4NBSX5o6_JUmLFHW72Pyx8hT5qr?usp=drive_link)

---

