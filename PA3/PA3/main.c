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
	FILE* infile = fopen("input.dat", "r");
	// Open the out file for saving results
	FILE* outfile = fopen("output.dat", "w");

	

	// Close the files because we're done with them
	fclose(infile);
	fclose(outfile);

	// Tell the system the program executed successfully
	return 0;
}
