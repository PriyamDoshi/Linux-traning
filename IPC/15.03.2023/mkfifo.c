#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main ()
{
int a;
a = mkfifo("myfifo", 0777);
printf("fifo file is created");
return 0;
}
