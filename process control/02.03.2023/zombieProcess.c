#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main (){
    pid_t p;
    p = fork();
    if (p == 0){
        printf("it is a child process and pricess id is %d",getpid());\
        printf("parent pid is %d", getppid() );
    }else {
        printf("")
    }
}