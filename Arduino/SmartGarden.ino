#include <DHT.h>
#include <SD.h>
#include "config.h"
#include "sensors.h"

// SD card pin
const int SD_CS_PIN = 4;  // Chip select for SD card module

File logFile;  // File object for SD card logging

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  dht.begin();         // Initialize the DHT sensor

  // Initialize SD card
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("Error initializing SD card!");
    return;
  }
  Serial.println("SD card initialized.");

  // Create/Open the CSV file for logging
  logFile = SD.open("garden_log.csv", FILE_WRITE);
  if (logFile) {
    // Write header if file is empty
    logFile.println("Timestamp, Temperature (°C), Humidity (%), Light Intensity, Soil Moisture");
    logFile.close();
  } else {
    Serial.println("Error opening garden_log.csv!");
  }

  Serial.println("Smart Garden Monitoring System Starting...");
}

void loop() {
  // Collect data
  SensorData data = readSensors();
  String timestamp = String(millis() / 1000);  // Log time in seconds since start
  
  // Display data on serial monitor
  printSensorData(data);

  // Write data to SD card
  logFile = SD.open("garden_log.csv", FILE_WRITE);
  if (logFile) {
    logFile.print(timestamp);                          // Timestamp
    logFile.print(", ");
    logFile.print(data.temperature);                    // Temperature
    logFile.print(", ");
    logFile.print(data.humidity);                       // Humidity
    logFile.print(", ");
    logFile.print(data.lightIntensity);                 // Light intensity
    logFile.print(", ");
    logFile.println(data.soilMoisture);                // Soil moisture
    logFile.close();  // Close the file after writing
  } else {
    Serial.println("Error opening garden_log.csv for writing!");
  }

  // Check thresholds
  checkThresholds(data);

  // Delay before next reading
  delay(READ_INTERVAL_MS);
}
