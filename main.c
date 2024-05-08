#include <stdio.h>
#include "uart.h"

int main() {

    UARTDriverState uartState;

    initialize_UART(&uartState);

    char singlecharacter = 'A'; // Example character to send
    uart_writechar(&uartState,singlecharacter);


    return 0;
}
