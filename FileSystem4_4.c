#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/dir.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
  
   DIR *dp = NULL;
   struct dirent *entry = NULL;
   char path[30];
   char Buffer[10];
   int fd = 0,fd2 = 0;
   int Ret = 0;
   dp = opendir(argv[1]);
   if(dp == NULL)
   {
      printf("Unable to open the directory\n");
      return -1;
   }
   fd = creat(argv[2],0777);
   
   while((entry = readdir(dp)) != NULL)
   {
      sprintf(path,"%s/%s",argv[1],entry->d_name);
      fd2 = open(path,O_RDONLY);
      Ret = read(fd2,Buffer,10);
      write(fd,Buffer,Ret);
   }
   

  return 0;
}
