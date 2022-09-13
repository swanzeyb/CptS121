/*******************************************************************************************
* Programmer: Benjamin Swanzey
* Class: CptS 121, Fall 2022; Lab Section 2
* Programming Assignment: Lab1Task1
* Date: August 30, 2022
* Description: This program prints out a simple "hello world" message.
*******************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

#define PI 3.14

int partA(void) {
	// we need to request memory for
	int number1_int = 0, number2_int = 0; // 2 variable declarations - reserves two memory blocks for integers and sets them to 0's
	double number1_float = 0.0, number2_float = 0.0; // reserves two memory blocks for numbers with high precision (floating-point)

	printf("Enter two integer values: "); // ask user
	scanf("%d%d", &number1_int, &number2_int); // read the integers typed through the keyboard - %d is for "decimal", i.e. integers

	printf("Enter two floating-point values: "); // ask user
	scanf("%lf%lf", &number1_float, &number2_float); // read the integers typed through the keyboard - %lf is for "long float", i.e. double precision numbers
	
	// Add number1_int and number2_int together and print the result as an integer value
	int add_total = number1_int + number2_int;
	printf("Add number1_int and number2_int equals: %d\n", add_total);

	// Subtract number1_float from number2_float and print the result as a floating-point value
	double subtract_total = number1_float - number2_float;
	printf("Subtract number1_float from number2_float equals: %lf\n", subtract_total);

	// Multiply number1_int by number1_float and print the result as an integer value
	int multiply_total = number1_int * number1_float;
	printf("Multiply number1_int and number2_int equals: %d\n", multiply_total);

	// Divide number1_int by number2_int and print the result as an integer and a floating-point value
	double divide_int_total_float = number1_int / number2_int;
	int divide_int_total_int = divide_int_total_float;
	printf("Divide number1_int by number2_int equals %d integer and %lf float\n", divide_int_total_int, divide_int_total_float);

	// Divide number1_int by number2_float and print the result as an integer and a floating-point value
	double divide_lfd_total_float = number1_int / number2_float;
	int divide_lfd_total_int = divide_lfd_total_float;
	printf("Divide number1_int by number2_float equals %d integer and %lf float\n", divide_lfd_total_int, divide_lfd_total_float);

	// Explicitly cast number1_int as a floating-point value and divide by number2_int. Print the result as a floating-point value.
	double number1_int_as_float = (double)number1_int;
	double number1_casted_total = number1_int_as_float / number2_int;
	printf("Divide number1_int as float by number2_int equals %lf\n", number1_casted_total);

	// Try to mod number1_float by number2_float. Does the program compile? If not, fix it so that it does.
	int mod_total = (int)number1_float % (int)number2_float;
	printf("Mod number1_float by number2_float: %d\n", mod_total);

	// Determine if number1_int and number2_int are even or odd. Print 0 if even and 1 if odd. You may not use “if” statements. Use the mod operator instead.
	int number1_int_evenodd = number1_int % 2;
	printf("Is number1_int even or odd? it's: %d\n", number1_int_evenodd);

	int number2_int_evenodd = number2_int % 2;
	printf("Is number2_int even or odd? it's: %d\n", number2_int_evenodd);

	return 0; // return program executed successfully
}

int partB(void) {
	int current = 0, resistance = 0;

	// Ask for current
	printf("Enter current: ");
	scanf("%d", &current);

	// Ask for voltage
	printf("Enter resistance: ");
	scanf("%d", &resistance);

	int voltage = current * resistance;
	printf("Voltage is: %d\n", voltage);

	return 0;
}

int partC(void) {
	// Joule's Law: P = (V^2) / R
	int voltage = 0, resistance = 0;

	// Ask for current
	printf("Enter voltage: ");
	scanf("%d", &voltage);

	// Ask for voltage
	printf("Enter resistance: ");
	scanf("%d", &resistance);

	int power = (voltage * voltage) / resistance;
	printf("Power is: %d\n", power);

	return 0;
}

int partD(void) {
	// y = 3 * ax3 + (1/4) * bx2 + 10 * cx + (-5) * d  (x, y, a, b, c, and d are integer numbers)
	double x, y, a, b, c, d = 0.0;

	printf("Enter x: ");
	scanf("%lf", &x);
	printf("Enter a: ");
	scanf("%lf", &a);
	printf("Enter b: ");
	scanf("%lf", &b);
	printf("Enter c: ");
	scanf("%lf", &c);
	printf("Enter d: ");
	scanf("%lf", &d);

	y = 3 * (a * (x * x * x)) + (1/4) * (b * (x * x)) + 10 * (c * x) + -5 * d;
	printf("Third order polynomial y value: %lf\n", y);

	return 0;
}

int partE(void) {
	// circumference = 2 * PI * radius
	double radius = 0.0;

	printf("Enter radius: ");
	scanf("%lf", &radius);

	double circumference = 2 * PI * radius;
	printf("Circumference of circle: %lf\n", circumference);

	return 0;
}

int main(void) {

	printf("Part A:\n");
	partA();

	printf("\nPart B:\n");
	partB();

	printf("\nPart C:\n");
	partC();

	printf("\nPart D:\n");
	partD();

	printf("\nPart E:\n");
	partE();

	return 0;
}
