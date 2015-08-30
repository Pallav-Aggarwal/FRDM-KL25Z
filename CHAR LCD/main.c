#include "charlcd.h"

#define DELAY 
//#define SETBIT(PORT, BIT) PORT |=(1<<BIT)
//#define CLRBIT(PORT, BIT) PORT |=(1<<BIT)

#define RED_LED 					18
#define GREEN_LED 				19
#define BLUE_LED					1


int main(void)
{
	//unsigned long i=0;
	//All system related settings
	SystemCoreClockUpdate();//Set System MAIN Clock to 48Mhz
	//SIM->SCGC5 |= (1<<10);	//Enable Clock for PORTB
	SIM->SCGC5 |= (1<<12);	//Enable Clock for PORTD
	
	// PORT CONTROL FOR ALTERNATE FUNCTIONS
	//PORTB->PCR[18] |= (1 << 8); // 0000 0001 0000 0000 // PORTB18 Pin set GPIO Function
	//PORTB->PCR[19] |= (1 << 8); // 0000 0001 0000 0000 // PORTB19 Pin set GPIO Function
	PORTD->PCR[1] |= PORT_PCR_MUX(1); // 0000 0001 0000 0000 // PORTD1 Pin set GPIO Function + Pull up
	
	//PTB->PDDR |= (1 << 18); //Configure PTB18 pin as output
	//PTB->PDDR |= (1 << 19); //Configure PTB19 pin as output
  PTD->PDDR |= (1<< 1); // Configure PTD1 pin as output

	//io_port_initialisation();
	init_lcd();
	init_lcd();
	init_lcd();
	while(1)
	{
		put_chr_lcd(LINE1, 15, '3');
		put_chr_lcd(LINE2, 15, '2');
		put_str_lcd(LINE1, 0, "  Hello World   ", 16);
		//put_str_of_dec(LINE1, 0, 256, 4, YES_SHOW_LEADING_ZEROS);
	}

}



