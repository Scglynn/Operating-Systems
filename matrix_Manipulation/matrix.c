#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>

uint64_t diff,writ,comp,rd;
struct timespec start, end;


struct matrix {
    int row;
    int column;
    int **matrix_1;
};

struct matrix current;
struct matrix * matrices;
struct matrix * answers;
int fPointer;
char * input_file;
char * output_file;


void read_matrices() {
    fPointer = open(input_file, O_RDONLY|O_WRONLY);

    //this will read in what is inside the binary file and create the desired matrices
    //this will make the size of the matrix
    for (int i = 0; i < 100; i++)
    {
        int rows, columns;
        if(!read(fPointer, &rows,sizeof(rows)))
        {
            printf("Can not read file");
            exit(1);
        }
        if(!read(fPointer, &columns,sizeof(columns)))
        {
            printf("can not read file");
            exit(1);
        }
        matrices[i].row = rows; 
        matrices[i].column = columns; 
        matrices[i].matrix_1 = malloc(matrices[i].row *sizeof(matrices[i]));
        for (int j = 0; j < rows; j++)
        {
            matrices[i].matrix_1[j] = malloc(matrices[i].column*sizeof(int));
            for (int k = 0; k < columns; k++)
            {
                int value;
                if(!read(fPointer, &value,sizeof(value)))
                {
                    printf("Can not read file");
                    exit(1);
                }
                matrices[i].matrix_1[j][k] = value;
            }
        }
        
        
        
    }
}

// void mult_matrices() {

//    // Multiplying first and second matrices and storing it in result
//    //then we will also sort each row in ascending order
// }
// void show_matrices() {
//     //this will show the new matrices after multiplying 
//     //this is where we will also sort each row in ascending order

// }

int main(__attribute__((unused)) int argc, char* argv[]) 
{
    input_file = argv[1];
    //start the elapsed clock
    clock_gettime(CLOCK_REALTIME, &start);

    // initialize any global variables
    //start reading clock
    clock_gettime(CLOCK_REALTIME, &start);
    read_matrices();
    clock_gettime(CLOCK_REALTIME, &end);
    rd = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    //end reading clock


    // //start computing clock
    // clock_gettime(CLOCK_REALTIME, &start);
    // mult_matrices();
    // clock_gettime(CLOCK_REALTIME, &end);
    // comp = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    // //end computing clock

    // //start writing clock
    // clock_gettime(CLOCK_REALTIME, &start);
    // show_matrices();
    // clock_gettime(CLOCK_REALTIME, &end);
    // writ = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    // //end writing clock

    clock_gettime(CLOCK_REALTIME, &end);
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;

    // report time
    printf("Reading:       %luns\n", rd);
    // printf("Compute:       %luns\n", comp);
    // printf("Writing:       %luns\n", writ);
    printf("Elapsed:       %luns\n", diff);

    
    close(fPointer);

    return 0;
}