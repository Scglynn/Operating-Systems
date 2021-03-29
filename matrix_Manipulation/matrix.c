#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>



void read_matrices() {

}
void mult_matrices() {

}
void show_matrices() {

}

int main(__attribute__((unused)) int argc, const char* sam_file[]) 
{
    FILE *fPointer;
    uint64_t diff,writ,comp,read;
    struct timespec start, end;


    fPointer = fopen(sam_file[1], "r");

    while(1)
    {
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

    }
    fclose(fPointer);

    return 0;
}