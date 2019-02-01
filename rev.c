#include<stdio.h>

unsigned int myans(unsigned int x)
{
	unsigned int result =0;
	unsigned int size = sizeof(x) *8 -1;
	while (size) {
		unsigned temp = x & 1;
		result = result | temp;
		result = result << 1;
		x = x >> 1;
		size--;
	}
	return result;
}
unsigned int geeks(unsigned int num) 
{ 
    unsigned int  NO_OF_BITS = sizeof(num) * 8; 
    unsigned int reverse_num = 0, i, temp; 
  
    for (i = 0; i < NO_OF_BITS; i++) 
    { 
        temp = (num & (1 << i)); 
        if(temp) 
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i)); 
    } 
   
    return reverse_num; 
} 
int main()
{
	unsigned n;
	scanf("%d", &n);
	printf(" Geeks answer = %u\n", geeks(n));
	printf(" My answer = %u\n", myans(n));
}
