#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;
pthread_cond_t cv;
int datos_listos = 0;

void *espera_datos(void *arg) {
    pthread_mutex_lock(&lock);

    while (datos_listos == 0) {
        pthread_cond_wait(&cv, &lock);
    }

    printf("¡Datos recibidos! Procesando...\n");
    
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *envia_datos(void *arg) {
    pthread_mutex_lock(&lock);
    
    datos_listos = 1; 
    printf("Datos generados. Enviando señal...\n");
    
    pthread_cond_signal(&cv); 
    
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cv, NULL);

    pthread_create(&t1, NULL, espera_datos, NULL);
    pthread_create(&t2, NULL, envia_datos, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cv);
    return 0;
}