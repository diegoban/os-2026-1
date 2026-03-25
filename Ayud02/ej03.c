#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    pid_t t = fork();
    if(fork() || fork()){
        printf("PID=%d\n", getpid());
    }else{
        printf("Hola\n");
        exit(0);
    }
    return 0;
}