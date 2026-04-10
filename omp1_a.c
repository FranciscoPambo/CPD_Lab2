#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define NUMITER 30
int main(int argc, char *argv[]) {
  int i, tid;
  #pragma omp parallel private(i,tid)
  {
    tid = omp_get_thread_num();
    #pragma omp for
    for(i = 0; i < NUMITER; i++){
      printf("Thread: %d\titer=%d\n", tid, i);
      fflush(stdout);
    }
    printf("Thread %d, almost..\n", tid); fflush(stdout);
    printf("Thread %d, done!\n", tid);    fflush(stdout);
  }
  printf("All threads have finished!\n");
  return 0;
}
