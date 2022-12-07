/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA8
* Date: December 6th, 2022
* Description: For this assignment you will be required to write functions which solve various problems.
*******************************************************************************************/

#include "alg.h"

int main() {

	char* test = "onomonopia";

	Occurrences occurrences[64] = { { 0, 0.0 } };
	char* most_used = malloc(sizeof(char));
	double* used_frequency = malloc(sizeof(double));

	Occurrences* result = maximum_occurences(test, occurrences, used_frequency, most_used);

	// Tell the system the program executed successfully
	return 0;
}
