/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA6
* Date: November 2nd, 2022
* Description: This module describes the games logic and rules.
*******************************************************************************************/

#include "game.h"
#include <stdio.h>
#include <stdlib.h>

// Static game state

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
	printf("Get Menu Key Called: %d\n", key);
	return key;
}

int sum_array(int nums[], int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += nums[i];
  }
  return sum;
}

// I want to print in color, so I found this StackOverflow that lists
// the ANSI codes to change the print color!
// https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
void color(Colors color) {
  printf("\033[0;%dm", color);
}

void reset() {
  printf("\033[0m");
}

// Since this is the root menu of the game,
// we don't need to set it up as a game scene.
void display_main_menu() {
	printf("Battleship Menu:\n");
	printf("1. Play Battleship\n");
	printf("2. Battleship Rules\n");
	printf("3. Exit\n");
	printf("\nChoose by entering a menu number\n");
}

void display_rules() {
  /*
    The following rules were directly taken from an online source.
    https://cardgames.io/yahtzee/
  */
  printf("How to Battleship:\n");
}

int roll_die(void) {
  // This is supposed to make random return different values each
  // time the program run, but it doesn't seem to do anything.
  return (rand() % 6) + 1;
}

// This method allows us to dynamically start
// any game scene and enable user navigation
void goto_scene(int (*scene)(char, State*), State* state) {
  int continue_scene = 1;
  int current_input = '\0';

	clear_terminal();
	(*scene)(current_input, state);

	// Begin reading user value
	while (continue_scene == 1) {
		current_input = wait_for_input();
    clear_terminal();
    // Keep calling the scene until it returns a non-one int
		continue_scene = (*scene)(current_input, state);
	}
}

int rules_scene(char input, State* state) {
  if (input == '\0') {
    display_rules();
    printf("\nPress any key to go back.\n");
  } else {
    return 0;
  }

  // Returning 1 tells the scene manager to wait until the user navigates away
  return 1;
}

char wait_for_input() {
  while (1) {
    // fflush(stdin);
    system("/bin/stty raw");
    char in = getchar();
    system("/bin/stty cooked");
    if ((in != '\n') && (in != ' ')) {
      return in;
    }
  }
}

// The Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells.
const int ship_lengths[] = { 0, 2, 3, 3, 4, 5 };
// Indicated by 'c' for Carrier, 'b' for Battleship, 'r' for Cruiser, 's' for Submarine, or 'd' for Destroyer
const char ship_display[] = { '\0', 'd', 's', 'r', 'b', 'c' };

void init_fleet(Ship fleet[]) {
  for (int i = 0; i < 5; i++) {
    int type = i + 1;
    Ship a_ship = {
      ship_display[type],
      ship_lengths[type],
      type, 0, 0, 0, 0, 0
    };
    fleet[i] = a_ship;
  }
}

void init_board(Board* board) {
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      board->who_is[x][y] = NULL; // Set a null pointer because there is no ship here yet
      board->display[x][y] = '-'; // The default graphic is this lil' dude
    }
  }
}

void display_board(Board *board) {
  color(GREEN); printf("  0 1 2 3 4 5 6 7 8 9\n"); reset();
  for (int x = 0; x < 10; x++) {
    color(GREEN); printf("%d ", x); reset();
    for (int y = 0; y < 10; y++) {
      int tile = board->display[x][y];
      printf("%c ", tile);
    }
    printf("\n");
  }
}

void display_all_boards(State* state) {
  printf("Your Board:\n");
  display_board(state->p1);
  printf("\nOpposition's Board:\n");
  display_board(state->p2);
}

int game_scene(char input, State* state) {
  switch (input) {
    default: display_all_boards(state); break;
  }
  return 1;
}
