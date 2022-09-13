/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 2
* Programming Assignment: Lab 3
* Date: September 13th, 2022
* Description: Calculate your body mass index (BMI).
*******************************************************************************************/

#include "bmi.h"

/*
   Function: get_weight(void)
   Description: Asks the user for their weight in pounds
   Input Parameters: None
   Returns: The users weight in pounds
   Precondition: The stdio library has been included
   Postconditions: The users weight has been returned
*/
double get_weight() {
	double weight = 0.0;
	printf("Please enter your weight in pounds: ");
	scanf(" %lf", &weight);
	return weight;
}

/*
   Function: get_height(void)
   Description: Asks the user for their height in feet
   Input Parameters: None
   Returns: The users height in feet
   Precondition: The stdio library has been included
   Postconditions: The users height has been returned
*/
double get_height() {
	double height = 0.0;
	printf("Please enter your height in feet: ");
	scanf(" %lf", &height);
	return height;
}

/*
   Function: convert_feet_to_inches(double height_in_feet)
   Description: Converts imperial feet to inches
   Input Parameters: Height in feet
   Returns: Inches as a double
   Precondition: The actual parameter is not null
   Postconditions: Feet has been converted to inches
*/
double convert_feet_to_inches(double height_in_feet) {
	// A double is returned here even though we are multiplying by in int
	// because C promotes the result of this operation to a double because
	// height_in_feet is of the type double.
	return height_in_feet * 12;
}

/*
   Function: calculate_bmi(double weight_in_pounds, double height_in_feet)
   Description: Calculates Body Mass Index from the given weight and height
   Input Parameters: Weight in pounds as a double, Height in feet as a double
   Returns: A BMI score calculated from the actual parameters
   Precondition: Weight and Height were already gathered
   Postconditions: A BMI score was returned
*/
double calculate_bmi(double weight_in_pounds, double height_in_feet) {
	// Formula requires height in inches, so we convert it from feet to inches first!
	double height_in_inches = convert_feet_to_inches(height_in_feet);
	return (weight_in_pounds / pow(height_in_inches, 2)) * 703;
}

/*
   Function: display_bmi_scale(void)
   Description: Prints the BMI classification scale
   Input Parameters: None
   Returns: None
   Precondition: The stdio library has been included
   Postconditions: The BMI scale has been printed to the console
*/
void display_bmi_scale() {
	printf("\nBMI Scale:\n");
	printf("BMI of less than 18 indicates you are underweight\n");
	printf("BMI >= 18 and < 25 means you are at a healthy weight\n");
	printf("BMI >= 25 and < 30 means you are overweight\n");
	printf("BMI > 30 indicates obesity\n\n");
}

/*
   Function: display_bmi(double bmi)
   Description: Prints the users BMI score
   Input Parameters: The calculated BMI score
   Returns: None
   Precondition: The stdio library has been included
   Postconditions: The inputted BMI score has been printed to console
*/
void display_bmi(double bmi) {
	printf("Your BMI is %.2lf", bmi); // Truncate the score to 2 decimal places for brevity
}
