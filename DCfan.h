#ifndef DCFAN_H
#define DCFAN_H

// Pin definitions
#define FAN_PIN_A 18       // IN1 (control pin A for L9110)
#define FAN_PIN_B 17       // IN2 (control pin B for L9110)
#define FAN_PWM_PIN 21     // PWM pin for speed control (optional)

// Inline functions for initialization and control
void initDCFan();
void setFanSpeed(uint8_t speed, bool direction);
void stopFan();
void setupPWM(uint gpio);

#endif 
