#include<stdio.h>
#define N 8
int main()
{
    int A[N] = {1,0,1,1,1,0,1,0};
    int B[N] = {1,1,0,0,0,0,1,1};
    int C[N+1]; 

    int carry; 
    int sum;

    int i,j; 
    i = N-1;
    j = N;
    carry = 0;
    while(i>=0) {
	sum = A[i]+B[i]+carry;
	if (sum > 1){
	    carry = 1; 
	    C[j] = sum - 2;
	}
	else {
	    carry = 0;
	    C[j] = sum;
	}
	i--;
	j--;
    }
    if (carry == 1) 
    printf("%d",carry);

    for(i = 0; i<N; i++)
	printf("%d", C[i]);
    
}
