#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
   char DirName[20];
   char name[30];
   DIR *dp = NULL;
   struct dirent *entry = NULL;
   
   printf("Enter the Directory Name\n");
   scanf("%s",DirName);
   
   dp = opendir(DirName);
   
   if(dp == NULL)
   {
      printf("Unable to open the directory\n");
   }
   
   while((entry = readdir(dp)) != NULL)
   {
      sprintf(name,"%s/%s",DirName,entry->d_name);
      printf("%s\n",entry->d_name);
   }
   
   closedir(dp);

   return 0;
}
