#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long long counter = 0;
int NTHREADS=88;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;


void* worker(void* arg) {
        for (long i = 0; i < 1000; i++){
                pthread_mutex_lock(&m);
                counter++;
                pthread_mutex_unlock(&m);
        }
        return NULL;
}

int main() {
        pthread_t t[NTHREADS];
        for(int i = 0; i < NTHREADS; i++)
                pthread_create(&t[i], NULL, worker, NULL);
        for(int i = 0; i < NTHREADS; i++)
                pthread_join(t[i], NULL);
        printf("counter = %lld (esperado %lld)", counter, (long long)NTHREADS * 1000);
        return 0;
}