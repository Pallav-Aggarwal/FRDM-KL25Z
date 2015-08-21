#include <MKL25Z4.h>

// UART MACROS
#define UART_ONE_STOP_BIT			0
#define UART_TWO_STOP_BIT		  1

#define UART_PARITY_NONE			0
#define UART_PARITY_EVEN			1
#define UART_PARITY_ODD			  2

#define UART_MODE_8BIT				0
#define UART_MODE_9BIT				1
#define UART_BAUD_CLOCK				24000000
#define UART_BAUD_SBR					(UART_BAUD_CLOCK)/((16+1)*9600)

void Uart0Init(unsigned long baudRate, unsigned char parity, unsigned char stopBits, unsigned char mode);
unsigned long Uart0TxByte(unsigned char txData);
unsigned long Uart0RxByte(void);
