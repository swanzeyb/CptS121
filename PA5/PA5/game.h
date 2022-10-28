/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA4
* Date: October 7th, 2022
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

// Create a new struct to hold the game's score
// If this was C++ I think this would be better as a class
struct GameState {
  int current_player;
  int current_rolls;
  int upper[2][6]; // 2D array can store the upper section points for both players
  // The rest are 2 length arrays to store each users score
  int sum[2];
  int bonus[2];
  int three_kind[2];
  int four_kind[2];
  int full_house[2];
  int small_straight[2];
  int large_straight[2];
  int chance[2];
  int yahtzee[2];
  int total[2];
};

// This tells the compiler that I want to use the GameState struct as a type
typedef struct GameState GameState;

struct Points {
    /* Ones */           int ones;
    /* Twos */           int twos;
    /* Threes */         int threes;
    /* Fours */          int fours;
    /* Fives */          int fives;
    /* Sixes */          int sixes;
    /* 3 Kind */         int three_kind;
    /* 4 Kind */         int four_kind;
    /* Full House */     int full_house;
    /* Small Straight */ int small_straight;
    /* Large Straight */ int large_straight;
    /* Chance */         int chance;
    /* Yahtzee */        int yahtzee;
};

typedef struct Points Points;

// -- Helper functions --
void clear_terminal();
int get_menu_key();
int sum_array(int nums[], int length);

// -- The functions that purely print info to console --
void display_main_menu();
void display_rules();
void display_scorecard(GameState state);

// -- The components that make up scenes --
int roll_die(void);
void roll_component(int dice[]);

// -- The games main scenes --
void goto_scene(int (*scene)(int));
int rules_scene(int input);
int game_scene(int input);

// -- The functions that perform point calculations
int same_kind_points(int count[], int same_amount);
int full_house_points(int count[]);
int straight_points(int dice[], int how_many, int reward);
int yahtzee_points(int count[]);
Points calculate_points(int dice[]);

// -- The functions that modify game state --
void update_points(GameState state, int player, Points points);

#endif
