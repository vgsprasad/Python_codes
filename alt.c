#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    long i,j,k,count, T;
    char s[11][100000]; 
    scanf("%ld", &T);
    for(i=0;i<T;i++)
    {
	scanf("%s", s[i]); 
    }
    for(i=0 ; i<T; i++)
    {
	count = 0 ;
	for(j=0; j< strlen(s[i])-1;)
	{
	    for(k=j+1; k < strlen(s[i]); k++)
	    {
		if (s[i][j] == s[i][k])
		{  count++;
		    j++;
		}
		else 
		{
		    j=k;
		    break;
		}
	    }
	}
	printf("%ld\n", count);
    }
    return 0;
}

