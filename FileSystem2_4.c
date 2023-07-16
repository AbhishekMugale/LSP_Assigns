#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
   DIR *dp = NULL;
   struct dirent *entry = NULL;
   char name[20];
   if(argc != 2)
   {
      printf("Invalid Number of Arguments\n");
      return -1;
   }
   
   dp = opendir(argv[1]);
   
   if(dp == NULL)
   {
      printf("Unable to open the directory\n");
      return -1;
   } 
   
   while((entry = readdir(dp)) != NULL)
   {
       sprintf(name,"%s/%s",argv[1],entry->d_name);
       struct stat sobj;
       stat(name,&sobj);
       if(S_ISREG(sobj.st_mode))
       {
        printf("%s : Regular File\n",entry->d_name);
       } 
       if(S_ISREG(sobj.st_mode))
       {
        printf("%s : Regular File\n",entry->d_name);
       } 
       else if(S_ISDIR(sobj.st_mode))
       {
         printf("%s : Directory\n",entry->d_name);
       } 
       else if(S_ISBLK(sobj.st_mode))
       {
        printf("%s : Block Device\n",entry->d_name);
       } 
       else if(S_ISCHR(sobj.st_mode))
       {
        printf("%s : Character Device\n",entry->d_name);
       } 
       else if(S_ISSOCK(sobj.st_mode))
       {
        printf("%s : Socket\n",entry->d_name);
       } 
   }
   closedir(dp);

  return 0;
}
