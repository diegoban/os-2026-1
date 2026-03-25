#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int num = 2;
    while(num && fork()){
        num = (num*2)/4;
        printf("%d\n", num);
    }
    printf("PID=%d\n", getpid());
}