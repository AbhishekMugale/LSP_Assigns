#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
   void *ptr1 = NULL;
   int (*fptr1)(int,int);
   int (*fptr2)(int,int);
   int (*fptr3)(int,int);
   float (*fptr4)(float,float);
   int Ret = 0;
   float fRet = 0.0;
   ptr1 = dlopen("ASMDlib.so",RTLD_LAZY);
   
   if(ptr1 == NULL)
   {
      printf("Unable to open the library\n");
      return -1;
   }
   fptr1 = dlsym(ptr1,"Addition");
   if(fptr1 == NULL)
   {
      printf("Unable to load the address of addition function\n");
      return -1;
   }
   Ret = fptr1(10,11);
   printf("Addition of two parameters is :%d\n",Ret);
   
   fptr2 = dlsym(ptr1,"Substraction");
   if(fptr2 == NULL)
   {
      printf("Unable to load the address of substraction function\n");
      return -1;
   }
   Ret = fptr2(22,11);
   printf("Subastraction of two parameters is :%d\n",Ret);

   fptr3 = dlsym(ptr1,"Multiplication");
   if(fptr3 == NULL)
   {
      printf("Unable to load the address of Multiplication function\n");
      return -1;
   }
   Ret = fptr3(10,11);
   printf("Multiplication of two parameters is :%d\n",Ret);

   fptr4 = dlsym(ptr1,"Division");
   if(fptr4 == NULL)
   {
      printf("Unable to load the address of Division function\n");
      return -1;
   }
   fRet = fptr1(22,11);
   printf("Division of two parameters is :%f\n",fRet);

   return 0;
}
