/*
 ============================================================================
 Name        : Tut1_Ex9.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a C Program to reverse a given multidigit integer using a while loop.
(Ex: Input 235, output 532)
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int num,digit,reversed=0;

	printf("Enter a num:");
	scanf("%d",&num);

	while(num!=0){
		digit=num%10;
		reversed=reversed*10+digit;
		num/=10;
	}
	printf("ANSWER IS: %d",reversed);

}
