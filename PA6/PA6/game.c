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
    https://www.cs.nmsu.edu/~bdu/TA/487/brules.htm
  */
  printf("How to Battleship:\n");
  printf("The object of Battleship is to try and sink all of the other player's before they sink all of your ships. All of the other player's ships are somewhere on his/her board.  You try and hit them by calling out the coordinates of one of the squares on the board.  The other player also tries to hit your ships by calling out coordinates.  Neither you nor the other player can see the other's board so you must try to guess where they are.  Each board in the physical game has two grids:  the lower (horizontal) section for the player's ships and the upper part (vertical during play) for recording the player's guesses.\n");
  printf("Each player places the 5 ships somewhere on their board.  The ships can only be placed vertically or horizontally. Diagonal placement is not allowed. No part of a ship may hang off the edge of the board.  Ships may not overlap each other.  No ships may be placed on another ship.\n");
  printf("Once the guessing begins, the players may not move the ships.\n");
  printf("The 5 ships are:  Carrier (occupies 5 spaces), Battleship (4), Cruiser (3), Submarine (3), and Destroyer (2).\n");
  printf("Player's take turns guessing by calling out the coordinates. The opponent responds with 'hit' or 'miss' as appropriate.\n");
  printf("When all of the squares that one your ships occupies have been hit, the ship will be sunk. You should announce 'hit and sunk'.\n");
  printf("As soon as all of one player's ships have been sunk, the game ends.\n");
  // See citation above.
}

char wait_for_input() {
  while (1) {
    // fflush(stdin);
    // system("/bin/stty raw");
    // char in = getchar();
    // system("/bin/stty cooked");
    char in = _getch();
    if ((in != '\n') && (in != ' ')) {
      return in;
    }
  }
}

void wait_for_continue() {
  printf("Press any key to continue\n");
  wait_for_input();
}

// I want C++ for more dynamic options this is gross af no cap
FILE* open_log() {
  FILE* record = fopen("battleship.log", "a");
  return record;
}

// This method allows us to dynamically start
// any game scene and enable user navigation
void goto_scene(int (*scene)(char, State*), State* state) {
  int continue_scene = 1;
  int current_input = '\0';

	clear_terminal();
	continue_scene = (*scene)(current_input, state);

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
      0, 0, 1, length,
    };
    fleet[i] = a_ship;
  }
}

void init_board(Board* board) {
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      char tile = board->display[y][x];
      board->who_is[y][x] = NULL; // Set a null pointer because there is no ship here yet
      board->display[y][x] = '-'; // The default graphic is this lil' dude
      board->misses[y][x] = 0;
      board->hits[y][x] = 0;
    }
  }
}

void refresh_board(Board* board) {
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      char tile = board->display[y][x];
      board->who_is[y][x] = NULL; // Set a null pointer because there is no ship here yet
      board->display[y][x] = '-'; // The default graphic is this lil' dude
    }
  }
}

