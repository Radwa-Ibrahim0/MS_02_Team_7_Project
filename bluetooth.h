#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#define UART_ID uart0
#define BAUD_RATE 9600
#define UART_TX_PIN 0
#define UART_RX_PIN 1

void initBluetoothModule();
void sendData(const char* data);
char* receiveMessage();

#endif