/*
 ============================================================================
 Name        : Tut5_EX2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 A simple Code to change the Temperature value from Celsius to Fahrenheit using
Macros instead of Functions.

 */

#include <stdio.h>
#include <stdlib.h>

#define TEMP(x) ((x * (9.0/5.0))+32.0)

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	float temp_cel;
	float temp_feh;

	printf("Enter the temperature in Celsius:");
	scanf("%f",&temp_cel);

	temp_feh=TEMP(temp_cel);

	printf("Equivalent Temperature in Fehrenheit= %f",temp_feh);


	return 0;
}
