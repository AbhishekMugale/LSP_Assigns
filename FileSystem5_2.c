#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#pragma pack(1)
struct Employee
{
    int Emp_id;
    char Ename[20];
    float Salary;
    int Age;
};

int main(int argc,char *argv[])
{
   
   struct Employee eobj;
   char Fname[20];
   int fd = 0;
   
  
   printf("ENter the filename : \n");
   scanf("%s",Fname);
   
   fd = open(Fname,O_RDONLY);
   
   read(fd,&eobj,sizeof(eobj));
   
   printf("Employee ID : %d \n",eobj.Emp_id);
   printf("Employee Name : %s \n",eobj.Ename);
   printf("Salary : %f \n",eobj.Salary);
   printf("Age : %d \n",eobj.Age);
     

  return 0;
}

