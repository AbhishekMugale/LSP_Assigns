#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
   int fd = 0,ret = 0;
   char arr[20];
   fd = open(argv[1],O_RDONLY);
   if(fd == -1)
   {
      printf("Unable to open the file\n");
      return -1;
   }  
   lseek(fd,atoi(argv[2]),0);
   ret = read(fd,arr,20);
   printf("Data from the file is\n");
   write(1,arr,ret); 
  
  return 0;
}
