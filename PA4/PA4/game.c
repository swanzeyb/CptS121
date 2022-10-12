/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA4
* Date: October 7th, 2022
* Description: This module describes the games logic and rules.
*******************************************************************************************/

#include "game.h"
#include "bank.h"
#include <stdlib.h>

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

int points = -1;

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
		printf("Press 0 to go back.\n");
		current_input = get_menu_key();

		if (current_input == 0) {
			continue_scene = 0;
      points = -1;
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

// Set a module-scoped bank acc variable
Checking account = { 0, 0.0 };

int create_bank_scene(int input) {
  account = read_account();
  printf("Bank account has not been setup\n");
  double deposit = 0.0;
  printf("Please enter an account deposit amount: ");
  scanf(" %lf", &deposit);
  double new_bal = update_checking(&account, deposit);
  printf("\nYour new account balance is $%.2lf\n", new_bal);

  return 0;
}

int read_bank_scene(int input) {
  account = read_account();
  printf("Bank balance: $%.2lf\n", account.balance);

  return 0;
}

int check_bank_scene(int input) {
  account = read_account();
  
  if (account.has_setup == 0) {
    goto_scene(create_bank_scene);
  } else {
    goto_scene(read_bank_scene);
  }

  return 1;
}

double get_wager_amount(double balance) {
  int wager_req = 0;
  double wager = 0.0;
  while (wager_req == 0) {
    printf("Enter your wager: ");
    scanf(" %lf", &wager);

    if (wager > balance) {
      printf("You don't have enough for that wager!\n");
      printf("Your balance is: $%.2lf\n\n", balance);
    } else {
      wager_req = 1;
    }
  }
  return wager;
}

double get_bank_balance(void) {
  account = read_account();
  int account_req = account.has_setup;

  // Keep asking the user to set up an account until they do it successfully.
  // We need a while loop here to help with bad user inputs.
  while (account_req == 0) {
    goto_scene(create_bank_scene);
    account = read_account();
    account_req = account.has_setup;
  }

  return account.balance;
}

int roll_die(void) {
  srand(time(NULL));
  return (random() % 6) + 1;
}

int calculate_sum_dice (int die1_value, int die2_value) {
  return die1_value + die2_value;
}

int is_win_loss_or_point(int sum_dice) {
  int score_chart[11] = {
    /* 2 */  0,
    /* 3 */  0,
    /* 4 */  -1,
    /* 5 */  -1,
    /* 6 */  -1,
    /* 7 */  1,
    /* 8 */  -1,
    /* 9 */  -1,
    /* 10 */ -1,
    /* 11 */ 1,
    /* 12 */ 0
  };
  int win_loss_point = score_chart[sum_dice - 2];
  if (win_loss_point == -1) {
    return sum_dice;
  } else {
    return win_loss_point;
  }
}

int is_point_loss_or_neither(int sum_dice, int point_value) {
  if (sum_dice == point_value) {
    return 1;
  } else if (sum_dice == 7) {
    return 0;
  } else {
    return -1;
  }
}

// void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) {

// }

double wager = -1;

int do_roll() {
  printf("Your wager is $%.2lf\n\n", wager);
  printf("Ready? Enter R to roll the dice!\n");

  char roll_input = '\0'; // We aren't going to check, it's just for the lolz
  scanf(" %c", &roll_input);

  int die1 = roll_die();
  int die2 = roll_die();

  printf("\n The dies are \n");
  printf("-- %d --\n", die1);
  printf("-- %d --\n", die2);

  int die_sum = calculate_sum_dice(die1, die2);
  printf("\nThe die sum is %d\n\n", die_sum);

  return die_sum;
}

int game_scene(int input) {
  if (points != -1) {
    printf("The game point is now %d\n\n", points);
  }

  double balance = get_bank_balance();
  wager = get_wager_amount(balance);

  int die_sum = do_roll();

  int outcome = -1;
  if (points != -1) {
    outcome = is_point_loss_or_neither(die_sum, points);
  } else {
    outcome = is_win_loss_or_point(die_sum);
  }

  if (outcome == 1) {
    // They won the bet, add the wager
    update_checking(&account, wager);
    points = -1;
    printf("You won $%.2lf!\n", wager);
  } else if (outcome == 0) {
    // They lost the bet, subtract the wager
    update_checking(&account, wager * -1.0);
    points = -1;
    printf("You lost $%.2lf :(\n", wager);
  } else {
    if (points == -1) {
      points = die_sum;
    }
    update_checking(&account, wager * -1.0);
    printf("You lost $%.2lf :(\n", wager);
  }

  // chatter_messages();

  printf("\nKeep playing!\n");
  printf("  Enter 1 to continue\n");
  printf("  > OR <\n  ");
  return 1;
}
