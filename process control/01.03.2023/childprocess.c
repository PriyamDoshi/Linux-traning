#include<stdio.h>
#include<unistd.h>

int main (){
    int f = fork();
    fork();
    
    printf("hello world form id %d\n", f);
    if (f == 0){
        printf("hello form child process and id is %d\n", f);
    }else{
        printf("hello form parent process and process id is %d\n", f);
    }
   
}