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
		read_integer(records); // Coordinates to the student Id in the stream
		GPAs[i] = read_double(records); // The current student's GPA
		levels[i] = read_integer(records); // The current student's class standing
		ages[i] = read_double(records); // The current student's age
	}

	// Calculate the sum of GPAs

	// Calculate the sum of the class standings

	// Calculate the sum of ages

	// Calculate the mean of GPAs and save the result

	// Calculate the mean of class standing and save the result

	// Calculate the mean of ages and save the result

	// Calculate the deviation of each GPA from the mean

	// Calculate the variance of GPAs

	// Calculate the standard deviation of the GPAs and save the result

	// Find the min of the GPAs and save the result

	// Find the max of the GPAs and save the result

	// Close the files because we're done with them
	fclose(records);
	fclose(results);

	// Tell the system the program executed successfully
	return 0;
}
