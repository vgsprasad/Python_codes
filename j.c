#include<stdio.h>
int main()
{
    int a =1, i=2;
    switch(i) {
	case 1 :
	case 2:
	    if(a==0)
	    {
		printf("Hi\n");
		break;
	    }
	    printf("Bye\n");
	    break;
	default:printf("HIHIHIHI\n");
            break;
    }
}


