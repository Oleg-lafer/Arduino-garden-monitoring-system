#ifndef CONFIG_H
#define CONFIG_H

// Pin Definitions
#define DHT_PIN 2            // DHT sensor data pin
#define DHT_TYPE DHT11       // DHT11 or DHT22
#define LDR_PIN A0           // Light sensor pin
#define SOIL_MOISTURE_PIN A1 // Soil moisture sensor pin
#define SD_CS_PIN 10         // SD card module chip select pin

// Thresholds
const int LIGHT_THRESHOLD = 300;  // Adjust for your light sensor
const int SOIL_THRESHOLD = 500;  // Adjust based on your soil sensor readings
const float TEMP_MIN = 15.0;     // Minimum ideal temperature (Celsius)
const float TEMP_MAX = 30.0;     // Maximum ideal temperature
const float HUMIDITY_MIN = 30.0; // Minimum ideal humidity (%)
const float HUMIDITY_MAX = 70.0; // Maximum ideal humidity (%)

// Reading interval
const int READ_INTERVAL_MS = 2000; // Delay between readings (in milliseconds)

#endif // CONFIG_H
