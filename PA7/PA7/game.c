/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA6
* Date: November 2nd, 2022
* Description: This module describes the games logic and rules.
*******************************************************************************************/

#include "game.h"

void deal (const int wDeck[][13], const char *wFace[], const char *wSuit[]) {
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
 
	/* deal each of the 52 cards */
	for (card = 1; card <= 52; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					printf ("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

void clear_terminal() {
  // According to one source, there is standard constants
  // defined by the compiler that tells us what system we
  // are compiling for. Since I use Mac and the graders use
  // Windows, this should give cross-system compatibility.
  #if defined(_WIN64) || defined(_WIN32)
    system("cls");
  #elif defined(__APPLE__)
    system("clear");
  #endif
}

int get_menu_key() {
	int key = 0;
  #if defined(_WIN64) || defined(_WIN32)
    scanf_s(" %d", &key);
  #elif defined(__APPLE__)
    scanf(" %d", &key);
  #endif
	return key;
}

void color(Colors color) {
  // I want to print in color, so I found this StackOverflow that lists
  // the ANSI codes to change the print color!
  // https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
  printf("\x1b[%dm", color);
}

void reset() {
  printf("\033[0m");
}

int rand_num(int len) {
  return (rand() % len);
}

int arr_max(int arr[], int len) {
  int max = arr[0];
  for (int i = 0; i < len; i ++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

// Since this is the root menu of the game,
// we don't need to set it up as a game scene.
void display_main_menu() {
	printf("Poker Menu:\n");
	printf("1. Play Poker\n");
	printf("2. Poker Rules\n");
	printf("3. Exit\n");
	printf("\nChoose by entering a menu number\n");
}

void display_rules() {
  /*
    The following rules were directly taken from an online source.
    https://www.contrib.andrew.cmu.edu/~gc00/reviews/pokerrules#:~:text=Five%20card%20draw%20is%20one,cards%20as%20he%2Fshe%20discarded.
  */
  printf("Poker is played from a standard pack of 52 cards.\n");
  printf("The cards are ranked (from high to low) Ace, King, Queen, Jack, 10, 9, 8, 7, 6, 5, 4, 3, 2, Ace. \n");
  printf("There are four suits (spades, hearts, diamonds and clubs); however, no suit is higher than another.\n");
  printf("All poker hands contain five cards, the highest hand wins.\n");
  // See citation above.
}

char wait_for_input() {
  while (1) {
    #if defined(_WIN64) || defined(_WIN32)
      char in = _getch();
    #elif defined(__APPLE__)
      fflush(stdin);
      system("/bin/stty raw");
      char in = getchar();
      system("/bin/stty cooked");
    #endif
    if ((in != '\n') && (in != ' ')) {
      return in;
    }
  }
}

void wait_for_continue() {
  printf("Press any key to continue\n");
  wait_for_input();
}

// Structures
void init_deck(Card deck[52]) {
  for (int s = 0; s < 4; s++) {
    for (int c = 0; c < 13; c++) {
      int i = (s * 13) + c + 1; // Current position in deck
      Card card = {
        s, // Suit
        c, // Card Value
        false, // Has been used
      };
      deck[i] = card;
    }
  }
}

// Game Logic
bool has_same_count(Hand* hand, int amount) {
  for (int i = 0; i < 5; i++) {
    int curr_face = hand->cards[i].face;
    int like_count = 1;
    for (int j = 0; j < 5; j++) {
      int eval_face = hand->cards[j].face;
      if ((i != j) && (curr_face == eval_face)) {
        like_count += 1;
      }
    }
    if (like_count == amount) {
      return true;
    }
  }
  return false;
}

Rank has_pair(Hand* hand) {
  if (has_same_count(hand, 2)) {
    return RANK_PAIR;
  } else {
    return RANK_HIGH_CARD;
  }
}

Rank has_three_kind(Hand* hand) {
  if (has_same_count(hand, 3)) {
    return RANK_THREE_KIND;
  } else {
    return RANK_HIGH_CARD;
  }
}

Rank has_four_kind(Hand* hand) {
  if (has_same_count(hand, 4)) {
    return RANK_FOUR_KIND;
  } else {
    return RANK_HIGH_CARD;
  }
}

Rank has_two_pair(Hand* hand) {
  int pair_count = 0;
  for (int i = 0; i < 5; i++) {
    int curr_face = hand->cards[i].face;
    int like_count = 0;
    for (int j = 0; j < 5; j++) {
      int eval_face = hand->cards[i].face;
      if ((i != j) && (curr_face == eval_face)) {
        like_count += 1;
      }
    }
    if (like_count == 1) {
      pair_count += 1;
    }
    if (pair_count == 2) {
      return RANK_TWO_PAIR;
    }
  }
  return RANK_HIGH_CARD;
}

Rank has_full_house(Hand* hand) {
  if (has_same_count(hand, 2) && has_same_count(hand, 3)) {
    return RANK_FULL_HOUSE;
  } else {
    return RANK_HIGH_CARD;
  }
}

Rank has_flush(Hand* hand) {
  for (int i = 1; i < 5; i++) {
    int last = hand->cards[i - 1].suit;
    int next = hand->cards[i].suit;
    if (last != next) {
      return RANK_HIGH_CARD;
    }
  }
  return RANK_FLUSH;
}

Rank has_straight(Hand* hand) {
  int last = hand->cards[0].face;;
  for (int f = 0; f < 5; f++) {
    int next = hand->cards[f].face;
    if (abs(next - last) > 1) {
      return RANK_HIGH_CARD;
    }
    last = next;
  }
  return RANK_STRAIGHT;
}

Rank has_straight_flush(Hand* hand) {
  if (has_straight(hand) != RANK_HIGH_CARD) {
    if (has_flush(hand) != RANK_HIGH_CARD) {
      return RANK_STRAIGHT_FLUSH;
    }
  }
  return RANK_HIGH_CARD;
}

Card* find_high_card(Hand* hand) {
  Card* max = &hand->cards[0];
  for (int i = 1; i < 5; i++) {
    Card* eval = &hand->cards[i];
    if ((eval->face > max->face) && (eval->used == false)) {
      max = eval;
    }
  }
  return max;
}

// Game Functions
void shuffle(Card deck[52]) {
  for (int from = 0; from < 52; from++) {
    int to = rand_num(51); // Find a random place to swap cards
    Card from_card = deck[from];
    Card to_card = deck[to];
    deck[from] = to_card;
    deck[to] = from_card;
  }
}

Rank find_rank(Hand* hand) {
  int ranks[9] = {
    has_straight_flush(hand),
    has_four_kind(hand),
    has_full_house(hand),
    has_flush(hand),
    has_straight(hand),
    has_three_kind(hand),
    has_two_pair(hand),
    has_pair(hand),
  };
  return arr_max(ranks, 9);
}

void update_hand(Hand* hand) {
  hand->max = find_high_card(hand);
  hand->rank = find_rank(hand);
}

void replace_card(Card deck[52], Hand* hand, int to_replace) {
  for (int c = 0; c < 53; c++) {
    Card* card = &deck[c];
    if (card->used != true) {
      hand->cards[to_replace] = *card;
      hand->replaced += 1;
      card->used = true;
      update_hand(hand);
      break;
    }
  }
}

void deal_hand(Card deck[52], Hand* hand) {
  int delt = 0;
  for (int c = 0; c < 53; c++) {
    Card* card = &deck[c];
    if (card->used != true) {
      if (delt < 5) {
        hand->cards[delt] = *card;
        card->used = true;
        delt += 1;
      } else {
        update_hand(hand);
        hand->replaced = 0;
        break;
      }
    }
  }
}

// Names
#if defined(_WIN64) || defined(_WIN32)
  const char *suit_emojis[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
#elif defined(__APPLE__)
  const char *suit_emojis[4] = {"♥️", "♦️", "♣️", "♠️"};
#endif
const char *face_names[13] = {"A ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10 ", "J ", "Q ", "K "};
const char *rank_names[9] = {"High Card", "Pair", "Two Pair", "Three of a Kind", "Straight", "Flush", "Full House", "Four of a Kind", "Straight Flush"};

// Displays
void display_cards(Hand* hand, bool index) {
  for (int i = 0; i < 5; i++) {
    Card card = hand->cards[i];
    color(COLOR_BG_WHITE); printf(" ");
    if (index) {
      color(COLOR_ALT_BLUE);
      printf("%d. ", i + 1);
    }
    color(COLOR_BLACK);
    printf("%s%s  ", face_names[card.face], suit_emojis[card.suit]);
    reset();
    printf("\n\n");
  }
}

void display_rank(Hand* hand, bool is_p1) {
  if (is_p1) {
    printf("Your highest play is a ");
  } else {
    printf("Their highest play is a ");
  }
  color(COLOR_GREEN);
  printf("%s\n", rank_names[hand->rank]);
  reset();
  
  if (hand->rank == RANK_HIGH_CARD) {
    printf("The high card is ");
    color(COLOR_BG_BLACK);
    const char* face_name = face_names[hand->max->face];
    const char* suit_name = suit_emojis[hand->max->suit];
    color(COLOR_WHITE);
    printf(" %s%s  ", face_name, suit_name);
    reset();
    printf("\n");
  }
}

void display_hand(Hand* hand, bool index) {
  printf("Your hand is:\n\n");
  display_cards(hand, index);
  display_rank(hand, true);
}

// This method allows us to dynamically start
// any game scene and enable user navigation
void goto_scene(bool (*scene)(char, State*), State* state) {
  int continue_scene = true;
  int current_input = '\0';

	clear_terminal();
	continue_scene = (*scene)(current_input, state);

	// Begin reading user value
	while (continue_scene == true) {
		current_input = wait_for_input();
    clear_terminal();
    // Keep calling the scene until it returns a non-one int
		continue_scene = (*scene)(current_input, state);
	}
}

bool rules_scene(char input, State* state) {
  if (input == '\0') {
    display_rules();
    printf("\nPress any key to go back.\n");
  } else {
    return false;
  }

  // Returning 1 tells the scene manager to wait until the user navigates away
  return true;
}

bool deal_scene(char input, State* state) {
	init_deck(state->deck);
	shuffle(state->deck);
  deal_hand(state->deck, state->p1_hand);
  deal_hand(state->deck, state->p2_hand);
  return false;
}

bool replace_scene(char input, State* state) {
  int index_num = atoi(&input) - 1;
  switch (input) {
    case '\r':
      return false;
    default:
      if (state->p1_hand->replaced < 3) {
        if (index_num > -1 && index_num < 5) {
          replace_card(state->deck, state->p1_hand, index_num);
        }
      }
      break;
  }

  printf("Enter the index number of card to replace or hit Enter when finished.\n\n");
  display_cards(state->p1_hand, true);
  printf("You've replaced %d of 3 cards.\n", state->p1_hand->replaced);

  return true;
}

bool showdown_scene(char input, State* state) {
  display_hand(state->p1_hand, false);
  printf("\nDealer's hand is:\n\n");
  display_cards(state->p2_hand, false);
  display_rank(state->p2_hand, false);
  printf("\n");

  Rank p1_rank = state->p1_hand->rank;
  Rank p2_rank = state->p2_hand->rank;
  Card* p1_max = state->p1_hand->max;
  Card* p2_max = state->p2_hand->max;

  color(COLOR_BG_MAGENTA);
  if (p1_rank > p2_rank) {
    printf("Your %s beat the dealers %s!", rank_names[p1_rank], rank_names[p2_rank]);
  } else if (p2_rank > p1_rank) {
    printf("The dealer's %s beat your %s!", rank_names[p2_rank], rank_names[p1_rank]);
  } else if (p1_rank == p2_rank) {
    // Compare max card because same rank
    bool has_winner = true;
    do {
      const char* p_f = face_names[p1_max->face];
      const char* p_s = suit_emojis[p1_max->suit];
      const char* d_f = face_names[p2_max->face];
      const char* d_s = suit_emojis[p2_max->suit];
      if (p1_max->face > p2_max->face) {
        printf("Your high card %s%s  beat the dealers %s%s !", p_f, p_s, d_f, d_s);
      } else if (p2_max->face > p1_max->face) {
        printf("The dealer's high card %s%s  beat your %s%s !", d_f, d_s, p_f, p_s);
      } else {
        // Tie again o_o
        p1_max->used = true;
        p1_max = find_high_card(state->p1_hand);
        p2_max->used = true;
        p2_max = find_high_card(state->p2_hand);
        has_winner = false;
      }
    } while (has_winner == false);
  }
  reset(); printf("\n");

  state->stage = STAGE_DEAL;
  printf("Press enter to start a new round.\n");
  return false;
}

bool game_scene(char input, State* state) {
  switch (input) {
    case 'd':
      goto_scene(deal_scene, state);
      state->stage = STAGE_REPLACE;
      break;
    case 'r':
      goto_scene(replace_scene, state);
      state->stage = STAGE_SHOWDOWN;
      break;
    case '\r':
      switch (state->stage) {
        case STAGE_REPLACE:
          state->stage = STAGE_SHOWDOWN; break;
        case STAGE_SHOWDOWN:
          goto_scene(showdown_scene, state);
          return true;
        case STAGE_COMPLETE:
          return false;
      }
      break;
  }

  clear_terminal();

  switch (state->stage) {
    case STAGE_DEAL:
      printf("Press D to have your cards delt\n");
      break;
    case STAGE_REPLACE:
      display_hand(state->p1_hand, false);
      printf("\nPress R to replace any cards or Enter to continue\n");
      break;
    case STAGE_SHOWDOWN:
      display_hand(state->p1_hand, false);
      printf("\nReady to showdown? Press enter to continue\n");
      break;
  }

  return true;
}
