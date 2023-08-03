#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
   printf("The value passed as a parameter from main is %d\n",(int)ptr);
}

int main()
{
   pthread_t TID;
   
   int ret = 0;
   int no = 51;
   ret = pthread_create(&TID,NULL,ThreadProc,(int *)no);
 
   if(ret != 0)
   {
      printf("Unable to create a thread\n");
      return -1;
   }
   
   printf("Thread is created with ID : %ld\n",TID);     
   pthread_join(TID,NULL);
   printf("End of main thread\n"); 
   
   return 0;
}
