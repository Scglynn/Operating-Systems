#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    if (fork() == 0){
        sleep(5);
        printf("This will finish after the parent\n");
    }
    else
    {
        //sleep(5);
        printf("This will finish before the child\n");
    
    }
    return 0;
}