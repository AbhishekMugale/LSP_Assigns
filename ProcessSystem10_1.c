#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void * ThreadProc(void * ptr)
{
   printf("Inside thread\n");
}

int main()
{
   pthread_t TID;
   int ret = 0;
   
   ret = pthread_create(&TID,NULL,ThreadProc,NULL);
   
   if(ret != 0)
   {
      printf("Unable to create the thread\n");
      return -1;
   }
   
   printf("Thread created with ID %ld\n",TID);

  return 0;
}
