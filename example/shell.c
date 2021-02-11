#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "parse.h"

#define EXEC  1
#define REDIR 2
#define LIST  3
#define BACK  4

struct cmd {
  int type;
};

struct execcmd {
  int type;
  char *argv[NUMARGS];
  char *eargv[NUMARGS];
};

struct redircmd {
  int type;
  struct cmd *cmd;
  char *file;
  char *efile;
  int mode;
  int fd;
};

struct listcmd {
  int type;
  struct cmd *left;
  struct cmd *right;
};

struct backcmd {
  int type;
  struct cmd *cmd;
};


int 
main(int argc, char* argv[]) {

    char* input = (char*)malloc(1024);
    command cmd;

    while(1) {
        printf(1,"shell> ",getpid());
        gets(input,1024);
        int rtrn_c = parse(input,&cmd);

        rtrn_c = fork();

        //checking to see if the command in shell is 'echo'
        if (strcmp(input,cmd.argv[0]="echo")==0)
        {
            if (rtrn_c < 0)
            {
                
                printf(2,"fork failed");

            }else if (rtrn_c == 0) {
                
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
                exec(cmd.argv[0],cmd.argv);
                
            }else {
                wait();
                //printf(1,"hello, I am parent of %d (pid:%d)\n",rtrn_c,getpid());
            }
        }
            //checking to see if the command in shell is 'echo'
        if (strcmp(input,cmd.argv[0]="echo")==0)
        {
            if (rtrn_c < 0)
            {
                
                printf(2,"fork failed");

            }else if (rtrn_c == 0) {
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
                
            }else {
                wait();
                //printf(1,"hello, I am parent of %d (pid:%d)\n",rtrn_c,getpid());
            }
        }
        if (strcmp(input,cmd.argv[0]="wait")==0)
        {
            if (rtrn_c < 0)
            {
                printf(1,"fork failed\n");
            }
            else if (rtrn_c == 0)
            {
                wait();
                printf(2,"exec failed\n");
            }
            else
            {
                wait();
            }
            
        }
        //checking to see if the command in shell is 'exit'
        if (strcmp(input, cmd.argv[0]="exit")==0)
        {
            exit();
        }
        
        if (strcmp(input, cmd.argv[0]="ls")==0)
        {
            if (rtrn_c< 0)
            {
                // fork failed
                printf(2, "fork failed\n");
            }else if (rtrn_c == 0)
            {
                exec(input,cmd.argv);
                printf(2,"exec failed\n");
            }else{
                wait();
                printf(1,"finished process %d (pid:%d)\n",rtrn_c,getpid());
            }
        }
    }
    exit();
}