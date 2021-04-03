#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

struct matrix {
    int row;
    int column;
    int ** data;
};

int main(int argc, char *argv[]) 
{
    
    struct matrix matrices;
    char * input_file;
    char * output_file;

    input_file = argv[1];
    output_file = argv[2];

    int fd = open(input_file, O_CREAT|O_RDONLY, 0666);
    if (fd < 0)
    {
        printf("Failed to create and open the file");
        exit(1);
    }
    
    int rows, columns;
    if(!read(fd, &rows,sizeof(rows)))
    {
        printf("Can not read file");
        exit(1);
    }
    if(!read(fd, &columns,sizeof(columns)))
    {
        printf("can not read file");
        exit(1);
    }
    matrices.row = rows;
    matrices.column = columns;
    matrices.data = malloc(matrices.row*sizeof(matrices));

    if (read(fd, &matrices,sizeof(matrices)) != sizeof(matrices)) goto bad;

    for (int i = 0; i < matrices.row*matrices.column; i++)
    {
        int x;
        if(read(fd, &x, sizeof(x)) != sizeof(x)) goto bad;
    }
    free(fd);
    close(fd);
    return 0;

bad:
    printf("read failed\n");
    close(fd);
    return 1;


}