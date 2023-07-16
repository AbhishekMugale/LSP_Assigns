#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
   struct stat sobj; 
   if(argc != 2)
   {
      printf("INvalid Number of arguments\n");
      return -1;
   }
   stat(argv[1],&sobj);
   printf("File name:%s\n",argv[1]);
   printf("File size:%d\n",sobj.st_size);
   printf("Number of links:%d\n",sobj.st_nlink);
   printf("Inode number : %d\n",sobj.st_ino);
   printf("File System Number: %d\n",sobj.st_dev);
   printf("NUmber of blocks: %d\n",sobj.st_blocks);
   
   return 0;
}
