#include <stdio.h>
#include <omp.h>
int main()
{
    //omp_set_num_threads(10);
    printf("\n--- PARALLEL REGION 1 ---\n");

    #pragma omp parallel num_threads(5)
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        printf("Hello from thread %d/%d!\n", thread_id+1, num_threads);
    }

    printf("\n--- PARALLEL REGION 2 ---\n");

    #pragma omp parallel num_threads(9)
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        printf("Hello from thread %d/%d!\n", thread_id+1, num_threads);
    }

    // Fim da região paralela.
    return 0;
}
