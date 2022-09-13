
// guard code. A preprocessor directive
#ifndef EQUATIONS_H
#define EQUATIONS_H

#define _CRT_SECURE_NO_WARNINGS // To ignore scanf warning
#include <stdio.h>

int calculate_series_resistance(int r1, int r2, int r3);
double calculate_total_sales_tax(double sales_tax_rate, double item_cost);
double calculate_volume_pyramid(double l, double w, double h);
double calculate_parallel_resistance(int r1, int r2, int r3);
char encode_character(char plaintext_character, int shift_int);
double calculate_distance(double x1, double y1, double x2, double y2);
double calculate_general_equation(double x, double y, double z, int a);

#endif
