#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
    int32_t a;
    u_int8_t b; 
    printf("Enter hex number \n");
    scanf("%x", &a);
    if (a >127) 
    {
        a = a |0xffffff00;
    }


    printf("\n Entered number = %d \n",a);
}
