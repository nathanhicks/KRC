/*************************************************************************\
*                  Copyright (C) Nathan Hicks, 2015.                      *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/
/* Solution for Exercise 1-13 from the K & R "C Programming Language, 2nd ed."
 *
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging.
 *
*/
#include <stdio.h>

main()
{
  int c,x,y,largest_qty;

  int length_frequency[10];
  for(x = 0; x < 10; ++x)
    length_frequency[x] = 0;
  c = x = y = largest_qty = 0;

  /* Count wordlength */
  while ((c = getchar()) != EOF) {
    if((c == ' ') || (c == '\t') || (c == '\n')) { 
      length_frequency[x] += 1;
      // Determine y-dimension based on the most frequent word length
      if ( length_frequency[x] > largest_qty) {
        largest_qty = length_frequency[x];
      }
      x = 0;
    } else {
      ++x;
    }
  }

  /* Print histogram
   * y represents the vertical height of histogram
   * largest_qty represents the wordlength that occurs most frequently, which
   *    is used to determine what y should be
   *
   * */
  printf("\n");
  for(y = 0; y < largest_qty; ++y) {
    for(x = 0; x < 10; ++x) {
      if ( length_frequency[x] > 0 ) {
        printf("||\t");
        length_frequency[x]--;
      } else {
        printf("\t");
      }
    }
    printf("\n");
  }

  // Print Labels at bottom of histogram
  for(x = 0; x < 10; ++x)
    printf("%d\t ",x);
  printf("\n");
}
