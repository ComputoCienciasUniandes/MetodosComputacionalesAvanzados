#include <stdio.h>

int main(void){
  unsigned int id;
  int min;
  float x;

  min = 1073741824;
  
  for (id=min;id<min+10;id++){
    x = (*(float*)&id);
    printf("%e\n", x);
  }

  return 0;
}
