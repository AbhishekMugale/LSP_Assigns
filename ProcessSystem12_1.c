#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
int main()
{
   int ret = 0;
   int FD[2];
   char Buffer[512];
   char Arr[] = "Abhishek Abhi";
   
   pipe(FD);
   ret = fork();
   
   if(ret == 0)
   {
       printf("Child Process is scheduled for reading from the pipe\n");
      close(FD[1]);
      read(FD[0],Buffer,sizeof(Buffer));
      printf("Data from buffer is %s\n",Buffer); 
      // exit(0);
   }
   else
   {
      printf("Parent process is scheduled for writing purpose\n");
      close(FD[0]);
       write(FD[1],Arr,strlen(Arr));
      
      
   }


}
