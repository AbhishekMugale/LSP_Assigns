// Client Application

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<sys/msg.h>
#include<stdlib.h>

struct my_msg_st
{
   long int my_msg_type;
   char some_text[BUFSIZ];
};

int main()
{
   printf("Client Process is Running");
   
   int running = 1;
   int msgid;
   struct my_msg_st some_data;
   long int msg_to_receive = 0;
   
   msgid = msgget((key_t)1234,0666 | IPC_CREAT);
   
   printf("Fetching the messaages from message queue\n");
   
   while(running)
   {
     msgrcv(msgid,(void *)&some_data,BUFSIZ,msg_to_receive,0);
     printf("Received Message %s : ",some_data.some_text);
     if(strncmp(some_data.some_text,"end",3) == 0)
     {
        running = 0;
     }
   }
   
   printf("Terminating the client process\n");
   
   exit(EXIT_SUCCESS);


}

