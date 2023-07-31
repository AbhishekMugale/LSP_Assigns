#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
   int fd = 0,fd2 = 0,ret = 0,iCnt = 0,i=0;
   char buffer[100];
   fd = open("Demo.txt",O_RDONLY);
   if(fd == -1)
   {
      printf("Unable to open the file\n");
      return -1;
   }
   while((ret = read(fd,buffer,sizeof(buffer))) != 0)
   {
      for(i=0;i<ret;i++)
      {
         if(buffer[i]>='a' && buffer[i]<='z')
         {
            iCnt++;
         }
      }
   }
    
   fd2 = open("count.txt",O_RDWR | O_APPEND);
   if(fd2 == -1)
   {
      printf("Unable to open the file\n");
      return -1;
   }
   char buf[33]; 
   sprintf(buf,"%s %d\n","The total small characters are",iCnt); 
   write(fd2,buf,sizeof(buf));
   

   return 0;
}
