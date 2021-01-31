#include <stdio.h>
#include <stdlib.h>

int g = 42;
extern char _end;

int main(int argc, char *argv[])
{
    (void)argv;
    char *p = malloc(1);
    printf("main=%p\n",&main);
    printf("global=%p\n",&g);
    printf("_end=%p\n",&_end);
    printf("heap=%p\n",p);
    printf("stack=%p\n",&argc);
}
