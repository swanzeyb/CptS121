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
} Occurrences;

char* my_str_n_cat(char* source, char* sink, int n);
int binary_search(int nums[], int length, int target);
void bubble_sort(char** strings, int length);
int is_palindrome(char* string, int length);
unsigned int sum_primes(unsigned int to, unsigned int sum);
Occurrences* maximum_occurences(char* string, Occurrences occurrences[], double* frequeny, char* most_occured);

#endif
