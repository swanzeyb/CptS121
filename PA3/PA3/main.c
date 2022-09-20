/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA3
* Date: September 19th, 2022
* Description: A program that processes numbers, corresponding to student records read in from a file,
*              and writes the required results to an output file.
*******************************************************************************************/

#include "equations.h"

int main() {
	// Open the student records file
	FILE* records = fopen("input.dat", "r");
	// Open the out file for saving results
	FILE* results = fopen("output.dat", "w");

	// Use arrays to create a dictionary-like lookup for students
	double GPAs[5] = { 0.0 }; // Students GPAs
	int levels[5] = { 0 }; // Students Class Standings
	double ages[5] = { 0.0 }; // Students Ages

	// We know that the file only has 5 student entries, so lets iterate over them.
	// Oh side note, we could try counting the amount of blank lines to
	// figure out how many entries are in the file.
	for (int i = 0; i < 5; i += 1) {
		// We don't use the student Id for anything in this progarm, so it's not being assigned here
		// But we do need to advance the read stream, so it's being called.
		read_integer(records); // Coordinates to the student Id in the stream
		GPAs[i] = read_double(records); // The current student's GPA
		levels[i] = read_integer(records); // The current student's class standing
		ages[i] = read_double(records); // The current student's age
	}

	// Calculate the sum of GPAs
	double gpa_sum = calculate_sum(GPAs[0], GPAs[1], GPAs[2], GPAs[3], GPAs[4]);

	// Calculate the sum of the class standings
	int level_sum = calculate_sum(levels[0], levels[1], levels[2], levels[3], levels[4]);

	// Calculate the sum of ages
	double age_sum = calculate_sum(ages[0], ages[1], ages[2], ages[3], ages[4]);

	// Calculate the mean of GPAs and save the result
	double gpa_mean = calculate_mean(gpa_sum, 5);
	print_double(results, gpa_mean);

	// Calculate the mean of class standing and save the result
	double level_mean = calculate_mean(level_sum, 5);
	print_double(results, level_mean);

	// Calculate the mean of ages and save the result
	double age_mean = calculate_mean(age_sum, 5);
	print_double(results, age_mean);

	// Calculate the deviation of each GPA from the mean
	double deviation[5] = { 0.0 }; // Initiate a new array to hold each deviation
	for (int i = 0; i < 5; i += 1) {
		// Calculate the deviation from the mean for each student's GPA
		deviation[i] = calculate_deviation(GPAs[i], gpa_mean); // This is called 5 times
	}

	// Calculate the variance of GPAs
	double variance = calculate_variance(deviation[0], deviation[1], deviation[2], deviation[3], deviation[4], 5);

	// Calculate the standard deviation of the GPAs and save the result
	double standard_deviation = calculate_standard_deviation(variance);
	print_double(results, standard_deviation);

	// Find the min of the GPAs and save the result
	double gpa_min = find_min(GPAs[0], GPAs[1], GPAs[2], GPAs[3], GPAs[4]);
	print_double(results, gpa_min);

	// Find the max of the GPAs and save the result
	double gpa_max = find_max(GPAs[0], GPAs[1], GPAs[2], GPAs[3], GPAs[4]);
	print_double(results, gpa_max);

	// Close the files because we're done with them
	fclose(records);
	fclose(results);

	// Tell the system the program executed successfully
	return 0;
}
