#include <stdio.h>
#include "omp.h"

/*
  Basado en el tutorial:
  http://openmp.org/mp-documents/omp-hands-on-SC08.pdf
*/

void print_square(int n);
void main(){
  
  omp_set_num_threads(8);
#pragma omp parallel 
  {
    int id = omp_get_thread_num();
    print_square(id);
  }
}

void print_square(int n){
  printf("%d\n", n*n);
}
