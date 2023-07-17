#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    int fd = 0;
    char path[30];
    dp = opendir(argv[1]);
    if(dp == NULL)
    {
       printf("Unable to open the directory");
       return -1;
    }
    
    sprintf(path,"%s/%s",argv[1],argv[2]);
    
    fd = creat(path,0777);
    if(fd == -1)
    {
       printf("Unable to create the file\n");
       return -1;
    }
    
 
   return 0;
}
