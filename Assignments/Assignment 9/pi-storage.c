/** ***************************************************************************
 * @remark exploring the storage of the number Pi as a double                 * 
 *                                                                            *
 *  the treu value of pi to 39 decimal places is                              *
 *     3.141592653589793238462643383279502884197                              *
 *                                                                            *
 *  the true valued is stored in a double and printed                         *
 *     to various decimal places,                                             *
 *                                                                            *
 * @author Henry M. Walker                                                    *
 * @file  pi-storage.c                                                        *
 * @date  Summer, 2023                                                        *
 *                                                                            *
 * @remark References                                                         *
 * @remark Consequences of Data Representation on Programming                 *
  https://blue.cs.sonoma.edu/~hwalker/courses/415-sonoma.sp23/readings/data-rep-consequences.html
 * @remark article "pi" in Britannica                                         *
  https://www.britannica.com/science/pi-mathematics
 *                                                                            *
 *****************************************************************************/

#include <stdio.h>
#include <string.h>

int main ( ) {
  char * piString = "3.141592653589793238462643383279502884197";
  printf ("Program to explore the storage of the number Pi\n");

  printf ("according to Britannica.com, the value to 39 decimal places is %s\n", piString);

  double piDouble = 3.141592653589793238462643383279502884197;

  printf ("double variable 'piDouble' initialized to pi with 32 decimal places\n");
    printf ("printing of double variable to succesive decimal places\n");

  printf ("decimal places pi (double) // \n");
  printf ("places+1       actual pi\n");

  char formatString [50] = {0};
  for (int i = 13; i < 25; i++) {
    // format and double to i decimal places
    sprintf (formatString, "%%.%dlf", i);
    printf ("%3d (double)    ", i);
    printf (formatString, piDouble);
    printf ("\n");

    // print i+1 decimal places of actual pi string
    char piSubstring [50] = {0};
    strncpy(piSubstring, piString, i+3);
    printf ("    (actual)    %s\n", piSubstring);

    // highlight 15th decimal place with '^' characte4
    printf ("                  %15c\n\n", '^');

  }
  
  return 0;
}