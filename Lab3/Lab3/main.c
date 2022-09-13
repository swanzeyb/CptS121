/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 2
* Programming Assignment: Lab 3
* Date: September 13th, 2022
* Description: Solve 3 problems
*			   -  Calculate your body mass index (BMI).
*			   -  Compute the duration of a projectile's flight and its height above the ground when it reaches the target.
*			   -  Prompt the user for the scores received on two exams, two labs, and two projects and then compute separate averages for the exams, labs, and project.
*******************************************************************************************/

#include "bmi.h"

int main() {
	// Calculate your body mass index (BMI).
	
	// Ask the user for their weight and height
	double weight = get_weight();
	double height = get_height();
	// Then calculate their BMI score based on their input
	double bmi = calculate_bmi(weight, height);

	// Give the user context for BMI scores before showing them their score
	display_bmi_scale();

	// Then show the user their BMI score
	display_bmi(bmi);

	// Compute the duration of a projectile's flight and its height above the ground when it reaches the target.

	// Tell the system the program executed successfully
	return 0;
}
