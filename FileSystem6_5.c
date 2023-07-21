#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
  int fd = 0,i=0,j=0,removedata_size=0,filesize=0;
  
  long offset = 0;
  char Fname[20];
  struct stat sobj;
 
  printf("Enter the File name\n");
  scanf("%s",Fname);
  printf("Enter the offset\n");
  scanf("%ld",&offset);
  fd = open(Fname,O_RDWR);
  
  if(fd == -1)
   {
      printf("Unable to open the file\n");
      return -1;
   }
     
   stat(Fname,&sobj);
   lseek(fd,offset,SEEK_SET);
   filesize = sobj.st_size;
   removedata_size = filesize - offset;
    
   write(fd,"",removedata_size);
   
    j = filesize-removedata_size;
    i = ftruncate(fd,j);
  
   close(fd);
  return 0;
}
// ftruncate systemcall truncates the file to the size of data that was nor deleted,which removes garabage characters.
