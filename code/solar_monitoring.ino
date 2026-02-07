#include <ESP8266WiFi.h>

const int voltagePin = A0;
const int currentPin = A1;

float voltageValue = 0;
float currentValue = 0;
float powerValue = 0;

// WiFi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi Connected");
}

void loop() {
  int voltageRaw = analogRead(voltagePin);
  int currentRaw = analogRead(currentPin);

  voltageValue = voltageRaw * (5.0 / 1023.0) * 5;
  currentValue = (currentRaw - 512) * (5.0 / 1023.0);

  powerValue = voltageValue * currentValue;

  Serial.print("Voltage: ");
  Serial.print(voltageValue);
  Serial.print(" V | Current: ");
  Serial.print(currentValue);
  Serial.print(" A | Power: ");
  Serial.print(powerValue);
  Serial.println(" W");

  delay(5000);
}

