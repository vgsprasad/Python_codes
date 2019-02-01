#include<stdio.h>

int A[6] = { 31, 41, 59, 26, 41, 58 };
insertion_sort()
{
    int i, j, key;
    for(i = 1; i<6 ;i++)
    {
	key = A[i];
	j = i-1;
	while(j>=0 && (A[j] > key)) 
	{
	    A[j+1] = A[j];
	    j--;
	}
	A[j+1] = key;
    }
}
int main()
{
    int i;
    insertion_sort();
    for(i=0;i<6;i++)
	printf("%d \t", A[i]);
    printf("\n");
    return 0;
}

