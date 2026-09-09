#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char **argv){
    int N = atoi(argv[1]);
    int *A = malloc(sizeof(int)*N);
    long long int sum = 0;

    long long int vetor[32] = {0}; 

    for(int i=0; i<N; i++){
        A[i] = i;
    }

    // Cria threads para executarem o bloco a seguir
    // A carga de trabalho não é dividida adequadamente por padrão -> para isso, é necessário adicionar o 'for' após o 'parallel'
    // 'sum' precisa ser declarada como Privada para não haver Condição de Corrida
    // '#pragma omp parallel' + 'for' + 'private(sum)' 
    // #pragma omp parallel firstprivate(sum) // Precisamos colocar 'first' para não pegar 'lixo' da memória
    #pragma omp parallel
    {
        int sum_local = 0; // Agora cada thread possui seu 'sum' local
        #pragma omp for // Obtemos a soma privada de cada thread, pois precisamos entender por que o primeiro Sum foi igual a 0
        for(int i=0; i<N; i++){
            sum_local += A[i]; // Antes era 'sum', agora é 'sum_local'
        }
        printf("Thread %d, sum = %lld\n", omp_get_thread_num(), sum);

        //vetor[omp_get_thread_num()] = sum; // Agora a soma é igual a um vetor que está na memória compartilhada

        //#pragma omp critical // 'Crítico!' -> Uma thread acessa por vez; não há mais Condição de Corrida (executado por software, não por hardware, então é mais lento)
        //{
        #pragma omp atomic // Realiza a operação atõmica direto pelo hardware, então é mais rápido
            sum += sum_local;
        //}
        // (!) Códigos com 'atomic' e 'critical' reduzem o potencial de escalabilidade
    }

    //for(int i=0; i<32; i++)
    //    sum += vetor[i];

    printf("Sum = %lld\n", sum);

    return 0;
}

