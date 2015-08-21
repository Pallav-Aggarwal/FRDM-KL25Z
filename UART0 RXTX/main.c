#include "uart0.h"

#define CPU_CLOCK							48000000

#define DELAY 
#define SETBIT(PORT, BIT) 		PORT |=(1<<BIT)
#define CLRBIT(PORT, BIT) 		PORT |=(1<<BIT)

#define RED_LED 							18
#define GREEN_LED 						19
#define BLUE_LED							1

int main(void)
{
	unsigned long i=0;
	//All system related settings
	SystemCoreClockUpdate();								//Set System MAIN Clock to 48Mhz
	Uart0Init(9600, UART_PARITY_NONE, UART_ONE_STOP_BIT, UART_MODE_8BIT);
	

	while(1)
	{
		
		Uart0TxByte(0xAA);
		for(i=0;i<1000000;i++);
		for(i=0;i<1000000;i++);
		
	}
	//return 0;
}



