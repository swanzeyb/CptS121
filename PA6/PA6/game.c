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

void wait_for_continue() {
  printf("Press any key to continue\n");
  wait_for_input();
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

// The Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells.
const int ship_lengths[] = { 0, 2, 3, 3, 4, 5 };
// Indicated by 'c' for Carrier, 'b' for Battleship, 'r' for Cruiser, 's' for Submarine, or 'd' for Destroyer
const char ship_display[] = { '\0', 'd', 's', 'r', 'b', 'c' };
const char* ship_names[] = { "No Ship", "Destroyer", "Submarine", "Cruiser", "Battleship", "Carrier" };

void init_fleet(Ship fleet[]) {
  for (int i = 0; i < 5; i++) {
    int type = i + 1;
    int length = ship_lengths[type];
    Ship a_ship = {
      ship_display[type],
      length,
      type,
      { 0 },
      0, 0, 1, length,
    };
    fleet[i] = a_ship;
  }
}

void init_board(Board* board) {
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      char tile = board->display[y][x];
      if (tile == '~' || tile == '+') {
        // It's a miss, so just reset the who_is value
        board->who_is[y][x] = NULL;
      } else {
        board->who_is[y][x] = NULL; // Set a null pointer because there is no ship here yet
        board->display[y][x] = '-'; // The default graphic is this lil' dude
      }
    }
  }
}

void display_board(Board* board, int only_hits) {
  color(GREEN); printf("  0 1 2 3 4 5 6 7 8 9\n"); reset();
  for (int x = 0; x < 10; x++) {
    color(GREEN); printf("%d ", x); reset();
    for (int y = 0; y < 10; y++) {
      int tile = board->display[x][y];
      switch (tile) {
        case '*': color(RED); break; // Strike
        case '+': color(RED); break; // Cursor
        case '~': color(CYAN); break; // Miss
        case 'c': color(ALT_MAGENTA); break; // Carrier
        case 'd': color(ALT_MAGENTA); break; // Destroyer
        case 'r': color(ALT_MAGENTA); break; // Cruiser
        case 's': color(ALT_MAGENTA); break; // Submarine
        case 'b': color(ALT_MAGENTA); break; // Battleship
        default: reset();
      }
      if (only_hits == 1) {
        reset();
        printf("- ");
      } else {
        printf("%c ", tile);
      }
    }
    printf("\n");
  }
}

void display_cursor(Board* board) {
  color(GREEN); printf("  0 1 2 3 4 5 6 7 8 9\n"); reset();
  for (int x = 0; x < 10; x++) {
    color(GREEN); printf("%d ", x); reset();
    for (int y = 0; y < 10; y++) {
      int tile = board->display[x][y];
      switch (tile) {
        case '*': color(RED); break; // Strike
        case '+': color(RED); break; // Cursor
        case '~': color(CYAN); break; // Miss
        default: reset();
      }
      char display = '\0';
      switch (tile) {
        case '*': display = '*'; break;
        case '+': display = '+'; break;
        case '~': display = '~'; break;
        default: display = '-'; break;
      }
      printf("%c ", display);
    }
    printf("\n");
  }
}

void display_all_boards(State* state) {
  printf("Your Board:\n");
  display_board(state->p1_board, 0);
  printf("\nOpposition's Board:\n");
  display_board(state->p2_board, 1);
}

void display_setup_menu() {
  printf("Welcome to Battleship!\n");
	printf("1. Manually place ships\n");
	printf("2. Auto-place ships\n");
	printf("\nChoose by entering a menu number\n");
}

int is_space_occupied(Ship in_theory, Board* board) {
  int is_occupied = 1;
  if ((in_theory.y_upper <= 10) && (in_theory.y_lower >= 0)) {
    if ((in_theory.x_upper <= 10) && (in_theory.x_lower >= 0)) {
      // If the ship is within the bounds of the game board,
      // check if new placement would conflict with other ships.
      
      is_occupied = 0; // The ship is within the board
      for (int x = in_theory.x_lower; x < in_theory.x_upper; x++) {
        for (int y = in_theory.y_lower; y < in_theory.y_upper; y++) {
          Ship* who_is = board->who_is[y][x];

          // Now check if there is a ship in the way
          if ((who_is != NULL) && (who_is->type != in_theory.type)) {
            is_occupied = 1;
          }
        }
      }
    }
  }
  return is_occupied;
}

