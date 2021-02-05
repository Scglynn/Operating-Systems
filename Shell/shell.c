#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.c"

int main(int argc, char* argv[]) {

    command cmd;
    char*line;

    int rc = parse(line, &cmd);

    if (rc == 0)
    {

        cmd.argv[0];
        cmd.argc;
        cmd.bg;
        cmd.input;
        cmd.output;
    }
    
    

    return 0;
}