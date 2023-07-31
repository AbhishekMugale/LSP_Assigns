#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<fcntl.h>

int main()
{
   void *ptr = NULL;
   void (*fptr)(int,int);
   char Fname1[20],Fname2[20];
   int fd1=0,fd2=0;
   ptr = dlopen("fcompare.so",RTLD_LAZY);
   
   if(ptr == NULL)
   {
      printf("Unable to load library\n");
      return -1;
   }
   
   fptr = dlsym(ptr,"FileCompare");
   
   if(fptr == NULL)
   {
      printf("Unable to load address of function\n");
   }
   fd1 = open("Input.txt",O_RDONLY);
   fd2 = open("Output.txt",O_RDONLY);
   
   if(fd1 == -1 || fd2 == -1)
   {
      printf("Unable to open the file \n");
      return -1;
   }
   
   fptr(fd1,fd2);

   return 0;
}
 
