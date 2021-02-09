#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "parse.h"

int 
main(int argc, char* argv[]) {

    char* input = (char*)malloc(1024);
   
    command cmd;
    
 
    

    while(1) {
        printf(1,"shell> ",getpid());
        gets(input,1024);
        int rc = parse(input,&cmd);
        rc = fork();
        
        
        

        //checking to see if the command in shell is 'exit'
        if (strcmp(input, cmd.argv[0]="exit")==0)
        {
            wait();
        }
        
        //checking to see if the command in shell is 'echo'
        if (strcmp(input,cmd.argv[0]="echo")==0)
        {
            
            if (rc < 0)
            {
                
                printf(2,"fork failed");

            }else if (rc == 0)
            {
                exec(cmd.argv[0],cmd.argv);
                if (cmd.input)
                {
                    close(0);
                    open(cmd.input, O_CREATE | O_RDONLY);
                }
                if (cmd.output)
                {
                    close(1);
                    open(cmd.output, O_CREATE | O_WRONLY);

                }
                
            }else{
                wait();
                //printf(1,"hello, I am parent of %d (pid:%d)\n",rc,getpid());
            }
            if (strcmp(input,cmd.argv[0]="echo")==0)
            {

                if (cmd.input)
                    {
                        close(0);
                        open(cmd.input,O_CREATE | O_RDONLY);
                    }
                    if (cmd.output)
                    {
                        close(1);
                        open(cmd.output,O_CREATE | O_WRONLY);

                    }
                    exec(cmd.argv[0],cmd.argv);
            }
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