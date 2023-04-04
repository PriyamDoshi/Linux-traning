#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main (){
    pid_t p;
    int a;
    a = p = fork();
    if (p == 0){
        printf("we are in child process and its pid is %d and parent pid is %d\n", getpid(), getppid());
        printf(" int valude of pid is %d\n", a);
    
    }else {
        wait(NULL);
        sleep(3);
        printf("now we are in parent process and its pid is %d\n",getpid());
        printf("int value is %d\n", a);
    }
return 0;
}