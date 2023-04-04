#include<stdio.h>
#include<unistd.h>
#include<time.h>

int main (){
    int f = fork();
    if (f == 0){
        printf(" from child process\n");
        for(int i = 1 ; i < 6; i++){
        printf("%d\n",i);
        }
    }else{
        wait();
       for(int i = 6; i < 11; i++){
        printf("%d\n",i);
        }
    }
    return 0;
}