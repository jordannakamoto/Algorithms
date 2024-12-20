/** ***************************************************************************
 * @remark basic computation of input integer n to its forth power using      *
 * recursive method.                                                          *
 * @author Henry M. Walker                                                    *
 * @file  fourthPower.c                                                       *
 * @date  February 8, 2024                                                    *
 *                                                                            *
 * @remark Compile this program in a Terminal window with the line            *
 *        gcc -o fourthPower fourthPower.c                                    *
 * @remark References                                                         *
 * @remark Analysis of Recursive Algorithms:  Anany Levitin, "The Design and  *
 *         and Analysis of Algorithms", Second Edition,                       *
 *         Chapter 2:  Fundamentals of the Analysis of Algorithm Efficiency   *
 ******************************************************************************/

#include <stdio.h>

/** ***************************************************************************
 * prompt the user to enter an integer value 'n' and read input.              *
 * @returns The integer value entered by the user.                            *
 ******************************************************************************/
int readn() {
    int value;
    printf("Enter integer value n: ");
    scanf("%d", &value);
    return value;
}

/** ***************************************************************************
 * compute the fourth power of a given integer recursively                    *
 * using polynomial expansion of (n-1)^4                                      *
 *                                                                            *
 * @param n: the integer to n to compute the Fourth Power of                  *
 * @returns the resultant fourth power of integer n.                          *
 ******************************************************************************/
int computeFourth(int n) {
    int result;
    if (n == 1) {
        result = 1;
    } else {
        result = computeFourth(n - 1) + 4 * n * n * n - 6 * n * n + 4 * n - 1;
    }
    return result;
}

/** ***************************************************************************
 * main procedure prompts user, computes fourth power, and prints result      *
 *                                                                            *
 * @returns int Program exit status.                                          *
 ******************************************************************************/
int main() {
    printf("Program to compute n to the fourth power\n");
    
    int n = readn();
    int answer = computeFourth(n);
    
    printf("%d to the fourth is %d\n", n, answer);
    
    return 0;
}