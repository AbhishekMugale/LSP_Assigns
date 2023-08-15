#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/types.h>


int main()
{
    int fd = open("new1.txt",O_RDONLY,S_IRUSR | S_IWUSR);
    struct stat obj;
    
    if(fstat(fd,&obj) == -1)
    {
       printf("Couldn't get file size\n");
    }
    printf("File size is %ld bytes\n",obj.st_size);
    
    char *ptr = mmap(NULL,obj.st_size,PROT_READ,MAP_PRIVATE,fd,0);
    
    printf("Data read by using mapping is \n");
    for(int i=0;i<obj.st_size;i++)
    {
        printf("%c",ptr[i]);
    }
    printf("\n");
    
    munmap(ptr,obj.st_size);
    close(fd);
    return 0;
}

