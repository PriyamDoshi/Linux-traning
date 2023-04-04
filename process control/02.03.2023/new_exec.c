#include<stdio.h>
#include<unistd.h>

int main (){
    printf("i am in new process and its pid is %d\n", getpid());
    printf("%d is sum of 2 and 10\n", (2+10));
    return 0;
}