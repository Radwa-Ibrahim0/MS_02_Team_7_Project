#ifndef LED_H
#define LED_H

#define GAS_LED_PIN 15
#define TEMP_LED_PIN 16
#define FLAME_LED_PIN 19

// Function Prototypes
void initLEDs(); // Initialize GPIO pins
void turnOnGasLed();
void turnOffGasLed();
void turnOnTempLed();
void turnOffTempLed();
void turnOnFlameLed();
void turnOffFlameLed();
void delay_ms(int ms); // Function to delay in milliseconds

#endif
