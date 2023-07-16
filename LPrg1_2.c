#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char *argv[])
{
   int fd = 0;
   int mode = 0;
   if(argc != 3)
   {
      printf("Invalid number of arguments\n");
      return -1;
   }
   if(strcmp(argv[2],"Read") == 0)
   {
      fd = open(argv[1],O_RDONLY);
      if(fd == -1)
      {
         printf("Unable to open the file\n");
         return -1;
      }
      else
      {
        printf("file is opened succesfully in a read mode with fd %d\n",fd);     
      }
   }
   else if(strcmp(argv[2],"Write")==0)
   {
      fd = open(argv[1],O_WRONLY);
      if(fd == -1)
      {
         printf("Unable to open the file\n");
         return -1;
      }
      else
      {
        printf("file is opened succesfully in a write mode with fd %d \n",fd);     
      }
   }
   else if(strcmp(argv[2],"ReadWrite")==0)
   {
      fd = open(argv[1],O_RDWR);
      if(fd == -1)
      {
         printf("Unable to open the file\n");
         return -1;
      }
      else
      {
        printf("file is opened succesfully in a read and write mode with fd %d \n",fd);     
      }
   }
   else
   {
      printf("Please enter the proper mode\n");
      return -1;
   }
   
   return 0;
}
