#include<stdio.h>

int main() 
{
    int n,count=0;
    int i;
    printf("Enter number n \n");
    scanf("%d",&n);
    for(i =2;i<=n;i++)
    {
	int j=i;
	while(j)
	{
	    int last_digit = j%10;
	    if(last_digit ==2)
		count++;
	    j/=10;
	}

    }
    printf("\nCount = %d",count);
}

