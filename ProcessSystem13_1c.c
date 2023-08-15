// Client Application

#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#define MAX_BUF 1024
int main()
{
   int fd;
   char *myfifo = "/tmp/myfifo";
   char buf[MAX_BUF];
   
   printf("Named Pipe IPC\n");
   
   printf("Client is Running\n");
   
   
   
   fd = open(myfifo,O_RDONLY);
   read(fd,buf,MAX_BUF);
   printf("Received data is : %s\n",buf);
   close(fd);
   
   
   return 0; 

}
