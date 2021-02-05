#include <stdio.h>
#include <unistd.h>

int main() 
{
    printf("hello world (pid:%d)\n", getpid());
    int rc = execlp("ls","ls",NULL);
    if(rc < 0)
        fprintf(stderr, "exec failed\n");
    else
        printf("it worked!\n");
}