#include "loop.h"

int run1(int n) {
  
  int sum = 0;

  for (int i=0 ; i < 6*n ; i+=3)
    sum++;

  return sum;
}