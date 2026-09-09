#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
volatile int stop = 0;

void* bully(void* arg) {
        long long hits = 0;
        while (!stop){
                pthread_mutex_lock(&m);
                hits++;
                pthread_mutex_unlock(&m);
        }
        printf("bully hits = %lld\n", hits);
        return NULL;
}

void* victim(void* arg) {
        long long hits = 0;
        while (!stop){
                pthread_mutex_lock(&m);
                hits++;
                pthread_mutex_unlock(&m);
                usleep(1000);
        }
        printf("victim hits = %lld\n", hits);
        return NULL;
}


int main() {
        pthread_t a,b;
        pthread_create(&a,NULL,bully,NULL);
        pthread_create(&b,NULL,victim,NULL);
        sleep(2);
        stop = 1;
        pthread_join(a,NULL);
        pthread_join(b,NULL);
        return 0;
}