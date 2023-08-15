#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>


int main()
{
   int ret = 0;
   int FD[2];
   char Arr[] = "Abhishek Mugale";
   char Buffer[512];
   
   pipe(FD);
   ret = fork();
   if(ret == 0)
   {
      printf("Inside child Process for writing data\n");
      close(FD[0]);
      write(FD[1],Arr,strlen(Arr));      
   }
   else
   {
      printf("Inside Parent process for reading\n");
      close(FD[1]);
      read(FD[0],Buffer,sizeof(Buffer));
      printf("Data from buffer is %s\n",Buffer);
   }


   return 0;
}
