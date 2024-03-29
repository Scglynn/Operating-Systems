#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {    
    printf("hello world (pid:%d)\n", getpid());    
    int rc = fork();    
    if (rc < 0) {        // fork failed        
        fprintf(stderr, "fork failed\n");    
    }    
    else if (rc == 0) 
    {        // child (new process)        
        printf("hello, I am child (pid:%d)\n",getpid());    
    }     
    else 
    {        // parent goes down this path (main)        
        printf("hello, I am parent of %d (pid:%d)\n",rc,getpid());    
    }
}