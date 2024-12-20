#include "loop.h"

int run4(int n) {

   int sum = 0;

   for (int i = 1 ; i <= n ; i++ )
     for (int j = i-2; j <= i+1; j++)
     sum++;
   
   return sum;

}
