#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>


int main(int argc,char *argv[])
{
   DIR *dp = NULL;
   struct dirent *entry = NULL;
   char path[30];
   struct stat sobj;
   dp = opendir(argv[1]);
   if(dp == NULL)
   {
      printf("Unable to open the directory\n");
      return -1;
   }
   int size = 0,ret = 0,fd = 0 ;
   while((entry = readdir(dp))!=NULL)
   {
      sprintf(path,"%s/%s",argv[1],entry->d_name);
      stat(path,&sobj);
      if(S_ISREG(sobj.st_mode))
      {
       fd = open(path,O_RDWR);
       if(fd == -1)
       {
          printf("Unable to open the file %s\n:",path);
       }   
       if(sobj.st_size < 1024)
       {         
         lseek(fd,0,SEEK_END);
         write(fd,"",0);
       }
       else
       {
         
         size = sobj.st_size - 1024;
         ret = ftruncate(fd,size);
         write(1,"Hii",3);
       }
      } 
   }
   

  return 0;
}
