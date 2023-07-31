#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



int main()
{

   char *homedir = getenv("HOME");
   char *usrname = getenv("USERNAME");
   
   printf("HOME : %s\n",homedir);
   printf("USERNAME : %s\n",usrname);
 
  return 0;
}
