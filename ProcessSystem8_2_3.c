#include<stdio.h>
#include<unistd.h>

int main()
{
  printf("This is process 3 running with pid %d\n",getpid());
  
  return 0;
}
