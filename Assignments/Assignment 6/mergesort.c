/* program to time several versions of the merge sort algorithm on data sets of various sizes
 */

#include <stdio.h>
#include <stdlib.h>   // for malloc, free
#include <time.h>     // for time

/** *******************************************************************************
 * structure to identify both the name of a sorting algorithm and                 *
 * a pointer to the function that performs the sort                               *
 * the main function utilizes this struct to define an array of                   *
 * the sorting algorithms to be timed by this program.                            *
 *********************************************************************************/
typedef struct sorts {
  char * name;                     /**< the name of a sorting algorithm as text  */
  void (*sortProc) (int [ ], int); /**< the procedure name of a sorting function */
} sorts;

/*****************************************************************************************
 * * * * * * * * * traditional recursive merge sort and merge procedures * * * * * * * * *
 ****************************************************************************************/
/** **************************************************************************************
 * tradtional merge Sort procedure, renamed from                                         *
 * source:  tutorialpoint.com:                                                           *
 * https://www.tutorialspoint.com/cplusplus-program-to-implement-merge-sort              *
 * See URL for parameters, etc.                                                          *
 *****************************************************************************************/
void tutorialPointMerge (int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
/** **************************************************************************************
 * tradtional merge Sort procedure, with left/right (l/r) parameters, renamed from       *
 * source:  tutorialpoint.com:                                                           *
 * https://www.tutorialspoint.com/cplusplus-program-to-implement-merge-sort              *
 * See URL for parameters, etc.                                                          *
 *****************************************************************************************/

void tutorialPointMergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      tutorialPointMergeSort(array, l, m);
      tutorialPointMergeSort(array, m+1, r);
      tutorialPointMerge(array, l, m, r);
   }
}
/** **************************************************************************************
 * iterative  merge Sort procedure with copy to array and copy back, but                 *
 *    just using the original array and one other                                        *
 * @param  a  the array to be sorted                                                     *
 * @param  n  the size of the array                                                      *
 * @post  the first n elements of a are sorted in non-descending order                   *
 *****************************************************************************************/
void tradRecMergeSort  (int a [ ], int n) {
tutorialPointMergeSort (a, 0, n-1);
}
/*****************************************************************************************
 * * * * * * * * traditional,recursive merge sort with only 2 local arrays  * * * * * * *
 ****************************************************************************************/

/** **************************************************************************************
 * traditional, recursive merge Sort procedure,                                          *
 *   where associated merge procedure uses only two working arrays (not local arrays)    *
 * @param  a  the array to be sorted                                                     *
 * @param  n  the size of the array                                                      *
 * @post  the first n elements of a are sorted in non-descending order                   *
 *****************************************************************************************/
void recMerge2Arrays (int initArr [ ], int n) {
  // to be implemented
}
/*****************************************************************************************
 * * * * * * * * * iterative merge sort and traditional merge procedures * * * * * * * * *
 ****************************************************************************************/
/** **************************************************************************************
 * merge sort helper function                                                            *
 * @param  aInit  source array for merging                                               *
 * @param  aRes   target array for merging                                               *
 * @param  aInitLength  the size of the array segment to be merged                       *
 * @param  start1  the first index of the first array segment to be merged               *
 * @param  start2  the first index of the second  array segment to be merged             *
 * @param  end2 the index after the second array segment to be merged                    *
 * @post  elements  aInit[start1]..aInit[start1+mergeSize] merged with                   *
 *              aInit[start2]..Init[end2]                                                *
 *               with the result placed in aRes                                          *
 * Note:  it may be that start2 >= aInit.length, in which case, only the                 *
 *        valid part of aInit[start1] is copied                                          *
 ****************************************************************************************/
void iterMergeDynArrays (int array [ ], int aInitLength,
                int start1, int start2, int end2) {
  if (start2 > aInitLength)
    start2 = aInitLength;
  int end1 = start2-1;
  
  if (end2 > aInitLength)
    end2 = aInitLength;
  int pos = start1;
  
   
  //size of left and right sub-arrays
  int lSize = start2 - start1;
  int rSize = end2 - start2;
  
  // copy array segments to local arrays
  int * lArr = (int *) malloc (lSize * sizeof (int));
  int * rArr = (int *) malloc (rSize * sizeof (int));
  //fill left and right sub-arrays
  int i, j;
  for(i = 0; i<lSize; i++)
    lArr[i] = array[start1+i];
  for(j = 0; j<rSize; j++)
    rArr[j] = array[start2+j];
  
  //copy smaller of two non-empty local arrays
  i = j = 0;
  while ((i < lSize) && (j < rSize)) {
    if (lArr[i] <= rArr[j]) {
      array[pos] = lArr[i];
      i++;
      pos++;
    }
    else {
      array[pos] = rArr[j];
      j++;
      pos++;
    }
  }
    //copy any remaining elements from first segment
    while (i < lSize) {
      array[pos] = lArr[i];
      i++;
      pos++;
    }
    //copy any remaining elements from second segment
    while (j < rSize) {
      array[pos] = rArr[j];
      j++;
      pos++;
    }
free (lArr);
free (rArr);
}	
/** **************************************************************************************
 * iterative2-array merge Sort procedure,                                                *
 * @param  a  the array to be sorted                                                     *
 * @param  n  the size of the array                                                      *
 * @post  the first n elements of a are sorted in non-descending order                   *
 *****************************************************************************************/
