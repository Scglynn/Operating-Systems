#include <stdio.h>

int f(int x)
{
    if(x<2) return x;
    return f(x-1)+f(x-2);
}

int main()
{
    unsigned char *p =(unsigned char *) &f;
    //unsigned char byte = *p;
    printf("%02x ",*p);
    printf("%02x ",p[1]);
}