#include <stdio.h>

int main(void){
  int i=0;
  float x=1.0;
  float d=1.0E-2;

  while(x>0.0){
    x = x-d;
    i++;
  }
  printf("finished after %d iterations\n", i);
  
  return 0;
}
