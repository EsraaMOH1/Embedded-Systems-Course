/*
 ============================================================================
 Name        : Tut1_Ex11.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a C Function that takes one character and checks if it is alphabetic or not
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	char input;

	printf("Enter a charcter:");
	scanf(" %c",&input);

	if((input>='a' && input<='z')||(input>='A'&& input<='Z')){
		printf("Character is alphabetic");
	}
	else{
		printf("Character is not alphabetic");
	}

	return 0;
}
