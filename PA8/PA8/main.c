/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA8
* Date: December 6th, 2022
* Description: For this assignment you will be required to write functions which solve various problems.
*******************************************************************************************/

#include "alg.h"

int main() {

	char* alpaca = (char*)malloc(sizeof(char) * 6);
	char* bison = (char*)malloc(sizeof(char) * 4);
	char* cat = (char*)malloc(sizeof(char) * 3);
	char* dog = (char*)malloc(sizeof(char) * 3);

	alpaca = "Alpaca";
	bison = "Bison";
	cat = "Cat";
	dog = "Dog";

	char** animals = (char**)malloc(sizeof(alpaca) + sizeof(bison) + sizeof(cat) + sizeof(dog));

	animals[0] = alpaca;
	animals[3] = bison;
	animals[1] = cat;
	animals[2] = dog;

	bubble_sort(animals, 4);

	for (int i = 0; i < 4; i++) {
		printf("Animal: %s\n", animals[i]);
	}

	// free(animals);

	// Tell the system the program executed successfully
	return 0;
}
