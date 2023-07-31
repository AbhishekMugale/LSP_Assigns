#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  int Ret = 0;
  
  Ret = fork();
  
  // If child process then exit 
  if(Ret == 0)
  {
     exit(0);
  }
  
  // THis function is used to create new session or group for the calling process.This function detaches the calling process from its calling terminal and makes it session leader.
  setsid();
  
  //close the standard input,output and error file descriptors.
  close(0);
  close(1);
  close(2);
  
  //continue running in background.
  while(1)
  {}

   return 0;
}
