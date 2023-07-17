#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#pragma pack(1)
struct Student
{
    int Roll_no;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc,char *argv[])
{
   
   struct Student sobj;
   int fd = 0;
   
   fd = open(argv[1],O_RDWR);
   
   read(fd,&sobj,sizeof(sobj));
   
   printf("Roll No : %d \n",sobj.Roll_no);
   printf("Student Name : %s \n",sobj.Sname);
   printf("Marks : %f \n",sobj.Marks);
   printf("Age : %d \n",sobj.Age);
     

  return 0;
}

