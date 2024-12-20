/** ****************************************************************************
 * @remark Program implementing Newton's Method to find the root               *
 *    of a function y = f(x), based on an initial guess x0                     * 
 *                                                                             *
 * @author Henry M. Walker                                                     *
 * @file  newtins-method.c                                                     *
 * @date  July 25, 2002; updated December 24, 2022                             *
 *                                                                             *
 *******************************************************************************/
/* Newton's Method for finding the root of a function */

/* To use this program, you should follow these steps:

   1.  Copy this program to your account.  The suggested name is 

          newtons-method.c

   2.  Use an editor to adjust two functions within this file:

          f(x), the function of interest
          fprime(x), the derivative of the function

   3.  In a terminal window, compile the program using the command:

          gcc -o newtons-method -lm  newtons-method.c

       If all goes well, the window will respond with the usual prompt.
       If you get an error message, check the spelling of f and fprime
          or ask your instructor. 

   4.  In a terminal window, run the edited program with the command

          ./newtons-method

*/    

#include <stdio.h>
#include <math.h>     /* sometimes needed for trig. func. and sqrt */

/** ***************************************************************************
 * compute a function y = f(x)---the function forming the basis for this work *
 * @param  x  the desired initial parameter for this function                 *
 * @pre    x is in the domain of this function                                *
 * @returns the value computed for f(x)                                       *
 ******************************************************************************/
double f (double x) 
{
  return x*x*x - 21;
}

/** ***************************************************************************
 * compute  the derivative of the function y = f(x), defined elsewhere        *
 * @param  x  the desired initial parameter for this function                 *
 * @pre    x is in the domain of this derivative function                     *
 * @returns the value computed for f'(x)                                       *
 ******************************************************************************/
double fprime (double x) 
{
  return 3*x*x;
}

int iterations = 20;

/** ***************************************************************************
 * this function runs Newton's Method for a specified number of iterations    *
 *     + the user is prompted to enter an initial guess                       *
 *     + the program assumes (and does not check) that                        *
 *           function fprime is the derivative of function f                  *
 *     + the program repeats Newton's Method, based on the value of           *
 *           variable iterations                                              *
 ******************************************************************************/
int main () 
{
  double guess, revisedGuess;
  double fguess, fprimeGuess;
  int index;

  /* Getting started */
  printf ("Program to apply Newton's Method %d times\n\n", iterations);
  printf ("Enter initial guess: ");
  scanf ("%lf", &guess);

  /* printing heading */
  printf ("iteration  guess      f(guess)     f'(guess)    new guess\n");

  /* applying Newton's Method */
  for (index = 1; index <= iterations; index++)
    {
      fguess = f(guess);
      fprimeGuess = fprime(guess);
      revisedGuess = guess - fguess/fprimeGuess;
      printf ("%5d %12.8lf %12.8lf %12.8lf %12.8lf\n", 
              index, guess, fguess, fprimeGuess, revisedGuess);
      guess = revisedGuess;
    }

  printf ("\nThe approximate root is %12.8lf\n", revisedGuess);

}