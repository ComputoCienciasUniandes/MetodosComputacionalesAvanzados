#include <stdio.h>
#include "omp.h"

/*
  Basado en el tutorial:
  http://openmp.org/mp-documents/omp-hands-on-SC08.pdf
*/

void main(){
#pragma omp parallel 
  {
    printf("Hola Mundo\n");
  }
}
