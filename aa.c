#include<stdio.h> 

int main()
{
	char b[100]="Jan 18 00:11:22 this is junk syslog message";
	int i;
	for(i=0;i<15;i++)
		b[i]=32;
	printf("%s\n",b);
}
