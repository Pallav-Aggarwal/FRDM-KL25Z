#include <MKL25Z4.h>

#define SETBIT(PORT, BIT) PORT |=(1<<BIT)
#define CLRBIT(PORT, BIT) PORT |=(1<<BIT)

#define RED_LED 					18
#define GREEN_LED 				19
#define BLUE_LED					1
#define DELAY_1M					2000000

void delay(unsigned long cycles);

int main(void)
{
	unsigned char keyFlag = 0;
	//All system related settings
	SystemCoreClockUpdate();//Set System MAIN Clock to 48Mhz
	SIM->SCGC5 |= (1<<12);	//Enable Clock for PORTD
	SIM->SCGC5 |= (1<<10);	//Enable Clock for PORTB
	
	// PORT CONTROL FOR ALTERNATE FUNCTIONS
	PORTB->PCR[18] |= PORT_PCR_MUX(1) ; // 0000 0001 0000 0000 // PORTB18 Pin set GPIO Function
	//PORTB->PCR[19] |= PORT_PCR_MUX(1) ; // 0000 0001 0000 0000 // PORTB19 Pin set GPIO Function
	
	PORTD->PCR[1] |= PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK | PORT_PCR_ISF_MASK | PORT_PCR_IRQC(6) ; // 0000 0001 0000 0000 // PORTD1 Pin set GPIO Function + Pull up
  //PTD->PDDR |= (0 << 1); // Configure PTD1 pin as input

	PTB->PDDR |= (1 << 18); //Configure PTB18 pin as output
	//PTB->PDDR |= (1 << 19); //Configure PTB19 pin as output
	
	//NVIC_EnableIRQ(PORTD_IRQn);
	CLRBIT(PTB->PDOR, RED_LED);
	
	while(1)
	{
		if (!(PTD->PDIR & (1<<1))) keyFlag = 1;
		
		while(keyFlag)
		{
			SETBIT(PTB->PCOR, RED_LED);
			delay(50000);
			CLRBIT(PTB->PDOR, RED_LED);
			delay(DELAY_1M);
			delay(DELAY_1M);
			delay(DELAY_1M);
			delay(DELAY_1M);
			delay(DELAY_1M);
			delay(DELAY_1M);
			delay(DELAY_1M);
		}
	}
}



void delay(unsigned long cycles)
{
	while(cycles--);
}

//__irq void PORTD_IRQ()
//{
//	SETBIT(PTB->PCOR, RED_LED);
//}
