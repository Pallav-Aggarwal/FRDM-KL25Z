#include "DAC.h"

// Initialize DAC (No DMA)
void InitDAC(unsigned char dacEnable, unsigned char dacRef, unsigned char dacPowerMode)
{
	SIM->SCGC6 |= SIM_SCGC6_DAC0_MASK; // ENABLE DAC0 CLOCK
	//PORTE->PCR[30] |= PORT_PCR_MUX(0); // SELECT DAC0 on PTE30
		
	if(dacEnable) DAC0->C0 |= DAC_C0_DACEN_MASK;
	if(dacRef) DAC0->C0 |= DAC_C0_DACRFS_MASK;
	//if(dacTrig) DAC0->C0|= DAC_C0_DACTRGSEL_MASK;
	if(dacPowerMode) DAC0->C0 |= DAC_C0_LPEN_MASK;
}

void SetDAC(unsigned long value)
{
	
	DAC0->DAT->DATL = (0x000000FF & value); 
	DAC0->DAT->DATH = (0x0000000F & (value>>8)); 
	
}
