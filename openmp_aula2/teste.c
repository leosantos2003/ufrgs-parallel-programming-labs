#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int c = 2;
    int *A = malloc(sizeof(int)*N);
    int *A_out = malloc(sizeof(int)*N);

    //preencher A
    for(int i=0; i<N; i++){
        A[i] = N-i;
    }

    //computacao
    #pragma omp parallel for schedule(static, 1)
    for(int i=0; i<N; i++){
        A_out[i] = A[i] * (c+i);
        printf("Thread %d -> A_out[%d]\n", omp_get_thread_num(), i);
    }

    //saida
    for(int i=0; i<N; i++){
        printf("A_out[%d] = %d\n", i, A_out[i]);
    }

    free(A_out);
    free(A);
    return 0;
}
