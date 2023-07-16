#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define BLOCKSIZE 1024
int main(int argc,char *argv[])
{
   int fdsource = 0;
   int fdest = 0;
   int fd = 0;
   char buffer[BLOCKSIZE];
   int Ret = 0;
   fdsource = open(argv[1],O_RDONLY);
   if(fdsource == -1)
   {
      printf("Unable to open the file\n");
      return -1;
   }
   
   fdest = creat(argv[2],0777);
   if(fdest == -1)
   {
      printf("Unable to open the file\n");
      close(fdsource);
      return -1;
   }
   
   
   while((Ret = read(fdsource,buffer,sizeof(buffer))) != 0)
   {
       write(fdest,buffer,Ret);
       memset(buffer,0,sizeof(buffer));
   } 

   close(fdsource);
   close(fdest);
   return 0;
}
