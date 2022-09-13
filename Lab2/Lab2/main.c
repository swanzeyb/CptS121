/*******************************************************************************************
* Programmer: Benjamin Swanzey
* Class: CptS 121, Fall 2022; Lab Section 2
* Programming Assignment: Lab2
* Date: September 6th, 2022
* Description: Lab 2
*******************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void partA(void) {
	double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;

	// Prompt the user for the coordinates of the two points
	printf("Enter the first point x y: ");
	scanf(" %lf%lf", &x1, &y1);
	printf("Enter the second point x y: ");
	scanf(" %lf%lf", &x2, &y2);

	// Compute the slope of the line between those two points
	double slope = (y2 - y1) / (x2 - x1);

	// Compute the coordinates of the midpoint of the line segment between the two points by averaging the two x coordinates and the two y coordinates
	double midpoint_x = (x1 + x2) / 2;
	double midpoint_y = (y1 + y2) / 2;

	// Compute the slope of the perpendicular bisector by taking the negative reciprocal of the slope of the line segment
	double m_perp_bisector = -1 * (1 / slope);
	printf("Slope of perpendicular bisctor: %.2lf\n", m_perp_bisector);

	// Compute the y intercept of the perpendicular bisector(you now have the slope m of the bisector and a point(xmid, ymid) on the bisector, so the y intercept is ymid - m xmid)
	double y_intercept_perp_bisector = midpoint_y - (m_perp_bisector * midpoint_x);
	printf("Y intercept of perpendicular bisctor: %.2lf\n", y_intercept_perp_bisector);

	// Output the labels of the original two points, and output in y = mx + b format the equation of the perpendicular bisector.
	printf("Original points Point 1: (%.2lf, %.2lf), Point 2: (%.2lf, %.2lf)\n", x1, y1, x2, y2);
	printf("y=mx+b of the perpendicular bisector of these points: y=%.2lfx+%.2lf\n", m_perp_bisector, y_intercept_perp_bisector);
}

// Write a program to calculate your body mass index(BMI).
void partB(void) {

	// Prompt the user for weight in pounds and height in feet
	int lb = 0, ft = 0, in = 0;
	printf("Please enter your weight in pounds: ");
	scanf(" %d", &lb);
	printf("Please enter your height in feet and inches: ");
	scanf(" %d%d", &ft, &in);

	// Compute bmi from inputs
	int height_in = (ft * 12) + in;
	double bmi = (lb / pow(height_in, 2)) * 703;

	// Print the resulting BMI
	printf("BMI Scale:\n");
	printf("BMI of less than 18 indicates you are underweight\n");
	printf("BMI >= 18 and < 25 means you are at a healthy weight\n");
	printf("BMI >= 25 and < 30 means you are overweight\n");
	printf("BMI > 30 indicates obesity\n");
	printf("Your BMI is: %.2lf: ", bmi);
}

int main(void) {
	partA();
	partB();
	return 0;
}
