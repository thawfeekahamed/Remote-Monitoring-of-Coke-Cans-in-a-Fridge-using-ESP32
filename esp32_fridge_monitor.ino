#include <WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// ---------------- WiFi -------------------
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ---------------- MQTT Broker -------------------
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);

// ---------------- DS18B20 -------------------
#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// ---------------- Ultrasonic -------------------
#define TRIG_PIN 5
#define ECHO_PIN 18

long duration;
float distanceCm;

// ---------------- CAN CONFIG ------------------
const float canHeight = 6.0;     // 1 Coke can height (cm)
const int maxCans = 6;           // Max cans in box
const float maxHeight = maxCans * canHeight; // 36 cm

// ---------------- WiFi -----------------------
void setup_wifi() {
  Serial.println();
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(400);
    Serial.print(".");
  }
  Serial.println(" Connected!");
}

// ---------------- MQTT -----------------------
void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP32-Fridge-Monitor")) {
      Serial.println(" Connected!");
      client.subscribe("fridge/commands");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying...");
      delay(1500);
    }
  }
}

// -------------- Read Ultrasonic ---------------
float readUltrasonic() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(4);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distanceCm = duration * 0.034 / 2;
  return distanceCm;
}

// -------- Convert Distance → Coke Can Count ----
int calculateCanCount(float measuredDistance) {
  float filledHeight = maxHeight - measuredDistance;

  if (filledHeight < 0) filledHeight = 0;
  if (filledHeight > maxHeight) filledHeight = maxHeight;

  int cans = filledHeight / canHeight;

  if (cans < 0) cans = 0;
  if (cans > maxCans) cans = maxCans;

  return cans;
}

// ---------------- Setup -----------------------
void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  sensors.begin();
  setup_wifi();

  client.setServer(mqtt_server, 1883);
}

// ---------------- MAIN LOOP --------------------
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Temperature
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  // Level
  float distance = readUltrasonic();

  // Coke can count
  int cansLeft = calculateCanCount(distance);

  // MQTT Publish
  client.publish("fridge/temperature", String(tempC).c_str());
  client.publish("fridge/can_level", String(distance).c_str());
  client.publish("fridge/can_count", String(cansLeft).c_str());

  // Serial Debugging
  Serial.println("=====================================");
  Serial.println("Temperature: " + String(tempC) + " °C");
  Serial.println("Distance from top: " + String(distance) + " cm");
  Serial.println("Coke Cans Left: " + String(cansLeft));
  Serial.println("=====================================");

  delay(2000);
}
