// gas_detector.h

#ifndef GAS_DETECTOR_H
#define GAS_DETECTOR_H

// Pin definitions
#define GAS_SENSOR_PIN 26

// Gas threshold value
#define GAS_THRESHOLD 1500

// Function prototypes
void initializeGasDetector();
uint16_t readGasLevel();
void checkGasLevel(uint16_t gasLevel);
void sendGasAlert(uint16_t gasLevel);

#endif
