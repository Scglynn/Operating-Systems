#include <stdio.h>
#include <unistd.h>

int global = 0;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: mem <string>\n");
        return 0;
    }

    while (1) {
        printf("%s: [%p]=%d\n",argv[1],&global,global); 
        global++;
        sleep(1);
    }
}
