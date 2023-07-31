#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
   int ret1 = 0,ret2 = 0;
   int status1 = 0,status2 = 0;
   ret1 = fork();
   
  if(ret1 == 0)
  {
     execl("./process2","NULL",NULL);
  }
  wait(&status1);
  exit(EXIT_SUCCESS);
  ret2 = fork(); 
  if(ret2 == 0)
  {
     execl("./Process3","NULL",NULL);   
  } 
   printf("Parent process is running with pid%d\n",getpid());  
   wait(&status2);
   exit(EXIT_SUCCESS);
  
  
  
  
     
  
  

  return 0;
}
