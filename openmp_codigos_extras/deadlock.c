#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t A = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t B = PTHREAD_MUTEX_INITIALIZER;

void* t1(void* arg) {
        pthread_mutex_lock(&A);
        usleep(1000);
        pthread_mutex_lock(&B);
        printf("t1 entrou");
        pthread_mutex_unlock(&B);
        pthread_mutex_unlock(&A);
}

void* t2(void* arg) {
        pthread_mutex_lock(&B);
        usleep(1000);
        pthread_mutex_lock(&A);
        printf("t2 entrou");
        pthread_mutex_unlock(&A);
        pthread_mutex_unlock(&B);
}

int main() {
        pthread_t x,y;
        pthread_create(&x,NULL,t1,NULL);
        pthread_create(&y,NULL,t2,NULL);
        pthread_join(x,NULL);
        pthread_join(y,NULL);
        return 0;
}