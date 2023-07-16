#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/dir.h>
#include<string.h>
int main(int argc,char *argv[])
{
    if(argc != 3)
    {
       printf("Invalid Arguments\n");
       return -1;
    }
    
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    dp = opendir(argv[1]);
    
    if(dp == NULL)
    {
       printf("Unable to open the directory\n");
       return -1;
    } 
    
    while((entry = readdir(dp))!= NULL)
    {
       
       if(strcmp(argv[2],entry->d_name) == 0)
       {
          printf("The file is present in directory\n");
          break;
       }
    }
    if(entry == NULL)
    {
       printf("There is no such file\n");
    }
    
  
    return 0;
}
