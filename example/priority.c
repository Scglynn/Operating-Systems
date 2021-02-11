#include "types.h"
#include "user.h"


int 
main(int argc, char const *argv[])
{
    getpid();
    if (argc == 1) {
        printf(1,"usage: priority <pid> [<priority>]\n");
        exit();
    }

    // while (1) {
    //     sleep(1);
    //     printf(1,"%s\n",argv[1]);
    // }
    exit();
}
