#include "UID.h"

int main(void)
{
	char uid[25]={0};
	//All system related settings
	SystemCoreClockUpdate(); //Set System MAIN Clock to 48Mhz
	
	while(1)
	{
		readUID(uid);
	}
}




