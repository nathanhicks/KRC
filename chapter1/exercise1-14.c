/*************************************************************************\
*                  Copyright (C) Nathan Hicks, 2015.                      *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/
/* Solution for Exercise 1-14 from the K & R "C Programming Language, 2nd ed."
 *
 * Write a program to print a histogram of the frequencies of different
 * characters in its input.
 *
*/

#include <stdio.h>

main()
{
  int c,i,j,y;
  // 97 - 122 (a - z)
  int frequency[26];
  for(i = 0; i < 26; ++i) {
    frequency[i] = 0;
  }
  c = i = j = y = 0;

  // Count frequency of each character
  while ((c = getchar()) != EOF) {
    frequency[c-97] += 1;
    //printf("f[%d] = %d, c = %d\n",c-97,frequency[c-97],c);
    if ( frequency[c-97] > y ) {
      y = frequency[c-97];
    }
  }
  printf("y = %d\n",y);

  // Print the histogram
  for(i = 0; i < y; ++i) {
    for(j = 0; j < 26; ++j) {
      if ( frequency[j] > 0 ) {
        printf("||\t");
        frequency[j]--;
        //printf("%c = %d\n",i+97,frequency[i]);
      } else {
        printf("\t");
      }
    }
      printf("\n");
  }

  for(i = 0; i < 26; ++i)
    printf("%c\t",i+97);
  printf("\n");

}
