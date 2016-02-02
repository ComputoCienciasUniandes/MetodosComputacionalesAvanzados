#include <stdio.h>
#include <stdlib.h>
void print_u(double *u, int n_points);
void initial_condition(double *u, int n_points, double delta_x);
void update_u(double *u_new, double *u_past, int n_points, 
	      double delta_x, double delta_t, double c);
void copy(double *u_new, double *u_past, int n_points);
int main(void){
  double *u_past;
  double *u_present;

  double delta_x=0.01;
  int n_x = (int)(10.0/delta_x);
  double delta_t = 1E-4;
  int n_t = (int)(2.0/delta_t);  
  double c = 1.0;
  int i;

  /*reserva memoria*/
  u_past = malloc(n_x * sizeof(double));
  u_present = malloc(n_x * sizeof(double));
  
  /*inicializacion*/
  initial_condition(u_past, n_x, delta_x);

  for(i=0;i<n_t;i++){
    update_u(u_present, u_past, n_x,delta_x, delta_t, c); 
    copy(u_present, u_past, n_x);
  }

  /*imprime en pantalla*/
  print_u(u_past, n_x);
  return 0;
}
void copy(double *u_new, double *u_past, int n_points){
  int i;
  for(i=0;i<n_points;i++){
    u_past[i] = u_new[i];
  }
}

void update_u(double *u_new, double *u_past, int n_points, 
	      double delta_x, double delta_t, double c){
  int j;
  for(j=1; j<(n_points-1);j++){
    u_new[j] = 
      u_past[j] 
      - c*delta_t/(delta_x) * (u_past[j] - u_past[j-1]);
  }  
}


void initial_condition(double *u, int n_points, double delta_x){
  int i;
  double x;
  for(i=0;i<n_points;i++){
    x = i*delta_x;
    if( x < 5.0){
      u[i] = 1.0;
    }else{
      u[i] = 0.0;
    }
  }
}

void print_u(double *u, int n_points){
  int i;
  for(i=0;i<n_points;i++){
    printf("%.5e\n", u[i]);
  }
}
