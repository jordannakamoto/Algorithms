/** ***************************************************************************
 * @remark  After reading a double x and non-negative integer n               *
 *  program assigns and prints an array with values                           *
 *                                                                            *
 *  a[i] = x^i  for 1 <= i <= n                                               *
 *                                                                            *
 *  program uses both iterative and recursive procedures,                     *
 *  to provide a context for efficiency analysis for both types               *
 *  of procedures.                                                            *
 *                                                                            *
 * @author Henry M. Walker                                                    *
 * @file simple-loop-analysis-2.c                                             *
 * @date Summer, 2023                                                         *
 *                                                                            *
 *****************************************************************************/
/**
*/

#include <stdio.h>

/* required computation done iterative in nested loops */
void iter_compute (double x, int n, double a[ ])
{
   int i, j;
   for (i = 1; i <= n; i++) {
       a[i] = 1;
       for (j = 1; j <= i; j++) {
          a[i] *= x;
       }
    }
}

/* required computation done recursively for n */
void rec_compute (double x, int n, double a[ ])
{
   a[n] = 1;
   if (n > 0) {
      a[n] = 1;
      for (int j = 1; j <= n; j++) {
         a[n] *= x;
      }
      rec_compute (x, n-1, a);
   }
}

/* print a given an array */
void print_array (int n, double a[])
{
  int i;
  for (i = 0; i <= n; i++)
    printf ("%7.1lf ", a[i]);
  printf ("\n");
}

int main ()
{
  /* prolog */
  printf ("program to compute and print array\n");
  printf ("  a[i] = x^i  for 0 <= i <= n\n");
  printf ("  given a value of real number x\n");

  /* determine array size */
  int n;
  double x;
  printf ("enter double x and non-negative integer n: ");
  scanf ("%lf %d", &x, &n);

  double r[n], s[n];

  /* iterative processing */
  iter_compute (x, n, r);
  printf ("result via iteration\n");
  print_array (n, r);

  /* recursive processing */
  rec_compute (x, n, s);
  printf ("result via recursion\n");
  print_array (n, s);

  return 0;
}
