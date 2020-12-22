#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void exec(char**, int, char*);

int main(int argc, char *argv[]) {
  char *buff = NULL;
  //pid_t pid = getpid();
  ssize_t bufsize = 0;
  size_t len = 0;
  int size = 0;
  int j = 0;
  int redirect = 0;
  char redirect_file[32];
  
  while((bufsize = getline(&buff, &len, stdin)) != 0) {
   char *args[32];
   char *arg[32];
   buff[strlen(buff) - 1] = '\0';
   
   if(strcmp(buff, "exit") == 0) {
     _exit(1);
   }
   
   for(int i = 0; i < 32; i++) {
     
     args[i] = strsep(&buff, " ");
     
     if(args[i] == NULL) {
       break;
     }
     size++;
   }
   
   for(int i = 0; i < size; i++) {
     if(args[i] != NULL) {
       if(strcmp(args[i], ">") == 0) {
         redirect = 1;
         i++;
         strcpy(redirect_file, args[i]);
         continue;
       }
       arg[j] = args[i];
       j++;
       
     } else {
          break;
     }
   }
   
   free(buff);   

   exec(arg, redirect, redirect_file);
   
   size = 0;
   j = 0;
   bufsize = 0;
   redirect = 0;
   
   for(int i = 0; i < 32; i++){
     args[i] = NULL;
     arg[i] = NULL;
   }
  }
  return 0;
}
