#include <stdio.h>
#include <stdint.h>
#include "hardware/uart.h"
#include "pico/stdlib.h"
#include "bluetooth.h"

const char data[64]; // Buffer for received data in the initialization

void initBluetoothModule() {
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}

void sendData(const char* data) {
    uart_puts(UART_ID, data);
}

char* receiveMessage() {
    static char received_message[100];
    int i = 0;
    while (uart_is_readable(UART_ID) && i < sizeof(received_message) - 1) {
        received_message[i++] = uart_getc(UART_ID);
    }
    received_message[i] = '\0'; // Null-terminate the string
    return received_message;
}
