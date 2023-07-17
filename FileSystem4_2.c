#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/dir.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
   int status;
   if(argc != 2)
   {
      printf("Invalid Arguments\n");
      return -1;
   }
   status = mkdir(argv[1],S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
   
   if(status==0)
   {
      printf("Directory is created succesfully\n");
   }
   else
   {
      printf("Unable to create the directory\n");
   }
   

  return 0;
}
