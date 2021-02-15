#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int 
main(int argc, char const *argv[])
{
    int pr, pid;
    pid = atoi(argv[1]);
    pr = atoi(argv[2]);

    getpid();
    if (argc == 1) {
        printf(1,"usage: priority <pid> [<priority>]\n");
        exit();
    }
    else if (argc == 2)
    {
        ps();
        printf(1,"\n");
        exit();
    }
    else if (argc == 3){
        if (pr < 0 || pr > 100)
        {
            printf(2,"Invalid priority locations!\n");
            exit();
        }
        else {
            priority(pid,pr);
            exit();
        }
        exit();
    }
    
    exit();
}