#include<stdio.h>
#include<sys/types.h>

u_int32_t reverseBits(u_int32_t n) {
	u_int32_t i;
	u_int32_t rev_num=0;
	for(i =0 ;i<32;i++, n >>=1)
	{
		rev_num <<= 1;
		rev_num = rev_num | (n&1);
	}
	return rev_num;
}
int main(){
	u_int32_t num;
	scanf("%u", &num);
	printf("%u\n", reverseBits(num));
}
