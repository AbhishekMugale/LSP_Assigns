#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
   printf("Thread1\n");
}
void * ThreadProc2(void *ptr)
{
   printf("Thread2\n");
}
void * ThreadProc3(void *ptr)
{
   printf("Thread3\n");
}
void * ThreadProc4(void *ptr)
{
   printf("Thread4\n");
}
int main()
{
   pthread_t TID1,TID2,TID3,TID4;
   int ret1 = 0,ret2,ret3,ret4;
   
   
  ret1 = pthread_create(&TID1,NULL,ThreadProc1,NULL);
  if(ret1 != 0)
  {
     printf("unable to create thread\n");
     return -1;
  }
  
  ret2 = pthread_create(&TID2,NULL,ThreadProc2,NULL);
  if(ret2 != 0)
  {
     printf("unable to create thread\n");
     return -1;
  }
  ret3 = pthread_create(&TID3,NULL,ThreadProc3,NULL);
  if(ret3 != 0)
  {
     printf("unable to create thread\n");
     return -1;
  }
  ret4 = pthread_create(&TID4,NULL,ThreadProc4,NULL);
  if(ret4 != 0)
  {
     printf("unable to create thread\n");
     return -1;
  }    
  
  pthread_join(TID1,NULL);
  pthread_join(TID2,NULL);
  pthread_join(TID3,NULL);
  pthread_join(TID4,NULL);
  
  printf("End of main thread\n"); 
   
      
   
  
}
