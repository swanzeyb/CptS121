/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA4
* Date: October 7th, 2022
* Description: Write a program that implements a craps game that allows for wagering.
*******************************************************************************************/

#include "game.h"
#include "bank.h"

int main() {
	int continue_game = 1;
	int current_menu = -1;

	Checking bank = read_account();
	printf("bal: %.2lf\n", read_checking(&bank));
	update_checking(&bank, 2.00);
	update_checking(&bank, -3.01);
	printf("bal: %.2lf\n", read_checking(&bank));

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
