/*******************************************************************************************
* Programmer: Benjamin Swanzey <benjamin.swanzey@wsu.edu>
* Class: CptS 121, Fall 2022; Lab Section 2
* Programming Assignment: Lab 3
* Date: September 13th, 2022
* Description: Compute the duration of a projectile's flight and its height above the ground when it reaches a target distance.
*******************************************************************************************/

#ifndef PROJECTILE_H_

#define PROJECTILE_H_
#define _CRT_SECURE_NO_WARNINGS // Suppress scanf memory security warnings
#define G 32.17 // Gravitational constant

#include <stdio.h> // Include our standard functions for interacting with the IO stream
#include <math.h> // Used to get access to sin, cos, pow

/*
   Function: get_theta(void)
   Description: Asks the user for the theta angle of the projectile in radians.
   Input Parameters: None.
   Returns: Theta in radians.
   Precondition: The stdio library has been included.
   Postconditions: Theta in radians has been returned.
*/
double get_theta(void);

/*
   Function: get_distance(void)
   Description: Asks the user for the projectile's target distance in feet.
   Input Parameters: None.
   Returns: Distance in feet.
   Precondition: The stdio library has been included.
   Postconditions: Distance in feet has been returned.
*/
double get_distance(void);

/*
   Function: get_velocity(void)
   Description: Asks the user for the velocity of the projectile in ft/sec.
   Input Parameters: None.
   Returns: Velocity in ft/sec.
   Precondition: The stdio library has been included.
   Postconditions: Velocity in ft/sec has been returned.
*/
double get_velocity(void);

/*
   Function: calculate_flight_duration(double distance, double velocity, double theta)
   Description: Calculates flight duration to target distance.
   Input Parameters: Distance in feet, Velocity in ft/sec, and Angle in radians.
   Returns: The duration in seconds to reach the target distance.
   Precondition: Target distance, velocity, and theta have been gathered.
   Postconditions: Flight duration has been calculated and returned.
*/
double calculate_flight_duration(double distance, double velocity, double theta);

/*
   Function: calculate_projectile_height(double velocity, double theta, double time)
   Description: Calculates the projectile's height at a target distance
   Input Parameters: Velocity in ft/sec, Angle in radians, and Time in seconds
   Returns: The height in feet at the target distance.
   Precondition: Flight duration has been calculated, and Velocity and the Angle have been gathered.
   Postconditions: Projectile height has been calculated and returned.
*/
double calculate_projectile_height(double velocity, double theta, double time);

/*
   Function: display_flight_duration(double duration)
   Description: Prints the time the projectile has been in flight.
   Input Parameters: The flight duration of the projectile.
   Returns: None.
   Precondition: Flight duration has been calculated.
   Postconditions: The projectile's flight duration has been printed to the console.
*/
void display_flight_duration(double duration);

/*
   Function: display_projectile_height(double height)
   Description: Prints the height of the projectile.
   Input Parameters: The height of the projectile.
   Returns: None.
   Precondition: The projectile's height has been calculated.
   Postconditions: The projectile's height has been printed to the console.
*/
void display_projectile_height(double height);

#endif
