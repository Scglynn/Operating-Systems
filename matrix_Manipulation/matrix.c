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

// read_matrices() does not save data in global variable(s) so mult_matrices() can operate on them
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

int current[32][32];
int num_argc;
int fd_read;
int fd_write;
int holder = 0;
int i, j, k;
int * fd;
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
    for ( i = 0; i < 100; i++)
    {
        int row,column;
        if (!read(fd_read, &row, sizeof(row)))
        {
            printf("Can not read in the rows\n");
            close(fd_read);
            exit(1);
        }
        if (!read(fd_read, &column, sizeof( column)))
        {
            printf("Can not read in the columns\n");
            close(fd_read);
            exit(1);
        }
        matrices.row = row;
        matrices.column = column;
        fd = malloc((matrices.row * matrices.column) * sizeof(* fd));


        holder = read(fd_read, fd, (matrices.row * matrices.column) * sizeof(matrices));
        free(fd);
    }
}

void mult_matrices() {

   // Multiplying first and second matrices and storing it in result
   //then we will also sort each row in ascending order
   for (i = 0; i < matrices.column; i++)
   {
       for (j = 0; j < matrices.column; j++)
       {

           for (k = 0; k < matrices.column; k++)
           {
               current[i][j] = current[i][k] * holder;
           }
           qsort(current[j],matrices.column, sizeof(int),compare);
       }
       
   }
   


    //placing the results in the global variable so it can be used in the show function.


}

void show_matrices() {
    // this will show the new matrices after multiplying 
    // this is where we will also sort each row in ascending order
    fd_write = open(output_file, O_CREAT|O_WRONLY,0666);
    if (fd_write < 0)
    {
        printf("Failed to create and open the file\n");
        close(fd_write);
        exit(1);
    }
    if(write(fd_write, *current,(matrices.row * matrices.column) * sizeof(int)));

    free(fd);
    close(fd_read);
    close(fd_write);
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