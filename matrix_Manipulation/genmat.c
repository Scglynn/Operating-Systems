#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("usage: %s <num> <max> <name>\n",argv[0]);
        return 1;
    }
    int N = atoi(argv[1]);
    int MAX = atoi(argv[2]);
    if (N < 1 || MAX < 2) {
        printf("bad parameters (%d,%d)\n",N,MAX);
        return 1;
    }

    int fd = open(argv[3],O_CREAT|O_TRUNC|O_WRONLY,0666);
    if (fd < 0) {
        printf("open %s failed\n",argv[3]);
        return 1;
    }
    
    srand((unsigned)time(NULL));
    int rows,cols;
    cols = 1+rand()%MAX;
    for (int i=0; i<N; i++) {
        // output each matrix
        rows = cols;
        cols = 1+rand()%MAX;
        if (write(fd,&rows,sizeof(rows)) != sizeof(rows)) goto bad;
        if (write(fd,&cols,sizeof(cols)) != sizeof(cols)) goto bad;

        for (int j=0; j<rows*cols; j++) {
            int x = rand();
            if (write(fd,&x,sizeof(x)) != sizeof(x)) goto bad;
        }
    }
    rows = cols = 0;
    if (write(fd,&rows,sizeof(rows)) != sizeof(rows)) goto bad;
    if (write(fd,&cols,sizeof(cols)) != sizeof(cols)) goto bad;
    close(fd);
    return 0;

bad:
    printf("write failed\n");
    close(fd);
    return 1;
}
