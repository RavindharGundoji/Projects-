#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

// ===============================
// WiFi Credentials
// ===============================
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// ===============================
// MQTT Broker Details
// ===============================
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

// MQTT Topics
const char* publishTopic = "ravindhar/test";
const char* subscribeTopic = "ravindhar/esp32/led";

// Onboard LED
#define LED_PIN 2

// ===============================
// WiFi and MQTT Client
// ===============================
WiFiClient espClient;
PubSubClient client(espClient);

// ===============================
// Connect to WiFi
// ===============================
void connectWiFi()
{
    Serial.println("Connecting to WiFi...");

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

// ===============================
// MQTT Callback Function
// ===============================
void callback(char* topic, byte* payload, unsigned int length)
{
    Serial.print("Message Received: ");

    String message = "";

    for (unsigned int i = 0; i < length; i++)
    {
        message += (char)payload[i];
    }

    Serial.println(message);

    if (message == "ON")
    {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("LED ON");
    }
    else if (message == "OFF")
    {
        digitalWrite(LED_PIN, LOW);
        Serial.println("LED OFF");
    }
}

// ===============================
// Connect to MQTT Broker
// ===============================
void connectMQTT()
{
    while (!client.connected())
    {
        Serial.println("Connecting to MQTT...");

        if (client.connect("ESP32_Client"))
        {
            Serial.println("MQTT Connected Successfully!");

            client.subscribe(subscribeTopic);

            client.publish(publishTopic, "Hello from ESP32");
        }
        else
        {
            Serial.print("Connection Failed. Error Code: ");
            Serial.println(client.state());

            delay(2000);
        }
    }
}

// ===============================
// Setup Function
// ===============================
void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);

    connectWiFi();

    client.setServer(mqtt_server, mqtt_port);

    client.setCallback(callback);

    connectMQTT();
}

// ===============================
// Loop Function
// ===============================
void loop()
{
    if (!client.connected())
    {
        connectMQTT();
    }

    client.loop();
}
