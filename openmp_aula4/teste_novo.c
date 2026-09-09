#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char **argv){
    int N = atoi(argv[1]);
    int *A = malloc(sizeof(int)*N);
    long long int sum = 0;

    for(int i=0; i<N; i++){
        A[i] = i;
    }

    #pragma omp parallel for reduction(+:sum) // Soma os valores de 'sum' entre threads como nodos de uma árvore, mas de forma paralelizada
    for(int i=0; i<N; i++){
        sum += A[i]; 
    }

    printf("Sum = %lld\n", sum);

    return 0;
}
