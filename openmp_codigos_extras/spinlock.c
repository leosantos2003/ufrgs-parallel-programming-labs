#include <pthread.h>
#include <stdio.h>

#define NTHREADS 4
#define ITERS 1000000
long long counter = 0;
pthread_spinlock_t s;

void* worker(void* arg) {
        for (long i = 0; i < ITERS; i++) {
                pthread_spin_lock(&s);
                counter++;
                pthread_spin_unlock(&s);
        }
        return NULL;
}

int main() {
        pthread_t t[NTHREADS];
        pthread_spin_init(&s, PTHREAD_PROCESS_PRIVATE);
        for (int i = 0; i < NTHREADS; i++)
                pthread_create(&t[i], NULL, worker, NULL);
        for (int i = 0; i < NTHREADS; i++) pthread_join(t[i], NULL);
                pthread_spin_destroy(&s);
         printf("counter = %lld\n", counter);
         return 0;
}