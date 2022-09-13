/*******************************************************************************************
* Programmer: Benjamin Swanzey
* Class: CptS 121, Fall 2022; Lab Section 2
* Programming Assignment: PA1
* Date: August 31st, 2022
* Description: A program that evaluates various equations provided.
*******************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define PI 3.14

int main(void) {	
	// Total series resistance: series_resistance = R1 + R2 + R3, for 3 resistors. R1, R2, and R3 are integers.
	int R1 = 0, R2 = 0, R3 = 0;
	printf("Please enter the resistance of 3 resistors for series resistance: ");
	scanf(" %d%d%d", &R1, &R2, &R3);
	double series_resistance = R1 + R2 + R3;
	printf("Total series resistance: %.2lf\n", series_resistance); // Limit the decimal place to hundreths by using %.2lf

	// Sales tax: total_sales_tax = sales_tax_rate * item_cost
	double sales_tax_rate = 0.0, item_cost = 0.0;
	printf("Please enter the sales tax rate and item cost: ");
	scanf(" %lf%lf", &sales_tax_rate, &item_cost); // using lf with scanf to get the tax as a percent decimal
	double total_sales_tax = sales_tax_rate * item_cost;
	printf("Sales tax: %.2lf\n", total_sales_tax);;

	// Volume of a right rectangular pyramid: volume_pyramid = (l * w * h) / 3, where l and w are the length and width of the base, respectively, and h is the height of the pyramid.
	double length = 0.0, width = 0.0, height = 0.0;
	printf("Please enter the length, width, and height of a pyramid: ");
	scanf(" %lf%lf%lf", &length, &width, &height);
	double volume_pyramid = (length * width * height) / 3;
	printf("Volume of a right rectangular pyramid: %.2lf\n", volume_pyramid);

	// Total parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3), for 3 resistors. R1, R2, and R3 are integers.
	R1 = 0, R2 = 0, R3 = 0; // Reset resistor values to 0 for next computation
	printf("Please enter the resistance of 3 resistors for parallel resistance: ");
	scanf(" %d%d%d", &R1, &R2, &R3);
	double parallel_resistance = 1 / (1 / (double)R1 + 1 / (double)R2 + 1 / (double)R3); // We cast the R values to double
																						 // to preserve the accuracy.
	printf("Total series resistance: %.2lf\n", parallel_resistance);

	// Character encoding: encoded_character = (plaintext_character – 'a') + 'A' – shift_int; shift_int is an integer
	char plaintext_character = '\0';
	int shift_int = 0;
	printf("Please enter a character to encode plus a shifting integer: ");
	scanf(" %c%d", &plaintext_character, &shift_int); // A space was added at the beginning of scanf 
													  // to flush the whitespaces and newline before
													  // reading the character to shift because scanf
													  // was adding the newling and space to the int val.
	char encoded_character = (plaintext_character - 'a') + 'A' - shift_int;
	printf("Encoded character: %c\n", encoded_character);

	// Distance between two points: distance = square root of ((x1 - x2)2 + (y1 - y2)2)
	double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
	printf("Calculate distance between two points,\n");
	printf("Please enter the first point x and y: ");
	scanf(" %lf%lf", &x1, &y1);
	printf("Please enter the second point x and y: ");
	scanf(" %lf%lf", &x2, &y2);
	double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); // Calculate using math.h helper functions
															   // to make the code more readable
	printf("Distance: %.2lf\n", distance);

	// General equation: y = y / (3/17)  - z + x / (a % 2) + PI
	double x = 0.0, y = 0.0, z = 0.0;
	int a = 0;
	printf("Find the result of a general equation,\n");
	printf("Please enter values for x, y, z, and a: ");
	scanf(" %lf%lf%lf%d", &x, &y, &z, &a);
	double general_eq = y / ((double)3 / (double)17) - z + x / fmod((double)a, 2) + PI;

	printf("General equation result: %.2lf\n", general_eq); // Show the user the result of the general eq

	return 0;
}