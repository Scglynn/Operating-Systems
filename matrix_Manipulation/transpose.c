#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

struct matrix {
    int row;
    int column;
};

int main(int argc, char *argv[]) 
{
    
    
    struct matrix matrices;
    char * input_file;
    char * output_file;
    if (argc !=3)
    {
        printf("you are missing an input or output file name\n");
        exit(1);
    }

    input_file = argv[1];
    output_file = argv[2];

    int fd = open(input_file, O_RDONLY, 0666);
    if (fd < 0)
    {
        printf("Failed to create and open the file");
        exit(1);
    }
    if(read(fd,&matrices,sizeof(matrices)) != sizeof(matrices)) goto bad;
    for (int i = 0; i < matrices.row*matrices.column; i++)
    {
        int x;
        if(read(fd, &x, sizeof(x)) != sizeof(x)) goto bad;
    }
    
    close(fd);
    return 0;

bad:
    printf("read failed\n");
    close(fd);
    return 1;


}