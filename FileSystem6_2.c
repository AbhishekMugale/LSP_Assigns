#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
   int fd = 0;
   int hole = 1024;
   struct stat sobj;
 
   fd = open("Demo.txt",O_RDWR);
   if(fd == -1)
   {
      printf("Unable to open the file\n");
      return -1;
   }    
   
   lseek(fd,0,SEEK_END);
   
   write(fd,"",hole);
   stat("Demo.txt",&sobj);
   if(sobj.st_size >1023 )
   {
     printf("A hole of size 1 kb is created\n");
   }
   else
   {
      printf("No hole has been created\n");
   }
   close(fd);
   
   

   return 0;
}

