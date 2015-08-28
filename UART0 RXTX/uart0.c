#include "uart0.h"

void Uart0Init(unsigned long baudRate, unsigned char parity, unsigned char stopBits, unsigned char mode)
{
	SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1); 		// UART0 CLOCK SOURCE - MCGFLLCLK clock or MCGPLLCLK/2
	SIM->SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK; // PLL Divide by 2
	SIM->SCGC4 |= SIM_SCGC4_UART0_MASK; 		// ENABLE UART0 CLOCK
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK; 		// ENABLE PORTD CLOCK (RX, TX Pins)
	
	// PORT CONTROL FOR ALTERNATE FUNCTIONS
	PORTD->PCR[6] |=  PORT_PCR_ISF_MASK | PORT_PCR_MUX(3); //PTD6 - UART0_RX
	PORTD->PCR[7] |=  PORT_PCR_ISF_MASK | PORT_PCR_MUX(3); //PTD7 - UART0_TX
	
	UART0->C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);  // TX & RX disable before UART0 configuration
  
	// CONFIGURE STOP BIT
  if(stopBits == UART_TWO_STOP_BIT) UART0->BDH |= UART0_BDH_SBNS_MASK; 
  
	//CONFIGURE PARITY
	if (parity == UART_PARITY_EVEN)
	{
		UART0->C1 |= UART0_C1_PE_MASK;
	}
	else if (parity == UART_PARITY_EVEN)
	{
		UART0->C1 |= UART0_C1_PE_MASK | UART0_C1_PT_MASK;
	}
	
  // CONFIGURE 8/9 BIT MODE
	if(mode == UART_MODE_9BIT) UART0->C1 |= UART0_C1_M_MASK; 

	//CONFIGURE BAUDRATE
	UART0->BDH = 0x00;
  UART0->BDL = 76;  //(24000000/((16+1)*(9600))) / Baud 9600
	
  UART0->C2 |= UART0_C2_TE_MASK | UART0_C2_RE_MASK;  		// TX & RX enable after UART0 configuration

}

void Uart0TxByte(unsigned char txData)
{
	//Wait till buffer if not empty or tx is still in progress
	while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 & UART_S1_TC_MASK));  
	UART0->D = txData;
}

void Uart0TxString(char *txString, unsigned char stringLength)
{
	while(*txString) Uart0TxByte(*txString++);

}
unsigned char Uart0RxPollByte(void)
{
	unsigned char rx=0;
	if(UART0_S1_RDRF_MASK & UART0->S1) rx = UART0->D;
	return rx;
}
