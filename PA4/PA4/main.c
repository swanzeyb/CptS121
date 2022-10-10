/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA4
* Date: October 7th, 2022
* Description: Write a program that implements a craps game that allows for wagering.
*******************************************************************************************/

#include "game.h"
#include "bank.h"

int get_menu_key() {
	int key = 0;
	scanf(" %d", &key);
	// printf("Get Menu Key Called: %d\n", key);
	return key;
}

// Since this is the root menu of the game,
// we don't need to set it up as a game scene.
void display_main_menu() {
	printf("Game Menu:\n");
	printf("1. Play Craps\n");
	printf("2. Craps Rules\n");
	printf("3. Bank Balance\n");
	printf("4. Exit\n");
	printf("\nChoose by entering a menu number\n");
}

// This method allows us to dynamically start
// any game scene and enable user navigation
void goto_scene(void (*scene)(int)) {
	int continue_scene = 1;
	int current_input = -1;

	// Start the scene with a garbage state
	clear_terminal();
	(*scene)(current_input);

	// Begin reading user value
	while (continue_scene == 1) {
		// Give the option for the user to leave the scene
		printf("\nPress 0 to go back.\n");
		current_input = get_menu_key();

		if (current_input == 0) {
			continue_scene = 0;
		} else {
			// Call the scene with the updated state
			clear_terminal();
			(*scene)(current_input);
		}
	}
}

int main() {
	int continue_game = 1;
	int current_menu = -1;

	Checking bank_account;
	create_checking(&bank_account, 118.26);
	printf("bal: %.2lf\n", read_checking(&bank_account));
	update_checking(&bank_account, 2.00);
	update_checking(&bank_account, -3.01);
	printf("bal: %.2lf\n", read_checking(&bank_account));

	// Now wait for user's input
	// while (continue_game == 1) {
	// 	clear_terminal();
	// 	display_main_menu();
	// 	current_menu = get_menu_key();

	// 	switch(current_menu) {
	// 		case 1:
	// 			goto_scene(game_scene);
	// 			break;
	// 		case 2:
	// 			goto_scene(rules_scene);
	// 			break;
	// 		case 4:
	// 			continue_game = 0;
	// 			break;
	// 		default:
	// 			// display_main_menu();
	// 			printf("default case...");
	// 	}
	// }

	// Tell the system the program executed successfully
	return 0;
}
