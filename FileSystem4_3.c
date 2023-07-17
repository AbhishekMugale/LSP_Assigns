#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
int main(int argc,char *argv[])
{
   int Ret = 0,iCnt = 0;
   struct stat obj1,obj2;
   char Buffer1[100];
   char Buffer2[100];
   int fd1=0,fd2=0;
   
   if(argc != 3)
   {
      printf("Invalid NUmber of arguments\n");
      return -1;
   }
   
   fd1 = open(argv[1],O_RDONLY);
   fd2 = open(argv[2],O_RDONLY);
   
   if(fd1 == -1 || fd2 ==-1)
   {
     printf("Unable to open the file\n");
     return -1;
   }
   fstat(fd1,&obj1);
   fstat(fd2,&obj2);
   
   if(obj1.st_size != obj2.st_size)
   {
      printf("Both files are not same as their sizes are differnt\n");
      return -1;
   }
   while((Ret = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
   {
       printf("Iteration no : %d\n",iCnt);
        iCnt++;
       Ret = read(fd2,Buffer2,sizeof(Buffer2));
       
       if(memcmp(Buffer1,Buffer2,Ret) != 0)
       {
           break;
       }  
   }
   
   if(Ret == 0)
   {
       printf("Both files are identical\n");
   }
   else
   {
      printf("Both Files are not same\n");
   }
   return 0;
}

