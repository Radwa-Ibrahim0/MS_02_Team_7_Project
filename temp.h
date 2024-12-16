// temperature_sensor.h

#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#define TEMP_SENSOR_PIN 27 

#define TEMP_THRESHOLD 2700 

void initializeTemperatureSensor();
float readTemperature();
void checkTemperature(float temperature);

#endif
