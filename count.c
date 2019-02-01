#include<stdio.h>

int main()
{
    long n;
    long i;
    char temp_str[100];
    long temp_int, count[100], temp;
    scanf("%ld", &n);
    for(i=0;i<100;i++) 
    {
	count[i] = 0;
    }
    for(i=0;i<n;i++) 
    {
	scanf("%ld%s", &temp_int,temp_str);
	count[temp_int] = count[temp_int] +1;
    }
    temp =0;
    for(i=0;i<100;i++)
    {
	temp = temp+count[i];
	printf("%ld ",temp);
    }
}

