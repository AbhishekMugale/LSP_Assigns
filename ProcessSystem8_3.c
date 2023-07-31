#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
   int pid = 0,i=0;
   
   for(i=1;i<=3;i++)
   {
      pid = fork();
      if(pid == 0)
      {
         printf("This is child process %d\n",i);
         execl("./Process3","NULL",NULL);
      }
      
   }
   for(i=0;i<3;i++)
   {
     wait(NULL);
   }

   return 0;
}
