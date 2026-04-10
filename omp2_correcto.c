#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define TOTALSIZE 1000
#define NUMITER 200
#define f(x,y) ((x+y)/2.0)
int main(int argc, char *argv[]) {
  int i, iter;
  double *V     = (double *) malloc(TOTALSIZE * sizeof(double));
  double *Vcopy = (double *) malloc(TOTALSIZE * sizeof(double));
  for(i = 0; i < TOTALSIZE; i++) V[i] = 0.0 + i;
  for(iter = 0; iter < NUMITER; iter++) {
    for(i = 0; i < TOTALSIZE; i++) Vcopy[i] = V[i];
    #pragma omp parallel for
    for(i = 0; i < TOTALSIZE-1; i++)
      V[i] = f(Vcopy[i], Vcopy[i+1]);
  }
  printf("Output:\n");
  for(i = 0; i < TOTALSIZE; i++) printf("%4d %f\n", i, V[i]);
  free(V); free(Vcopy);
  return 0;
}
