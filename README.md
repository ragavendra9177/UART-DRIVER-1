i have implemented the UART driver and i  mentioned below How to calculate baudrate also....and This UART DRIVER developed as per 7th chapter in "Programming Embedded Systems in C and C++ by Michael Barr" book

Below i mentioned How to calculate the Baudrate for stm32F411RE Board 

Formula For Baudrate:

The baud rate for the receiver and transmitter (Rx and Tx) are both set to the same value as programmed in the Mantissa and Fraction values of USARTDIV.

Equation 1: Baud rate for standard USART

Tx/Rx Baudrate=frequency / (82-OVER8USARTDIV);

Examples:

Example 1:

Now iam calculating baudrate for 9600 on my stm32F411RE Board

Actualyy USART2 in my board that is getting Clock from APB1 bus thai is 50 MHZ

According my formula= 5000000 / ((8 * 2 - 1)* 9600

                =32.552

     fraction part=16*0.552
                  =8.332 = Nearest real number is 9

     mantissa=32
so final inserting value for BRR ragister is 0x209.
