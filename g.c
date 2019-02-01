#include<stdio.h>
#include<sys/types.h>
int main()
{
    u_int32_t c;
    u_int8_t a[2];
    a[0]=0x16;
    a[1]=0x6d;
    c=ntohs((u_int16_t)a);
    printf("Hi\n");
    printf("%7.3f\n",c);
}
    
