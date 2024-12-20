#include "loop.h"

int run5(int n) {

   int sum = 0;

   for (int i = 1 ; i <= n * n ; i++ )
     for (int j = 1; j <= i; j++)
     sum++;
   
   return sum;
 }
