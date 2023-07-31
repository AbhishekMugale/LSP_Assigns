#include "chkprime.h"
#include<stdbool.h>

int CheckPrime(int No)
{
   bool flag = true;
   for(int i=2;i<=No/2;i++)
   {
      if(No % i == 0)
      {
         flag = false;
         break;
      }
   }
   return flag;
}
