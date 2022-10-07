/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA4
* Date: October 7th, 2022
* Description: Write a program that implements a craps game that allows for wagering.
*******************************************************************************************/

// Header guard to ensure that our code is only included once by the compiler
#ifndef GAME_H

// Define contstants
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS // To ignore scanf warning

// The required libraries
#include <stdio.h> // Include our standard functions for interacting with the IO stream
#include <math.h> // Used to get access to pow, sqrt, fmod function

// Prints out the rules of the game of "craps".
void print_game_rules(void);

// Prompts the player for an initial bank balance from which wagering will be added or subtracted.
double get_bank_balance(void);

// Prompts the player for a wager on a particular roll.
double get_wager_amount(void);

// Checks to see if the wager is within the limits of the player's available balance.
int check_wager_amount(double wager, double balance);

// Rolls one die. This function should randomly generate a value between 1 and 6, inclusively.
int roll_die(void);

// Sums together the values of the two dice and returns the result
int calculate_sum_dice(int die1_value, int die2_value);

// Determines the result of the first dice roll.
int is_win_loss_or_point(int sum_dice);

// Determines the result of any successive roll after the first roll.
int is_point_loss_or_neither(int sum_dice, int point_value);

// Modifies the bank balance.
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);

// Prints a message dependent on the number of rolls taken by the player.
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);

#endif
