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
  int right = length, mid = length / 2;
  int found = 0, index = -1, left = 0;

  while (found == 0 && left <= right) {
    // Calc midpoint
    mid = (left + right) / 2;

    // Check if target is at midpoint
    if (nums[mid] == target) {
      found = 1;
      index = mid;
    }

    // If the target is less than midpoint
    if (target < nums[index]) {
      right = mid - 1;
    } else if (target > nums[index]) {
      left = mid + 1;
    }
  }

  return index;
}

void bubble_sort(char** strings, int length) {
  int u = length;
  int c = 0;
  while (u > 0) {
    c = 1;
    while (c < u) {
      if (*strings[c] < *strings[c -1]) {
        char* tmp = strings[c];
        strings[c] = strings[c - 1];
        strings[c - 1] = tmp;
      }
      c++;
    }
    u--;
  }
}

int is_palindrome(char* string, int length) {
  int start_index = 0;
  int end_index = length - 1;
  char first_value = string[start_index];
  char last_value = string[end_index];

  // Determine offset
  int offset = end_index;
  char determine_value = last_value;
  while (determine_value != '\0') {
    determine_value = string[++offset];
  }
  offset -= length;
  start_index += offset;
  first_value = string[start_index];

  // Ignore whitespace
  while (first_value == ' ') {
    first_value = string[++start_index];
  }
  while (last_value == ' ') {
    last_value = string[--end_index];
  }

  if (first_value == last_value) {
    if (start_index == end_index) {
      return 1;
    } else {
      return is_palindrome(string, --length);
    }
  }

  return 0;
}

unsigned int sum_primes(unsigned int to, unsigned int sum) {
  // If the current number is prime, add it to the sum
  if (to % 2 != 0) {
    sum += to;
  }

  if (to <= 2) {
    return sum;
  } else {
    // Decrement until to reaches 2
    return sum_primes(--to, sum);
  }
}

// int get_occurence_key() {}

Occurrences* maximum_occurences(char* string, Occurrences occurrences[], double* frequeny, char* most_occured) {
  double str_len = strlen(string);
  Occurrences* high_occurrences = &occurrences[0];

  for (int i = 0; i < str_len; i++) {
    char curr = string[i];
    Occurrences* record = NULL;

    // Make an ordered key
    int key = 0;
    if (curr >= '0' && curr <= '9') {
      key = curr - '0';
    } else if (curr >= 'A' && curr <= 'Z') {
      key = 10 + (curr - 'A');
    } else if (curr >= 'a' && curr <= 'z') {
      key = 36 + (curr - 'a');
    } else if (curr == ' ') {
      key = 63;
    }
    record = &occurrences[key];
    
    // Update stats
    record->num_occurrences += 1;
    record->frequency = record->num_occurrences / str_len;

    // Keep track of highest occurrence
    if (record->num_occurrences > high_occurrences->num_occurrences) {
      high_occurrences = record;
      *most_occured = curr;
      *frequeny = high_occurrences->frequency;
    }
  }

  return high_occurrences;
}
