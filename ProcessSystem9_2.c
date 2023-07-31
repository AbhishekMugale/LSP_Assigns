#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
   int ret1 = 0,ret2 = 0;
   int status1,status2;
   ret1 = fork();
   if(ret1 == 0)
   {
      execl("./small","NULL",NULL);
   }
   wait(&status1);
   
   ret2 = fork();
   if(ret2 == 0)
   {
      execl("./capital","NULL",NULL);
   }
   wait(&status2);
   
   return 0;
}
