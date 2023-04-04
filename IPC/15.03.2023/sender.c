#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main ()
{
int a, n;
a = open("myfifo",O_WRONLY);
write(a,"Massage",7);
printf("sender process PID is %d\n", getpid());
return 0;
}
