#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
    printf("hello world (pid:%d)\n", getpid());

    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
    }
    else if (rc == 0) {
        // child -- "restart"
        execlp("ls","ls",NULL);
        
        fprintf(stderr, "exec failed\n");
    } 
    else {
        // parent -- wait and report
        wait(NULL);
        printf("finished process %d (pid:%d)\n",rc,getpid());
    }
}