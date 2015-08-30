#include "DAC.h"

int main(void)
{
	SystemCoreClockUpdate();
	InitDAC(DAC_ENABLE, DAC_REF_VDDA, DAC_HIGH_POWER);
	while(1)
	{
		SetDAC(1024);
		SetDAC(2048);
		SetDAC(3096);
		SetDAC(4095);
	}
}
