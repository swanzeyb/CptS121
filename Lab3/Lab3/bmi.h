
// Header guard to ensure that our code is only included once by the compiler
#ifndef BMI_H_

#define BMI_H_
#define CRT_SECURE_NO_WARNINGS // Supress scanf memory security warnings

#include <stdio.h> // Include our standard functions for interacting with the IO stream.

// The following our the custom functions to solve the problem of calculating BMI

double get_weight();
double get_height();
double convert_feet_to_inches(double height_in_feet);


#endif
