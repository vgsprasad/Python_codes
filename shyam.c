#include<stdio.h>
void f(char *s, int i) {
	s = (char *) malloc(20*sizeof(char));
	s[i++] = 50;
	s[i++] = 51;
}
int main()
{
	int i=10;
	char *s =0;
	//f(s,i);
	printf("%d\n", s);
}

