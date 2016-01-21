#include <stdio.h>

int main(void){
  float x,y,z, result;
  x = 1E8;
  y = 1E5;
  z = -1.0 - 1E5;

  result = x * y + x * z;
  printf("result a: %e\n", result);
  
  result = x * (y + z);
  printf("result b: %e\n", result);
  
  return 0;
}
