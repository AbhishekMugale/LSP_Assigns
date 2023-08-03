#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
   int j = (int)ptr;
   printf("Value recived from main thread is :%d\n",(int)ptr);
   pthread_exit(++j);
}
int main()
{
   pthread_t TID;
   int ret = 0,no = 21;
   int value = 0;
   ret = pthread_create(&TID,NULL,ThreadProc,(int *)no);
   if(ret != 0)
   {
      printf("Unable to create thread\n");
      return -1;
   } 
   
   printf("Thread ID is : %ld\n",TID);
   pthread_join(TID,&value);
   printf("Value returned from thread is %d\n",value);
   printf("End of main Thread\n");

  return 0;
}
