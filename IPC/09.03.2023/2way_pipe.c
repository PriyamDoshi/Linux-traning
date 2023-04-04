#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>

int main (){

    int p1[2]; // c to p
    int p2[2]; // p to c
    if (pipe(p2) == -1){return 1;}
    if (pipe(p1) == -1){return 1;}
    int pid = fork();
    if (pid == 0){
        // in child process
        close(p1[0]);
        close(p2[1]);
        int x;
        read(p2[0], &x , sizeof(x));
        printf("number recived form parent process is %d\n",x);
        x *= x;
        printf("write in p[1] %d\n",x);
        write(p1[1], &x, sizeof(x));
        close(p1[1]);
        close(p2[0]);
    } else {
        // in parent process
        close(p1[1]);
        close(p2[0]);
        int y = rand()%20;
        write(p2[1], &y, sizeof(y));
        read(p1[0], &y, sizeof(y));
        printf("sq of random number is %d\n",y);
        wait(3);
    }
    return 0;
}