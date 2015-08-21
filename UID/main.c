#include <MKL25Z4.h>
#include <string.h>

#define DELAY 
#define SETBIT(PORT, BIT) PORT |=(1<<BIT)
#define CLRBIT(PORT, BIT) PORT |=(1<<BIT)

void readUID(char* uid)
{
	
}

int main(void)
{
	unsigned long i=0;
	char uidString[20] = {0};
	//All system related settings
	SystemCoreClockUpdate();//Set System MAIN Clock to 48Mhz
	
	while(1)
	{
		
		readUID(uidString);
		
	}
	//return 0;
}




