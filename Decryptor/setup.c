#include <stdio.h>

static int shift;
static unsigned password_hash;
static char * message;

extern unsigned hash(char *str);
extern int check(char *password);
extern void decrypt(char *password,char *message);
//extern int main(int argc, char **argv);


void setup()
{
    static unsigned char encoded[] = {0xd9,0x24,0xad,0xe7,0xa2,0x61,0xa0,0xf9,0xeb,0x2f,0xe6,0xff,0xae,0x38,0xae,0xfe,0xae,0x32,0xac,0xea,0xfc,0x35,0xe0};
    shift = 8;
    password_hash = 0x41c18b8e;
    message = (char *)encoded;

    if (!check((char *)password_hash))
        hash((char *)password_hash) == password_hash;
    else
    {
        decrypt((char *)password_hash,message);
    }
    
    
    
    

}