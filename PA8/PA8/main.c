/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA8
* Date: December 6th, 2022
* Description: For this assignment you will be required to write functions which solve various problems.
*******************************************************************************************/

#include "alg.h"

int main() {

	char* pali = "race car";
	char* not_pali = "hi mom";

	printf("%s is a palindrome: %s\n", pali, is_palindrome(pali, 8) == 1 ? "true" : "false");
	printf("%s is a palindrome: %s\n", not_pali, is_palindrome(not_pali, 6) == 1 ? "true" : "false");

	// Tell the system the program executed successfully
	return 0;
}
