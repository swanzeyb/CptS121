/*******************************************************************************************
* Programmer: Benjamin Swanzey
* Class: CptS 121, Fall 2022; Lab Section 2
* Programming Assignment: PA2
* Date: September 7th, 2022
* Description: A program that evaluates various equations provided.
*******************************************************************************************/

#include <math.h>
#define PI 3.14

int calculate_series_resistance(int r1, int r2, int r3) {
	return r1 + r2 + r3;
}

double calculate_total_sales_tax(double sales_tax_rate, double item_cost) {
	return sales_tax_rate * item_cost;
}

double calculate_volume_pyramid(double l, double w, double h) {
	return (l * w * h) / 3;
}

// A function for calculating the total parallel resistance
double calculate_parallel_resistance(int r1, int r2, int r3) {
	return 1 / (1 / (double)r1 + 1 / (double)r2 + 1 / (double)r3);
}

// A function for the character encoding
char encode_character(char plaintext_character, int shift_int) {
	return (plaintext_character - 'a') + 'A' - shift_int;
}

// A function for calculating the distance between two points
double calculate_distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// A function for evaluating the general equation
double calculate_general_equation(double x, double y, double z, int a) {
	return y / ((double)3 / (double)17.0) - z + x / fmod((double)a, 2) + PI;
}
