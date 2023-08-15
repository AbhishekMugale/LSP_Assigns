// Client for Shared Memory

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/shm.h>
int main()
{
   int shmid = 0;
   int shmsize = 100;
   int Key = 1234;
   char *ptr = NULL;
   
   printf("Client application is running...\n");
   
   shmid = shmget(Key,shmsize,0666);
   
   printf("Shared Memory allocated succesfully...\n");
   
   ptr = shmat(shmid,NULL,0);
   
   if(ptr != NULL)
   {
      printf("Shared Memory attached succesfully...\n");
   }
   
   while(*ptr != '\0')
   {
     printf("%c",*ptr);
     ptr++;
   }
 
    
   
    return 0;
}
