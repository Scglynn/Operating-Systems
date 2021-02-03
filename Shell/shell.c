#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "parse.c"

int main() {

    char fnctn;
    scanf("%c",&fnctn);

    switch (fnctn)
    {
        case'exit':
            return 0;
            break;
        case'bg':
            printf("hello world (pid:%d)\n", getpid());
            int rc = fork();
            if (rc < 0)
            {
                //fork failed
                fprintf(stderr, "fork failed\n");
            } else if (rc == 0) {
                //child (new process)
                printf("hello, I am child (pid:%d)\n", getpid());
            } else {
                //parent goes down this path (main)
                printf("hello, I am parent of %d (pid:%d)\n",rc,getpid());
            }
            break;
        case 'ls':
            
            break;
        default:
            printf("Invalid command\n");
            break;
    }
    return 0;
}