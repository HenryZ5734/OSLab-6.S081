#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    int child;
    char buf[20];
    int fd1[2];
    int fd2[2];

    pipe(fd1);
    pipe(fd2);

    // parent
    if((child = fork()) != 0){
        close(fd1[0]);
        close(fd2[1]);
        write(fd1[1], "ping", 20);
        read(fd2[0], buf, 20);
        printf("%d: received %s\n", getpid(), buf);
    }
    // child
    else{
        close(fd2[0]);
        close(fd1[1]);
        read(fd1[0], buf, 20);
        printf("%d: received %s\n", getpid(), buf);
        write(fd2[1], "pong", 20);
    }

    wait(&child);
    exit(0);
}