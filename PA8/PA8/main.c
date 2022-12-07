/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA8
* Date: December 6th, 2022
* Description: For this assignment you will be required to write functions which solve various problems.
*******************************************************************************************/

#include "alg.h"

void color(Colors color) {
  // I want to print in color, so I found this StackOverflow that lists
  // the ANSI codes to change the print color!
  // https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
  printf("\x1b[%dm", color);
}

void reset() {
  printf("\033[0m");
}

int main() {

	// my_str_n_cat
	char source[] = "dogs.";
	char sink[100] = "I like ";
	char* str_cat_result = my_str_n_cat(source, sink, 5);

	color(COLOR_CYAN); printf("Result of my_str_n_cat: \n"); reset();
	printf("%s\n", str_cat_result);

	// binary_search
	int sorted_nums[] = { 5, 10, 24, 25, 32, 48, 50 };
	color(COLOR_CYAN); printf("Result of binary_search: \n"); reset();

	binary_search_result_t r_one = binary_search(sorted_nums, 7, 24);
	printf("Index of %d in sorted_nums is %d\n", 24, r_one.index);

	binary_search_result_t r_two = binary_search(sorted_nums, 7, 50);
	printf("Index of %d in sorted_nums is %d\n", 50, r_two.index);

	binary_search_result_t r_three =binary_search(sorted_nums, 7, 27);
	printf("Index of %d in sorted_nums is %d\n", 27, r_three.index);

	// bubble_sort
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

	color(COLOR_CYAN); printf("Result of bubble_sort: \n"); reset();
	for (int i = 0; i < 4; i++) {
		printf("Animal: %s\n", animals[i]);
	}

	// is_palindrome
	char* pali = "race car";
	char* not_pali = "hi mom";
	color(COLOR_CYAN); printf("Result of is_palindrome: \n"); reset();

	printf("%s is a palindrome: %s\n", pali, is_palindrome(pali, 8) == 1 ? "true" : "false");
	printf("%s is a palindrome: %s\n", not_pali, is_palindrome(not_pali, 6) == 1 ? "true" : "false");

	// sum_primes
	color(COLOR_CYAN); printf("Result of sum_primes: \n"); reset();
	printf("%d is the sum of all prime numbers in %d\n", sum_primes(123, 0), 1235);

	// maximum_occurences
	char* test_occurrences = "onomonopia";
	Occurrences occurrences[64] = { { 0, 0.0 } };
	char* most_used = malloc(sizeof(char));
	double* used_frequency = malloc(sizeof(double));
	Occurrences* m_occurrences = maximum_occurences(test_occurrences, occurrences, used_frequency, most_used);
	
	color(COLOR_CYAN); printf("Result of maximum_occurences: \n"); reset();
	printf("Char '%c', Used %d, Frequency %.2lf\n", *most_used, m_occurrences->num_occurrences, m_occurrences->frequency);

	// Tell the system the program executed successfully
	return 0;
}
