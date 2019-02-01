#include<stdio.h>

int main()
{
    long n,i,j,minimal;
    long count_arr[5];
    long temp, output;
    scanf("%ld", &n);
    for(j=0; j<5;j++)
	count_arr[j] = 0;
    for(i=0;i<n;i++)
    {
	scanf("%ld", &temp);
	count_arr[temp-1]++;
    }
    minimal = -1;
    for (j=0;j<5;j++)
    {
	if(count_arr[j] > minimal)
	{
	    output = j+1;
	    minimal = count_arr[j];
	}
    }
    printf("%ld\n", output);
}

