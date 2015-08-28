#include <MKL25Z4.h>


#define DELAY 
#define SETBIT(PORT, BIT) 						PORT |=(1<<BIT)
#define CLRBIT(PORT, BIT) 						PORT |=(1<<BIT)

//ADC SC1
#define ADC_INTERRUPT_DISBLE  				0
#define ADC_INTERRUPT_ENABLE  				1

#define ADC_SING_MODE_ENABLE					0
#define ADC_DIFF_MODE_ENABLE					1

#define ADC_INTERNAL_CHANNEL_TEMP			26

//ADC CFG1
#define ADC_PWR_MODE_NORMAL						0
#define ADC_PWR_MODE_LOW							1

#define ADC_INPUT_CLOCK_DIV_1					1
#define ADC_INPUT_CLOCK_DIV_2					1
#define ADC_INPUT_CLOCK_DIV_4					2
#define ADC_INPUT_CLOCK_DIV_8					3

#define ADC_SAMPLE_TIME_SHORT					0
#define ADC_SAMPLE_TIME_LONG					1

#define ADC_RESOLUTION_8_9_BIT				0
#define ADC_RESOLUTION_12_13_BIT			1
#define ADC_RESOLUTION_10_11_BIT			2
#define ADC_RESOLUTION_16_16_BIT			3

#define ADC_INPUT_CLOCK_BUS						0
#define ADC_INPUT_CLOCK_BUS2					1
#define ADC_INPUT_CLOCK_ALTCLK				2
#define ADC_INPUT_CLOCK_ADACK					3


struct adcSC1
{
	unsigned int channel:5;
	unsigned int diffMode:1;
	unsigned int conversionInterruptEnable:1;	
};

struct adcCGF1
{
	unsigned int inputClock:2;
	unsigned int ResolutionMode:2;
	unsigned int sampleTimeMode:1;	
	unsigned int clockDivision:2;	
	unsigned int lowPowerConfig:1;
};

struct ADC
{
	struct adcSC1 SC1;
	struct adcCGF1 CGF1;	
};

struct ADC adc;

void adcInit(unsigned char interruptEnable, unsigned char adcDiffMode, unsigned char channel);


int main(void)
{

	SystemCoreClockUpdate();//Set System MAIN Clock to 48Mhz
	adc.SC1.diffMode = ADC_SING_MODE_ENABLE;
	adc.SC1.channel = ADC_INTERNAL_CHANNEL_TEMP;
	adc.CGF1.lowPowerConfig = ADC_PWR_MODE_LOW;
	adc.CGF1.clockDivision = ADC_INPUT_CLOCK_DIV_8;
	adc.CGF1.ResolutionMode = ADC_RESOLUTION_16_16_BIT;
	adc.CGF1.sampleTimeMode = ADC_SAMPLE_TIME_LONG;
	adc.CGF1.inputClock = ADC_INPUT_CLOCK_BUS2;
	
	adcInit(ADC_INTERRUPT_DISBLE, ADC_SING_MODE_ENABLE, ADC_INTERNAL_CHANNEL_TEMP);
	
	while(1)
	{
	
	ADC0->SC1[0] |= ADC_SC1_AIEN_MASK;
		
	}
	//return 0;
}

void adcInit(unsigned char interruptEnable, unsigned char adcDiffMode, unsigned char channel)
{
	
	
	SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK; // Enable ADC Clock
	if(interruptEnable == ADC_INTERRUPT_ENABLE) ADC0->SC1[0] |= ADC_SC1_AIEN_MASK; // Configure ADC Conversion Complete Interrupt
	if(adcDiffMode == ADC_DIFF_MODE_ENABLE) ADC0->SC1[0] |= ADC_SC1_DIFF_MASK; // Configure Conversion Mode
	ADC0->SC1[0] |= ADC_SC1_ADCH(channel); // Select Channel
	//ADC0->CFG1 |= ADC_CFG1_

	
}


