#include<stdio.h>
#define EEPROM_POS 5
int main()
{
    int final_num,j,i;
    printf(" SFB slot        EEPROM num       Final num,     sfb_slot     eeprom num\n");
    for(j = 0 ; j < 8 ;j++)
    {
    
	for(i = 0 ; i < 6 ;i++)
	{
	    final_num =(i << EEPROM_POS) | j;
	    printf(" %d \t\t %d  \t\t    %x     %d     %d", j, i, final_num, final_num&0x1F, (final_num&0xE0)>>5);
	printf("\n");
	}
    }
}
