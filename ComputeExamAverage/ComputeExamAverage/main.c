/*
	Author: benjamin.swanzey@wsu.edu
	Date: 8/29/22
	Course: CptS 121 Section 2
	Description: This program prompts the user for 3 exam scores,
				 computes the average of the scores, and displays
				 the result to the screen.
*/

#define _CRT_SECURE_NO_WARNINGS // goes above #include to ignore scanf warnings 
#include <stdio.h> // printf (), scanf ()

int main(void) { // starting point of execution
	int score1 = 0;
	int score2 = 0;
	int score3 = 0;
	int average = 0;

	// 1. Ask the user for exam score 1.
	printf("Enter excm score 1 as an integer: ");

	// 2. Get exam score 1.
	scanf("%d", &score1);

	// 3. Ask the user for exam score 2.
	printf("Enter exam score 2 as an integer: ");

	// 4. Get exam score 2.
	scanf("%d", &score2);

	// 5. Ask the user for exam score 3.
	printf("Enter exam score 3 as an integer: ");

	// 6. Get exam score 3.
	scanf("%d", &score3);

	// 7. Calculate exam score average from inputs.
	average = (score1 + score2 + score3) / 3;

	// 8. Display the average exam score.
	printf("Exam average: %d\n", average);

	return 0; // our program executed successfully
}