#include <stdio.h>
int global =0;
int main()
{
    while(1)
    {
        printf("%d", global);
        global++;
    }
}