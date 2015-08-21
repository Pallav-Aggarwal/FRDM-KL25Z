#include <MKL25Z4.h>

#define DELAY 
#define SETBIT(PORT, BIT) PORT |=(1<<BIT)
#define CLRBIT(PORT, BIT) PORT |=(1<<BIT)

#define RED_LED 					18
#define GREEN_LED 				19
#define BLUE_LED					1


int main(void)
{
	unsigned long i=0;
	//All system related settings
	SystemCoreClockUpdate();//Set System MAIN Clock to 48Mhz
	//SIM->SCGC5 |= (1<<10);	//Enable Clock for PORTB
	SIM->SCGC5 |= (1<<12);	//Enable Clock for PORTD
	
	// PORT CONTROL FOR ALTERNATE FUNCTIONS
	//PORTB->PCR[18] |= (1 << 8); // 0000 0001 0000 0000 // PORTB18 Pin set GPIO Function
	//PORTB->PCR[19] |= (1 << 8); // 0000 0001 0000 0000 // PORTB19 Pin set GPIO Function
	PORTD->PCR[1] |= (1<<8); // 0000 0001 0000 0000 // PORTD1 Pin set GPIO Function
	
	//PTB->PDDR |= (1 << 18); //Configure PTB18 pin as output
	//PTB->PDDR |= (1 << 19); //Configure PTB19 pin as output
  PTD->PDDR |= (1<< 1); // Configure PTD1 pin as output


	
	while(1)
	{
		
		//PTB->PCOR = (1 << 18);
		SETBIT(PTD->PDOR, BLUE_LED);
		for(i=0;i<1000000;i++);
		for(i=0;i<1000000;i++);
			
		//PTB->PDOR = (1 << 18);
		CLRBIT(PTD->PCOR, BLUE_LED);
		for(i=0;i<1000000;i++);
		for(i=0;i<1000000;i++);
		
		
	}
	//return 0;
}


