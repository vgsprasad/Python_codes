#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/* Head ends here */

int pairs(int a_size, int* a, int k) {


    long  i,j, count =0,n1, n2;
    for (i = 0 ;i < a_size-1; i++) {
	for (j = i+1; j < a_size; j++) {
	    n1 = a[i] - a[j];
	    n2 = a[j] - a[i];
	    if (n1==k || n2==k)
		count++;
	}
    }
    return count; 


}

/* Tail starts here */
int main() {
    int res;

    int _a_size,_a_i,_k;
    scanf("%d %d", &_a_size,&_k);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
	int _a_item;
	scanf("%d", &_a_item);

	_a[_a_i] = _a_item;
    }
    sort(_a_size,_a);
    res=pairs(_a_size,_a,_k);
    printf("%d\n",res);    
    return 0;
}

