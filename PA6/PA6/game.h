/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA6
* Date: November 2nd, 2022
* Description: This module describes the games logic and rules.
*******************************************************************************************/

// Header guard to ensure that our code is only included once by the compiler
#ifndef GAME_H

// Define contstants
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS // To ignore scanf warning

// The required libraries
#include <stdio.h> // Include our standard functions for interacting with the IO stream
#include <stdlib.h> // Gives us access to system function
#include <time.h> // This gives access to time func used in srand

// The Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells.
enum Ships {
  NoShip = 0,
  Destroyer = 1,
  Submarine = 2,
  Cruiser = 3,
  Battleship = 4,
  Carrier = 5,
};

// If this was C++, I think I would use polymorphism to extend a base ship class
// and then make all the different ship types.

typedef struct {
  char display;
  int length;
  enum Ships type;
  int is_vert;
  int x_lower;
  int y_lower;
  int x_upper;
  int y_upper;
} Ship;

typedef struct {
  Ship* who_is[10][10];
  char display[10][10];
} Board;

typedef struct {
  Board p1;
  Board p2;
} State;

// I want to support a bunch of different colors,
// and I found out that C supports enums so ima
// try them out.
typedef enum {
  RED = 31,
  GREEN = 32,
  YELLOW = 33,
  BLUE = 34,
  MAGENTA = 35,
  CYAN = 36,
  GRAY = 37,
  ALT_GRAY = 90,
  ALT_RED = 91,
  ALT_GREEN = 92,
  ALT_YELLOW = 93,
  ALT_BLUE = 94,
  ALT_MAGENTA = 95,
  ALT_CYAN = 96,
  WHITE = 97,
} Colors;

// -- Helper functions --
void clear_terminal();
int get_menu_key();
char wait_for_input();
int sum_array(int nums[], int length);
int is_zero_default(int val_one, int val_two);
void color(Colors color);
void reset();

// -- The functions that purely print info to console --
void display_main_menu();
void display_rules();

// -- The components that make up scenes --
int roll_die(void);

// -- The games main scenes --
void goto_scene(int (*scene)(char, State*), State* state);
int rules_scene(char input, State* state);
int game_scene(char input, State* state);

// -- Game Stuff
void init_fleet(Ship fleet[]);
void init_board(Board *board);
void display_board(Board *board);

#endif
