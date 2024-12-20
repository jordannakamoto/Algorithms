/** ******************************************************************************
 * @remark Program to compute and test polynomials using Horner's Rule           *
 *                                                                               *
 * @author Jordan Nakamoto                                                       *
 * @file   horner.c                                                              *
 * @date   Mar 14, 2024                                                          *
 *                                                                               *
 * @remark References                                                            *
 * @remark https://blue.cs.sonoma.edu/~hwalker/courses/                          *
 *         415-sonoma.sp24/assignments/assignment-heapssorting-alg-efficiency.php*
 *                                                                               *                                                                      *
 * @remark People participating with Problem/Program Discussions:                *
 *         None                                                                  *
 *                                                                               *
 *********************************************************************************/

#include <stdio.h>

/*********************************************************************************
 * evaluate a polynomial for a given x using Horner's Rule.                      *
 * @param poly array of polynomial coefficients in descending power order        *
 * @param n    size of the array of coefficients                                 *
 * @param x    value for which polynomial is evaluated                           *
 * @return     integer result                                                    *
**********************************************************************************/
int compute_poly(int poly[], int n, int x) 
{
    int result = poly[0]; // Initialize result
    // Horner's Rule
    for (int i = 1; i < n; i++)
        result = result * x + poly[i];
    return result;
}

/*********************************************************************************
 *     MAIN Driver Program                                                       *
 ********************************************************************************/
int main() 
{
    // Test Cases
    int test1[] = {2, -6, 2, -1};
    int test2[] = {1, 0, -4, 4};
    int test3[] = {-1, 3, -3, 1};
    int test4[] = {3, -2, 0};
    int test5[] = {1, -4}; // Example of a 1st degree polynomial

    // Number of coefficients in each polynomial
    int lengths[] = {4,4,4,3,2};
    
    // Values of x for the tests...
    int xs[] = {3, 2, -1, 5, 0};

    // Arrays of pointers to the test case arrays
    int* tests[] = {test1, test2, test3, test4, test5};
    int n_tests = 5;

    // Printing the table header
    printf("Polynomial Coefficients\t\tX\tResult\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < n_tests; i++) {
        // Print the input polynomial coefficients
        printf("[ ");
        for (int j = 0; j < lengths[i]; j++) {
            printf("%d ", tests[i][j]);
        }
        printf("]\t\t\t");

        // Calculate and print the result
        int result = compute_poly(tests[i], lengths[i], xs[i]);
        printf("%d\t%d\n", xs[i], result);
    }

    return 0;
}
