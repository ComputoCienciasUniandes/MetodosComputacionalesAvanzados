#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double new_value(double x, double size);
void load_data(char *filein, double *x, double *y, int n_points);
int count_points(char *filein);
double * init_array(int n_points);
void print_array(double *x, int n_points);
void model(double A, double B, double *x_in, double *y_model, int n);
double loglikelihood(double *y_obs, double *y_model, int n);
#define MIN(x,y) x<y?x:y

int main(int argc, char **argv){
  int n_points= 0;
  double *x;
  double *y;
  double *y_model;
  int n_steps = 10000;
  double *A;
  double *B;
  double *loglike;
  double loglike_prime;
  double loglike_here;
  double alpha;
  double r;
  int i;

  n_points = count_lines(argv[1]);
  fprintf(stdout, "File %s has %d lines\n", argv[1], n_points);


  x = init_array(n_points);
  y = init_array(n_points);  
  y_model = init_array(n_points);  
  load_data(argv[1], x, y, n_points);

  /*initialize chains*/
  A = init_array(n_steps);
  B = init_array(n_steps);
  loglike = init_array(n_steps);

  /*first step*/
  A[0] = 10.0;
  B[0] = 10.0;
  model(A[0], B[0], x, y_model, n_points);
  loglike[0] = loglikelihood(y, y_model, n_points);

  for(i=1;i<n_steps;i++){
    A[i] = new_value(A[i-1], 0.1);
    B[i] = new_value(B[i-1], 0.1);
    model(A[i], B[i], x, y_model, n_points);
    loglike[i] = loglikelihood(y, y_model, n_points);    

    r = MIN(1.0, exp(loglike[i] - loglike[i-1]));
    alpha = drand48();      
    if(alpha < r){
      A[i] = A[i];
      B[i] = B[i];
    }else{
      A[i] = A[i-1];
      B[i] = B[i-1];
    }

    fprintf(stdout, "%f %f %f\n", A[i], B[i], loglike[i]);
  }

  return 0;
}

double new_value(double x, double size){
  double y;
  y = x  + (drand48()-0.5) * size;
  do{
    y = x  + (drand48()-0.5) * size;
  }while(y<0);
  return y;
}
void model(double A, double B, double *x_in, double *y_model, int n){
  int i;
  for(i=0;i<n;i++){
    y_model[i] = A * exp( -(x_in[i] * x_in[i])/(2.0 * pow(B,2)));
  }
}

double loglikelihood(double *y_obs, double *y_model, int n){
  double loglike=0;
  int i;

  for(i=0;i<n;i++){
    loglike += pow(y_obs[i] - y_model[i], 2.0)/2.0;
  }
  loglike = -loglike;
  return loglike;
}

double * init_array(int n_points){
  int i;
  double *x;
  if(!(x=malloc(sizeof(double) * n_points))){
    fprintf(stderr,"problem with malloc\n");
    exit(1);
  }
  for(i=0;i<n_points;i++){
    x[i] = 0.0;
  }
  return x;
}

int count_lines(char *filein){
  FILE *in;
  int n,c;
  int i;
  if(!(in=fopen(filein, "r"))){
    fprintf(stderr,"problem opening file %s\n", filein);
    exit(1);
  }

  /*count lines*/
  n=0;
  do{
    c = fgetc(in);
    if(c=='\n'){
      n++;
    }
  }while(c!=EOF);
  fclose(in);
  return n;
}


void load_data(char *filein, double *x, double *y, int n_points){
  FILE *in;
  int n,c;
  int i;
  if(!(in=fopen(filein, "r"))){
    fprintf(stderr,"problem opening file %s\n", filein);
    exit(1);
  }  
  for(i=0;i<n;i++){
    fscanf(in, "%lf %lf\n", &(x[i]), &(y[i]));
  }
  fclose(in);
}

void print_array(double *x, int n_points){
  int i;
  for(i=0;i<n_points;i++){
    fprintf(stdout, "%f\n", x[i]);
  }
}
