/*
 ============================================================================
 Name        : Tut5_Ex1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 A simple code to Swap between two numbers using Macros instead of functions.
 */

#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y) {\
	int temp=x;\
	x=y;\
	y=temp;\
}

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int num1;
	int num2;

	printf("Enter 2 numbers:");
	scanf("%d %d",&num1,&num2);

	SWAP(num1,num2);

	printf("New num1=%d, num2=%d",num1,num2);


	return 0;
}
