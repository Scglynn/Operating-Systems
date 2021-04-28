#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

struct matrix matrices;

int num_argc;
int size = (100 * 8);
int fd_read;
int fd_write;
int **matrices_size;
int **matrices_values;

int count_size;
int count_value;

char * input_file;
char * output_file;


struct matrix {
    int row;
    int column;
};


void read_matrices()
{
    //this will read in what is inside the binary file and create the desired matrices
    //this will make the size of the matrix
    fd_read = open(input_file, O_RDONLY);
    matrices_size = malloc(size);
    matrices_values = malloc(size);
    if(fd_read < 0)
    {
        printf("Failed to read and open the file\n");
        exit(1);
    }
    
    while (read(fd_read, &matrices, 2 * sizeof(int)) == 2 * sizeof(int))
    {
        if (matrices.row != 0 && matrices.column != 0)
        {
            matrices_size[count_size] = malloc(2 * sizeof(int));
            matrices_size[count_size][0] = matrices.row;
            matrices_size[count_size][1] = matrices.column;
            count_size++;
        }
        else
        {
            break;
        }
        matrices_values[count_value] = malloc(matrices.row * matrices.column * 4);
        if(read(fd_read, matrices_values[count_value], (matrices.row * matrices.column * 4)) != (matrices.row * matrices.column * 4)) break;
        count_value++;
    }
}

void mult_matrices()
{

}

void show_matrices()
{
    
}



int main(int argc, char* argv[])
{
    input_file = argv[1];
    output_file = argv[2];
    num_argc = argc;
    if(num_argc != 3)
    {
        printf("you are missing an input or output file name\n");
        exit(1);
    }

    uint64_t diff,writ,comp,rd;
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    //read in the matrices
    clock_gettime(CLOCK_REALTIME, &start);
    read_matrices();
    clock_gettime(CLOCK_REALTIME, &end);
    rd = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    printf("Reading:       %9luns\n", rd);


    //compute the matrices
    clock_gettime(CLOCK_REALTIME, &start);
    mult_matrices();
    clock_gettime(CLOCK_REALTIME, &end);
     comp= 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    printf("Compute:       %9luns\n", comp);

    //writes out the new matrices
    clock_gettime(CLOCK_REALTIME, &start);
    show_matrices();
    clock_gettime(CLOCK_REALTIME, &end);
    writ = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    printf("Writing:       %9luns\n", writ);

    //computes the total elapsed time
    clock_gettime(CLOCK_REALTIME, &end);
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    printf("Elapsed:       %9luns\n", diff);

    return 0;
}