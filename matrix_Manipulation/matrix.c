#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <time.h>


// uint64_t diff;
// struct timespec start, end;
// clock_gettime(CLOCK_REALTIME, &start);
// /* do stuff */
// clock_gettime(CLOCK_REALTIME, &end);
// diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
// printf("elapsed time = %luns\n", diff);

void read_matrices() {

}
void mult_matrices() {

}
void show_matrices() {

}

int main(__attribute__((unused)) int argc,const char* sam_file[]) 
{
    FILE *fPointer;

    //char c;

    fPointer = fopen(sam_file[1], "r");

    // while(1)
    // {
    //     c = getc(fPointer);

    // }
    fclose(fPointer);

    // initialize any global variables
    //start the elapsed clock

    read_matrices();
    //start reading clock


    mult_matrices();
    //start computing clock


    show_matrices();
    //start writing clock

    // report time

    return 0;
}