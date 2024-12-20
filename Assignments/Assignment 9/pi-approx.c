/** ***************************************************************************
 * @remark approximate Pi adding n terms from an arithmetic series            * 
 *                                                                            *
 *   pi is the sum of terns Tn   for i = 0, 1, . . .                          *
 *      where t0 = T1 = 1 and Tn = 2nT(n-1)/(2(n-2))                          *
 *                                                                            *
 *     for 0 <= i <= numTerms, this sum is evaluated                          *
 *         from largest term to smallest, and                                 *   
 *         from smallest term to largest                                      *
 *                                                                            *
 * @author Henry M. Walker                                                    *
 * @file  pi-series.c                                                         *
 * @date  Summer, 2023                                                        *
 *                                                                            *
 * @remark References                                                         *
 * @remark Consequences of Data Representation on Programming                 *
  https://blue.cs.sonoma.edu/~hwalker/courses/415-sonoma.sp23/readings/data-rep-consequences.html
 * @remark Wikpedia article on Leibniz formula for π                         *
 *   combining terms pairwise from a Taylor's series
  https://en.wikipedia.org/wiki/Leibniz_formula_for_π
  * @remark Series that converge to π quickly                                 *
  https://math.stackexc.com/questions/14113/series-that-converge-to-pi-quickly
 *                                                                            *
 *****************************************************************************/

#include <stdio.h>

int main ( ) {
  printf ("approximating Pi, based on a Taylor series and algebra\n");

  double actualPi = 3.1415926535897932384626433;
  int numTerms;
  printf ("Enter number of terms: ");
  scanf ("%d", &numTerms);

  // Set up array for terms of series
  double  T[numTerms +1];
  T[0] = 2.0;
  
  T[1] = 2.0/3.0;
  int i;
  for (i = 2; i <= numTerms; i++) {
    T[i] = 2.0 * i * T[i-1] / (2.0 * (2.0*i+1.0));
  }

 //print table headers
  printf ("                                      approximation      actual value (to 15 places)      error\n\n");

  // adding terms with i from 0 to numTerms
  double sum = 0;
  for (i = 0 ; i < numTerms ; i++) {
    sum += T[i];
    }
  printf ("adding from i = 0 to i = %d:   %18.16lf", numTerms, sum); 
  printf (" %23.16lf", actualPi);
  printf (" %23.16lf\n", actualPi - sum);


  sum = 0;
  for (i = numTerms-1 ; i >= 0 ; i--) {
    sum += T[i];
    }
  printf ("adding from i = %d to i = 0:   %18.16lf", numTerms, sum); 
  printf (" %23.16lf", actualPi);
  printf (" %23.16lf\n\n", actualPi - sum);  
  
  return 0;
}