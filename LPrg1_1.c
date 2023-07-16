#include<stdio.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
  if(argc != 2)
  {
     printf("Invalid Number of arguments\n");
     return -1;
  }
  int fd = 0;
  fd = open(argv[1],O_RDONLY);
  if(fd == -1)
  {
     printf("Unable to open file\n");
     return -1;
  }
  else
  {
     printf("File is opened succesfully with file descriptor %d\n",fd);
  }

  return 0;
}
