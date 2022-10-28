/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA4
* Date: October 7th, 2022
* Description: This module describes the games logic and rules.
*******************************************************************************************/

#include "game.h"
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

int sum_array(int nums[], int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += nums[i];
  }
  return sum;
}

// In JavaScript, I would normally just the logical OR operator
// But it seems like that returns different values in C
// So this let's us do a default value if val_one is zero.
int is_zero_default(int val_one, int val_two) {
  if (val_one != 0) {
    return val_one;
  } else {
    return val_two;
  }
}

// I want to print in color, so I found this StackOverflow that lists
// the ANSI codes to change the print color!
// https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
void blue() {
  printf("\033[0;96m");
}

void green() {
  printf("\033[0;32m");
}

void reset() {
  printf("\033[0m");
}


void highlight_point(char format[], int curr_point, int new_point) {
  // Basically, if it's a new point and it's available highlight it
  if (new_point != 0 && curr_point == 0) {
    green();
    printf(format, new_point);
    reset();
  } else {
    printf(format, curr_point);
  }
}

// Since this is the root menu of the game,
// we don't need to set it up as a game scene.
void display_main_menu() {
	printf("Yahtzee Menu:\n");
	printf("1. Play Yahtzee\n");
	printf("2. Yahtzee Rules\n");
	printf("3. Exit\n");
	printf("\nChoose by entering a menu number\n");
}

void display_rules() {
  /*
    The following rules were directly taken from an online source.
    https://www.onlinegambling.com/casino/craps/how-to-play/
  */
  printf("How to Yahtzee:\n");
}

void display_scorecard(GameState state) {
  printf("Players         P1   P2\n");
  printf("Ones            %d | %d\n", state.upper[0][0], state.upper[1][0]);
  printf("Twos            %d | %d\n", state.upper[0][1], state.upper[1][1]);
  printf("Threes          %d | %d\n", state.upper[0][2], state.upper[1][2]);
  printf("Fours           %d | %d\n", state.upper[0][3], state.upper[1][3]);
  printf("Fives           %d | %d\n", state.upper[0][4], state.upper[1][4]);
  printf("Sixes           %d | %d\n", state.upper[0][5], state.upper[1][5]);
  printf("Sum             %d | %d\n", state.sum[0], state.sum[1]);
  printf("Bonus           %d | %d\n", state.bonus[0], state.bonus[1]);
  printf("3 of a Kind     %d | %d\n", state.three_kind[0], state.three_kind[1]);
  printf("4 of a Kind     %d | %d\n", state.four_kind[0], state.four_kind[1]);
  printf("Full House      %d | %d\n", state.full_house[0], state.full_house[1]);
  printf("Small Straight  %d | %d\n", state.small_straight[0], state.small_straight[1]);
  printf("Large Straight  %d | %d\n", state.large_straight[0], state.large_straight[1]);
  printf("Chance          %d | %d\n", state.chance[0], state.chance[1]);
  printf("Yahtzee         %d | %d\n", state.yahtzee[0], state.yahtzee[1]);
  printf("Total           %d | %d\n", state.total[0], state.total[1]);
}

void display_options(GameState state, Points points) {
  // If the new point combo is non zero, and this player hasn't used the combo previously
  // Highlight it so it's obvious they can pick that one.
  int player = state.current_player;
  printf("Available point combinations:\n");
  highlight_point("1.  Ones            %d\n", state.upper[player][1], points.ones);
  highlight_point("2.  Twos            %d\n", state.upper[player][1], points.twos);
  highlight_point("3.  Threes          %d\n", state.upper[player][1], points.threes);
  highlight_point("4.  Fours           %d\n", state.upper[player][1], points.fours);
  highlight_point("5.  Fives           %d\n", state.upper[player][1], points.fives);
  highlight_point("6.  Sixes           %d\n", state.upper[player][1], points.sixes);
  highlight_point("7.  3 of a Kind     %d\n", state.three_kind[player], points.three_kind);
  highlight_point("8.  4 of a Kind     %d\n", state.four_kind[player], points.four_kind);
  highlight_point("9.  Full House      %d\n", state.full_house[player], points.full_house);
  highlight_point("10. Small Straight  %d\n", state.small_straight[player], points.small_straight);
  highlight_point("11. Large Straight  %d\n", state.large_straight[player], points.large_straight);
  highlight_point("12. Chance          %d\n", state.chance[player], points.chance);
  highlight_point("13. Yahtzee         %d\n", state.yahtzee[player], points.yahtzee);
}

void display_dice(int dice[]) {
  printf("\nThe dice are: \n");
  for (int i = 0; i < 5; i++) {
    int value = dice[i];
    printf("| %d |    ", value);
  }
  printf("\n\n");
}

