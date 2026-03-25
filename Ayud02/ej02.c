#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    if(0 && fork()){
        printf("Soy el padre!!\n");
    }else{
        printf("Soy el hijo!!\n");
    }
    return 0;
}