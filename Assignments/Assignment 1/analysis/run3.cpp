#include "loop.h"

int run3(int n) {

  int sum = 0;
  
  for (int i=0 ; i < n/2 ; i++)
    for (int j=0 ; j < 2*n ; j++)
      sum++;
  
  return sum;
}
