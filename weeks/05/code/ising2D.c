#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN(x,y) x<y?x:y

int *init_lattice(int n_side);
double compute_energy(int *lattice, int n_side);
int random_between(int a, int b);
void get_neighbors(int *lattice, int n_side, int i, int *neigh);
double compute_magnetiza(int *lattice, int n_side);
int main(int argc, char ** argv){
  int *lattice;
  int neigh[4];
  int n_side;
  int i_flip=0;
  int i,j;
  double r;
  double delta_E;
  double T = 10.0;
  double beta = 1.0/T;
  double E;
  double M;
  double alpha;
  double h;
  int n_steps;


  n_side = atoi(argv[1]);
  lattice = init_lattice(n_side);
  E = compute_energy(lattice, n_side);
  M = compute_magnetiza(lattice, n_side);
  printf("%f %f\n", E, M);
  n_steps = n_side * n_side * 10;

  for(i=0;i<n_steps;i++){
    i_flip = random_between(0,n_side*n_side-1);
    get_neighbors(lattice, n_side, i_flip, neigh);
    
    h = 0.0;
    for(j=0;j<4;j++){
      h += lattice[neigh[j]];
    }
    delta_E = 2.0 * h * lattice[i_flip];

    r = MIN(1.0, exp(-beta * delta_E));
    alpha = drand48();
    if(alpha < r){
      lattice[i_flip] = -lattice[i_flip];
      E = E + delta_E;
    }    
    M = compute_magnetiza(lattice, n_side);
    printf("%f %f\n", E, M);
  }

  return 0;
}

int *init_lattice(int n_side){
  int *x;
  int i;
  if(!(x=malloc(sizeof(int) * n_side * n_side))){
    fprintf(stdout, "allocation problem\n");
    exit(1);
  }
  for(i=0;i<n_side*n_side;i++){
    x[i] = -1; 
  }
  return x;
}

double compute_magnetiza(int *lattice, int n_side){
  double M;
  int i, j;
  int index;
  M = 0.0;
  for(i=0;i<n_side;i++){
    for(j=0;j<n_side;j++){
      index = j + (n_side * i);
      M = M + lattice[index];
    }
  }
  return M;
}

double compute_energy(int *lattice, int n_side){
  double E;
  int i,j, down, right;
  int index, index_down, index_right;
  
  E = 0.0;
  for(i=0;i<n_side;i++){
    for(j=0;j<n_side;j++){
      down = (i+1)%n_side;
      right = (j+1)%n_side;

      index = j + (n_side * i);
      index_down = j + (n_side * down);
      index_right = right + (n_side * i);
       
      E += - lattice[index] * lattice[index_down];
      E += - lattice[index] * lattice[index_right];
    }
  }  
  return E;
}

int random_between(int a, int b){
  int i;
  if(b<a){
    fprintf(stderr,"b < a!\n");
  }
  
  i = a + (int)(drand48()*(b-a));
  return i;
}

void get_neighbors(int *lattice, int n_side, int index, int *neigh){
  int up, down, left, right;
  int i;
  int j;

  j = index%n_side;
  i = (index-j)/n_side;
  
  up = (i-1);if(up<0)up=n_side-up; 
  left = (j-1);if(left<0)left=n_side-left; 
  down = (i+1)%n_side;
  right = (j+1)%n_side;

  
  neigh[0] =  j + (n_side * up);
  neigh[1] =  j + (n_side * down);
  neigh[2] =  left + (n_side * i);
  neigh[3] =  right + (n_side * i);
}
