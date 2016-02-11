#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN(x,y) x<y?x:y

double func(double x);
int main(int argc, char ** argv){
  int i;
  int n;
  double x = 0.0;
  double x_prime = 0.0;
  double r, alpha;
  n = atoi(argv[1]);

  srand48(n);
  for(i=0;i<n;i++){
    x_prime = x + 0.1 * (drand48()-0.5);      
    r = MIN(1.0, func(x_prime)/func(x));
    alpha = drand48();      
    if(alpha < r){
      x = x_prime;
    }
    printf("%f\n", x);
  }

  return 0;
}

double func(double x){
return exp(-(x*x)/2.0);
}
