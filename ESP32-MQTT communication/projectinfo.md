# 🚀 ESP32 MQTT IoT Communication System

An end-to-end IoT project demonstrating MQTT-based communication between an **ESP32** and a **Laptop** using the **HiveMQ Public Broker**. The project implements both **Publisher** and **Subscriber** functionalities, enabling remote control of the ESP32 onboard LED through MQTT.

---

## 📌 Project Overview

This project demonstrates how an ESP32 can communicate over the Internet using the MQTT protocol.

### Features

* ✅ ESP32 Wi-Fi Connectivity
* ✅ MQTT Broker Communication
* ✅ MQTT Publisher
* ✅ MQTT Subscriber
* ✅ Remote LED Control
* ✅ Serial Debugging
* ✅ PlatformIO Development Environment
* ✅ HiveMQ Public Broker
* ✅ Mosquitto MQTT Client Testing

---

## 🏗️ Project Architecture

```text
                Internet
                    |
                    |
          broker.hivemq.com
                    |
        -------------------------
        |                       |
        |                       |
   Laptop                  ESP32 DevKit V1
(Mosquitto Client)      (Arduino Framework)
        |                       |
        |                       |
   Publish / Subscribe    Publish / Subscribe
        |                       |
        -------- MQTT ----------
                    |
                 GPIO2
                    |
                Onboard LED
```

---

# 🛠 Hardware Used

* ESP32 DevKit V1
* USB Cable
* Laptop/PC

---

# 💻 Software Used

* Visual Studio Code
* PlatformIO IDE
* Arduino Framework
* Mosquitto MQTT Client
* HiveMQ Public Broker

---

# 📚 Technologies Used

* Embedded C++
* ESP32
* MQTT
* Wi-Fi
* TCP/IP
* PlatformIO
* Arduino Framework

---

# 📂 Project Structure

```text
ESP32_MQTT_Project/
│
├── src/
│   └── main.cpp
│
├── include/
│
├── lib/
│
├── platformio.ini
│
└── README.md
```

---

# ⚙️ PlatformIO Configuration

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200

lib_deps =
    knolleary/PubSubClient
```

---

# 📡 MQTT Broker Details

| Parameter | Value             |
| --------- | ----------------- |
| Broker    | broker.hivemq.com |
| Port      | 1883              |
| Protocol  | MQTT              |
| QoS       | 0                 |

---

# 📍 Topics Used

### Publisher Topic

```
ravindhar/test
```

### Subscriber Topic

```
ravindhar/esp32/led
```

---

# 🔄 Project Workflow

1. ESP32 connects to Wi-Fi.
2. ESP32 connects to HiveMQ Broker.
3. Laptop publishes MQTT messages.
4. ESP32 subscribes to the MQTT topic.
5. ESP32 receives commands.
6. Onboard LED turns ON/OFF.

---

# 💡 MQTT Publisher Code

```cpp
client.publish(
    "ravindhar/test",
    "Hello from ESP32"
);
```

---

# 💡 MQTT Subscriber Code

```cpp
client.subscribe("ravindhar/esp32/led");
```

---

# 💻 Complete MQTT Connection Code

```cpp
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

void connectMQTT()
{
    while (!client.connected())
    {
        Serial.println("Connecting to MQTT...");

        if (client.connect("ESP32_Client"))
        {
            Serial.println("MQTT Connected Successfully!");
        }
        else
        {
            Serial.print("Failed, rc=");
            Serial.println(client.state());
            delay(2000);
        }
    }
}
```

---

# 📤 Publish Example

```cpp
client.publish(
    "ravindhar/test",
    "Hello from ESP32"
);
```

---

# 📥 Subscribe Example

```cpp
client.subscribe(
    "ravindhar/esp32/led"
);
```

---

# 💻 Mosquitto Commands

### Subscribe

```powershell
.\mosquitto_sub.exe -h broker.hivemq.com -t ravindhar/test -v
```

### Publish

```powershell
.\mosquitto_pub.exe -h broker.hivemq.com -t ravindhar/esp32/led -m "ON"
```

Turn OFF:

```powershell
.\mosquitto_pub.exe -h broker.hivemq.com -t ravindhar/esp32/led -m "OFF"
```

---

# 🖥 Serial Monitor Output

```text
Connecting to WiFi...
.....
WiFi Connected!

IP Address: 10.66.172.68

Connecting to MQTT...

MQTT Connected Successfully!
```

---

# 🔍 Learning Outcomes

Through this project, I learned:

* ESP32 Programming
* PlatformIO Development
* MQTT Publish-Subscribe Architecture
* Wi-Fi Networking
* TCP/IP Basics
* GPIO Programming
* Embedded C++
* MQTT Broker Communication
* Serial Debugging
* Root Cause Analysis
* IoT Device Communication

---

# 🚀 Future Improvements

* Read Temperature & Humidity Sensor Data
* MQTT Dashboard Integration
* Mobile App Control
* OLED Display Support
* Secure MQTT (TLS)
* Home Automation System
* Cloud Database Integration

---

# 👨‍💻 Author

**Ravindhar Gundoji**

Embedded Systems | IoT | ESP32 | MQTT | PlatformIO

---


