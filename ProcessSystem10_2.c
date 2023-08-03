#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
   int i=0;
   for(i=1;i<=500;i++)
   {
      printf("%d\n",i);
   }
}

void * ThreadProc2(void *ptr)
{
   int i=0;
   for(i=500;i>0;i--)
   {
      printf("%d\n",i);
   }
}

int main()
{
   pthread_t TID1,TID2;
   int ret1,ret2;
   
   ret1 = pthread_create(&TID1,NULL,ThreadProc1,NULL);
   if(ret1 != 0)
   {
      printf("Unable to create the thread1\n");
      return -1;
   }
   
   ret2 = pthread_create(&TID2,NULL,ThreadProc2,NULL);
   if(ret2 != 0)
   {
      printf("Unable to create the thread2\n");
      return -1;
   }
   
   
      pthread_join(TID1,NULL);
      pthread_join(TID2,NULL);
      printf("Thread1 is created with ID : %ld\n",TID1);
      printf("Thread2 is created with ID : %ld\n",TID2); 
     printf("End of main thread\n");    
 
  return 0;
}
