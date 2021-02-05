#include <stdio.h>
#include <unistd.h>

int main() 
{
    printf("hello world (pid:%d)\n", getpid());
    int rc = execlp("ls","ls",NULL);
    fprintf(stderr, "exec failed\n");
}