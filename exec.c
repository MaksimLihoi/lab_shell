#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void exec(char **arg, int redirect, char *redirect_file) {
   int p = fork();
   int fd;
   
   if(p == 0) {
   
   if(redirect == 1) {
     fd = open(redirect_file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
     dup2(fd, 1);
     close(fd);
   }
   
   switch(p) {
     case 0: {
       if(execvp(arg[0], arg) == -1) {
         perror("execvp");
         _exit(127);
       }
     }   
   }
  } else {
    wait(NULL);
  }
}
