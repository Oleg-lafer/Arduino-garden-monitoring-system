#ifndef SENSORS_H
#define SENSORS_H

#include <DHT.h>
#include "config.h"

// Struct to hold sensor data
struct SensorData {
  float temperature;
  float humidity;
  int lightIntensity;
  int soilMoisture;
};

// Function declarations
void initializeSensors();
SensorData readSensors();
void printSensorData(const SensorData &data);
void checkThresholds(const SensorData &data);

#endif // SENSORS_H
