#include "uart0.h"

#define CPU_CLOCK							48000000

#define DELAY_1M							3000000 
#define SETBIT(PORT, BIT) 		PORT |=(1<<BIT)
#define CLRBIT(PORT, BIT) 		PORT |=(1<<BIT)

#define RED_LED 							18
#define GREEN_LED 						19
#define BLUE_LED							1
void delay(unsigned long cycles);

int main(void)
{
	//unsigned temp=0;
	//All system related settings
	SystemCoreClockUpdate();								//Set System MAIN Clock to 48Mhz
	Uart0Init(9600, UART_PARITY_NONE, UART_ONE_STOP_BIT, UART_MODE_8BIT);
	

	while(1)
	{
		//Uart0TxByte(134);
		Uart0TxString("Ambient Temperature : 26.5 deg C\n", 0);
		delay(DELAY_1M);
		delay(DELAY_1M);
		delay(DELAY_1M);
		delay(DELAY_1M);

		//temp = Uart0RxPollByte();
		//if(temp) Uart0TxByte(temp);

	}
	//return 0;
}

void delay(unsigned long cycles)
{
	while(cycles--);
}