int roll_die(void) {
  // This is supposed to make random return different values each
  // time the program run, but it doesn't seem to do anything.
  return (rand() % 6) + 1;
}

void roll_component(int dice[]) {
  printf("Ready? Enter R to roll the dice!\n");

  char roll_input = '\0'; // We aren't going to check, it's just for the lolz
  scanf(" %c", &roll_input);

  for (int i = 0; i < 5; i++) {
    dice[i] = roll_die();
  }
}

// This method allows us to dynamically start
// any game scene and enable user navigation
void goto_scene(int (*scene)(int)) {
	int continue_scene = 1;
	int current_input = -1;

	// Start the scene with a garbage input state
	clear_terminal();
	continue_scene = (*scene)(current_input);

	// Begin reading user value
	while (continue_scene == 1) {
		// Give the option for the user to leave the scene
		printf("Press 0 to go back.\n");
		current_input = get_menu_key();

		if (current_input == 0) {
			continue_scene = 0;
      // Reseting the point regardless of the current scene assures that
      // when the user navigates away from the game but then comes back,
      // they get a fresh game state to start with.

      // reset_game()
		} else {
			// Call the scene with the updated state
			clear_terminal();
			continue_scene = (*scene)(current_input);
		}
	}
}

int rules_scene(int input) {
  // Normally in a scene, the input would be evaluated.
  // But since we're just showing the rules, there's
  // no interactivity to this scene, so just print
  // the game rules.
  display_rules();

  // Returning 1 tells the scene manager to wait until the user navigates away
  return 1;
}

int same_kind_points(int count[], int same_amount) {
  int has_point = 0;
  int total = 0;
  for (int i = 0; i < 6; i++) {
    int amount = count[i];
    total += i * amount;
    if (amount == same_amount) {
      has_point = 1;
    }
  }
  return has_point * total;
}

int full_house_points(int count[]) {
  int two_kind = same_kind_points(count, 2);
  int three_kind = same_kind_points(count, 3);

  if (two_kind != 0 && three_kind != 0) {
    return 25;
  } else {
    return 0;
  }
}

int straight_points(int dice[], int how_many, int reward) {
  int last = 0;
  int count = 0;
  for (int i = 0; i < 5; i++) {
    int value = dice[i];
    if ((value - last) == 1) {
      // If the difference is one, it's sequential
      count += 1;
    } else {
      // Else it's no sequential, so just reset the count
      count = 0;
    }
    if (count == how_many) {
      // If there were 4 in a row give them the point
      return reward;
    }
    last = value;
  }
  return 0;
}

int yahtzee_points(int count[]) {
  int five_kind = same_kind_points(count, 5);
  if (five_kind != 0) {
    return 50;
  }
  return 0;
}

Points calculate_points(int dice[]) {
  int count[6] = { 0 };

  for (int i = 0; i < 5; i++) {
    int value = dice[i] - 1; // Subtract 1 to reference an array index
    count[value] += 1;
  }
  
  Points points = {
    /* Ones */           count[0],
    /* Twos */           2 * count[1],
    /* Threes */         3 * count[2],
    /* Fours */          4 * count[3],
    /* Fives */          5 * count[4],
    /* Sixes */          6 * count[5],
    /* 3 Kind */         same_kind_points(count, 3),
    /* 4 Kind */         same_kind_points(count, 4),
    /* Full House */     full_house_points(count),
    /* Small Straight */ straight_points(dice, 4, 30),
    /* Large Straight */ straight_points(dice, 5, 40),
    /* Chance */         sum_array(dice, 5),
    /* Yahtzee */        yahtzee_points(count),
  };

  return points;
}

void update_points(GameState state, int player, Points points) {
  state.upper[player][0] = points.ones;
  state.upper[player][1] = points.twos;
  state.upper[player][2] = points.threes;
  state.upper[player][3] = points.fours;
  state.upper[player][4] = points.fives;
  state.upper[player][5] = points.sixes;
  state.three_kind[player] = points.three_kind;
  state.four_kind[player] = points.four_kind;
  state.full_house[player] = points.full_house;
  state.small_straight[player] = points.small_straight;
  state.large_straight[player] = points.large_straight;
  state.chance[player] = points.chance;
  state.yahtzee[player] = points.yahtzee;
}

GameState state = {
  0, 0,
  { { 0 }, { 0 } },
  { 0 }, { 0 },
  { 0 }, { 0 },
  { 0 }, { 0 },
  { 0 }, { 0 },
  { 0 }, { 0 }
};

int game_scene(int input) {
  int dice[5] = { 0 };

  roll_component(dice);
  display_dice(dice);
  Points potential = calculate_points(dice);
  display_options(state, potential);
  int choice = get_menu_key();
  
  // printf("\n");
  // printf("  Enter 1 to continue\n");
  // printf("  > OR <\n  ");
  return 1;
}
