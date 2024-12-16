#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "gas.h"
#include "buzzer.h"
#include "led.h"
#include "bluetooth.h"
#include "DCfan.h"

extern bool buzzerStatus; // Declare the global variable

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

void adjustFanSpeed(uint16_t gasLevel)
{
    initDCFan();
    buzzer_init();
    
    uint8_t fanSpeed = 0;
    if (gasLevel > GAS_THRESHOLD)
    {
        fanSpeed = (gasLevel - GAS_THRESHOLD) * 255 / (MAX_GAS_LEVEL - GAS_THRESHOLD); // Scale to 0-255
        if (fanSpeed > 255) fanSpeed = 255; // Cap the speed at 255
        buzzer_on();
    }
    else
    {
        fanSpeed = 0;
        buzzer_off();
    }
    setFanSpeed(fanSpeed, true);
}

void checkGasLevel(uint16_t gasLevel)
{
    if (gasLevel > GAS_THRESHOLD)
    {
        turnOnGasLed();
        buzzerStatus = true; // Set the global variable
        sendData("Gas detected! Warning!\n");  
    }
    else
    {
        turnOffGasLed();
    }
    adjustFanSpeed(gasLevel);
}


