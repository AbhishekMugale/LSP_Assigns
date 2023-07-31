#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sched.h>

int main()
{
   int ret = 0;
  printf("Before Yeild\n");
  ret = sched_yield();
  if(ret == -1)
  {
     printf("Unable to yeild\n");
     return -1;
  }
  printf("After yield\n");

}
