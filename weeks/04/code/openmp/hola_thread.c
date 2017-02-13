#include <stdio.h>
#include "omp.h"

/*
  Basado en el tutorial:
  http://openmp.org/mp-documents/omp-hands-on-SC08.pdf
*/

void main(){
#pragma omp parallel 
  {
    int id = omp_get_thread_num();
    printf("Hola Mundo (%d)\n", id);
  }
}
