/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA2
* Date: September 7th, 2022
* Description: A program that performs various equations given user inputs.
*******************************************************************************************/

// Header guard to ensure that our code is only included once by the compiler
#ifndef EQUATIONS_H

// Define contstants
#define EQUATIONS_H
#define _CRT_SECURE_NO_WARNINGS // To ignore scanf warning
#define PI 3.14

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
int calculate_series_resistance(int r1, int r2, int r3);

/*
   Function: calculate_total_sales_tax(double sales_tax_rate, double item_cost)
   Description: Calulates the sales tax for the cost of an item and it's tax rate.
   Input Parameters: The sales tax rate as a decimal percentage and the item cost.
   Returns: The total sales tax for that item.
   Precondition: The sales tax rate and item cost is known.
   Postconditions: The sales tax has been returned.
*/
double calculate_total_sales_tax(double sales_tax_rate, double item_cost);

/*
   Function: calculate_volume_pyramid(double l, double w, double h)
   Description: Calulates the volume of a pyramid.
   Input Parameters: The length, width, and height of the pyramid.
   Returns: The volume of whatever unit of measure used for parameters, cubed.
   Precondition: The length, width, and height in the same unit of measure is known.
   Postconditions: The volume of the pyramid is returned.
*/
double calculate_volume_pyramid(double l, double w, double h);

/*
   Function: calculate_parallel_resistance(int r1, int r2, int r3)
   Description: Calculates the resistance of three reistors in parallel.
   Input Parameters: The resistance value of each resistor.
   Returns: The total parallel resistance.
   Precondition: The resistance of the three resistors is known.
   Postconditions: The parallel resistance has been returned.
*/
double calculate_parallel_resistance(int r1, int r2, int r3);

/*
   Function: encode_character(char plaintext_character, int shift_int)
   Description: Encodes a given character with a top secret equation and a shifting int.
   Input Parameters: The character to shift, and the shifting amount.
   Returns: The encoded character with the top secret formula.
   Precondition: Having a character to shift and the shift amount.
   Postconditions: The encoded character.
*/
char encode_character(char plaintext_character, int shift_int);

/*
   Function: calculate_distance(double x1, double y1, double x2, double y2)
   Description: Calculates the distance between two points using standard distance formula.
   Input Parameters: Point 1 x and y, and Point 2 x and y.
   Returns: The distance between the two points.
   Precondition: Having two points to calc the distance between.
   Postconditions: The distance between the two points.
*/
double calculate_distance(double x1, double y1, double x2, double y2);

/*
   Function: calculate_general_equation(double x, double y, double z, int a)
   Description: An arbitrary equation that does cool things.
   Input Parameters: Float numbers x, y, z, and a.
   Returns: The result of an equation.
   Precondition: Having 4 float values to input.
   Postconditions: The result of the equation.
*/
double calculate_general_equation(double x, double y, double z, int a);

#endif
