#include "parse.h"
#include "types.h"
#include "stat.h"
#include "user.h"
int 
main(int argc, char* argv[]) {

    char* input = (char*)malloc(1024);
    command cmd;
    

    while(1) {
        printf(1,"Shell> ",getpid());
        gets(input,1024);
        int rtrn_c = parse(input,&cmd);

        rtrn_c = fork();
        
        if (rtrn_c < 0)
        {
            // fork failed
            printf(2, "fork failed\n");
        }
        
        //check if command is exit
        if (rtrn_c == 0){
            
        }
        // //set the last value to Null for exec
        // cmd.argv[i]=0;
        // cmd.argc=i;
        // for (i=0;i<cmd.argc;i++)
        // {
        //     printf(1,"%s\n",cmd.argv[i]);
        // }
        // strcpy(progpath, path);           //copy /bin/ to file path
        // strcpy(progpath, cmd.argv[0]);            //add program to path
        // int rc = fork();                   //fork child
        // if (rc < 0)
        // {
        //     printf(2, "fork failed\n");
        // } else if (rc == 0)
        // {
        //     // child -- "restart"
        //     exec(progpath,cmd.argv);
        //     printf(2,"exec failed\n");
        // } else {
        //     // parent -- wait and report
        //     wait();
        //     printf(1,"finished process %d (pid:%d)\n",rc,getpid());
        // }
        
        
        
        
        
        
        //exit();
    } 



    exit();
}