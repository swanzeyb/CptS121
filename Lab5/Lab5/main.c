/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: Lab 5
* Date: September 27th, 2022
*******************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS // To ignore scanf warning

// The required libraries
#include <stdio.h> // Include our standard functions for interacting with the IO stream
#include <math.h>

// void partA() {
// 	FILE* salaries = fopen("salaries.txt", "r");

// 	double sum = 0.0;
// 	while (!feof(salaries)) {
// 		double payment = 0.0;
// 		fscanf(salaries, "%lf", &payment);
// 		sum += payment;
// 	}

// 	printf("Sum of payments: %.2lf\n", sum);
// 	char bracket = 'm';

// 	if (sum < 15000) {
// 		bracket = 'l';
// 	} else if (sum > 200000) {
// 		bracket = 'h';
// 	}

// 	printf("Tax bracket: %c\n", bracket);

// 	// Close the files because we're done with them
// 	fclose(salaries);
// }

int largest_digit(int to_test) {
	int largest = 0;

	while(to_test > 0.9) {
		int modulo_of = to_test % 10;

		if (modulo_of > largest) {
			largest = modulo_of;
		}

		to_test = to_test / 10;
	}

	return largest;
}

int main() {
	// partA();

	int a = largest_digit(3597);
	int b = largest_digit(671);

	printf("\n%d\n\n%d\n", a, b);

	// Tell the system the program executed successfully
	return 0;
}
