#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter a and b \n");
 
    scanf("%d%d",&a,&b);
    printf("a-b= %d",a+(~b)+1);
}
