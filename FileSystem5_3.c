#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#pragma pack(1)

int main(int argc,char *argv[])
{
   DIR *dp = NULL;
   struct dirent *entry =NULL;
   int fd = 0;
   char path[30];
   char buffer[4096];
   dp = opendir(argv[1]);
   if(dp == NULL)
   {
     printf("Unable to open the directory\n");
     return -1;
   }
   while((entry = readdir(dp)) != NULL)
   {
       sprintf(path,"%s/%s",argv[1],entry->d_name);
       write(1,path,sizeof(path));
       printf("\t");
       fd = open(path,O_RDONLY);
       read(fd,buffer,sizeof(buffer));
       write(1,buffer,sizeof(buffer));
       printf("\n");
   }
 
   return 0;  
}
