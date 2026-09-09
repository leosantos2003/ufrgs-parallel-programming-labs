#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NTHREADS 4
pthread_barrier_t bar;

void* worker(void* arg) {
        long id = (long)arg;
        printf("t %ld fase 1\n", id);
        usleep(50000 * (id + 1));
        pthread_barrier_wait(&bar);
        printf("t %ld fase 2\n", id);
        return NULL;
}

int main() {
        pthread_t t[NTHREADS];
        pthread_barrier_init(&bar, NULL, NTHREADS);
        for (long i = 0; i < NTHREADS; i++)
                pthread_create(&t[i], NULL, worker, (void*)i);
        for (int i = 0; i < NTHREADS; i++)
                pthread_join(t[i], NULL);
        pthread_barrier_destroy(&bar);
        return 0;
}