/** ****************************************************************************
 * program to count letters and basic punctuation in a line of text            *
 *    upper and lower case letters are considered the same in processing       *
 *                                                                             *
 * @author Henry M. Walker                                                     *
 * @file  count-characters.c                                                   *
 * @date December 31, 2022                                                     *
 *                                                                             *
 *******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main ( ) {

  /* list characters to be counted, with the space character last */
  char charArray [ ] = "abcdefghijklmnopqrstuvwxyz'!@#$%^&*()_+-=,. ";

//   printf ("program to count characters in a line of text\n");
//   printf ("   characters recognized:  %s\n", charArray);

  /* variables used */
  int pos, i;
  char ch;
  int otherCount = 0;   // count of characters not covered in charArray
  int count [strlen(charArray)];  // number of time each charater in charArray
  for (i = 0; i < strlen(charArray); i++)
    count[i] = 0;

  /* read and process each character in line entered by user */
  while ( (ch = tolower(getchar ())) != '\n') { 
    // since strchr returns the address of the character in a string,
    //   subtract the base address to get the index of the character
    pos = strchr (charArray, ch) - charArray;
    if (pos >= 0)
      count[pos] ++;
    else
      otherCount++;
  }

  /* report counts */
  printf ("\nccharacter counts in line\n     ");
  for (i = 0; i <  strlen(charArray)-1; i++)
    printf (" %c", charArray[i]);
  printf (" space other\n     ");
    
   for (i = 0; i <  strlen(charArray)-1; i++)
    printf ("%2d", count[i]);
   printf ("  %2d    %2d \n", count[strlen(charArray)-1], otherCount);
 
  return 0;
}