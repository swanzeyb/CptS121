/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA6
* Date: November 2nd, 2022
* Description: This module describes the games logic and rules.
*******************************************************************************************/

// I dev on a Mac, graders use Windows
#if defined(_WIN64) || defined(_WIN32)
  #include <conio.h>
#endif

// Header guard to ensure that our code is only included once by the compiler
#ifndef GAME_H

// Define contstants
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS // To ignore scanf warning

// The required libraries
#include <stdio.h> // Include our standard functions for interacting with the IO stream
#include <stdlib.h> // Gives us access to system function
#include <time.h> // This gives access to time func used in srand
#include <stdbool.h> // I prefer bools over ints
#include <string.h> // atoi

typedef enum {
  SUIT_HEARTS = 0,
  SUIT_DIAMONDS = 1,
  SUIT_CLUBS = 2,
  SUIT_SPADES = 3,
} Suits;

typedef enum {
  FACE_ACE = 0,
  FACE_DEUCE = 1,
  FACE_THREE = 2,
  FACE_FOUR = 3,
  FACE_FIVE = 4,
  FACE_SIX = 5,
  FACE_SEVEN = 6,
  FACE_EIGHT = 7,
  FACE_NINE = 8,
  FACE_TEN = 9,
  FACE_JACK = 10,
  FACE_QUEEN = 11,
  FACE_KING = 12,
} Faces;

typedef struct {
  Suits suit;
  Faces face;
  bool used;
} Card;

typedef enum {
  RANK_STRAIGHT_FLUSH = 8,
  RANK_FOUR_KIND = 7,
  RANK_FULL_HOUSE = 6,
  RANK_FLUSH = 5,
  RANK_STRAIGHT = 4,
  RANK_THREE_KIND = 3,
  RANK_TWO_PAIR = 2,
  RANK_PAIR = 1,
  RANK_HIGH_CARD = 0,
} Rank;

typedef struct {
  Card cards[5];
  Card* max;
  Rank rank;
  int replaced;
} Hand;

typedef enum {
  STAGE_DEAL = 0,
  STAGE_REPLACE = 1,
  STAGE_SHOWDOWN = 2,
  STAGE_COMPLETE = 3,
} Stage;

typedef struct {
  Card* deck;
  Hand* p1_hand;
  Hand* p2_hand;
  Stage stage;
} State;

// I want to support a bunch of different colors,
// and I found out that C supports enums so ima
// try them out.
typedef enum {
  COLOR_BLACK = 30,
  COLOR_RED = 31,
  COLOR_GREEN = 32,
  COLOR_YELLOW = 33,
  COLOR_BLUE = 34,
  COLOR_MAGENTA = 35,
  COLOR_CYAN = 36,
  COLOR_GRAY = 37,
  COLOR_CRIMSON = 38,
  COLOR_ALT_GRAY = 90,
  COLOR_ALT_RED = 91,
  COLOR_ALT_GREEN = 92,
  COLOR_ALT_YELLOW = 93,
  COLOR_ALT_BLUE = 94,
  COLOR_ALT_MAGENTA = 95,
  COLOR_ALT_CYAN = 96,
  COLOR_WHITE = 97,
  COLOR_BG_BLACK = 40,
  COLOR_BG_RED = 41,
  COLOR_BG_GREEN = 42,
  COLOR_BG_YELLOW = 43,
  COLOR_BG_BLUE = 44,
  COLOR_BG_MAGENTA = 45,
  COLOR_BG_CYAN = 46,
  COLOR_BG_WHITE = 47,
  COLOR_BG_CRIMSON = 48,
} Colors;

// -- Helper functions --
void clear_terminal();
int get_menu_key();
char wait_for_input();
int is_zero_default(int val_one, int val_two);
void color(Colors color);
void reset();
int rand_num(int len);
int arr_max(int arr[], int len);

// -- The functions that purely print info to console --
void display_main_menu();
void display_rules();

// -- The components that make up scenes --
// int roll_die(void);

// -- The games main scenes --
void goto_scene(bool (*scene)(char, State*), State* state);
bool rules_scene(char input, State* state);
bool game_scene(char input, State* state);

// -- Game Stuff
void init_deck(Card deck[52]);
void shuffle(Card deck[52]);
void deal_hand(Card deck[52], Hand* hand);

#endif
