#include "buzzer.h"
#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

void buzzer_init() {
    gpio_init(BUZZER_PIN); // Initialize the GPIO for the buzzer pin
    gpio_set_dir(BUZZER_PIN, GPIO_OUT); // Set the buzzer pin as output
}

void buzzer_on() {
    gpio_put(BUZZER_PIN, 1); // Set the buzzer pin high to turn on the buzzer
}

void buzzer_off() {
    gpio_put(BUZZER_PIN, 0); // Set the buzzer pin low to turn off the buzzer
}