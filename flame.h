#ifndef FLAME_H
#define FLAME_H

// Pin definitions
#define FLAME_SENSOR_PIN 28

// Flame threshold value
#define FLAME_THRESHOLD 3200 // Adjust this value as necessary

// Function prototypes
void initializeFlameDetector();
uint16_t readFlameLevel();
void checkFlameLevel(uint16_t flameLevel);

#endif // FLAME_H
