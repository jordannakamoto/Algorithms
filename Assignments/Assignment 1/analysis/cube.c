/* program to computer n^3 recursively

   notes:  
   * this program lacks many descriptive elements, usually required by C/C++ Style Guides

   * compile this program in a Terminal window with the line
          gcc -o cube cube.c
 */

#include <stdio.h>

int readn () {
  int value;
  printf ("enter integer value n: "); scanf ("%d", &value);  return value;
}

int computeCube (int n) {
  int result;  if (n == 1) result = 1; else result = computeCube (n-1) + 3*n*n - 3*n + 1; return result;}

int main ( ) {
  printf ("program to compute n cubed\n");
  int n = readn (); int answer = computeCube (n); printf ("%d cubed is %d\n", n, answer); return 0;}
  
