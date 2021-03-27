#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>





uint64_t diff;
struct timespec start, end;
clock_gettime(CLOCK_REALTIME, &start);
/* do stuff */
clock_gettime(CLOCK_REALTIME, &end);
diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
printf("elapsed time = %luns\n", diff);