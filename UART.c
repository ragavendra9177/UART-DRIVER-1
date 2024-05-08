
#include"uart.h"



#define USART2 ((struct UARTDevice *)USART2_Base)


static char rxbuffer[40];
static char index =0;

/* UART Initialization  */

void initialize_UART(UARTDriverState* state) {
    // Code to initialize the I2C hardware

	state->UART= (struct UARTDevice*)USART2_Base;

	state->UART->BRR =0x147;
    state->UART->CR1 |= UART_Enable;
    state->UART->CR1 |= TE;
    state->UART->CR1 |= RE;
    state->UART->CR1 |= RXNEIE;
    state->is_initialized = 1;
}


/* UART writing character  */

void uart_writechar(UARTDriverState* state,char ch)
{

	         state->UART->DATA= ch;   // LOad the Data
		     while(!((state->UART->status)&TC));  // Wait for TC to SET.. This indicates that the data has been transmitted
}

/* UART reading single byte character */


char uart_readchar(UARTDriverState* state)
{
		char Temp;

		while (!((state->UART->status)&RXNE));  // Wait for RXNE to SET.. This indicates that the data has been Received
		Temp =state->UART->DATA;  // Read the data.
		return Temp;
}


/* UART send string  */

void uart_sendstring(UARTDriverState* state,char *string)
{
	while(*string)
	{
		uart_writechar(state, *string);
		string++;
	}
}

/* UART reading String  */

char * uart_readstring(UARTDriverState* state,char *string,char length)
{
	char i;
	for(i=0;i<length;i++)
	{
		while (!((state->UART->status)&RXNE));  // Wait for RXNE to SET.. This indicates that the data has been Received
		string[i]=state->UART->DATA;  // Read the data.
		if(string[i]=='\n')
			break;
	}
	string[i]='\0';  //putting Null character at the end
}

/* UART interrupt handler for receving data*/


void USART2_IRQHandler(UARTDriverState* state)
{

	while (!((state->UART->status)&RXNE));  // Wait for RXNE to SET.. This indicates that the data has been Received
			rxbuffer[index++]=state->UART->DATA;  // Read the data.
			if(rxbuffer[index]=='\n')
			{
				rxbuffer[index]='\0';
			}
}




