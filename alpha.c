#include<stdio.h>
int main() 
{
    char *s;
    int i;
    long count[27]; 
    for (i=0;i<27;i++)
	count[i] = 0;
    s = (char *) malloc(100000 *sizeof(char *));
    if (!s) {
	printf(" Malloc failure \n");
    }
    scanf("%s", s);
    for(i=0;i<strlen(s);i++)
    {
	switch(s[i]) 
	{
	case 'a': count_arr[1]++;
		  break;
	case 'b': count_arr[2]++;
		  break;
	case 'c': count_arr[3]++;
		  break;
	case 'd': count_arr[4]++;
		  break;
	case 'e': count_arr[5]++;
		  break;
	case 'f': count_arr[6]++;
		  break;
	case 'g': count_arr[7]++;
		  break;
	case 'h': count_arr[8]++;
		  break;
	case 'i': count_arr[9]++;
		  break;
	case 'j': count_arr[10]++;
		  break;
	case 'k': count_arr[11]++;
		  break;
	case 'l': count_arr[12]++;
		  break;
	case 'm': count_arr[13]++;
		  break;
	case 'n': count_arr[14]++;
		  break;
	case 'o': count_arr[15]++;
		  break;
	case 'p': count_arr[16]++;
		  break;
	case 'q': count_arr[17]++;
		  break;
	case 'r': count_arr[18]++;
		  break;
	case 's': count_arr[19]++;
		  break;
	case 't': count_arr[20]++;
		  break;
	case 'u': count_arr[21]++;
		  break;
	case 'v': count_arr[22]++;
		  break;
	case 'w': count_arr[23]++;
		  break;
	case 'x': count_arr[24]++;
		  break;
	case 'y': count_arr[25]++;
		  break;
	case 'z': count_arr[26]++;
		  break;
	}
    }
    scanf("%d", &n);
    for (i=0;i<n;i++) {


