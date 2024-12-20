/** ***************************************************************************
 * A driver program to run the Loop-based analysis exercises.                 *
 *                                                                            *
 * @author Henry M. Walker                                                    *
 * @file  float-loop.c                                                        *
 * @date  January 24, 2022                                                    *
 *                                                                            *
 *****************************************************************************/

#include <iostream>
#include <sstream>
#include <time.h>
#include "loop.h"

using namespace std;

/* dummy variable to determine time to call pfunction and return */
int runBase (int n) {
  int var = 0;
  return var;
}
    
int main(int argc, char * argv []) {

  int (* funcArray [6]) (int)= {runBase, run1, run2, run3, run4, run5};

    int MAX_EXERCISE = 5;
    int NUMBER_REPETITIONS = 2000;

    // prelinimaries
    cout << "Program to run and time loop-based code segments\n";
      
    int exer = 0;    // loop exercise to run and time
    int iter = 0;  // number of iterations to time

    try {
    // error checking of command-line arguments
    // check for exactyly 2 numbers supplied
    if (argc != 3) {
      throw 1;     // error 1:  wrong number o auguments
    }


    istringstream iss1 (argv[1]);
      if (!(iss1 >> exer) || !iss1.eof() || (exer <= 0) || (exer > MAX_EXERCISE) ) {
        throw 2;  // error 2:  first argument not a number;
      }
      
      istringstream iss2 (argv[2]);
      if (!(iss2 >> iter) || !iss2.eof() || (iter <= 0) ) {
        throw 3;  // error 2:  second argument not a number;
      }
    }  // end try block
    
    catch (int except) {
      cout << "command-line error\n";
      switch (except) {
         case 1:  cout << "     2 arguments required\n";
         case 2:  cout << "     arg. 1:  Loop variations to use --- a number between 1 and " << MAX_EXERCISE << "(inclusie)\n";
         case 3:  cout << "     arg. 2:  number of iterations to time --- a positive number\n";
         default:  cout << "     integer error identified\n";
      } ;
      cout << "exiting program\n";
      exit(1);
    }
    catch (...) {
      cout << "exception of another type\n";
      exit (1);
    }


    int i, j;

    cout << "Running Exercise " << exer << " with time iterations = " << iter << "\n";;
    cout << "   run repeated " << NUMBER_REPETITIONS << " squared times\n";

    // first time doubly-nested loop and assignment
    int res;
    long baseStartTime = clock ();
    long baseEndTime;
    for (i = 0; i < NUMBER_REPETITIONS; i++)
        for (j = 0; j < NUMBER_REPETITIONS; j++)
          res = funcArray[0] (iter);
    baseEndTime = clock ();
    
    double baseDuration = (baseEndTime - baseStartTime) / (double) CLOCKS_PER_SEC;

    // now test desired method
    long startTime = clock ();
    for (i = 0; i < NUMBER_REPETITIONS; i++)
        for (j = 0; j < NUMBER_REPETITIONS; j++)
          res = funcArray[exer] (iter);
    baseEndTime = clock ();

    int endTime = clock();
    double duration = (endTime - startTime) / (double) CLOCKS_PER_SEC;

    cout << "result returned:  " << res << "\n";

    double methodTime = duration - baseDuration;
    if (methodTime < 0)
       methodTime = 0;

    printf ("looping time:        %7.2lf \n", baseDuration);
    printf ("method execution time%7.2lf \n", duration);
    printf ("loop execution time: %7.2lf \n", methodTime);
  
}

