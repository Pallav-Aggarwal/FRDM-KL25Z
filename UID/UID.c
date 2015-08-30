#include "UID.h"
#include <string.h>

void readUID(char *uidString)
{
	
	unsigned char i = 0;
	unsigned long UID = 0;
	const char hexString[16] ={'0', '1', '2', '3', '4', '5', '6', '7', '8','9', 'A', 'B', 'C', 'D', 'E', 'F'};

	UID = SIM->UIDL;
	for(i = 0; i < 8; i++)
	{
		uidString[23 - i] = hexString[(UID >> (i * 4)) & 0x000000F];
	}
	
	UID = SIM->UIDML;
	for(i = 0; i < 8; i++)
	{
		uidString[15 - i] = hexString[(UID >> (i * 4)) & 0x000000F];
	}
	
	UID = SIM->UIDMH;
	for(i = 0; i < 8; i++)
	{
		uidString[7 - i] = hexString[(UID >> (i * 4)) & 0x000000F];
	}
}
