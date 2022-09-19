/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA3
* Date: September 19th, 2022
* Description: A program that processes numbers, corresponding to student records read in from a file,
*              and writes the required results to an output file.
*******************************************************************************************/

#include "equations.h"

double read_double(FILE *infile) {
  double value = 0.0;
  fscanf(infile, "%lf", &value);
  return value;
}

int read_integer(FILE *infile) {
  int value = 0.0;
  fscanf(infile, "%d", &value);
  return value;
}

double calculate_sum(double num1, double num2, double num3, double num4, double num5) {
  return num1 + num2 + num3 + num4 + num5;
}

double calculate_mean(double sum, int num) {
  double mean = sum / num;
  // If the number is negative or equals zero, return -1.0
  if (mean <= 0.0) {
    return -1.0;
  } else {
    return mean;
  }
}

double calculate_deviation(double num, double mean) {
  return num - mean;
}

double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int num) {
  return (pow(deviation1, 2) + pow(deviation1, 2) + pow(deviation1, 2) + pow(deviation1, 2) + pow(deviation1, 2)) / (double)num;
}

double calculate_standard_deviation(double variance) {
  return sqrt(variance);
}

double find_max(double num1, double num2, double num3, double num4, double num5) {
  double needle = 0.0;
  double haystack[] = { num1, num2, num3, num4, num5 };
  for (int i = 0; i < 5; i += 1) {
    if (haystack[i] > needle) {
      needle = haystack[i];
    }
  }
  return needle;
}

double find_min(double num1, double num2, double num3, double num4, double num5) {
  double needle = num1;
  double haystack[] = { num1, num2, num3, num4, num5 };
  for (int i = 0; i < 5; i += 1) {
    if (haystack[i] < needle) {
      needle = haystack[i];
    }
  }
  return needle;
}

void print_double(FILE *outfile, double num) {
  fprintf(outfile, "%lf", num);
}