void iterAlgWkthTradMerge (int a [ ], int n) {	
  int mergeSize = 1;
  int start1;
  while (mergeSize < n)
    {
      int end2;
      for (start1 = 0; start1 < n; start1 = end2) {
        int start2 = start1 + mergeSize;
        end2 = start2 + mergeSize;
        iterMergeDynArrays (a, n, start1, start2, end2);
      }
      mergeSize *=2;
    }
}
/*****************************************************************************************
 * * * * * * * * * iterative 2-array merge sort and associated procedures  * * * * * * * *
 ****************************************************************************************/

/** **************************************************************************************
 * iterative 2-array merge Sort procedure,                                               *
 *   using only one auxiliary [1-dimensional] array                                      *
 * @param  a  the array to be sorted                                                     *
 * @param  n  the size of the array                                                      *
 * @post  the first n elements of a are sorted in non-descending order                   *
 *****************************************************************************************/
void iter2ArrMergeSort (int initArr [ ], int n) {
  // to be implemented
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
/** **************************************************************************************
 * driver program for testing and timing sorting algorithms                              *
 *****************************************************************************************/
int main ( ) {
  #define numAlgs 4
  sorts sortProcs [numAlgs] = {{"trad. recursive merge sort", tradRecMergeSort},
                               {"rec. merge sort w/2 arrays", recMerge2Arrays},
                               {"iter. merge w/trad. merge ", iterAlgWkthTradMerge},
                               {"2-array interative sort   ", iter2ArrMergeSort}};

  //size variables
  int maxDataSetSize = 40960000;
  int algTimeLimit = 15; // do not print results after algorithm taks this long (in seconds)

  //arrays to determine which algorithms are to be run
  //   1 = run algorithm; 0 = do not run (alg has taken too long in past
  int algAscActive [numAlgs];
  int algRanActive [numAlgs];
  int algDesActive [numAlgs];

  // set maxRecSize to largest size avaiable before runtime stack overflow for recursive algorithms
  int maxRecSize = 1600000;
  maxRecSize = maxDataSetSize;  // this line allows all algorithms to be called, regardless of their details
                                // see assignment, problem 4b for details
  
  // initially all algorithms active for ascending, random, and descendind data
  int numSort;
;
 for (numSort = 0; numSort < numAlgs; numSort++) {
      algAscActive[numSort] = 1;
      algRanActive[numSort] = 1;
      algDesActive[numSort] = 1;
    }      
 
  // randomize random number generator's seed
  srand (time ((time_t *) 0) );
  srandom (time ((time_t *) 0) );
  
  // print headings
  printf ("                             Data Set                                Times\n");
  printf ("Algorithm                      Size        Ascending Order       Random Order   Descending Order\n");

  int size;
  for (size = 100000; size <= maxDataSetSize; size *= 2) {
      // create and initialize control data set arrays
     int * asc = (int *) malloc (size * sizeof(int));   //array with ascending data
     int * ran = (int *) malloc (size * sizeof(int));   //array with random data
     int * des = (int *) malloc (size * sizeof(int));   // array with descending data

     int i;
     for (i = 0; i< size; i++) {
        asc[i] = 2*i;
        ran[i] = rand();
        des[i] = 2*(size - i - 1); 
     } 

     // timing variables
     clock_t start_time, end_time;
     double elapsed_time;

     /* loop to test successive sorting procedures */
     // copy to test arrays
     int * tempAsc = malloc (size * sizeof(int));
     int * tempRan = malloc (size * sizeof(int));
     int * tempDes = malloc (size * sizeof(int));

     // break output for this array sze
     printf ("\n");

     /* iterate through sorting algorithms */
     for (numSort = 0; numSort < numAlgs; numSort++) {

       for (i = 0; i< size; i++) {
         tempAsc[i] = asc[i];
         tempRan[i] = ran[i];
         tempDes[i] = des[i];
       }
     
       // timing for sorting algorithm
       printf ("%14s %8d", sortProcs[numSort].name, size);
       // run-time stack exceeded for qicksort for large ordered arrays
       if (!algAscActive[numSort]) {
         printf ("           ---  --");
       } else {
         // ascending data
         start_time = clock ();
         sortProcs[numSort].sortProc (tempAsc, size);
         end_time = clock();
         elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
         printf ("%14.1lf", elapsed_time);
         printf ("  %2s", checkAscValues (tempAsc, size));
         algAscActive[numSort] = (elapsed_time <= algTimeLimit)
                                  && ((numSort!= 0) || (size < maxRecSize));
       }
       
       if (!algRanActive[numSort]) {
         printf ("            ---  --");
       } else {
        // random data
       start_time = clock ();
       sortProcs[numSort].sortProc (tempRan, size);
       end_time = clock();
       elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
       printf ("%15.1lf", elapsed_time);
       printf ("  %2s", checkAscending (tempRan, size));
       algRanActive[numSort] = (elapsed_time <= algTimeLimit)
                               && ((numSort!= 0) || (size < maxRecSize));
       }
       
       // run-time stack exceeded for qicksort for large ordered arrays
       if (!algDesActive[numSort]) {
         printf ("            ---  --");
       } else {
         // descending data
         start_time = clock ();
         sortProcs[numSort].sortProc (tempDes, size);
         end_time = clock();
         elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
         printf ("%15.1lf", elapsed_time);
         printf ("  %2s", checkAscValues (tempDes, size));
         algDesActive[numSort] = (elapsed_time <= algTimeLimit)
                                 && ((numSort!= 0) || (size < maxRecSize));
       }
       
       printf ("\n");

     }

     // clean up copies of test arrays
     free (tempAsc);
     free (tempRan);
     free (tempDes);

     // clean up original test arrays
     free (asc);
     free (ran);
     free (des);

  } // end of loop for testing procedures with different array sizes

  return 0;
}

