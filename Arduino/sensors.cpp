#include "sensors.h"

// Create DHT object
DHT dht(DHT_PIN, DHT_TYPE);

void initializeSensors() {
  dht.begin();  // Initialize the DHT sensor
}

SensorData readSensors() {
  SensorData data;
  data.temperature = dht.readTemperature();
  data.humidity = dht.readHumidity();
  data.lightIntensity = analogRead(LDR_PIN);
  data.soilMoisture = analogRead(SOIL_MOISTURE_PIN);
  return data;
}

void printSensorData(const SensorData &data) {
  Serial.println("----- Sensor Data -----");
  Serial.print("Temperature: ");
  Serial.print(data.temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(data.humidity);
  Serial.println(" %");

  Serial.print("Light Intensity: ");
  Serial.print(data.lightIntensity);
  Serial.println(" (Analog Value)");

  Serial.print("Soil Moisture: ");
  Serial.print(data.soilMoisture);
  Serial.println(" (Analog Value)");
  Serial.println("-----------------------");
}

void checkThresholds(const SensorData &data) {
  if (data.temperature < TEMP_MIN || data.temperature > TEMP_MAX) {
    Serial.println("WARNING: Temperature out of range!");
  }
  if (data.humidity < HUMIDITY_MIN || data.humidity > HUMIDITY_MAX) {
    Serial.println("WARNING: Humidity out of range!");
  }
  if (data.lightIntensity < LIGHT_THRESHOLD) {
    Serial.println("WARNING: Low light detected!");
  }
  if (data.soilMoisture > SOIL_THRESHOLD) {
    Serial.println("WARNING: Soil is too dry!");
  }
}
