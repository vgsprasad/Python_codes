#include<stdio.h>

void reverse(char *s, int start, int len)
{
	int index =start;
	printf("%d %d\n", start, len);
	while(index < len/2)
	{
		char temp;
		temp = s[index];
		s[index] = s[len-index-1];
		s[len-index-1] = temp;
		index++;
	}
}
int main()
{	
	char s[100];
	int len;
	int start=0;
	int count =0;
	int i;
	gets(s);
	len = strlen(s);
	reverse(s, 0, len);
	start = 0;
	for(i =0; i < len; i++)
	{
		printf("%c\n", s[i]);
		if (s[i] == ' ') {
			printf(" count = %d, s[i] = %c\n", count,s[i] );
			if (count > 1) {
				printf("count = %d Log 1\n", count);
				reverse(s, start, count);
				count = 0;
			}
			printf("start = %d\n", start);
			start = i+1;
		}
		else{

			printf("Log 2\n");
			count ++;
		}
	}
	printf("%s", &s);
}
