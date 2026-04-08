#include <stdio.h>
#include <pthread.h>

int saldo = 500; 

void* hacer_deposito(void* arg) {
    for(int i = 0; i < 100000; i++) {
        saldo = saldo + 100; 
    }
    return NULL;
}

int main() {
    pthread_t hilo1, hilo2;

    pthread_create(&hilo1, NULL, hacer_deposito, NULL);
    pthread_create(&hilo2, NULL, hacer_deposito, NULL);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    printf("Saldo final esperado: 20000500\n");
    printf("Saldo final real: %d\n", saldo); 

    return 0;
}