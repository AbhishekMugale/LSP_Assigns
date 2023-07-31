#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
   int status;
   int pid;
   pid = fork();
   if(pid == 0)
   {
     printf("RUnning the child process\n");
     exit(EXIT_SUCCESS);
   }
   else
   {
      // THis is Parent Process
      wait(&status);
      printf("Child Process exited with status %d\n",status);
   }

   return 0;
}
