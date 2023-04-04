#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main ()
{
int a,n;
char buffer[100];
a = open("myfifo", O_RDONLY);
n = read(a,buffer,100);
printf("data recived by receiver %d is : %s", getpid(), buffer);
return 0;
}

