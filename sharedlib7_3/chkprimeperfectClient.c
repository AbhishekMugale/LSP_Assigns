#include<stdio.h>
#include<stdbool.h>
#include<dlfcn.h>


int main(int argc,char *argv[])
{
   void *ptr1 = NULL;
   void *ptr2 = NULL;
   
   bool (*fptr1)(int);
   bool (*fptr2)(int);
   int Ret1 = 0,Ret2 = 0;
   ptr1 = dlopen("chkprime.so",RTLD_LAZY);
   if(ptr1 == NULL)
   {
       printf("Unable to load prime number library\n");
       return -1;
   }
   ptr2 = dlopen("chkperfect.so",RTLD_LAZY);
   if(ptr2 == NULL)
   {
       printf("Unable to load perfect number library\n");
       return -1;
   }
   
   fptr1 = dlsym(ptr1,"CheckPrime");
   if(fptr1 == NULL)
   {
      printf("Unable to load address of CheckPrime Function\n");
      return -1;
   }
   
   fptr2 = dlsym(ptr2,"CheckPerfect");
   if(fptr2 == NULL)
   {
      printf("Unable to load address of CheckPerfect Function\n");
      return -1;
   }
   
   Ret1 = fptr1(atoi(argv[1]));
   if(Ret1 == 1)
   {
      printf("%d is a prime number\n",atoi(argv[1]));
   }
   else
   {
      printf("%d is not a prime number\n",atoi(argv[1]));
   }
   Ret2 = fptr2(atoi(argv[2])); 
   if(Ret2 == 1)
   {
      printf("%d is a perfect number\n",atoi(argv[2]));
   }
   else
   {
      printf("%d is not a perfect number\n",atoi(argv[2]));
   }    
   
   
   return 0;
}
