#include<stdio.h>
#include<unistd.h>

int main()
{
  int Ret = fork();
  
  if(Ret == 0)
  {
     execl("./Process2","NULL",NULL);
  }
  else
  {
     printf("Process 1 or parent is running with PID : %d\n",getpid());
  }
  
  return 0;
}
