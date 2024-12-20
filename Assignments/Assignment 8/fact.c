/** ***************************************************************************
 * @remark program to determine integer overflow for factorials               *
 *                                                                            *
 * @author Henry M. Walker                                                    *
 * @file  factorial.c                                                         *
 * @date  July 22, 2022                                                       *
 *                                                                            *
 * @remark Reference                                                          *
 * @remark Consequences of Data Representation on Programming                 *
  https://blue.cs.sonoma.edu/~hwalker/courses/415-sonoma.sp23/readings/data-rep-consequences.html
 *                                                                            *
 *****************************************************************************/

// C(n,k) = n! / [k! (n-k)!]

#include <stdio.h>

int main ( ) {
  printf ("program to determine integer overflow for factorials\n");

  long int i = 1;
  long int fact = 1;
  printf ("  i   factorial\n");

  printf ("%3ld  %20ld\n", i, fact);

  while (fact > 0) {
    i++;
    fact *= i;
    printf ("%3ld  %20ld\n", i, fact);
  }

  printf ("loop ended with %ld factorial = %ld\n", i, fact);

  return 0;
}