void display_board(Board* board) {
  color(GREEN); printf("  0 1 2 3 4 5 6 7 8 9\n"); reset();
  for (int x = 0; x < 10; x++) {
    color(GREEN); printf("%d ", x); reset();
    for (int y = 0; y < 10; y++) {

      // Get the current tile for this board
      int tile = board->display[y][x];

      // Set the color depending on type of char
      switch (tile) {
        case '*': color(RED); break; // Strike
        case '+': color(RED); break; // Cursor
        case 'x': color(ALT_CYAN); break; // Miss
        case 'c': color(ALT_MAGENTA); break; // Carrier
        case 'd': color(ALT_MAGENTA); break; // Destroyer
        case 'r': color(ALT_MAGENTA); break; // Cruiser
        case 's': color(ALT_MAGENTA); break; // Submarine
        case 'b': color(ALT_MAGENTA); break; // Battleship
        default: reset();
      }

       printf("%c ", tile);
    }
    reset();
    printf("\n");
  }
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

void move_cursor(int vert, int horz, State* state) {
  Coord in_theory = *state->cursor;
  in_theory.x += horz;
  in_theory.y += vert;

  if ((in_theory.y <= 10) && (in_theory.y >= 0)) {
    if ((in_theory.x <= 10) && (in_theory.x >= 0)) {
      // If cursor is in bounds, display it
      state->cursor->x = in_theory.x;
      state->cursor->y = in_theory.y;
    }
  }
}

void display_strike(Board* board, Coord* cursor, int show_cursor) {
  color(GREEN); printf("  0 1 2 3 4 5 6 7 8 9\n"); reset();
  for (int x = 0; x < 10; x++) {
    color(GREEN); printf("%d ", x); reset();
    for (int y = 0; y < 10; y++) {
      char tile = '\0';

      // Check if there is a cursor
      if ((cursor->x == y) && (cursor->y == x) && (show_cursor == 1)) { // I messed up, the coords are switched.
        tile = '+';
      } else {
        tile = board->display[y][x];
      }

      // Set the color depending on type of char
      switch (tile) {
        case '*': color(RED); break; // Strike
        case '+': color(RED); break; // Cursor
        case 'x': color(ALT_CYAN); break; // Miss
        default: reset();
      }

      // Hide other players ships
      switch (tile) {
        case '*': break;
        case '+': break;
        case 'x': break;
        default: tile = '-'; break;
      }

      printf("%c ", tile);
    }
    reset();
    printf("\n");
  }
}

void display_all_boards(State* state) {
  printf("Your Board:\n");
  display_board(state->p1_board);
  printf("\nOpposition's Board:\n");
  display_strike(state->p2_board, state->cursor, 0);
}

void display_setup_menu() {
  printf("Welcome to Battleship!\n");
	printf("1. Manually place ships\n");
	printf("2. Auto-place ships\n");
	printf("\nChoose by entering a menu number\n");
}

int is_space_occupied(Ship in_theory, Board* board) {
  int is_occupied = 1;
  if ((in_theory.y_upper < 10) && (in_theory.y_lower >= 0)) {
    if ((in_theory.x_upper < 10) && (in_theory.x_lower >= 0)) {
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
  refresh_board(board);

  // Update display for where the ships are
  for (int i = 0; i < length; i++) {
    Ship curr_ship = fleet[i];

    // For the bounds of the ship
    for (int x = curr_ship.x_lower; x < curr_ship.x_upper; x++) {
      for (int y = curr_ship.y_lower; y < curr_ship.y_upper; y++) {
        board->display[y][x] = curr_ship.display;;
        board->who_is[y][x] = &fleet[i];
      }
    }
  }

  // Update display for hits and misses
  for (int x = 0; x < 10; x++) {
    for(int y = 0; y < 10; y++) {
      char display = board->display[y][x];
      int hit = board->hits[y][x];
      int miss = board->misses[y][x];
      if (hit == 1) {
        display = '*';
      } else if (miss == 1) {
        display = 'x';
      }
      board->display[y][x] = display;
    }
  }
}

int rand_num(int len) {
  return (rand() % len);
}

void rand_place_fleet(Board* board, Ship* fleet) {
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
    case '\r':
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
  display_board(state->p1_board);
  printf("\nYou're currently placing your %s\n", ship_names[curr_ship->type]);

  return 1;
}

int setup_scene(char input, State* state) {
  display_setup_menu();
  switch (input) {
    case '1':
      goto_scene(place_fleet_scene, state);
      rand_place_fleet(state->p2_board, state->p2_fleet);
      return 0; break;
    case '2':
      rand_place_fleet(state->p1_board, state->p1_fleet);
      rand_place_fleet(state->p2_board, state->p2_fleet);
      return 0; break;
  }
  return 1;
}

int attacked_scene(char input, State* state) {
  int x = rand_num(10);
  int y = rand_num(10);
  Ship* who_is = state->p1_board->who_is[x][y];
  FILE* log = open_log();
  fprintf(log, "Player 2 targeted Player 1 at ROW %d COL %d\n", y, x);

  if (who_is != NULL) {
    // It's a hit
    // Update the ships hits
    state->p1_board->hits[x][y] = 1;
    state->p2_stats->total_hits += 1;
    state->p2_stats->total_shots += 1;
    update_board(state->p1_board, state->p1_fleet, 5);

    fprintf(log, "Player 2 hit Player 1's %s\n", ship_names[who_is->type]);
    printf("Their missle hit your %s!\n\n", ship_names[who_is->type]);
    display_board(state->p1_board);
    printf("\n");
    wait_for_continue();
  } else {
    // It's not a hit
    state->p1_board->misses[x][y] = 1;
    state->p2_stats->total_misses += 1;
    state->p2_stats->total_shots += 1;
    update_board(state->p1_board, state->p1_fleet, 5);

    fprintf(log, "Player 2 missed\n");
    printf("Their missle missed!\n\n");
    display_board(state->p1_board);
    printf("\n");
    wait_for_continue();
  }

  fclose(log);
  return 0;
}

int kaboom_scene(char input, State* state) {
  Coord cursor = *state->cursor;
  Ship* who_is = state->p2_board->who_is[cursor.x][cursor.y];
  FILE* log = open_log();
  fprintf(log, "Player 1 targeted Player 2 at ROW %d COL %d\n", cursor.y, cursor.x);

  if (who_is != NULL) {
    // It's a hit
    // Update the ships hits
    state->p2_board->hits[cursor.x][cursor.y] = 1;
    state->p1_stats->total_hits += 1;
    state->p1_stats->total_shots += 1;
    update_board(state->p2_board, state->p2_fleet, 5);

    fprintf(log, "Player 1 hit Player 2's %s\n", ship_names[who_is->type]);
    printf("The missle hit their %s!\n\n", ship_names[who_is->type]);
    display_strike(state->p2_board, state->cursor, 0);
    printf("\n");
    wait_for_continue();
  } else {
    // It's not a hit
    state->p2_board->misses[cursor.x][cursor.y] = 1;
    state->p1_stats->total_misses += 1;
    state->p1_stats->total_shots += 1;
    update_board(state->p2_board, state->p2_fleet, 5);

    fprintf(log, "Player 1 missed\n");
    printf("The missle missed!\n\n");
    display_strike(state->p2_board, state->cursor, 0);
    printf("\n");
    wait_for_continue();
  }

  fclose(log);
  return 0;
}

int strike_scene(char input, State* state) {
  switch (tolower(input)) {
    case 'w': move_cursor(-1, 0, state); break;
    case 's': move_cursor(1, 0, state); break;
    case 'a': move_cursor(0, -1, state); break;
    case 'd': move_cursor(0, 1, state); break;
    case '\r':
      // Kaboom
      goto_scene(kaboom_scene, state);
      stop_cursor(state->cursor);
      return 0;
      break;
  }

  if (is_cursor_active(state->cursor) != 1) {
    start_cursor(state->cursor);
  }

  printf("Use WASD to select a tile to strike!\n\n");
  display_strike(state->p2_board, state->cursor, 1);
  printf("\nPress ENTER to send the missle when ready.\n");

  return 1;
}

void calculate_stats(Stats* stats) {
  stats->hits_to_misses = (double)stats->total_hits / (double)stats->total_misses;
}

void log_stats(Stats* stats, FILE* log) {
  fprintf(log, "Total Hits: %d\n", stats->total_hits);
  fprintf(log, "Total Misses: %d\n", stats->total_misses);
  fprintf(log, "Total Shots: %d\n", stats->total_shots);
  fprintf(log, "Hits to Misses Ratio: %.2f\n", stats->hits_to_misses);
  fprintf(log, "Is Winner: %d\n", stats->is_winner);
}

int game_scene(char input, State* state) {
  if (state->is_setup == 0) { // If the game hasn't been setup, then setup
    goto_scene(setup_scene, state);
    state->is_setup = 1;
  }

  // Check for any winners
  int winner = -1;
  if (state->p1_stats->total_hits == 17) {
    winner = 1;
    state->p1_stats->is_winner = 1;
  } else if (state->p2_stats->total_hits == 17) {
    winner = 2;
    state->p2_stats->is_winner = 1;
  }

  if (winner != -1) {
    FILE* log = open_log();
    fprintf(log, "Player %d has won!\n", winner);
    printf("Player %d has won!\n\n", winner);

    calculate_stats(state->p1_stats);
    fprintf(log, "Player 1 Stats:\n");
    log_stats(state->p1_stats, log);

    calculate_stats(state->p2_stats);
    fprintf(log, "Player 2 Stats:\n");
    log_stats(state->p2_stats, log);

    fprintf(log, "End\n");
    fclose(log);
    wait_for_continue();
    return 0;
  }

  // Show the game boards
  clear_terminal();
  display_all_boards(state);

  if ((state->rounds % 2) == 0) {
    // Let the player attack the computer
    printf("\nReady to strike? ");
    wait_for_continue();
    goto_scene(strike_scene, state);
  } else {
    // Let the computer attack back
    color(YELLOW); printf("\nMISSLE INCOMING! "); reset();
    wait_for_continue();
    goto_scene(attacked_scene, state);
  }

  state->rounds += 1;
  return 1;
}
