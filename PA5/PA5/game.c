/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA4
* Date: October 7th, 2022
* Description: This module describes the games logic and rules.
*******************************************************************************************/

#include "game.h"
#include "bank.h"
#include <stdlib.h>

void clear_terminal() {
  // According to one source, there is standard constants
  // defined by the compiler that tells us what system we
  // are compiling for. Since I use Mac and the graders use
  // Windows, this should give cross-system compatibility.
  #ifdef _WIN64
    system("cls");
  #elif _WIN32
    system("cls");
  #elif __APPLE__
    system("clear");
  #endif
}

int get_menu_key() {
	int key = 0;
	scanf(" %d", &key);
	// printf("Get Menu Key Called: %d\n", key);
	return key;
}

// Since this is the root menu of the game,
// we don't need to set it up as a game scene.
void display_main_menu() {
	printf("Yahtzee Menu:\n");
	printf("1. Play Yahtzee\n");
	printf("2. Yahtzee Rules\n");
	printf("3. Exit\n");
	printf("\nChoose by entering a menu number\n");
}

// Store the current game point globally so it can be accessed
// by other functions and to persist game state over
// different invocations of the game scene.
// put game state here

// function for reseting game state

// This method allows us to dynamically start
// any game scene and enable user navigation
void goto_scene(int (*scene)(int)) {
	int continue_scene = 1;
	int current_input = -1;

	// Start the scene with a garbage input state
	clear_terminal();
	continue_scene = (*scene)(current_input);

	// Begin reading user value
	while (continue_scene == 1) {
		// Give the option for the user to leave the scene
		printf("Press 0 to go back.\n");
		current_input = get_menu_key();

		if (current_input == 0) {
			continue_scene = 0;
      // Reseting the point regardless of the current scene assures that
      // when the user navigates away from the game but then comes back,
      // they get a fresh game state to start with.

      // reset_game()
		} else {
			// Call the scene with the updated state
			clear_terminal();
			continue_scene = (*scene)(current_input);
		}
	}
}

void display_game_rules() {
  /*
    The following rules were directly taken from an online source.
    https://www.onlinegambling.com/casino/craps/how-to-play/
  */
  printf("How to Yahtzee:\n");
}

int rules_scene(int input) {
  // Normally in a scene, the input would be evaluated.
  // But since we're just showing the rules, there's
  // no interactivity to this scene, so just print
  // the game rules.
  display_game_rules();

  // Returning 1 tells the scene manager to wait until the user navigates away
  return 1;
}

int roll_die(void) {
  // This is supposed to make random return different values each
  // time the program run, but it doesn't seem to do anything.
  srand(time(NULL));
  return (rand() % 6) + 1;
}

int sum_array(int nums[], int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += nums[i];
  }
  return sum;
}

void update_array(int nums[], int length, int (*cbFunc)(void)) {
  for (int i = 0; i < length; i++) {
    nums[i] = (*cbFunc)();
  }
}

int do_roll() {
  printf("Ready? Enter R to roll the dice!\n");

  char roll_input = '\0'; // We aren't going to check, it's just for the lolz
  scanf(" %c", &roll_input);

  int dies[5] = { 0 };
  update_array(dies, 5, do_roll);

  printf("\n The dies are \n");
  printf("-- %d --\n", dies[0]);
  printf("-- %d --\n", dies[1]);
  printf("-- %d --\n", dies[2]);
  printf("-- %d --\n", dies[3]);
  printf("-- %d --\n", dies[4]);

  int die_sum = sum_array(dies, 5);
  printf("\nThe die sum is %d\n\n", die_sum);

  return die_sum;
}

int game_scene(int input) {
  int die_sum = do_roll();
  
  printf("\nKeep playing!\n");
  printf("  Enter 1 to continue\n");
  printf("  > OR <\n  ");
  return 1;
}
