/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 2
* Programming Assignment: Lab 3
* Date: September 13th, 2022
* Description: Solve 3 problems
*			   -  Calculate your body mass index (BMI).
*			   -  Compute the duration of a projectile's flight and its height above the ground when it reaches a target distance.
*			   -  Prompt the user for the scores received on two exams, two labs, and two projects and then compute separate averages for the exams, labs, and projects.
*******************************************************************************************/

#include "bmi.h"
#include "projectile.h"
#include "scores.h"

int main() {
	// --- Calculate your body mass index (BMI). ---
	printf("*** Calculate your body mass index (BMI) ***\n\n");
	
	// Ask the user for their weight and height
	double weight = get_weight();
	double height = get_height();
	// Then calculate their BMI score based on their input
	double bmi = calculate_bmi(weight, height);

	// Give the user context for BMI scores before showing them their score
	display_bmi_scale();

	// Then show the user their BMI score
	display_bmi(bmi);

	// --- Compute the duration of a projectile's flight and its height above the ground when it reaches the target. ---
	printf("\n\n*** Compute the duration of a projectile's flight and its height above the ground when it reaches a target distance ***\n\n");
	
	// Ask the user the inputs to the duration and height equations
	double theta = get_theta();
	double distance = get_distance();
	double velocity = get_velocity();

	// Calculate the flight duration given the inputs
	double duration = calculate_flight_duration(distance, velocity, theta);

	// Calculate the height of the projectile at time of impact
	// Height has already been delcared, but since it is of the same type,
	// we can just assign height to the result of the calculation without needing
	// a new variable.
	height = calculate_projectile_height(velocity, theta, duration);

	// Now show the user the duration of the flight
	display_flight_duration(duration);

	// And then show the height at time of impact
	display_projectile_height(height);

	// --- Prompt the user for the scores received on two exams, two labs, and two projects and then compute separate averages for the exams, labs, and project. ---
	printf("\n\n*** Compute the averages for two exams, labs, and projects ***\n\n");

	// Ask the user for their exams, labs, and projects
	int exam1_score = get_score("exam", 1);
	int exam2_score = get_score("exam", 2);
	int lab1_score = get_score("lab", 1);
	int lab2_score = get_score("lab", 2);
	int project1_score = get_score("project", 1);
	int project2_score = get_score("project", 2);

	// Calculate the average of each assignment depending on their assignment type
	double exam_avg = calculate_average(exam1_score, exam2_score);
	double lab_avg = calculate_average(lab1_score, lab2_score);
	double project_avg = calculate_average(project1_score, project2_score);

	// Calculate the weighted average aftering calculating individual assignment averages
	double weighted_avg = calculate_weighted_average(exam_avg, lab_avg, project_avg, 0.3, 0.05, 0.15);

	// These scores only account for 50% of the grade, so this puts it in terms of out of 100%
	weighted_avg = (weighted_avg / 50.0) * 100;

	// Display to the user their weighted average
	display_weighted_average(weighted_avg);

	// Tell the system the program executed successfully
	return 0;
}
