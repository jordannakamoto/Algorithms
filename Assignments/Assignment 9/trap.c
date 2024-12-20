/** ***************************************************************************
 * @remark program to show numerical error produced by Trapezoidal Rule       *
 *                                                                            *
 * @remark Several ranges (a,b) are tested, decreasing function are tested    *
 *         for the decreasing function f(x) = 1000 - x^2                      *
 *                                                                            *
 * @author Jordan Nakamoto                                                    *
 * @file  trap.c                                                              *
 * @date  Apr 11, 2024                                                        *
 *                                                                            *
 * @remark References                                                         *
 * @remark https://blue.cs.sonoma.edu/~hwalker/courses/415-sonoma.sp24/assignments/assignment-data-rep-consequences.php
 *                                                                            *
 *****************************************************************************/

#include <stdio.h>
#include <math.h>


/** **************************************************************************************
 * function f(x) = 1000 - x^2                                                            *
 * @param  x  the value for f(x)                                                         *
 *****************************************************************************************/
double f(double x) {
    return 1000 - (x*x); // Decreasing quadratic function
}

/** **************************************************************************************
 * trapezoidalRule - calculate the area using the trapezoidal rule                       *
 * @param  start    the starting point of the area                                       *
 * @param  end      the ending point of the area                                         *
 * @param  n        the number of intervals                                              *
 * @param  reverse  flag for L-R or R-L                                                  *
 * @post            returns the area                                                     *
 *****************************************************************************************/
double trapezoidalRule(double start, double end, int n, int reverse) {
    // calculate h
    double h = (end - start) / n;
    // Initialize sum with the ends of the interval.
    double sum = (f(start) + f(end)) / 2.0;
    for (int i = 1; i < n; i++) {
        // Either start from the end and go backwards, or start from the beginning and go forwards
        double x;
        if(reverse){
            x = end - i * h;
        }
        else{
            x = start + i * h;
        }
        sum += f(x);
    }
    return sum * h;
}

// MAIN //----------------------------------------------------------------
int main() {
    double a = 0;  // Start of interval
    double b_values[] = {10, 20, 30, 40, 50};  // Different values for b
    // Different values for number of intervals
    int n_intervals[] = {100, 1000, 10000, 100000, 1000000, 10000000,100000000,1000000000};

    for (int j = 0; j < sizeof(b_values)/sizeof(b_values[0]); j++) {
        double b = b_values[j];
        double actualArea = 1000 * b - (b * b * b) / 3.0;  // Actual area calculation for each b

        printf("Results for interval [0, %.0f]:\n", b);
        printf("Intervals\tComputed L to R\t\terror\t\t\tComputed R to L\t\terror\n");

        for (int i = 0; i < sizeof(n_intervals)/sizeof(n_intervals[0]); i++) {
            int n = n_intervals[i];
            double areaLtoR = trapezoidalRule(a, b, n, 0);
            double areaRtoL = trapezoidalRule(a, b, n, 1);

            printf("%10d\t%.16f\t%.16f\t%.16f\t%.16f\n",
                n,
                areaLtoR, fabs(areaLtoR - actualArea),
                areaRtoL, fabs(areaRtoL - actualArea));
        }
        printf("\n");
    }
    return 0;
}