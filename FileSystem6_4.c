#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
  
    char path[30];
    dp = opendir(argv[1]);
    if(dp == NULL)
    {
       printf("Unable to open the directory");
       return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
      sprintf(path,"%s/%s",argv[1],entry->d_name);
      stat(path,&sobj);
      if(sobj.st_size > 100)
      {
         printf("%s %ld\n",entry->d_name,sobj.st_size);
      }
    }
 
   return 0;
}