void move_ship(int vert, int horz, State* state) {
  Ship* curr_ship = &state->p1_fleet[state->curr_place];

  // Theorize where the ship would be
  Ship in_theory = *curr_ship;
  in_theory.y_lower += vert;
  in_theory.y_upper += vert;
  in_theory.x_lower += horz;
  in_theory.x_upper += horz;

  // Now check if it conflicts with bounds or other ships
  int is_occupied = is_space_occupied(in_theory, state->p1_board);

  // If there are no conflicts, update the ship
  if (is_occupied == 0) {
    curr_ship->x_lower = in_theory.x_lower;
    curr_ship->y_lower = in_theory.y_lower;
    curr_ship->x_upper = in_theory.x_upper;
    curr_ship->y_upper = in_theory.y_upper;
  }
}

int rotate_ship(Ship* curr_ship, Board* board) {
  // Theorize where the ship would be
  Ship in_theory = *curr_ship;

  // If it's horizontal then
  int x_len = curr_ship->x_upper - curr_ship->x_lower;
  int y_len = curr_ship->y_upper - curr_ship->y_lower;
  if (x_len > y_len) {
    in_theory.y_upper = in_theory.y_lower + in_theory.length;
    in_theory.x_upper = in_theory.x_lower + 1;
  } else {
    in_theory.y_upper = in_theory.y_lower + 1;
    in_theory.x_upper = in_theory.x_lower + in_theory.length;
  }

  // Now check if it conflicts with bounds or other ships
  int is_occupied = is_space_occupied(in_theory, board);

  // If there are no conflicts, update the ship
  if (is_occupied == 0) {
    curr_ship->x_lower = in_theory.x_lower;
    curr_ship->y_lower = in_theory.y_lower;
    curr_ship->x_upper = in_theory.x_upper;
    curr_ship->y_upper = in_theory.y_upper;
  }

  return is_occupied;
}

void update_board(Board* board, Ship* fleet, int length) {
  // Reset Board
  init_board(board);

  // Update main players board
  for (int i = 0; i < length; i++) {
    Ship curr_ship = fleet[i];

    // For the bounds of the ship
    for (int x = curr_ship.x_lower; x < curr_ship.x_upper; x++) {
      for (int y = curr_ship.y_lower; y < curr_ship.y_upper; y++) {
        // Look if it's hit
        int x_len = curr_ship.x_upper - x;
        int y_len = curr_ship.y_upper - y;
        int hit_lookup = (x_len * y_len) - 1;

        // Display the correct character
        char display = '\0';
        int hit = curr_ship.hits[hit_lookup];
        if (hit == 1) {
          display = '*';
        } else if (board->display[y][x] != '~') {
          display = curr_ship.display;
        }
        board->display[y][x] = display;
        board->who_is[y][x] = &fleet[i];
      }
    }
  }
}

int rand_num(int len) {
  return (rand() % len);
}

void place_fleet(Board* board, Ship* fleet) {
  for (int i = 0; i < 5; i++) {
    Ship* curr_ship = &fleet[i]; // Grab a blank ship
    int is_occupied = 1;

    // Do random placement until there is no conflict
    do {
      // Randomly place it on the board
      curr_ship->x_lower = rand_num(10);
      curr_ship->y_lower = rand_num(10);
      curr_ship->x_upper = curr_ship->x_lower + 1;
      curr_ship->y_upper = curr_ship->y_lower + curr_ship->length;

      // Try to randomly rotate the ship
      if (rand_num(2) == 1) {
        // Rotate ship already checks for collisions
        is_occupied = rotate_ship(curr_ship, board);
      } else {
        is_occupied = is_space_occupied(*curr_ship, board);
      }
    } while (is_occupied == 1);

    // After successfull placing, update the board
    update_board(board, fleet, i + 1);
  }
}

