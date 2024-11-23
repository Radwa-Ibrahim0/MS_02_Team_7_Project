#include "led.h"
#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"


void initLEDs() {
    gpio_init(GAS_LED_PIN);
    gpio_set_dir(GAS_LED_PIN, GPIO_OUT);

    gpio_init(TEMP_LED_PIN);
    gpio_set_dir(TEMP_LED_PIN, GPIO_OUT);

    gpio_init(FLAME_LED_PIN);
    gpio_set_dir(FLAME_LED_PIN, GPIO_OUT);
}

void turnOnGasLed() {
    gpio_put(GAS_LED_PIN, 1); // Set the GAS_LED_PIN high to turn on the LED
}

void turnOffGasLed() {
    gpio_put(GAS_LED_PIN, 0); // Set the GAS_LED_PIN low to turn off the LED
}

void turnOnTempLed() {
    gpio_put(TEMP_LED_PIN, 1); // Set the TEMP_LED_PIN high to turn on the LED
}

void turnOffTempLed() {
    gpio_put(TEMP_LED_PIN, 0); // Set the TEMP_LED_PIN low to turn off the LED
}

void turnOnFlameLed() {
    gpio_put(FLAME_LED_PIN, 1); // Set the FLAME_LED_PIN high to turn on the LED
}

void turnOffFlameLed() {
    gpio_put(FLAME_LED_PIN, 0); // Set the FLAME_LED_PIN low to turn off the LED
}

void delay_ms(int ms) {
    sleep_ms(ms); // Delay for the specified number of milliseconds
}