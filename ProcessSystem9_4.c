#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
  int ret = 0;
  ret = nice(0);
  printf("Current priority of a process is %d\n",ret);
  ret = nice(-5);
  printf("Current priority after incresing  by 5 of a process is %d\n",ret);

  return 0;
}
