aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ gcc teste.c -o teste

aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ ./teste 100

Sum = 4950

-----------------

aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ gcc teste.c -o teste -fopenmp

aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ export OMP_NUM_THREADS=4

aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ ./teste 100

Sum = 0

-----------------

aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ gcc teste.c -o teste -fopenmp

aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ ./teste 100

Thread 2, sum = 138982813857294

Thread 0, sum = 140737112812236

Thread 3, sum = 138982805465215

Thread 1, sum = 138982822249373

Sum = 0

------------------

aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ gcc teste.c -o teste -fopenmp

aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ ./teste 100

Thread 3, sum = 2175

Thread 2, sum = 1550

Thread 0, sum = 300

Thread 1, sum = 925

Sum = 0

------------------

aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ gcc teste.c -o teste -fopenmp

aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ ./teste 100

Thread 0, sum = 300

Thread 3, sum = 2175

Thread 1, sum = 925

Thread 2, sum = 1550

Sum = 4950

------------------

aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ gcc teste_novo.c -o teste_novo -fopenmp

aluno@s-67-101-30:~/programacao_paralela/openmp_aula4$ ./teste_novo 100

Sum = 4950