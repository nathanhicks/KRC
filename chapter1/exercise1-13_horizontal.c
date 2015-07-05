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

#define INSIDE 1
#define OUTSIDE 0

main()
{
  int c,i,j,wl;
  c = i = j = wl = 0;
  int histogram[10];

  for(i = 0; i < 10; ++i)
    histogram[i] = 0;

  /* Count wordlength */
  while ((c = getchar()) != EOF) {
    if((c == ' ') || (c == '\t') || (c == '\n')) { 
      histogram[wl] += 1;
      wl = 0;
    } else {
      ++wl;
    }
  }

  /* Print histogram based on wordlength of each word in stdin */
  for(i = 0; i < 10; ++i) {
    printf("%d ",i);
    for(j = 0; j < histogram[i]; ++j)
      printf("=");
    printf("\n");
  }
}
