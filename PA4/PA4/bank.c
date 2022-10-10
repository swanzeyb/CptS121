/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA4
* Date: October 7th, 2022
* Description: Write a program that implements a craps game that allows for wagering.
*******************************************************************************************/

#include "bank.h"

double create_checking(Checking *account, double deposit) {
  // Using the -> operator, we can modify the members of
  // the struct Checking. This lets us set the inital
  // bank account balance here.
  account->balance = deposit;
  return deposit;
}

double read_checking(Checking *account) {
  return account->balance;
}

double update_checking(Checking *account, double difference) {
  account->balance += difference;
  return account->balance;
}
