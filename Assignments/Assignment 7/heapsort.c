/** ******************************************************************************
 * @remark Program to compute and test polynomials using Horner's Rule           *
 *                                                                               *
 * @author Jordan Nakamoto                                                       *
 * @file   horner.c                                                              *
 * @date   Mar 14, 2024                                                          *
 *                                                                               *
 * @remark References                                                            *
 * @remark https://blue.cs.sonoma.edu/~hwalker/courses/                          *
 *         415-sonoma.sp24/assignments/assignment-heapssorting-alg-efficiency.php*                                                                      *
 * @remark People participating with Problem/Program Discussions:                *
 *         None                                                                  *
 *                                                                               *
 *********************************************************************************/

#include <stdio.h>    // for printf
#include <stdlib.h>   // for malloc, free
#include <time.h>     // for time

/**********************************************************************************
 * * *   max heap implementation of heap sort to non descending order         * * *
 *********************************************************************************/
/** *******************************************************************************
 * percDown function                                                              *
 * @param  array  the array to be made into a heap, starting at hole              *
 * @param  hole:  the node index (or base) of subtree for start of processing     *
 * @param  size  the size of the array                                            *
 * @pre   all nodes in left and right subtrees of the hole node are heaps         *
 * @post  all nodes in the tree from the hole node downward form a heap           *
 *********************************************************************************/
void percDown(int array[], int hole, int size) {
    // index markers
    int largest = hole;     //  largest starts at i
    int left = 2*hole + 1; //   left = 2*i + 1
    int right = 2*hole + 2; //  right = 2*i + 2

    // check that array access does not go beyond the size of the array
    // If left child is larger than root
    if (left < size && array[left] > array[largest]){
        largest = left;
    }
    // If right child is larger than largest so far
    if (right < size && array[right] > array[largest]){
        largest = right;
    }
    // If largest is found in left or right child
    if (largest != hole) {
        // Swap a[hole] with largest
        int temp = array[hole];
        array[hole] = array[largest];
        array[largest] = temp;

        // Recursively percDown the affected sub-tree
        percDown(array, largest, size);
    }
}
/** *******************************************************************************
 * heap sort, main function                                                       *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * @post  the first n elements of a are sorted in non-descending order            *
 *********************************************************************************/
void heapSort(int heap[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        percDown(heap, i, n);

    // One by one extract an element from heap
    for (int i = n-1; i > 0; i--) {
        // Move current root to end
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        // call percDown on the reduced heap
        percDown(heap, 0, i);
    }
}
/*****************************************************************************************
 * * * * * * * * * * * * * procedures to check sorting correctness * * * * * * * * * * * *
 ****************************************************************************************/
/** **************************************************************************************
 * check all array elements have values 0, 2, 4, . . ., 2(n-1)                           *
 * @param  a  the array to be sorted                                                     *
 * @param  n  the size of the array                                                      *
 * returns  "ok" if array contains required elements; "NO" if not                        *
 *****************************************************************************************/
char * checkAscValues (int a [ ], int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] != 2*i) {
      //printf ("%4d %4d", i, a[i]);  // index of first error
      return "Er";
    }
  }
  return "ok";
}
/** **************************************************************************************
 * check all array elements are in non-descending order                                  *
 * @param  a  the array to be sorted                                                     *
 * @param  n  the size of the array                                                      *
 * returns  "ok" if array elements in non-descending order; "NO" otherwise               *
 *****************************************************************************************/
char * checkAscending (int a [ ], int n) {
  for (int i = 0; i < n-1; i++) {
    if (a[i] > a[i+1])
      return "NO";
  }
  return "ok";
}
/*****************************************************************************************
 *     MAIN Driver Program                                                               *
 ****************************************************************************************/
int main ( ) {
  //size variables
  int size = 10000;
  int maxDataSetSize = 40960000;
  int numSort;

  // randomize random number generator's seed
  srand (time ((time_t *) 0) );
  srandom (time ((time_t *) 0) );
  
  // print headings
  printf ("                Data Set                                Times\n");
  printf ("Algorithm        Size        Ascending Order       Random Order   Descending Order\n");

  for (size = size; size <= maxDataSetSize; size *= 2) {
    // create and initialize control data set arrays
    int * asc = (int *) malloc (size * sizeof(int));   //array with ascending data
    int * ran = (int *) malloc (size * sizeof(int));   //array with random data
    int * des = (int *) malloc (size * sizeof(int));   // array with descending data

    // populate arrays with values
    int i;
    for (i = 0; i< size; i++) {
    asc[i] = 2*i;
    ran[i] = rand();
    des[i] = 2*(size - i - 1); 
    } 
    // timing variables
    clock_t start_time, end_time;
    double elapsed_time;

    // print sorting algo name
    printf ("%8s %14d", "HeapSort", size);
      
    // ascending data
    start_time = clock ();
    heapSort (asc, size);
    end_time = clock();
    elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
    printf ("%14.1lf", elapsed_time);
    printf ("  %2s", checkAscValues (asc, size));
         
    // random data
    start_time = clock ();
    heapSort (ran, size);
    end_time = clock();
    elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
    printf ("%15.1lf", elapsed_time);
    printf ("  %2s", checkAscending (ran, size));
    
    // descending data
    start_time = clock ();
    heapSort (des, size);
    end_time = clock();
    elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
    printf ("%15.1lf", elapsed_time);
    printf ("  %2s", checkAscValues (des, size));
    printf ("\n");
    
    // CLEAN -----
    free (asc);
    free (ran);
    free (des);
  }
  return 0;
}