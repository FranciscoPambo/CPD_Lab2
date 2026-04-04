#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define TOTALSIZE 1000
#define NUMITER 200

#define f(x,y) ((x+y)/2.0)

int main(int argc, char *argv[]) {
  int i, iter;
  double *A = (double *) malloc(TOTALSIZE * sizeof(double));
  double *B = (double *) malloc(TOTALSIZE * sizeof(double));
  double *leitura, *escrita, *temp;

  for(i = 0; i < TOTALSIZE; i++) {
    A[i] = 0.0 + i;
  }

  leitura = A;
  escrita = B;

  for(iter = 0; iter < NUMITER; iter++) {

    #pragma omp parallel for
    for(i = 0; i < TOTALSIZE-1; i++) {
      escrita[i] = f(leitura[i], leitura[i+1]);
    }
    escrita[TOTALSIZE-1] = leitura[TOTALSIZE-1];

    /* Trocar ponteiros em vez de copiar */
    temp    = leitura;
    leitura = escrita;
    escrita = temp;
  }

  printf("Output:\n"); 
  for(i = 0; i < TOTALSIZE; i++) {
    printf("%4d %f\n", i, leitura[i]);
  }

  free(A);
  free(B);
}
