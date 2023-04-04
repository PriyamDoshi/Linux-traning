#include<stdio.h>
#include<unistd.h>
int main (){
    printf("i am in demo.c and its prosess id is %d\n", getpid());
    char *a[] = {"./new_exec",NULL};
    execv(a[0],a);
    printf("in demo file\n");
    return 0;
}