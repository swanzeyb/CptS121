/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 1
* Programming Assignment: PA4
* Date: October 7th, 2022
* Description: Write a program that implements a craps game that allows for wagering.
*******************************************************************************************/

// Header guard to ensure that our code is only included once by the compiler
#ifndef BANK_H

// Define contstants
#define BANK_H
#define _CRT_SECURE_NO_WARNINGS // To ignore scanf warning

// The required libraries
#include <stdio.h> // Include our standard functions for interacting with the IO stream
#include <math.h> // Used to get access to pow, sqrt, fmod function

// User's bank account
struct checking {
	int has_setup;
	double balance;
};

// This tells the compiler that I want to use the checking struct as a type
typedef struct checking Checking;

// Following the CRUD API standard... (even tho this is a library)

double create_checking(Checking *account, double deposit);

double read_checking(Checking *account);

double update_checking(Checking *account, double difference);

#endif
