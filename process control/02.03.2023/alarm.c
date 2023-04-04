#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
void sig_handlar(int s ){
    printf("we are in a function\n");
}

int main (){
    sig_handlar(SIGALRM);
    alarm(2);
    for (int i = 0;; i++){
        printf("%d",i);
        sleep(1);
    }
return 0;
}