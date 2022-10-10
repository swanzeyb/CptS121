/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA4
* Date: October 7th, 2022
* Description: This module implements a simple checking account system with persistence.
*******************************************************************************************/

#include "bank.h"

double read_double(FILE *infile) {
  double value = 0.0;
  fscanf(infile, "%lf", &value);
  return value;
}

Checking read_account() {
  FILE* record = fopen("bank.dat", "r");
  double balance = read_double(record);
  fclose(record);

  // Declare new account
  // Set 0 balance and flag that it is not setup
  Checking account = { 0, 0.0 };
  if (balance < 0.1) {
    account.has_setup = 0;
  } else {
    account.has_setup = 1;
    account.balance = balance;
  }

  return account;
}

void save_account(Checking *account) {
  FILE* record = fopen("bank.dat", "w");
  fprintf(record, "%.2lf", account->balance);
  fclose(record);
}

double create_checking(Checking *account, double deposit) {
  // Using the -> operator, we can modify the members of
  // the struct Checking. This lets us set the inital
  // bank account balance here.
  account->balance = deposit;
  save_account(account); // Update on disk
  return deposit;
}

double read_checking(Checking *account) {
  return account->balance;
}

double update_checking(Checking *account, double difference) {
  account->balance += difference;
  save_account(account); // Update on disk
  return account->balance;
}
