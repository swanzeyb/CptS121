/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA3
* Date: September 19th, 2022
* Description: A program that processes numbers, corresponding to student records read in from a file,
*              and writes the required results to an output file.
*******************************************************************************************/

// Header guard to ensure that our code is only included once by the compiler
#ifndef EQUATIONS_H

// Define contstants
#define EQUATIONS_H
#define _CRT_SECURE_NO_WARNINGS // To ignore scanf warning

// The required libraries
#include <stdio.h> // Include our standard functions for interacting with the IO stream
#include <math.h> // Used to get access to pow, sqrt, fmod function

/*
   Function: read_double(FILE *infile)
   Description: Reads the next double for a given file.
   Input Parameters: The file to read from.
   Returns: The double found in the file stream.
   Precondition: The file is open in read mode.
   Postconditions: A found double has been returned.
*/
double read_double(FILE *infile);

/*
   Function: read_integer(FILE *infile)
   Description: Reads the next integer for a given file.
   Input Parameters: The file to read from.
   Returns: The integer found in the file stream.
   Precondition: The file is open in read more.
   Postconditions: A found integer has been returned.
*/
int read_integer(FILE *infile);

/*
   Function: calculate_sum(double num1, double num2, double num3, double num4, double num5)
   Description: Adds all 5 input doubles together.
   Input Parameters: 5 double values.
   Returns: The sum of all input doubles.
   Precondition: Have 5 doubles to add together.
   Postconditions: The sum has been returned.
*/
double calculate_sum(double num1, double num2, double num3, double num4, double num5);

/*
   Function: calculate_mean(double sum, int num)
   Description: Finds the average of a sum and the number of items.
   Input Parameters: The sum and the number of items in the avg.
   Returns: The average of the items.
   Precondition: The number of items are known.
   Postconditions: The average has been returned.
*/
double calculate_mean(double sum, int num);

/*
   Function: calculate_deviation(double num, double mean)
   Description: Finds the deviation of the number from the mean.
   Input Parameters: A number to find the deviation of and the mean.
   Returns: The number's deviation from mean.
   Precondition: The mean of the values has been found
   Postconditions: The number's deviation has been returned.
*/
double calculate_deviation(double num, double mean);

/*
   Function: calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int num)
   Description: Calculates the variance of 5 input numbers.
   Input Parameters: The 5 values to find the variance of.
   Returns: The variance between the items.
   Precondition: The variance of the 5 values is known.
   Postconditions: The variance has been returned.
*/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int num);

/*
   Function: calculate_standard_deviation(double variance)
   Description: Calculates the standard deviation given a variance.
   Input Parameters: The variance between values to calculate deviation of.
   Returns: The standard variation between the values.
   Precondition: The variance has been calculated.
   Postconditions: The standard deviation has been returned.
*/
double calculate_standard_deviation(double variance);

/*
   Function: find_max(double num1, double num2, double num3, double num4, double num5)
   Description: Finds the largest number given 5 values.
   Input Parameters: 5 numbers to search through.
   Returns: The largest number of the input values.
   Precondition: There are 5 values to compare.
   Postconditions: The largest number has been returned.
*/
double find_max(double num1, double num2, double num3, double num4, double num5);

/*
   Function: find_min(double num1, double num2, double num3, double num4, double num5)
   Description: Finds the smallest number given 5 values.
   Input Parameters: 5 numbers to search through.
   Returns: The smallest number of the input values.
   Precondition: There are 5 values to compare.
   Postconditions: The smallest number has been returned.
*/
double find_min(double num1, double num2, double num3, double num4, double num5);

/*
   Function: print_double(FILE *outfile, double num)
   Description: Prints a double to a file.
   Input Parameters: The file to write to, and the number to write.
   Returns: Nothing.
   Precondition: The file is open is write mode.
   Postconditions: A number has been written to the file.
*/
void print_double(FILE *outfile, double num);

#endif
