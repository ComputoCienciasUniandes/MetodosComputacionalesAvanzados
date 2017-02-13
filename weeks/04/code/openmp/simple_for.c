#include <stdio.h>
#include "omp.h"

/*
  Basado en el tutorial:
  http://openmp.org/mp-documents/omp-hands-on-SC08.pdf
*/

void main (){ 
  int a[20];
  int id;
  int i;
  omp_set_num_threads(4);

#pragma omp parallel for
  for (i = 0 ; i < 20; i++){
    id = omp_get_thread_num();
    a[i] = id;
  }

  for (i = 0 ; i < 20; i++){
    printf("a[%d]=%d\n", i, a[i]);
  }
}

