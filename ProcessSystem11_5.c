#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>

// void * _____(void * ___)
// {}


 void * ThreadProc1(void *ptr)
 {
    
    int fd = 0,i=0;
   char Buffer[512];
   int iRet = 0;
   int iCnt = 0;
   
   fd = open("Demo.txt",O_RDONLY);

   while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
   {
      for(i=0;i<iRet;i++)
      {
         if(Buffer[i]>='a' && Buffer[i]<= 'z')
         {
            iCnt++;
         }
      }
   } 
   printf("Number of Small characters are :%d\n",iCnt);
   
   close(fd);
    pthread_exit(NULL);
 }
 
 void * ThreadProc2(void *ptr)
 {
    
   int fd = 0,i=0;
   char Buffer[512];
   int iRet = 0;
   int iCnt = 0;
   
   fd = open("Demo.txt",O_RDONLY);

   while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
   {
      for(i=0;i<iRet;i++)
      {
         if(Buffer[i]>='A' && Buffer[i]<= 'Z')
         {
            iCnt++;
         }
      }
   } 
   printf("Number of Capital characters are :%d\n",iCnt);
   
   close(fd);
   pthread_exit(NULL);
 }
 
int main()
{
   
     pthread_t TID1,TID2;
     int ret1 = 0,ret2=0;
     
     ret1 = pthread_create(&TID1,NULL,ThreadProc1,NULL);        
     		
     
     					  
     if(ret1 != 0)
     {
        printf("Unable to create thread1\n");
        return -1;
     }
     
     printf("Thread1 is created with ID : %ld\n",TID1);
     
     ret2 = pthread_create(&TID2,NULL,ThreadProc2,NULL);
     
     if(ret2 != 0)
     {
        printf("Unable to create thread2\n");
        return -1;
     }
     
     printf("Thread2 is created with ID : %ld\n",TID2);
     
     
     pthread_join(TID1,NULL);
     pthread_join(TID2,NULL);
     printf("End of main thread\n");  
     
     pthread_exit(NULL);
   return 0;
}
