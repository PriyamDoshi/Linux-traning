#include<stdio.h>
#include<unistd.h>
int main (){
   int id = fork();
    if (id != 0 ){
        fork();
    }
    printf("hello world and id nimber is %d\n", id);
    return 0;
}