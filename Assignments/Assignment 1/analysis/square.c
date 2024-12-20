/* program to computer n^2 recursively


   note:  this program lacks many descriptive elements, usually required by C/C++ Style Guides
 */

#include <stdio.h>

int readn () {
  int value;
  printf ("enter integer value n: "); scanf ("%d", &value);  return value;
}

int computeSquare (int n) {
  int result;  if (n == 1) result = 1; else result = 2*n - 1 + computeSquare (n-1); return result;}

int main ( ) {
  printf ("program to compute n sequared\n");
  int n = readn (); int answer = computeSquare (n); printf ("%d squared is %d\n", n, answer); return 0;}
  
