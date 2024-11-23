#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "gas.h"
#include "buzzer.h"
#include "led.h"
#include "bluetooth.h"

void initializeGasDetector()
{
    adc_gpio_init(GAS_SENSOR_PIN); 
    adc_select_input(0);
}

uint16_t readGasLevel()
{
    uint16_t gasLevel = adc_read(); 
    printf("Gas Level: %u\n", gasLevel);
    // char gasMessage[50];
    // sprintf(gasMessage, "Gas Level: %u\n", gasLevel);
    // sendData(gasMessage);
    return gasLevel;
}

void checkGasLevel(uint16_t gasLevel)
{
    if (gasLevel > GAS_THRESHOLD)
    {
        turnOnGasLed();
        // buzzer_on();
        sendData("Gas detected! Warning!\n");
    }
    else
    {
        turnOffGasLed();
        // buzzer_off();
    }
}


