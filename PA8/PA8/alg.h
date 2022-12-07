/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA8
* Date: December 6th, 2022
* Description: For this assignment you will be required to write functions which solve various problems.
*******************************************************************************************/

// Header guard to ensure that our code is only included once by the compiler
#ifndef ALG_H

// Define contstants
#define ALG_H
#define _CRT_SECURE_NO_WARNINGS // To ignore scanf warning

// The required libraries
#include <stdio.h> // Include our standard functions for interacting with the IO stream
#include <stdlib.h> // Gives us access to system function
#include <time.h> // This gives access to time func used in srand
#include <stdbool.h> // I prefer bools over ints
#include <string.h> // atoi

typedef struct {
  int num_occurrences;
  double frequency;
} Occurrences; // This is not the best naming, should use _t convention

typedef struct {
  int index;
  bool found;
} binary_search_result_t;

// I want to support a bunch of different colors,
// and I found out that C supports enums so ima
// try them out.
typedef enum {
  COLOR_BLACK = 30,
  COLOR_RED = 31,
  COLOR_GREEN = 32,
  COLOR_YELLOW = 33,
  COLOR_BLUE = 34,
  COLOR_MAGENTA = 35,
  COLOR_CYAN = 36,
  COLOR_GRAY = 37,
  COLOR_CRIMSON = 38,
  COLOR_ALT_GRAY = 90,
  COLOR_ALT_RED = 91,
  COLOR_ALT_GREEN = 92,
  COLOR_ALT_YELLOW = 93,
  COLOR_ALT_BLUE = 94,
  COLOR_ALT_MAGENTA = 95,
  COLOR_ALT_CYAN = 96,
  COLOR_WHITE = 97,
  COLOR_BG_BLACK = 40,
  COLOR_BG_RED = 41,
  COLOR_BG_GREEN = 42,
  COLOR_BG_YELLOW = 43,
  COLOR_BG_BLUE = 44,
  COLOR_BG_MAGENTA = 45,
  COLOR_BG_CYAN = 46,
  COLOR_BG_WHITE = 47,
  COLOR_BG_CRIMSON = 48,
} Colors;

char* my_str_n_cat(char* source, char* sink, int n);
binary_search_result_t binary_search(int nums[], int length, int target);
void bubble_sort(char** strings, int length);
int is_palindrome(char* string, int length);
unsigned int sum_primes(unsigned int to, unsigned int sum);
Occurrences* maximum_occurences(char* string, Occurrences occurrences[], double* frequeny, char* most_occured);

#endif
