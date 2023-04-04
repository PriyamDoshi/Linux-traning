#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


int main (){
    if(mkfifo("myfifo1", 0777) == -1){
        if(errno != EEXIST){
            printf("Could not creat fifo file\n");
            return 1;
        }
    }
    printf("opening...\n");
    int fd = open("myfifo1", O_WRONLY);
    printf("opened\n");
    int x = 100;
    write(fd, &x, sizeof(x));
    printf("writen\n");
    close(fd);
    printf("closed\n");
    return 0;
}
// there is property of fifo in which we have to do read the fifo file simunteniusly... so we have to use cat function in another terminal
// we can use O_RDWR... 