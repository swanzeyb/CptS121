/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA8
* Date: December 6th, 2022
* Description: For this assignment you will be required to write functions which solve various problems.
*******************************************************************************************/

#include "alg.h"

char* my_str_n_cat(char* source, char* sink, int n) {
  char* start = sink;

  // Find the end of the destination string
  while (*sink != '\0') {
    sink++;
  }

  // Copy at max 'n' items to destination
  for (int i = 0; i < n; i++) {
    // Check to see if char to copy is null
    if (*source == '\0') break;

    // Copy the value to destination
    *sink = *source;

    // Iterate source and destination
    source++;
    sink++;
  }

  return start;
}

int binary_search(int nums[], int length, int target) {
  int found = 0, index = 0, left = 0, right = length, mid = length / 2;

  while (found == 0 && left < length) {

  }

  return found;
}
