#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>

struct matrix {
    int row;
    int column;
};

// mult_matrices() does not operate on two matrices
// show_matrices() does not write matrix headers or final 0-0 marker
// elapsed time is not calculated right

int compare (const void *a, const void *b)
{
  int x = *(int *)a;
  int y = *(int *)b;

  if (x<y) 
    return -1; 
  if (x>y) 
    return 1; 
  return 0;
}

struct matrix matrices;

int num_argc;
int size = (100 * 8);
//size_t nbytes = 2 * sizeof(int);
int fd_read;
int fd_write;
int **matrices_size;
int **matrices_values;

int **current;
int holder;

int count_nsize;
int count_nvalue;

char * input_file;
char * output_file;

void read_matrices() 
{
    //this will read in what is inside the binary file and create the desired matrices
    //this will make the size of the matrix
    fd_read = open(input_file, O_RDONLY);
    if(fd_read < 0)
    {
        printf("Failed to read and open the file\n");
        exit(1);
    }
    //Dynamically allocate memory for the pointer to pointer
    matrices_size = malloc(size);
    matrices_values = malloc(size);
    while (read(fd_read, &matrices, 2 * sizeof(int)) == 2 * sizeof(int))
    {
        if (matrices.row != 0 && matrices.column != 0)
        {
            matrices_size[count_nsize] = malloc(2 * sizeof(int));
            /*
            turn the 1d array that has been dynamically allocated with nbytes to a 2d array with the same name 
            the reasoning for you to do this is so that you won't have an overflow in the 2d array
            */
            matrices_size[count_nsize][0] = matrices.row;
            matrices_size[count_nsize][1] = matrices.column;
            count_nsize++;
        }
        else
        {
            break;
        }
        matrices_values[count_nvalue] = malloc(matrices.row * matrices.column * 4);
        if(read(fd_read, matrices_values[count_nvalue], (matrices.row * matrices.column * 4)) != (matrices.row * matrices.column * 4)) break;
        count_nvalue++;
    }
    //free(fd_read);
    close(fd_read);
}

void mult_matrices() {

   // Multiplying first and second matrices and storing it in result
   //then we will also sort each row in ascending order
   int temp[matrices.row * matrices.column];

   

    //placing the results in the global variable so it can be used in the show function.


}

void show_matrices() {
    // this will show the new matrices after multiplying 
    // this is where we will also sort each row in ascending order
    //  fd_write = open(output_file, O_CREAT|O_WRONLY,0666);
    // if (fd_write < 0)
    // {
    //     printf("Failed to create and open the file\n");
    //     close(fd_write);
    //     exit(1);
    // }
    //close(fd_write);
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