/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 2
* Programming Assignment: Lab 3
* Date: September 13th, 2022
* Description: Calculate your body mass index (BMI).
*******************************************************************************************/

/*
	Interesting note about guard headers, I learned from this Stack Overflow post that
	NASA's Goddard Space Flight Center maintains a rule set for header files that states
	they must be:
	- Self Contained: All needed types are defined, and includes needed relevant headers
	- Idempotent: In other words, if it gets called twice, it won't break anything
	- Minimal: Doesn't include unnecessary code for it's particular outcomes.

	SO Link: https://stackoverflow.com/questions/1804486/should-i-use-include-in-headers
*/

// Header guard to ensure that our code is only included once by the compiler
#ifndef BMI_H_

#define BMI_H_
#define _CRT_SECURE_NO_WARNINGS // Suppress scanf memory security warnings

#include <stdio.h> // Include our standard functions for interacting with the IO stream
#include <math.h> // Used to get access to pow function

// The following are the custom functions to solve the problem of calculating BMI

/*
   Function: get_weight(void)
   Description: Asks the user for their weight in pounds
   Input Parameters: None
   Returns: The users weight in pounds
   Precondition: The stdio library has been included
   Postconditions: The users weight has been returned
*/
double get_weight(void);

/*
   Function: get_height(void)
   Description: Asks the user for their height in feet
   Input Parameters: None
   Returns: The users height in feet
   Precondition: The stdio library has been included
   Postconditions: The users height has been returned
*/
double get_height(void);

/*
   Function: convert_feet_to_inches(double height_in_feet)
   Description: Converts imperial feet to inches
   Input Parameters: Height in feet
   Returns: Inches as a double
   Precondition: The actual parameter is not null
   Postconditions: Feet has been converted to inches
*/
double convert_feet_to_inches(double height_in_feet);

/*
   Function: calculate_bmi(double weight_in_pounds, double height_in_feet)
   Description: Calculates Body Mass Index from the given weight and height
   Input Parameters: Weight in pounds as a double, Height in feet as a double
   Returns: A BMI score calculated from the actual parameters
   Precondition: Weight and Height were already gathered
   Postconditions: A BMI score was returned
*/
double calculate_bmi(double weight_in_pounds, double height_in_feet);

/*
   Function: display_bmi_scale(void)
   Description: Prints the BMI classification scale
   Input Parameters: None
   Returns: None
   Precondition: The stdio library has been included
   Postconditions: The BMI scale has been printed to the console
*/
void display_bmi_scale(void);

/*
   Function: display_bmi(double bmi)
   Description: Prints the users BMI score
   Input Parameters: The calculated BMI score
   Returns: None
   Precondition: The stdio library has been included
   Postconditions: The inputted BMI score has been printed to console
*/
void display_bmi(double bmi);

#endif
