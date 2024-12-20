/** ***************************************************************************
 * @remark program to compute and print averages of values in an array,       *
 *    illustrating quite results from two closely-related data sets           *
 *                                                                            *
 * @author Henry M. Walker                                                    *
 * @file  integer-average.c                                                   *
 * @date  July 22, 2022                                                       *
 *                                                                            *
 * @remark Reference                                                          *
 * @remark Consequences of Data Representation on Programming                 *
  https://blue.cs.sonoma.edu/~hwalker/courses/415-sonoma.sp23/readings/data-rep-consequences.html
 *                                                                            *
 *****************************************************************************/

#include<stdio.h>
#include <limits.h>

/** ***************************************************************************
 * compute and print the average of the elements in an array                  *
 * @param  arr    the array to be printed                                     *
 * @param  size   the length of the array                                     *
 *                                                                            *
 * @remark  array elements are printed during processing                      *
 * @remark  average is computing by adding all elements                       *
 *     and dividing by the array size                                         *
 * @remark  both integer and double forms of the average are computed         *
 ******************************************************************************/
void compute_average (int arr [], int size) {
  printf ("array elements: ");
  int i;
  int sum = 0;
  for (i= 0; i < size; i++) {
    printf ("%12d", arr[i]);
    sum += arr[i];
  }                     
  printf ("\n");
  
  printf ("sum of elements:     %d\n", sum);

  // compute averages as an integer and double 
  int iavg = sum / size;
  double davg = ((double) sum) / ((double) size);

  printf ("average as integer:  %d\n", iavg);
  printf ("average as double:   %lf\n", davg);                                         
}

/** ***************************************************************************
 * main procedure controls array initialization, computation, and printing    *
 *****************************************************************************/
int main () {
  // declare arrays of integers
  const int array_size = 10;
  int arr1 [array_size];
  int arr2 [array_size];

  printf ("program to compute averages, with several values\n");
  printf (" range of ints:  %d to %d\n", INT_MIN, INT_MAX);

  // find average of first array of values
  int arr_value = (INT_MAX / 10);
  int i;
  for (i= 0; i < array_size; i++) {
    arr1[i] = arr_value;
  }
  compute_average (arr1, 10);
  
  // find average of second array of values
  arr_value = (INT_MAX / 10) + 2;
  for (i= 0; i < array_size; i++) {
    arr2[i] = arr_value;
  }
  compute_average (arr2, 10);

  return 0;

  }