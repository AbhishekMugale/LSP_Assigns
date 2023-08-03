#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
   printf("Value of thread id from thread is %ld\n",pthread_self());
}


int main()
{
  pthread_t TID;
  int ret = 0;
   
  ret = pthread_create(&TID,NULL,ThreadProc,NULL);
  if(ret != 0)
  {
     printf("Unable to create thread\n");
     return -1;
  } 
  
  printf("Thread id from main thread : %ld\n",TID);
  pthread_join(TID,NULL);
  printf("End of main thread\n");

  return 0;
}
