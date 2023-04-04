#include<stdio.h>
#include<unistd.h>

int main(){
    int fd[2];
    // fd[0] = for read and fd[1] = for write.
    pipe(fd);
    if (pipe(fd) == -1){
        printf(" error to open the pipe\n");
        return 1;
    }
    
    int id = fork();
    if ( id == 0){
        close(fd[0]);
        printf("inter a number ");
        int x;
        scanf("%d",&x);
        write(fd[1],&x,sizeof(int));
        close(fd[1]);
    }else{
        close(fd[1]);
        int y;
        read(fd[0], &y, sizeof(int));
        close(fd[0]);
        printf("form child process to parent process %d\n",y);
    }

    return 0;

}