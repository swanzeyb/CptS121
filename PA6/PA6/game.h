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

// -- Helper functions --
void clear_terminal();
int get_menu_key();
int sum_array(int nums[], int length);
int is_zero_default(int val_one, int val_two);
void blue();
void green();
void reset();

// -- The functions that purely print info to console --
void display_main_menu();
void display_rules();

// -- The components that make up scenes --
int roll_die(void);

// -- The games main scenes --
void goto_scene(int (*scene)(int));
int rules_scene(int input);
int game_scene(int input);

// -- The functions that modify game state --

#endif
