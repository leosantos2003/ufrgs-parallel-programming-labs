#include <stdio.h>
#include <math.h>
#include <omp.h> // Lembrar de incluir a biblioteca do OpenMP


#define MAX_ITER 14000
#define chunk 1

#define pontoX 0.0
#define pontoY 0.0
#define ALTURA 768
#define LARGURA 1024


float mandelbrot(float oX, float oY, float pX, float pY, int iter){
    float eX, eY, dist;

    eX = (oX * oX) - (oY * oY) + pX;
    eY = (2 * oX * oY) + pY;

    if(iter >= MAX_ITER)
            return iter;

    dist = sqrtf((eX*eX) + (eY * eY));

    if(dist <= 2.00){
            return mandelbrot(eX, eY, pX, pY, ++iter);
    }

    return dist;

}

/*Função para converter o valor do pixel para o valor do plano complexo.*/
void convertePixel(int pX, int pY, float *x, float *y){
    int coordX0;
    int coordY0;
    float scaleX;
    float scaleY;

    coordX0 = (LARGURA/3.0) * 2.0;
    coordY0 = (ALTURA/2) * 1;

    scaleX = 3.0 / LARGURA;
    scaleY = 2.0 / ALTURA;

    *x = (pX * scaleX) - 2.0;

    if(pY > coordY0){
            *y = -1 + ((ALTURA - pY) * scaleY);
    }
    else{
            *y = ((pY - (ALTURA/2)) * scaleY);
    }
}

int main(int argc, char **argv){

    // variáveis estão na memória compartilhada do processo
    // se todas as threads da região paralela acessarem elas na memória compartilhada, haverá problemas de dependência e condição de corrida
    // as threads devem fazer uma cópia para sua própria memória privada
    float cX, cY;
    int x, y, iter;

    double time0 = omp_get_wtime(); // A partir daqui começa a contar o tempo

    // paralelilzar
    // #pragma omp parallel for
    #pragma omp parallel for private(y, cY, cX) // o 'x', por ser a primeira variável, é automaticamente já privada pela diretiva (só aceita, mas pode privar manualmente também pra garantir)
    for(x = 0; x < ALTURA; x++){
        for(y = 0; y < LARGURA; y++){
            convertePixel(y, x,&cY, &cX);
            iter = mandelbrot(pontoY, pontoX, cY, cX, 0);
    	}
    }

    double time1 = omp_get_wtime(); // Terminar de contar o tempo aqui
    printf("Tempo total = %.5lf segundos.\n", time1 - time0);

    return 0;

}
