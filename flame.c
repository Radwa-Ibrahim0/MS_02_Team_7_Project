#include <stdio.h>
#include <stdint.h> // Add this line
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "flame.h"
#include "buzzer.h"
#include "led.h"
#include "bluetooth.h"


void initializeFlameDetector()
{
    adc_gpio_init(FLAME_SENSOR_PIN); 
    adc_select_input(2);            
}

uint16_t readFlameLevel()
{
    uint16_t flameLevel = adc_read(); 
    char flameMessage[50];
    snprintf(flameMessage, sizeof(flameMessage), "Flame Level: %u\n", flameLevel);
    printf("%s", flameMessage);
    sendData(flameMessage);
    return flameLevel;
}

void checkFlameLevel(uint16_t flameLevel)
{
    if (flameLevel < FLAME_THRESHOLD)
    {
        turnOnFlameLed();
        // buzzer_on();
        sendData("Flame detected! Warning!\n");
    }
    else
    {
        turnOffFlameLed();
        buzzer_off();
    }
}

