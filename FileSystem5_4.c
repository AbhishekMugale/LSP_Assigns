#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct FileInfo
{
    char Filename[9];
    int FileSize;
};

int main(int argc,char *argv[])
{
   DIR *dp = NULL;
   struct dirent *entry =NULL;
   struct FileInfo fobj;
   struct stat sobj;
   int fd = 0;
   char path[30];
   dp = opendir(argv[1]);
   if(dp == NULL)
   {
     printf("Unable to open the directory\n");
     return -1;
   }
   fd = creat("AllCombine.txt",0777);
   if(fd == -1)
   {
      printf("Unable to create file\n");
      closedir(dp);
      return -1;
   }
   
   while((entry = readdir(dp)) != NULL)
   {
       sprintf(path,"%s/%s",argv[1],entry->d_name);
       stat(path,&sobj);
       fobj.FileSize = sobj.st_size;
       strcpy(fobj.Filename,entry->d_name);
       write(fd,&fobj,sizeof(fobj));
       
       printf("%s\n",entry->d_name); 
   }
 
   return 0;  
}
