#include <MKL25Z4.h>

// DAC C0
#define DAC_DISABLE			0
#define DAC_ENABLE			1

#define DAC_REF_VREFH 	0
#define DAC_REF_VDDA 		1

#define DAC_SOFT_TRIG		1
#define DAC_HARD_TRIG		0

#define DAC_HIGH_POWER	0
#define DAC_LOW_POWER		1

void InitDAC(unsigned char dacEnable, unsigned char dacRef, unsigned char dacPowerMode);
void SetDAC(unsigned long value);
