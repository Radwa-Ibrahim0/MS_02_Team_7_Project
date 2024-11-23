#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "DCfan.h"

void setup() {
    // Initialize the fan pins
    initDCFan();

    // Set initial state: Forward direction, 50% speed
    setFanSpeed(0, true);      // 50% speed
}

void initDCFan() {
    setupPWM(FAN_PWM_PIN);

    // Initialize pins as outputs
    gpio_init(FAN_PIN_A);
    gpio_set_dir(FAN_PIN_A, GPIO_OUT);

    gpio_init(FAN_PIN_B);
    gpio_set_dir(FAN_PIN_B, GPIO_OUT);

    // Stop fan initially
    gpio_put(FAN_PIN_A, 1);
    gpio_put(FAN_PIN_B, 0);
  
}

void setFanSpeed(uint8_t speed,  bool direction) {
  pwm_set_gpio_level(FAN_PWM_PIN, speed); // Set PWM duty cycle
  
}

void stopFan() {
    gpio_put(FAN_PIN_A, 0);
    gpio_put(FAN_PIN_B, 0);
    pwm_set_gpio_level(FAN_PWM_PIN, 0); // Stop PWM
}

void setupPWM(uint gpio) { // tamam 
    gpio_set_function(gpio ,GPIO_FUNC_PWM) ; 
    uint slice = pwm_gpio_to_slice_num(FAN_PWM_PIN); 
    pwm_set_clkdiv(slice, 4.0f);
    
    pwm_set_wrap(slice , 255); 

    pwm_set_gpio_level(FAN_PWM_PIN, 0); // Set PWM to 0% duty cycle
    pwm_set_enabled(slice, true);

}

void fanLoop() {
    // Example: Change fan behavior every 5 seconds
    sleep_ms(5000);
    
    setFanSpeed(200, true);       // 80% speed
    
    sleep_ms(5000);
    
    stopFan();              // Stop the fan
    sleep_ms(2000);

    setFanSpeed(50, false);        // 20% speed
}
