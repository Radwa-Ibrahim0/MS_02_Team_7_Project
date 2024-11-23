// temperature_sensor.h

#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

// Pin definition for the temperature sensor
#define TEMP_SENSOR_PIN 27 // GPIO pin for the temperature sensor (ADC channel 1)

// Temperature threshold in Celsius (you can change this based on your application)
#define TEMP_THRESHOLD 2700 // Example: 30°C

// Function prototypes
void initializeTemperatureSensor();
float readTemperature();
void checkTemperature(float temperature);

#endif
