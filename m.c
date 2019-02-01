#include<stdio.h>
int FF[] = {'j','a','d','e'};
int SS[] = {'j','e','f','f'};
struct name
{
    int *first_name_array;
}N;
int main()
{
    int i,n;
    printf("Enter \n 1 to first name of first person \n 2 to first name of second person\n");
    scanf("%d", &n);
    if(n == 1)
	N.first_name_array = FF;
    else
	N.first_name_array = SS;

    printf("Printing array now \n");
    for(i=0;i<4;i++)
	printf("%c",N.first_name_array[i]);

}

