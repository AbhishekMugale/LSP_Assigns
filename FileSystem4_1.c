#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
   int iNo1 = 0,iNo2=0;
   int iAns = 0;
   
   scanf("%d",&iNo1);
   scanf("%d",&iNo2);
   iAns = iNo2 - iNo1;
   printf("Substraction is : %d\n",iAns);
   return 0;  
 
}


// ./FileSystem4_1 > Output.txt < Input.txt 2> Error.txt

