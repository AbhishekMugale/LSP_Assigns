#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
   int fd = 0;
   char * Buffer = NULL;
   int Ret = 0;
   if(argc != 3)
   {
      printf("Invalid NUmber of arguments\n");
      return -1;
   }
   
   fd = open(argv[1],O_RDONLY);
   if(fd == -1)
   {
      printf("Unable to open the file\n");
      return -1;
   }
   printf("\n");
   Buffer = (char*)malloc(sizeof(atoi(argv[2])));
   
   Ret = read(fd,Buffer,atoi(argv[2]));
   if(Ret == 0)
   {
     printf("Unable to read the data\n");
     return -1;
   }
      
    printf("Data from file is : %s\n ", Buffer);
  //  write(1,Buffer,Ret);
   

   return 0;
}
