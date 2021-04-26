#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

int num_argc;
char * input_file;
char * output_file;


struct matrix {
    int row;
    int column;
};


void read_matrices()
{

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