#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

#define PI 3.141592653589793
#define FLOAT double
#define BETA 1.0

void initialize(FLOAT *x, FLOAT *v, int N);
FLOAT F(FLOAT x, FLOAT x_before, FLOAT x_after);
FLOAT energy(FLOAT *x, FLOAT *v, int m, int k);

int main(int argc, char **argv){
  FLOAT delta_t  = 5E-3; 
  int N = 64;
  FLOAT T = 5.0 * pow(N,2.2);
  int N_T = T/delta_t;  
  FLOAT E_k_1 = 0.0;
  FLOAT E_k_2 = 0.0;
  FLOAT E_k_3 = 0.0;
  FLOAT* x = malloc(N * sizeof(FLOAT));
  FLOAT* v = malloc(N * sizeof(FLOAT));
  int t;
  int n;
  int n_proc;
  FLOAT F_x;

  n_proc = atoi(argv[1]);
  initialize(x, v, N);

  omp_set_num_threads(n_proc);
  
  for(t = 0; t < N_T; t++){

#pragma omp parallel for shared(v,x) private(F_x)
    for(n = 1; n < N-1; n++){
      F_x = F(x[n], x[n-1], x[n+1]);
      v[n] += F_x * delta_t * 0.5;
    }

#pragma omp parallel for shared(v,x)    
    for(n = 1; n < N-1; n++){
      x[n] += v[n] * delta_t;
    }	

#pragma omp parallel for shared(v,x) private(F_x)
    for(n = 1; n < N-1; n++){
      F_x = F(x[n], x[n-1], x[n+1]);
      v[n] += F_x * delta_t * 0.5;
    }
    
    if(!(t%(N_T/1000))){
      E_k_1 = energy(x, v, N, 1);
      E_k_2 = energy(x, v, N, 2);
      E_k_3 = energy(x, v, N, 3);      
      printf("%d %e %e %e\n", t, E_k_1, E_k_2, E_k_3);
    }
  }  
  return(0);
}

void initialize(FLOAT *x, FLOAT *v, int m){ 
  int i;
  for(i=0; i<m; i++){
    x[i] = sin(1.0*PI*(i)/(FLOAT)(m-1));
    v[i] = 0.0;
  }
}

FLOAT F(FLOAT x, FLOAT x_before, FLOAT x_after){
  FLOAT F_value;
  F_value = (x_after - 2.0 * x + x_before);
  F_value += BETA * (x_after- x) * (x_after - x);
  F_value -= BETA * (x-x_before) * (x-x_before);
  return F_value;
}

FLOAT energy(FLOAT *x, FLOAT *v, int m, int k){
  int i;
  FLOAT A_k, A_k_dot, omega_k_2, E_k;

  A_k = 0.0;
  for(i=0;i<m ;i++){
    A_k += sqrt(2.0/(m+1)) * x[i] * sin(1.0 * (i) * k * PI /(m));
  }


  A_k_dot = 0.0;
  for(i=0;i<m ;i++){
    A_k_dot += sqrt(2.0/(m+1)) * v[i] * sin(1.0 * (i) * k * PI /(m));
  }

  omega_k_2 = 4.0* pow(sin(1.0 * k * PI / (2.0*(m))), 2.0);

  E_k = 0.5 * (A_k_dot * A_k_dot + omega_k_2 * A_k * A_k);
  return E_k;
}
