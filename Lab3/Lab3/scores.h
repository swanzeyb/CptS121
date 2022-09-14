/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 2
* Programming Assignment: Lab 3
* Date: September 13th, 2022
* Description: Prompt the user for the scores received on two exams, two labs, and two projects and then compute separate averages for the exams, labs, and projects.
*******************************************************************************************/

#ifndef SCORES_H_

#define SCORES_H_
#define _CRT_SECURE_NO_WARNINGS // Suppress scanf memory security warnings

#include <stdio.h> // Include our standard functions for interacting with the IO stream

/*
   Function: get_score(char name[], int assignment_num)
   Description: Asks the user for their score for a certain assignment.
   Input Parameters: The name of the assignment and which assignment (EX: Lab, 2)
   Returns: The user's assignment score.
   Precondition: The stdio library has been included.
   Postconditions: The score for the given assignment has been returned.
*/
int get_score(char name[], int assignment_num);

/*
   Function: calculate_average(int num1, int num2)
   Description: Calculates the average of two numbers.
   Input Parameters: The two numbers to average together.
   Returns: The average of the two number inputs.
   Precondition: Two numbers to be averaged were gathered.
   Postconditions: The average of the numbers were returned.
*/
double calculate_average(int num1, int num2);

/*
   Function: calculate_weighted_average(double score1, double score2, double score3, double weight1, double weight2, double weight3)
   Description: Calulates the weighted average of three scores.
   Input Parameters: First three params are the scores, the last 3 params are the scores respective weights.
   Returns: The weighted average.
   Precondition: The scores and score weights are known.
   Postconditions: The weighted average has been returned.
*/
double calculate_weighted_average(double score1, double score2, double score3, double weight1, double weight2, double weight3);

/*
   Function: display_weighted_average(double weighted_average)
   Description: Prints the weighted average of the users scores.
   Input Parameters: The user's weighted average of their assignments.
   Returns: None.
   Precondition: The user's assignments weighted average has been calculated.
   Postconditions: The user's assignments weighted average has been printed to the console.
*/
void display_weighted_average(double weighted_average);

#endif
