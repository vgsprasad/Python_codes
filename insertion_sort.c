#include<stdio.h>

int A[10] = { 3,1,19,2, 0,56,32,-8, 6, 5 };
insertion_sort()
{
    int i, j, key;
    for(i = 1; i<10 ;i++)
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
    for(i=0;i<10;i++)
	printf("%d \t", A[i]);
    printf("\n");
    return 0;
}

