/*******************************************************************************************
* Programmer: Benjamin Swanzey
* Class: CptS 121, Fall 2022; Lab Section 2
* Programming Assignment: PA2
* Date: September 7th, 2022
* Description: A program that evaluates various equations provided.
*******************************************************************************************/

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
#include "equations.h"

struct Resistors {
	int R1;
	int R2;
	int R3;
};

// Precondition: the file must be open
struct Resistors read_resistance(FILE *input) {
	struct Resistors r = { 0, 0 ,0 };
	fscanf(input, " %d%d%d", &r.R1, &r.R2, &r.R3);
	return r;
}

int main() {

	FILE* infile = fopen("HiMom.txt", 'r'); // File name is relative to this project file
	struct Resistors r = read_resistance(infile);
	fclose(infile);
	int R1 = r.R1, R2 = r.R2, R3 = r.R3;

	printf("Enter 3 integers to calculate series resistance: ");
	//int R1 = 0, R2 = 0, R3 = 0;
	//scanf(" %d%d%d", &R1, &R2, &R3);
	int series_resistance = calculate_series_resistance(R1, R2, R3);
	printf("Series Resistance %d + %d + %d = %d", R1, R2, R3, series_resistance);

	return 0;
}
