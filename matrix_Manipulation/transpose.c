#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct matrix {
    int row;
    int column;
};

int val = 0;
int holder = 0;
int count = 0;

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

    int fd_read = open(input_file,O_RDONLY, 0666);
    if (fd_read < 0)
    {
        printf("Failed to read and open the file");
        exit(1);
    }

    //this will write the transpose matrices to the outputfile 
    int out = open(output_file, O_CREAT|O_TRUNC|O_WRONLY,0666);
    if (out < 0)
    {
        printf("Failed to create and open the file");
        exit(1);
    }

    int *x =(int *)malloc(1000000/*(matrices.row*matrices.column)*/* sizeof(*x));
 

    //stores(reads) in the matrix with all of it's elements
    if(read(fd_read,&matrices,sizeof(matrices)) != sizeof(matrices))
    {
        printf("read failed\n");
        close(fd_read);
        return 1;
    }

    holder = read(fd_read, x, (matrices.row * matrices.column)*sizeof(matrices));


    //transpose the matrix
    int z = matrices.row;
    matrices.row = matrices.column;
    matrices.column = z;

    //the new transpose matrix
    int transpose[matrices.row][matrices.column];

    for (int k = 0; k < matrices.row; k++)
    {
        for (int l = 0; l < matrices.row; l++, count++)
        {
            transpose[l][k] = x[count];
        }
        
    }
    


    if(write(out,&matrices,sizeof(matrices)) != sizeof(matrices)) goto bad1;

    //places the elements
    val = write(out, *transpose,(matrices.row * matrices.column)*sizeof(int));


    free(x);
    close(fd_read);
    close(out);
    return 0;

bad1:
    printf("write failed\n");
    close(out);
    return 1;

}