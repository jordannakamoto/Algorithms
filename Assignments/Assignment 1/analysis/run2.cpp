#include "loop.h"

int run2(int n) {

  int sum = 0;

  for (int i=0 ; i < n ; i++)
    sum++;
  for (int j=0 ; j <= n ; j++)
    sum++;
  
  return sum;
}
