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
#include <stdbool.h> // I'm tired of working with 1's and 0's

// I dev on a Mac, graders use Windows
#if defined(_WIN64) || defined(_WIN32)
  #include <conio.h>
#endif

// I know the boilerplate code was using these arrays, but I like enums better

// const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
typedef enum {
  SUIT_HEARTS = 0,
  SUIT_DIAMONDS = 1,
  SUIT_CLUBS = 2,
  SUIT_SPADES = 3,
} Suits;

// const char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
// typedef enum {
// } Faces;

typedef struct {
} State;

// I want to support a bunch of different colors,
// and I found out that C supports enums so ima
// try them out.
typedef enum {
  COLOR_RED = 31,
  COLOR_GREEN = 32,
  COLOR_YELLOW = 33,
  COLOR_BLUE = 34,
  COLOR_MAGENTA = 35,
  COLOR_CYAN = 36,
  COLOR_GRAY = 37,
  COLOR_ALT_GRAY = 90,
  COLOR_ALT_RED = 91,
  COLOR_ALT_GREEN = 92,
  COLOR_ALT_YELLOW = 93,
  COLOR_ALT_BLUE = 94,
  COLOR_ALT_MAGENTA = 95,
  COLOR_ALT_CYAN = 96,
  COLOR_WHITE = 97,
} Colors;

// -- Helper functions --
void clear_terminal();
int get_menu_key();
char wait_for_input();
int is_zero_default(int val_one, int val_two);
void color(Colors color);
void reset();
int rand_num(int len);

// -- The functions that purely print info to console --
void display_main_menu();
void display_rules();

// -- The components that make up scenes --
// int roll_die(void);

// -- The games main scenes --
void goto_scene(int (*scene)(char, State*), State* state);
int rules_scene(char input, State* state);
int game_scene(char input, State* state);

// -- Game Stuff
// void init_fleet(Ship fleet[]);
// void init_board(Board *board);
// void display_board(Board *board);

#endif
