#include<stdio.h>
#include<fcntl.h>
#include<stdbool.h>
int main(int argc,char *argv[])
{
   bool result = 0;
   int mode = 0;
   if(argc != 2)
   {
      printf("Invalid number of arguments\n");
      return -1;
   }
   
   result = access(argv[1],R_OK);
   if(result == 0)
   {
      printf("The file can be accessed by process in read mode \n");
   } 
   else
   {
      printf("The file can't be accessed in read mode \n");
   }
   
    
   return 0;
}
