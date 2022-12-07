/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA8
* Date: December 6th, 2022
* Description: For this assignment you will be required to write functions which solve various problems.
*******************************************************************************************/

#include "alg.h"

int main() {

	char source[] = "dogs.";
	char sink[100] = "I like ";

	char* result = my_str_n_cat(source, sink, 5);

	printf("Result: %s\n", result);

	// Tell the system the program executed successfully
	return 0;
}
