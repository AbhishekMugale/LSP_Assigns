#include  "chkperfect.h"
#include<stdbool.h>

int CheckPerfect(int No)
{
   bool flag = false;
   int sum = 0;
   for(int i=1;i<=No/2;i++)
   {
       if(No % i == 0)
       {
          sum = sum+i;
       }
   }
   if(sum == No)
   {
      flag = true;
   }
  
   return flag; 
}


