#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>

int counter;
int N;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * inc(void *arg)
{
    for (int i = 0; i < 10000000/N; i++)
    {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
}
int main(int argc, char *argv[])
{
    pthread_t thread[100];

    N = atoi(argv[1]);

    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    for (int i = 0; i < N; i++)
    {
        int r = pthread_create(&thread[i], NULL, inc,NULL);
        assert(!r);
    }

    for (int i = 0; i < N; i++)
    {
        int r = pthread_join(thread[i], NULL);
        assert(!r);
    }

    clock_gettime(CLOCK_REALTIME, &end);
    u_int64_t elapsed = 1000000000LU*(end.tv_sec-start.tv_sec)+end.tv_nsec-start.tv_nsec;
    printf("time = %lluns\n",elapsed);
    printf("counter = %d\n",counter);
    
    return 0;
}