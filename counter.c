#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {

    unsigned long long N[15], temp;
    int winner =0, T,i,k; // 0 for lousie 1 for richard
    scanf("%d", &T);
    for (i=0;i<T;i++) {
	scanf("%llu", &N[i]);
    }
    for(i=0;i<T;i++){
	while (N[i] != 1) {
	    if(!(N[i] & (N[i]-1)))
	    {
		N[i]/=2;
		winner = (winner+1) %2;
	    }
	    else 
	    {
		temp = N[i]; 
		for (k=1; k<=64; k++)
		{
		    if(temp >pow(2,k))
			continue;
		    else{
			temp = pow(2,k-1);
			break;
		    }
		}
		N[i] -= temp;
		winner = (winner+1) %2;
	    }
	}        
	printf("%s\n", (winner==0)?"Richard":"Louise");
    }
    return 0;
}

