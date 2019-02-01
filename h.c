#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    long int N[51],M[51],i,j,n,k,Ci[51][10001];
    scanf("%ld", &n);
    for( i=1;i<=n;i++)
    {    
	scanf("%ld", &M[n]);

	scanf("%ld", &N[n]);
	for (j=1;j<=N[n];j++)
	    scanf("%ld", &Ci[n][j]);
    }
    i=1;
start:
    for(; i<=n; i++)
    {

	for(j=1; j<N[i]; j++)
	{
	    int num = Ci[i][j];
	    for (k =j+1; k<= N[i]; k++) 
	    {
		if (M[i] - num == Ci[i][k]) {
		    printf ("%ld %ld %ld\n", j, k, i);
		    i++;
		    goto start;
		}
	    }

	}

    }
    return 0;
}
