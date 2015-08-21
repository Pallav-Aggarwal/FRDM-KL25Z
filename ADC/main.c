#include <MKL25Z4.h>


#define DELAY 
#define SETBIT(PORT, BIT) PORT |=(1<<BIT)
#define CLRBIT(PORT, BIT) PORT |=(1<<BIT)



int main(void)
{

	SystemCoreClockUpdate();//Set System MAIN Clock to 48Mhz
	
	while(1)
	{
		

		
	}
	//return 0;
}




