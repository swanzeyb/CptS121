/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA6
* Date: November 2nd, 2022
* Description: This module describes the games logic and rules.
*******************************************************************************************/

#include "game.h"

void shuffle (int wDeck[][13]) {
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand () % 4;
			column = rand () % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal (const int wDeck[][13], const char *wFace[], const char *wSuit[]) {
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
 
	/* deal each of the 52 cards */
	for (card = 1; card <= 52; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					printf ("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

void clear_terminal() {
  // According to one source, there is standard constants
  // defined by the compiler that tells us what system we
  // are compiling for. Since I use Mac and the graders use
  // Windows, this should give cross-system compatibility.
  #if defined(_WIN64) || defined(_WIN32)
    system("cls");
  #elif defined(__APPLE__)
    system("clear");
  #endif
}

int get_menu_key() {
	int key = 0;
	scanf(" %d", &key);
	return key;
}

void color(Colors color) {
  // I want to print in color, so I found this StackOverflow that lists
  // the ANSI codes to change the print color!
  // https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
  printf("\033[0;%dm", color);
}

void reset() {
  printf("\033[0m");
}

int rand_num(int len) {
  return (rand() % len);
}

int arr_max(int arr[], int len) {
  int max = arr[0];
  for (int i = 0; i < len; i ++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

// Since this is the root menu of the game,
// we don't need to set it up as a game scene.
void display_main_menu() {
	printf("Poker Menu:\n");
	printf("1. Play Poker\n");
	printf("2. Poker Rules\n");
	printf("3. Exit\n");
	printf("\nChoose by entering a menu number\n");
}

void display_rules() {
  /*
    The following rules were directly taken from an online source.
    https://www.cs.nmsu.edu/~bdu/TA/487/brules.htm
  */
  // See citation above.
}

char wait_for_input() {
  while (1) {
    #if defined(_WIN64) || defined(_WIN32)
      char in = _getch();
    #elif defined(__APPLE__)
      fflush(stdin);
      system("/bin/stty raw");
      char in = getchar();
      system("/bin/stty cooked");
    #endif
    if ((in != '\n') && (in != ' ')) {
      return in;
    }
  }
}

void wait_for_continue() {
  printf("Press any key to continue\n");
  wait_for_input();
}

// Game Logic
bool straight_flush() {}
bool four_kind() {}
bool full_house() {}
bool flush() {}
bool straight() {}
bool three_kind() {}
bool two_pair() {}
bool pair() {}
bool high_card() {}

// This method allows us to dynamically start
// any game scene and enable user navigation
void goto_scene(int (*scene)(char, State*), State* state) {
  int continue_scene = true;
  int current_input = '\0';

	clear_terminal();
	continue_scene = (*scene)(current_input, state);

	// Begin reading user value
	while (continue_scene == true) {
		current_input = wait_for_input();
    clear_terminal();
    // Keep calling the scene until it returns a non-one int
		continue_scene = (*scene)(current_input, state);
	}
}

bool rules_scene(char input, State* state) {
  if (input == '\0') {
    display_rules();
    printf("\nPress any key to go back.\n");
  } else {
    return false;
  }

  // Returning 1 tells the scene manager to wait until the user navigates away
  return true;
}

bool game_scene(char input, State* state) {
  return true;
}
