/** ***************************************************************************
 * @remark   program to assign and print an array with values                 *
 *                                                                            *
 *  a[i] = i + 2*i + ... i*i  for 1 <= i <= n                                 *
 *                                                                            *
 *  program uses both iterative and recursive procedures,                     *
 *  to provide a context for efficiency analysis for both types               *
 *  of procedures.                                                            *
 *                                                                            *
 * @author Henry M. Walker                                                    *
 * @file  float-loop.c                                                        *
 * @date  January 24, 2022                                                    *
 *                                                                            *
 *****************************************************************************/
/**
*/

#include <stdio.h>

/* required computation done iterative in nested loops */
void iter_compute (int n, int a[])
{
  int i, j;
  for (i = 1; i <= n; i++)
    {
      a[i] = 0;
      for (j = 1; j <= i; j++)
        a[i] += i*j;
    }
}

/* required computation done recursively for n */
void rec_compute (int n, int a[])
{
  if (n > 0)
    {
      int j;
      a[n] = 0;
      for (j = 1; j <= n; j++)
        a[n] += n*j;
      rec_compute (n-1, a);
    }
}

/* print a given an array */
void print_array (int n, int a[])
{
  int i;
  for (i = 1; i <= n; i++)
    printf ("%5d", a[i]);
  printf ("\n");
}

int main ()
{
  /* prolog */
  printf ("program to compute and print array\n");
  printf ("  a[i] = i + 2*i + ... i*i  for 0 <= i <= n\n");

  /* determine array size */
  int n;
  printf ("enter n: ");
  scanf ("%d", &n);

  int a[n];

  /* iterative processing */
  iter_compute (n, a);
  printf ("result via iteration\n");
  print_array (n, a);

  /* recursive processing */
  rec_compute (n, a);
  printf ("result via recursion\n");
  print_array (n, a);

  return 0;
}
