/*
 ============================================================================
 Name        : Tut1_Ex13.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a C Function to calculate the factorial of any input number using Recursion.

 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int x){
	if(x>1)
		return x*factorial(x-1);
	else
		return 1;

}

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int num1;
	printf("Enter a number:");
	scanf("%d",&num1);

	int result=factorial(num1);

	printf("The result of factorial is %d",result);

	return 0;
}
