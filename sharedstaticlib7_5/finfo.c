#include "finfo.h"
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
void File_Info(char *str)
{
   struct stat sobj;
   stat(str,&sobj);
   
   printf("File name : %s\n",str);
   printf("File Size is : %ld\n",sobj.st_size);
   printf("Number of Links : %ld\n",sobj.st_nlink);
   printf("Inode number : %ld\n",sobj.st_ino);
   printf("File System number : %ld\n",sobj.st_dev);
   printf("Number of blocks : %ld\n",sobj.st_blocks);
}