int place_fleet_scene(char input, State* state) {
  // Get the ship that is being currently placed
  Ship* curr_ship = &state->p1_fleet[state->curr_place];

  // Evaluate the input
  switch (tolower(input)) {
    case 'w': move_ship(-1, 0, state); break;
    case 's': move_ship(1, 0, state); break;
    case 'a': move_ship(0, -1, state); break;
    case 'd': move_ship(0, 1, state); break;
    case 'r': rotate_ship(curr_ship, state->p1_board); break;
    case 13:
      state->curr_place += 1;
      break;
  }

  // Update the display data from inputs
  update_board(state->p1_board, state->p1_fleet, state->curr_place + 1);

  if (state->curr_place > 4) {
    state->curr_place = 0;
    return 0;
  }

  // Display the new game state
  clear_terminal();
  printf("Use WASD to move ship up, down, left, right.\n");
  printf("Press R to rotate the ship on the board.\n");
  printf("Hit ENTER when finished placing this ship.\n\n");
  display_board(state->p1_board, 0);
  printf("\nYou're currently placing your %s\n", ship_names[curr_ship->type]);

  return 1;
}

int setup_scene(char input, State* state) {
  display_setup_menu();
  switch (input) {
    case '1':
      goto_scene(place_fleet_scene, state);
      place_fleet(state->p2_board, state->p2_fleet);
      return 0; break;
    case '2':
      place_fleet(state->p1_board, state->p1_fleet);
      place_fleet(state->p2_board, state->p2_fleet);
      return 0; break;
  }
  return 1;
}

void start_cursor(Coord* cursor) {
  cursor->x = 4;
  cursor->y = 4;
}

void stop_cursor(Coord* cursor) {
  cursor->x = -1;
  cursor->y = -1;
}

int is_cursor_active(Coord* cursor) {
  if ((cursor->x == -1) || (cursor->y == -1)) {
    return 0;
  } else {
    return 1;
  }
}

void update_cursor(Coord* last, Coord* next, Board* board) {
  if (is_cursor_active(next)) {
    char last_display = board->display[last->y][last->x];
    char display = '-';
    if ((last_display == '~') || (last_display == '*')) {
      display = last_display;
    }
    board->display[last->y][last->x] = display;
    board->display[next->y][next->x] = '+';
  } else {
    board->display[last->y][last->x] = '-';
  }
}

void move_cursor(int vert, int horz, State* state) {
  Coord in_theory = *state->cursor;
  in_theory.x += horz;
  in_theory.y += vert;

  if ((in_theory.y <= 10) && (in_theory.y >= 0)) {
    if ((in_theory.x <= 10) && (in_theory.x >= 0)) {
      // If cursor is in bounds, display it
      update_cursor(state->cursor, &in_theory, state->p2_board);
      state->cursor->x = in_theory.x;
      state->cursor->y = in_theory.y;
    }
  }
}

int kaboom_scene(char input, State* state) {
  Coord cursor = *state->cursor;
  Ship* who_is_cursor = state->p2_board->who_is[cursor.y][cursor.x];

  if (who_is_cursor != NULL) {
    // It's a hit
    // Update their fleet
    printf("The missle hit their %s!\n", ship_names[who_is_cursor->type]);
    wait_for_continue();
  } else {
    // It's not a hit
    state->p2_board->display[cursor.y][cursor.x] = '~';
    stop_cursor(state->cursor);
    update_cursor(state->cursor, state->cursor, state->p2_board);
    printf("The missle missed!\n");
    wait_for_continue();
  }

  return 0;
}

int strike_scene(char input, State* state) {
  switch (tolower(input)) {
    case 'w': move_cursor(-1, 0, state); break;
    case 's': move_cursor(1, 0, state); break;
    case 'a': move_cursor(0, -1, state); break;
    case 'd': move_cursor(0, 1, state); break;
    case 13:
      // Kaboom
      goto_scene(kaboom_scene, state);
      stop_cursor(state->cursor);
      update_cursor(state->cursor, state->cursor, state->p2_board);
      return 0;
      break;
  }

  if (is_cursor_active(state->cursor) != 1) {
    start_cursor(state->cursor);
    update_cursor(state->cursor, state->cursor, state->p2_board);
  }

  printf("Use WASD to select a tile to strike!\n\n");
  display_cursor(state->p2_board);
  printf("\nPress ENTER to send the missle when ready.\n");

  return 1;
}

int game_scene(char input, State* state) {
  if (state->is_setup == 0) { // If the game hasn't been setup, then setup
    goto_scene(setup_scene, state);
    state->is_setup = 1;
  }

  clear_terminal();
  display_all_boards(state);
  printf("\n");
  wait_for_continue();

  goto_scene(strike_scene, state);

  switch (input) {
    case 13: return 0; break;
    default: return 1; break;
  }
}
