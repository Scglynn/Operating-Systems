#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 1000

int arows, acolumns;
int i, j,k;
int matrix[MAX][MAX];

int brows, bcolumns;
int matrix2[MAX][MAX];
int r_rows,r_columns;
int results[MAX][MAX];

void read_matrices() {
    //this will read in what is inside the binary file and create the desired matrices

    //this will make the size of the matrix
    scanf("%d %d", &arows, &acolumns);

    //this will take in the elements for the first matrix
    for (i = 0; i < arows; i++)
    {
        for (j = 0; j < acolumns; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    //this will make the size of the second matrix
    scanf("%d %d", &arows, &bcolumns);

    //this will take in the elements for the second matrix
    for (i = 0; i < brows; i++)
    {
        for (j = 0; j < bcolumns; j++)
        {
            scanf("%d ", &matrix2[i][j]);
        }
    }
    printf("using read matrices function\n");
}
void mult_matrices() {

   // Multiplying first and second matrices and storing it in result
   for (i = 0; i < arows; ++i) {
      for (j = 0; j < bcolumns; ++j) {
         for (k = 0; k < brows; ++k) {
            results[i][j] += matrix[i][k] * matrix2[k][j];
         }
      }
   }
    printf("using multiply matrices function\n");
}
void show_matrices() {
    //this will show the new matrices after multiplying 
    //this is where we will also sort each row in ascending order
    for ( i = 0; i < r_rows; i++)
    {
        for ( j = 0; j < r_columns; j++)
        {
            printf("%d  ", results[i][j]);
            if (j == r_columns - 1)
            {
                printf("\n");
            }
        }
    }
    printf("using show matrices function\n");

}

int main(__attribute__((unused)) int argc, const char* sam_file[]) 
{
    uint64_t diff,writ,comp,read;
    struct timespec start, end;

    int fPointer = open(sam_file[1], O_RDONLY,O_WRONLY);
    //start the elapsed clock
    clock_gettime(CLOCK_REALTIME, &start);

    // initialize any global variables
    //start reading clock
    clock_gettime(CLOCK_REALTIME, &start);
    read_matrices();
    clock_gettime(CLOCK_REALTIME, &end);
    read = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    //end reading clock


    //start computing clock
    clock_gettime(CLOCK_REALTIME, &start);
    mult_matrices();
    clock_gettime(CLOCK_REALTIME, &end);
    comp = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    //end computing clock

    //start writing clock
    clock_gettime(CLOCK_REALTIME, &start);
    show_matrices();
    clock_gettime(CLOCK_REALTIME, &end);
    writ = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    //end writing clock

    clock_gettime(CLOCK_REALTIME, &end);
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;

    // report time
    printf("Reading:       %luns\n", read);
    printf("Compute:       %luns\n", comp);
    printf("Writing:       %luns\n", writ);
    printf("Elapsed:       %luns\n", diff);

    
    close(fPointer);

    return 0;
}