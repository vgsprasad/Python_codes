#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("This is the child %d with pid = %d from parent\n", getpid(), getppid());
    fflush(stdout);
    return 0;
}
