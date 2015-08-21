#include <MKL25Z4.h>

#define DELAY 
#define SETBIT(PORT, BIT) PORT |=(1<<BIT)
#define CLRBIT(PORT, BIT) PORT |=(1<<BIT)

#define RED_LED 					18
#define GREEN_LED 				19
#define BLUE_LED					1

unsigned long Uart0Init(unsigned long baudRate, unsigned char parity, unsigned char stopBits);
unsigned long SendByte(unsigned char txData);


int main(void)
{
	unsigned long i=0;
	//All system related settings
	SystemCoreClockUpdate();								//Set System MAIN Clock to 48Mhz
	

	while(1)
	{
		
		//PTB->PCOR = (1 << 18);
		SETBIT(PTB->PDOR, RED_LED);
		for(i=0;i<1000000;i++);
		for(i=0;i<1000000;i++);
			
		//PTB->PDOR = (1 << 18);
		CLRBIT(PTB->PCOR, RED_LED);
		for(i=0;i<1000000;i++);
		for(i=0;i<1000000;i++);
		
		
	}
	//return 0;
}

unsigned long Uart0Init(unsigned long baudRate, unsigned char parity, unsigned char stopBits)
{
	SIM->SOPT2 = SIM_SOPT2_UART0SRC(1); 		// UART0 CLOCK SOURCE - MCGFLLCLK clock or MCGPLLCLK/2
	SIM->SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK; // PLL Divide by 2
	SIM->SOPT2 |= SIM_SCGC4_UART0_MASK; 		// ENABLE UART0 CLOCK
	SIM->SOPT2 |= SIM_SCGC5_PORTD_MASK; 		// ENABLE PORTD CLOCK (RX, TX Pins)
	
	// PORT CONTROL FOR ALTERNATE FUNCTIONS
	PORTD->PCR[6] |=  PORT_PCR_ISF_MASK | PORT_PCR_MUX(3); //PTD6 - UART0_RX
	PORTD->PCR[7] |=  PORT_PCR_ISF_MASK | PORT_PCR_MUX(3); //PTD7 - UART0_TX
	
	
	
	
	return 0;
}

unsigned long SendByte(unsigned char txData)
{
	
	return 0;
}


