#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int cmty_flash_offset_not_used_table[4][2][8]=
{
    {
	{ 0,0,0,0,1,0,0,0,},
	{ 0,1,0,0,0,0,0,0,},
    },
    {
	{ 0,0,0,0,1,0,0,0,},
	{ 0,1,0,0,0,0,0,0,},
    },
    {
	{ 1,1,1,1,1,1,1,1,},
	{ 1,1,0,0,0,0,0,0,},
    },
    {
	{ 1,1,1,1,1,1,1,1,},
	{ 1,1,0,0,0,0,0,0,},
    },
};


int cmty_check_flash_offset_is_valid(unsigned int offset)
{
        unsigned int dev_addr;
	unsigned int  mux_dev;
	unsigned int  mux_chan;
	dev_addr = ((offset & 0x00C0) >> 6);
	
	mux_dev  = ((offset & 0x0800) >> 11); 
	
	mux_chan = ((offset & 0x0700) >> 8);
	
	return (((offset & 0x3f) < 4) || 
		(cmty_flash_offset_not_used_table[dev_addr][mux_dev][mux_chan]));
}

int main()
{
    unsigned int i;
    FILE *fp;
    fp = fopen("g","w");
    for(i=0;i<32767;i++)
	if(!cmty_check_flash_offset_is_valid(i))
	    fprintf(fp,"%x\n",i);
    exit(1);
}
