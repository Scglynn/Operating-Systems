#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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

    int fd = open(input_file,O_CREAT|O_RDONLY, 0666);
    if (fd < 0)
    {
        printf("Failed to read and open the file");
        exit(1);
    }
    //stores(reads) in the matrix with all of it's elements
    if(read(fd,&matrices,sizeof(matrices)) != sizeof(matrices)) goto bad;
    for (int i = 0; i < matrices.row/**matrices.column*/; i++)
    {
        //places the elements
        int * x =(int *)malloc(matrices.row*matrices.column*sizeof(int));
        if(read(fd, x, sizeof(x)) != sizeof(x)) goto bad3;
        free(x);
    }
    close(fd);


    //this will write the transpose matrices to the outputfile 
    int out = open(output_file, O_CREAT|O_WRONLY,0666);
    if (out < 0)
    {
        printf("Failed to create and open the file");
        exit(1);
    }
    if(write(out,&matrices,sizeof(matrices)) != sizeof(matrices)) goto bad1;
    for(int j = 0; j < matrices.row*matrices.column; j++)
    {
        //places the elements
        int * y = (int *)malloc(matrices.row*matrices.column*sizeof(int));
        if(write(out, y, sizeof(y)) != sizeof(y)) goto bad1;
        free(y);
    }
    
    close(out);
    return 0;

bad:
    printf("read failed\n");
    close(fd);
    return 1;

bad1:
    printf("write failed\n");
    close(out);
    return 1;
bad3:
    printf("failed reading in the elements\n");
    close(fd);
    return 1;

}