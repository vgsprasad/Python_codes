#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
unsigned long long array[1000][1000] = {0};
unsigned long long ncr(int n, int r)
{
    if (array[n][r] != 0)
	return array[n][r];
 //   if (array[n][n-r] != 0)
//	return array[n][n-r];

    if (n == r)
    {   
	array[n][r]= 1;
	return array[n][r];
    }
    if (r == 1) {   
	array[n][r]= n;
	return array[n][r];
    }

   // array[n][n-r] =
    array[n][r] = ncr(n-1,r-1) + ncr(n-1,r);
    return  array[n][r];

}
int main() {
    int n,a[1000],j,i;
    scanf ("%d" ,&n);
    for(i=0;i<n;i++)
	scanf("%d" , &a[i]); 
    for (i=0;i<n;i++)
    {
	printf("1 ");
	for (j=1; j<=a[i]; j++ )
	    printf("%llu ", ncr(a[i],j) % 1000000000);
	printf("\n");
    }
    return 0;
}

