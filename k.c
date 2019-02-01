#include<stdio.h>
struct name 
{
    char a ;
    int b;
    double c;
    void *p;
    int d[0];
}N;

int main()
{
    printf("Size = %d",sizeof(N));
    printf("\n%d %d %d %d %d ",sizeof(N.a),sizeof(N.b),sizeof(N.c),sizeof(N.p),sizeof(N.d));

}
