#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>

struct matrix
{
    int row;
    int col;
};

struct matrix matrices;
char * input_file;
char * output_file;
int num_argc;
int fd_read;
int fd_write;
int *fd;

int *transpose;
int holder = 0;
int count = 0;
int val_hold = 0;

void read_matrices() {
    fd_read = open(input_file, O_RDONLY);
    if (fd_read < 0)
    {
        printf("Failed to open and read in the file");
        exit(1);
    }
    for (int i = 0; i < 200; i++)
    {
        int row, column;
        if (!read(fd_read, &row, sizeof(row)))
        {
            printf("Can not read in the rows");
            close(fd_read);
            exit(1);
        }
        if (!read(fd_read, &column, sizeof(column)))
        {
            printf("Can not read in the rows");
            close(fd_read);
            exit(1);
        }

        matrices.row=row;
        matrices.col=column;
        fd = (int *)malloc((matrices.row * matrices.col) * sizeof(*fd));

        if (!read(fd_read, &matrices, sizeof(matrices)))
        {
            printf("Can not read in the elements");
            close(fd_read);
            exit(1);
        }
        holder = read(fd_read, fd, (matrices.row * matrices.col) * sizeof(*fd));
        free(fd);
        
    }
    
    

}

void mult_matrices() {


}
void show_matrices()
{
    fd_write = open(output_file, O_CREAT|O_TRUNC|O_WRONLY, 0666);
    if (fd_write < 0)
    {
        printf("Failed to create and write in the file");
        exit(1);
    }
    if(!write(fd_write, &matrices, sizeof(matrices)))
    {
        printf("failed to write");
        exit(1);
    }
    //val_hold = write(fd_write, *holder, (matrices.row * matrices.col) * sizeof(int));
    //free(fd);
    close(fd_read);
    close(fd_write);

}


int main(int argc, char * argv[])
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
}