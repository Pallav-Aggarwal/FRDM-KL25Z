#include <MKL25Z4.h>
#include <string.h>

#define DELAY 
#define SETBIT(PORT, BIT) PORT |=(1<<BIT)
#define CLRBIT(PORT, BIT) PORT |=(1<<BIT)

void readUID(char* uid)
{
	strcat(uid, "ABC");
}

int main(void)
{
	unsigned char i=0;
	char uidString[25] = {0};
	unsigned long UID[3] = {0};
	char hexString[16] ={'0', '1', '2', '3', '4', '5', '6', '7', '8','9', 'A', 'B', 'C', 'D', 'E', 'F'};
	//All system related settings
	SystemCoreClockUpdate();//Set System MAIN Clock to 48Mhz
	
	while(1)
	{
		UID[0] = SIM->UIDL;
		UID[1] = SIM->UIDML;
		UID[2] = SIM->UIDMH;
		
		for(i=0; i<8; i++)
		{
		uidString[23-i] = hexString[(UID[0]>>(i*4)) & 0x000000F];
		}
		for(i=0; i<8; i++)
		{
		uidString[15-i] = hexString[(UID[1]>>(i*4)) & 0x000000F];
		}
		for(i=0; i<8; i++)
		{
		uidString[7-i] = hexString[(UID[2]>>(i*4)) & 0x000000F];
		}
		readUID(uidString);
		
	}
	//return 0;
}




