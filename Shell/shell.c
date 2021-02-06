#include "parse.h"
#include "types.h"
#include "stat.h"
#include "user.h"
int 
main(int argc, char* argv[]) {

    char* input = (char*)malloc(1024);
    command cmd;

    

    while(1) {
        printf(1,"shell> ",getpid());
        gets(input,1024);
        int rtrn_c = parse(input,&cmd);
        int rc = rtrn_c;
        rc = fork();
        
        if (strcmp(input, cmd.argv[0]="exit")==0)
        {
            free(input);
            exit();
        }
        
        if (strcmp(input, cmd.argv[0]="ls")==0)
        {
            if (rc< 0)
            {
                // fork failed
                printf(2, "fork failed\n");
            }else if (rc == 0)
            {
                exec(input,cmd.argv);
                printf(2,"exec failed\n");
            }else{
                wait();
                printf(1,"finished process %d (pid:%d)\n",rc,getpid());
            }
        }
        

        
        
        
        
        
        
        
        
    }
    exit();
}