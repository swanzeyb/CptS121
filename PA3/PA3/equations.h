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
   Function: calculate_series_resistance(int r1, int r2, int r3)
   Description: Calculates the resistance of three reistors in series.
   Input Parameters: The resistance value of each resistor.
   Returns: The series resistance.
   Precondition: The resistance of the three resistors is known.
   Postconditions: The series resistance has been returned.
*/
double read_double(FILE *infile);
int read_integer(FILE *infile);
double calculate_sum(double num1, double num2, double num3, double num4, double num5);
double calculate_mean(double sum, int num);
double calculate_deviation(double num, double mean);
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int num);
double calculate_standard_deviation(double variance);
double find_max(double num1, double num2, double num3, double num4, double num5);
double find_min(double num1, double num2, double num3, double num4, double num5);
void print_double(FILE *outfile, double num);

#endif
