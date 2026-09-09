#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define NTHREADS 6
sem_t sem;

void* worker(void* arg) {
        long id = (long)arg;
        sem_wait(&sem);
        printf("thread %ld entrou\n", id);
        usleep(200000);
        printf("thread %ld saiu\n", id);
        sem_post(&sem);
        return NULL;
}

int main() {
        pthread_t t[NTHREADS];
        sem_init(&sem, 0, 2);
        for (long i = 0; i < NTHREADS; i++)
                pthread_create(&t[i], NULL, worker, (void*)i);
         for (int i = 0; i < NTHREADS; i++)
                pthread_join(t[i], NULL);
        sem_destroy(&sem);
        return 0;
}