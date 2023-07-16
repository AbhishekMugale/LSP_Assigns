#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
int main(int argc,char *argv[])
{
  if(argc != 2)
  {
     printf("Invalid Number of arguments\n");
     return -1;
  }
  
  struct dirent *entry = NULL;
  DIR *dp = NULL;
  char name[20];
  int iMax = 0;
  char namecopy[30];
  struct stat sobj;
  dp = opendir(argv[1]);
  if(dp == NULL)
  {
    printf("Unable to open directory\n");
  }
  while((entry = readdir(dp))!= NULL)
  {
     sprintf(name,"%s/%s",argv[1],entry->d_name);
     stat(name,&sobj);
     if(S_ISREG(sobj.st_mode))
     {
       if(iMax < sobj.st_size)
      {
         iMax = sobj.st_size;
         strcpy(namecopy,name);   
      }
     } 
     
     
  }
  printf("%s %d\n",namecopy,iMax);

  return 0;
}
