// main.c
#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "hardware/uart.h"
#include "gas.h"
#include "temp.h"
#include "DCfan.h"
#include "buzzer.h"
#include "led.h"
#include "flame.h"
#include "bluetooth.h"

bool buzzerStatus = false; // Define the global variable

int main()
{
    stdio_init_all();
    buzzer_init();
    initLEDs();
    adc_init();
    initBluetoothModule();
    initDCFan();


    for (int i = 0; i < 3; i++)
    {
        turnOnGasLed();
        turnOnTempLed();
        turnOnFlameLed();
        buzzer_on();
        sleep_ms(300);
        buzzer_off();
        turnOffFlameLed();
        turnOffTempLed();
        turnOffGasLed();
        sleep_ms(300);
    }

    while (true)
    {
        buzzerStatus = false; // Reset the global variable

        initializeGasDetector();
        uint16_t gasLevel = readGasLevel();
        checkGasLevel(gasLevel);

        initializeTemperatureSensor();
        float temperature = readTemperature();
        checkTemperature(temperature);

        initializeFlameDetector();
        uint16_t flameLevel = readFlameLevel();
        checkFlameLevel(flameLevel);

        if (buzzerStatus)
        {
            buzzer_on();
        }
        else
        {
            buzzer_off();
        }

        sleep_ms(1000); 

    }
    return 0;
}
