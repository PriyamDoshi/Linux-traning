#include<stdio.h>
#include<unistd.h>

int main (){
    int f =fork();
    if ( f == 0){
        fork();
    }
    printf("hello world and id is %d\n",f);
    return 0;
}