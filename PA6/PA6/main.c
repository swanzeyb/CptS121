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
	system("/bin/stty cooked");
	
	int continue_game = 1;
	int current_menu = -1;

	Board p1_board;
	Board p2_board;

	init_board(&p1_board);
	init_board(&p2_board);

	Ship p1_fleet[5];
	Ship p2_fleet[5];

	init_fleet(p1_fleet);
	init_fleet(p2_fleet);

	Coord cursor = { -1, -1 };

	State state = {
		&p1_board,
		&p2_board,
		p1_fleet,
		p2_fleet,
		0, // is_setup
		0, // rounds
		0, // curr_place
		&cursor,
	};

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
