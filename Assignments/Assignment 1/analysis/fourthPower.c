/* program to computer n^4 recursively

   notes:  
   * this program lacks many descriptive elements, usually required by C/C++ Style Guides

   * compile this program in a Terminal window with the line
          gcc -o fourthPower fourthPower.c
 */

#include <stdio.h>

int readn () {
  int value;
  printf ("enter integer value n: "); scanf ("%d", &value);  return value;
}

int computeFourth (int n) {
  int result;  if (n == 1) result = 1; else result = computeFourth (n-1) + 4*n*n*n - 6*n*n + 4*n - 1; return result;}

int main ( ) {
  printf ("program to compute n to the fourth\n");
  int n = readn (); int answer = computeFourth (n); printf ("%d to the fourth is %d\n", n, answer); return 0;}
  
