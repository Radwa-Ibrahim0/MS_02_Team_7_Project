#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "temp.h"
#include "led.h"
#include "bluetooth.h"
#include "buzzer.h"

extern bool buzzerStatus; // Declare the global variable

void initializeTemperatureSensor()
{
    adc_gpio_init(TEMP_SENSOR_PIN);
    adc_select_input(1);
}

float readTemperature()
{
    uint16_t adcValue = adc_read(); 
    printf("Temp Level: %d\n", adcValue);
    // char tempMessage[50];
    // sprintf(tempMessage, "Temp Level: %d\n", adcValue);
    // sendData(tempMessage);
    return adcValue;
}

void checkTemperature(float temperature)
{
    if (temperature < TEMP_THRESHOLD)
    {
        turnOnTempLed();
        buzzerStatus = true; // Set the global variable
        sendData("High temperature detected! Warning!\n");
    }
    else
    {
        //buzzer_off();
        turnOffTempLed();
    }
}

