#include <stdio.h>
#include <math.h>

int main(void){
  float x, y;

  x = 1.0E-8;

  y = 1 - cos(x);
  printf("result a) %e\n", y);

  y = (sin(x)*sin(x))/(1.0 + cos(x));
  printf("result b) %e\n",y);
  return 0;
}
