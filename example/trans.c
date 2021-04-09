#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// RUNNING
// gcc -Wall -Werror -O2 trans.c -o transpose
// valgrind --leak-check=yes -q --vgdb=no ./transpose fd_to_read fd_to_write.txt

struct matrix{
    int row;
    int col;
};

int VAL = 0;
int VAL2 = 0;
int count = 0;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Missing files\n");
        return 1;
    }
    struct matrix dimension;

    // O read
    int fd_to_read = open(argv[1], O_RDONLY, 0666);
    if (fd_to_read < 0)
    {
        printf("open %s failed\n",argv[1]);
        return 1;
    }

    // O write
    int fd_to_write = open(argv[2],O_CREAT|O_TRUNC|O_WRONLY,0666);
    if (fd_to_write < 0)
    {
        printf("open %s failed\n",argv[2]);
        return 1;
    }

    if (fd_to_read == -1 || fd_to_write == -1)
    {
        printf("file no open\n");
        return -1;
    }

    int *fd = (int *)malloc(1000000 * sizeof(*fd));


    if (read(fd_to_read, &dimension, sizeof(dimension)) != sizeof(dimension))
    {
        printf("read failed\n");
        return -1;
    }

    VAL = read(fd_to_read, fd, (dimension.row * dimension.col) * sizeof(dimension));

    int t = dimension.row;
    dimension.row = dimension.col;
    dimension.col = t;

    int transpose[dimension.row][dimension.col];

    for(int i = 0; i < dimension.col; i++)
    {
        for(int j = 0; j < dimension.row; j++, count++)
        {
            transpose[j][i] = fd[count];
            //(void)fd =transpose[j][i];
        }
    }

    if(write(fd_to_write, &dimension, sizeof(dimension)) != sizeof(dimension))
    {
        printf("write failed\n");
        return -1;
    }

    VAL2 = write(fd_to_write, *transpose, (dimension.row * dimension.col) * sizeof(int));

    free(fd);
    close(fd_to_read);
    close(fd_to_write);
    return 0;
}
