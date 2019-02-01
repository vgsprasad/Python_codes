#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long long ncr(int n, int k)
{
    if (n == k || k == 0)
	return 1;
    if (k == 1)
	return n;
  //  if (k > n/2)
//	k = n-k;
    return (ncr(n-1,k) + ncr(n-1, k-1));
}

unsigned long long light_combination(int num)
{
    unsigned long long int ret_val = 0;
    int index = 1; 
    while (index < num  ) 
    {
	ret_val += ncr(num,index);
	index ++;
    }
    ret_val = ret_val+1 % 100000;
    return ret_val;
}
int main() {

    unsigned long long res; 
    int num_test_cases,index, num_lights[1500];
    scanf("%d", &num_test_cases);
    for(index =0; index <num_test_cases; index++)
	scanf("%d", &num_lights[index]);
    for(index =0; index <num_test_cases; index++)
    {
	res = light_combination(num_lights[index]);
	printf("%llu\n", res);   
    }
    return 0;
}

