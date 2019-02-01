#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    int i=0;
    for(i=0; i < 100; i++) {
	fork();
	execl("./client", "./client", NULL);
    }
    if (wait(NULL) == -1)
	perror("error with wait");
    return 0;
}
