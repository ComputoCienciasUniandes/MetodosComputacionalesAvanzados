#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846264338327

int main(int argc, char **argv){
  long n_points;
  double x, y, r;
  double gauss_1, gauss_2;
  long long i;
  
  n_points = atoi(argv[1]);

  srand48(n_points);
  for(i=0;i<n_points;i++){    
      x = drand48();
      y = drand48();
      gauss_1 = sqrt(-2.0 * log(x)) * cos(2.0* PI * y);
      gauss_2 = sqrt(-2.0 * log(x)) * sin(2.0* PI * y);
      if(gauss_1>5.0){
	printf("%f %f\n", gauss_1, gauss_2);
      }
  }
}
