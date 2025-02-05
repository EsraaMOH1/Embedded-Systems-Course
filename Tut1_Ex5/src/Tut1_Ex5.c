/*
 ============================================================================
 Name        : Tut1_Ex5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a C Code to take the student grade (A, b, …etc.) from the user and check
then print the Equivalent Grade for it (Ex: Excellent, Very Good, …etc.) using
Switch Statements (Hint: The Program shouldn’t be case sensitive)
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	char grade;

	printf("Enter student grade:");
	scanf("%c",&grade);

	switch(grade){
	case 'A':
	case 'a':
	    printf("Student got excellent grade");
	    break;
	case 'B':
	case 'b':
		printf("Student got very good grade");
		break;
	}
	return 0;
}
