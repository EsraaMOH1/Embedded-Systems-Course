/*
 ============================================================================
 Name        : Tut1_EX3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a C Code to check if the input number is even or odd using If Conditions.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int input;
	printf("Please Enter a Number to check if it is even or odd:\n");
	scanf("%d",&input);
	if((input%2)==0)
		printf("%d is an even number",input);
	else
		printf("%d is an odd number",input);
	return 0;

}
