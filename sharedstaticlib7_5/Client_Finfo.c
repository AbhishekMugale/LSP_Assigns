#include "finfo.h"
#include<stdio.h>
int main()
{
   char Fname[20] = {'\0'};
   printf("ENter the file name u want to get info about and it should be from the same folder\n");
   scanf("%s",Fname);
   
   File_Info(Fname); 
    
   return 0;
}
