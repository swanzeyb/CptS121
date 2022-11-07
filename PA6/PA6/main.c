/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA5
* Date: October 7th, 2022
* Description: Write a program that implements Battleship.
*******************************************************************************************/

#include "game.h"

int main() {
	srand(time(NULL));
	
	int continue_game = 1;
	int current_menu = -1;

	Board p1 = { { { 0 }, { 0 } } };
	Board p2 = { { { 0 }, { 0 } } };

	init_board(&p1);
	init_board(&p2);

	State state = { p1, p2 };

	// Now wait for user's input
	while (continue_game == 1) {
		clear_terminal();
		display_main_menu();
		current_menu = get_menu_key();

		switch(current_menu) {
			case 1:
				goto_scene(game_scene, &state);
				break;
			case 2:
				goto_scene(rules_scene, &state);
				break;
			case 3:
				continue_game = 0;
				break;
		}
	}

	// Tell the system the program executed successfully
	return 0;
}
