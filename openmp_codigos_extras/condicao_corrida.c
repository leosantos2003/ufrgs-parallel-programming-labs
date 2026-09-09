#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long long counter = 0;
int NTHREADS=88;

void* worker(void* arg) {
        for (long i = 0; i < 1000; i++)
                counter++;
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