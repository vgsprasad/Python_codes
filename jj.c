#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    long int t, i, n[1000], c[1000], m[1000], answer, chocs, n1,n2;

    scanf("%d", &t);
    for (i = 0; i < t ;i++)
    {
	scanf("%ld%ld%ld",&n[i],&c[i],&m[i]);
    }
    for(i=0;i<t ;i++) {
	answer = 0; 
	answer += (n[i]/c[i]); 

	chocs = answer ; 

	while (chocs >= m[i]) 
	{
	    n1 = chocs / m[i];
	    n2 = chocs % m[i];
	    chocs = n1+n2;
	    answer++;
	}
	printf("%ld\n",answer);
    }
    return 0;
}

