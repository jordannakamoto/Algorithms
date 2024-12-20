/** ***************************************************************************
 * @remark program to time several versions of the merge sort algorithm       *
 *  on data sets of various sizes                                             *
 *                                                                            *
 * @remark Approach 1: Traditional Recursive Algorithm                        *
 * @remark Approach 2: Traditional Recursive Algo w/ just 2 working arrays    *
 * @remark Approach 3: Iterative Algorithm with Traditional Merge             *
 * @remark Approach 4: Iterative, with only one auxiliary array               *
 *                                                                            *
 * @author Jordan Nakamoto                                                    *
 * @file  mergesort.c                                                         *
 * @date  Mar 7, 2024                                                         *
 *                                                                            *
 * @remark References                                                         *
 * @remark https://blue.cs.sonoma.edu/~hwalker/courses/                       *
 *         415-sonoma.sp24/assignments/assignment-brute-force-mergesort.php   *
 * @remark https://www.tutorialspoint.com/                                    *
 *         cplusplus-program-to-implement-merge-sort                          *
 *                                                                            *
 * @remark People participating with Problem/Program Discussions:             *
 *         None                                                               *
 *                                                                            *
 *****************************************************************************/

/** *******************************************************************************
 * percDown function                                                              *
 * @param  array  the array to be made into a heap, starting at hole              *
 * @param  hole:  the node index (or base) of subtree for start of processing     *
 * @param  size  the size of the array                                            *
 * @pre   all nodes in left and right subtrees of the hole node are heaps         *
 * @post  all nodes in the tree from the hole node downward form a heap           *
 *********************************************************************************/

/** *******************************************************************************
 * heap sort, main function                                                       *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * @post  the first n elements of a are sorted in non-descending order            *
 *********************************************************************************/






/** **************************************************************************************
 * Merge Sort Helper Function for Approach 2                                             *
 * @param  array  source array for merging                                               *
 * @param  lArr  pointer to lArr working array pre-initialized memory                    *
 * @param  rArr  pointer to rArr working array pre-initialized memory                    *
 * @param  l  the left edge of sub array                                                 *
 * @param  m  the mid point of sub array                                                 *
 * @param  r  the right edge of sub array                                                *
 * @post  elements  array[l]..array[m] merged with                                       *
 *              array[m+1]..array[r]                                                     *
 *               with the result placed in array                                         *
 ****************************************************************************************/

/*****************************************************************************************
 * * Approach 3: iterative merge sort and traditional merge procedures   * * * * * * * * *
 ****************************************************************************************/
/** **************************************************************************************
 * merge sort helper function                                                            *
 * @param  array  source array for merging                                               *
 * @param  aInitLength  the size of the array segment to be merged                       *
 * @param  start1  the first index of the first array segment to be merged               *
 * @param  start2  the first index of the second  array segment to be merged             *
 * @param  end2 the index after the second array segment to be merged                    *
 * @post  elements  array[start1]..array[start1+mergeSize] merged with                   *
 *              array[start2]..array[end2]                                               *
 *               with the result placed in array                                         *
 * Note:  it may be that start2 >= array.length, in which case, only the                 *
 *        valid part of array[start1] is copied                                          *
 ****************************************************************************************/

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
