/** ***************************************************************************
 * @remark program to approximate a root of a function.                       *
 *     using the Bisection Method of repeated interval halving.               *
 *                                                                            *
 * @author Jordan Nakamoto                                                    *
 * @file  bisection.cpp                                                       *
 * @date  April 20, 2024                                                      *
 *                                                                            *
 * @remark Reference                                                          *
 * @remark Reading on the Bisection Method                                    *
https://blue.cs.sonoma.edu/~hwalker/courses/415-sonoma.sp24/readings/reading-bisection-method.php *                                                                            *
 *****************************************************************************/

#include <iostream>
#include <assert.h>

using namespace std;
/** ***************************************************************************
 * function, f, which program finds the root of                               *
 * @param     x    the input value which gets transformed to y                *
 * @returns        the y value result of the function                         *
 ******************************************************************************/
double f(double x){
    return x*x - 25; // example function
};

/** ***************************************************************************
 * find_root       finds the root of function, f, by bisecting an interval    *
 * @param     a        the x value for the left most point f(a)               *
 * @param     b        the x value for the right most point f(b)              *
 * @param     accuracy the minimum interval for an accurate convergence       *
 * @returns   m        midpoint root with minimum accuracy                    *
 ******************************************************************************/
double find_root(double a,double b, double accuracy){


// > find_root should continue to cut the interval in half,
// > following the Bisection Method, until
// > either f(m)=0 for a computed midpoint m
// > or the newly computed interval is shorter than the accuracy specified.
    
    assert(f(a) * f(b) < 0); // Assert f(a) f(b) one is positive other is negative
    assert(accuracy > 0);    // Check that accuracy is positive

    double m = (a + b) / 2;  // first midpoint check
    while(true){
        double m = (a + b) / 2;
        // fabs returns absolute value
        if(fabs(f(m)) < accuracy) return m;
        else if(f(a)*f(m) < 0) b = m;
        else a = m;
    }
    return m; // return the computed midpoint of the final interval.
};

/** ***************************************************************************
 * main procedure: ...                                                        *
 *****************************************************************************/
int main(){
    // The main program should ask the user to enter endpoints a and b and the accuracy. The main program then should call find_roots with the appropriate parameters and report the result.
    double a, b, accuracy;

    cout << "Enter endpoints a and b and the accuracy: " << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "accuracy: "; cin >> accuracy;
    double root = find_root(a, b, accuracy);

    cout << "Computed Root: \n" << root << endl;

    return 1;
};


