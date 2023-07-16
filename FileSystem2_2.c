#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
   int fd = 0,Ret = 0;
   char buffer[12] = {" AbhiMugale"};
   if(argc != 2)
   {
      printf("Invalid NUmber of Arguments\n");
      return -1;
   }
   
   fd = open(argv[1],O_WRONLY | O_APPEND);
   if(fd == -1)
   {
      printf("Unable to open the file in append mode");
   }
   
   write(fd,buffer,10);   
   
   close(fd);
   
   return 0;
}

