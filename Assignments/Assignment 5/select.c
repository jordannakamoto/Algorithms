#include <stdio.h>
#include <stdlib.h>   // for malloc, free
#include <time.h>     // for time

/** *******************************************************************************
 * procedure implements the partition operation, following Loop Invariant 1a      *
 *    the Reading on Quicksort referenced above                                   *
 *    in brief: array segment has pivot, then small, unprocessed, large elements  *
 *              both unprocessed endpoints examined, swapping done in line        *
 * @param   a      the array containing the segment to be partitioned             *
 * @param   size   the size of array a                                            *
 * @param   left   the index of the first array element in the partition          *
 * @param   right  the index of the last array element in the partitionn          *
 * @post    a[left] is moved to index mid, with left <= mid <= right              *
 * @post    elements between left and right are permuted, so that                 *
 *             a[left], ..., a[mid-1] <= a[mid]                                   *
 *             a[mid+1], ..., a[right] >= a[mid]                                  *
 * @post    elements outside left, ..., right are not changed                     *
 * @returns  mid                                                                  *
/ *********************************************************************************/
int basicPartition (int a[ ], int size, int left, int right) {
  
  int pivot = a[left];
  int l_spot = left+1;
  int r_spot = right;
  int temp;
  
  while (l_spot <= r_spot) {
    while( (l_spot <= r_spot) && (a[r_spot] >= pivot))
      r_spot--;
    while ((l_spot <= r_spot) && (a[l_spot] <= pivot)) 
      l_spot++;

    // if misplaced small and large values found, swap them
    if (l_spot < r_spot) {
      temp = a[l_spot];
      a[l_spot] = a[r_spot];
      a[r_spot] = temp;
      l_spot++;
      r_spot--;
      }
  }

  // swap a[left] with biggest small value
  temp = a[left];
  a[left] = a[r_spot];
  a[r_spot] = temp;
  return r_spot;
}

/** *******************************************************************************
 * Quicksort helper function                                                      *
 * @param  a  the array to be processed                                           *
 * @param  size  the size of the array                                            *
 * @param  left  the lower index for items to be processed                        *
 * @param  right the upper index for items to be processed                        *
 * @post  sorts elements of a between left and right                              *
 *********************************************************************************/
void basicQuicksortHelper (int a [ ], int size, int left, int right) {
  if (left > right)
    return;
  int mid = basicPartition (a, size, left, right);
  basicQuicksortHelper (a, size, left, mid-1);
  basicQuicksortHelper (a, size, mid+1, right);
}

/** *******************************************************************************
 * quicksort, main function                                                       *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * @post  the first n elements of a are sorted in non-descending order            *
  ********************************************************************************/
void basicQuicksort (int a [ ], int n) {
  basicQuicksortHelper (a, n, 0, n-1);
}

int select(int a[], int size, int left, int right, int k) {

    // define pivot and pointer indexes
    int pivot = a[left];
    int l_spot = left + 1;
    int r_spot = right;
    int temp; // for swapping

    // Inlined Invariant 1 Style Pivot...
    while (l_spot <= r_spot) {
        while ((l_spot <= r_spot) && (a[r_spot] >= pivot)) {
            r_spot--;
        }
        while ((l_spot <= r_spot) && (a[l_spot] <= pivot)) {
            l_spot++;
        }
        if (l_spot < r_spot) {
            temp = a[l_spot];
            a[l_spot] = a[r_spot];
            a[r_spot] = temp;
        }
    }
    int mid = r_spot; // Alias mid. Swap the pivot to its correct place
    temp = a[left];
    a[left] = a[mid];
    a[mid] = temp;

    // Check if we have found the k-th element in the semi-sorted array
    if (mid == k - 1) {
        return a[mid];
    } else if (mid > k - 1) { // Otherwise, proceed to further divide and conquer the sort
        return select(a, size, left, mid - 1, k);
    } else {
        return select(a, size, mid + 1, right, k);
    }
}


int main() {
    srand(time(NULL));
    int size = 20;
    int k = rand() % size;

    int a[size];
    int aSorted[size];
    for (int i = 0; i < size; i++) {
        int randVal = rand() % 100;
        a[i] = randVal;
        aSorted[i] = randVal;
    }
    printf("Random Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    int result = select(a, size, 0, size - 1, k);
    printf("\nThe %d-th smallest element is: %d\n", k, result);

    // Verify with quicksort at a[k-1]
    basicQuicksort(aSorted,size);
    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", aSorted[i]);
    }
    printf("\nVerify with quicksort, %d-th smallest element is: %d\n", k, aSorted[k-1]);

    return 0;
}
