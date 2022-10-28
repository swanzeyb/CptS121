/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA5
* Date: October 7th, 2022
* Description: Write a program that implements Yahtzee.
*******************************************************************************************/

#include "game.h"

int main() {
	srand(time(NULL));
	
	int continue_game = 1;
	int current_menu = -1;

	// Now wait for user's input
	while (continue_game == 1) {
		clear_terminal();
		display_main_menu();
		current_menu = get_menu_key();

		switch(current_menu) {
			case 1:
				goto_scene(game_scene);
				break;
			case 2:
				goto_scene(rules_scene);
				break;
			case 3:
				continue_game = 0;
				break;
		}
	}

	// Tell the system the program executed successfully
	return 0;
}
