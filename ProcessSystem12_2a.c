//server for shared memory

#include<unistd.h>
#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>

int main()
{
   int shmid;
   int shmsize = 0;
   int key = 1234;
   char *ptr = NULL;
   
   shmid = shmget(key,shmsize,IPC_CREAT | 0666);
   
   printf("Server application is running...\n");
   
   printf("Shared Memory allocated succesfully\n");
   
   ptr = shmat(shmid,NULL,0);
   
   if(ptr != NULL)
   {
      printf("Shared Memory attached succesfully\n");
   }
   
   *ptr = 'A';
   ptr++;
   
   *ptr = 'b';
   ptr++;
   
   *ptr = 'h';
   ptr++;
   
   *ptr = 'i';
   ptr++;
   
   *ptr = 'j';
   ptr++;
   
   *ptr = '\0';
   ptr++;
   
   printf("Data Writen succesfully\n");

   return 0;
}
