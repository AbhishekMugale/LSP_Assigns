#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char name[50];
    
    dp = opendir(argv[1]);
    if(dp == NULL)
    {
      printf("Unable to open directory\n");
      return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
        
       sprintf(name,"%s/%s",argv[1],entry->d_name);
       stat(name,&sobj);
       if(sobj.st_size == 0)
       {
         remove(name);
       }
       
    }
    
    closedir(dp);
     
  
   return 0;
}
