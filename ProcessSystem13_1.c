// Server Application

#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main()
{
   int fd;
   char *myfifo = "/tmp/myfifo";
   
   printf("Named Pipe IPC\n");
   
   printf("Server is RUnning\n");
   
   mkfifo(myfifo,0666); // Created fifo(named pipe)
   
   fd = open(myfifo,O_WRONLY);
   write(fd,"Marvellous Info",strlen("Marvellous Info") +1);
   close(fd);
   
   printf("Data Succesfully written in named pipe\n");
   
   return 0; 

}
