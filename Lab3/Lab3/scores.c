/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 2
* Programming Assignment: Lab 3
* Date: September 13th, 2022
* Description: Prompt the user for the scores received on two exams, two labs, and two projects and then compute separate averages for the exams, labs, and projects.
*******************************************************************************************/

#include "scores.h"

int get_score(char name[], int assignment_num) {
	int score = 0;
	printf("Please enter the score for %s %d: ", name, assignment_num);
	scanf(" %d", &score);
	return score;
}

double calculate_average(int num1, int num2) {
	return (num1 + num2) / 2;
}

double calculate_weighted_average(double score1, double score2, double score3, double weight1, double weight2, double weight3) {
	return (score1 * weight1) + (score2 * weight2) + (score3 * weight3);
}

void display_weighted_average(double weighted_average) {
	printf("\nThe weigthed average of the scores is: %.1lf%%\n", weighted_average); // The percent sign must be escaped here to print the percent sign because it is a format character
}
