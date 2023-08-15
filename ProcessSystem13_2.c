#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void sighup()
  {
     signal(SIGHUP,sighup);
     printf("CHILD : I Have received a SIGHUP\n");
  }
  void sigint()
  {
     signal(SIGINT,sigint);
     printf("CHILD : I Have received a SIGINT\n");
  }
  void sigquit()
  {
     printf("Parent process kill child\n");
     exit(0);
  }



int main()
{
  int pid;
  
  if((pid = fork())< 0)
  {
     exit(1);
  } 
  if(pid == 0) // Child Process
  {
     signal(SIGHUP,sighup);
     signal(SIGINT,sigint);
     signal(SIGQUIT,sigquit);
     for(;;);
  }
  else  // Parent Process
  {
    printf("\nPARENT : sending SIGHUP\n");
    kill(pid,SIGHUP);
    sleep(3);
    
    printf("\nPARENT : sending SIGINT\n");
    kill(pid,SIGINT);
    sleep(3);
    
    printf("\nPARENT : sending SIGQUIT\n");
    kill(pid,SIGQUIT);
    sleep(3);
  }
  
  void sighup();
void sigint();
void sigquit();
   
  return 0; 
}

