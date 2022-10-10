/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA4
* Date: October 7th, 2022
* Description: This module describes the games logic and rules.
*******************************************************************************************/

#include "game.h"
#include "bank.h"

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
	// printf("Get Menu Key Called: %d\n", key);
	return key;
}

// Since this is the root menu of the game,
// we don't need to set it up as a game scene.
void display_main_menu() {
	printf("Game Menu:\n");
	printf("1. Play Craps\n");
	printf("2. Craps Rules\n");
	printf("3. Bank Balance\n");
	printf("4. Exit\n");
	printf("\nChoose by entering a menu number\n");
}

// This method allows us to dynamically start
// any game scene and enable user navigation
void goto_scene(int (*scene)(int)) {
	int continue_scene = 1;
	int current_input = -1;

	// Start the scene with a garbage state
	clear_terminal();
	continue_scene = (*scene)(current_input);

	// Begin reading user value
	while (continue_scene == 1) {
		// Give the option for the user to leave the scene
		printf("\nPress 0 to go back.\n");
		current_input = get_menu_key();

		if (current_input == 0) {
			continue_scene = 0;
		} else {
			// Call the scene with the updated state
			clear_terminal();
			continue_scene = (*scene)(current_input);
		}
	}
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

int rules_scene(int input) {
  // Normally in a scene, the input would be evaluated.
  // But since we're just showing the rules, there's
  // no interactivity to this scene, so just print
  // the game rules.
  display_game_rules();

  return 1;
}

int create_bank_scene(int input) {
  Checking account = read_account();
  printf("Bank account has not been setup\n");
  double deposit = 0.0;
  printf("To set up an account,\n");
  printf("please enter an account deposit amount: ");
  scanf(" %lf", &deposit);
  double new_bal = update_checking(&account, deposit);
  printf("\nYour new account balance is $%.2lf\n", new_bal);

  return 0;
}

int read_bank_scene(int input) {
  Checking account = read_account();
  printf("Bank balance: $%.2lf\n", account.balance);

  return 0;
}

int check_bank_scene(int input) {
  Checking account = read_account();
  
  if (account.has_setup == 0) {
    goto_scene(create_bank_scene);
  } else {
    goto_scene(read_bank_scene);
  }

  return 1;
}

int game_scene(int input) {
  Checking account = read_account();
  int account_req = account.has_setup;
  int wager_req = 0;

  // Keep asking the user to set up an account
  // until they do it successfully.
  // We need a while loop here to help with
  // bad user inputs.
  while (account_req == 0) {
    goto_scene(create_bank_scene);
    account = read_account();
    account_req = account.has_setup;
  }

  // Same story here as the account requirement.
  // Helps with users entering bad wagers.
  while (wager_req == 0) {
    printf("Enter your wager: ");
    double wager = 0.0;
    scanf(" %lf", &wager);
    printf("\n");

    if (wager > account.balance) {
      printf("Please enter a wager less than or equal to your bank balance!\n");
      printf("Your balance is: $%.2lf\n", account.balance);
    } else {
      wager_req = 1;
    }
  }

  printf("lets play craps... :) \n");
  return 1;
}
