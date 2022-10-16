#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    // check parameters number
    if(argc != 2){
        exit(1);
    }

    int ticks = atoi(argv[1]);
    sleep(ticks);
    printf("(nothing happens for a little while)\n");
    exit(0);
}