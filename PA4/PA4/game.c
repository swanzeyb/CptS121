/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA4
* Date: October 7th, 2022
* Description: Write a program that implements a craps game that allows for wagering.
*******************************************************************************************/

#include "game.h"

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
    // system("clear");
  #endif
}

void display_game_rules() {
  /*
    The following rules were directly taken from an online source.
    https://www.onlinegambling.com/casino/craps/how-to-play/
  */
  printf("How to Play Craps:\n");
  printf("1. Start with a bet.\n");
  printf(" - All craps games begin with a 'pass line' bet.\n");
  printf(" - Here, you bet that the dice will land on a 7 or 11 ('pass the line') or on a 2, 3, or 12 ('don't pass').\n");

  printf("\n2. Roll the dice.\n");
  printf(" - The shooter will start the game with the first roll of the dice, known as the 'comeout roll'.\n");

  printf("\n3. Check your first bets.\n");
  printf(" - If the dice lands on 7 or 11 on the comeout roll, pass line bets instantly win.\n");
  printf(" - Don't pass bets win if the dice lands on a combined 2, 3, or 12.\n");
  printf(" - If the dice lands on any other number, your pass or don't pass bets remain in play for subsequent rolls.\n");

  printf("\n4. Establish a point.\n");
  printf(" - Any other numbers (4, 5, 6, 8, 9, or 10) the dice lands on from the comeout roll establishes that number as the 'point' on the craps table.\n");
  printf(" - Game play continues (as well as your pass or don't pass bets) until the point number is rolled again or a 7 is rolled.\n");
  
  printf("\n5. Add to your bets.\n");
  printf(" - Once a point has been set, you can then bet on the dice landing the point, landing on different numbers, or losing completely by landing on 7.\n");
  
  printf("\n6. Continue to shoot.\n");
  printf(" - The shooter will keep rolling the dice (and you can keep betting) until they land a 7 or the point.\n");
  
  printf("\n7. End the round.\n");
  printf(" - If the point is rolled before a 7, all pass line bets will win.\n");
  printf(" - If a 7 is rolled before the point, all pass line bets will lose and all don't pass bets will win instead.\n");
}

void rules_scene(int input) {
  // Normally in a scene, the input would be evaluated.
  // But since we're just showing the rules, there's
  // no interactivity to this scene, so just print
  // the game rules.
  display_game_rules();
}

void game_scene(int input) {
  printf("Game not implemented yet\n");
}
